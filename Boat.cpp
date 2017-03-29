//
//  Boat.cpp
//  bn
//
//  Created by fabrice locqueville on 08/03/2017.
//  Copyright © 2017 fabrice locqueville. All rights reserved.
//

#include "Boat.hpp"
#include "Console.hpp"
#include <ctime>

Boat::Boat()
{
    pConsole = Console::getInstance();
}
Boat::Boat(std::pair<int, int> coord, char type, bool vertical)
{
    m_coord = coord;
    m_type = type;
    m_vertical = vertical;
    m_touche = false;
    m_fusee = false;
    m_coule = false;

    if(m_type == '*')
        m_sizeAttack = 3;
    else if(m_type == 's')
        m_sizeAttack = 1;
    else if(m_type == '+')
        m_sizeAttack = 1;
    else if(m_type == 'o')
        m_sizeAttack = 2;
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


void Boat::shotBoat(std::vector<std::pair<int, int> > coords, std::vector<Boat*> vectBoatAdvers)
{
    for(int i(0); i< coords.size(); i++)
        attaque(coords[i], vectBoatAdvers);
}
void Boat::seeFusee(std::vector<std::pair<int, int> > coords, std::vector<Boat*> vectBoatAdvers)
{
    Console * p = Console::getInstance();
    for(int i(0); i< vectBoatAdvers.size(); i++)
    {
        for(int j(0); j<vectBoatAdvers[i]->getPointsTouches().size(); j++)
        {
            for(int k(0); k< coords.size(); k++)
            {
                int x = vectBoatAdvers[i]->getPointsTouches()[j].first;
                int y = vectBoatAdvers[i]->getPointsTouches()[j].second;

                if(x == coords[k].first)
                {
                    if(y == coords[k].second)
                    {
                        p->gotoLigCol(50,50);
                        std::cout << "ddns";
                        p->gotoLigCol(2*x+2,3*y+45+14);
                        p->setColor(COLOR_RED);
                        std::cout << "XX";
                        p->setColor(COLOR_DEFAULT);
                        while(0==0){}
                    }
                }
            }
        }
    }
    this->setFusee();
    clock_t t = clock();
    while(clock()-t<3000){}
    while(p->isKeyboardPressed()){p->getInputKey();}
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

bool Boat::setVertical()
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
        return true;
    }
    else
    {
        return false;
    }
}
int Boat::getSizeAttacks()
{
    if(this->m_fusee)
    {
        std::cout <<std::endl<< "Voulez-vous utiliser la fusee? Tapez 'y' si oui - tapez une autre touche si non." << std::endl;
        char choix;
        std::cin >> choix;
        if(choix == 'y')
            return 4;
    }

    return m_sizeAttack;
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








std::vector<std::pair<int, int> > Boat::getPointsTouches()
{
    return m_pointsTouches;
}

bool Boat::getVertical()
{
    return m_vertical;
}
void Boat::printBoat()
{
    pConsole->gotoLigCol(4,130);
    std::cout<<"                             ";
    pConsole->gotoLigCol(6,130);
    std::cout<<"                             ";
    pConsole->gotoLigCol(4,130);
    std::cout << "(" << (char)(m_coord.first+ 'a') << "," << m_coord.second << ")" << " - ";
    if(m_type == '*'){std::cout << " Cuirasse";}
    if(m_type == '+'){std::cout << " Destroyer";}
    if(m_type == 's'){std::cout << " Sous-marin";}
    if(m_type == 'o'){std::cout << " Croiseur";}
}
char Boat::getType()
{
    return m_type;
}
void Boat::setType(char type)
{
    if(type == '*' || type == '+' || type == 's' || type == 'o')
    {
        m_type = type;
    }
}
void Boat::setFusee()
{
    m_fusee = false;
}
void Boat::setCoule()
{
    if(this->getPointsTouches().size() == this->envergure()*2+1)
        this->m_coule = true;
}
bool Boat::getCoule()
{
    return m_coule;
}
void Boat::attaque(std::pair<int, int> coord, std::vector<Boat*> vectBoatAdvers)
{
    for(int j(0); j< vectBoatAdvers.size(); j++)
    {
       if(vectBoatAdvers[j]->getVertical() )
        {
            int deb = vectBoatAdvers[j]->getCoord().first - vectBoatAdvers[j]->envergure();
            int fin = vectBoatAdvers[j]->getCoord().first + vectBoatAdvers[j]->envergure();
            for(int k(deb); k<fin+1; k++)
            {
                if(coord.first == k && coord.second == vectBoatAdvers[j]->getCoord().second)
                {
                    bool present(false);
                    for(int l(0); l < vectBoatAdvers[j]->getPointsTouches().size(); l++)
                    {
                        if(vectBoatAdvers[j]->getPointsTouches()[l] == coord)
                        {
                            present = true;
                            break;
                        }
                    }
                    if(!present)
                    {
                        vectBoatAdvers[j]->setPointsTouches(coord);
                        vectBoatAdvers[j]->setCoule();
                    }
                    return;
                }

            }
        }
        else
        {
            int deb = vectBoatAdvers[j]->getCoord().second - vectBoatAdvers[j]->envergure();
            int fin = vectBoatAdvers[j]->getCoord().second + vectBoatAdvers[j]->envergure();
            for(int k(deb); k<fin+1; k++)
            {
                if(coord.first == vectBoatAdvers[j]->getCoord().first && k == coord.second)
                {
                    bool present(false);
                    for(int l(0); l < vectBoatAdvers[j]->getPointsTouches().size(); l++)
                    {
                        if(vectBoatAdvers[j]->getPointsTouches()[l] == coord)
                        {
                            present = true;
                            break;
                        }
                    }
                    if(!present)
                    {
                        vectBoatAdvers[j]->setPointsTouches(coord);
                        vectBoatAdvers[j]->setCoule();
                    }
                    return;
                }
            }
        }
    }
}
