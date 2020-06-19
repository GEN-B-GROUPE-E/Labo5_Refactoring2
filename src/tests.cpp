//Unit tests
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Customer.h"
#include "RegularMovieState.h"
#include "NewReleaseMovieState.h"
#include "ChildrensMovieState.h"


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

