//
//  sousMarin.cpp
//  bn
//
//  Created by fabrice locqueville on 09/03/2017.
//  Copyright © 2017 fabrice locqueville. All rights reserved.
//

#include "SousMarin.hpp"

SousMarin::SousMarin()
{

}
SousMarin::SousMarin(std::pair<int, int> coord, char type, bool vertical):Boat(coord, type, vertical)
{
}

void SousMarin::attaque(std::pair<int, int> coord, std::vector<Boat*> vectBoatAdvers)
{
    for(int j(0); j< vectBoatAdvers.size(); j++)
    {
        if(vectBoatAdvers[j]->getType() == 's')
        {
            if(vectBoatAdvers[j]->getVertical() )
            {
                int deb = vectBoatAdvers[j]->getCoord().first - vectBoatAdvers[j]->envergure();
                int fin = vectBoatAdvers[j]->getCoord().first + vectBoatAdvers[j]->envergure();
                for(int k(deb); k<fin+1; k++)
                {
                    if(coord.first == k && coord.second == vectBoatAdvers[j]->getCoord().second)
                    {
                        bool present(false);
                        for(int l(0); l < vectBoatAdvers[j]->getPointsTouches().size(); l++)
                        {
                            if(vectBoatAdvers[j]->getPointsTouches()[l] == coord)
                            {
                                present = true;
                                break;
                            }
                        }
                        if(!present)
                        {
                            vectBoatAdvers[j]->setTouche();
                            vectBoatAdvers[j]->setPointsTouches(coord);
                            vectBoatAdvers[j]->setCoule();
                        }
                        return;
                    }

                }
            }
            else
            {
                int deb = vectBoatAdvers[j]->getCoord().second - vectBoatAdvers[j]->envergure();
                int fin = vectBoatAdvers[j]->getCoord().second + vectBoatAdvers[j]->envergure();
                for(int k(deb); k<fin+1; k++)
                {
                    if(coord.first == vectBoatAdvers[j]->getCoord().first && k == coord.second)
                    {
                        bool present(false);
                        for(int l(0); l < vectBoatAdvers[j]->getPointsTouches().size(); l++)
                        {
                            if(vectBoatAdvers[j]->getPointsTouches()[l] == coord)
                            {
                                present = true;
                                break;
                            }
                        }
                        if(!present)
                        {
                            vectBoatAdvers[j]->setTouche();
                            vectBoatAdvers[j]->setPointsTouches(coord);
                            vectBoatAdvers[j]->setCoule();
                        }
                        return;
                    }
                }
            }
        }
    }
}
