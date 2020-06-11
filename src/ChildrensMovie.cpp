//
// Created by Ilias on 11.06.2020.
//

#include "ChildrensMovie.h"

double ChildrensMovie::getAmount(int nbRentedDays) const {
    double amount = 1.5;
    if ( nbRentedDays > 3 )
        amount += ( nbRentedDays - 3 ) * 1.5;
    return amount;
}
