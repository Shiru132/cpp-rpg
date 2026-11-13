#pragma once
#include <stdexcept>
#include <climits>
// pierwszy raz jest tutaj : Singleton to kreacyjny wzorzec projektowy gwarantujący istnienie tylko jednego obiektu danego rodzaju.
// Udostępnia też pojedynczy punkt dostępowy do takiego obiektu z dowolnego miejsca w programie.
class IdGenerator
{
private:
    IdGenerator() {}
    static int instanceGeneratedId;
    static int characterGeneratedId;

public:
    // zabezpieczenie przed kopiowaniem generatora i przenoszeniem
    IdGenerator(const IdGenerator &) = delete;
    IdGenerator &operator=(const IdGenerator &) = delete;
    IdGenerator(const IdGenerator &&) = delete;
    IdGenerator &operator=(const IdGenerator &&) = delete;
    static IdGenerator &getInstance()
    {
        static IdGenerator idGenerator;
        return idGenerator;
    }
    int generateInstanceId()
    {
        if (instanceGeneratedId < 1)
        {
            throw std::out_of_range("out of range\n");
        }
        else if (instanceGeneratedId >= INT_MAX)
        {
            throw std::overflow_error("overflow_error\n");
        }
        else
        {
            return instanceGeneratedId++;
        }
    }
    int generateCharacterId()
    {
        if (characterGeneratedId < 1 || characterGeneratedId >= INT_MAX)
        {
            throw std::out_of_range("out of range\n");
        }
        else if (characterGeneratedId >= INT_MAX)
        {
            throw std::overflow_error("overflow_error\n");
        }
        else
        {
            return characterGeneratedId++;
        }
    }
};