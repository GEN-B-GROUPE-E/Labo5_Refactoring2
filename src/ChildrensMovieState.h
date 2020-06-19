//
// Created by Ilias on 11.06.2020.
//

#ifndef GEN_REFACTOR2_CHILDRENSMOVIE_H
#define GEN_REFACTOR2_CHILDRENSMOVIE_H


#include "MovieState.h"

class ChildrensMovieState : public MovieState {
private:
    static MovieState* instance;

public:
    double getAmount(int nbRentedDays) const override;
    static const MovieState* getInstance();
};


#endif //GEN_REFACTOR2_CHILDRENSMOVIE_H
