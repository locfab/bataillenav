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
    m_touche = false;
    
}

int Boat::envergure()
{
    if(this->m_type == '*')
        return 3;
    if(this->m_type == 's')
        return 0;
    if(this->m_type == '+')
        return 1;
    if(this->m_type == 'o')
        return 2;
    std::cout << this->m_type << "  ERREUR!!! PAS DE REFERENCE BATEAU" << std::endl;
    return -1;
}

std::pair<int, int> Boat::getCoord()
{
    return m_coord;
}
void Boat::setCoord(int x, int y)
{
    if(x<15 && x>=0 && y<15 && y>=0)
    {
        m_coord.first = x;
        m_coord.second = y;
    }
}
void Boat::setCoord(std::pair<int, int> coord)
{
    setCoord(coord.first, coord.second);
}

void Boat::setVertical()
{
    int x =  this->getCoord().first;
    int y =  this->getCoord().second;
    
    if(x +envergure() < 15 && x - envergure() >= 0 && y +envergure() < 15 && y - envergure() >= 0)
    {
        if(this->getVertical())
        {
            this->m_vertical = false;
        }
        else
        {
            this->m_vertical = true;
        }
    }
    else
    {
        std::cout << "Impossible, DEPASSEMENT" << std::endl;
    }
}

void Boat::setTouche()
{
    this->m_touche = true;
}

void Boat::setPointsTouches(int x, int y)
{
    setPointsTouches(std::make_pair(x, y));
}
void Boat::setPointsTouches(std::pair<int, int> coord)
{
    m_pointsTouches.push_back(coord);
}

std::vector<std::pair<int, int>> Boat::getPointsTouches()
{
    return m_pointsTouches;
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


