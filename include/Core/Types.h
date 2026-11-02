#include <cstdint>
#pragma once

class ItemId
{
private:
    std::uint32_t itemId = 0;

public:
    explicit ItemId(std::uint32_t itemId) : itemId(itemId) {};
    std::uint32_t getItemId() const
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
    std::uint32_t instanceId = 0;

public:
    explicit InstanceId(std::uint32_t instanceId) : instanceId(instanceId) {};
    std::uint32_t getInstanceId() const
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
    std::uint32_t characterId = 0;

public:
    explicit CharacterId(std::uint32_t characterId) : characterId(characterId) {};
    std::uint32_t getCharacterId() const
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
    std::uint32_t monsterId = 0;

public:
    explicit MonsterId(std::uint32_t monsterId) : monsterId(monsterId) {};
    std::uint32_t getMonsterId() const
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
