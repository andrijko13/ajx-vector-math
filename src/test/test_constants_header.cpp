#define BOOST_TEST_DYN_LINK

#define BOOST_TEST_MODULE "Constants Test Module"
#include <boost/test/unit_test.hpp>

#include "constants.h"
#include <iostream>

BOOST_AUTO_TEST_CASE ( approx )
{
  int x = 5;
  int y = 5;

  double a = 2.091241;
  double b = 2.091242;
  double c = 2.100000;

  BOOST_CHECK (ajx::approx(x,y));
  BOOST_CHECK (ajx::approx(a,b));
  BOOST_CHECK (!ajx::approx(b,c));
}