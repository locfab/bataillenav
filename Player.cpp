//
//  Player.cpp
//  bn
//
//  Created by fabrice locqueville on 08/03/2017.
//  Copyright © 2017 fabrice locqueville. All rights reserved.
//

#include "Player.hpp"

Player::Player()
{
    
}
void Player::printGrill(char grille[15][15])
{
    std::cout << " ¦";
    for(int i(0); i<15; i++)
    {
        std::cout << std::setw(2) << std::setfill('0') << i;
        std::cout << "¦";
    }
    std::cout << std::endl;
    std::cout << " ¦--¦--¦--¦--¦--¦--¦--¦--¦--¦--¦--¦--¦--¦--¦--¦"<<  std::endl;
    for(int i(0); i<15; i++)
    {
        std::cout << (char)(i+'a') << "¦";
        
        for(int j(0); j<15; j++)
        {
            std::cout << "██" << "¦";
        }
        std::cout << std::endl;
        std::cout << " ¦--¦--¦--¦--¦--¦--¦--¦--¦--¦--¦--¦--¦--¦--¦--¦"<<  std::endl;
    }
}
