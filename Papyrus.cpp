#include <PCH.h>
#include <Global.h>

// Declare all functions here
RE::TESObjectREFR::RemoveItemData BuildRemoveItemData_Internal(RE::BGSInventoryItem* aInventoryItem, RE::TESObjectREFR* aContainer, std::int32_t aCount);
RE::TESObjectREFR::RemoveItemData BuildRemoveItemData_Internal(RE::BGSInventoryItem* aInventoryItem, RE::TESObjectREFR* aContainer, std::uint32_t aCount);
RE::TESObjectREFR::RemoveItemData BuildRemoveItemData_Internal(RE::TESBoundObject* aInventoryItem, RE::TESObjectREFR* aContainer, std::int32_t aCount);
RE::BSTArray<RE::TESForm*> CombineArray_Native(std::monostate, RE::BSTArray<RE::TESForm*> aFormArray1, RE::BSTArray<RE::TESForm*> aFormArray2);
void EquipBestItems_Native(std::monostate, RE::TESObjectREFR* aNPC, std::vector<int> slots);
bool EquipInventoryItem_Internal(RE::TESObjectREFR* aNPC, RE::BGSInventoryItem* aInvItem);
RE::BSTArray<RE::TESForm*> GetArmorItems_Native(std::monostate, RE::BSTArray<RE::TESForm*> aFormArray);
RE::BSTArray<RE::TESForm*> GetArmorItems_Internal(RE::BSTArray<RE::TESForm*> aFormArray);
RE::BSTArray<RE::BGSInventoryItem*> GetArmorItems_Internal(RE::BSTArray<RE::BGSInventoryItem*> itemArray);
RE::TESObjectARMO* GetBestArmor_Native(std::monostate, RE::BSTArray<RE::TESForm*> aFormArray);
RE::TESObjectWEAP* GetBestWeapon_Native(std::monostate, RE::BSTArray<RE::TESForm*> aFormArray);
RE::TESForm* GetBestItem_Internal(RE::BSTArray<RE::TESForm*> aFormArray);
RE::BGSInventoryItem* GetBestItem_Internal(RE::BSTArray<RE::BGSInventoryItem*> itemArray);
std::int32_t GetGoldPrice_Native(std::monostate, RE::TESForm* aForm);
std::int32_t GetGoldPrice_Internal(RE::TESForm* aForm);
RE::BSTArray<RE::TESForm*> GetMatchingItems_Native(std::monostate, RE::BSTArray<RE::TESForm*> aFormArray, std::int32_t aSlot);
RE::BSTArray<RE::TESForm*> GetMatchingItems_Internal(RE::BSTArray<RE::TESForm*> aFormArray, std::int32_t aSlot);
RE::BSTArray<RE::BGSInventoryItem*> GetMatchingItems_Internal(RE::BGSInventoryList* inventoryList, std::int32_t slot);
RE::BSTArray<RE::TESForm*> GetWeaponItems_Native(std::monostate, RE::BSTArray<RE::TESForm*> aFormArray);
RE::BSTArray<RE::BGSInventoryItem*> GetWeaponItems_Internal(RE::BGSInventoryList* inventoryList);
bool HasAnyKeyword_Internal(RE::TESForm* form, const std::vector<std::string>& keywords);
bool IsArmorWeapon_Native(std::monostate, RE::TESForm* aForm);
bool IsArmorWeapon_Internal(RE::TESForm* aForm);
bool IsArmorWeapon_Internal(RE::BGSInventoryItem* aItem);
bool IsFormIDExcluded_Internal(uint32_t formID);
std::uint32_t GetSlotMaskFromIndex_Internal(std::int32_t aiSlotIndex);
bool ItemMatchesSlot_Native(std::monostate, RE::TESObjectARMO* aArmor, std::int32_t aSlot);
bool ProcessNPCArmor_Native(std::monostate, RE::TESObjectREFR* aNPC, RE::TESObjectREFR* aContainer, std::int32_t aSlot);
bool ProcessNPCWeapon_Native(std::monostate, RE::TESObjectREFR* aNPC, RE::TESObjectREFR* aContainer);
bool SetObjectName_Native(std::monostate, RE::TESObjectREFR* aItemRef, RE::BSFixedString newName);
bool StringContains_Native(std::monostate, RE::BSFixedString aString, RE::BSFixedString aSearchString);
bool StripSettler_Native(std::monostate, RE::TESObjectREFR* aNPC, RE::TESObjectREFR* aContainer);
bool SwapItems_Native(std::monostate, RE::TESObjectREFR* aNPC, RE::TESForm* aOldItem, RE::TESForm* aNewItem, RE::TESObjectREFR* aContainer);
bool SwapItems_Internal(RE::TESObjectREFR* aNPC, RE::TESForm* aOldItem, RE::TESForm* aNewItem, RE::TESObjectREFR* aContainer);

// Helper to construct the RemoveItemData for the RemoveItem(RemoveItemData zData) function
// std::int32_t
RE::TESObjectREFR::RemoveItemData BuildRemoveItemData_Internal(RE::BGSInventoryItem* aInventoryItem, RE::TESObjectREFR* aContainer, std::int32_t aCount)
{
    // --- RemoveItemData ---
    //Main constructor that takes a TESBoundObject and the item count:
    //    RemoveItemData(TESBoundObject* a_object, std::int32_t a_count)
    // members
    // This array holds unique instance data, like FormIDs of attached mods,
    // which are part of the BGSInventoryItem::Stack.
    //BSTSmallArray<std::uint32_t, 4> stackData;
    // The base object of the item (e.g., TESObjectWEAP, TESObjectARMO).
    //TESBoundObject* object{ nullptr };
    // The number of items to remove.
    //std::int32_t count{ 0 };
    // An enum specifying the reason for the item's removal (e.g., kEquip, kStoreTeammate).
    //ITEM_REMOVE_REASON reason{ ITEM_REMOVE_REASON::kNone };
    // The destination container for the item if it's being transferred.
    // If null, the item is typically dropped.
    //TESObjectREFR* a_otherContainer{ nullptr };
    // Pointers to the position and rotation data if the item is being dropped in the world.
    //const NiPoint3* dropLoc{ nullptr };
    //const NiPoint3* rotate{ nullptr };

    // The constructor for RemoveItemData takes the base object and count.
    RE::TESObjectREFR::RemoveItemData newData(aInventoryItem->object, aCount);

    // Set the destination container and the reason for the transfer.
    newData.a_otherContainer = aContainer;
    // Needs to be RE::ITEM_REMOVE_REASON::kStoreTeammate to work properly
    newData.reason = RE::ITEM_REMOVE_REASON::kStoreContainer;

    // The stackData does not work correctly and causes no item to be transferred
    // Correctly transfer the unique item instance data handle.
    //if (aInventoryItem->stackData && aInventoryItem->stackData->extra) {
        //newData.stackData.push_back(reinterpret_cast<std::uint32_t>(aInventoryItem->stackData.get()));
    //}

    return newData;
}

// Helper to construct the RemoveItemData for the RemoveItem(RemoveItemData zData) function
// std::uint32_t
RE::TESObjectREFR::RemoveItemData BuildRemoveItemData_Internal(RE::BGSInventoryItem* aInventoryItem, RE::TESObjectREFR* aContainer, std::uint32_t aCount)
{
    // The constructor for RemoveItemData takes the base object and count.
    RE::TESObjectREFR::RemoveItemData newData(aInventoryItem->object, static_cast<std::int32_t>(aCount));

    // Set the destination container and the reason for the transfer.
    newData.a_otherContainer = aContainer;
    // Needs to be RE::ITEM_REMOVE_REASON::kStoreTeammate to work properly
    newData.reason = RE::ITEM_REMOVE_REASON::kStoreContainer;

    // The stackData does not work correctly and causes no item to be transferred
    //if (aInventoryItem->stackData && aInventoryItem->stackData->extra) {
        //newData.stackData.push_back(reinterpret_cast<std::uint32_t>(aInventoryItem->stackData->extra.get()));
    //}

    return newData;
}

// Helper to construct the RemoveItemData for the RemoveItem(RemoveItemData zData) function
// RE::TESBoundObject
// std::int32_t
RE::TESObjectREFR::RemoveItemData BuildRemoveItemData_Internal(RE::TESBoundObject* aInventoryItem, RE::TESObjectREFR* aContainer, std::int32_t aCount)
{
    // The constructor for RemoveItemData takes the base object and count.
    RE::TESObjectREFR::RemoveItemData newData(aInventoryItem, static_cast<std::int32_t>(aCount));

    // Set the destination container and the reason for the transfer.
    newData.a_otherContainer = aContainer;
    // Needs to be RE::ITEM_REMOVE_REASON::kStoreTeammate to work properly
    newData.reason = RE::ITEM_REMOVE_REASON::kStoreContainer;

    // The stackData does not work correctly and causes no item to be transferred
    //if (aInventoryItem->stackData && aInventoryItem->stackData->extra) {
        //newData.stackData.push_back(reinterpret_cast<std::uint32_t>(aInventoryItem->stackData->extra.get()));
    //}

    return newData;
}

// Form[] Function CombineArray(Form[] aFormArray1, Form[] aFormArray2) global native
RE::BSTArray<RE::TESForm*> CombineArray_Native(std::monostate, RE::BSTArray<RE::TESForm*> aFormArray1, RE::BSTArray<RE::TESForm*> aFormArray2)
{
    RE::BSTArray<RE::TESForm*> combinedArray;

    if (DEBUGGING) gLog->info("CombineArray_Native: Function called.");

    // Check if the first array is valid before iterating to prevent crashes on null arrays.
    if (!aFormArray1.empty() || aFormArray1.size() == 0) {
        if (DEBUGGING) gLog->info("CombineArray_Native: Adding items from first array.");
        for (const auto& form : aFormArray1) {
            // Check for null forms inside the array to prevent crashes.
            if (form) {
                combinedArray.push_back(form);
            }
        }
    }

    // Check if the second array is valid before iterating.
    if (!aFormArray2.empty() || aFormArray2.size() == 0) {
        if (DEBUGGING) gLog->info("CombineArray_Native: Adding items from second array.");
        for (const auto& form : aFormArray2) {
            // Check for null forms inside the array to prevent crashes.
            if (form) {
                combinedArray.push_back(form);
            }
        }
    }

    if (DEBUGGING) gLog->info("CombineArray_Native: Combined array has {} forms.", combinedArray.size());

    return combinedArray;
}

// bool Function EquipBestItems(ObjectReference akNPC, int[] slots) global native
void EquipBestItems_Native(std::monostate, RE::TESObjectREFR* aNPC, std::vector<int> slots)
{
    if (DEBUGGING) gLog->info("EquipBestItems_Native: Function called.");

    if (!aNPC) {
        if (DEBUGGING) gLog->warn("EquipBestItems_Native: NPC reference is null.");
        return;
    }

    if (slots.empty() || slots.size() == 0) {
        if (DEBUGGING) gLog->warn("EquipBestItems_Native: Slots array is empty or null.");
        return;
    }

    // Get the inventory items
    RE::BGSInventoryList* itemList = aNPC->inventoryList;
    if (!itemList) {
        if (DEBUGGING) gLog->warn("EquipBestItems_Native: NPC has no inventory list. Cannot continue.");
        return;
    }

    // Iterate over the armor slots and equip the best item for each slot
    for (int slot : slots) {
        RE::BSTArray<RE::BGSInventoryItem*> matchingItems = GetMatchingItems_Internal(itemList, slot);
        RE::BSTArray<RE::BGSInventoryItem*> matchingArmorItems = GetArmorItems_Internal(matchingItems);
        if (matchingArmorItems.empty() || matchingArmorItems.size() == 0) {
            if (DEBUGGING) gLog->warn("EquipBestItems_Native: No matching armor items found for slot: {}. Skipping.", slot);
            continue;
        }
        RE::BGSInventoryItem* bestItem = GetBestItem_Internal(matchingArmorItems);
        if (!bestItem || !bestItem->object) {
            if (DEBUGGING) gLog->warn("EquipBestItems_Native: No armor item found for slot: {}. Skipping.", slot);
            continue;
        }
        if (DEBUGGING) gLog->info("EquipBestItems_Native: Equipping FormID: {:08X} to slot: {}.", bestItem->object->GetFormID(), slot);
        if (EquipInventoryItem_Internal(aNPC, bestItem)){
            if (DEBUGGING) gLog->info("EquipBestItems_Native: Successfully equipped armor item.");
        } else {
            if (DEBUGGING) gLog->warn("EquipBestItems_Native: Failed to equip armor item.");
        }
    }

    // equip best weapon
    RE::BSTArray<RE::BGSInventoryItem*> weaponItems = GetWeaponItems_Internal(itemList);
    RE::BGSInventoryItem* bestItem = GetBestItem_Internal(weaponItems);
    if (bestItem && bestItem->object) {
        auto weapon = bestItem->object->As<RE::TESObjectWEAP>();
        if (weapon && weapon->weaponData.ammo) {
            // Check if NPC has any of this ammo
            bool hasAmmo = false;
            if (aNPC->inventoryList) {
                for (auto& invItem : aNPC->inventoryList->data) {
                    if (invItem.object == weapon->weaponData.ammo && invItem.stackData->GetCount() > 10) {
                        hasAmmo = true;
                        break;
                    }
                }
            }
            // If not, add some ammo
            if (!hasAmmo) {
                if (DEBUGGING) gLog->info("EquipBestArmorItems_Native: Adding ammo FormID: {:08X} to NPC inventory.", weapon->weaponData.ammo->GetFormID());
                aNPC->AddObjectToContainer(weapon->weaponData.ammo, nullptr, 10, nullptr, RE::ITEM_REMOVE_REASON::kStoreContainer);
            }
        }
        if (DEBUGGING) gLog->info("EquipBestArmorItems_Native: Equipping best weapon FormID: {:08X}.", bestItem->object->GetFormID());
        if (EquipInventoryItem_Internal(aNPC, bestItem)) {
            if (DEBUGGING) gLog->info("EquipBestArmorItems_Native: Successfully equipped weapon.");
        } else {
            if (DEBUGGING) gLog->warn("EquipBestArmorItems_Native: Failed to equip weapon.");
        }
    } else {
        if (DEBUGGING) gLog->warn("EquipBestArmorItems_Native: No best weapon found to equip.");
    }

    if (DEBUGGING) gLog->info("EquipBestArmorItems_Native: Function finished.");
}
// Helper function to equip a single inventory item to an NPC
bool EquipInventoryItem_Internal(RE::TESObjectREFR* aNPC, RE::BGSInventoryItem* aInvItem)
{
    if (!aInvItem || !aInvItem->object || !aNPC) return false;
    // Last check to ensure the item is an armor or weapon
    if (!IsArmorWeapon_Internal(aInvItem->object)) return false;
    // Get the actor from the reference
    RE::Actor* actor = aNPC->As<RE::Actor>();
    if (!actor)
        return false;
    // Get instance data and stack ID
    RE::TBO_InstanceData* instanceData = nullptr;
    std::uint32_t validStackID = 0;
    for (std::uint32_t i = 0; i < aInvItem->stackData->count; ++i) {
        instanceData = aInvItem->GetInstanceData(i);
        if (instanceData) {
            validStackID = i;
            break;
        }
    }
    if (!instanceData) {
        if (DEBUGGING) gLog->warn("No valid instanceData found for FormID: {:08X}", aInvItem->object->GetFormID());
        return false;
    }
    //RE::TBO_InstanceData* instanceData = aInvItem->GetInstanceData(stackID);
    // Create object instance
    RE::BGSObjectInstance objInstance(aInvItem->object, instanceData);
    // Determine equip slot (armor or weapon)
    const RE::BGSEquipSlot* equipSlot = nullptr;
    if (aInvItem->object->GetFormType() == RE::ENUM_FORM_ID::kARMO) {
        auto armor = aInvItem->object->As<RE::TESObjectARMO>();
        equipSlot = armor ? armor->equipSlot : nullptr;
    } else if (aInvItem->object->GetFormType() == RE::ENUM_FORM_ID::kWEAP) {
        auto weapon = aInvItem->object->As<RE::TESObjectWEAP>();
        equipSlot = weapon ? weapon->equipSlot : nullptr;
    }
    // Equip using ActorEquipManager
    auto* equipMgr = RE::ActorEquipManager::GetSingleton();
    equipMgr->EquipObject(
        actor,
        objInstance,
        validStackID,
        1,              // count
        equipSlot,      // slot (nullptr for weapons)
        false,          // queueEquip
        true,           // forceEquip
        true,           // playSounds
        true,           // applyNow
        true            // locked
    );
    return true;
}

// Form[] Function GetArmorItems(Form[] aFormArray) global native
RE::BSTArray<RE::TESForm*> GetArmorItems_Native(std::monostate, RE::BSTArray<RE::TESForm*> aFormArray)
{
    RE::BSTArray<RE::TESForm*> armorArray;

    // Check if the array pointer is valid before proceeding.
    if (aFormArray.empty() || aFormArray.size() == 0) {
        if (DEBUGGING) gLog->warn("GetArmorItems_Native: Input array is empty or null. Returning empty array.");
        return armorArray;
    }

    if (DEBUGGING) gLog->info("GetArmorItems_Native: Function called with array size: {}", aFormArray.size());

    // Loop through each item in the input array
    for (RE::TESForm* currentForm : aFormArray) {
        if (currentForm == nullptr) {
            // Skip null forms
            continue;
        }
        // Check the Form Type
        if (currentForm->GetFormType() == RE::ENUM_FORM_ID::kARMO) {
            armorArray.push_back(currentForm);
        }
    }

    if (DEBUGGING) gLog->info("GetArmorItems_Native: Total matching items found: {}.", armorArray.size());

    return armorArray;
}
// Form[] Function GetArmorItems(Form[] aFormArray) global native
RE::BSTArray<RE::TESForm*> GetArmorItems_Internal(RE::BSTArray<RE::TESForm*> aFormArray)
{
    RE::BSTArray<RE::TESForm*> armorArray;

    // Check if the array pointer is valid before proceeding.
    if (aFormArray.empty() || aFormArray.size() == 0) {
        return armorArray;
    }

    // Loop through each item in the input array
    for (RE::TESForm* currentForm : aFormArray) {
        if (currentForm == nullptr) {
            // Skip null forms
            continue;
        }
        // Check the Form Type
        if (currentForm->GetFormType() == RE::ENUM_FORM_ID::kARMO) {
            armorArray.push_back(currentForm);
        }
    }

    return armorArray;
}
RE::BSTArray<RE::BGSInventoryItem*> GetArmorItems_Internal(RE::BSTArray<RE::BGSInventoryItem*> itemArray)
{
    RE::BSTArray<RE::BGSInventoryItem*> armorArray;
    if (itemArray.empty() || itemArray.size() == 0) {
        return armorArray;
    }
    for (RE::BGSInventoryItem* currentItem : itemArray) {
        if (!currentItem || !currentItem->object) continue;
        RE::TESForm* form = currentItem->object->As<RE::TESForm>();
        if (!form) continue;
        if (form->GetFormType() == RE::ENUM_FORM_ID::kARMO) {
            armorArray.push_back(currentItem);
        }
    }
    return armorArray;
}

// Armor Function GetBestItem(Form[] aFormArray) global native
RE::TESObjectARMO* GetBestArmor_Native(std::monostate, RE::BSTArray<RE::TESForm*> aFormArray)
{
    // Set the DN015_NoneNameMisc TESForm to bypass the CommonLibF4 limitation to convert nullptr to Papyrus Form None
    RE::TESObjectARMO* bestItem = nullptr;
    if (bestItem) {
        if (DEBUGGING) gLog->info("GetBestArmor_Native: Found fake None TESForm ObjectTypeName: {}", bestItem->GetObjectTypeName());
    }
    std::uint32_t bestValue = 0;

    // Check if the array pointer is valid before proceeding.
    if (aFormArray.empty() || aFormArray.size() == 0) {
        if (DEBUGGING) gLog->warn("GetBestArmor_Native: Input array is empty or null. Returning empty TESForm.");
        return bestItem;
    }

    if (DEBUGGING) gLog->info("GetBestArmor_Native: Function called with array size: {}", aFormArray.size());
    
    // Iterate over the Forms in the Array
    for (RE::TESForm* currentItem : aFormArray) {
        if (IsArmorWeapon_Internal(currentItem)) {
            if (DEBUGGING) gLog->info("GetBestArmor_Native: Getting Value for FormID: {:08X}", currentItem->formID);
            std::int32_t currentValue = GetGoldPrice_Internal(currentItem);
            if (DEBUGGING) gLog->info("GetBestArmor_Native: Got Value: {}", currentValue);
            // Comapre value
            if (currentValue > bestValue) {
                bestItem = currentItem->As<RE::TESObjectARMO>();
                bestValue = currentValue;
            }
        }
    }

    if (DEBUGGING) {
        if (bestItem) {
            gLog->info("GetBestArmor_Native: Found best item FormID: {:08X} with value: {} .", bestItem->formID, bestValue);
        }
        else {
            gLog->warn("GetBestArmor_Native: No valid item found in array. Returning null.");
        }
    }

    return bestItem;
}
// Weapon Function GetBestItem(Form[] aFormArray) global native
RE::TESObjectWEAP* GetBestWeapon_Native(std::monostate, RE::BSTArray<RE::TESForm*> aFormArray)
{
    // Set the DN015_NoneNameMisc TESForm to bypass the CommonLibF4 limitation to convert nullptr to Papyrus Form None
    RE::TESObjectWEAP* bestItem = nullptr;
    if (bestItem) {
        if (DEBUGGING) gLog->info("GetBestWeapon_Native: Found fake None TESForm ObjectTypeName: {}", bestItem->GetObjectTypeName());
    }
    std::uint32_t bestValue = 0;

    // Check if the array pointer is valid before proceeding.
    if (aFormArray.empty() || aFormArray.size() == 0) {
        if (DEBUGGING) gLog->warn("GetBestWeapon_Native: Input array is empty or null. Returning empty TESForm.");
        return bestItem;
    }

    if (DEBUGGING) gLog->info("GetBestWeapon_Native: Function called with array size: {}", aFormArray.size());

    // Iterate over the Forms in the Array
    for (RE::TESForm* currentItem : aFormArray) {
        if (IsArmorWeapon_Internal(currentItem)) {
            if (DEBUGGING) gLog->info("GetBestWeapon_Native: Getting Value for FormID: {:08X}", currentItem->formID);
            std::int32_t currentValue = GetGoldPrice_Internal(currentItem);
            if (DEBUGGING) gLog->info("GetBestWeapon_Native: Got Value: {}", currentValue);
            // Comapre value
            if (currentValue > bestValue) {
                bestItem = currentItem->As<RE::TESObjectWEAP>();
                bestValue = currentValue;
            }
        }
    }

    if (DEBUGGING) {
        if (bestItem) {
            gLog->info("GetBestWeapon_Native: Found best item FormID: {:08X} with value: {} .", bestItem->formID, bestValue);
        }
        else {
            gLog->warn("GetBestWeapon_Native: No valid item found in array. Returning null.");
        }
    }

    return bestItem;
}
RE::TESForm* GetBestItem_Internal(RE::BSTArray<RE::TESForm*> aFormArray)
{
    // Set the DN015_NoneNameMisc TESForm to bypass the CommonLibF4 limitation to convert nullptr to Papyrus Form None
    RE::TESForm* bestItem = nullptr; //g_dataHandler.->LookupForm(0x0000C2CB, "Fallout4.esm");
    if (bestItem) {
    }
    std::uint32_t bestValue = 0;
    // Check if the array pointer is valid before proceeding.
    if (aFormArray.empty() || aFormArray.size() == 0) {
        return bestItem;
    }
    // Iterate over the Forms in the Array
    for (RE::TESForm* currentItem : aFormArray) {
        if (IsArmorWeapon_Internal(currentItem)) {
            std::int32_t currentValue = GetGoldPrice_Internal(currentItem);
            // Comapre value
            if (currentValue > bestValue) {
                bestItem = currentItem;
                bestValue = currentValue;
            }
        }
    }
    return bestItem;
}
RE::BGSInventoryItem* GetBestItem_Internal(RE::BSTArray<RE::BGSInventoryItem*> itemArray)
{
    RE::BGSInventoryItem* bestItem = nullptr;
    std::uint32_t bestValue = 0;
    if (itemArray.empty() || itemArray.size() == 0) {
        return bestItem;
    }
    for (RE::BGSInventoryItem* currentItem : itemArray) {
        if (!currentItem || !currentItem->object) continue;
        RE::TESForm* form = currentItem->object->As<RE::TESForm>();
        if (!form) continue;
        if (IsArmorWeapon_Internal(form)) {
            std::int32_t currentValue = GetGoldPrice_Internal(form);
            if (currentValue > bestValue) {
                bestItem = currentItem;
                bestValue = currentValue;
            }
        }
    }
    return bestItem;
}

// int Function GetGoldPrice(Form aForm) global native
std::int32_t GetGoldPrice_Native(std::monostate, RE::TESForm* aForm)
{
    // Check the item
    if (!aForm) {
        if (DEBUGGING) gLog->info("GetGoldPrice_Native: Input Form is empty or null. Returning 0.");
        return 0;
    }

    if (DEBUGGING) gLog->info("GetGoldPrice_Native: Function called with Form: {:08X}.", aForm->formID);

    // Try casting to a TESObjectARMO
    if (aForm->GetFormType() == RE::ENUM_FORM_ID::kARMO) {
        RE::TESObjectARMO* armor = aForm->As<RE::TESObjectARMO>();
        if (armor != nullptr) {
            if (DEBUGGING) gLog->info("GetGoldPrice_Native: Armor with value: {}.", armor->armorData.GetValue());
            return armor->armorData.GetValue();
        }
    }

    // Try casting to a TESObjectWEAP
    if (aForm->GetFormType() == RE::ENUM_FORM_ID::kWEAP) {
        RE::TESObjectWEAP* weapon = aForm->As<RE::TESObjectWEAP>();
        if (weapon != nullptr) {
            if (DEBUGGING) gLog->info("GetGoldPrice_Native: Weapon with value: {}.", weapon->weaponData.GetValue());
            return weapon->weaponData.GetValue();
        }
    }

    return 0;
}
// Internal call to the function
std::int32_t GetGoldPrice_Internal(RE::TESForm* aForm)
{
    // Check the item
    if (!aForm) {
        return 0;
    }

    // Check if Armor
    if (aForm->GetFormType() == RE::ENUM_FORM_ID::kARMO) {
        RE::TESObjectARMO* armor = aForm->As<RE::TESObjectARMO>();
        if (armor != nullptr) {
            return armor->armorData.GetValue();
        }
    }

    // Check if Weapon
    if (aForm->GetFormType() == RE::ENUM_FORM_ID::kWEAP) {
        RE::TESObjectWEAP* weapon = aForm->As<RE::TESObjectWEAP>();
        if (weapon != nullptr) {
            return weapon->weaponData.GetValue();
        }
    }

    return 0;
}

// Helper function to convert a Papyrus slot index to a bitmask.
// This function now handles all slots from 30 to 61 using a bitwise shift.
std::uint32_t GetSlotMaskFromIndex_Internal(std::int32_t aiSlotIndex)
{
    if (aiSlotIndex >= 30 && aiSlotIndex <= 61) {
        return 1 << (aiSlotIndex - 30);
    }
    return 0;
}

// Form[] Function GetMatchingItems(Form[] aFormArray, Int aSlot) global native
RE::BSTArray<RE::TESForm*> GetMatchingItems_Native(std::monostate, RE::BSTArray<RE::TESForm*> aFormArray, std::int32_t aSlot)
{
    RE::BSTArray<RE::TESForm*> result;

    // Check if the array pointer is valid before proceeding.
    if (aFormArray.empty() || aFormArray.size() == 0) {
        if (DEBUGGING) gLog->warn("GetMatchingItems_Native: Input array is empty or null. Returning empty array.");
        return result;
    }

    if (DEBUGGING) gLog->info("GetMatchingItems_Native: Function called");

    // Make sure we only get Armor Forms
    RE::BSTArray<RE::TESForm*> armorArray = GetArmorItems_Internal(aFormArray);

    for (RE::TESForm* currentForm : armorArray) {
        if (currentForm == nullptr) {
            // Skip null forms
            if (DEBUGGING) gLog->warn("GetMatchingItems_Native: The current Form is nullptr!");
            continue;
        }
        RE::TESObjectARMO* armor = currentForm->As<RE::TESObjectARMO>();
        // Check if aSlot SlotMask fits into the overall SlotMask of the Armor
        if ((armor->bipedModelData.bipedObjectSlots & GetSlotMaskFromIndex_Internal(aSlot)) != 0) {
            if (IsArmorWeapon_Internal(currentForm)) {
                result.push_back(currentForm);
            }
        }
    }

    if (DEBUGGING) gLog->info("GetMatchingItems_Native: Function finished. Returning Array of size: {}", result.size());

    return result;
}
RE::BSTArray<RE::TESForm*> GetMatchingItems_Internal(RE::BSTArray<RE::TESForm*> aFormArray, std::int32_t aSlot)
{
    RE::BSTArray<RE::TESForm*> result;
    // Check if the array pointer is valid before proceeding.
    if (aFormArray.empty() || aFormArray.size() == 0) {
        return result;
    }
    // Make sure we only get Armor Forms
    RE::BSTArray<RE::TESForm*> armorArray = GetArmorItems_Internal(aFormArray);
    for (RE::TESForm* currentForm : armorArray) {
        if (currentForm == nullptr) {
            // Skip null forms
            continue;
        }
        RE::TESObjectARMO* armor = currentForm->As<RE::TESObjectARMO>();
        // Check if aSlot SlotMask fits into the overall SlotMask of the Armor
        if ((armor->bipedModelData.bipedObjectSlots & GetSlotMaskFromIndex_Internal(aSlot)) != 0) {
            if (IsArmorWeapon_Internal(currentForm)) {
                result.push_back(currentForm);
            }
        }
    }
    return result;
}
RE::BSTArray<RE::BGSInventoryItem*> GetMatchingItems_Internal(RE::BGSInventoryList* inventoryList, std::int32_t slot)
{
    RE::BSTArray<RE::BGSInventoryItem*> result;
    if (!inventoryList || inventoryList->data.empty()) {
        return result;
    }
    for (RE::BGSInventoryItem& item : inventoryList->data) {
        auto armor = item.object->As<RE::TESObjectARMO>();
        if (!armor) continue;
        if ((armor->bipedModelData.bipedObjectSlots & GetSlotMaskFromIndex_Internal(slot)) != 0) {
            if (IsArmorWeapon_Internal(&item)) {
                result.push_back(&item);
            }
        }
    }
    return result;
}

// Form[] Function GetWeaponItems(Form[] aFormArray) global native
RE::BSTArray<RE::TESForm*> GetWeaponItems_Native(std::monostate, RE::BSTArray<RE::TESForm*> aFormArray)
{
    RE::BSTArray<RE::TESForm*> weaponArray;

    // Check if the array pointer is valid before proceeding.
    if (aFormArray.empty() || aFormArray.size() == 0) {
        if (DEBUGGING) gLog->warn("GetWeaponItems_Native: Input array is empty or null. Returning empty array.");
        return weaponArray;
    }

    if (DEBUGGING) gLog->info("GetWeaponItems_Native: Function called with array size: {}", aFormArray.size());

    // Loop through each item in the input array
    for (RE::TESForm* currentForm : aFormArray) {
        if (currentForm == nullptr) {
            // Skip null forms
            if (DEBUGGING) gLog->warn("GetWeaponItems_Native: The current Form is nullptr!");
            continue;
        }

        // Check the Form Type
        if (currentForm->GetFormType() == RE::ENUM_FORM_ID::kWEAP) {
            weaponArray.push_back(currentForm);
        }
    }

    if (DEBUGGING) gLog->info("GetWeaponItems_Native: Total matching items found: {}.", weaponArray.size());

    return weaponArray;
}
RE::BSTArray<RE::BGSInventoryItem*> GetWeaponItems_Internal(RE::BGSInventoryList* inventoryList)
{
    RE::BSTArray<RE::BGSInventoryItem*> weaponArray;
    if (!inventoryList || inventoryList->data.empty()) {
        return weaponArray;
    }
    for (RE::BGSInventoryItem& item : inventoryList->data) {
        if (!item.object) continue;
        if (item.object->GetFormType() == RE::ENUM_FORM_ID::kWEAP) {
            weaponArray.push_back(&item);
        }
    }
    return weaponArray;
}

// Helper function to check if an armor has keywords
bool HasAnyKeyword_Internal(RE::TESForm* form, const std::vector<std::string>& keywords)
{
    auto armor = form->As<RE::TESObjectARMO>();
    auto weapon = form->As<RE::TESObjectWEAP>();
    for (const auto& kw : keywords) {
        if ((armor && armor->HasKeywordString(kw.c_str())) ||
            (weapon && weapon->HasKeywordString(kw.c_str()))) {
            return true;
        }
    }
    return false;
}

// bool Function IsArmorWeapon(Form aForm) global native
bool IsArmorWeapon_Native(std::monostate, RE::TESForm* aForm)
{
    // Check the form
    if (!aForm) {
        if (DEBUGGING) gLog->warn("IsArmorWeapon_Native: Input Form is NULL.");
        return false;
    }

    if (DEBUGGING) gLog->info("IsArmorWeapon_Native: Function called");

    // Exclude if any excluded keyword matches
    if (HasAnyKeyword_Internal(aForm, excludedKeywords)) return false;

    // If include list is not empty, require at least one included keyword
    if (!includedKeywords.empty() && !HasAnyKeyword_Internal(aForm, includedKeywords)) return false;

    // Exclude if FormID is in the excluded list
    if (IsFormIDExcluded_Internal(aForm->formID)) return false;

    // Check the Form Type
    if (aForm->GetFormType() == RE::ENUM_FORM_ID::kWEAP) {
        auto weapon = aForm->As<RE::TESObjectWEAP>();
        if (!weapon || weapon->weaponData.GetValue() <= 0) {
            if (DEBUGGING) gLog->warn("IsArmorWeapon_Native: Weapon has no value. Ignoring.");
            return false;
        }
        if (weapon && weapon->weaponData.ammo) {
            if (DEBUGGING) gLog->info("IsArmorWeapon_Native: Weapon uses Ammo: {:08X}.", weapon->weaponData.ammo->formID);
        }
        if (DEBUGGING) gLog->info("IsArmorWeapon_Native: Valid weapon {} Form: {:08X}.", weapon->GetFullName(), aForm->formID);
        return true;
    }

    // Check the Form Type
    if (aForm->GetFormType() == RE::ENUM_FORM_ID::kARMO) {
        auto armor = aForm->As<RE::TESObjectARMO>();
        if (!armor || armor->armorData.GetValue() <= 0) {
            if (DEBUGGING) gLog->warn("IsArmorWeapon_Native: Armor has no value. Ignoring.");
            return false;
        }
        if (&armor->bipedModelData == nullptr || armor->bipedModelData.bipedObjectSlots == 0 || armor->bipedModelData.bipedObjectSlots > maxAllowedSlotmask) {
            if (DEBUGGING) gLog->warn("IsArmorWeapon_Native: Armor has no or excluded equip slotmask. Ignoring.");
            return false;
        }
        if (DEBUGGING) gLog->info("IsArmorWeapon_Native: Valid armor {} Form: {:08X}.", armor->GetFullName(), aForm->formID);
        return true;
    }

    return false;
}
bool IsArmorWeapon_Internal(RE::TESForm* aForm)
{
    // Check the form
    if (!aForm) {
        return false;
    }
    // Exclude if any excluded keyword matches
    if (HasAnyKeyword_Internal(aForm, excludedKeywords)) return false;
    // If include list is not empty, require at least one included keyword
    if (!includedKeywords.empty() && !HasAnyKeyword_Internal(aForm, includedKeywords)) return false;
    // Exclude if FormID is in the excluded list
    if (IsFormIDExcluded_Internal(aForm->formID)) return false;
    // Check the Form Type
    if (aForm->GetFormType() == RE::ENUM_FORM_ID::kWEAP) {
        auto weapon = aForm->As<RE::TESObjectWEAP>();
        if (!weapon || weapon->weaponData.GetValue() <= 0) {
            return false;
        }
        return true;
    }
    // Check the Form Type
    if (aForm->GetFormType() == RE::ENUM_FORM_ID::kARMO) {
        auto armor = aForm->As<RE::TESObjectARMO>();
        if (!armor || armor->armorData.GetValue() <= 0) {
            return false;
        }
        if (&armor->bipedModelData == nullptr || armor->bipedModelData.bipedObjectSlots == 0 || armor->bipedModelData.bipedObjectSlots > maxAllowedSlotmask) {
            return false;
        }
        return true;
    }
    return false;
}
bool IsArmorWeapon_Internal(RE::BGSInventoryItem* aItem)
{
    if (!aItem || !aItem->object)
        return false;
    // Forward to the TESForm* version
    return IsArmorWeapon_Internal(aItem->object);
}

// Helper function to check if a FormID is in the excluded list
bool IsFormIDExcluded_Internal(uint32_t formID) {
    char buf[9];
    // Format as 8-digit uppercase hex
    snprintf(buf, sizeof(buf), "%08X", formID);
    for (const auto& idStr : excludedFormIDs) {
        // Case-insensitive compare
        if (_stricmp(idStr.c_str(), buf) == 0)
            return true;
    }
    return false;
}

// bool Function ItemMatchesSlot(Armor aArmor, Int aSlot) global native
bool ItemMatchesSlot_Native(std::monostate, RE::TESObjectARMO* aArmor, std::int32_t aSlot)
{
    // Check the form
    if (!aArmor) {
        if (DEBUGGING) gLog->warn("IsArmorWeapon_Native: Input Armor is NULL.");
        return false;
    }

    // Compare the SlotMasks
    if ((aArmor->bipedModelData.bipedObjectSlots & GetSlotMaskFromIndex_Internal(aSlot)) != 0) {
        return true;
    }

    return false;
}

// bool Function ProcessNPCArmor(ObjectReference aNPC, ObjectReference aContainer, Int aSlot) global native
bool ProcessNPCArmor_Native(std::monostate, RE::TESObjectREFR* aNPC, RE::TESObjectREFR* aContainer, std::int32_t aSlot)
{
    if (DEBUGGING) gLog->info("ProcessNPCArmor: Function called");

    // Check the object reference
    if (!aNPC || !aContainer) {
        if (DEBUGGING) gLog->warn("ProcessNPCArmor: aNPC or aContainer pointers is NULL. Cannot continue.");
        return false;
    }

    // Get NPC inventory and container inventory
    RE::BGSInventoryList* npcInventory = aNPC->inventoryList;
    RE::BGSInventoryList* containerInventory = aContainer->inventoryList;
    if (!npcInventory || !containerInventory) {
        if (DEBUGGING) gLog->warn("ProcessNPCArmor: Missing inventory list(s).");
        return false;
    }

    // Get matching armor items for the slot
    auto npcMatchingArmor = GetMatchingItems_Internal(npcInventory, aSlot);
    auto containerMatchingArmor = GetMatchingItems_Internal(containerInventory, aSlot);

    // Find best armor in each
    RE::BGSInventoryItem* bestNpcArmor = GetBestItem_Internal(npcMatchingArmor);
    RE::BGSInventoryItem* bestContainerArmor = GetBestItem_Internal(containerMatchingArmor);

    // Get their values
    int npcArmorValue = bestNpcArmor ? GetGoldPrice_Internal(bestNpcArmor->object) : 0;
    int containerArmorValue = bestContainerArmor ? GetGoldPrice_Internal(bestContainerArmor->object) : 0;

    // Decide if swap is needed
    if (bestContainerArmor && (containerArmorValue > npcArmorValue || !bestNpcArmor)) {
        // Use SwapItems_Internal for robust swapping
        RE::TESForm* oldItemForm = bestNpcArmor ? bestNpcArmor->object->As<RE::TESForm>() : nullptr;
        RE::TESForm* newItemForm = bestContainerArmor->object->As<RE::TESForm>();
        bool swapResult = SwapItems_Internal(aNPC, oldItemForm, newItemForm, aContainer);
        if (DEBUGGING) gLog->info("ProcessNPCArmor: Swapped armor items for slot {} using SwapItems_Internal", aSlot);
        return swapResult;
    }

    // No swap needed
    if (DEBUGGING) gLog->info("ProcessNPCArmor: No swap needed for slot {}", aSlot);
    return false;
}

// bool Function ProcessNPCArmor(ObjectReference aNPC, ObjectReference aContainer, Int aSlot) global native
bool ProcessNPCWeapon_Native(std::monostate, RE::TESObjectREFR* aNPC, RE::TESObjectREFR* aContainer)
{
    if (DEBUGGING) gLog->info("ProcessNPCWeapon: Function called");

    // Check the object reference
    if (!aNPC || !aContainer) {
        if (DEBUGGING) gLog->warn("ProcessNPCWeapon: aNPC or aContainer pointers is NULL. Cannot continue.");
        return false;
    }

    // Get NPC inventory and container inventory
    RE::BGSInventoryList* npcInventory = aNPC->inventoryList;
    RE::BGSInventoryList* containerInventory = aContainer->inventoryList;
    if (!npcInventory || !containerInventory) {
        if (DEBUGGING) gLog->warn("ProcessNPCWeapon: Missing inventory list(s).");
        return false;
    }

    // Get all weapon items
    auto npcInventoryWeapons = GetWeaponItems_Internal(npcInventory);
    auto containerInventoryWeapons = GetWeaponItems_Internal(containerInventory);

    // Find best weapon in each
    RE::BGSInventoryItem* bestNpcWeapon = GetBestItem_Internal(npcInventoryWeapons);
    RE::BGSInventoryItem* bestContainerWeapon = GetBestItem_Internal(containerInventoryWeapons);

    // Get their values
    int npcWeaponValue = bestNpcWeapon ? GetGoldPrice_Internal(bestNpcWeapon->object) : 0;
    int containerWeaponValue = bestContainerWeapon ? GetGoldPrice_Internal(bestContainerWeapon->object) : 0;

    // Decide if swap is needed
    if (bestContainerWeapon && (containerWeaponValue > npcWeaponValue || !bestNpcWeapon)) {
        // Use SwapItems_Internal for robust swapping
        RE::TESForm* oldItemForm = bestNpcWeapon ? bestNpcWeapon->object->As<RE::TESForm>() : nullptr;
        RE::TESForm* newItemForm = bestContainerWeapon->object->As<RE::TESForm>();
        bool swapResult = SwapItems_Internal(aNPC, oldItemForm, newItemForm, aContainer);
        if (DEBUGGING) gLog->info("ProcessNPCWeapon: Swapped weapon items using SwapItems_Internal.");
        return swapResult;
    }

    // No swap needed
    if (DEBUGGING) gLog->info("ProcessNPCWeapon: No swap needed.");
    return false;
}

// bool Function SetObjectName(ObjectReference aArmor, string aString) global native
bool SetObjectName_Native(std::monostate, RE::TESObjectREFR* aItemRef, RE::BSFixedString newName)
{
    // Check the object reference
    if (!aItemRef) {
        if (DEBUGGING) gLog->warn("SetObjectName_Native: Input TESObjectREFR is NULL. Cannot rename.");
        return false;
    }

    // Check the new name
    if (newName.data() == nullptr || newName.empty()) {
        if (DEBUGGING) gLog->warn("SetObjectName_Native: Input BSFixedString is NULL. Cannot rename.");
        return false;
    }

    if (DEBUGGING) gLog->info("SetObjectName_Native: Function called with Object name: {} And new name: {}.", aItemRef->GetDisplayFullName(), newName);

    // Check if the extraList is valid
    if (!aItemRef->extraList) {
        if (DEBUGGING) gLog->warn("SetObjectName_Native: Object does not have an extraList. Cannot rename.");
        return false;
    }

    // Rename the object
    aItemRef->extraList->SetOverrideName(newName.c_str());

    if (DEBUGGING) gLog->info("SetObjectName_Native: Function finished successful and the new TESObjectREFR name: {}", aItemRef->GetDisplayFullName());

    return true;
}

// Bool Function StringContains(string aString, string aSearchString) global native
bool StringContains_Native(std::monostate, RE::BSFixedString aString, RE::BSFixedString aSearchString)
{
    if (DEBUGGING) gLog->info("StringContains_Native: Function called with String {} - Contains {}.", aString, aSearchString);

    if (aString.data() == nullptr || aString.empty() || aSearchString.data() == nullptr || aSearchString.empty()) {
        if (DEBUGGING) gLog->warn("StringContains_Native: One or both Input Strings are null or empty.");
        return false;
    }

    return aString.contains(aSearchString);
}

// bool Function StripSettler(ObjectReference aNPC, ObjectReference aContainer) global native
bool StripSettler_Native(std::monostate, RE::TESObjectREFR* aNPC, RE::TESObjectREFR* aContainer)
{
    // Check the object reference
    if (!aNPC || !aContainer) {
        if (DEBUGGING) gLog->warn("StripSettler_Native: aNPC or aContainer pointers is NULL. Cannot continue.");
        return false;
    }

    // Get the inventory items
    RE::BGSInventoryList* itemList = aNPC->inventoryList;
    if (!itemList) {
        if (DEBUGGING) gLog->warn("StripSettler_Native: NPC has no inventory list. Cannot continue.");
        return false;
    }

    // uneqip all items first
    // This is problematic as it also removes power armor and clothing, which will not be re-equipped by this mod
    //aNPC->RemoveAllObjectsWorn();

    // Get a list of matching inventory items to remove
    RE::BSTArray<RE::BGSInventoryItem*> itemsToRemove;
    for (RE::BGSInventoryItem& currentItem : itemList->data) {
        RE::TESBoundObject* currentObject = currentItem.object;
        // Get the TESForm
        RE::TESForm* currentForm = currentObject->As<RE::TESForm>();
        // Check if Armor or Weapon
        if (IsArmorWeapon_Internal(currentForm)) {
            itemsToRemove.push_back(&currentItem);
        }
    }

    if (DEBUGGING) gLog->info("StripSettler_Native: Found {} items to strip.", itemsToRemove.size());

    // Go over the items to remove and transfer
    for (RE::BGSInventoryItem* itemToStrip : itemsToRemove) {
        if (DEBUGGING) gLog->info("StripSettler_Native: Moving item {:08X} to container, count: {}.", itemToStrip->object->formID, itemToStrip->stackData->GetCount());
        // Build the RemoveItemData
        RE::TESObjectREFR::RemoveItemData newData = BuildRemoveItemData_Internal(itemToStrip, aContainer, itemToStrip->stackData->GetCount());
        // Move the item
        aNPC->RemoveItem(newData);
    }

    if (DEBUGGING) gLog->info("StripSettler_Native: Function finished successfully.");

    return true;
}

// bool Function SwapItems(ObjectReference aNPC, Form aOldItem, Form aNewItem, ObjectReference aContainer) global native
bool SwapItems_Native(std::monostate, RE::TESObjectREFR* aNPC, RE::TESForm* aOldItem, RE::TESForm* aNewItem, RE::TESObjectREFR* aContainer)
{
    // Check the object reference
    if (!aNPC || !aContainer) {
        if (DEBUGGING) gLog->warn("SwapItems_Native: aNPC or aContainer pointers is NULL. Cannot continue.");
        return false;
    }

    // Check the object reference
    if (!aNewItem) {
        if (DEBUGGING) gLog->warn("SwapItems_Native: aNewItem pointer is NULL. Cannot continue.");
        return false;
    }

    // Declare the objects
    RE::TESBoundObject* newItemObject = nullptr;
    RE::TESBoundObject* oldItemObject = nullptr;

    // Move the items
    // aNewItem: aContainer -> aNPC
    newItemObject = aNewItem->As<RE::TESBoundObject>();
    RE::TESObjectREFR::RemoveItemData newItemRemoveItemData = BuildRemoveItemData_Internal(newItemObject, aNPC, 1);
    aContainer->RemoveItem(newItemRemoveItemData);
    if (DEBUGGING) gLog->info("SwapItems_Native: Moved new item from the container to the NPC, FormID: {:08X}", aNewItem->formID);
    if (aOldItem) {
        // aOldItem: aNPC -> aContainer
        oldItemObject = aOldItem->As<RE::TESBoundObject>();
        RE::TESObjectREFR::RemoveItemData oldItemRemoveItemData = BuildRemoveItemData_Internal(oldItemObject, aContainer, 1);
        aNPC->RemoveItem(oldItemRemoveItemData);
        if (DEBUGGING) gLog->info("SwapItems_Native: Moved new item from the container to the NPC, FormID: {:08X}", aOldItem->formID);
    }

    if (DEBUGGING) gLog->info("SwapItems_Native: Function finished successfully.");

    return true;
}
bool SwapItems_Internal(RE::TESObjectREFR* aNPC, RE::TESForm* aOldItem, RE::TESForm* aNewItem, RE::TESObjectREFR* aContainer)
{
    // Check the object reference
    if (!aNPC || !aContainer) {
        return false;
    }
    // Check the object reference
    if (!aNewItem) {
        return false;
    }
    // Declare the objects
    RE::TESBoundObject* newItemObject = nullptr;
    RE::TESBoundObject* oldItemObject = nullptr;
    // Move the items
    // aNewItem: aContainer -> aNPC
    newItemObject = aNewItem->As<RE::TESBoundObject>();
    RE::TESObjectREFR::RemoveItemData newItemRemoveItemData = BuildRemoveItemData_Internal(newItemObject, aNPC, 1);
    aContainer->RemoveItem(newItemRemoveItemData);
    if (aOldItem) {
        // aOldItem: aNPC -> aContainer
        oldItemObject = aOldItem->As<RE::TESBoundObject>();
        RE::TESObjectREFR::RemoveItemData oldItemRemoveItemData = BuildRemoveItemData_Internal(oldItemObject, aContainer, 1);
        aNPC->RemoveItem(oldItemRemoveItemData);
    }
    return true;
}

// Register all Papyrus functions
bool RegisterPapyrusFunctions(RE::BSScript::IVirtualMachine* vm) {
    if (DEBUGGING) gLog->info("RegisterPapyrusFunctions: Attempting to register Papyrus functions. VM pointer: {}", static_cast<const void*>(vm));

    // vm->BindNativeMethod("<Name of the script binding the function>", "<Name of the function in Papyrus>", <Name of the function in F4SE>, <can run parallel to Papyrus>);
    vm->BindNativeMethod("ES_API", "CombineArray", CombineArray_Native, true);
    vm->BindNativeMethod("ES_API", "EquipBestItems", EquipBestItems_Native, true);
    vm->BindNativeMethod("ES_API", "GetArmorItems", GetArmorItems_Native, true);
    vm->BindNativeMethod("ES_API", "GetBestArmor", GetBestArmor_Native, true);
    vm->BindNativeMethod("ES_API", "GetBestWeapon", GetBestWeapon_Native, true);
    vm->BindNativeMethod("ES_API", "GetGoldPrice", GetGoldPrice_Native, true);
    vm->BindNativeMethod("ES_API", "GetMatchingItems", GetMatchingItems_Native, true);
    vm->BindNativeMethod("ES_API", "GetWeaponItems", GetWeaponItems_Native, true);
    vm->BindNativeMethod("ES_API", "IsArmorWeapon", IsArmorWeapon_Native, true);
    vm->BindNativeMethod("ES_API", "ItemMatchesSlot", ItemMatchesSlot_Native, true);
    vm->BindNativeMethod("ES_API", "ProcessNPCArmor", ProcessNPCArmor_Native, true);
    vm->BindNativeMethod("ES_API", "ProcessNPCWeapon", ProcessNPCWeapon_Native, true);
    vm->BindNativeMethod("ES_API", "SetObjectName", SetObjectName_Native, true);
    vm->BindNativeMethod("ES_API", "StringContains", StringContains_Native, true);
    vm->BindNativeMethod("ES_API", "StripSettler", StripSettler_Native, true);
    vm->BindNativeMethod("ES_API", "SwapItems", SwapItems_Native, true);

    if (DEBUGGING) gLog->info("RegisterPapyrusFunctions: All Papyrus functions registration attempts completed.");

    return true;
}