#define BOOST_TEST_DYN_LINK

#define BOOST_TEST_MODULE "matrix2D Test Module"
#include <boost/test/unit_test.hpp>

#include "vec2d.h"
#include "matrix2d.h"
#include <cmath>
#include <iostream>

BOOST_AUTO_TEST_CASE(constructors)
{
	ajx::vec2d<int> vec1(1,2);
	ajx::vec2d<int> vec2(3,4);
	ajx::matrix2d<int> matrix1(vec1,vec2);

	BOOST_CHECK(matrix1.column1() == vec1);
	BOOST_CHECK(matrix1.column1().x() == 1);
	BOOST_CHECK(matrix1.column1().y() == 2);
	BOOST_CHECK(matrix1.column2() == vec2);
	BOOST_CHECK(matrix1.column2().x() == 3);
	BOOST_CHECK(matrix1.column2().y() == 4);
}

BOOST_AUTO_TEST_CASE(zero_left_col)
{
	ajx::vec2d<int> vec1(1,2);
	ajx::vec2d<int> vec2(3,4);
	ajx::matrix2d<int> matrix1(vec1,vec2);

	matrix1.ZeroLeftCol();

	BOOST_CHECK(matrix1.column1().x() == 0);
	BOOST_CHECK(matrix1.column1().y() == 0);
	BOOST_CHECK(matrix1.column2() == vec2);
}

BOOST_AUTO_TEST_CASE(zero_right_col)
{
	ajx::vec2d<int> vec1(7,3);
	ajx::vec2d<int> vec2(5,1);
	ajx::matrix2d<int> matrix1(vec1,vec2);

	matrix1.ZeroRightCol();

	BOOST_CHECK(matrix1.column1() == vec1);
	BOOST_CHECK(matrix1.column2().x() == 0);
	BOOST_CHECK(matrix1.column2().y() == 0);
}

BOOST_AUTO_TEST_CASE(Transpose)
{
	ajx::matrix2d<int> matrix1(1,3,2,4);
	// ajx::vec2d<int> vec1(1,3);
	// ajx::vec2d<int> vec2(2,4);
	// ajx::matrix2d<int> matrix1(vec1,vec2);
	BOOST_CHECK(matrix1.column1().x() == 1);
	BOOST_CHECK(matrix1.column1().y() == 3);
	BOOST_CHECK(matrix1.column2().x() == 2);
	BOOST_CHECK(matrix1.column2().y() == 4);

	matrix1.Transpose();

	BOOST_CHECK(matrix1.column1().x() == 1);
	BOOST_CHECK(matrix1.column1().y() == 2);
	BOOST_CHECK(matrix1.column2().x() == 3);
	BOOST_CHECK(matrix1.column2().y() == 4);
}

BOOST_AUTO_TEST_CASE( equals_Operator)
{
	ajx::matrix2d<int> matrix1(1,3,2,4);
	ajx::matrix2d<int> matrix2(1,3,2,4);
	ajx::matrix2d<int> matrix3(1,2,3,4);
	ajx::matrix2d<int> matrix4(7,6,4,5);

	BOOST_CHECK(matrix1 == matrix2);
	BOOST_CHECK(!(matrix2 == matrix3));
	BOOST_CHECK(!(matrix4 == matrix3));
}

BOOST_AUTO_TEST_CASE( plus_equals)
{
	ajx::matrix2d<int> matrix1(1,3,2,4);
	ajx::matrix2d<int> matrix2(7,6,5,8);

	matrix1 += matrix2;

	BOOST_CHECK(matrix1.column1().x() == 8);
	BOOST_CHECK(matrix1.column1().y() == 9);
	BOOST_CHECK(matrix1.column2().x() == 7);
	BOOST_CHECK(matrix1.column2().y() == 12);
}

BOOST_AUTO_TEST_CASE( minus_equals)
{
	ajx::matrix2d<int> matrix1(1,3,8,4);
	ajx::matrix2d<int> matrix2(7,6,5,8);

	matrix1 -= matrix2;

	BOOST_CHECK(matrix1.column1().x() == -6);
	BOOST_CHECK(matrix1.column1().y() == -3);
	BOOST_CHECK(matrix1.column2().x() == 3);
	BOOST_CHECK(matrix1.column2().y() == -4);
}

BOOST_AUTO_TEST_CASE( times_equals)
{
	ajx::matrix2d<int> matrix1(1,3,2,4);
	ajx::matrix2d<int> matrix2(4,6,5,7);

	matrix1 *= matrix2;

	BOOST_CHECK(matrix1.column1().x() == 16);
	BOOST_CHECK(matrix1.column1().y() == 36);
	BOOST_CHECK(matrix1.column2().x() == 19);
	BOOST_CHECK(matrix1.column2().y() == 43);
}

BOOST_AUTO_TEST_CASE( ToThePowerOf )
{
	ajx::matrix2d<int> matrix1(1,3,2,4);

	matrix1.ToThePowerOf(3);

	BOOST_CHECK(matrix1.column1().x() == 37);
	BOOST_CHECK(matrix1.column1().y() == 81);
	BOOST_CHECK(matrix1.column2().x() == 54);
	BOOST_CHECK(matrix1.column2().y() == 118);
}