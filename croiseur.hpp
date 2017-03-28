//
//  croiseur.hpp
//  bn
//
//  Created by fabrice locqueville on 09/03/2017.
//  Copyright © 2017 fabrice locqueville. All rights reserved.
//

#ifndef croiseur_hpp
#define croiseur_hpp

#include "Boat.hpp"

class Croiseur: public Boat
{
public:
    Croiseur();
    Croiseur(std::pair<int, int> coord, char type, bool vertical);

friend std::istream& operator>>(std::istream& is, Croiseur &b)
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

#endif /* croiseur_hpp */
