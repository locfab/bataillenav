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

class Player
{
public:
    Player();
    void printGrill();
    std::vector<std::vector<char> > getGrille1();
    std::vector<std::vector<char> > getGrille2();
    std::vector<Boat*> getVectBoat();
    void aleaGrille1();
    void setGrille1();
    bool toucher(std::pair<int, int> coord, bool vectical, int envergure);
protected:
    std::vector<Boat*> m_vectBoat;
    std::vector<std::vector<char>> m_grille1;
    std::vector<std::vector<char>> m_grille2;
};
#endif /* Player_hpp */
