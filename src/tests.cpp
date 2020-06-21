//Unit tests
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Customer.h"
#include "NewReleaseMovieState.h"
#include "ChildrensMovieState.h"
#include "RentalMock.h"

using ::testing::Return;

TEST(customer, getTotalAmount){

    MovieMock movie("OSS 117");

    RentalMock rent1(&movie, 1);
    RentalMock rent2(&movie, 2);
    RentalMock rent3(&movie, 3);

    EXPECT_CALL(rent1, getAmount()).WillRepeatedly(Return(42));
    EXPECT_CALL(rent2, getAmount()).WillRepeatedly(Return(11));
    EXPECT_CALL(rent3, getAmount()).WillRepeatedly(Return(12));

    Customer customer("Hubert");

    customer.addRental(&rent1);
    customer.addRental(&rent2);
    customer.addRental(&rent3);

    ASSERT_EQ(customer.getTotalAmount(), 55);
}
TEST(customer, getTotalPoints){
    MovieMock movie("OSS 117");

    RentalMock rent1(&movie, 1);
    RentalMock rent2(&movie, 2);
    RentalMock rent3(&movie, 3);

    EXPECT_CALL(rent1, getPoints()).WillRepeatedly(Return(2));
    EXPECT_CALL(rent2, getPoints()).WillRepeatedly(Return(5));
    EXPECT_CALL(rent3, getPoints()).WillRepeatedly(Return(1));

    Customer customer("Hubert");
    customer.addRental(&rent1);
    customer.addRental(&rent2);
    customer.addRental(&rent3);

    ASSERT_EQ(customer.getTotalPoints(), 8);
}
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
    Rental rent1 = Rental(  &movie1, 7);
    Rental rent2 = Rental( &movie2, 5);
    Rental rent3 = Rental( &movie3, 3 );
    customer.addRental( &rent1);
    customer.addRental( &rent2);
    customer.addRental( &rent3);

    ASSERT_EQ(customer.statement(), "Rental Record for Olivier\n"
        "\tKarate Kid\t9.5\n"
        "\tAvengers: Endgame\t15\n"
        "\tSnow White\t1.5\n"
        "Amount owed is 26\n"
        "You earned 4 frequent renter points");
}

