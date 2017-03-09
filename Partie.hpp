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


class Partie
{
public:
    Partie();
protected:
    Player ordi;
    Player user;
};

#endif /* Partie_hpp */
