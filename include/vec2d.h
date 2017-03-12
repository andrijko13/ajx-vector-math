#ifndef AJX_VEC2D
#define AJX_VEC2D

#include <boost/operators.hpp>
#include "constants.h"
#include <cmath>

namespace ajx {

    template <class T>
    class vec2d : boost::operators< vec2d<T> > {
        public:

        	vec2d() {
        		this->m_x = 0;
        		this->m_y = 0;
        	};

            vec2d(T t1, T t2) {
				this->m_x = t1;
				this->m_y = t2;
   			};

   			vec2d(const vec2d<T> &myvec) {
   				this->m_x = myvec.m_x;
   				this->m_y = myvec.m_y;
   			}

            ~vec2d() {

            };

            static vec2d<T> ZeroVector() {
            	vec2d<T> myvec(0,0);
				return myvec;
		    }

		    static vec2d<T> VectorWith(const T &x, const T &y) {
		    	vec2d<T> myvec(x,y);
		    	return myvec;
		    }


            bool operator<(const vec2d<T>& x) const {
            	return ((this->m_x * this->m_x + this->m_y * this->m_y) < (x.m_x * x.m_x + x.m_y * x.m_y));
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

		    vec2d<T> operator *(const T& val) {
		    	vec2d<T> result(this->m_x * val, this->m_y *val);
		    	return result;
		    }

		    friend vec2d<T> operator * (const T& val, const vec2d<T>& V) {
		    	vec2d<T> myvec;
		    	myvec->m_x = V->m_x * val;
		    	myvec->m_y = V->m_y * val;
		    	return myvec;
		    }

		    vec2d<T>& operator /= (const T& val) {
		    	this->m_x /= val;
		    	this->m_y /= val;
		    }

		    vec2d<T> operator /(const T& val) {
		    	vec2d<T> result(this->m_x / val, this->m_y / val);
		    	return result;
		    }

		    bool equals(const vec2d<T>& x) const {
		    	T resultx = x.m_x - this->m_x;
		    	T resulty = x.m_y - this->m_y;
		    	resultx = (resultx < 0) ? -1 * resultx : resultx;
		    	resulty = (resulty < 0) ? -1 * resulty : resulty;
		    	if (resultx < epsilon && resulty < epsilon) return true;
		    	return false;
		    };

		 	static bool approx(const T &x, const T &y) {
		 		T result = x - y;
		 		result = (result < 0) ? result * -1 : result;
		 		return (result < epsilon);
		 	}

            T x() { return m_x; };
            T y() { return m_y; };
            T dot(const vec2d<T> &U) const { return (m_x * U.m_x + m_y * U.m_y); };
            T cross(const vec2d<T> &U) const { return (m_x*U.m_y - m_y*U.m_x); };
            T length() const { return std::sqrt(m_x*m_x + m_y*m_y); };
            T lengthSquared() const { return (m_x*m_x + m_y*m_y); };

            vec2d<T> normalized() {
            	vec2d<T> myvec;
            	T veclength = this->length();
            	if (veclength < epsilon) return *this;
            	myvec.m_x = m_x/veclength;
            	myvec.m_y = m_y/veclength;
            	return myvec;
            };



        protected:
        	T m_x;
        	T m_y;
    };
}

#endif
