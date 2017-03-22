//
//  sousMarin.hpp
//  bn
//
//  Created by fabrice locqueville on 09/03/2017.
//  Copyright © 2017 fabrice locqueville. All rights reserved.
//

#ifndef sousMarin_hpp
#define sousMarin_hpp

#include "Boat.hpp"

class SousMarin: public Boat
{
public:
    SousMarin();
    SousMarin(std::pair<int, int> coord, char type, bool vertical);
    void attaque(std::pair<int, int> coord, std::vector<Boat*> vectBoatAdvers);
protected:
};

#endif /* sousMarin_hpp */
