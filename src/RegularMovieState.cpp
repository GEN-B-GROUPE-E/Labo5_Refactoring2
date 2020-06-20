//
// Created by Ilias on 11.06.2020.
//

#include "RegularMovieState.h"

const MovieState* RegularMovieState::instance = new RegularMovieState();

double RegularMovieState::getAmount(int nbRentedDays) const {
    double amount = 2;
    if ( nbRentedDays > 2 )
        amount += ( nbRentedDays - 2 ) * 1.5 ;
    return amount;
}

const MovieState* RegularMovieState::getInstance() {
    return instance;
}
