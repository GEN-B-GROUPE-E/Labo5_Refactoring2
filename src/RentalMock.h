#ifndef GEN_REFACTOR2_RENTALMOCK_H
#define GEN_REFACTOR2_RENTALMOCK_H

#include "Rental.h"
#include "gmock/gmock.h"
#include "MovieMock.h"

class RentalMock : public Rental{
public:
    RentalMock(Movie* movie, int nbDays) : Rental(movie,nbDays) {}
    MOCK_METHOD(double, getAmount, (), (const));
    MOCK_METHOD(int, getPoints, (), (const));
};

#endif //GEN_REFACTOR2_RENTALMOCK_H
