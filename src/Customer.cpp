// Customer.cpp
#include <sstream>
#include <vector>
#include "Customer.h"

using std::ostringstream;
using std::vector;

using namespace std;

string Customer::statement()
{
    double totalAmount = 0;
    int frequentRenterPoints = 0;

    ostringstream result;
    result << "Rental Record for " << getName() << "\n";

    for (auto each : _rentals) {
        double thisAmount = each.getMovie()->getAmount(each.getDaysRented());

        // add frequent renter points
        frequentRenterPoints++;
        // add bonus for a two day new release rental
        if ( (( each.getMovie())->getPriceCode() == Movie::NEW_RELEASE )
             && each.getDaysRented() > 1 ) frequentRenterPoints++;

        // show figures for this rental
        result << "\t" << each.getMovie()->getTitle() << "\t"
               << thisAmount << "\n";
        totalAmount += thisAmount; // TODO va proablement disparaitre
    }
    // add footer lines
    result << "Amount owed is " << totalAmount << "\n";
    result << "You earned " << frequentRenterPoints
           << " frequent renter points";
    return result.str();
}