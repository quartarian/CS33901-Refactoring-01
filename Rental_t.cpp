/*
  Rental_t.cpp

  Test program for class Rental

  John I. Doe
  jdoe@cs.kent.edu
*/

#include <cassert>

#include "Rental.hpp"

int main() {

	Movie movie("Test Movie", Movie::CHILDRENS);

	// Test Constructor & Correct Movie Pointer
	{
		// Create rentals of these movies
		Rental r1(movie, 10);
		assert("Test Movie" == r1.getMovie().getTitle());
	}

	// Test Days
	{
		// Create rentals of these movies
		Rental r1(movie, 10);
		assert(r1.getDaysRented() == 10);
	}

  return 0;
}
