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

class Player
{
public:
    Player();
    void printGrill(char grille[15][15]);
protected:
    std::vector<Boat*> boat;
    char grille1[15][15];
    char grille2[15][15];
};
#endif /* Player_hpp */
