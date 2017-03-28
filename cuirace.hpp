//
//  cuirace.hpp
//  bn
//
//  Created by fabrice locqueville on 09/03/2017.
//  Copyright © 2017 fabrice locqueville. All rights reserved.
//

#ifndef cuirace_hpp
#define cuirace_hpp

#include "Boat.hpp"

class Cuirace: public Boat
{
public:
    Cuirace();
    Cuirace(std::pair<int, int> coord, char type, bool vertical);

    friend std::istream& operator>>(std::istream& is, Cuirace& b)
    {
        int a;
        is >> a;
        for(int i(0); i< a; i++)
        {
            is >> b.m_coord.first >> b.m_coord.second >> b.m_type;
            is >> b.m_vertical >> b.m_touche >> b.m_coule >> b.m_sizeAttack >> b.m_fusee;

            int c;
            is >> c;
            for(int j(0); j<c; j++)
            {
                std::pair<int, int> temp;
                is >> temp.first >> temp.second;
                b.m_pointsTouches.push_back(temp);
            }
        }
        return is;
    }

protected:

};

#endif /* cuirace_hpp */

