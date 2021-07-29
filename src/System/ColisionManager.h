#pragma once
#include "Interfaces/IColisionable.h"
#include "raylib.h"
#include <memory>
#include <list>

using namespace std;

namespace GunFight {
    
    struct ColisionRegister {
        shared_ptr<IColisionable> colisioner;
        shared_ptr<IColisionable> otherColisioner;
    };
    
    class ColisionManager
    {
        list<ColisionRegister> colRegister;
        list<shared_ptr<IColisionable>> colisionables;

    public:
        ColisionManager();
        void AddToCollisionManager(shared_ptr<IColisionable>& colisionable);
        void RemoveFromCollisionManager(shared_ptr<IColisionable>& colisionable);
        void CheckCollisions();
    };
}