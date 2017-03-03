#include "vec2d.h"

namespace ajx {

    // operator overloads!
    template <class T>
	vec2d<T> vec2d<T>::operator*=(const vec2d<T>& x) {
		this->m_x = this->m_x * x.m_x;
		this->m_y = this->m_y * x.m_y;
		return this;
	}

	template <class T>
    bool vec2d<T>::operator<(const vec2d<T>& x) const {
    	return ((this->m_x * this->m_x + this->m_y + this->m_y) < (x.m_x * x.m_x + x.m_y * x.m_y));
    }

    template <class T>
    bool vec2d<T>::operator==(const vec2d<T>& x) const {
    	if (this->m_x != x.m_x) return false;
    	if (this->m_y != x.m_y) return false;
    	return true;
    }

    template <class T>
    vec2d<T> vec2d<T>::operator+=(const vec2d<T>& x) {
    	this->m_x += x.m_x;
    	this->m_y += x.m_y;
    	return this;
    }

    template <class T>
    vec2d<T> vec2d<T>::operator-=(const vec2d<T>& x) {
    	this->m_x -= x.m_x;
    	this->m_y -= x.m_y;
    	return this;
    }

    template <class T>
    vec2d<T> vec2d<T>::operator/=(const vec2d<T>& x) {
    	this->m_x /= x.m_x;
    	this->m_y /= x.m_y;
    	return this;
    }

    template <class T>
    vec2d<T> vec2d<T>::operator%=(const vec2d<T>& x) {
    	this->m_x %= x.m_x;
    	this->m_y %= x.m_y;
    	return this;
    }

    template <class T>
    vec2d<T> vec2d<T>::operator|=(const vec2d<T>& x) {
    	this->m_x |= x.m_x;
    	this->m_y |= x.m_y;
    	return this;
    }

    template <class T>
    vec2d<T> vec2d<T>::operator&=(const vec2d<T>& x) {
    	this->m_x &= x.m_x;
    	this->m_y &= x.m_y;
    	return this;
    }

    template <class T>
    vec2d<T> vec2d<T>::operator^=(const vec2d<T>& x) {
    	this->m_x ^= x.m_x;
    	this->m_y ^= x.m_y;
    	return this;
    }
}

