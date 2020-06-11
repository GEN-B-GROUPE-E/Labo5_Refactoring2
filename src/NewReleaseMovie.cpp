//
// Created by Ilias on 11.06.2020.
//

#include "NewReleaseMovie.h"
double NewReleaseMovie::getAmount(int nbRentedDays) const{
    return  nbRentedDays * 3;
}