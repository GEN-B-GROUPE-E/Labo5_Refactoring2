// Customer.cpp
#include <sstream>
#include <vector>
#include <iostream>
#include "Customer.h"
#include "NewReleaseMovieState.h"

using std::ostringstream;
using std::vector;

using namespace std;

string Customer::statement()
{
    //TODO : Faudrait-il tranformer totalAmount et frequentRenterPoints en attributs ?
    double totalAmount = 0;
    int frequentRenterPoints = 0;

    ostringstream result;
    result << "Rental Record for " << getName() << "\n";

    for (auto each : _rentals) {
        double thisAmount = each.getAmount();

        frequentRenterPoints += each.getPoints();

        // show figures for this rental
        result << "\t" << each.getMovieTitle() << "\t"
               << thisAmount << "\n";
        totalAmount += thisAmount; // TODO va proablement disparaitre
    }
    // add footer lines
    result << "Amount owed is " << totalAmount << "\n";
    result << "You earned " << frequentRenterPoints
           << " frequent renter points";
    return result.str();
}