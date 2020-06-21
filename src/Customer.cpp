// Customer.cpp
#include <sstream>
#include <vector>
#include <iostream>
#include "Customer.h"
#include "NewReleaseMovieState.h"

using std::ostringstream;
using std::vector;

using namespace std;

string Customer::statement(){
    ostringstream result;
    result << "Rental Record for " << getName() << "\n";
    for(auto each: _rentals){
        result << "\t" << each->getMovieTitle() << "\t"
               << each->getAmount() << "\n";
    }

    // add footer lines
    result << "Amount owed is " << getTotalAmount() << "\n";
    result << "You earned " << getTotalPoints()
           << " frequent renter points";
    return result.str();
}

double Customer::getTotalAmount() const {
    double totalAmount = 0;
    for (auto each : _rentals) {
        totalAmount += each->getAmount();
    }
    return totalAmount;
}

int Customer::getTotalPoints() const {
    int frequentRenterPoints =0;
    for (auto each : _rentals) {
        frequentRenterPoints += each->getPoints();
    }
    return frequentRenterPoints;
}
