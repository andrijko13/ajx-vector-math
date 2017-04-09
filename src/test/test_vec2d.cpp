#define BOOST_TEST_DYN_LINK

#define BOOST_TEST_MODULE "Vec2D Test Module"
#include <boost/test/unit_test.hpp>

#include "vec2d.h"
#include <cmath>
#include <iostream>

BOOST_AUTO_TEST_CASE( constructors_and_getters )
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

BOOST_AUTO_TEST_CASE ( divide_equals )
{
  ajx::vec2d<int> first(20,-20);
  first /= ajx::vec2d<int>::VectorWith(5,5);

  BOOST_CHECK(first.x() == 4);
  BOOST_CHECK(first.y() == -4);
}

BOOST_AUTO_TEST_CASE( modulus_equals )
{
  ajx::vec2d<int> first(20,-20);
  first %= ajx::vec2d<int>::VectorWith(5,3);

  BOOST_CHECK(first.x() == 0);
  BOOST_CHECK(first.y() == -2);
}

BOOST_AUTO_TEST_CASE( or_equals )
{
  ajx::vec2d<int> first(0,0);
  first |= ajx::vec2d<int>::VectorWith(10,-10);

  BOOST_CHECK(first.x() == 10);
  BOOST_CHECK(first.y() == -10);
}

BOOST_AUTO_TEST_CASE( and_equals )
{
  ajx::vec2d<int> first(0xFFFFFFFF,0xFFFFFFFF);
  first &= ajx::vec2d<int>::VectorWith(0,1);

  BOOST_CHECK(first.x() == 0);
  BOOST_CHECK(first.y() == 1);
}

BOOST_AUTO_TEST_CASE( xor_equals )
{
  ajx::vec2d<int> first(20,-20);
  first ^= ajx::vec2d<int>::VectorWith(-73,98);
  first ^= ajx::vec2d<int>::VectorWith(-73,98);


  BOOST_CHECK(first.x() == 20);
  BOOST_CHECK(first.y() == -20);
}

BOOST_AUTO_TEST_CASE( plusplus )
{
  ajx::vec2d<int> first(0,-1);
  first++;

  BOOST_CHECK(first.x() == 1);
  BOOST_CHECK(first.y() == 0);
}

BOOST_AUTO_TEST_CASE( minusminus )
{
  ajx::vec2d<int> first(0,-1);
  first--;

  BOOST_CHECK(first.x() == -1);
  BOOST_CHECK(first.y() == -2);
}

BOOST_AUTO_TEST_CASE( times_const )
{
  ajx::vec2d<int> first(33,-11);
  ajx::vec2d<int> result1 = first * 2;
  ajx::vec2d<int> result2 = -2 * first;

  BOOST_CHECK(result1.x() == 66);
  BOOST_CHECK(result1.y() == -22);

  BOOST_CHECK(result2.x() == -66);
  BOOST_CHECK(result2.y() == 22);

  result1 *= -1;
  BOOST_CHECK(result1 == result2);
}

BOOST_AUTO_TEST_CASE( divides_const )
{
  ajx::vec2d<int> first(33,-11);
  ajx::vec2d<int> result1 = first / 11;

  BOOST_CHECK(result1.x() == 3);
  BOOST_CHECK(result1.y() == -1);

  result1 /= -1;
  BOOST_CHECK(result1.x() == -3);
  BOOST_CHECK(result1.y() == 1);
}

BOOST_AUTO_TEST_CASE ( dot )
{
  ajx::vec2d<int> first(10,10);
  ajx::vec2d<int> second(20,20);
  int result = first.dot(second);

  BOOST_CHECK(result == 400);
}

BOOST_AUTO_TEST_CASE ( cross )
{
  ajx::vec2d<int> first(10,10);
  ajx::vec2d<int> second(10,20);
  int result = first.cross(second);

  BOOST_CHECK(result == 100);
}

BOOST_AUTO_TEST_CASE ( length )
{
  ajx::vec2d<int> first(0,-10);
  ajx::vec2d<int> second(3,4);

  BOOST_CHECK(first.length() == 10);
  BOOST_CHECK(second.length() == 5);
}

BOOST_AUTO_TEST_CASE ( length_square )
{
  ajx::vec2d<int> first(0,-10);
  ajx::vec2d<int> second(3,4);

  BOOST_CHECK(first.lengthSquared() == 100);
  BOOST_CHECK(second.lengthSquared() == 25);
}

BOOST_AUTO_TEST_CASE ( normalized )
{
  ajx::vec2d<int> first(0,-10);
  ajx::vec2d<double> second(-4,4);

  first = first.normalized();
  second = second.normalized();

  BOOST_CHECK(first.x() == 0);
  BOOST_CHECK(first.y() == -1);

  BOOST_CHECK(ajx::approx(second.x(), -0.707107));
  BOOST_CHECK(ajx::approx(second.y(), 0.707107));
}

BOOST_AUTO_TEST_CASE ( rotatedBy )
{
  ajx::vec2d<double> first(10,10);
  ajx::vec2d<double> second(0,1);
  ajx::vec2d<double> third(73.53, 92.11);

  first = first.rotatedBy(M_PI/2);
  second = second.rotatedBy(M_PI);
  third = third.rotatedBy(8*M_PI/3);

  BOOST_CHECK(ajx::approx(first.x(), -10.0));
  BOOST_CHECK(ajx::approx(first.y(),  10.0));
  BOOST_CHECK(ajx::approx(second.x(),  0.0));
  BOOST_CHECK(ajx::approx(second.y(), -1.0));
  BOOST_CHECK(ajx::approx(-116.53459994258463, third.x()));
  BOOST_CHECK(ajx::approx(17.62384794026989, third.y()));
}

BOOST_AUTO_TEST_CASE ( rotatedByAbout )
{
  ajx::vec2d<double> first(1.0,1.0);
  ajx::vec2d<double> second(-4.0,4.0);

  ajx::vec2d<double> about(1,1);
  ajx::vec2d<double> about2(-4.0,2.0);
  ajx::vec2d<double> about3(5.0,5.0);

  first = first.rotatedByAbout(M_PI/2.0, about);
  ajx::vec2d<double> third = second.rotatedByAbout(M_PI/2.0, about3);
  second = second.rotatedByAbout(M_PI, about2);

  BOOST_CHECK(ajx::approx(first.x(),  1.0));
  BOOST_CHECK(ajx::approx(first.y(),  1.0));
  BOOST_CHECK(ajx::approx(second.x(), -4.0));
  BOOST_CHECK(ajx::approx(second.y(), 0.0));
  BOOST_CHECK(ajx::approx(third.x(),  6.0));
  BOOST_CHECK(ajx::approx(third.y(),  -4.0));
}