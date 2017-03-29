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
    bool setVertical();
    int getSizeAttacks();
    std::vector<std::pair<int, int> > getPointsTouches();
    void setPointsTouches(int x, int y);
    void setPointsTouches(std::pair<int, int> coord);
    void setTouche();
    virtual void printBoat();
    char getType();
    void setType(char type);
    void shotBoat(std::vector<std::pair<int, int> > coords, std::vector<Boat*> vectBoatAdvers);
    virtual void attaque(std::pair<int, int> coord, std::vector<Boat*> vectBoatAdvers);
    void setFusee();
    void setCoule();
    bool getCoule();
    void seeFusee(std::vector<std::pair<int, int> > coords, std::vector<Boat*> vectBoatAdvers);


friend std::ostream& operator<<(std::ostream& os, const std::vector<Boat*> &b)
{
    os << b.size() << std::endl;
    for(int i=0;i<b.size();i++)
    {
        os << b[i]->m_type << " " << b[i]->m_coord.first << " " << b[i]->m_coord.second<< " " << b[i]->m_vertical << " " << b[i]->m_touche;
        os << " " << b[i]->m_coule << " " << b[i]->m_sizeAttack << " " << b[i]->m_fusee << std::endl;

        os << b[i]->getPointsTouches().size() << " ";
        for(int j(0); j<b[i]->getPointsTouches().size(); j++)
        {
            os << b[i]->getPointsTouches()[j].first << " " << b[i]->getPointsTouches()[j].second << " ";
        }
        os << std::endl;
    }

    return os;
}

friend std::istream& operator>>(std::istream& is, Boat &b)
{
    is >> b.m_coord.first >> b.m_coord.second;
    is >> b.m_vertical >> b.m_touche >> b.m_coule >> b.m_sizeAttack >> b.m_fusee;
    int c;
    is >> c;
    for(int j(0); j<c; j++)
    {
        std::pair<int, int> temp;
        is >> temp.first >> temp.second;
        b.m_pointsTouches.push_back(temp);
    }
    return is;
}


protected:
    char m_type;
    std::pair<int, int> m_coord;
    bool m_vertical;
    bool m_touche;
    bool m_coule;
    int m_sizeAttack;
    bool m_fusee;
    std::vector<std::pair<int, int> > m_pointsTouches;
};

#endif /* Boat_hpp */
