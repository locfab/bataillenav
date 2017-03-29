//
//  Partie.cpp
//  bn
//
//  Created by PeTheFa on 08/03/2017.
//  Copyright © 2017 PeTheFa. All rights reserved.
//

#include "Partie.hpp"
#include "Console.hpp"
#include <vector>
#include <cstdlib>
#include <fstream>

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
    if(ps[0]->getid() == 2)
    {
        i = 1;
    }

    else
    {
        i = 0;
    }


    while(!victoire(*ps[1-i]))
    {
        ps[i]->printGrill(*ps[1-i]);
      //  ps[i]->setid(i+1);
        ps[i]->play(*ps[1-i]);
        i++;
        i%=2;
        ps[i]->setid(i+1);
       // if(i==0)
       // {

       // }

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

void Partie::aleaGrill1()
{
    m_user.aleaGrille1();
    m_ordi.aleaGrille1();
}

void Partie::aide()
{
    system("CLS");
    std::cout << std::endl<<std::endl <<  "Dans ce jeu, vous prendrez part a une bataille navale sans pitie !" << std::endl<<std::endl;
    std::cout << "Cette bataille navale se joue a 2. Chaque joueur joue tour a tour." << std::endl;
    std::cout << "A gauche, vous avez votre grille de bateaux, et a droite, une grille pour visualiser les degats infliges a votre adversaire." << std::endl;
    std::cout << "Chaque joueur possede une flotte de 10 navires, composee de :" << std::endl << std::endl;
    std::cout << "- 1 cuirasse, d'une taille de 7 cases, et tirant des obus faisant des degats sur 9 cases." << std::endl;
    std::cout << "- 2 croiseurs, d'une taille de 5 cases, et tirant des obus faisant des degats sur 4 cases." << std::endl;
    std::cout << "- 3 destroyers, d'une taille de 3 cases, et tirant des obus faisant des degats sur 1 case." << std::endl;
    std::cout << "- 4 sous-marins, d'une taille de 1 case, et tirant des obus faisant des degats sur 1 case." << std::endl<<std::endl<<std::endl;
    std::cout << "Un destroyer a la particularite de pouvoir envoyer une fusee eclairante, devoilant une surface de 4*4 sur la grille adverse." << std::endl;
    std::cout << "Les sous-marins ne peuvent detruire que les sous-marins." << std::endl;
    std::cout << "A chaque tour, le joueur doit choisir de faire une action :" << std::endl<<std::endl;
    std::cout << "- Deplacer un bateau d'une case. Il ne peut se deplacer que horizontalement (si il est a l'horizontale), ou verticalement (dans le cas contraire)." << std::endl;
    std::cout << "- Tourner un navire a 90 degres." << std::endl;
    std::cout << "- Lancer une attaque avec un bateau selectionne, ou bien une fusee eclairante." << std::endl<<std::endl<<std::endl;
    std::cout << "La rotation et la translation ne se font que si elles sont possibles. Sinon, vous devez a nouveau faire une action." << std::endl;
    std::cout << "Pour se deplacer dans les menus, vous devez utiliser les touches Z-Q-S-D." << std::endl;
    std::cout << "Pour changer de bateau selectionne, vous devez utiliser la touche ESPACE." << std::endl;
    std::cout << "Pour cibler votre attaque, vous devez utiliser les touches Z-Q-S-D." << std::endl;
    std::cout << "Pour confirmer un choix, n'importe lequel, la touche ENTREE est utilisee." << std::endl<<std::endl<<std::endl;
    std::cout << "L'equipe vous souhaite une bonne bataille !" << std::endl<<std::endl<<std::endl;
    std::cout << " " << std::endl;
    std::cout << "Appuyez sur n'importe quelle touche pour revenir au menu." << std::endl;
}
