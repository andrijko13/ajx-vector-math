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

BOOST_AUTO_TEST_CASE ( rad2deg )
{
  double radians1 = M_PI;
  double radians2 = M_PI / 2;
  double radians3 = M_PI * 8 / 3;

  BOOST_CHECK ( ajx::approx( ajx::rad2deg(radians1), 180.0 ) );
  BOOST_CHECK ( ajx::approx( ajx::rad2deg(radians2), 90.0 ) );
  BOOST_CHECK ( ajx::approx( ajx::rad2deg(radians3), 480.0 ) );
}

BOOST_AUTO_TEST_CASE ( deg2rad )
{
  double degrees1 = 90;
  double degrees2 = 180;
  double degrees3 = 270;

  BOOST_CHECK ( ajx::approx( ajx::deg2rad(degrees1), M_PI/2.0 ) );
  BOOST_CHECK ( ajx::approx( ajx::deg2rad(degrees2), M_PI ) );
  BOOST_CHECK ( ajx::approx( ajx::deg2rad(degrees3), 3.0/2.0*M_PI ) );
}