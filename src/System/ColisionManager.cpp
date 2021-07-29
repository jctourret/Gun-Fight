#include "ColisionManager.h"


namespace GunFight {

	ColisionManager::ColisionManager()
	{

	}

	void ColisionManager::AddToCollisionManager(shared_ptr<IColisionable>& colisionable){
		colisionables.push_back(colisionable);
	}

	void ColisionManager::RemoveFromCollisionManager(shared_ptr<IColisionable>& colisionable)
	{
		colisionables.remove(colisionable);
	}

	void ColisionManager::CheckCollisions()
    {
        list<shared_ptr<IColisionable>>::iterator firstIterator;
        list<shared_ptr<IColisionable>>::iterator secondIterator;

        list<ColisionRegister>::iterator registerIterator;
        bool isOnRegister = false;

        for (firstIterator = colisionables.begin(); firstIterator != colisionables.end(); firstIterator++)
        {
            for (secondIterator = colisionables.begin(); secondIterator != colisionables.end(); secondIterator++) // Recorro con ambos iteradores para que todos checkeen con todos.
            {
                if (firstIterator != secondIterator) // No quiero que los objetos checkeen con si mismos.
                {
                    ColisionRegister auxRegister;
                    auxRegister.colisioner = (*firstIterator);
                    auxRegister.colisioner = (*secondIterator);
                    if (CheckCollisionRecs((*firstIterator)->GetBody(), (*secondIterator)->GetBody()))
                    {
                        for (registerIterator = colRegister.begin(); registerIterator != colRegister.end(); registerIterator++)
                        {
                            if ((*registerIterator).colisioner == (*firstIterator) &&
                                (*registerIterator).otherColisioner == (*secondIterator))
                            {
                                isOnRegister = true;
                            }
                        }
                        if (!isOnRegister)
                        {
                            colRegister.push_back(auxRegister);
                            (*firstIterator)->OnCollisionEnter((*secondIterator));
                        }
                        else
                        {
                            (*firstIterator)->OnCollisionStay((*secondIterator));
                        }
                        isOnRegister = false;
                    }
                    else
                    {
                        for (registerIterator = colRegister.begin(); registerIterator != colRegister.end(); registerIterator++)
                        {
                            if ((*registerIterator).colisioner != (*firstIterator) &&
                                (*registerIterator).otherColisioner != (*secondIterator))
                            {
                                isOnRegister = true;
                            }
                            if (isOnRegister)
                            {
                                (*firstIterator)->OnCollisionExit((*secondIterator));
                            }
                        }
                    }
                }
            }
        }
    }
}