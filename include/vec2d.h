#ifndef AJX_VEC2D
#define AJX_VEC2D

#include <boost/operators.hpp>
#include <cmath>

namespace ajx {
    template <class T>
    class vec2d : boost::operators< vec2d<T> > {
        public:
            vec2d(T t1, T t2) {
				this->m_x = t1;
				this->m_y = t2;
   			};

            ~vec2d() {

            };

            bool operator<(const vec2d<T>& x) const {
            	return ((this->m_x * this->m_x + this->m_y + this->m_y) < (x.m_x * x.m_x + x.m_y * x.m_y));
            };

		    bool operator==(const vec2d<T>& x) const {
		    	if (this->m_x != x.m_x) return false;
		    	if (this->m_y != x.m_y) return false;
		    	return true;
		    };

		    vec2d<T>& operator+=(const vec2d<T>& x) {
		    	this->m_x += x.m_x;
		    	this->m_y += x.m_y;
		    	return *this;
		    };

		    vec2d<T>& operator-=(const vec2d<T>& x) {
		    	this->m_x -= x.m_x;
		    	this->m_y -= x.m_y;
		    	return *this;
		    };

		    vec2d<T>& operator*=(const vec2d<T>& x) {
				this->m_x = this->m_x * x.m_x;
				this->m_y = this->m_y * x.m_y;
				return *this;
			};

		    vec2d<T>& operator/=(const vec2d<T>& x) {
		    	this->m_x /= x.m_x;
		    	this->m_y /= x.m_y;
		    	return *this;
		    };

		    vec2d<T>& operator%=(const vec2d<T>& x) {
		    	this->m_x %= x.m_x;
		    	this->m_y %= x.m_y;
		    	return *this;
		    };

		    vec2d<T>& operator|=(const vec2d<T>& x) {
		    	this->m_x |= x.m_x;
		    	this->m_y |= x.m_y;
		    	return *this;
		    };

		    vec2d<T>& operator&=(const vec2d<T>& x) {
		    	this->m_x &= x.m_x;
		    	this->m_y &= x.m_y;
		    	return *this;
		    };

		    vec2d<T>& operator^=(const vec2d<T>& x) {
		    	this->m_x ^= x.m_x;
		    	this->m_y ^= x.m_y;
		    	return *this;
		    };

		    vec2d<T>& operator++() {
		    	this->m_x += 1;
		    	this->m_y += 1;
		    	return *this;
		    };

		    vec2d<T>& operator--() {
		    	this->m_x -= 1;
		    	this->m_y -= 1;
		    	return *this;
		    };

            T x() { return m_x; };
            T y() { return m_y; };
            T distance() { return std::sqrt(m_x*m_x + m_y*m_y); };

        protected:
        	T m_x;
        	T m_y;
    };
}

#endif
