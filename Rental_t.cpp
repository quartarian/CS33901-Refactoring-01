
/*
Rental_t.cpp

Test program for class Rental

John I. Doe
jdoe@cs.kent.edu
*/

#include <cassert>
#include "Rental.hpp"

int main() {

Movie regular("Regular movie", Movie::REGULAR);
Movie newRelease("New release", Movie::NEW_RELEASE);
Movie children("Children's Movie", Movie::CHILDRENS);

	// Test Constructor & Correct Movie Pointer
	{
		// Create rentals of these movies
		Rental r1(regular, 10);
		assert("Regular movie" == r1.getMovie().getTitle());
	}

	// Test Days
	{
		// Create rentals of these movies
		Rental r1(regular, 10);
		assert(r1.getDaysRented() == 10);
	}

	// Test getCharge
	{
		// Create rentals of each type
		Rental r1(regular, 10); 	// Regular price code.
		Rental r2(newRelease, 12);	// New Release price code.
		Rental r3(children, 15);	// Children price code.

		// Test logic of getCharge() function
		assert(r1.getCharge() ==  (2 + (r1.getDaysRented() - 2) * 1.5));
		assert(r2.getCharge() == (r2.getDaysRented() * 3));
		assert(r3.getCharge() ==  (1.5 + (r3.getDaysRented() - 3) * 1.5));

	}

  return 0;
}
