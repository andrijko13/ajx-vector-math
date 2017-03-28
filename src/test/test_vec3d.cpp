#define BOOST_TEST_DYN_LINK

#define BOOST_TEST_MODULE "Vec3D Test Module"
#include <boost/test/unit_test.hpp>

#include "vec3d.h"
#include <iostream>

BOOST_AUTO_TEST_CASE( constructors )
{
	ajx::vec3d<int> vec1;
	ajx::vec3d<int> vec2;
	ajx::vec3d<long long> vec3;
	ajx::vec3d<double> vec4;

  BOOST_CHECK(vec1.x() == vec2.x());
  BOOST_CHECK(vec2.x() == vec3.x());
  BOOST_CHECK(vec1.y() == vec2.y());
  BOOST_CHECK(vec2.y() == vec3.y());
  BOOST_CHECK(vec1.z() == vec2.z());
  BOOST_CHECK(vec2.z() == vec3.z());


  BOOST_CHECK(vec4.x() < ajx::epsilon);
  BOOST_CHECK(vec4.y() < ajx::epsilon);
  BOOST_CHECK(vec4.z() < ajx::epsilon);
}


BOOST_AUTO_TEST_CASE( assignment )
{
  ajx::vec3d<int> vec1(5,-10, 30);
  ajx::vec3d<int> vec2 = vec1;


  BOOST_CHECK_EQUAL(vec2.x(), 5);
  BOOST_CHECK_EQUAL(vec2.y(), -10);
  BOOST_CHECK_EQUAL(vec2.z(), 30);
}

BOOST_AUTO_TEST_CASE( zero_vector )
{
  ajx::vec3d<int> zero = ajx::vec3d<int>::ZeroVector();
  ajx::vec3d<double> zero2 = ajx::vec3d<double>::ZeroVector();

  BOOST_CHECK(zero.x() == 0);
  BOOST_CHECK(zero.y() == 0);
  BOOST_CHECK(zero.z() == 0);

  BOOST_CHECK(zero2.x() < ajx::epsilon);
  BOOST_CHECK(zero2.y() < ajx::epsilon);
  BOOST_CHECK(zero2.z() < ajx::epsilon);
}

BOOST_AUTO_TEST_CASE( multiplication )
{
  ajx::vec3d<int> vec(10,20,30);
  ajx::vec3d<int> result = vec * 3;
  ajx::vec3d<int> result2 = 2 * vec;

  BOOST_CHECK_EQUAL(result.x(), 30);
  BOOST_CHECK_EQUAL(result.y(), 60);
  BOOST_CHECK_EQUAL(result.z(), 90);

  BOOST_CHECK_EQUAL(result2.x(), 20);
  BOOST_CHECK_EQUAL(result2.y(), 40);
  BOOST_CHECK_EQUAL(result2.z(), 60);
}

BOOST_AUTO_TEST_CASE( VectorWith)
{
  ajx::vec3d<int> vec1 = ajx::vec3d<int>::VectorWith(5, 10, 15);
  ajx::vec3d<int> vec2(10,20, 30);
  ajx::vec3d<int> vec3 = ajx::vec3d<int>::VectorWith(1, 2, 3);

  BOOST_CHECK(vec1.x() == 5);
  BOOST_CHECK(vec1.y() == 10);
  BOOST_CHECK(vec1.z() == 15);

  BOOST_CHECK(vec2.x() == ajx::vec3d<int>::VectorWith(10,10,10).x());
  BOOST_CHECK(vec2.y() == ajx::vec3d<int>::VectorWith(10,20,20).y());
  BOOST_CHECK(vec2.z() == ajx::vec3d<int>::VectorWith(30,30,30).z());

  BOOST_CHECK(vec3.x() == 1);
  BOOST_CHECK(vec3.y() == 2);
  BOOST_CHECK(vec3.z() == 3);
}

BOOST_AUTO_TEST_CASE ( equality )
{
  ajx::vec3d<int> first(100,200, 300);
  ajx::vec3d<int> second(200,100, 50);
  ajx::vec3d<int> third(200,100, 50);

  BOOST_CHECK(!(first == second));
  BOOST_CHECK(first != second);
  BOOST_CHECK(second == third);
}

BOOST_AUTO_TEST_CASE ( plus_equals )
{
  ajx::vec3d<int> first(1,1,1);
  first += ajx::vec3d<int>::VectorWith(2,2,2);
  ajx::vec3d<int> second(3,3,3);
  second += first;

  BOOST_CHECK(first.x() == 3);
  BOOST_CHECK(first.y() == 3);
  BOOST_CHECK(first.z() == 3);
  BOOST_CHECK(second.x() == 6);
  BOOST_CHECK(second.y() == 6);
  BOOST_CHECK(second.z() == 6);
}

BOOST_AUTO_TEST_CASE( minus_equals )
{
  ajx::vec3d<int> first(4,4,4);
  ajx::vec3d<int> second(5,5,5);
  second -= first;
  first -= ajx::vec3d<int>::VectorWith(2,2,2);

  BOOST_CHECK(first.x() == 2);
  BOOST_CHECK(first.y() == 2);
  BOOST_CHECK(first.z() == 2);
  BOOST_CHECK(second.x() == 1);
  BOOST_CHECK(second.y() == 1);
  BOOST_CHECK(second.z() == 1);
}

BOOST_AUTO_TEST_CASE ( times_equals )
{
  ajx::vec3d<int> first(4,5,6);
  ajx::vec3d<int> second(-3, 7, 5);
  ajx::vec3d<int> third(1,1,1);

  first *= second;
  second *= third;

  BOOST_CHECK(first.x() == -12);
  BOOST_CHECK(first.y() == 35);
  BOOST_CHECK(first.z() == 30);
  BOOST_CHECK(second.x() == -3);
  BOOST_CHECK(second.y() == 7);
  BOOST_CHECK(second.z() == 5);
}

BOOST_AUTO_TEST_CASE ( divide_equals )
{
  ajx::vec3d<int> first(20,-20,35);
  first /= ajx::vec3d<int>::VectorWith(5,5,7);

  BOOST_CHECK(first.x() == 4);
  BOOST_CHECK(first.y() == -4);
  BOOST_CHECK(first.z() == 5);
}

BOOST_AUTO_TEST_CASE( modulus_equals )
{
  ajx::vec3d<int> first(20,-20, 40);
  first %= ajx::vec3d<int>::VectorWith(5,3, 7);

  BOOST_CHECK(first.x() == 0);
  BOOST_CHECK(first.y() == -2);
  BOOST_CHECK(first.z() == 5);
}

BOOST_AUTO_TEST_CASE( cross )
{
  ajx::vec3d<int> vec1(1,5,1);
  ajx::vec3d<int> vec2(2,3,4);

  ajx::vec3d<int> result = vec1.cross(vec2);

  BOOST_CHECK(result.x() == 17);
  BOOST_CHECK(result.y() == -2);
  BOOST_CHECK(result.z() == -7);
}

BOOST_AUTO_TEST_CASE( rotateAboutAxis )
{
  ajx::vec3d<double> vec1(1,-1,0);
  ajx::vec3d<double> axis(1,1,1);

  vec1 = vec1.rotateAboutAxis(M_PI/3, axis);

  BOOST_CHECK(ajx::approx(vec1.x(), 1.0));
  BOOST_CHECK(ajx::approx(vec1.y(), 0.0));
  BOOST_CHECK(ajx::approx(vec1.z(), -1.0));
}