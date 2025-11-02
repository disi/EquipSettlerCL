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
    inline constexpr std::size_t PATCH = 6;
    inline constexpr auto NAME = "0.5"sv;
    inline constexpr auto AUTHORNAME = "disi"sv;
    inline constexpr auto PROJECT = "EquipSettlerCL"sv;
}

// Global variable to play animations
bool ANIMATION = false;
// Global variable to store NPC exclude EditorIDs
std::unordered_set<std::uint32_t> excludeNPC = {
    0x0003F22C,
    0x00045C34,
    0x0003F23D,
    0x00045C35,
    0x00036D6F,
    0x00036D72,
    0x0006B4D3,
    0x0006D3A2,
    0x0006B4D1,
    0x0006D3A3,
    0x0003F22B,
    0x00045C36,
    0x0003F23B,
    0x00048B78,
    0x0012FCCB,
    0x0012FCCC,
    0x00039FD3,
    0x00089143,
    0x0003F236,
    0x00048BA8,
    0x00019FDB,
    0x0001A4DB,
    0x0001995C,
    0x0001995E,
    0x0006B4D2,
    0x0006D3A4,
    0x00019FD8,
    0x0001A4D9,
    0x00019FDC,
    0x0001A4DA,
    0x000AA78E,
    0x000B0EEE,
    0x0003A458,
    0x00055EC9,
    0x00002F06,
    0x00002F07,
    0x00019FDA,
    0x0001A4D8,
    0x0002A82A,
    0x000ABF9E,
    0x00031FB3,
    0x000ABFA0,
    0x00031FB4,
    0x0003F234,
    0x00048B76
};
bool excludeNPCCleared = false;
std::unordered_set<std::uint32_t> excludeFaction = { 0x00023C01, 0x001EC1B9 };
bool excludeFactionCleared = false;
// Global variable for max allowed slotmask
std::uint32_t maxAllowedSlotmask = 0xFFFFFFFF;
// Define slot order: always check slot 33 first, then others
std::vector<int> slotOrder = {33, 30, 41, 42, 43, 44, 45};
// Global variable for armor slots per cycle
int armorSlotsPerCycle = 1;
// Global variable for excluded keywords items
std::unordered_set<std::uint32_t> excludedKeywords = { 0x001CF299, 0x0004D8A1 };
bool excludedKeywordsCleared = false;
// Global variable for included keywords items
std::unordered_set<std::uint32_t> includedKeywords = {
    0x000F4AEA,
    0x000F4AE9,
    0x0012EEE8,
    0x0006C0EC,
    0x0010C417,
    0x0006C0ED,
    0x0020DE40,
    0x0007820B
};
bool includedKeywordsCleared = false;
// Global variable for excluded FormIDs
std::unordered_set<std::uint32_t> excludedFormIDs = {};
// Global variable to store Workshop objects keywords
std::unordered_set<std::uint32_t> workshopObjectKeywords = { 0x00020596, 0x00069548, 0x00020592 };
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
    size_t semicolonPos = value.find(';');
    // remove comments after the value
    if (semicolonPos != std::string::npos) value = value.substr(0, semicolonPos);
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
    if (hexStr.empty()) return 0;
    try {
        return static_cast<uint32_t>(std::stoul(hexStr, nullptr, 16));
    } catch (...) {
        if (DEBUGGING) gLog->warn("ParseHexFormID: Failed to parse hex string: {}", hexStr);
        return 0;
    }
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
            gLog->warn("Failed to create default INI at: {}", configPath);
            return;
        }

        // Try to open again for reading
        file.open(configPath);
        if (!file.is_open()) {
            gLog->warn("Still could not open INI file after creating default: {}", configPath);
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

        // --- NPC Exclude EditorIDs ---
        if (lowerLine.find("excludenpc") == 0) {
            if (!excludeNPCCleared) {
                excludeNPC.clear();
                excludeNPCCleared = true;
            }
            std::uint32_t value = ParseHexFormID(GetValueFromLine(line));
            if (value != 0) {
                std::unordered_set<std::uint32_t> temp = excludeNPC;
                try {
                    temp.insert(value);
                    excludeNPC.insert(value);
                } catch (...) {
                    if (DEBUGGING) gLog->warn("Failed to insert excludeNPC value: {:08X}", value);
                }
            }
            continue;
        }

        if (lowerLine.find("excludefaction") == 0) {
            if (!excludeFactionCleared) {
                excludeFaction.clear();
                excludeFactionCleared = true;
            }
            std::uint32_t value = ParseHexFormID(GetValueFromLine(line));
            if (value != 0) {
                std::unordered_set<std::uint32_t> temp = excludeFaction;
                try {
                    temp.insert(value);
                    excludeFaction.insert(value);
                } catch (...) { 
                    if (DEBUGGING) gLog->warn("Failed to insert excludeFaction value: {:08X}", value);
                }
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
            } catch (...) { 
                if (DEBUGGING) gLog->warn("Failed to parse maxAllowedSlotmask value: {}", value);
            }
            continue;
        }

        // --- Slot order ---
        if (lowerLine.find("slotorder") == 0) {
            std::string value = GetValueFromLine(line);
            slotOrder.clear();
            std::vector<int> temp = slotOrder;
            std::stringstream ss(value);
            std::string token;
            while (std::getline(ss, token, ',')) {
                token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                if (!token.empty()) {
                    try {
                        temp.push_back(std::stoi(token));
                    } catch (...) { 
                        if (DEBUGGING) gLog->warn("Failed to parse slotOrder token: {}", token);
                    }
                }
            }
            if (!temp.empty()) {
                slotOrder = temp;
            }
            continue;
        }

        // --- Armor slots per cycle ---
        if (lowerLine.find("armorslotspercycle") == 0) {
            std::string value = GetValueFromLine(line);
            try {
                armorSlotsPerCycle = std::stoi(value);
                if (armorSlotsPerCycle < 0) armorSlotsPerCycle = 0;
            } catch (...) { 
                if (DEBUGGING) gLog->warn("Failed to parse armorSlotsPerCycle value: {}", value);
            }
            continue;
        }

        // --- Item Excluded keywords ---
        if (lowerLine.find("excludeitem") == 0) {
            if (!excludedKeywordsCleared) {
                excludedKeywords.clear();
                excludedKeywordsCleared = true;
            }
            std::uint32_t value = ParseHexFormID(GetValueFromLine(line));
            if (value != 0) {
                std::unordered_set<std::uint32_t> temp = excludedKeywords;
                try {
                    temp.insert(value);
                    excludedKeywords.insert(value);
                } catch (...) { 
                    if (DEBUGGING) gLog->warn("Failed to insert excludeItem keyword: {:08X}", value);
                }
            }
            continue;
        }

        // --- Item Included keywords ---
        if (lowerLine.find("includeitem") == 0) {
            if (!includedKeywordsCleared) {
                includedKeywords.clear();
                includedKeywordsCleared = true;
            }
            std::uint32_t value = ParseHexFormID(GetValueFromLine(line));
            if (value != 0) {
                std::unordered_set<std::uint32_t> temp = includedKeywords;
                try {
                    temp.insert(value);
                    includedKeywords.insert(value);
                } catch (...) { 
                    if (DEBUGGING) gLog->warn("Failed to insert includeItem keyword: {:08X}", value);
                }
            }
            continue;
        }

        // --- Item Excluded FormIDs ---
        if (lowerLine.find("excludeformid") == 0) {
            std::uint32_t value = ParseHexFormID(GetValueFromLine(line));
            if (value != 0) {
                std::unordered_set<std::uint32_t> temp = excludedFormIDs;
                try {
                    temp.insert(value);
                    excludedFormIDs.insert(value);
                } catch (...) { 
                    if (DEBUGGING) gLog->warn("Failed to insert excludeFormID value: {:08X}", value);
                }
            }
            continue;
        }

        // --- Workshop object keywords ---
        if (lowerLine.find("workshopobject") == 0) {
            if (!workshopObjectKeywordsCleared) {
                workshopObjectKeywords.clear();
                workshopObjectKeywordsCleared = true;
            }
            std::uint32_t value = ParseHexFormID(GetValueFromLine(line));
            if (value != 0) {
                std::unordered_set<std::uint32_t> temp = workshopObjectKeywords;
                try {
                    temp.insert(value);
                    workshopObjectKeywords.insert(value);
                } catch (...) { 
                    if (DEBUGGING) gLog->warn("Failed to insert workshopObject keyword: {:08X}", value);
                }
            }
            continue;
        }

        // --- Ammo settings ---
        if (lowerLine.find("ammomin") == 0) {
            try {
                ammoMin = std::stoi(GetValueFromLine(line));
            } catch (...) { 
                if (DEBUGGING) gLog->warn("Failed to parse ammomin value: {}", GetValueFromLine(line));
            }
            continue;
        }
        if (lowerLine.find("ammorefill") == 0) {
            try {
                ammoRefill = std::stoi(GetValueFromLine(line));
            } catch (...) { 
                if (DEBUGGING) gLog->warn("Failed to parse ammoRefill value: {}", GetValueFromLine(line));
            }
            continue;
        }
    }
    file.close();
    // Log loaded settings
    gLog->info("Loaded {} excludeNPC entries from INI.", excludeNPC.size());
    gLog->info("Loaded {} excludeFaction entries from INI.", excludeFaction.size());
    gLog->info("maxAllowedSlotmask set to: 0x{:X}", maxAllowedSlotmask);
    gLog->info("Loaded {} equipment slots as slotOrder from INI.", slotOrder.size());
    gLog->info("armorSlotsPerCycle set to: {}", armorSlotsPerCycle);
    gLog->info("Loaded {} excluded item keywords from INI.", excludedKeywords.size());
    gLog->info("Loaded {} included item keywords from INI.", includedKeywords.size());
    gLog->info("Loaded {} excluded item FormIDs from INI.", excludedFormIDs.size());
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