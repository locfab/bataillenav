//
//  destroyer.cpp
//  bn
//
//  Created by fabrice locqueville on 09/03/2017.
//  Copyright © 2017 fabrice locqueville. All rights reserved.
//

#include "Destroyer.hpp"


Destroyer::Destroyer()
{
    pConsole = Console::getInstance();
}
Destroyer::Destroyer(std::pair<int, int> coord, char type, bool vertical): Boat(coord, type, vertical)
{
    m_fusee = true;
}
void Destroyer::printBoat()
{
    pConsole->gotoLigCol(4,130);
    std::cout<<"                             ";
    pConsole->gotoLigCol(4,130);
    std::cout << "(" << (char)(m_coord.first+ 'a') << "," << m_coord.second << ")" << " - " << " Destroyer"<< std::endl<< std::endl;
    //pConsole->gotoLigCol(5,131);
    //std::cout<<"                             ";
    pConsole->gotoLigCol(6,130);
    if(m_fusee)
    {
        pConsole->setColor(COLOR_GREEN);
        std::cout<< "Fusee : Activable"  <<  "     " << std::endl;
    }

    else
    {
        pConsole->setColor(COLOR_RED);
        std::cout<< "Fusee : Inactivable"  <<  "   " << std::endl;
    }


    pConsole->setColor(COLOR_DEFAULT);

}
