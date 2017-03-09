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

class Destroyer: public Boat
{
public:
    Destroyer();
    Destroyer(std::pair<int, int> coord, char type, bool vertical);
protected:

    
};

#endif /* destroyer_hpp */
