#ifndef _VIDEO_VIDEO_H_
#define _VIDEO_VIDEO_H_

#include "util/geometry.h"


namespace video
{

template <class B>
class Video
{
public:
	// video mode of this class
	enum Type {
		CURSES	= 0,
		SDL		= 1
	};

	// display size aliases
	enum SizeMode {
		FULLSCREEN	= 0
	};

	// default constructor
	Video(void) = default;

	// get the size of the display
	const util::geometry::dim_t &getSize(void) const;

	// set the size of the display
	virtual bool setSize(const util::geometry::dim_t &d);

protected:

	// video buffers and count of buffers
	static constexpr unsigned int BUFFER_COUNT = 2;

	void *buffer{};

	// which buffer is going to be drawn to
	/* NOTE:
	 * x
	 */
	/* NOTE: buffer[2+(!which)]
	 *  ! (0) -> (0xFF..FF) -> (-1 + 2) -> 1
	 *  !(-1) -> (0x00..00) -> (0 +
	 */
	// NOTE: to flip: `which = (1 + !which)'
	//char which{};

	// swap the back buffer to the front, and vice versa
	virtual void flip(void);

	// update the screen
	virtual void update(void);

	// draw to the screen
	virtual void draw(void *buf);

	// get buffer #'s buffer
	virtual B* getBuffer(unsigned int which) const;

	// set buffer # to buffer given
	virtual void setBuffer(unsigned int which, void *buf);

private:
	// screen size
	util::geometry::dim_t screen_size{};

	// screen buffers
	void *buffers[BUFFER_COUNT] = { nullptr, nullptr };
	unsigned int buf_idx = 0;
};

// Video singleton
Video *video = nullptr;

}

#endif

