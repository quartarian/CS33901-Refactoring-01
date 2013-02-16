/*
  Customer.hpp

  Include file for Customer class.

  John I. Doe
  jdoe@cs.kent.edu
*/

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Rental.hpp"

#include <string>
#include <vector>

class Customer {

public:

  // constructor
  Customer(const std::string& name);

  // customer name
  std::string getName() const;

  // add a new rental
  void addRental(const Rental& rental);

  double getTotalCharge(std::vector<Rental>::const_iterator& it) const;

  // customer rental statement
  std::string statement() const;
  void getFrequentRenterPoints(int& frequentRenterPoints,
			std::vector<Rental>::const_iterator& it) const;

private:

  std::string         name;
  std::vector<Rental> rentals;
};

#endif
