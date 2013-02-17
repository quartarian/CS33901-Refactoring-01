/*
  Movie.hpp

  Include file for Movie class.

  John I. Doe
  jdoe@cs.kent.edu
*/

#ifndef MOVIE_H
#define MOVIE_H

#include <string>

class Price {
public:
	virtual const int getPriceCode() = 0;
};
class RegularPrice: public Price {
public:
	const int  getPriceCode();
};
class ChildrensPrice: public Price {
public:
	const int  getPriceCode();
};
class NewReleasePrice: public Price {
public:
	const int  getPriceCode();
};


class Movie {
public:

  static const int REGULAR      = 0;
  static const int NEW_RELEASE  = 1;
  static const int CHILDRENS    = 2;

  // constructor
  Movie(const std::string& title, int price_code);

  // movie title
  const std::string& getTitle() const;

  // movie price code
  int getPriceCode() const;

  // set movie price code
  void setPriceCode(int new_price_code);

  double getCharge(int daysRented) const;
    
private:

  std::string title;
  Price*      price_code;
};

#endif
