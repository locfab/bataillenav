//
//  Partie.hpp
//  bn
//
//  Created by fabrice locqueville on 08/03/2017.
//  Copyright © 2017 fabrice locqueville. All rights reserved.
//

#ifndef Partie_hpp
#define Partie_hpp

#include <iostream>
#include <vector>
#include "Player.hpp"
#include <fstream>


class Partie
{
public:
    Partie();
    ~Partie();

    void sauvegarde();
    void getInfoSauv();
    void aide();
    bool victoire(Player &p);
    bool boucleDeJeu(bool begin);
    void aleaGrill1();
    friend std::ostream& operator<<(std::ostream& os, const Partie& p)
       {
           os << p.m_ordi << '\n';
           os << p.m_user;
           return os;
       }

        friend std::istream& operator>>(std::istream& is, Partie& p)
        {
            is >> p.m_ordi;
            is >> p.m_user;
            return is;
        }

protected:

    Player m_ordi;
    Player m_user;
};

#endif /* Partie_hpp */
