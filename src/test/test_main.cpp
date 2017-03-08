#define BOOST_TEST_DYN_LINK

#define BOOST_TEST_MODULE "Main Test Module"
#include <boost/test/unit_test.hpp>

#include "vec2d.h"
#include <iostream>

BOOST_AUTO_TEST_CASE( constructors )
{
	ajx::vec2d<int> vec1;
	ajx::vec2d<int> vec2;
	ajx::vec2d<long long> vec3;
	ajx::vec2d<double> vec4;

  BOOST_CHECK(vec1.x() == vec2.x());
  BOOST_CHECK(vec2.x() == vec3.x());
  BOOST_CHECK(vec1.y() == vec2.y());
  BOOST_CHECK(vec2.y() == vec3.y());

  BOOST_CHECK(vec4.x() < ajx::epsilon);
  BOOST_CHECK(vec4.y() < ajx::epsilon);
}


BOOST_AUTO_TEST_CASE( assignment )
{
  ajx::vec2d<int> vec1(5,-10);
  ajx::vec2d<int> vec2 = vec1;


  BOOST_CHECK_EQUAL(vec2.x(), 5);
  BOOST_CHECK_EQUAL(vec2.y(), -10);
}
