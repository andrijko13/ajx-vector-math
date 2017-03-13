#ifndef AJX_CONSTANTS
#define AJX_CONSTANTS

namespace ajx {
	const double epsilon = 0.0001;

	template <typename T>
	static bool approx(const T &x, const T &y) {
 		T result = x - y;
 		result = (result < 0) ? result * -1 : result;
 		return (result < epsilon);
	}
}

#endif