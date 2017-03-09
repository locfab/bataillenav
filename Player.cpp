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
    std::vector<std::pair<char, int> > objet = { {'C', 1}, {'c', 2}, {'d', 3}, {'s', 4} };
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
                        
            
            
            if(type == 'C')
            {
                m_vectBoat.push_back(new Boat(coord, type, vertical));
            }
            if(type == 's')
            {
                m_vectBoat.push_back(new Boat(coord, type, vertical));
            }
            if(type == 'd')
            {
                m_vectBoat.push_back(new Boat(coord, type, vertical));
            }
            if(type == 'c')
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
