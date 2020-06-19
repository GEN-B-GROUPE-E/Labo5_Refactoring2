//
// Created by Ilias on 11.06.2020.
//

#include "NewReleaseMovieState.h"
const MovieState* NewReleaseMovieState::instance = new NewReleaseMovieState();

double NewReleaseMovieState::getAmount(int nbRentedDays) const{
    return  nbRentedDays * 3;
}

const MovieState *NewReleaseMovieState::getInstance() {
    return instance;
}
