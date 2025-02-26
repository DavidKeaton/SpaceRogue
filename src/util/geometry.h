#ifndef _UTIL_GEOMETRY_H_
#define _UTIL_GEOMETRY_H_

namespace util::geometry
{

/**
 * @brief Holds 3D dimensions.
 */
typedef struct dimensions {
	int width{ 0 };
	int height{ 0 };
	int length{ 0 };

	// set our dimensions from another
	dimensions& operator=(const dimensions &rhs);
} dimensions_t;

} // }}} util::geometry

#endif

