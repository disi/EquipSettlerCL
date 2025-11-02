#include <PCH.h>
#include <Global.h>

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
            if (IsArmorWeapon_Internal(&currentItem)) {
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
    if (!IsArmorWeapon_Internal(aInvItem)) return false;
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
        if (DEBUGGING) gLog->info("EquipInventoryItem_Internal: No valid instanceData found for FormID: {:08X}. UUsing default.", aInvItem->object->GetFormID());
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

// ObjectReference[] Function FilterSettlers(ObjectReference[] aFormArray, Int aChestTypePass, Bool aShuffle) global native
RE::BSTArray<RE::TESObjectREFR*> FilterSettlers_Native(std::monostate, RE::BSTArray<RE::TESObjectREFR*> aFormArray, std::int32_t aChestTypePass, bool aShuffle)
{
    if (DEBUGGING) gLog->info("FilterSettlers_Native: Function called");

    RE::BSTArray<RE::TESObjectREFR*> filteredArray;

    if (aFormArray.empty() || aFormArray.size() == 0) {
        if (DEBUGGING) gLog->warn("FilterSettlers_Native: Input array is empty or null. Exiting function.");
        return filteredArray;
    }

    if (aChestTypePass < 0 || aChestTypePass > 3) {
        if (DEBUGGING) gLog->warn("FilterSettlers_Native: Invalid chest type pass value: {}. Must be between 0 and 3. Exiting function.", aChestTypePass);
        return filteredArray;
    }

    if (DEBUGGING) gLog->info("FilterSettlers_Native: Found {} settlers before filtering.", aFormArray.size());

    // Check each form in the input array and filter for settlers
    for (const auto& form : aFormArray) {
        if (!form) continue;
        if (IsSettlerNPC_Internal(form)) {
            filteredArray.push_back(form);
        }
    }
    if (filteredArray.empty() || filteredArray.size() == 0) {
        if (DEBUGGING) gLog->warn("FilterSettlers_Native: No settlers found after IsSettlerNPC_Internal check. Exiting function.");
        return filteredArray;
    }

    // Remove any null entries to prevent crashes
    filteredArray.erase(std::remove(filteredArray.begin(), filteredArray.end(), nullptr), filteredArray.end());

    // Remove duplicates to prevent crashes
    std::unordered_set<RE::TESObjectREFR*> uniqueSet;
    auto it = filteredArray.begin();
    while (it != filteredArray.end()) {
        if (!uniqueSet.insert(*it).second) {
            it = filteredArray.erase(it); // Duplicate found, erase
        } else {
            ++it;
        }
    }

    // Further filter by chest type if specified
    if (aChestTypePass != 0) {
        RE::BSTArray<RE::TESObjectREFR*> guards;
        RE::BSTArray<RE::TESObjectREFR*> workers;
        for (auto* aNPC : filteredArray) {
            if (!aNPC) continue;
            // Get the bIsGuard property from the WorkshopNPCScript
            bool bIsGuard = GetPapyrusProperty_Internal<bool>(aNPC, "WorkshopNPCScript", "bIsGuard").value_or(false);
            if (DEBUGGING) gLog->info("FilterSettlers_Native: NPC FormID: {:08X} bIsGuard: {}", aNPC->GetFormID(), bIsGuard);
            // Only Guards
            if (bIsGuard) {
                guards.push_back(aNPC);
            // Only Non-Guards
            } else {
                workers.push_back(aNPC);
            }
        }
        if (aChestTypePass == 1) {
            filteredArray = guards;
        } else {
            filteredArray = workers;
        }
    }

    // Shuffle the array before returning it
    if (aShuffle) {
        std::shuffle(filteredArray.begin(), filteredArray.end(), std::mt19937{ std::random_device{}() });
    }

    if (DEBUGGING) gLog->info("FilterSettlers_Native: Filtered array has {} settlers with Chest Type: {}", filteredArray.size(), aChestTypePass);

    return filteredArray;
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

// ObjectReference[] Function FindSettlerTrunk(Float aRadius) Global native
RE::BSTArray<RE::TESObjectREFR*> FindSettlerTrunk_Native(std::monostate, float aRadius)
{
    if (DEBUGGING) gLog->info("FindSettlerTrunk_Native: Function called.");

    RE::BSTArray<RE::TESObjectREFR*> foundObjects;

    // Get the player reference
    RE::PlayerCharacter* player = RE::PlayerCharacter::GetSingleton();
    if (!player) {
        if (DEBUGGING) gLog->warn("FindSettlerTrunk_Native: Player reference is null.");
        return foundObjects;
    }

    // Get the player cell
    auto* cell = player->parentCell;
    if (!cell)
        return foundObjects;

    // Get all forms in the cell
    const auto& formsPair = cell->GetAllForms();

    // Get the map of forms
    const auto* formsMap = formsPair.first;
    if (!formsMap)
        return foundObjects;

    // Get the player position
    auto playerPos = player->GetPosition();
    // Iterate over all forms and check for references with matching keywords
    std::vector<std::pair<RE::TESObjectREFR*, float>> tempObjects;
    for (auto& entry : *formsMap) {
        RE::TESForm* form = entry.second;
        // early continue if form is null
        if (!form) continue;
        // Check if the form is a reference
        RE::TESObjectREFR* ref = form->As<RE::TESObjectREFR>();
        if (!ref || ref->IsDeleted() || ref->IsDisabled()) {
            continue;
        }
        // Check distance
        float distance = playerPos.GetDistance(ref->GetPosition());
        if (distance > aRadius) continue;
        // Check keywords
        if (!HasAnyKeyword_Internal(ref, trunkKeyword)) {
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

    if (DEBUGGING) gLog->info("FindSettlerTrunk_Native: Found {} matching trunk references.", foundObjects.size());

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
        if (!IsArmorWeapon_Internal(currentItem)) {
            continue;
        }
        if (form->GetFormType() == RE::ENUM_FORM_ID::kARMO) {
            armorArray.push_back(currentItem);
        }
    }
    return armorArray;
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
        if (IsArmorWeapon_Internal(currentItem)) {
            std::int32_t currentValue = GetGoldPrice_Internal(form);
            if (currentValue > bestValue) {
                bestItem = currentItem;
                bestValue = currentValue;
            }
        }
    }
    return bestItem;
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
        if (!IsArmorWeapon_Internal(&item)) {
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
bool HasAnyKeyword_Internal(RE::TESObjectREFR* aRef, const std::string& keyword)
{
    if (!aRef) return false;
    RE::TESBoundObject* baseForm = aRef->GetObjectReference();
    auto* keywordForm = baseForm ? baseForm->As<RE::BGSKeywordForm>() : nullptr;
    if (!keywordForm) return false;
    std::string keywordLower = keyword;
    std::transform(keywordLower.begin(), keywordLower.end(), keywordLower.begin(), ::tolower);
    for (uint32_t i = 0; i < keywordForm->numKeywords; ++i) {
        auto* kw = keywordForm->keywords[i];
        if (!kw) continue;
        const char* editorID = kw->GetFormEditorID();
        if (!editorID) continue;
        std::string editorIDLower(editorID);
        std::transform(editorIDLower.begin(), editorIDLower.end(), editorIDLower.begin(), ::tolower);
        if (editorIDLower == keywordLower) {
            return true;
        }
    }
    return false;
}
bool HasAnyKeyword_Internal(RE::TESForm* form, std::unordered_set<std::uint32_t> keywords)
{
    if (!form) return false;
    auto* keywordForm = form->As<RE::BGSKeywordForm>();
    if (!keywordForm) return false;
    for (uint32_t i = 0; i < keywordForm->numKeywords; ++i) {
        auto* kw = keywordForm->keywords[i];
        if (!kw) continue;
        std::uint32_t kwFormID = kw->GetFormID();
        if (!kwFormID) continue;
        if (keywords.find(kwFormID) != keywords.end()) {
            return true;
        }
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
    if (aItem->stackData->GetCount() <= 0)
        return false;
    // Forward to the TESForm* version
    return IsArmorWeapon_Internal(aItem->object);
}

// Helper function to check if a FormID is in the excluded list
bool IsFormIDExcluded_Internal(uint32_t formID) {
    if (!formID) return false;
    if (excludedFormIDs.find(formID) != excludedFormIDs.end()) {
        return true;
    }
    return false;
}

bool IsSettlerNPC_Internal(RE::TESObjectREFR* aNPC)
{
    // Check the object reference
    if (!aNPC) {
        return false;
    }
    auto actor = aNPC->As<RE::Actor>();
    if (!actor) {
        if (DEBUGGING) gLog->warn("IsSettlerNPC_Internal: The object is not an Actor. Failsafe ignoring.");
        return false;
    }
    auto npc = actor->GetNPC();
    if (!npc) {
        if (DEBUGGING) gLog->warn("IsSettlerNPC_Internal: Could not get ActorBase for the NPC. Failsafe ignoring.");
        return false;
    }
    // Pre-checks on the NPC
    if (actor->IsDeleted()) {
        if (DEBUGGING) gLog->warn("IsSettlerNPC_Internal: The NPC is deleted. Failsafe ignoring.");
        return false;
    }
    if (actor->IsDisabled()) {
        if (DEBUGGING) gLog->warn("IsSettlerNPC_Internal: The NPC is disabled. Failsafe ignoring.");
        return false;
    }
    if (actor->IsDead(false)) {
        if (DEBUGGING) gLog->warn("IsSettlerNPC_Internal: The NPC is dead. Failsafe ignoring.");
        return false;
    }
    if (actor->IsChild()) {
        if (DEBUGGING) gLog->warn("IsSettlerNPC_Internal: The NPC is a child. Failsafe ignoring.");
        return false;
    }
    if (actor->IsPlayer()) {
        if (DEBUGGING) gLog->warn("IsSettlerNPC_Internal: The NPC is the player. Failsafe ignoring.");
        return false;
    }
    if (actor->IsInCombat()) {
        if (DEBUGGING) gLog->warn("IsSettlerNPC_Internal: The NPC is in combat. Failsafe ignoring.");
        return false;
    }
    RE::Actor* player = RE::PlayerCharacter::GetSingleton();
    if (!player) {
        if (DEBUGGING) gLog->warn("IsSettlerNPC_Internal: Could not get player Actor. Failsafe ignoring.");
        return false;
    } else if (actor->GetHostileToActor(player)) {
        if (DEBUGGING) gLog->warn("IsSettlerNPC_Internal: The NPC is hostile to the player. Failsafe ignoring.");
        return false;
    }
    // Get the needed FormIDs and EditorIDs
    std::uint32_t npcBaseFormID = npc->GetFormID();
    std::uint32_t npcRefFormID = actor->GetFormID();
    std::string npcEditorID;
    if (npc->GetFormEditorID() && std::strlen(npc->GetFormEditorID()) > 0) {
        npcEditorID = npc->GetFormEditorID();
    } else if (actor->GetFormEditorID() && std::strlen(actor->GetFormEditorID()) > 0) {
        npcEditorID = actor->GetFormEditorID();
    } else if (aNPC->GetFormEditorID() && std::strlen(aNPC->GetFormEditorID()) > 0) {
        npcEditorID = aNPC->GetFormEditorID();
    } else {
        npcEditorID = "Unknown";
    }
    // Check if NPC's base FormID is in excludeNPC
    if (excludeNPC.empty() || excludeNPC.size() == 0) {
        if (DEBUGGING) gLog->info("IsSettlerNPC_Internal: No excludeNPC filter set, skipping.");
    } else {
        if (npcBaseFormID != 0 && npcRefFormID != 0) {
            if (excludeNPC.find(npcBaseFormID) != excludeNPC.end() || excludeNPC.find(npcRefFormID) != excludeNPC.end()) {
                if (DEBUGGING) gLog->warn("IsSettlerNPC_Internal: The NPC {} Ref FormID {:08X} Base FormID {:08X} is in the exclude list. Ignoring.", npcEditorID, npcRefFormID, npcBaseFormID);
                return false;
            } else {
                if (DEBUGGING) gLog->info("IsSettlerNPC_Internal: The NPC {} Ref FormID {:08X} Base FormID {:08X} is not in the exclude list.", npcEditorID, npcRefFormID, npcBaseFormID);
            }
        } else {
            if (DEBUGGING) gLog->warn("IsSettlerNPC_Internal: Could not get Actor FormIDs. Failsafe ignoring.");
            return false;
        }
    }
    // Faction checks
    if (excludeFaction.empty() || excludeFaction.size() == 0) {
        if (DEBUGGING) gLog->info("IsSettlerNPC_Internal: No excludeFaction filter set, skipping.");
    } else {
        // Get the Actor's factions
        std::vector<std::uint32_t> factionFormIDs;
        for (auto& factionData : npc->factions) {
            RE::TESFaction* faction = factionData.faction;
            std::uint32_t factionFormID = faction->GetFormID();
            if (!factionFormID) continue;
            factionFormIDs.emplace_back(factionFormID);
        }
        if (factionFormIDs.empty() || factionFormIDs.size() == 0) {
            if (DEBUGGING) gLog->warn("IsSettlerNPC_Internal: The NPC has no factions. Failsafe ignoring.");
            return false;
        }
        // Check if any of the NPC's factions are in the exclude list
        for (const std::uint32_t& factionFormID : factionFormIDs) {
            if (excludeFaction.find(factionFormID) != excludeFaction.end()) {
                if (DEBUGGING) gLog->warn("IsSettlerNPC_Internal: The NPC {} Base FormID: {:08X} is in the faction {:08X} exclude list. Ignoring.", npcEditorID, npcBaseFormID, factionFormID);
                return false;
            }
        }
    }
    // All tests passed
    return true;
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
            if (DEBUGGING) gLog->info("PreProcessNPCArmor_Native: Swap needed.");
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
        if (DEBUGGING) gLog->info("PreProcessNPCWeapon_Native: Swap needed.");
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

RE::BSTArray<RE::TESObjectREFR*> ShuffleArray_Internal(RE::BSTArray<RE::TESObjectREFR*> aFormArray)
{
    // shuffle the array using a random device
    static std::random_device rd;
    static std::mt19937 g(rd());
    std::shuffle(aFormArray.begin(), aFormArray.end(), g);
    return aFormArray;
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
    if (IsArmorWeapon_Internal(aOldItem)) {
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
    if (!IsArmorWeapon_Internal(aInvItem)) return false;
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
        if (DEBUGGING) gLog->warn("EquipInventoryItem_Internal: No valid instanceData found for FormID: {:08X}. Using default.", aInvItem->object->GetFormID());
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
    vm->BindNativeMethod("ES_API", "EquipBestItems", EquipBestItems_Native, true);
    vm->BindNativeMethod("ES_API", "EquipBestItemsAll", EquipBestItemsAll_Native, true);
    vm->BindNativeMethod("ES_API", "FilterSettlers", FilterSettlers_Native, true);
    vm->BindNativeMethod("ES_API", "FindNearbyWorkshopObjects", FindNearbyWorkshopObjects_Native, true);
    vm->BindNativeMethod("ES_API", "FindSettlerTrunk", FindSettlerTrunk_Native, true);
    vm->BindNativeMethod("ES_API", "GetArmorItems", GetArmorItems_Native, true);
    vm->BindNativeMethod("ES_API", "GetWeaponItems", GetWeaponItems_Native, true);
    vm->BindNativeMethod("ES_API", "ProcessNPCArmor", ProcessNPCArmor_Native, true);
    vm->BindNativeMethod("ES_API", "PreProcessNPCArmor", PreProcessNPCArmor_Native, true);
    vm->BindNativeMethod("ES_API", "ProcessNPCWeapon", ProcessNPCWeapon_Native, true);
    vm->BindNativeMethod("ES_API", "PreProcessNPCWeapon", PreProcessNPCWeapon_Native, true);
    vm->BindNativeMethod("ES_API", "SetObjectName", SetObjectName_Native, true);
    vm->BindNativeMethod("ES_API", "SettingDebuggingEnabled", SettingDebuggingEnabled_Native, true);
    vm->BindNativeMethod("ES_API", "SettingAnimationEnabled", SettingAnimationEnabled_Native, true);

    if (DEBUGGING) gLog->info("RegisterPapyrusFunctions: All Papyrus functions registration attempts completed.");

    return true;
}