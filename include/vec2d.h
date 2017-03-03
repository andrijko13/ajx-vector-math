#ifndef AJX_VEC2D
#define AJX_VEC2D

#include <boost/operators.hpp>
#include <cmath>

namespace ajx {
    template <class T> class vec2d : boost::operators< vec2d<T> > {
        public:
            vec2d(T t1, T t2) {
				this->m_x = t1;
				this->m_y = t2;
   			};

            ~vec2d() {

            };

            bool operator<(const vec2d& x) const;
		    bool operator==(const vec2d& x) const;
		    vec2d operator+=(const vec2d& x);
		    vec2d operator-=(const vec2d& x);
		    vec2d operator*=(const vec2d& x);
		    vec2d operator/=(const vec2d& x);
		    vec2d operator%=(const vec2d& x);
		    vec2d operator|=(const vec2d& x);
		    vec2d operator&=(const vec2d& x);
		    vec2d operator^=(const vec2d& x);
		    vec2d operator--();

            T x() { return m_x; };
            T y() { return m_y; };
            T distance() { return std::sqrt(m_x*m_x + m_y*m_y); };

        protected:
        	T m_x;
        	T m_y;
    };
}

#endif
