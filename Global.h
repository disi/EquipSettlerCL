#pragma once

#include <PCH.h>

// Global logger pointer
extern std::shared_ptr<spdlog::logger> gLog;
// Global debug flag
extern bool DEBUGGING;
// Global data handler
extern RE::TESDataHandler* g_dataHandle;
// Global variable for max allowed slotmask
extern std::uint32_t maxAllowedSlotmask;
// Global variable for excluded FormIDs
extern std::vector<std::string> excludedFormIDs;
// Global variable for excluded keywords
extern std::vector<std::string> excludedKeywords;
// Global variable for included keywords
extern std::vector<std::string> includedKeywords;
