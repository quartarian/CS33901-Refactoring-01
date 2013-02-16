/*
  Rental.cpp

  Definition file for Rental class.

  John I. Doe
  jdoe@cs.kent.edu
*/

#include "Rental.hpp"

// constructor
Rental::Rental(const Movie& movie, int days_rented)
      : movie(movie), days(days_rented)
{ }

// days rented
int Rental::getDaysRented() const {

  return days;
}

// movie rented
const Movie& Rental::getMovie() const {

  return movie;
}

double Rental::getCharge() const {
	return movie.getCharge(days);
}

int Rental::getFrequentRenterPoints(int& frequentRenterPoints, std::vector<Rental>::const_iterator& it) const {
	// every rental is a rental point
	++frequentRenterPoints;
	// new releases rented for more then one day gives a bonus rental point
	if (it->getMovie().getPriceCode() == Movie::NEW_RELEASE && it->getDaysRented() > 1)
		++frequentRenterPoints;
	return frequentRenterPoints;
}
