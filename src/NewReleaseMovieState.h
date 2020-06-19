//
// Created by Ilias on 11.06.2020.
//

#ifndef GEN_REFACTOR2_NEWRELEASEMOVIE_H
#define GEN_REFACTOR2_NEWRELEASEMOVIE_H

#include "MovieState.h"

class NewReleaseMovieState : public MovieState {
private:
    const static MovieState* instance;

public:
    double getAmount(int nbRentedDays) const override;
    const static MovieState* getInstance();
};


#endif //GEN_REFACTOR2_NEWRELEASEMOVIE_H
