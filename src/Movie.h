// Movie.h
#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include "MovieState.h"
#include "RegularMovieState.h"

class Movie {
public:

    Movie( const std::string& title, const MovieState* priceCode = RegularMovieState::getInstance() );

    const MovieState* getPriceCode() const;
    void setState(MovieState*);
    std::string getTitle() const;
    double getAmount(int nbRentedDays) const
    {
        return _priceCode->getAmount(nbRentedDays);
    }

    int getPoints(int nbRentedDays) const
    {
        return _priceCode->getPoints(nbRentedDays);
    }

private:
    std::string _title;
    const MovieState* _priceCode;
};

inline Movie::
Movie( const std::string& title, const MovieState* priceCode )
        : _title( title )
        , _priceCode( priceCode )
{}

inline const MovieState* Movie::
getPriceCode() const { return _priceCode; }

inline void Movie::
setState(MovieState* movieState) { _priceCode =  movieState;}

inline std::string Movie::
getTitle() const { return _title; }



#endif // MOVIE_H