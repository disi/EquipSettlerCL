#include <PCH.h>
#include <Global.h>

// Declare all functions here
bool AdminEquipSettlers_Native(std::monostate, std::vector<RE::TESObjectREFR*> aNPCs, RE::TESObjectREFR* aContainer);
bool AdminStripSettlers_Native(std::monostate, std::vector<RE::TESObjectREFR*> aNPCs, RE::TESObjectREFR* aContainer);
RE::TESObjectREFR::RemoveItemData BuildRemoveItemData_Internal(RE::BGSInventoryItem* aInventoryItem, RE::TESObjectREFR* aContainer, std::int32_t aCount);
RE::TESObjectREFR::RemoveItemData BuildRemoveItemData_Internal(RE::BGSInventoryItem* aInventoryItem, RE::TESObjectREFR* aContainer, std::uint32_t aCount);
RE::TESObjectREFR::RemoveItemData BuildRemoveItemData_Internal(RE::TESBoundObject* aInventoryItem, RE::TESObjectREFR* aContainer, std::int32_t aCount);
RE::BSTArray<RE::TESForm*> CombineArrayForm_Native(std::monostate, RE::BSTArray<RE::TESForm*> aFormArray1, RE::BSTArray<RE::TESForm*> aFormArray2);
RE::BSTArray<RE::TESObjectREFR*> CombineArrayObject_Native(std::monostate, RE::BSTArray<RE::TESObjectREFR*> aFormArray1, RE::BSTArray<RE::TESObjectREFR*> aFormArray2);
void EquipBestItems_Native(std::monostate, RE::TESObjectREFR* aNPC);
void EquipBestItems_Internal(RE::TESObjectREFR* aNPC);
void EquipBestItemsAll_Native(std::monostate, std::vector<RE::TESObjectREFR*> akNPC);
bool EquipInventoryItem_Internal(RE::TESObjectREFR* aNPC, RE::BGSInventoryItem* aInvItem);
RE::BSTArray<RE::TESObjectREFR*> FindAllObjectsWithAnyKeywords_Native(std::monostate, RE::TESObjectREFR* akRef, RE::BSTArray<RE::BGSKeyword*> akKeywords, float aRadius, bool shuffleResults);
RE::BSTArray<RE::TESObjectREFR*> FindNearbyWorkshopObjects_Native(std::monostate, RE::TESObjectREFR* akRef, float aRadius, bool shuffleResults);
RE::BSTArray<RE::TESObjectREFR*> FindSettlerNPC_Native(std::monostate, RE::TESObjectREFR* akRef, float aRadius, bool shuffleResults);
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
template <typename T>
std::optional<T> GetPapyrusProperty_Internal(RE::TESObjectREFR* ref, const std::string& scriptName, const std::string& propertyName);
std::uint32_t GetSlotMaskFromIndex_Internal(std::int32_t aiSlotIndex);
RE::BSTArray<RE::TESForm*> GetWeaponItems_Native(std::monostate, RE::BSTArray<RE::TESForm*> aFormArray);
RE::BSTArray<RE::BGSInventoryItem*> GetWeaponItems_Internal(RE::BGSInventoryList* inventoryList);
bool HasAnyKeyword_Internal(RE::TESForm* form, const std::vector<std::string>& keywords);
bool HasAnyKeyword_Internal(RE::TESObjectREFR* aRef, const std::vector<std::string>& keywords);
bool HasAnyKeyword_Internal(RE::TESForm* form, const std::unordered_set<std::string>& keywords);
bool HasAnyKeyword_Internal(RE::TESObjectREFR* aRef, const std::unordered_set<std::string>& keywords);
bool IsArmorWeapon_Native(std::monostate, RE::TESForm* aForm);
bool IsArmorWeapon_Internal(RE::TESForm* aForm);
bool IsArmorWeapon_Internal(RE::BGSInventoryItem* aItem);
bool SettingDebuggingEnabled_Native(std::monostate);
bool SettingAnimationEnabled_Native(std::monostate);
bool IsFormIDExcluded_Internal(uint32_t formID);
bool IsSettlerNPC_Native(std::monostate, RE::TESObjectREFR* aNPC);
bool IsSettlerNPC_Internal(RE::TESObjectREFR* aNPC);
bool ItemMatchesSlot_Native(std::monostate, RE::TESObjectARMO* aArmor, std::int32_t aSlot);
bool ProcessNPCArmor_Native(std::monostate, RE::TESObjectREFR* aNPC, RE::TESObjectREFR* aContainer);
bool ProcessNPCArmor_Internal(RE::TESObjectREFR* aNPC, RE::TESObjectREFR* aContainer);
bool PreProcessNPCArmor_Native(std::monostate, RE::TESObjectREFR* aNPC, RE::TESObjectREFR* aContainer);
bool ProcessNPCWeapon_Native(std::monostate, RE::TESObjectREFR* aNPC, RE::TESObjectREFR* aContainer);
bool ProcessNPCWeapon_Internal(RE::TESObjectREFR* aNPC, RE::TESObjectREFR* aContainer);
bool PreProcessNPCWeapon_Native(std::monostate, RE::TESObjectREFR* aNPC, RE::TESObjectREFR* aContainer);
bool SetObjectName_Native(std::monostate, RE::TESObjectREFR* aItemRef, RE::BSFixedString newName);
RE::BSTArray<RE::TESObjectREFR*> ShuffleArray_Native(std::monostate, RE::BSTArray<RE::TESObjectREFR*> aFormArray);
RE::BSTArray<RE::TESObjectREFR*> ShuffleArray_Internal(RE::BSTArray<RE::TESObjectREFR*> aFormArray);
bool StringContains_Native(std::monostate, RE::BSFixedString aString, RE::BSFixedString aSearchString);
bool SwapItems_Native(std::monostate, RE::TESObjectREFR* aNPC, RE::TESForm* aOldItem, RE::TESForm* aNewItem, RE::TESObjectREFR* aContainer);
bool SwapItems_Internal(RE::TESObjectREFR* aNPC, RE::BGSInventoryItem* aOldItem, RE::BGSInventoryItem* aNewItem, RE::TESObjectREFR* aContainer);
bool UnEquipInventoryItem_Internal(RE::TESObjectREFR* aNPC, RE::BGSInventoryItem* aInvItem);
void UpdateNPCVisual_Internal(RE::TESObjectREFR* aNPC);

// bool Function AdminEquipSettlers(ObjectReference[] aNPC, ObjectReference aContainer) global native
bool AdminEquipSettlers_Native(std::monostate, std::vector<RE::TESObjectREFR*> aNPCs, RE::TESObjectREFR* aContainer)
{
    if (DEBUGGING) gLog->info("AdminEquipSettlers_Native: Function called.");

    // Check the object reference
    if (aNPCs.empty() || !aContainer) {
        if (DEBUGGING) gLog->warn("AdminEquipSettlers_Native: NPC array is empty or container pointer is NULL. Cannot continue.");
        return false;
    }

    if (DEBUGGING) gLog->info("AdminEquipSettlers_Native: Starting to process {} NPCs.", aNPCs.size());
    // loop over all NPCs in the array
    for (auto* aNPC : aNPCs) {
        if (!aNPC) continue;

        // For each slot in slotOrder, process armor
        for (auto slot : slotOrder) {
            ProcessNPCArmor_Internal(aNPC, aContainer);
        }
        // For weapon, process once
        ProcessNPCWeapon_Internal(aNPC, aContainer);
        // Equip best items
        EquipBestItems_Internal(aNPC);
        // Refresh the NPC 3D model to reflect changes
        UpdateNPCVisual_Internal(aNPC);
    }

    if (DEBUGGING) gLog->info("AdminEquipSettlers_Native: Function finished successfully.");
    return true;
}

// bool Function AdminStripSettlers(ObjectReference[] aNPC, ObjectReference aContainer) global native
bool AdminStripSettlers_Native(std::monostate, std::vector<RE::TESObjectREFR*> aNPCs, RE::TESObjectREFR* aContainer)
{
    // Check the object reference
    if (aNPCs.empty() || !aContainer) {
        if (DEBUGGING) gLog->warn("AdminStripSettlers_Native: NPC array is empty or container pointer is NULL. Cannot continue.");
        return false;
    }

    for (auto* aNPC : aNPCs) {
        if (!aNPC) continue;

        // Get the inventory items
        RE::BGSInventoryList* itemList = aNPC->inventoryList;
        if (!itemList) {
            if (DEBUGGING) gLog->warn("AdminStripSettlers_Native: NPC has no inventory list. Cannot continue.");
            return false;
        }

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

        if (DEBUGGING) gLog->info("AdminStripSettlers_Native: Found {} items to strip.", itemsToRemove.size());

        // Go over the items to remove and transfer
        for (RE::BGSInventoryItem* itemToStrip : itemsToRemove) {
            if (DEBUGGING) gLog->info("AdminStripSettlers_Native: Moving item {:08X} to container, count: {}.", itemToStrip->object->formID, itemToStrip->stackData->GetCount());
            // Move the item to the container
            SwapItems_Internal(aNPC, itemToStrip, nullptr, aContainer);
        }
        // Refresh the NPC 3D model to reflect changes
        UpdateNPCVisual_Internal(aNPC);
    }

    if (DEBUGGING) gLog->info("AdminStripSettlers_Native: Function finished successfully.");

    return true;
}

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

    return newData;
}

// Form[] Function CombineArray(Form[] aFormArray1, Form[] aFormArray2) global native
RE::BSTArray<RE::TESForm*> CombineArrayForm_Native(std::monostate, RE::BSTArray<RE::TESForm*> aFormArray1, RE::BSTArray<RE::TESForm*> aFormArray2)
{
    RE::BSTArray<RE::TESForm*> combinedArray;

    if (DEBUGGING) gLog->info("CombineArrayForm_Native: Function called.");

    // Check if the first array is valid before iterating to prevent crashes on null arrays.
    if (!aFormArray1.empty() || aFormArray1.size() == 0) {
        if (DEBUGGING) gLog->info("CombineArrayForm_Native: Adding items from first array.");
        for (const auto& form : aFormArray1) {
            // Check for null forms inside the array to prevent crashes.
            if (form) {
                combinedArray.push_back(form);
            }
        }
    }

    // Check if the second array is valid before iterating.
    if (!aFormArray2.empty() || aFormArray2.size() == 0) {
        if (DEBUGGING) gLog->info("CombineArrayForm_Native: Adding items from second array.");
        for (const auto& form : aFormArray2) {
            // Check for null forms inside the array to prevent crashes.
            if (form) {
                combinedArray.push_back(form);
            }
        }
    }

    if (DEBUGGING) gLog->info("CombineArrayForm_Native: Combined array has {} forms.", combinedArray.size());

    // Shuffle the array before returning it
    std::shuffle(combinedArray.begin(), combinedArray.end(), std::mt19937{ std::random_device{}() });

    return combinedArray;
}

// Form[] Function CombineArray(Form[] aFormArray1, Form[] aFormArray2) global native
RE::BSTArray<RE::TESObjectREFR*> CombineArrayObject_Native(std::monostate, RE::BSTArray<RE::TESObjectREFR*> aFormArray1, RE::BSTArray<RE::TESObjectREFR*> aFormArray2)
{
    RE::BSTArray<RE::TESObjectREFR*> combinedArray;

    if (DEBUGGING) gLog->info("CombineArrayObject_Native: Function called.");

    // Check if the first array is valid before iterating to prevent crashes on null arrays.
    if (!aFormArray1.empty() || aFormArray1.size() == 0) {
        if (DEBUGGING) gLog->info("CombineArrayObject_Native: Adding items from first array.");
        for (const auto& form : aFormArray1) {
            // Check for null forms inside the array to prevent crashes.
            if (form) {
                combinedArray.push_back(form);
            }
        }
    }

    // Check if the second array is valid before iterating.
    if (!aFormArray2.empty() || aFormArray2.size() == 0) {
        if (DEBUGGING) gLog->info("CombineArrayObject_Native: Adding items from second array.");
        for (const auto& form : aFormArray2) {
            // Check for null forms inside the array to prevent crashes.
            if (form) {
                combinedArray.push_back(form);
            }
        }
    }

    if (DEBUGGING) gLog->info("CombineArrayObject_Native: Combined array has {} forms.", combinedArray.size());

    // Shuffle the array before returning it
    std::shuffle(combinedArray.begin(), combinedArray.end(), std::mt19937{ std::random_device{}() });

    return combinedArray;
}

// bool Function EquipBestItems(ObjectReference akNPC) global native
void EquipBestItems_Native(std::monostate, RE::TESObjectREFR* aNPC)
{
    if (DEBUGGING) gLog->info("EquipBestItems_Native: Function called.");

    if (!aNPC) {
        if (DEBUGGING) gLog->warn("EquipBestItems_Native: NPC reference is null.");
        return;
    }

    // Get the inventory items
    RE::BGSInventoryList* itemList = aNPC->inventoryList;
    if (!itemList) {
        if (DEBUGGING) gLog->warn("EquipBestItems_Native: NPC has no inventory list. Cannot continue.");
        return;
    }

    // Iterate over the armor slots and equip the best item for each slot
    for (int slot : slotOrder) {
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
                    if (invItem.object == weapon->weaponData.ammo && invItem.stackData->GetCount() >= ammoMin) {
                        hasAmmo = true;
                        break;
                    }
                }
            }
            // If not, add some ammo
            if (!hasAmmo) {
                if (DEBUGGING) gLog->info("EquipBestItems_Native: Adding ammo FormID: {:08X} to NPC inventory.", weapon->weaponData.ammo->GetFormID());
                aNPC->AddObjectToContainer(weapon->weaponData.ammo, nullptr, ammoRefill, nullptr, RE::ITEM_REMOVE_REASON::kStoreContainer);
            }
        }
        if (DEBUGGING) gLog->info("EquipBestItems_Native: Equipping best weapon FormID: {:08X}.", bestItem->object->GetFormID());
        if (EquipInventoryItem_Internal(aNPC, bestItem)) {
            if (DEBUGGING) gLog->info("EquipBestItems_Native: Successfully equipped weapon.");
        } else {
            if (DEBUGGING) gLog->warn("EquipBestItems_Native: Failed to equip weapon.");
        }
    } else {
        if (DEBUGGING) gLog->warn("EquipBestItems_Native: No best weapon found to equip.");
    }

    if (DEBUGGING) gLog->info("EquipBestItems_Native: Function finished.");
}
void EquipBestItems_Internal(RE::TESObjectREFR* aNPC)
{
    if (!aNPC) {
        return;
    }
    // Get the inventory items
    RE::BGSInventoryList* itemList = aNPC->inventoryList;
    if (!itemList) {
        return;
    }
    // Iterate over the armor slots and equip the best item for each slot
    for (int slot : slotOrder) {
        RE::BSTArray<RE::BGSInventoryItem*> matchingItems = GetMatchingItems_Internal(itemList, slot);
        RE::BSTArray<RE::BGSInventoryItem*> matchingArmorItems = GetArmorItems_Internal(matchingItems);
        if (matchingArmorItems.empty() || matchingArmorItems.size() == 0) {
                continue;
        }
        RE::BGSInventoryItem* bestItem = GetBestItem_Internal(matchingArmorItems);
        if (!bestItem || !bestItem->object) {
            continue;
        }
        EquipInventoryItem_Internal(aNPC, bestItem);
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
                    if (invItem.object == weapon->weaponData.ammo && invItem.stackData->GetCount() >= ammoMin) {
                        hasAmmo = true;
                        break;
                    }
                }
            }
            // If not, add some ammo
            if (!hasAmmo) {
                aNPC->AddObjectToContainer(weapon->weaponData.ammo, nullptr, ammoRefill, nullptr, RE::ITEM_REMOVE_REASON::kStoreContainer);
            }
        }
        EquipInventoryItem_Internal(aNPC, bestItem);
    }
}
// bool Function EquipBestItems(ObjectReference[] akNPC) global native
void EquipBestItemsAll_Native(std::monostate, std::vector<RE::TESObjectREFR*> akNPC)
{
    if (akNPC.empty() || akNPC.size() == 0) {
        if (DEBUGGING) gLog->warn("EquipBestItemsAll_Native: Input array is empty or null. Exiting function.");
        return;
    }

    if (DEBUGGING) gLog->info("EquipBestItemsAll_Native: Function called for {} NPC.", akNPC.size());

    for (auto* npc : akNPC) {
        if (npc) {
            EquipBestItems_Internal(npc);
        }
    }

    if (DEBUGGING) gLog->info("EquipBestItemsAll_Native: Function finished.");
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
        if (DEBUGGING) gLog->warn("EquipInventoryItem_Internal: No valid instanceData found for FormID: {:08X}", aInvItem->object->GetFormID());
        validStackID = 0;
        instanceData = nullptr;
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
        false            // locked
    );
    return true;
}

// ObjectReference[] Function FindAllObjectsWithAnyKeywords(ObjectReference akRef, FormList akKeywords, Int aRadius) global native
RE::BSTArray<RE::TESObjectREFR*> FindAllObjectsWithAnyKeywords_Native(std::monostate, RE::TESObjectREFR* akRef, RE::BSTArray<RE::BGSKeyword*> akKeywords, float aRadius, bool shuffleResults)
{
    if (DEBUGGING) gLog->info("FindAllObjectsWithAnyKeywords_Native: Function called.");

    RE::BSTArray<RE::TESObjectREFR*> foundObjects;

    if (!akRef) {
        if (DEBUGGING) gLog->warn("FindAllObjectsWithAnyKeywords_Native: NPC reference is null.");
        return foundObjects;
    }
    if (akKeywords.empty() || akKeywords.size() == 0) {
        if (DEBUGGING) gLog->warn("FindAllObjectsWithAnyKeywords_Native: Keyword list is null or empty.");
        return foundObjects;
    }
    if (aRadius <= 0.0f) {
        if (DEBUGGING) gLog->warn("FindAllObjectsWithAnyKeywords_Native: Radius is zero or negative.");
        return foundObjects;
    }

    // Get the worldspace and cell of the NPC
    RE::TESObjectCELL* cell = akRef->GetParentCell();
    if (!cell) {
        if (DEBUGGING) gLog->warn("FindAllObjectsWithAnyKeywords_Native: NPC has no parent cell.");
        return foundObjects;
    }

    // Get the position of the NPC
    RE::NiPoint3 npcPosition = akRef->GetPosition();

    // Get all forms in the cell
    const auto& formsPair = cell->GetAllForms();
    const auto* formsMap = formsPair.first;

    if (!formsMap) {
        if (DEBUGGING) gLog->warn("FindAllObjectsWithAnyKeywords_Native: No forms found in the cell.");
        return foundObjects;
    }

    // Iterate over all forms and check for references with matching keywords within the radius
    std::vector<std::pair<RE::TESObjectREFR*, float>> tempObjects;
    for (auto& entry : *formsMap) {
        RE::TESForm* form = entry.second;
        // early continue if form is null
        if (!form) continue;
        // We are only interested in references
        RE::TESObjectREFR* ref = form->As<RE::TESObjectREFR>();
        if (!ref || ref->IsDeleted() || ref->IsDisabled()) {
            continue;
        }
        // check distance
        float distance = npcPosition.GetDistance(ref->GetPosition());
        if (distance > aRadius) {
            continue;
        }
        //if (DEBUGGING) gLog->info("FindAllObjectsWithAnyKeywords_Native: Distance OK, checking keywords for reference FormID: {:08X}", ref->GetFormID());
        // check keywords
        RE::TESBoundObject* baseForm = ref->GetObjectReference();
        auto keywordForm = baseForm ? baseForm->As<RE::BGSKeywordForm>() : nullptr;
        if (!keywordForm) continue;
        for (uint32_t i = 0; i < keywordForm->numKeywords; ++i) {
            auto keyword = keywordForm->keywords[i];
            if (!keyword) continue;
            if (std::find(akKeywords.begin(), akKeywords.end(), keyword) != akKeywords.end()) {
                tempObjects.emplace_back(ref, distance);
                break;
            }
        }
    }

    // Sort by distance (closest first)
    std::sort(tempObjects.begin(), tempObjects.end(),
    [](const auto& a, const auto& b) { return a.second < b.second; });
    // Extract sorted references
    for (const auto& pair : tempObjects) {
        foundObjects.push_back(pair.first);
    }

    if (DEBUGGING) gLog->info("FindAllObjectsWithAnyKeywords_Native: Found {} matching active objects within radius {}.", foundObjects.size(), aRadius);

    // Shuffle the results if requested
    if (shuffleResults) {
        foundObjects = ShuffleArray_Internal(foundObjects);
    }

    // Remove any null entries to prevent crashes
    foundObjects.erase(std::remove(foundObjects.begin(), foundObjects.end(), nullptr), foundObjects.end());

    // Remove duplicates
    std::unordered_set<RE::TESObjectREFR*> uniqueSet;
    auto it = foundObjects.begin();
    while (it != foundObjects.end()) {
        if (!uniqueSet.insert(*it).second) {
            it = foundObjects.erase(it); // Duplicate found, erase
        } else {
            ++it;
        }
    }

    return foundObjects;
}

// ObjectReference[] Function FindNearbyWorkshopObjects(ObjectReference akRef, Float aRadius, Bool aShuffle) global native
RE::BSTArray<RE::TESObjectREFR*> FindNearbyWorkshopObjects_Native(std::monostate, RE::TESObjectREFR* akRef, float aRadius, bool shuffleResults)
{
    if (DEBUGGING) gLog->info("FindNearbyWorkshopObjects_Native: Function called.");

    RE::BSTArray<RE::TESObjectREFR*> foundObjects;

    if (!akRef) {
        if (DEBUGGING) gLog->warn("FindNearbyWorkshopObjects_Native: NPC reference is null.");
        return foundObjects;
    }
    if (aRadius <= 0.0f) {
        if (DEBUGGING) gLog->warn("FindNearbyWorkshopObjects_Native: Radius is zero or negative.");
        return foundObjects;
    }

    // Get the worldspace and cell of the NPC
    RE::TESObjectCELL* cell = akRef->GetParentCell();
    if (!cell) {
        if (DEBUGGING) gLog->warn("FindNearbyWorkshopObjects_Native: NPC has no parent cell.");
        return foundObjects;
    }

    // Get the position of the NPC
    RE::NiPoint3 npcPosition = akRef->GetPosition();

    // Get all forms in the cell
    const auto& formsPair = cell->GetAllForms();
    const auto* formsMap = formsPair.first;

    if (!formsMap) {
        if (DEBUGGING) gLog->warn("FindNearbyWorkshopObjects_Native: No forms found in the cell.");
        return foundObjects;
    }

    // Iterate over all forms and check for references with matching keywords within the radius
    std::vector<std::pair<RE::TESObjectREFR*, float>> tempObjects;
    for (auto& entry : *formsMap) {
        RE::TESForm* form = entry.second;
        // early continue if form is null
        if (!form) continue;
        // We are only interested in references
        RE::TESObjectREFR* ref = form->As<RE::TESObjectREFR>();
        if (!ref || ref->IsDeleted() || ref->IsDisabled()) {
            continue;
        }
        // check distance
        float distance = npcPosition.GetDistance(ref->GetPosition());
        if (distance > aRadius) {
            continue;
        }
        // check keywords
        if (!HasAnyKeyword_Internal(ref, workshopObjectKeywords)) {
            continue;
        }
        // if we reach this point, we have a match
        tempObjects.emplace_back(ref, distance);
    }

    // Sort by distance (closest first)
    std::sort(tempObjects.begin(), tempObjects.end(),
    [](const auto& a, const auto& b) { return a.second < b.second; });
    // Extract sorted references
    for (const auto& pair : tempObjects) {
        foundObjects.push_back(pair.first);
    }

    if (DEBUGGING) gLog->info("FindNearbyWorkshopObjects_Native: Found {} matching objects within radius {}.", foundObjects.size(), aRadius);

    // Shuffle the results if requested
    if (shuffleResults) {
        foundObjects = ShuffleArray_Internal(foundObjects);
    }

    // Remove any null entries to prevent crashes
    foundObjects.erase(std::remove(foundObjects.begin(), foundObjects.end(), nullptr), foundObjects.end());

    // Remove duplicates
    std::unordered_set<RE::TESObjectREFR*> uniqueSet;
    auto it = foundObjects.begin();
    while (it != foundObjects.end()) {
        if (!uniqueSet.insert(*it).second) {
            it = foundObjects.erase(it); // Duplicate found, erase
        } else {
            ++it;
        }
    }

    return foundObjects;
}

// ObjectReference[] Function FindSettlerNPC(ObjectReference akRef, Float aRadius, Bool aShuffle) global native
RE::BSTArray<RE::TESObjectREFR*> FindSettlerNPC_Native(std::monostate, RE::TESObjectREFR* akRef, float aRadius, bool shuffleResults)
{
    if (DEBUGGING) gLog->info("FindSettlerNPC_Native: Function called.");

    RE::BSTArray<RE::TESObjectREFR*> foundObjects;

    if (!akRef) {
        if (DEBUGGING) gLog->warn("FindSettlerNPC_Native: NPC reference is null.");
        return foundObjects;
    }
    if (aRadius <= 0.0f) {
        if (DEBUGGING) gLog->warn("FindSettlerNPC_Native: Radius is zero or negative.");
        return foundObjects;
    }
    // Get the worldspace and cell of the NPC
    RE::TESObjectCELL* cell = akRef->GetParentCell();
    if (!cell) {
        return foundObjects;
    }
    // Get the position of the NPC
    RE::NiPoint3 npcPosition = akRef->GetPosition();
    // Get all forms in the cell
    const auto& formsPair = cell->GetAllForms();
    const auto* formsMap = formsPair.first;
    if (!formsMap) {
        return foundObjects;
    }
    // Iterate over all forms and check for references with matching keywords within the radius
    std::vector<std::pair<RE::TESObjectREFR*, float>> tempObjects;
    for (auto& entry : *formsMap) {
        RE::TESForm* form = entry.second;
        // early continue if form is null
        if (!form) continue;
        // We are only interested in references
        RE::TESObjectREFR* ref = form->As<RE::TESObjectREFR>();
        if (!ref || ref->IsDeleted() || ref->IsDisabled()) {
            continue;
        }
        // check distance
        float distance = npcPosition.GetDistance(ref->GetPosition());
        if (distance > aRadius) {
            continue;
        }
        // check the race for keywords
        auto* actor = ref->As<RE::Actor>();
        if (!actor) continue;
        RE::TESRace* race = actor->race;
        if (!HasAnyKeyword_Internal(race, npcInclude)) {
            continue;
        }
        // check if settler NPC
        if (!IsSettlerNPC_Internal(ref)) {
            continue;
        }
        // if we reach this point, we have a match
        tempObjects.emplace_back(ref, distance);
    }

    // Sort by distance (closest first)
    std::sort(tempObjects.begin(), tempObjects.end(),
    [](const auto& a, const auto& b) { return a.second < b.second; });
    // Extract sorted references
    for (const auto& pair : tempObjects) {
        foundObjects.push_back(pair.first);
    }

    if (DEBUGGING) gLog->info("FindSettlerNPC_Native: Found {} matching active actors within radius {}.", foundObjects.size(), aRadius);

    // Shuffle the results if requested
    if (shuffleResults) {
        foundObjects = ShuffleArray_Internal(foundObjects);
    }

    // Remove any null entries to prevent crashes
    foundObjects.erase(std::remove(foundObjects.begin(), foundObjects.end(), nullptr), foundObjects.end());

    // Remove duplicates
    std::unordered_set<RE::TESObjectREFR*> uniqueSet;
    auto it = foundObjects.begin();
    while (it != foundObjects.end()) {
        if (!uniqueSet.insert(*it).second) {
            it = foundObjects.erase(it); // Duplicate found, erase
        } else {
            ++it;
        }
    }

    return foundObjects;
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
        if (!IsArmorWeapon_Internal(currentForm)) {
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
        if (!IsArmorWeapon_Internal(currentForm)) {
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
        if (!IsArmorWeapon_Internal(form)) {
            continue;
        }
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

// Helper to get a Papyrus property value from a script attached to a ref
template <typename T>
std::optional<T> GetPapyrusProperty_Internal(RE::TESObjectREFR* ref, const std::string& scriptName, const std::string& propertyName)
{
    if (!ref) return std::nullopt;
    // Get the vm and handle
    auto gameVM = RE::GameVM::GetSingleton();
    auto vm = gameVM->GetVM();
    if (!vm) return std::nullopt;
    std::uint32_t type = static_cast<std::uint32_t>(ref->GetFormType());
    std::size_t handle = gameVM->handlePolicy.GetHandleForObject(type, ref);
    if (!handle) return std::nullopt;
    // Get the script object
    RE::BSTSmartPointer<RE::BSScript::Object> scriptObj;
    if (vm->FindBoundObject(handle, scriptName.c_str(), true, scriptObj, false)) {
        auto typeInfo = scriptObj->GetTypeInfo();
        if (typeInfo) {
            // Get the property index
            std::uint32_t propertyIndex = typeInfo->GetPropertyIndex(propertyName);
            if (propertyIndex && propertyIndex > 0) {
                // Get the property value
                RE::BSScript::Variable var;
                if (vm->GetVariableValue(scriptObj, propertyIndex, var)) {
                    if (var.is<T>()) {
                        return RE::BSScript::get<T>(var);
                    }
                }
            }
        }
    }
    // Nothing found
    return std::nullopt;
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
        if (!IsArmorWeapon_Internal(currentForm)) {
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
        if (!IsArmorWeapon_Internal(item.object)) {
            continue;
        }
        if (item.object->GetFormType() == RE::ENUM_FORM_ID::kWEAP) {
            weaponArray.push_back(&item);
        }
    }
    return weaponArray;
}

// Helper function to check if the form has any of the keywords - case insensitive
bool HasAnyKeyword_Internal(RE::TESForm* form, const std::vector<std::string>& keywords)
{
    if (!form) return false;
    auto* keywordForm = form->As<RE::BGSKeywordForm>();
    if (!keywordForm) return false;
    for (uint32_t i = 0; i < keywordForm->numKeywords; ++i) {
        auto* keyword = keywordForm->keywords[i];
        if (!keyword) continue;
        const char* editorID = keyword->GetFormEditorID();
        if (!editorID) continue;
        std::string editorIDLower(editorID);
        std::transform(editorIDLower.begin(), editorIDLower.end(), editorIDLower.begin(), ::tolower);
        for (const auto& kw : keywords) {
            std::string kwLower(kw);
            std::transform(kwLower.begin(), kwLower.end(), kwLower.begin(), ::tolower);
            if (editorIDLower == kwLower) {
                return true;
            }
        }
    }
    return false;
}
bool HasAnyKeyword_Internal(RE::TESObjectREFR* aRef, const std::vector<std::string>& keywords)
{
    if (!aRef) return false;
    RE::TESBoundObject* baseForm = aRef->GetObjectReference();
    auto* keywordForm = baseForm ? baseForm->As<RE::BGSKeywordForm>() : nullptr;
    if (!keywordForm) return false;
    for (uint32_t i = 0; i < keywordForm->numKeywords; ++i) {
        auto* keyword = keywordForm->keywords[i];
        if (!keyword) continue;
        const char* editorID = keyword->GetFormEditorID();
        if (!editorID) continue;
        std::string editorIDLower(editorID);
        std::transform(editorIDLower.begin(), editorIDLower.end(), editorIDLower.begin(), ::tolower);
        for (const auto& kw : keywords) {
            std::string kwLower(kw);
            std::transform(kwLower.begin(), kwLower.end(), kwLower.begin(), ::tolower);
            if (editorIDLower == kwLower) {
                return true;
            }
        }
    }
    return false;
}
bool HasAnyKeyword_Internal(RE::TESForm* form, const std::unordered_set<std::string>& keywords)
{
    if (!form) return false;
    auto* keywordForm = form->As<RE::BGSKeywordForm>();
    if (!keywordForm) return false;
    for (uint32_t i = 0; i < keywordForm->numKeywords; ++i) {
        auto* keyword = keywordForm->keywords[i];
        if (!keyword) continue;
        const char* editorID = keyword->GetFormEditorID();
        if (!editorID) continue;
        std::string editorIDLower(editorID);
        std::transform(editorIDLower.begin(), editorIDLower.end(), editorIDLower.begin(), ::tolower);
        if (keywords.find(editorIDLower) != keywords.end()) {
            return true;
        }
    }
    return false;
}
bool HasAnyKeyword_Internal(RE::TESObjectREFR* aRef, const std::unordered_set<std::string>& keywords)
{
    if (!aRef) return false;
    RE::TESBoundObject* baseForm = aRef->GetObjectReference();
    auto* keywordForm = baseForm ? baseForm->As<RE::BGSKeywordForm>() : nullptr;
    if (!keywordForm) return false;
    for (uint32_t i = 0; i < keywordForm->numKeywords; ++i) {
        auto* keyword = keywordForm->keywords[i];
        if (!keyword) continue;
        const char* editorID = keyword->GetFormEditorID();
        if (!editorID) continue;
        std::string editorIDLower(editorID);
        std::transform(editorIDLower.begin(), editorIDLower.end(), editorIDLower.begin(), ::tolower);
        if (keywords.find(editorIDLower) != keywords.end()) {
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

// bool Function IsSettlerNPC(ObjectReference aNPC) global native
bool IsSettlerNPC_Native(std::monostate, RE::TESObjectREFR* aNPC)
{
    if (DEBUGGING) gLog->info("IsSettlerNPC_Native: Function called");

    // Check the object reference
    if (!aNPC) {
        if (DEBUGGING) gLog->warn("IsSettlerNPC_Native: Input NPC is NULL.");
        return false;
    }

    auto actor = aNPC->As<RE::Actor>();
    if (!actor) {
        if (DEBUGGING) gLog->warn("IsSettlerNPC_Native: Input NPC is not an Actor.");
        return false;
    }

    // Pre-checks on the NPC
    if (actor->IsDeleted()) {
        if (DEBUGGING) gLog->warn("IsSettlerNPC_Native: The NPC is deleted. Ignoring.");
        return false;
    }
    if (actor->IsDisabled()) {
        if (DEBUGGING) gLog->warn("IsSettlerNPC_Native: The NPC is disabled. Ignoring.");
        return false;
    }
    if (actor->IsDead(false)) {
        if (DEBUGGING) gLog->warn("IsSettlerNPC_Native: The NPC is dead. Ignoring.");
        return false;
    }
    if (actor->IsChild()) {
        if (DEBUGGING) gLog->warn("IsSettlerNPC_Native: The NPC is a child. Ignoring.");
        return false;
    }
    if (actor->IsPlayer()) {
        if (DEBUGGING) gLog->warn("IsSettlerNPC_Native: The NPC is the player. Ignoring.");
        return false;
    }
    if (actor->IsInCombat()) {
        if (DEBUGGING) gLog->warn("IsSettlerNPC_Native: The NPC is in combat. Ignoring.");
        return false;
    }
    RE::Actor* player = RE::PlayerCharacter::GetSingleton();
    if (!player) {
        if (DEBUGGING) gLog->warn("IsSettlerNPC_Native: Could not get player Actor.");
    } else if (actor->GetHostileToActor(player)) {
        if (DEBUGGING) gLog->warn("IsSettlerNPC_Native: The NPC is hostile to the player. Ignoring.");
        return false;
    }

    // Check if NPC's EditorID is in npcExclude
    if (const char* actorEditorID = actor->GetFormEditorID()) {
        //if (DEBUGGING) gLog->info("IsSettlerNPC_Native: Found NPC FormID {:08X} with EditorID {}.", actor->formID, actorEditorID);
        std::string editorIDLower(actorEditorID);
        std::transform(editorIDLower.begin(), editorIDLower.end(), editorIDLower.begin(), ::tolower);
        for (const auto& excludeID : npcExclude) {
            if (editorIDLower.find(excludeID) != std::string::npos) {
                if (DEBUGGING) gLog->warn("IsSettlerNPC_Native: The NPC EditorID {} is in the exclude list. Ignoring.", actorEditorID);
                return false;
            }
        }
    }
    
    // Get the Actor's factions
    std::vector<std::string> factionEditorIDs;
    auto npc = actor->GetNPC();
    if (npc) {
        //if (DEBUGGING) gLog->info("IsSettlerNPC_Native: Found NPC FormID {:08X} with {} factions.", npc->formID, npc->factions.size());
        for (auto& factionData : npc->factions) {
            RE::TESFaction* faction = factionData.faction;
            const char* editorID = faction ? faction->GetFormEditorID() : nullptr;
            if (DEBUGGING && faction) {
                //gLog->info("IsSettlerNPC_Native: Found Faction FormID {:08X} with EditorID {}.", faction->formID, faction->GetFormEditorID());
            }
            if (!editorID) continue;
            factionEditorIDs.emplace_back(editorID);
        }
    } else {
        return false;
    }

    // Faction checks
    if (includeFaction.empty() || includeFaction.size() == 0) {
        if (DEBUGGING) gLog->warn("IsSettlerNPC_Native: No faction includeFaction filter set, passing No NPCs.");
        return false;
    } else {
        // Check if any of the NPC's factions are in the include list and not in the exclude list
        bool included = includeFaction.empty();
        for (const std::string& factionEditorID : factionEditorIDs) {
            std::string factionEditorIDLower = factionEditorID;
            std::transform(factionEditorIDLower.begin(), factionEditorIDLower.end(), factionEditorIDLower.begin(), ::tolower);
            if (includeFaction.find(factionEditorIDLower) != includeFaction.end())
                included = true;
            if (excludeFaction.find(factionEditorIDLower) != excludeFaction.end())
                return false;
        }
        if (!included) return false;
    }

    if (DEBUGGING) gLog->info("IsSettlerNPC_Native: NPC FormID {:08X} passed faction checks.", aNPC->formID);

    // All tests passed
    return true;
}
bool IsSettlerNPC_Internal(RE::TESObjectREFR* aNPC)
{
    // Check the object reference
    if (!aNPC) {
        return false;
    }
    auto actor = aNPC->As<RE::Actor>();
    if (!actor) {
        return false;
    }
    // Pre-checks on the NPC
    if (actor->IsDeleted()) {
        return false;
    }
    if (actor->IsDisabled()) {
        return false;
    }
    if (actor->IsDead(false)) {
        return false;
    }
    if (actor->IsChild()) {
        return false;
    }
    if (actor->IsPlayer()) {
        return false;
    }
    if (actor->IsInCombat()) {
        return false;
    }
    RE::Actor* player = RE::PlayerCharacter::GetSingleton();
    if (!player) {
        return false;
    } else if (actor->GetHostileToActor(player)) {
        return false;
    }
    // Check if NPC's EditorID is in npcExclude
    if (const char* actorEditorID = actor->GetFormEditorID()) {
        std::string editorIDLower(actorEditorID);
        std::transform(editorIDLower.begin(), editorIDLower.end(), editorIDLower.begin(), ::tolower);
        for (const auto& excludeID : npcExclude) {
            if (editorIDLower.find(excludeID) != std::string::npos) {
                if (DEBUGGING) gLog->warn("IsSettlerNPC_Internal: The NPC EditorID {} is in the exclude list. Ignoring.", actorEditorID);
                return false;
            }
        }
    }
    // Get the Actor's factions
    std::vector<std::string> factionEditorIDs;
    auto npc = actor->GetNPC();
    if (npc) {
        for (auto& factionData : npc->factions) {
            RE::TESFaction* faction = factionData.faction;
            const char* editorID = faction ? faction->GetFormEditorID() : nullptr;
            if (DEBUGGING && faction) {
            }
            if (!editorID) continue;
            factionEditorIDs.emplace_back(editorID);
        }
    } else {
        return false;
    }
    // Faction checks
    if (includeFaction.empty() || includeFaction.size() == 0) {
        return false;
    } else {
        // Check if any of the NPC's factions are in the include list and not in the exclude list
        bool included = includeFaction.empty();
        for (const std::string& factionEditorID : factionEditorIDs) {
            std::string factionEditorIDLower = factionEditorID;
            std::transform(factionEditorIDLower.begin(), factionEditorIDLower.end(), factionEditorIDLower.begin(), ::tolower);
            if (includeFaction.find(factionEditorIDLower) != includeFaction.end())
                included = true;
            if (excludeFaction.find(factionEditorIDLower) != excludeFaction.end())
                return false;
        }
        if (!included) return false;
    }

    // This NPC is in the correct factions and should have a WorkshopNPCScript attached
    bool bIsGuard = GetPapyrusProperty_Internal<bool>(aNPC, "WorkshopNPCScript", "bIsGuard").value_or(false);
    if (DEBUGGING) gLog->info("IsSettlerNPC_Internal: Retrieved bIsGuard value: {} for NPC FormID {:08X}.", bIsGuard, aNPC->formID);
    // This is not working yet
    //int workshopID = GetPapyrusProperty_Internal<int>(aNPC, "WorkshopNPCScript", "workshopID").value_or(0);
    //if (DEBUGGING) gLog->info("IsSettlerNPC_Internal: Retrieved workshopID value: {} for NPC FormID {:08X}.", workshopID, aNPC->formID);

    // All tests passed
    return true;
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

// bool Function ProcessNPCArmor(ObjectReference aNPC, ObjectReference aContainer) global native
bool ProcessNPCArmor_Native(std::monostate, RE::TESObjectREFR* aNPC, RE::TESObjectREFR* aContainer)
{
    if (DEBUGGING) gLog->info("ProcessNPCArmor_Native: Function called");

    // Check the object reference
    if (!aNPC || !aContainer) {
        if (DEBUGGING) gLog->warn("ProcessNPCArmor_Native: aNPC or aContainer pointers is NULL. Cannot continue.");
        return false;
    }

    // Get NPC inventory and container inventory
    RE::BGSInventoryList* npcInventory = aNPC->inventoryList;
    RE::BGSInventoryList* containerInventory = aContainer->inventoryList;
    if (!npcInventory || !containerInventory) {
        if (DEBUGGING) gLog->warn("ProcessNPCArmor_Native: Missing inventory list(s).");
        return false;
    }

    // Iterate over each slot in the defined order
    bool anySwapped = false;
    int swapped = 0;
    for (int slot : slotOrder) {
        auto npcMatchingArmor = GetMatchingItems_Internal(npcInventory, slot);
        auto containerMatchingArmor = GetMatchingItems_Internal(containerInventory, slot);
        if (npcMatchingArmor.empty() && containerMatchingArmor.empty()) {
            if (DEBUGGING) gLog->info("ProcessNPCArmor_Native: No matching armor found for slot {}. Skipping.", slot);
            continue;
        }
        RE::BGSInventoryItem* bestNpcArmor = GetBestItem_Internal(npcMatchingArmor);
        RE::BGSInventoryItem* bestContainerArmor = GetBestItem_Internal(containerMatchingArmor);

        int npcArmorValue = bestNpcArmor ? GetGoldPrice_Internal(bestNpcArmor->object) : 0;
        int containerArmorValue = bestContainerArmor ? GetGoldPrice_Internal(bestContainerArmor->object) : 0;
        // Decide if swap is needed
        if (bestContainerArmor && (containerArmorValue > npcArmorValue || !bestNpcArmor)) {
            bool swapResult = SwapItems_Internal(aNPC, bestNpcArmor, bestContainerArmor, aContainer);
            if (DEBUGGING) gLog->info("ProcessNPCArmor_Native: Swapped armor items for slot {} using SwapItems_Internal", slot);
            if (armorSlotsPerCycle == 1) {
                return swapResult;
            }
            if (swapResult) {
                swapped++;
                anySwapped = true;
                if (swapped >= armorSlotsPerCycle && armorSlotsPerCycle > 0) {
                    if (DEBUGGING) gLog->info("ProcessNPCArmor_Native: Reached armorSlotsPerCycle of {}. Ending processing.", armorSlotsPerCycle);
                    return true;
                }
            }
        }
    }

    if (DEBUGGING) gLog->info("ProcessNPCArmor_Native: Cycle for all slots finished, Did a swap occur: {}", anySwapped);
    return anySwapped;
}
bool ProcessNPCArmor_Internal(RE::TESObjectREFR* aNPC, RE::TESObjectREFR* aContainer)
{
    // Check the object reference
    if (!aNPC || !aContainer) {
        return false;
    }
    // Get NPC inventory and container inventory
    RE::BGSInventoryList* npcInventory = aNPC->inventoryList;
    RE::BGSInventoryList* containerInventory = aContainer->inventoryList;
    if (!npcInventory || !containerInventory) {
        return false;
    }
    // Iterate over each slot in the defined order
    bool anySwapped = false;
    int swapped = 0;
    for (int slot : slotOrder) {
        auto npcMatchingArmor = GetMatchingItems_Internal(npcInventory, slot);
        auto containerMatchingArmor = GetMatchingItems_Internal(containerInventory, slot);
        if (npcMatchingArmor.empty() && containerMatchingArmor.empty()) {
            continue;
        }
        RE::BGSInventoryItem* bestNpcArmor = GetBestItem_Internal(npcMatchingArmor);
        RE::BGSInventoryItem* bestContainerArmor = GetBestItem_Internal(containerMatchingArmor);
        int npcArmorValue = bestNpcArmor ? GetGoldPrice_Internal(bestNpcArmor->object) : 0;
        int containerArmorValue = bestContainerArmor ? GetGoldPrice_Internal(bestContainerArmor->object) : 0;
        // Decide if swap is needed
        if (bestContainerArmor && (containerArmorValue > npcArmorValue || !bestNpcArmor)) {
            bool swapResult = SwapItems_Internal(aNPC, bestNpcArmor, bestContainerArmor, aContainer);
            if (armorSlotsPerCycle == 1) {
                return swapResult;
            }
            if (swapResult) {
                swapped++;
                anySwapped = true;
                if (swapped >= armorSlotsPerCycle && armorSlotsPerCycle > 0) {
                    return true;
                }
            }
        }
    }
    return anySwapped;
}
bool PreProcessNPCArmor_Native(std::monostate, RE::TESObjectREFR* aNPC, RE::TESObjectREFR* aContainer)
{
    if (DEBUGGING) gLog->info("PreProcessNPCArmor_Native: Function called");

    // Check the object reference
    if (!aNPC || !aContainer) {
        return false;
    }
    // Get NPC inventory and container inventory
    RE::BGSInventoryList* npcInventory = aNPC->inventoryList;
    RE::BGSInventoryList* containerInventory = aContainer->inventoryList;
    if (!npcInventory || !containerInventory) {
        return false;
    }
    // Iterate over each slot in the defined order
    for (int slot : slotOrder) {
        auto npcMatchingArmor = GetMatchingItems_Internal(npcInventory, slot);
        auto containerMatchingArmor = GetMatchingItems_Internal(containerInventory, slot);
        if (npcMatchingArmor.empty() && containerMatchingArmor.empty()) {
            continue;
        }
        RE::BGSInventoryItem* bestNpcArmor = GetBestItem_Internal(npcMatchingArmor);
        RE::BGSInventoryItem* bestContainerArmor = GetBestItem_Internal(containerMatchingArmor);
        int npcArmorValue = bestNpcArmor ? GetGoldPrice_Internal(bestNpcArmor->object) : 0;
        int containerArmorValue = bestContainerArmor ? GetGoldPrice_Internal(bestContainerArmor->object) : 0;
        // Decide if swap is needed
        if (bestContainerArmor && (containerArmorValue > npcArmorValue || !bestNpcArmor)) {
            // Return true that a swap is needed
            return true;
        }
    }
    // No swap needed
    if (DEBUGGING) gLog->info("PreProcessNPCArmor_Native: No swap needed for any slot.");
    return false;
}

// bool Function ProcessNPCArmor(ObjectReference aNPC, ObjectReference aContainer) global native
bool ProcessNPCWeapon_Native(std::monostate, RE::TESObjectREFR* aNPC, RE::TESObjectREFR* aContainer)
{
    if (DEBUGGING) gLog->info("ProcessNPCWeapon_Native: Function called");

    // Check the object reference
    if (!aNPC || !aContainer) {
        if (DEBUGGING) gLog->warn("ProcessNPCWeapon_Native: aNPC or aContainer pointers is NULL. Cannot continue.");
        return false;
    }

    // Get NPC inventory and container inventory
    RE::BGSInventoryList* npcInventory = aNPC->inventoryList;
    RE::BGSInventoryList* containerInventory = aContainer->inventoryList;
    if (!npcInventory || !containerInventory) {
        if (DEBUGGING) gLog->warn("ProcessNPCWeapon_Native: Missing inventory list(s).");
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
        bool swapResult = SwapItems_Internal(aNPC, bestNpcWeapon, bestContainerWeapon, aContainer);
        if (DEBUGGING) gLog->info("ProcessNPCWeapon_Native: Swapped weapon items using SwapItems_Internal.");
        return swapResult;
    }

    // No swap needed
    if (DEBUGGING) gLog->info("ProcessNPCWeapon_Native: No swap needed.");
    return false;
}
bool ProcessNPCWeapon_Internal(RE::TESObjectREFR* aNPC, RE::TESObjectREFR* aContainer)
{
    // Check the object reference
    if (!aNPC || !aContainer) {
        return false;
    }
    // Get NPC inventory and container inventory
    RE::BGSInventoryList* npcInventory = aNPC->inventoryList;
    RE::BGSInventoryList* containerInventory = aContainer->inventoryList;
    if (!npcInventory || !containerInventory) {
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
        bool swapResult = SwapItems_Internal(aNPC, bestNpcWeapon, bestContainerWeapon, aContainer);
        return swapResult;
    }
    // No swap needed
    return false;
}
bool PreProcessNPCWeapon_Native(std::monostate, RE::TESObjectREFR* aNPC, RE::TESObjectREFR* aContainer)
{
    if (DEBUGGING) gLog->info("PreProcessNPCWeapon_Native: Function called");

    // Check the object reference
    if (!aNPC || !aContainer) {
        return false;
    }
    // Get NPC inventory and container inventory
    RE::BGSInventoryList* npcInventory = aNPC->inventoryList;
    RE::BGSInventoryList* containerInventory = aContainer->inventoryList;
    if (!npcInventory || !containerInventory) {
        return false;
    }
    // Get all weapon items
    auto npcInventoryWeapons = GetWeaponItems_Internal(npcInventory);
    auto containerInventoryWeapons = GetWeaponItems_Internal(containerInventory);
    // If either inventory has no weapons, skip processing
    if (npcInventoryWeapons.empty() || containerInventoryWeapons.empty()) {
        return false;
    }
    // Find best weapon in each
    RE::BGSInventoryItem* bestNpcWeapon = GetBestItem_Internal(npcInventoryWeapons);
    RE::BGSInventoryItem* bestContainerWeapon = GetBestItem_Internal(containerInventoryWeapons);
    // Get their values
    int npcWeaponValue = bestNpcWeapon ? GetGoldPrice_Internal(bestNpcWeapon->object) : 0;
    int containerWeaponValue = bestContainerWeapon ? GetGoldPrice_Internal(bestContainerWeapon->object) : 0;
    // Decide if swap is needed
    if (bestContainerWeapon && (containerWeaponValue > npcWeaponValue || !bestNpcWeapon)) {
        // Return true that a swap is needed
        return true;
    }
    // No swap needed
    if (DEBUGGING) gLog->info("PreProcessNPCWeapon_Native: No swap needed.");
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

// bool Function SettingDebuggingEnabled() global native
bool SettingDebuggingEnabled_Native(std::monostate)
{
    return DEBUGGING;
}

// bool Function SettingAnimationEnabled() global native
bool SettingAnimationEnabled_Native(std::monostate)
{
    return ANIMATION;
}

// ObjectReference[] Function ShuffleArray(ObjectReference[] aFormArray) global native
RE::BSTArray<RE::TESObjectREFR*> ShuffleArray_Native(std::monostate, RE::BSTArray<RE::TESObjectREFR*> aFormArray)
{
    // shuffle the array using a random device
    static std::random_device rd;
    static std::mt19937 g(rd());
    std::shuffle(aFormArray.begin(), aFormArray.end(), g);
    return aFormArray;
}
RE::BSTArray<RE::TESObjectREFR*> ShuffleArray_Internal(RE::BSTArray<RE::TESObjectREFR*> aFormArray)
{
    // shuffle the array using a random device
    static std::random_device rd;
    static std::mt19937 g(rd());
    std::shuffle(aFormArray.begin(), aFormArray.end(), g);
    return aFormArray;
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
        // Unequip the old item first
        UnEquipInventoryItem_Internal(aNPC, aOldItem->As<RE::BGSInventoryItem>());
        // aOldItem: aNPC -> aContainer
        oldItemObject = aOldItem->As<RE::TESBoundObject>();
        RE::TESObjectREFR::RemoveItemData oldItemRemoveItemData = BuildRemoveItemData_Internal(oldItemObject, aContainer, 1);
        aNPC->RemoveItem(oldItemRemoveItemData);
        if (DEBUGGING) gLog->info("SwapItems_Native: Moved new item from the container to the NPC, FormID: {:08X}", aOldItem->formID);
    }

    if (DEBUGGING) gLog->info("SwapItems_Native: Function finished successfully.");

    return true;
}
bool SwapItems_Internal(RE::TESObjectREFR* aNPC, RE::BGSInventoryItem* aOldItem, RE::BGSInventoryItem* aNewItem, RE::TESObjectREFR* aContainer)
{
    // Check the object reference
    if (!aNPC || !aContainer) {
        return false;
    }
    // Declare the objects
    RE::TESBoundObject* newItemObject = nullptr;
    RE::TESBoundObject* oldItemObject = nullptr;
    // Move the items
    if (aNewItem) {
        // aNewItem: aContainer -> aNPC
        newItemObject = aNewItem->object;
        RE::TESObjectREFR::RemoveItemData newItemRemoveItemData = BuildRemoveItemData_Internal(newItemObject, aNPC, 1);
        aContainer->RemoveItem(newItemRemoveItemData);
    }
    if (aOldItem) {
        // Unequip the old item first
        UnEquipInventoryItem_Internal(aNPC, aOldItem);
        // aOldItem: aNPC -> aContainer
        oldItemObject = aOldItem->object;
        RE::TESObjectREFR::RemoveItemData oldItemRemoveItemData = BuildRemoveItemData_Internal(oldItemObject, aContainer, 1);
        aNPC->RemoveItem(oldItemRemoveItemData);
    }
    return true;
}

// Helper function to equip a single inventory item to an NPC
bool UnEquipInventoryItem_Internal(RE::TESObjectREFR* aNPC, RE::BGSInventoryItem* aInvItem)
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
        if (DEBUGGING) gLog->warn("EquipInventoryItem_Internal: No valid instanceData found for FormID: {:08X}. Attempt to equip to the default slot.", aInvItem->object->GetFormID());
        validStackID = 0;
        instanceData = nullptr;
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
    equipMgr->UnequipObject(
        actor,
        &objInstance,   // pointer
        1,              // count
        equipSlot,      // slot (nullptr for weapons)
        validStackID,   // stackID
        false,          // queueEquip
        true,           // forceEquip
        false,          // playSound
        true,           // applyNow
        nullptr         // slotbeingReplaced
    );
    return true;
}

// Helper function to refresh NPC visual appearance
void UpdateNPCVisual_Internal(RE::TESObjectREFR* aNPC)
{
    if (!aNPC) return;
    RE::Actor* actor = aNPC->As<RE::Actor>();
    if (!actor) return;
    actor->Reset3D(/*reloadAll=*/false, /*additionalFlags=*/0, /*queueReset=*/true, /*excludeFlags=*/0);
}

bool RegisterPapyrusFunctions(RE::BSScript::IVirtualMachine* vm) {
    if (DEBUGGING) gLog->info("RegisterPapyrusFunctions: Attempting to register Papyrus functions. VM pointer: {}", static_cast<const void*>(vm));

    // vm->BindNativeMethod("<Name of the script binding the function>", "<Name of the function in Papyrus>", <Name of the function in F4SE>, <can run parallel to Papyrus>);
    
    vm->BindNativeMethod("ES_API", "AdminEquipSettlers", AdminEquipSettlers_Native, true);
    vm->BindNativeMethod("ES_API", "AdminStripSettlers", AdminStripSettlers_Native, true);
    vm->BindNativeMethod("ES_API", "CombineArrayForm", CombineArrayForm_Native, true);
    vm->BindNativeMethod("ES_API", "CombineArrayObject", CombineArrayObject_Native, true);
    vm->BindNativeMethod("ES_API", "EquipBestItems", EquipBestItems_Native, true);
    vm->BindNativeMethod("ES_API", "EquipBestItemsAll", EquipBestItemsAll_Native, true);
    vm->BindNativeMethod("ES_API", "FindAllObjectsWithAnyKeywords", FindAllObjectsWithAnyKeywords_Native, true);
    vm->BindNativeMethod("ES_API", "FindNearbyWorkshopObjects", FindNearbyWorkshopObjects_Native, true);
    vm->BindNativeMethod("ES_API", "FindSettlerNPC", FindSettlerNPC_Native, true);
    vm->BindNativeMethod("ES_API", "GetArmorItems", GetArmorItems_Native, true);
    vm->BindNativeMethod("ES_API", "GetBestArmor", GetBestArmor_Native, true);
    vm->BindNativeMethod("ES_API", "GetBestWeapon", GetBestWeapon_Native, true);
    vm->BindNativeMethod("ES_API", "GetGoldPrice", GetGoldPrice_Native, true);
    vm->BindNativeMethod("ES_API", "GetMatchingItems", GetMatchingItems_Native, true);
    vm->BindNativeMethod("ES_API", "GetWeaponItems", GetWeaponItems_Native, true);
    vm->BindNativeMethod("ES_API", "IsArmorWeapon", IsArmorWeapon_Native, true);
    vm->BindNativeMethod("ES_API", "IsSettlerNPC", IsSettlerNPC_Native, true);
    vm->BindNativeMethod("ES_API", "ItemMatchesSlot", ItemMatchesSlot_Native, true);
    vm->BindNativeMethod("ES_API", "ProcessNPCArmor", ProcessNPCArmor_Native, true);
    vm->BindNativeMethod("ES_API", "PreProcessNPCArmor", PreProcessNPCArmor_Native, true);
    vm->BindNativeMethod("ES_API", "ProcessNPCWeapon", ProcessNPCWeapon_Native, true);
    vm->BindNativeMethod("ES_API", "PreProcessNPCWeapon", PreProcessNPCWeapon_Native, true);
    vm->BindNativeMethod("ES_API", "SetObjectName", SetObjectName_Native, true);
    vm->BindNativeMethod("ES_API", "SettingDebuggingEnabled", SettingDebuggingEnabled_Native, true);
    vm->BindNativeMethod("ES_API", "SettingAnimationEnabled", SettingAnimationEnabled_Native, true);
    vm->BindNativeMethod("ES_API", "ShuffleArray", ShuffleArray_Native, true);
    vm->BindNativeMethod("ES_API", "StringContains", StringContains_Native, true);
    vm->BindNativeMethod("ES_API", "SwapItems", SwapItems_Native, true);

    if (DEBUGGING) gLog->info("RegisterPapyrusFunctions: All Papyrus functions registration attempts completed.");

    return true;
}
