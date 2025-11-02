#pragma once
#include <PCH.h>
#include <Papyrus.h>

// Global logger pointer
extern std::shared_ptr<spdlog::logger> gLog;
// Global debug flag
extern bool DEBUGGING;
// Global data handler
extern RE::TESDataHandler* g_dataHandle;

// Global debug flag
extern bool ANIMATION;
// Global variable to store NPC exclude EditorIDs
extern std::unordered_set<std::uint32_t> excludeNPC;
// Global variables for faction filters
extern std::unordered_set<std::uint32_t> excludeFaction;
// Global variable for max allowed slotmask
extern std::uint32_t maxAllowedSlotmask;
// Define slot order: always check slot 33 first, then others
extern std::vector<int> slotOrder;
// Global variable for armor slots per cycle
extern int armorSlotsPerCycle;
// Global variable for excluded keywords
extern std::unordered_set<std::uint32_t> excludedKeywords;
// Global variable for included keywords
extern std::unordered_set<std::uint32_t> includedKeywords;
// Global variable for excluded FormIDs
extern std::unordered_set<std::uint32_t> excludedFormIDs;
// Global variable to store Workshop objects keywords
extern std::unordered_set<std::uint32_t> workshopObjectKeywords;
// Global variables for ammunition
extern int ammoMin;
extern int ammoRefill;

// Default ini file
extern const char* defaultIni;

// Global variable for the trunk Keyword
extern std::string trunkKeyword;