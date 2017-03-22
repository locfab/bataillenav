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
    void sauvegarde(Player &ordi, Player &user);
    void getInfoSauv(Player $ordi, Player $user);
    bool victoire(Player &p);
    bool boucleDeJeu(bool begin);

protected:
    Player m_ordi;
    Player m_user;
};

#endif /* Partie_hpp */
