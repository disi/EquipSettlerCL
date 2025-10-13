#include <PCH.h>
#include <Global.h>
#include <Papyrus.h>

// Global debug flag
bool DEBUGGING = false;

// Global logger pointer
std::shared_ptr<spdlog::logger> gLog;

// Declare the F4SEMessagingInterface and F4SEScaleformInterface
const F4SE::MessagingInterface* g_messaging = nullptr;
// Papyrus interface
const F4SE::PapyrusInterface* g_papyrus = nullptr;
// Plugin handle
F4SE::PluginHandle g_pluginHandle = 0;
// Datahandler
RE::TESDataHandler* g_dataHandle = 0;

// --- Explicit F4SE_API Definition ---
// This macro is essential for exporting functions from the DLL.
// If the F4SE headers aren't providing it correctly for your setup,
// we define it directly.
#define F4SE_API __declspec(dllexport)

// This is used by commonLibF4
namespace Version
{
    inline constexpr std::size_t MAJOR = 0;
    inline constexpr std::size_t MINOR = 5;
    inline constexpr std::size_t PATCH = 0;
    inline constexpr auto NAME = "0.5"sv;
    inline constexpr auto AUTHORNAME = "disi"sv;
    inline constexpr auto PROJECT = "EquipSettlerCL"sv;
}

// Global variable to play animations
bool ANIMATION = true;
// Global variable to store NPC keywords
std::unordered_set<std::string> npcInclude = { "actortypenpc", "actortypehuman" };
bool npcIncludeCleared = false;
// Global variable to store NPC exclude EditorIDs
std::unordered_set<std::string> npcExclude = {
    "abigailfinch",
    "abrahamfinch",
    "annehargraves",
    "blakeabernathy",
    "connieabernathy",
    "danielfinch",
    "deirdre",
    "docweathers",
    "jacoborden",
    "junewarwick",
    "junlong",
    "kessler",
    "lucyabernathy",
    "mamamurphy",
    "marcylong",
    "minutemenradioannouncer",
    "ronnieshaw",
    "sheffield",
    "sturges",
    "tinadeluca",
    "vaulttecrep",
    "wiseman"
};
bool npcExcludeCleared = false;
// Global variables for faction filters
std::unordered_set<std::string> includeFaction = { "workshopnpcfaction" };
bool includeFactionCleared = false;
std::unordered_set<std::string> excludeFaction = { "currentcompanionfaction", "potentialcompanionfaction" };
bool excludeFactionCleared = false;
// Global variable for max allowed slotmask
std::uint32_t maxAllowedSlotmask = 0xFFFFFFFF;
// Define slot order: always check slot 33 first, then others
std::vector<int> slotOrder = {33, 30, 41, 42, 43, 44, 45};
// Global variable for armor slots per cycle
int armorSlotsPerCycle = 1;
// Global variable for excluded keywords
std::unordered_set<std::string> excludedKeywords = { "playercannotequip", "armortypepower" };
bool excludedKeywordsCleared = false;
// Global variable for included keywords
std::unordered_set<std::string> includedKeywords = {
    "objecttypeweapon",
    "objecttypearmor",
    "armortypehat",
    "armorbodypartchest",
    "armorbodyparthands",
    "armorbodypartfeet",
    "ma_railroad_clothingarmor",
    "dogmeatnovisualsonretrieve"
};
bool includedKeywordsCleared = false;
// Global variable for excluded FormIDs
std::unordered_set<std::string> excludedFormIDs = { };
// Global variable to store Workshop objects keywords
std::unordered_set<std::string> workshopObjectKeywords = { "workshopbedobject", "workshopguardobject", "workshopworkobject" };
bool workshopObjectKeywordsCleared = false;
// Global variables for ammunition
int ammoMin = 20;
int ammoRefill = 20;
// Global variable for the trunk Keyword
std::string trunkKeyword = "ES_EquipSettlerTrunk";

// Helper function to extract value from a line
inline std::string GetValueFromLine(const std::string& line) {
    size_t eqPos = line.find('=');
    if (eqPos == std::string::npos)
        return "";
    std::string value = line.substr(eqPos + 1);
    value.erase(std::remove_if(value.begin(), value.end(), ::isspace), value.end());
    return value;
}
// Helper function to convert string to lowercase
inline std::string ToLower(const std::string& str) {
    std::string out = str;
    std::transform(out.begin(), out.end(), out.begin(), ::tolower);
    return out;
}
// Helper to get the directory of the plugin DLL
std::string GetPluginDirectory(HMODULE hModule) {
    char path[MAX_PATH];
    GetModuleFileNameA(hModule, path, MAX_PATH);
    std::string fullPath(path);
    size_t pos = fullPath.find_last_of("\\/");
    return (pos != std::string::npos) ? fullPath.substr(0, pos + 1) : "";
}
// Helper to parse hex string to uint32_t
uint32_t ParseHexFormID(const std::string& hexStr) {
    return static_cast<uint32_t>(std::stoul(hexStr, nullptr, 16));
}
void LoadConfig(HMODULE hModule) {
    std::string configPath = GetPluginDirectory(hModule) + "EquipSettler.ini";
    gLog->info("Loading config from: {}", configPath);
    // First try to open the stream directly
    std::ifstream file(configPath);
    // Check if the file opened successfully
    if (!file.is_open()) {
        gLog->warn("Could not open INI file: {}. Creating default.", configPath);
        // Create the file with defaultIni contents
        std::ofstream out(configPath);
        if (out.is_open()) {
            out << defaultIni;
            out.close();
            gLog->info("Default INI created at: {}", configPath);
        } else {
            gLog->error("Failed to create default INI at: {}", configPath);
            return;
        }

        // Try to open again for reading
        file.open(configPath);
        if (!file.is_open()) {
            gLog->error("Still could not open INI file after creating default: {}", configPath);
            return;
        }
    }
    std::string line;
    while (std::getline(file, line)) {
        // Trim whitespace
        line.erase(0, line.find_first_not_of(" \t\r\n"));
        line.erase(line.find_last_not_of(" \t\r\n") + 1);

        // Skip comments and empty lines
        if (line.empty() || line[0] == ';')
            continue;

        // Lower case for case-insensitive comparison
        std::string lowerLine = ToLower(line);

        // --- Debugging flag ---
        if (lowerLine.find("debugging") == 0) {
            std::string value = GetValueFromLine(line);
            if (ToLower(value) == "true" || value == "1") {
                DEBUGGING = true;
            } else {
                DEBUGGING = false;
            }
            continue;
        }

        // --- Animation flag ---
        if (lowerLine.find("animation") == 0) {
            std::string value = GetValueFromLine(line);
            if (ToLower(value) == "true" || value == "1") {
                ANIMATION = true;
            } else {
                ANIMATION = false;
            }
            continue;
        }

        // --- NPC Keywords ---
        if (lowerLine.find("npcinclude") == 0) {
            if (!npcIncludeCleared) {
                npcInclude.clear();
                npcIncludeCleared = true;
            }
            std::string value = GetValueFromLine(line);
            if (!value.empty())
                npcInclude.insert(ToLower(value));
            continue;
        }

        // --- NPC Exclude EditorIDs ---
        if (lowerLine.find("npcexclude") == 0) {
            if (!npcExcludeCleared) {
                npcExclude.clear();
                npcExcludeCleared = true;
            }
            std::string value = GetValueFromLine(line);
            if (!value.empty())
                npcExclude.insert(ToLower(value));
            continue;
        }

        // --- NPC Faction filters ---
        if (lowerLine.find("includefaction") == 0) {
            if (!includeFactionCleared) {
                includeFaction.clear();
                includeFactionCleared = true;
            }
            std::string value = GetValueFromLine(line);
            if (!value.empty()) {
                try {
                    includeFaction.insert(ToLower(value));
                } catch (...) { /* ignore invalid entries */ }
            }
            continue;
        }
        if (lowerLine.find("excludefaction") == 0) {
            if (!excludeFactionCleared) {
                excludeFaction.clear();
                excludeFactionCleared = true;
            }
            std::string value = GetValueFromLine(line);
            if (!value.empty()) {
                try {
                    excludeFaction.insert(ToLower(value));
                } catch (...) { /* ignore invalid entries */ }
            }
            continue;
        }

        // --- Slotmask ---
        if (lowerLine.find("maxallowedslotmask") == 0) {
            std::string value = GetValueFromLine(line);
            if (value.find("0x") == 0 || value.find("0X") == 0)
                value = value.substr(2);
            try {
                maxAllowedSlotmask = ParseHexFormID(value);
            } catch (...) { /* keep default if invalid */ }
            continue;
        }

        // --- Slot order ---
        if (lowerLine.find("slotorder") == 0) {
            std::string value = GetValueFromLine(line);
            slotOrder.clear();
            std::stringstream ss(value);
            std::string token;
            while (std::getline(ss, token, ',')) {
                token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                if (!token.empty()) {
                    try {
                        slotOrder.push_back(std::stoi(token));
                    } catch (...) { /* ignore invalid entries */ }
                }
            }
            if (slotOrder.empty()) {
                slotOrder = {33, 30, 41, 42, 43, 44, 45};
            }
            continue;
        }

        // --- Armor slots per cycle ---
        if (lowerLine.find("armorslotspercycle") == 0) {
            std::string value = GetValueFromLine(line);
            try {
                armorSlotsPerCycle = std::stoi(value);
                if (armorSlotsPerCycle < 0) armorSlotsPerCycle = 0;
            } catch (...) { /* keep default if invalid */ }
            continue;
        }

        // --- Item Excluded keywords ---
        if (lowerLine.find("excludeitem") == 0) {
            if (!excludedKeywordsCleared) {
                excludedKeywords.clear();
                excludedKeywordsCleared = true;
            }
            std::string kw = GetValueFromLine(line);
            if (!kw.empty())
                excludedKeywords.insert(ToLower(kw));
            continue;
        }

        // --- Item Included keywords ---
        if (lowerLine.find("includeitem") == 0) {
            if (!includedKeywordsCleared) {
                includedKeywords.clear();
                includedKeywordsCleared = true;
            }
            std::string kw = GetValueFromLine(line);
            if (!kw.empty())
                includedKeywords.insert(ToLower(kw));
            continue;
        }

        // --- Item Excluded FormIDs ---
        if (lowerLine.find("excludeformid") == 0) {
            std::string value = GetValueFromLine(line);
            if (!value.empty()) {
                try {
                    excludedFormIDs.insert(value);
                } catch (...) { /* ignore invalid entries */ }
            }
            continue;
        }

        // --- Workshop object keywords ---
        if (lowerLine.find("workshopobject") == 0) {
            if (!workshopObjectKeywordsCleared) {
                workshopObjectKeywords.clear();
                workshopObjectKeywordsCleared = true;
            }
            std::string value = GetValueFromLine(line);
            if (!value.empty())
                workshopObjectKeywords.insert(ToLower(value));
            continue;
        }

        // --- Ammo settings ---
        if (lowerLine.find("ammomin") == 0) {
            try {
                ammoMin = std::stoi(GetValueFromLine(line));
            } catch (...) { /* keep default if invalid */ }
            continue;
        }
        if (lowerLine.find("ammorefill") == 0) {
            try {
                ammoRefill = std::stoi(GetValueFromLine(line));
            } catch (...) { /* keep default if invalid */ }
            continue;
        }
    }
    file.close();
    // Log loaded settings
    gLog->info("Loaded {} npcInclude entries from INI.", npcInclude.size());
    gLog->info("Loaded {} npcExclude entries from INI.", npcExclude.size());
    gLog->info("Loaded {} includeFaction entries from INI.", includeFaction.size());
    gLog->info("Loaded {} excludeFaction entries from INI.", excludeFaction.size());
    gLog->info("maxAllowedSlotmask set to: 0x{:X}", maxAllowedSlotmask);
    gLog->info("Loaded {} slots as slotOrder from INI.", slotOrder.size());
    gLog->info("armorSlotsPerCycle set to: {}", armorSlotsPerCycle);
    gLog->info("Loaded {} excluded keywords from INI.", excludedKeywords.size());
    gLog->info("Loaded {} included keywords from INI.", includedKeywords.size());
    gLog->info("Loaded {} excluded FormIDs from INI.", excludedFormIDs.size());
    gLog->info("Loaded {} workshopObject entries from INI.", workshopObjectKeywords.size());
    gLog->info("ammoMin set to: {}", ammoMin);
    gLog->info("ammoRefill set to: {}", ammoRefill);
}

// Message handler definition
void F4SEMessageHandler(F4SE::MessagingInterface::Message* a_message) {
    switch (a_message->type) {
    case F4SE::MessagingInterface::kPostLoad:
        gLog->info("Received kMessage_PostLoad. Game data is now loaded!");
        break;
    case F4SE::MessagingInterface::kPostPostLoad:
        gLog->info("Received kMessage_PostPostLoad. Game data finished loading.");
        break;
    case F4SE::MessagingInterface::kGameDataReady:
        gLog->info("Received kMessage_GameDataReady. Game data is ready.");
        // Get the global data handle and interfaces
        g_dataHandle = RE::TESDataHandler::GetSingleton();
        if (g_dataHandle) {
            gLog->info("TESDataHandler singleton acquired successfully.");
        } else {
            gLog->warn("Failed to acquire TESDataHandler singleton.");
        }
    }
}

// --- F4SE Entry Points - MUST have C linkage for F4SE to find them ---
extern "C"  { // This block ensures C-style (unmangled) names for the linker

    F4SE_API bool F4SEPlugin_Query(const F4SE::QueryInterface* f4se, F4SE::PluginInfo* info)
    {
        // Set the plugin information
        // This is crucial to load the plugin
        info->infoVersion = F4SE::PluginInfo::kVersion;
        info->name = Version::PROJECT.data();
        info->version = Version::MAJOR;

        // Set up the logger
        // F4SE::log::log_directory().value(); == Documents/My Games/F4SE/
        std::filesystem::path logPath = F4SE::log::log_directory().value();
        logPath = logPath.parent_path() / "Fallout4" / "F4SE" / fmt::format(FMT_STRING("{}.log"), Version::PROJECT);
        // Create the file
        auto sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(logPath.string(), true);
        auto aLog = std::make_shared<spdlog::logger>("aLog"s, sink);
        // Configure the logger
        aLog->set_level(spdlog::level::info);
        aLog->flush_on(spdlog::level::info);
        // Set pattern
        aLog->set_pattern("[%T] [%^%l%$] %v"s);
        // Register to make it global accessable
        spdlog::register_logger(aLog);
        // Assign to global pointer
        gLog = spdlog::get("aLog");
        // First log
        gLog->info("{}: Plugin Query started.", Version::PROJECT);

        // Minimum version 1.10.163
        const auto ver = f4se->RuntimeVersion();
        if (ver < F4SE::RUNTIME_1_10_162) {
            gLog->critical("unsupported runtime v{}", ver.string());
            return false;
        }

        return true;
    }

    // This function is called after F4SE has loaded all plugins and the game is about to start.
    F4SE_API bool F4SEPlugin_Load(const F4SE::LoadInterface* f4se)
    {
        // Initialize the plugin with logger false to prevent F4SE to use its own logger
        F4SE::Init(f4se, false);

        // Log information
        gLog->info("{}: Plugin loaded!", Version::PROJECT);
        gLog->info("F4SE version: {}", F4SE::GetF4SEVersion().string());
        gLog->info("Game runtime version: {}", f4se->RuntimeVersion().string());

        // Get the global plugin handle and interfaces
        g_pluginHandle = f4se->GetPluginHandle();
        g_messaging = F4SE::GetMessagingInterface();
        g_papyrus = F4SE::GetPapyrusInterface();

        // Register Papyrus functions
        if (g_papyrus) {
            g_papyrus->Register(RegisterPapyrusFunctions);
            gLog->info("Papyrus functions registration callback successfully registered.");
        }
        else {
            gLog->warn("Failed to register Papyrus functions. This is critical for native functions.");
        }

        // Set the messagehandler to listen to events
        if (g_messaging && g_messaging->RegisterListener(F4SEMessageHandler, "F4SE")) {
            gLog->info("Registered F4SE message handler.");
        }
        else {
            gLog->warn("Failed to register F4SE message handler.");
            return false;
        }

        // Get the DLL handle for this plugin
        HMODULE hModule = GetModuleHandleA("EquipSettlerCL.dll");
        // Load config
        LoadConfig(hModule);

        return true;
    }

    F4SE_API void F4SEPlugin_Release() {
        // This is a new function for cleanup. It is called when the plugin is unloaded.
        gLog->info("%s: Plugin released.", Version::PROJECT);
        gLog->flush();
        spdlog::drop_all();
    }
}