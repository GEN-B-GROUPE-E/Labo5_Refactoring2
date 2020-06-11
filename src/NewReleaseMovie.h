//
// Created by Ilias on 11.06.2020.
//

#ifndef GEN_REFACTOR2_NEWRELEASEMOVIE_H
#define GEN_REFACTOR2_NEWRELEASEMOVIE_H

#include "Movie.h"

class NewReleaseMovie : public Movie {
    double getAmount(int nbRentedDays) const override;

public:
    NewReleaseMovie( const std::string& title, int priceCode ) : Movie(title, priceCode){}
};

#endif //GEN_REFACTOR2_NEWRELEASEMOVIE_H
