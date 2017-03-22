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

    int choix = 0;
    Console* p=Console::getInstance();
    srand(time(NULL));
    std::vector<std::string> menu;
    menu.push_back("1 - Jouer");
    menu.push_back("2 - charger partie");
    menu.push_back("3 - aide");
    menu.push_back("4 - quitter");

    int a;
    while(a != 13)
    {
        system("CLS");
        p->gotoLigCol(0,0);
        for(int i=0;i<menu.size();i++)
        {
            if(choix==i)
            {
                p->setColor(COLOR_BLUE);
                std::cout<<menu[i]<<std::endl;
                p->setColor(COLOR_DEFAULT);
            }
            else
                std::cout<<menu[i]<<std::endl;
        }
        while(p->isKeyboardPressed())
            {}
        a = p->getInputKey();
        if(a == 's')
            choix++;
        if(a == 'z')
            choix--;
        choix %= menu.size();
    }


    if(choix == 0)
    {
        Partie partie;
        partie.aleaGrill1();
        partie.boucleDeJeu(true);
        partie.sauvegarde();
    }
    else if(choix == 1)
    {
        bool sauv(false);
        Partie partie;
        partie.getInfoSauv();
        sauv = partie.boucleDeJeu(true);
        if(sauv)
            partie.sauvegarde();
    }
    else if(choix == 2)
    {

    }
    else if(choix == 3)
    {

    }

    return 0;
}
