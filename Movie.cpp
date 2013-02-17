/*
  Movie.cpp

  Definition file for Movie class.

  John I. Doe
  jdoe@cs.kent.edu
*/

#include "Movie.hpp"

// constructor
Movie::Movie(const std::string& title, int price_code) {
      this->title = title;
      this->setPriceCode(price_code);
}

// movie title
const std::string& Movie::getTitle() const {

  return title;
}

// movie price code
int Movie::getPriceCode() const {
  return price_code->getPriceCode();
}

// set movie price code
void Movie::setPriceCode(int new_price_code) {
	switch (new_price_code) {
		case Movie::REGULAR:
			this->price_code = new RegularPrice;
			break;

		case Movie::NEW_RELEASE:
			this->price_code = new NewReleasePrice;
			break;

		case Movie::CHILDRENS:
			this->price_code = new ChildrensPrice;
			break;

	}
  //price_code = new Price;
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

const int RegularPrice::getPriceCode() {
	return Movie::REGULAR;
}

const int ChildrensPrice::getPriceCode() {
	return Movie::CHILDRENS;
}

const int NewReleasePrice::getPriceCode() {
	return Movie::NEW_RELEASE;
}

