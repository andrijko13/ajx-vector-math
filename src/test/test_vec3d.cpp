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

BOOST_AUTO_TEST_CASE( cross )
{
  ajx::vec3d<int> vec1(1,5,1);
  ajx::vec3d<int> vec2(2,3,4);

  ajx::vec3d<int> result = vec1.cross(vec2);

  BOOST_CHECK(result.x() == 17);
  BOOST_CHECK(result.y() == -2);
  BOOST_CHECK(result.z() == -7);
}