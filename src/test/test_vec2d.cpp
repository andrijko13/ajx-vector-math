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
  ajx::vec2d<int> vec5(10, 20);

  BOOST_CHECK(vec1.x() == vec2.x());
  BOOST_CHECK(vec2.x() == vec3.x());
  BOOST_CHECK(vec1.y() == vec2.y());
  BOOST_CHECK(vec2.y() == vec3.y());
  BOOST_CHECK(vec1.x() == 0);
  BOOST_CHECK(vec1.y() == 0);

  BOOST_CHECK(vec4.x() < ajx::epsilon);
  BOOST_CHECK(vec4.y() < ajx::epsilon);

  BOOST_CHECK(vec5.x() == 10);
  BOOST_CHECK(vec5.y() == 20);
}


BOOST_AUTO_TEST_CASE( assignment )
{
  ajx::vec2d<int> vec1(5,-10);
  ajx::vec2d<int> vec2 = vec1;


  BOOST_CHECK_EQUAL(vec2.x(), 5);
  BOOST_CHECK_EQUAL(vec2.y(), -10);
}

BOOST_AUTO_TEST_CASE( zero_vector )
{
  ajx::vec2d<int> zero = ajx::vec2d<int>::ZeroVector();
  ajx::vec2d<double> zero2 = ajx::vec2d<double>::ZeroVector();

  BOOST_CHECK(zero.x() == 0);
  BOOST_CHECK(zero.y() == 0);

  BOOST_CHECK(zero2.x() < ajx::epsilon);
  BOOST_CHECK(zero2.y() < ajx::epsilon);
}

BOOST_AUTO_TEST_CASE( VectorWith )
{
  ajx::vec2d<int> vec1 = ajx::vec2d<int>::VectorWith(5, 10);
  ajx::vec2d<int> vec2(10,20);

  BOOST_CHECK(vec1.x() == 5);
  BOOST_CHECK(vec1.y() == 10);

  BOOST_CHECK(vec2.x() == ajx::vec2d<int>::VectorWith(10,10).x());
  BOOST_CHECK(vec2.y() == ajx::vec2d<int>::VectorWith(10,20).y());
}

BOOST_AUTO_TEST_CASE( less_than )
{
  ajx::vec2d<int> first(3,4); // distance 5
  ajx::vec2d<int> second(4,3); // distance 5
  ajx::vec2d<int> third(5,6); // distance > 5

  ajx::vec2d<double> firstd(3.1,4.1);
  ajx::vec2d<double> secondd(3.1, 4.1);
  ajx::vec2d<double> thirdd(3.1001, 4.1001);

  BOOST_CHECK(!(first < second));
  BOOST_CHECK(first < third);
  BOOST_CHECK(second < third);

  BOOST_CHECK(!(firstd < secondd));
  BOOST_CHECK(firstd < thirdd);
  BOOST_CHECK(secondd < thirdd);
}

BOOST_AUTO_TEST_CASE ( equality )
{
  ajx::vec2d<int> first(100,200);
  ajx::vec2d<int> second(200,100);
  ajx::vec2d<int> third(200,100);

  BOOST_CHECK(!(first == second));
  BOOST_CHECK(first != second);
  BOOST_CHECK(second == third);
}

BOOST_AUTO_TEST_CASE ( plus_equals )
{
  ajx::vec2d<int> first(1,1);
  first += ajx::vec2d<int>::VectorWith(2,2);
  ajx::vec2d<int> second(3,3);
  second += first;

  BOOST_CHECK(first.x() == 3);
  BOOST_CHECK(first.y() == 3);
  BOOST_CHECK(second.x() == 6);
  BOOST_CHECK(second.y() == 6);
}

BOOST_AUTO_TEST_CASE( minus_equals )
{
  ajx::vec2d<int> first(4,4);
  ajx::vec2d<int> second(5,5);
  second -= first;
  first -= ajx::vec2d<int>::VectorWith(2,2);

  BOOST_CHECK(first.x() == 2);
  BOOST_CHECK(first.y() == 2);
  BOOST_CHECK(second.x() == 1);
  BOOST_CHECK(second.y() == 1);
}

BOOST_AUTO_TEST_CASE ( times_equals )
{
  ajx::vec2d<int> first(4,5);
  ajx::vec2d<int> second(-3, 7);
  ajx::vec2d<int> third(1,1);

  first *= second;
  second *= third;

  BOOST_CHECK(first.x() == -12);
  BOOST_CHECK(first.y() == 35);
  BOOST_CHECK(second.x() == -3);
  BOOST_CHECK(second.y() == 7);
}