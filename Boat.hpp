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

protected:
    std::pair<int, int> m_coord;
    char m_type;
    bool m_vertical;
    bool m_touche;
    int m_sizeAttack;
    std::vector<std::pair<int, int> > m_pointsTouches;
};

#endif /* Boat_hpp */
