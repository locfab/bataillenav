//
//  destroyer.hpp
//  bn
//
//  Created by fabrice locqueville on 09/03/2017.
//  Copyright © 2017 fabrice locqueville. All rights reserved.
//

#ifndef destroyer_hpp
#define destroyer_hpp

#include "Boat.hpp"
#include "Console.hpp"

class Destroyer: public Boat
{
public:
    Destroyer();
    Destroyer(std::pair<int, int> coord, char type, bool vertical);
    void printBoat();
    Console* pConsole = NULL;

    friend std::istream& operator>>(std::istream& is, Destroyer &b)
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


friend std::ostream& operator<<(std::ostream& os, const std::vector<Destroyer*> &b)
{
    os << b.size() << std::endl;
    for(int i=0;i<b.size();i++)
    {
        os << b[i]->m_coord.first << " " << b[i]->m_coord.second << " " << b[i]->m_type << " " << b[i]->m_vertical << " " << b[i]->m_touche;
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

protected:


};

#endif /* destroyer_hpp */
