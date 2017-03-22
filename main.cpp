//
//  main.cpp
//  bn
//
//  Created by fabrice locqueville and Quentin Perraudin and l'autre on 08/03/2017.
//  Copyright © 2017 fabrice locqueville. All rights reserved.
//

#include "Partie.hpp"
#include "Console.hpp"
#include <iostream>
#include <vector>
#include <string>
//test
int main(int argc, const char * argv[]) {
    int choix = 1;
    Console* p=Console::getInstance();
    srand(time(NULL));
    std::vector<std::string> menu;
    menu.push_back("1 - Jouer");
    menu.push_back("2 - charger partie");
    menu.push_back("3 - aide");
    menu.push_back("4 - quitter");

    for(int i=0;i<menu.size();i++)
    {
        if(choix==i)
        {
            p->setColor(COLOR_BLUE);
            std::cout<<menu[i]<<std::endl;
            p->setColor(COLOR_DEFAULT);
        }
        std::cout<<menu[i]<<std::endl;
    }

    if(choix == 1)
    {
        Partie partie;
        partie.boucleDeJeu(true);
    }
    else if(choix == 2)
    {
        Partie partie;
        partie.getInfoSauv();
        partie.boucleDeJeu(true);

    }
    else if(choix == 3)
    {

    }
    else if(choix == 4)
    {

    }

    return 0;
}
