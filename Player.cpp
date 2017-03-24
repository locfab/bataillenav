//
//  Player.cpp
//  bn
//
//  Created by fabrice locqueville on 08/03/2017.
//  Copyright © 2017 fabrice locqueville. All rights reserved.
//

#include "Player.hpp"
#include "Console.hpp"
#include <cstdlib>
#include <ctime>

Player::Player()
{
    std::vector<char> temp(15, '?');
    for(int i(0); i< 15; i++)
    {
        m_grille1.push_back(temp);
        m_grille2.push_back(temp);
    }
    pConsole = Console::getInstance();
}

void Player::play(Player adversaire)
{
    int choix(0);
    std::vector<std::string> menu;
    menu.push_back("1 - choix, deplacement");
    menu.push_back("2 - choix, rotation");
    menu.push_back("3 - choix, attaque");

    bool opetationEff(false);
    do
    {
        int a = -1;
        choix = 0;
        while(a != 13)
        {
            pConsole->gotoLigCol(35,0);
            for(int i=0;i<menu.size();i++)
            {
                if(choix==i)
                {
                    pConsole->setColor(COLOR_RED);
                    std::cout<<menu[i]<<std::endl;
                    pConsole->setColor(COLOR_DEFAULT);
                }
                else
                    std::cout<<menu[i]<<std::endl;
            }
            while(pConsole->isKeyboardPressed())
                {}
            a = pConsole->getInputKey();
            if(a == 's')
                choix++;
            if(a == 'z')
                choix--;
            choix %= menu.size();
        }

        if(choix == 0)
        {
            do
            {
                choix = choixBoat();
            }while(choix < 0 || choix > getVectBoat().size());
            opetationEff = moveBoat(choix);
        }
        else if(choix == 1)
        {
            do
            {
                choix = choixBoat();
            }while(choix < 0 || choix > getVectBoat().size());
            opetationEff = turnBoat(choix);
        }
        else if(choix == 2)
        {
            do
            {
                choix = choixBoat();
            }while(choix < 0 || choix > getVectBoat().size());

            int sizeAttacks = m_vectBoat[choix]->getSizeAttacks();
            std::pair<int, int> coord = std::make_pair(0,0);
            coord = moveZoneRight(coord, choix, sizeAttacks);
            if(coord.first != -1 && coord.second != -1) // si pas d'annulation dans moveZoneRight
            {
                std::vector<std::pair<int, int> > coords;
                int x = coord.first;
                int y = coord.second;
                for(int i(x); i<x+sizeAttacks; i++)//creation de la zone
                {
                    for(int j(y); j<y+sizeAttacks; j++)
                    {
                        coords.push_back(std::make_pair(i, j));
                    }
                }
                m_vectBoat[choix]->shotBoat(coords, adversaire.getVectBoat());
                opetationEff = true;
            }
        }
        if(!opetationEff)
            printGrill(adversaire);
    }while(!opetationEff);

    system("CLS");
    printGrill(adversaire);
    clock_t t = clock ();
    while(clock()-t < 2000){}

    //pConsole->gotoLigCol(35,60);
    //std::cout << adversaire.m_vectBoat[0]->getPointsTouches().size() << std::endl;
}
std::pair<int, int> Player::moveZoneRight(std::pair<int, int> coord, int choix, int sizeAttacks)
{
    int a;
    while(a != 13)
    {
        printZoneGrille2(coord, m_vectBoat[choix], sizeAttacks);
        while(!this->pConsole->isKeyboardPressed())
            {}
        a = this->pConsole->getInputKey();
        if(a==122)//z
        {
            coord.first--;
            if(coord.first<0)
                coord.first = 0;
        }
        if(a==113)//q
        {
            coord.second--;
            if(coord.second < 0)
                coord.second = 0;
        }
        if(a==115)//s
        {
            coord.first++;
            if(coord.first > (15-sizeAttacks))
                coord.first = (15-sizeAttacks);
        }
        if(a==100)//d
        {
            coord.second++;
            if(coord.second > (15-sizeAttacks))
                coord.second = (15-sizeAttacks);
        }
        if(a=='e')
            return std::make_pair(-1,-1);
    }
    return coord;
}

int Player::choixBoat() /// !!! ON NE PEUT PAS CHANGER DE CHOIX DE BATEAU !!!
{
    int a = 0;
    int boat = 0;
    while(a != 13) //entrer
    {
        printBoatGrille1(getVectBoat(), getVectBoat()[boat]);
        while(!this->pConsole->isKeyboardPressed())
        {}
        a = this->pConsole->getInputKey();
        if(a == 32)//espace
        {
            boat += 1;
            boat %= getVectBoat().size();
            printBoatGrille1(getVectBoat(), getVectBoat()[boat]);
        }
    }
    return boat;
}

bool Player::turnBoat(int y)  /// !!!! DOIT REVENIR A l'ETAPE D'AVANT SI BATEAU DEJA PRESENT !!!!
{
    Boat * b = m_vectBoat[y];
    if(!toucher(std::make_pair(b->getCoord().first, b->getCoord().second), !b->getVertical(), b->envergure(), y))
    {
        bool eff = b->setVertical();
        return eff;
    }
    else
    {
        return false;
    }
}

bool Player::moveBoat(int y) /// SE DIRIGE MAL -> LE BATEAU EST BIEN SELECTIONNE ET BOUGE, MAIS N'IMPORTE COMMENT ///
{
    std::pair<int, int> b = m_vectBoat[y]->getCoord();
    std::pair<int, int> dir;
    do
    {
        char direction;
        std::vector<std::pair<int, int> > allDir = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
        do{
            pConsole->gotoLigCol(39,0);
            std::cout << "Choisir la direction avec 'z', 'q', 's', 'd' ou 'e' pour sortir du menu" << std::endl;
            std::cout << "Direction : ";
            std::cin >> direction;
        }while(!(direction == 'z' || direction == 's' || direction == 'q' || direction == 'd' || direction == 'e'));

        if(direction == 'z')
            dir = allDir[1];
        else if(direction == 's')
            dir = allDir[0];
        else if(direction == 'q')
            dir = allDir[3];
        else if(direction == 'd')
            dir = allDir[2];
        else if(direction == 'e')
            return false;
        //std::cout << b.first << " + " << dir.first << " , " << b.second << " + " <<  dir.second << ", ver:  " << m_vectBoat[y]->getVertical() << ", env: " << m_vectBoat[y]->envergure() << ", indice: " <<  y << std::endl;
    }while(toucher(std::make_pair(b.first + dir.first, b.second + dir.second), m_vectBoat[y]->getVertical(), m_vectBoat[y]->envergure(), y));

    //std::cout << m_vectBoat[y]->getCoord().first << " - " << m_vectBoat[y]->getCoord().second << std::endl;
    m_vectBoat[y]->setCoord(b.first + dir.first, b.second + dir.second);
    return true;
    //std::cout << m_vectBoat[y]->getCoord().first << " - " << m_vectBoat[y]->getCoord().second << std::endl;
}

void Player::printColorBoat(Boat * b)
{
    int envergure = b->envergure();
    int x = b->getCoord().first;
    int y = b->getCoord().second;

    if(b->getVertical())
    {
        for(int i(x-envergure); i< x+envergure+1; i++)
        {
            pConsole->gotoLigCol(2*i+2, 3*y+2);
            pConsole->setColor(COLOR_YELLOW);
            std::cout << b->getType() << b->getType();

        }
    }
    else
    {
        for(int i(y-envergure); i< y+envergure+1; i++)
        {
            pConsole->gotoLigCol(2*x+2, 3*i+2);
            pConsole->setColor(COLOR_YELLOW);
            std::cout << b->getType() << b->getType();
        }
    }
    pConsole->setColor(COLOR_DEFAULT);
}

void Player::printZoneGrille2(std::pair<int, int> coord, Boat*b, int sizeAttacks)
{
    for(int i(0); i<15; i++)
    {
        for(int j(0); j<15; j++)
        {
            pConsole->gotoLigCol(2*i+2, 3*j+15*3+14);
            //pConsole->setColor(COLOR_YELLOW);
            std::cout << ' ' << ' ';
        }
    }
    int x = coord.first;
    int y = coord.second;
    for(int i(x); i<x+sizeAttacks; i++)
    {
        for(int j(y); j<y+sizeAttacks; j++)
        {
            pConsole->gotoLigCol(2*i+2, 3*j+15*3+14);
            pConsole->setColor(COLOR_YELLOW);
            std::cout << 'X' << 'X';
        }
    }
    pConsole->setColor(COLOR_DEFAULT);
}

void Player::printDefaultColorBoat(std::vector<Boat*> bs)
{
    for(int j(0); j<bs.size(); j++)
    {
        Boat * b = bs[j];
        int envergure = b->envergure();
        int x = b->getCoord().first;
        int y = b->getCoord().second;
        if(b->getVertical())
        {
            for(int i(x-envergure); i< x+envergure+1; i++)
            {
                pConsole->gotoLigCol(2*i+2, 3*y+2);
                std::cout << b->getType() << b->getType();

            }
        }
        else
        {
            for(int i(y-envergure); i< y+envergure+1; i++)
            {
                pConsole->gotoLigCol(2*x+2, 3*i+2);
                std::cout << b->getType() << b->getType();
            }
        }
    }
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

void Player::printGrill(Player &adversaire)
{
   // pConsole->setColor(COLOR_YELLOW);
    setGrille1();
    setGrille2(adversaire);
    system("CLS");
    pConsole->gotoLigCol(0,0);
    std::string espace = "          ";
    std::cout << " |";
    for(int i(0); i<15; i++)
    {
        std::cout << std::setw(2) << std::setfill('0') << i;
        std::cout << "|";
    }
    std::cout << espace + " |";
    for(int i(0); i<15; i++)
    {
        std::cout << std::setw(2) << std::setfill('0') << i;
        std::cout << "|";
    }
    std::cout << std::endl;
    std::cout << " |--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|";
    std::cout << espace;
    std::cout << " |--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|"<<  std::endl;
    for(int i(0); i<15; i++)
    {
        std::cout << (char)(i+'a') << "|";
        for(int j(0); j<15; j++)
        {
            //std::cout << "██" << "¦";
            if(m_grille1[i][j] != '?')
                std::cout << m_grille1[i][j] << m_grille1[i][j] << "|";
            else
                std::cout << " " << " " << "|";
        }
        std::cout << espace;
        std::cout << (char)(i+'a') << "|";
        for(int j(0); j<15; j++)
            {
            //std::cout << "██" << "¦";
            if(m_grille2[i][j] == 't')
                std::cout << "X" << "X" << "|";
            else if(m_grille2[i][j] != '?')
                std::cout << m_grille2[i][j] << m_grille2[i][j] << "¦";
            else
                std::cout << " " << " " << "|";
        }
        std::cout << std::endl;
        std::cout << " |--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|";
        std::cout << espace;
        std::cout << " |--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|"<<  std::endl;
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

void Player::setGrille2(Player adversaire)
{
    std::vector <Boat*> boatsAdv = adversaire.getVectBoat();
    for(int i(0); i< boatsAdv.size(); i++)
    {
        for(int j(0); j< boatsAdv[i]->getPointsTouches().size(); j++)
        {
            std::pair<int, int> coordTouche = boatsAdv[i]->getPointsTouches()[j];
            m_grille2[coordTouche.first][coordTouche.second] = 't';
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
                m_vectBoat.push_back(new Cuirace(coord, type, vertical));
            }
            if(type == 's')
            {
                m_vectBoat.push_back(new SousMarin(coord, type, vertical));
            }
            if(type == '+')
            {
                m_vectBoat.push_back(new Destroyer(coord, type, vertical));
            }
            if(type == 'o')
            {
                m_vectBoat.push_back(new Croiseur(coord, type, vertical));
            }
        }
    }
    /*for(int i(0); i<m_vectBoat.size(); i++)
    {
        m_vectBoat[i]->printBoat();
    }*/
}
void Player::printBoatGrille1(std::vector<Boat*> bs, Boat * b)
{
    printDefaultColorBoat(bs);
    printColorBoat(b);
    pConsole->gotoLigCol(3,130);
    b->printBoat();
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
                                //std::cout << " bateau " << j  << " coord "<< i << " - " << coord.second << std::endl;
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
                                //std::cout << " bateau " << j  << " coord "<< i << " - " << k << std::endl;
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
                                //std::cout << " bateau " << j  << " coord "<< i << " - " << k << std::endl;
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
                                //std::cout << " bateau " << j  << " coord "<< i << " - " << coord.first << std::endl;
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
