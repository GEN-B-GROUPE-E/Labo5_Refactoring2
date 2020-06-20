//
// Created by Ilias on 11.06.2020.
//

#ifndef GEN_REFACTOR2_REGULARMOVIE_H
#define GEN_REFACTOR2_REGULARMOVIE_H


#include "MovieState.h"

class RegularMovieState : public MovieState {
private:
    static const MovieState* instance;

public:
    double getAmount(int nbRentedDays) const override ;
    static const MovieState* getInstance();
};

#endif //GEN_REFACTOR2_REGULARMOVIE_H
