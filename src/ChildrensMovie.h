//
// Created by Ilias on 11.06.2020.
//

#ifndef GEN_REFACTOR2_CHILDRENSMOVIE_H
#define GEN_REFACTOR2_CHILDRENSMOVIE_H


#include "Movie.h"

class ChildrensMovie : public Movie {
    double getAmount(int nbRentedDays) const override;

public:
    ChildrensMovie( const std::string& title, int priceCode ) : Movie(title, priceCode){}
};


#endif //GEN_REFACTOR2_CHILDRENSMOVIE_H
