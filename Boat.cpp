//
//  Boat.cpp
//  bn
//
//  Created by fabrice locqueville on 08/03/2017.
//  Copyright © 2017 fabrice locqueville. All rights reserved.
//

#include "Boat.hpp"

Boat::Boat()
{
}
Boat::Boat(std::pair<int, int> coord, char type, bool vertical)
{
    m_coord = coord;
    m_type = type;
    m_vertical = vertical;
    
}

int Boat::envergure()
{
    if(this->m_type == 'C')
        return 3;
    if(this->m_type == 's')
        return 0;
    if(this->m_type == 'd')
        return 1;
    if(this->m_type == 'c')
        return 2;
    std::cout << this->m_type << "  ERREUR!!! PAS DE REFERENCE BATEAU" << std::endl;
    return -1;
}

std::pair<int, int> Boat::getCoord()
{
    return m_coord;
}
bool Boat::getVertical()
{
    return m_vertical;
}
void Boat::printBoat()
{
    std::cout << "(" << (char)(m_coord.first+ 'a') << "," << m_coord.second << ")" << " - " << m_type << " - " << m_vertical << std::endl;
}
char Boat::getType()
{
    return m_type;
}

