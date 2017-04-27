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

// BOOST_AUTO_TEST_CASE(zero_left_col)
// {
// 	ajx::vec2d<int> vec1(1,2);
// 	ajx::vec2d<int> vec2(3,4);
// 	ajx::matrix2d<int> matrix1(vec1,vec2);

// 	matrix1.ZeroLeftCol();

// 	BOOST_CHECK(matrix1.column1().x() == 0);
// 	BOOST_CHECK(matrix1.column1().y() == 0);
// 	//BOOST_CHECK(matrix1.column2() == vec2);
// 	BOOST_CHECK(matrix1.column2() == vec2);
// }