//
//  Player.hpp
//  bn
//
//  Created by fabrice locqueville on 08/03/2017.
//  Copyright © 2017 fabrice locqueville. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <iostream>
#include <iomanip>
#include <vector>
#include "Boat.hpp"
#include "Cuirace.hpp"
#include "SousMarin.hpp"
#include "Destroyer.hpp"
#include "Croiseur.hpp"
#include "Console.hpp"

class Player
{
public:
    Player();
    void printGrill(Player &adversaire);
    void printBoatGrille1(std::vector<Boat*> bs,Boat * b);
    std::vector<std::vector<char> > getGrille1();
    std::vector<std::vector<char> > getGrille2();
    std::vector<Boat*> getVectBoat();
    void aleaGrille1();
    void setGrille1();
    void setGrille2(Player adversaire);
    void setid(int id);
    //bool toucher(std::pair<int, int> coord, bool vectical, int envergure);
    bool toucher(std::pair<int, int> coord, bool vectical, int envergure, int withoutIndice = -1);
    void play(Player adversaire);
    void playIA();
    bool moveBoat(int y);
    bool turnBoat(int y);
    Console* pConsole = NULL;
    void printColorBoat(Boat * b);
    void printDefaultColorBoat(std::vector<Boat*> bs);
    void printZoneGrille2(std::pair<int, int> coord, Boat*b, int sizeAttacks);
    int choixBoat();
    std::pair<int, int> moveZoneRight(std::pair<int, int> coord, int choix, int sizeAttacks);




   friend std::ostream& operator<<(std::ostream& os, const Player& p)
   {
       os << p.m_vectBoat;
       return os;
   }

    friend std::istream& operator>>(std::istream& is, Player& p)
    {
        int a;
        is >> a;
        p.m_vectBoat.resize(a);

        for(int i(0); i<10; i++)
        {
            char type;
            is >> type;
            if(type == '*')
            {
                p.m_vectBoat[i] = new Cuirace;
                is >> *p.m_vectBoat[i];
            }
            else if(type  == 's')
            {
                p.m_vectBoat[i] = new SousMarin;
                is >> *p.m_vectBoat[i];
            }
            else if(type  == '+')
            {
                p.m_vectBoat[i] = new Destroyer;
                is >> *p.m_vectBoat[i];
            }
            else if(type  == 'o')
            {
                p.m_vectBoat[i] = new Croiseur;
                is >> *p.m_vectBoat[i];
            }
            p.m_vectBoat[i]->setType(type);

        }
        return is;
    }

protected:
    std::vector<Boat*> m_vectBoat;
    std::vector<std::vector<char> > m_grille1;
    std::vector<std::vector<char> > m_grille2;
    int m_id;
};
#endif /* Player_hpp */
