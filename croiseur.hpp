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
protected:
};

#endif /* croiseur_hpp */
