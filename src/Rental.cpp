//
// Created by Robin Reuteler on 2020-06-19.
//

#include "Movie.h"
#include "Rental.h"

Rental::Rental( const Movie* movie, int daysRented )
        : _movie(const_cast<Movie *>(movie))
        , _daysRented( daysRented ) {}

int Rental::getDaysRented() const { return _daysRented; }

const Movie* Rental::getMovie() const { return _movie; }

double Rental::getAmount() const {return _movie->getAmount(_daysRented);}