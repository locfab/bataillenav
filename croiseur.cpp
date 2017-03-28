//
//  croiseur.cpp
//  bn
//
//  Created by fabrice locqueville on 09/03/2017.
//  Copyright © 2017 fabrice locqueville. All rights reserved.
//

#include "Croiseur.hpp"

Croiseur::Croiseur()
{

}
Croiseur::Croiseur(std::pair<int, int> coord, char type, bool vertical): Boat(coord, type, vertical)
{
}
