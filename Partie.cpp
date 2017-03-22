//
//  Partie.cpp
//  bn
//
//  Created by fabrice locqueville on 08/03/2017.
//  Copyright © 2017 fabrice locqueville. All rights reserved.
//

#include "Partie.hpp"
#include "Console.hpp"
#include <vector>
<<<<<<< HEAD
#include <cstdlib>
=======
#include <fstream>
>>>>>>> sauvegarde

Partie::Partie()
{
}

Partie::~Partie()
{
}

bool Partie::boucleDeJeu(bool begin)
{
    Console *p= Console::getInstance();
    int sauv = false;
    std::vector<Player*> ps;
    ps.push_back(&m_ordi);
    ps.push_back(&m_user);

    int i(0);
    while(!victoire())
    {
        ps[i]->printGrill(*ps[1-i]);
        ps[i]->play(*ps[1-i]);
        i++;
        i%=2;
    }
    return false;
}
bool Partie::victoire(Player &p)
{
    for(int i(0); i<p.getVectBoat().size(); i++)
        if(!p.getVectBoat()[i]->getCoule())
            return false;
    return true;
}


void Partie::sauvegarde()
{
    std::ofstream myfile;
    myfile.open("binary",std::ios::binary | std::ios::out);
    ///in binary mode without string
    //myfile.write((char*)&partie,sizeof(Partie));
    myfile << *this; /// with the overload

    myfile.close();
}


void Partie::getInfoSauv()
{
    Partie partie;
    std::ifstream myfile;
    myfile.open("binary",std::ios::binary | std::ios::in);

    ///in binary mode without string
//    myfile.read((char*)&game,sizeof(Game));

    myfile >> *this; /// with the overload
    myfile.close();
}
