//
// Created by Ilias on 11.06.2020.
//

#include "RegularMovie.h"


double RegularMovie::getAmount(int nbRentedDays) const {
    double amount = 2;
    if ( nbRentedDays > 2 )
        amount += ( nbRentedDays - 2 ) * 1.5 ;
    return amount;
}
