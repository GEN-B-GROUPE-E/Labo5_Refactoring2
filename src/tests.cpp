//Unit tests
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Customer.h"
#include "RegularMovieState.h"
#include "NewReleaseMovieState.h"
#include "ChildrensMovieState.h"
#include "MovieState.h"

TEST(movieState, getAmount)
{
    const MovieState* state1 = RegularMovieState::getInstance();
    const MovieState* state2 = NewReleaseMovieState::getInstance();
    const MovieState* state3 = ChildrensMovieState::getInstance();

    ASSERT_EQ(state1->getAmount(10), 14);
    ASSERT_EQ(state1->getAmount(0), 2);
    ASSERT_EQ(state2->getAmount(6), 18);
    ASSERT_EQ(state2->getAmount(0), 0);
    ASSERT_EQ(state3->getAmount(5), 4.5);
    ASSERT_EQ(state3->getAmount(0), 1.5);
}

TEST(movieState, getPoints)
{
    const MovieState* state1 = RegularMovieState::getInstance();
    const MovieState* state2 = NewReleaseMovieState::getInstance();
    const MovieState* state3 = ChildrensMovieState::getInstance();

    ASSERT_EQ(state1->getPoints(10), 1);
    ASSERT_EQ(state1->getPoints(0), 1);
    ASSERT_EQ(state2->getPoints(6), 2);
    ASSERT_EQ(state2->getPoints(1), 1);
    ASSERT_EQ(state3->getPoints(5), 1);
}



TEST(customer, statement)
{
    Customer customer("Olivier");

    Movie movie1 =  Movie("Karate Kid", RegularMovieState::getInstance());
    Movie movie2 =  Movie("Avengers: Endgame", NewReleaseMovieState::getInstance());
    Movie movie3 =  Movie("Snow White", ChildrensMovieState::getInstance());

    customer.addRental( Rental(  &movie1, 7));
    customer.addRental( Rental( &movie2, 5));
    customer.addRental( Rental( &movie3, 3 ));

    ASSERT_EQ(customer.statement(), "Rental Record for Olivier\n"
        "\tKarate Kid\t9.5\n"
        "\tAvengers: Endgame\t15\n"
        "\tSnow White\t1.5\n"
        "Amount owed is 26\n"
        "You earned 4 frequent renter points");
}

