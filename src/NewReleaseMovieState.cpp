//
// Created by Ilias on 11.06.2020.
//

#include "NewReleaseMovieState.h"
#include <iostream>

const MovieState* NewReleaseMovieState::instance = new NewReleaseMovieState();

double NewReleaseMovieState::getAmount(int nbRentedDays) const{
    return  nbRentedDays * 3;
}

const MovieState *NewReleaseMovieState::getInstance() {
    return instance;
}

int NewReleaseMovieState::getPoints(int nbRentedDays) const {
    return MovieState::getPoints(nbRentedDays) + (nbRentedDays >= 2 ? 1 : 0);
}
