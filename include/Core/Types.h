#pragma once
#include <cstdint>
#include <iostream>

class ItemId
{
private:
    int itemId = 0;

public:
    explicit ItemId(int itemId) : itemId(itemId) {
        if (itemId <1) {throw std::invalid_argument("Niepoprawne itemId!\n");}
    };
    int getItemId() const
    {
        return itemId;
    }
    bool operator==(const ItemId &other) const
    {
        return itemId == other.itemId;
    }
    bool operator!=(const ItemId &other) const
    {
        return itemId != other.itemId;
    }
};

class InstanceId
{
private:
    int instanceId = 0;

public:
    explicit InstanceId(int instanceId) : instanceId(instanceId) {
        if (instanceId <1) {throw std::invalid_argument("Niepoprawne itemId!\n");}
    };
    int getInstanceId() const
    {
        return instanceId;
    }
    bool operator==(const InstanceId &other) const
    {
        return instanceId == other.instanceId;
    }
    bool operator!=(const InstanceId &other) const
    {
        return instanceId != other.instanceId;
    }
};
class CharacterId
{
private:
    int characterId = 0;

public:
    explicit CharacterId(int characterId) : characterId(characterId) {
        if (characterId <1) {throw std::invalid_argument("Niepoprawne itemId!\n");}
    };
    int getCharacterId() const
    {
        return characterId;
    }
    bool operator==(const CharacterId &other) const
    {
        return characterId == other.characterId;
    }
    bool operator!=(const CharacterId &other) const
    {
        return characterId != other.characterId;
    }
};
class MonsterId
{
private:
    int monsterId = 0;

public:
    explicit MonsterId(int monsterId) : monsterId(monsterId) {
        if (monsterId <1) {throw std::invalid_argument("Niepoprawne itemId!\n");}
    };
    int getMonsterId() const
    {
        return monsterId;
    }
    bool operator==(const MonsterId &other) const
    {
        return monsterId == other.monsterId;
    }
    bool operator!=(const MonsterId &other) const
    {
        return monsterId != other.monsterId;
    }
};
enum class CharacterClass
{
    Warrior,
    Mage,
    Archer,
};
