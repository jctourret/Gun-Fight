#include "ColisionManager.h"


namespace GunFight {

	ColisionManager::ColisionManager()
	{

	}

	void ColisionManager::AddToCollisionManager(IColisionable* colisionable){
		colisionables.push_back(colisionable);
	}

	void ColisionManager::RemoveFromCollisionManager(IColisionable* colisionable)
	{
        for (vector<IColisionable*>::iterator it = colisionables.end(); it != colisionables.begin(); it--)
        {
            if ((*it) == colisionable)
            {
                colisionables.erase(it);
            }
        }
	}
    
	void ColisionManager::CheckCollisions()
    {   
        bool isOnRegister = false;

        for (int i = 0; i < (int)colisionables.size() ; i++) //
        {
            for (int j = 0; j < (int)colisionables.size(); j++) // Recorro con ambos iteradores para que todos checkeen con todos.
            {
                if (i != j) // No quiero que los objetos checkeen con si mismos.
                {
                    ColisionRegister auxRegister;
                    auxRegister.colisioner.push_back(colisionables[i]);
                    auxRegister.otherColisioner.push_back(colisionables[j]);
                    if (CheckCollisionRecs(colisionables[i]->GetBody(), colisionables[j]->GetBody()))
                    {
                        for (int k  = 0; k < (int)colRegister.colisioner.size(); k++)
                        {
                            if (colRegister.colisioner[k] == colisionables[i] &&
                                colRegister.otherColisioner[k] == colisionables[j])
                            {
                                isOnRegister = true;
                            }
                        }
                        if (!isOnRegister)
                        {
                            colRegister.colisioner.push_back(auxRegister.colisioner[0]);
                            colRegister.otherColisioner.push_back(auxRegister.otherColisioner[0]);
                            colisionables[i]->OnCollisionEnter(colisionables[j]);
                        }
                        else
                        {
                            colisionables[i]->OnCollisionStay(colisionables[j]);
                        }
                        isOnRegister = false;
                    }
                    else
                    {
                       for (int k = 0; k < (int)colRegister.colisioner.size(); k++)
                       {
                          isOnRegister = false;
                          if (colRegister.colisioner[k] == colisionables[i] &&
                              colRegister.otherColisioner[k] == colisionables[j])
                          {
                              isOnRegister = true;
                          }
                          if (isOnRegister)
                          {
                             vector<IColisionable*>::iterator it = std::find(colRegister.colisioner.begin(), colRegister.colisioner.end(), colisionables[i]);
                             if (it != colRegister.colisioner.end())
                             {
                                 colRegister.colisioner.erase(it);
                             }
                             it = std::find(colRegister.otherColisioner.begin(), colRegister.otherColisioner.end(), colisionables[j]);
                             if (it != colRegister.otherColisioner.end())
                             {
                                 colRegister.otherColisioner.erase(it);
                             }
                             colisionables[i]->OnCollisionExit(colisionables[j]);
                          }
                       }
                    }
                }
            }
        }
    }
}