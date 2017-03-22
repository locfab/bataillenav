//
//  Boat.hpp
//  bn
//
//  Created by fabrice locqueville on 08/03/2017.
//  Copyright © 2017 fabrice locqueville. All rights reserved.
//

#ifndef Boat_hpp
#define Boat_hpp

#include <iostream>
#include <vector>






class Boat
{
public:
    Boat();
    Boat(std::pair<int, int> coord, char type, bool m_vertical);
    int envergure();
    std::pair<int, int> getCoord();
    void setCoord(int x, int y);
    void setCoord(std::pair<int, int> coord);
    bool getVertical();
    void setVertical();
    int getSizeAttacks();
    std::vector<std::pair<int, int> > getPointsTouches();
    void setPointsTouches(int x, int y);
    void setPointsTouches(std::pair<int, int> coord);
    void setTouche();
    void printBoat();
    char getType();
    void shotBoat(std::vector<std::pair<int, int> > coords, std::vector<Boat*> vectBoat);
    void attaque(std::pair<int, int> coord, std::vector<Boat*> vectBoat);
    void setFusee();

friend std::istream& operator>>(std::istream& is, std::vector<Boat*> &b)
{
    int a;
    is >> a;
    for(int i(0); i< a; i++)
    {
        Boat *boatTemp = new Boat();
        is >> boatTemp->m_coord.first >> boatTemp->m_coord.second >> boatTemp->m_type;
        is >> boatTemp->m_vertical >> boatTemp->m_touche >> boatTemp->m_sizeAttack >> boatTemp->m_fusee;

        int c;
        is >> c;
        for(int j(0); j<c; j++)
        {
            std::pair<int, int> temp;
            is >> temp.first >> temp.second;
            boatTemp->m_pointsTouches.push_back(temp);
        }

        /*if(boatTemp->m_type == '*')
        {
            b.push_back((Cuirace)boatTemp);
        }
        if(boatTemp->m_type == 's')
        {
            b.push_back((SousMarin)boatTemp);
        }
        if(boatTemp->m_type == '+')
        {
            b.push_back((Destroyer)boatTemp);
        }
        if(boatTemp->m_type == 'o')
        {
            b.push_back((Croiseur)boatTemp);
        }*/
        if(boatTemp->m_type == '*')
        {
            b.push_back(boatTemp);
        }
        if(boatTemp->m_type == 's')
        {
            b.push_back(boatTemp);
        }
        if(boatTemp->m_type == '+')
        {
            b.push_back(boatTemp);
        }
        if(boatTemp->m_type == 'o')
        {
            b.push_back(boatTemp);
        }
    }
    //for(int i(0); i<10; i++)
      //  std::cout << "faux: " << b[i]->getCoord().first << "," << b[i]->getCoord().second << std::endl;
        //std::cout << std::endl;
    return is;
}


friend std::ostream& operator<<(std::ostream& os, const std::vector<Boat*> &b)
{
    os << b.size() << std::endl;
    for(int i=0;i<b.size();i++)
    {
        os << b[i]->m_coord.first << " " << b[i]->m_coord.second << " " << b[i]->m_type << " " << b[i]->m_vertical << " " << b[i]->m_touche;
        os << " " << b[i]->m_sizeAttack << " " << b[i]->m_fusee << std::endl;

        os << b[i]->getPointsTouches().size() << " ";
        for(int j(0); j<b[i]->getPointsTouches().size(); j++)
        {
            os << b[i]->getPointsTouches()[j].first << " " << b[i]->getPointsTouches()[j].second << " ";
        }
        os << std::endl;
    }

    return os;
}

protected:
    std::pair<int, int> m_coord;
    char m_type;
    bool m_vertical;
    bool m_touche;
    int m_sizeAttack;
    bool m_fusee;
    std::vector<std::pair<int, int> > m_pointsTouches;
};

#endif /* Boat_hpp */
