#ifndef AJX_MATRIX2D
#define AJX_MATRIX2D

#include <boost/operators.hpp>
#include "constants.h"
#include "vec2d.h"
#include <cmath>

namespace ajx {

    template <class T>
    class matrix2d : boost::operators< matrix2d<T> > {
        public:

      	matrix2d() {
      		col1(0,0);
      		col2(0,0);
      	};

      	matrix2d(T t1, T t2, T t3, T t4) {
  				col1(t1,t2);
  				col2(t3,t4);
 			  };

   			matrix2d(const ajx::vec2d<T> &v1, const ajx::vec2d<T> &v2)
   			{
   				col1 = v1;
   				col2 = v2;
   			};

   			~matrix2d(){

   			};

   			void ZeroLeftCol()
   			{
   				this->col1 = this->col1 * 0;
   			}

        void ZeroRightCol()
        {
          this->col2 = this->col2 * 0;
        }

        bool operator==(const matrix2d<T>& x) const {
          if (this->col1 != x.col1) return false;
          if (this->col2 != x.col2) return false;
          return true;
        };

        T x() const { return col1.x();}
        T y() const { return col2.y();}
        vec2d<T> column1() const { return col1;}
        vec2d<T> column2() const { return col2;}



        protected:
        	vec2d<T> col1;
        	vec2d<T> col2;
    };
}

#endif
