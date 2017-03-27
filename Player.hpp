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
           os << p.m_vectBoat << '\n';
           return os;
       }

        friend std::istream& operator>>(std::istream& is, Player& p)
        {
            is >> p.m_vectBoat;

            if(p.m_vectBoat[0]->getType()== '*')
                p.m_vectBoat[0] = (Cuirace*)p.m_vectBoat[0];
            else if(p.m_vectBoat[0]->getType()== '+')
                p.m_vectBoat[0] = (Destroyer*)p.m_vectBoat[0];
            else if(p.m_vectBoat[0]->getType()== 's')
                p.m_vectBoat[0] = (SousMarin*)p.m_vectBoat[0];
            else if(p.m_vectBoat[0]->getType()== 'o')
                p.m_vectBoat[0] = (Croiseur*)p.m_vectBoat[0];
            return is;
        }




protected:
    std::vector<Boat*> m_vectBoat;
    std::vector<std::vector<char> > m_grille1;
    std::vector<std::vector<char> > m_grille2;
    int m_id;
};
#endif /* Player_hpp */
