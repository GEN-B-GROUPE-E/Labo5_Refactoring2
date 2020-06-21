#ifndef GEN_REFACTOR2_MOVIEMOCK_H
#define GEN_REFACTOR2_MOVIEMOCK_H
#include "gmock/gmock.h"
#include "Movie.h"

class MovieMock : public Movie{
public:
    MovieMock(const std::string& title) : Movie(title){}
    MOCK_METHOD(double, getAmount, (), (const));
    MOCK_METHOD(int, getPoints, (), (const));
};

#endif //GEN_REFACTOR2_MOVIEMOCK_H
