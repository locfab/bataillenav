//
//  main.cpp
//  bn
//
//  Created by fabrice locqueville et les autres on 08/03/2017.
//  Copyright © 2017 fabrice locqueville. All rights reserved.
//

#include "Partie.hpp"
#include <iostream>
#include <vector>

int main(int argc, const char * argv[]) {
    
    std::cout << "1 - Jouer" << std::endl;
    std::cout << "2 - charger partie" << std::endl;
    std::cout << "3 - aide" << std::endl;
    std::cout << "4 - quitter" << std::endl;
    
    int choix(-1);
    std::cout << "faite un choix compris entre 1 et 4" << std::endl;
    do{
        std::cin >> choix;
    }while(choix < 1 || choix > 4);
    
    std::cout << choix << std::endl;
    char a[15][15];
    if(choix == 1)
    {
        Partie partie;
    }
    else if(choix == 2)
    {
        Partie partie;
    }
    else if(choix == 3)
    {
        
    }
    else if(choix == 4)
    {
        
    }
    
    return 0;
}
