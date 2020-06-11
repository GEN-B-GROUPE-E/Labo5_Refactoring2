//
// Created by Ilias on 11.06.2020.
//

#ifndef GEN_REFACTOR2_REGULARMOVIE_H
#define GEN_REFACTOR2_REGULARMOVIE_H


#include "Movie.h"

class RegularMovie : public Movie {
    double getAmount(int nbRentedDays) const override ;

public:
    RegularMovie( const std::string& title, int priceCode ) : Movie(title, priceCode){}
};

#endif //GEN_REFACTOR2_REGULARMOVIE_H
