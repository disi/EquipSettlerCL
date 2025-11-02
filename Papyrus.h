#pragma once

#include <PCH.h>

bool RegisterPapyrusFunctions(RE::BSScript::IVirtualMachine* vm);

// Declare all functions here
bool AdminEquipSettlers_Native(std::monostate, std::vector<RE::TESObjectREFR*> aNPCs, RE::TESObjectREFR* aContainer);
bool AdminStripSettlers_Native(std::monostate, std::vector<RE::TESObjectREFR*> aNPCs, RE::TESObjectREFR* aContainer);
RE::TESObjectREFR::RemoveItemData BuildRemoveItemData_Internal(RE::BGSInventoryItem* aInventoryItem, RE::TESObjectREFR* aContainer, std::int32_t aCount);
RE::TESObjectREFR::RemoveItemData BuildRemoveItemData_Internal(RE::BGSInventoryItem* aInventoryItem, RE::TESObjectREFR* aContainer, std::uint32_t aCount);
RE::TESObjectREFR::RemoveItemData BuildRemoveItemData_Internal(RE::TESBoundObject* aInventoryItem, RE::TESObjectREFR* aContainer, std::int32_t aCount);
void EquipBestItems_Native(std::monostate, RE::TESObjectREFR* aNPC);
void EquipBestItems_Internal(RE::TESObjectREFR* aNPC);
void EquipBestItemsAll_Native(std::monostate, std::vector<RE::TESObjectREFR*> akNPC);
bool EquipInventoryItem_Internal(RE::TESObjectREFR* aNPC, RE::BGSInventoryItem* aInvItem);
RE::BSTArray<RE::TESObjectREFR*> FilterSettlers_Native(std::monostate, RE::BSTArray<RE::TESObjectREFR*> aFormArray, std::int32_t aChestTypePass, bool aShuffle);
RE::BSTArray<RE::TESObjectREFR*> FindNearbyWorkshopObjects_Native(std::monostate, RE::TESObjectREFR* akRef, float aRadius, bool shuffleResults);
RE::BSTArray<RE::TESObjectREFR*> FindSettlerTrunk_Native(std::monostate, float aRadius);
RE::BSTArray<RE::TESForm*> GetArmorItems_Native(std::monostate, RE::BSTArray<RE::TESForm*> aFormArray);
RE::BSTArray<RE::TESForm*> GetArmorItems_Internal(RE::BSTArray<RE::TESForm*> aFormArray);
RE::BSTArray<RE::BGSInventoryItem*> GetArmorItems_Internal(RE::BSTArray<RE::BGSInventoryItem*> itemArray);
RE::TESForm* GetBestItem_Internal(RE::BSTArray<RE::TESForm*> aFormArray);
RE::BGSInventoryItem* GetBestItem_Internal(RE::BSTArray<RE::BGSInventoryItem*> itemArray);
std::int32_t GetGoldPrice_Internal(RE::TESForm* aForm);
RE::BSTArray<RE::TESForm*> GetMatchingItems_Internal(RE::BSTArray<RE::TESForm*> aFormArray, std::int32_t aSlot);
RE::BSTArray<RE::BGSInventoryItem*> GetMatchingItems_Internal(RE::BGSInventoryList* inventoryList, std::int32_t slot);
template <typename T>
std::optional<T> GetPapyrusProperty_Internal(RE::TESObjectREFR* ref, const std::string& scriptName, const std::string& propertyName);
std::uint32_t GetSlotMaskFromIndex_Internal(std::int32_t aiSlotIndex);
RE::BSTArray<RE::TESForm*> GetWeaponItems_Native(std::monostate, RE::BSTArray<RE::TESForm*> aFormArray);
RE::BSTArray<RE::BGSInventoryItem*> GetWeaponItems_Internal(RE::BGSInventoryList* inventoryList);
bool HasAnyKeyword_Internal(RE::TESForm* form, const std::vector<std::string>& keywords);
bool HasAnyKeyword_Internal(RE::TESObjectREFR* aRef, const std::vector<std::string>& keywords);
bool HasAnyKeyword_Internal(RE::TESForm* form, const std::unordered_set<std::string>& keywords);
bool HasAnyKeyword_Internal(RE::TESObjectREFR* aRef, const std::unordered_set<std::string>& keywords);
bool HasAnyKeyword_Internal(RE::TESObjectREFR* aRef, const std::string& keyword);
bool HasAnyKeyword_Internal(RE::TESForm* form, std::unordered_set<std::uint32_t> keywords);
bool IsArmorWeapon_Internal(RE::TESForm* aForm);
bool IsArmorWeapon_Internal(RE::BGSInventoryItem* aItem);
bool SettingDebuggingEnabled_Native(std::monostate);
bool SettingAnimationEnabled_Native(std::monostate);
bool IsFormIDExcluded_Internal(uint32_t formID);
bool IsSettlerNPC_Internal(RE::TESObjectREFR* aNPC);
bool ProcessNPCArmor_Native(std::monostate, RE::TESObjectREFR* aNPC, RE::TESObjectREFR* aContainer);
bool ProcessNPCArmor_Internal(RE::TESObjectREFR* aNPC, RE::TESObjectREFR* aContainer);
bool PreProcessNPCArmor_Native(std::monostate, RE::TESObjectREFR* aNPC, RE::TESObjectREFR* aContainer);
bool ProcessNPCWeapon_Native(std::monostate, RE::TESObjectREFR* aNPC, RE::TESObjectREFR* aContainer);
bool ProcessNPCWeapon_Internal(RE::TESObjectREFR* aNPC, RE::TESObjectREFR* aContainer);
bool PreProcessNPCWeapon_Native(std::monostate, RE::TESObjectREFR* aNPC, RE::TESObjectREFR* aContainer);
bool SetObjectName_Native(std::monostate, RE::TESObjectREFR* aItemRef, RE::BSFixedString newName);
RE::BSTArray<RE::TESObjectREFR*> ShuffleArray_Internal(RE::BSTArray<RE::TESObjectREFR*> aFormArray);
bool SwapItems_Internal(RE::TESObjectREFR* aNPC, RE::BGSInventoryItem* aOldItem, RE::BGSInventoryItem* aNewItem, RE::TESObjectREFR* aContainer);
bool UnEquipInventoryItem_Internal(RE::TESObjectREFR* aNPC, RE::BGSInventoryItem* aInvItem);
void UpdateNPCVisual_Internal(RE::TESObjectREFR* aNPC);