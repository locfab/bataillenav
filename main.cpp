//
//  main.cpp
//  bn
//
//  Created by Fabrice locqueville and Quentin Perraudin and Théophile Grimault on 08/03/2017.
//  Copyright © 2017 PeTheFa. All rights reserved.
//

#include "Partie.hpp"
#include "Console.hpp"
#include <iostream>
#include <vector>
#include <string>

inline bool exist() {
    std::ifstream myfile;
    bool exist(false);
    myfile.open("binary",std::ios::binary | std::ios::in);
    exist = myfile.good();
    myfile.close();
    return exist;
}

//test
int main(int argc, const char * argv[]) {

    int choix = 0;
    Console* p=Console::getInstance();
    srand(time(NULL));
    std::vector<std::string> menu;
    menu.push_back("1 - Jouer");
    menu.push_back("2 - Charger partie");
    menu.push_back("3 - Aide");
    menu.push_back("4 - Quitter");

    while(choix != 3)
    {
        int a;
        while(a != 13)
        {
            system("CLS");
            p->gotoLigCol(0,0);
            std::cout <<std::endl<< "\t\t\tMenu"<<std::endl<<std::endl<<std::endl;
            for(int i=0;i<menu.size();i++)
            {
                if(choix==i)
                {
                    p->setColor(COLOR_RED);
                    std::cout<<menu[i]<<std::endl<<std::endl;
                    p->setColor(COLOR_DEFAULT);
                }
                else
                    std::cout<<menu[i]<<std::endl<<std::endl;
            }
            p->gotoLigCol(15,0);
            std::cout << "                                 o o" <<std::endl;
            std::cout << "                                 o ooo" << std::endl;
            std::cout << "                                   o oo" << std::endl;
            std::cout << "                                      o o      |   #)" <<std::endl;
            std::cout << "                                       oo     _|_|_#_" <<std::endl;
            std::cout << "                                         o   | U505  |" <<std::endl;
            std::cout << "    __                    ___________________|       |_________________" <<std::endl;
            std::cout << "   |   -_______-----------                                              \\ " <<std::endl;
            std::cout << "  >|    _____                                                   --->     )" <<std::endl;
            std::cout << "   |__ -     ---------_________________________________________________ /" <<std::endl;

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
            if(exist())
            {
                partie.getInfoSauv();
                sauv = partie.boucleDeJeu(true);
                if(sauv)
                    partie.sauvegarde();
            }
            else
                a=0;
        }
        else if(choix == 2)
        {

        }
    }

    return 0;
}
