/*
  Movie.cpp

  Definition file for Movie class.

  John I. Doe
  jdoe@cs.kent.edu
*/

#include "Movie.hpp"

// constructor
Movie::Movie(const std::string& title, int price_code)
      : title(title), price_code(price_code)
{ }

// movie title
const std::string& Movie::getTitle() const {

  return title;
}

// movie price code
int Movie::getPriceCode() const {

  return price_code;
}

// set movie price code
void Movie::setPriceCode(int new_price_code) {

  price_code = new_price_code;
}

double Movie::getCharge(int daysRented) const {
    double thisAmount = 0;
    switch(getPriceCode()) {

      case Movie::REGULAR:
              thisAmount += 2;
              if (daysRented > 2)
                  thisAmount += (daysRented - 2) * 1.5;
              break;

      case Movie::NEW_RELEASE:
              thisAmount += daysRented * 3;
              break;

      case Movie::CHILDRENS:
              thisAmount += 1.5;
              if (daysRented > 3)
                  thisAmount += (daysRented - 3) * 1.5;
              break;
    }

return thisAmount;

}
