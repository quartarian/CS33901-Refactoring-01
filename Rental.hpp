/*
  Rental.hpp

  Include file for Rental class.

  John I. Doe
  jdoe@cs.kent.edu
*/

#ifndef RENTAL_H
#define RENTAL_H

#include "Movie.hpp"

class Rental {

public:

  // constructor
  Rental(const Movie& movie, int days_rented);

  // days rented
  int getDaysRented() const;

  // movie rented
  const Movie& getMovie() const;

  double getCharge() const;
  
  int getFrequentRenterPoints(int& frequentRenterPoints, std::vector<Rental>::const_iterator& it) const;


private:

  Movie movie;
  int days;
};

#endif
