/*
  Customer.cpp

  Definition file for Customer class.

  John I. Doe
  jdoe@cs.kent.edu
*/

#include "Customer.hpp"
#include "Movie.hpp"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// constructor
Customer::Customer(const std::string& name)
    : name(name)
{ }

// customer name
std::string Customer::getName() const {

  return name;
}

// add a rental to this customer
void Customer::addRental(const Rental& rental) {

  rentals.push_back(rental);
}


// customer rental statement
std::string Customer::statement() const {

  // customer name
  std::string result("Rental Record for ");
  result += getName();
  result += "\n";

  // rentals
  double totalAmount          = 0;
  int    frequentRenterPoints = 0;
  for (std::vector<Rental>::const_iterator it = rentals.begin();
       it != rentals.end(); ++it) {

      // every rental is a rental point
  	frequentRenterPoints = it->getFrequentRenterPoints(frequentRenterPoints, it);
       
      // title of rental
      result += "\t";
      result += it->getMovie().getTitle();
      result += "\t";

      // amount of rental
      std::ostringstream out_str_stream;
      out_str_stream << it->getCharge();
      result += out_str_stream.str();
      result += "\n";

      totalAmount += it->getCharge();
  }

  // total amount owed
  result += "Amount owed is: ";
  std::ostringstream out_str_stream;
  out_str_stream << totalAmount;
  result += out_str_stream.str();
  result += "\n";

  // frequent renter points earned
  result += "You earned: ";
  std::ostringstream out_str_stream2;
  out_str_stream2 << frequentRenterPoints;
  result += out_str_stream2.str();
  result += " frequent renter points\n";

  return result;
}
