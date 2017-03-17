//
//  destroyer.cpp
//  bn
//
//  Created by fabrice locqueville on 09/03/2017.
//  Copyright © 2017 fabrice locqueville. All rights reserved.
//

#include "Destroyer.hpp"


Destroyer::Destroyer()
{
    m_fusee = true;
}
Destroyer::Destroyer(std::pair<int, int> coord, char type, bool vertical): Boat(coord, type, vertical)
{
    m_fusee = true;
}
