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
}
Destroyer::Destroyer(std::pair<int, int> coord, char type, bool vertical): Boat(coord, type, vertical)
{
    m_fusee = true;
}
void Destroyer::printBoat()
{
    std::cout << "(" << (char)(m_coord.first+ 'a') << "," << m_coord.second << ")" << " - " << m_type << " - ";
    if(m_fusee)
        std::cout<< "Fusee : Activable"  <<  "     " << std::endl;
    else
        std::cout<< "Fusee : Inactivable"  <<  "   " << std::endl;
}
