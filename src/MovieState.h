//
// Created by Robin Reuteler on 2020-06-19.
//

#ifndef GEN_REFACTOR2_MOVIESTATE_H
#define GEN_REFACTOR2_MOVIESTATE_H


class MovieState {

public:
    virtual double getAmount(int nbRentedDays) const = 0;
    virtual int getPoints(int nbRentedDays) const
    {
        return 1;
    }
};


#endif //GEN_REFACTOR2_MOVIESTATE_H
