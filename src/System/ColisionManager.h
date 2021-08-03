#pragma once
#include "Interfaces/IColisionable.h"
#include "raylib.h"
#include <memory>

using namespace std;

namespace GunFight {
    
    struct ColisionRegister {
        vector<IColisionable*> colisioner;
        vector<IColisionable*> otherColisioner;
    };
    
    class ColisionManager
    {
        ColisionRegister colRegister;
        vector<IColisionable*> colisionables;

    public:
        ColisionManager();
        void AddToCollisionManager(IColisionable* colisionable);
        void RemoveFromCollisionManager(IColisionable* colisionable);
        void CheckCollisions();
    };
}