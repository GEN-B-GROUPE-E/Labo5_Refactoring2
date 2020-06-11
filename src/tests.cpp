//Unit tests
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Customer.h"
#include "RegularMovie.h"
#include "NewReleaseMovie.h"
#include "ChildrensMovie.h"


TEST(customer, statement)
{
    Customer customer("Olivier");

    RegularMovie movie1 =  RegularMovie("Karate Kid", Movie::REGULAR);
    NewReleaseMovie movie2 =  NewReleaseMovie("Avengers: Endgame", Movie::NEW_RELEASE);
    ChildrensMovie movie3 =  ChildrensMovie("Snow White", Movie::CHILDRENS);

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

