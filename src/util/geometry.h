#ifndef _UTIL_GEOMETRY_H_
#define _UTIL_GEOMETRY_H_

namespace util::geometry
{

/**
 * @brief
 */
typedef struct dim {
	int width;
	int height;
	int length;

	// size = *{w, h}
	dim& operator=(const dim &rhs);

	// size = {w, h}
	dim& operator=(const dim *rhs);
} dim_t;

} // }}} geometry

#endif

