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
    virtual void printBoat();
    char getType();
    void shotBoat(std::vector<std::pair<int, int> > coords, std::vector<Boat*> vectBoatAdvers);
    virtual void attaque(std::pair<int, int> coord, std::vector<Boat*> vectBoatAdvers);
    void setFusee();
    void setCoule();
    bool getCoule();

protected:
    std::pair<int, int> m_coord;
    char m_type;
    bool m_vertical;
    bool m_touche;
    bool m_coule;
    int m_sizeAttack;
    bool m_fusee;
    std::vector<std::pair<int, int> > m_pointsTouches;
};

#endif /* Boat_hpp */
