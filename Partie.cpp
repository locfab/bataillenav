//
//  Partie.cpp
//  bn
//
//  Created by fabrice locqueville on 08/03/2017.
//  Copyright © 2017 fabrice locqueville. All rights reserved.
//

#include "Partie.hpp"
#include <vector>
#include <fstream>

Partie::Partie()
{
    this->sauvegarde();
    return;
}

Partie::~Partie()
{
}

bool Partie::boucleDeJeu(bool begin)
{
    while(!victoire())
    {
        m_ordi.printGrill(m_user);
        this->m_ordi.play(m_user);
        m_user.printGrill(m_ordi);
        this->m_user.play(m_ordi);
    }
    return false;
}
bool Partie::victoire()
{
    return false;
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

    myfile >> partie; /// with the overload
    myfile.close();

    return partie;
}
