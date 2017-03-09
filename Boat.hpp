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




class Boat
{
public:
    Boat();
    Boat(std::pair<int, int> coord, char type, bool m_vertical);
    int envergure();
    std::pair<int, int> getCoord();
    bool getVertical();
    void printBoat();
    char getType();
protected:
    std::pair<int, int> m_coord;
    char m_type;
    bool m_vertical;
};

#endif /* Boat_hpp */
