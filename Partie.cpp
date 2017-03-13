//
//  Partie.cpp
//  bn
//
//  Created by fabrice locqueville on 08/03/2017.
//  Copyright © 2017 fabrice locqueville. All rights reserved.
//

#include "Partie.hpp"
#include <vector>

Partie::Partie()
{
    boucleDeJeu(true);
}

Partie::~Partie()
{
}

bool Partie::boucleDeJeu(bool begin)
{
    while(!victoire())
    {
        //this->m_ordi.playIA();
        this->m_user.play();
    }
    return false;
}
bool Partie::victoire()
{
    return false;
}


void Partie::sauvegarde(Player &ordi, Player &user)
{
    std::ofstream monFlux("sauvegarde.txt");
    
    
    if(monFlux)
    {
        for(unsigned i(0); i<15; i++)
        {
            for(unsigned j(0); j<15; j++)
            {
                monFlux << ordi.getGrille1()[i][j] << " ";
            }
            monFlux << std::endl;
        }
       /* for(unsigned i(0); i<15; i++)
        {
            for(unsigned j(0); j<15; j++)
            {
                monFlux << ordi.getGrille2()[i][j] << " ";
            }
            monFlux << std::endl;
        }
        for(unsigned i(0); i<15; i++)
        {
            for(unsigned j(0); j<15; j++)
            {
                monFlux << user.getGrille1()[i][j] << " ";
            }
            monFlux << std::endl;
        }
        for(unsigned i(0); i<15; i++)
        {
            for(unsigned j(0); j<15; j++)
            {
                monFlux << user.getGrille2()[i][j] << " ";
            }
            monFlux << std::endl;
        }*/
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
}
void Partie::getInfoSauv(Player $ordi, Player $user)
{
    
}
