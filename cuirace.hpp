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
protected:
    
};

#endif /* cuirace_hpp */

