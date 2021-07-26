#pragma once
#include "Interfaces/IColisionable.h"
#include "raylib.h"
#include <list>

using namespace std;

namespace GunFight {
    class ColisionManager
    {
        list<IColisionable>* colisionables;
        ColisionManager()
        {
            colisionables = new list<IColisionable>();
        }
        void AddToCollisionManager(IColisionable colisionable)
        {
            colisionables->push_back(colisionable);
        }
        void RemoveFromCollisionManager(IColisionable colisionable)
        {
            list<IColisionable>::iterator it;

            it = find(colisionables->begin(), colisionables->end(), colisionable);

            if (it != colisionables->end())
            {
                colisionables->remove(colisionable);
            }
        }
        void CheckCollisions()
        {
            list<IColisionable>::iterator firstIterator;
            list<IColisionable>::iterator secondIterator;

            for (firstIterator = colisionables->begin(); firstIterator != colisionables->end(); firstIterator++)
            {
                for (secondIterator = colisionables->begin(); secondIterator != colisionables->end(); secondIterator++)
                {
                    if (firstIterator != secondIterator)
                    {
                        if (CheckCollisionRecs(firstIterator->GetBody(), secondIterator->GetBody()))
                        {

                        }
                    }
                }
            }
        }
    };
}