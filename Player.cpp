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
    std::vector<char> temp(15, '?');
    for(int i(0); i< 15; i++)
    {
        m_grille1.push_back(temp);
    }
    this->aleaGrille1();
}

void Player::play()
{
    std::cout << "1 - choix" << std::endl;
    std::cout << "2 - choix" << std::endl;
    std::cout << "3 - choix" << std::endl;
    
    int choix(-1);
    std::cout << "faite un choix compris entre 1 et 4" << std::endl;
    do{
        std::cin >> choix;
    }while(choix < 1 || choix > 3);
    
    if(choix == 1)
    {
        moveBoat(0);
    }
    else if(choix == 2)
    {
        //turnBoat();
    }
    else if(choix == 3)
    {
        char lettre;
        int nombre;
        do{
            std::cin >> lettre;
            std::cin >> nombre;
        }while(lettre < 'a' || lettre > 'o' || nombre < 1 || nombre > 14);
        //shotBoat((int)(lettre-'a'), nombre);
    }
    printGrill();
}

void Player::moveBoat(int y)
{
    std::pair<int, int> b = m_vectBoat[y]->getCoord();
    std::pair<int, int> dir;
    std::cout << b.first << " - " << b.second << std::endl;
    do
    {
        char direction;
        std::vector<std::pair<int, int>> allDir = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
        do{
            std::cout << "choisir la direction avec 'h', 'b', 'g' ou 'd'" << std::endl;
            std::cin >> direction;
        }while(!(direction == 'h' || direction == 'b' || direction == 'g' || direction == 'd'));
        
        if(direction == 'h')
            dir = allDir[1];
        else if(direction == 'b')
            dir = allDir[0];
        else if(direction == 'g')
            dir = allDir[3];
        else if(direction == 'd')
            dir = allDir[2];
        //std::cout << b.first << " + " << dir.first << " , " << b.second << " + " <<  dir.second << ", ver:  " << m_vectBoat[y]->getVertical() << ", env: " << m_vectBoat[y]->envergure() << ", indice: " <<  y << std::endl;
    }while(toucher(std::make_pair(b.first + dir.first, b.second + dir.second), m_vectBoat[y]->getVertical(), m_vectBoat[y]->envergure(), y));
    
    std::cout << m_vectBoat[y]->getCoord().first << " - " << m_vectBoat[y]->getCoord().second << std::endl;
    m_vectBoat[y]->setCoord(b.first + dir.first, b.second + dir.second);
    std::cout << m_vectBoat[y]->getCoord().first << " - " << m_vectBoat[y]->getCoord().second << std::endl;

}


std::vector<std::vector<char>> Player::getGrille1()
{
    return m_grille1;
}

std::vector<std::vector<char>> Player::getGrille2()
{
    return m_grille2;
}

std::vector<Boat*> Player::getVectBoat()
{
    return m_vectBoat;
}

void Player::printGrill()
{
    setGrille1();
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
            //std::cout << "██" << "¦";
            if(m_grille1[i][j] != '?')
                std::cout << m_grille1[i][j] << m_grille1[i][j] << "¦";
            else
                std::cout << " " << " " << "¦";
        }
        std::cout << std::endl;
        std::cout << " ¦--¦--¦--¦--¦--¦--¦--¦--¦--¦--¦--¦--¦--¦--¦--¦"<<  std::endl;
    }
}

void Player::setGrille1()
{
    for(int i(0); i<15; i++)
        for(int j(0); j<15; j++)
            m_grille1[i][j] = '?';
    for(int j(0); j < m_vectBoat.size(); j++)
    {
        if(m_vectBoat[j]->getVertical())
        {
            int deb = m_vectBoat[j]->getCoord().first - m_vectBoat[j]->envergure();
            int fin = m_vectBoat[j]->getCoord().first + m_vectBoat[j]->envergure();
            for(int i(deb); i < fin +1 ; i++)
            {
                m_grille1[i][m_vectBoat[j]->getCoord().second] = m_vectBoat[j]->getType();
            }
        }
        else
        {
            int deb = m_vectBoat[j]->getCoord().second - m_vectBoat[j]->envergure();
            int fin = m_vectBoat[j]->getCoord().second + m_vectBoat[j]->envergure();
            
            for(int i(deb); i <  fin + 1; i++)
            {
                m_grille1[m_vectBoat[j]->getCoord().first][i] = m_vectBoat[j]->getType();
            }
        }
    }
}



void Player::aleaGrille1()
{
    std::vector<std::pair<char, int> > objet = { {'*', 1}, {'o', 2}, {'+', 3}, {'s', 4} };
    for(int i(0); i<objet.size(); i++)
    {
        for(int j(0); j< objet[i].second; j++)
        {
            char type = objet[i].first;
            std::pair<int, int> coord;
            bool vertical;
            int envergure = 4-objet[i].second;
            do
            {
                vertical = rand()%2;
                if(vertical)
                {
                    int x = rand()%(15-2*(envergure)-1)+envergure;
                    coord = std::make_pair(x, rand()%15);
                }
                else
                {
                    int y = rand()%(15-2*(envergure)-1)+envergure;
                    coord = std::make_pair(rand()%15, y);
                }
            }while(toucher(coord, vertical, envergure)); //"objet[i].second-1", c'est l'eloignement du centre
                        
            
            
            if(type == '*')
            {
                m_vectBoat.push_back(new Boat(coord, type, vertical));
            }
            if(type == 's')
            {
                m_vectBoat.push_back(new Boat(coord, type, vertical));
            }
            if(type == '+')
            {
                m_vectBoat.push_back(new Boat(coord, type, vertical));
            }
            if(type == 'o')
            {
                m_vectBoat.push_back(new Boat(coord, type, vertical));
            }
        }
    }
    this->setGrille1();
    this->printGrill();
    
    for(int i(0); i<m_vectBoat.size(); i++)
    {
        m_vectBoat[i]->printBoat();
    }
}

bool Player::toucher(std::pair<int, int> coord, bool vertical, int envergure)
{
    if(vertical)
    {
        for(int i(coord.first - envergure); i <  coord.first + envergure + 1; i++)
        {
            for(int j(0); j< m_vectBoat.size(); j++)
            {
                if(m_vectBoat[j]->getVertical() )
                {
                    int deb = m_vectBoat[j]->getCoord().first - m_vectBoat[j]->envergure();
                    int fin = m_vectBoat[j]->getCoord().first + m_vectBoat[j]->envergure();
                    for(int k(deb); k<fin+1; k++)
                    {
                        if(i==k && coord.second == m_vectBoat[j]->getCoord().second)
                            return true;
                    }
                }
                else
                {
                    int deb = m_vectBoat[j]->getCoord().second - m_vectBoat[j]->envergure();
                    int fin = m_vectBoat[j]->getCoord().second + m_vectBoat[j]->envergure();
                    for(int k(deb); k<fin+1; k++)
                    {
                        if(i == m_vectBoat[j]->getCoord().first && k == coord.second)
                            return true;
                    }
                }
            }
        }
    }
    else
    {
        for(int i(coord.second - envergure); i <  coord.second + envergure + 1; i++)
        {
            for(int j(0); j< m_vectBoat.size(); j++)
            {
                if(m_vectBoat[j]->getVertical() )
                {
                    int deb = m_vectBoat[j]->getCoord().first - m_vectBoat[j]->envergure();
                    int fin = m_vectBoat[j]->getCoord().first + m_vectBoat[j]->envergure();
                    for(int k(deb); k<fin+1; k++)
                    {
                        if(i == m_vectBoat[j]->getCoord().second && coord.first == k)
                            return true;
                    }
                }
                else
                {
                    int deb = m_vectBoat[j]->getCoord().second - m_vectBoat[j]->envergure();
                    int fin = m_vectBoat[j]->getCoord().second + m_vectBoat[j]->envergure();
                    for(int k(deb); k<fin+1; k++)
                    {
                        if(i==k && coord.first == m_vectBoat[j]->getCoord().first)
                            return true;
                    }
                }
            }
        }
    }
    
    return false;
}
bool Player::toucher(std::pair<int, int> coord, bool vertical, int envergure, int sansIndiceBoat)
{
    if(vertical)
    {
        for(int i(coord.first - envergure); i <  coord.first + envergure + 1; i++)
        {
            for(int j(0); j< m_vectBoat.size(); j++)
            {
                if(j != sansIndiceBoat)
                {
                    if(m_vectBoat[j]->getVertical() )
                    {
                        int deb = m_vectBoat[j]->getCoord().first - m_vectBoat[j]->envergure();
                        int fin = m_vectBoat[j]->getCoord().first + m_vectBoat[j]->envergure();
                        for(int k(deb); k<fin+1; k++)
                        {
                            if(i==k && coord.second == m_vectBoat[j]->getCoord().second)
                            {
                                std::cout << " bateau " << j  << " coord "<< i << " - " << coord.second << std::endl;
                                return true;
                            }
                            
                        }
                    }
                    else
                    {
                        int deb = m_vectBoat[j]->getCoord().second - m_vectBoat[j]->envergure();
                        int fin = m_vectBoat[j]->getCoord().second + m_vectBoat[j]->envergure();
                        for(int k(deb); k<fin+1; k++)
                        {
                            if(i == m_vectBoat[j]->getCoord().first && k == coord.second)
                            {
                                std::cout << " bateau " << j  << " coord "<< i << " - " << k << std::endl;
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
    else
    {
        for(int i(coord.second - envergure); i <  coord.second + envergure + 1; i++)
        {
            for(int j(0); j< m_vectBoat.size(); j++)
            {
                if(j != sansIndiceBoat)
                {
                    if(m_vectBoat[j]->getVertical() )
                    {
                        int deb = m_vectBoat[j]->getCoord().first - m_vectBoat[j]->envergure();
                        int fin = m_vectBoat[j]->getCoord().first + m_vectBoat[j]->envergure();
                        for(int k(deb); k<fin+1; k++)
                        {
                            if(i == m_vectBoat[j]->getCoord().second && coord.first == k)
                            {
                                std::cout << " bateau " << j  << " coord "<< i << " - " << k << std::endl;
                                return true;
                            }
                        }
                    }
                    else
                    {
                        int deb = m_vectBoat[j]->getCoord().second - m_vectBoat[j]->envergure();
                        int fin = m_vectBoat[j]->getCoord().second + m_vectBoat[j]->envergure();
                        for(int k(deb); k<fin+1; k++)
                        {
                            if(i==k && coord.first == m_vectBoat[j]->getCoord().first)
                            {
                                std::cout << " bateau " << j  << " coord "<< i << " - " << coord.first << std::endl;
                                return true;
                            }
                        }
                    }

                }
            }
        }
    }
    return false;
}

