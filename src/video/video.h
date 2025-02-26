#ifndef _VIDEO_VIDEO_H_
#define _VIDEO_VIDEO_H_

#include <memory>

#include "util/geometry.h"


namespace video
{

/**
 * @brief Base class for graphics handling.
 */
class Video
{
public:
	// video mode of this class
	enum Type {
		CURSES	= 1,
		SDL		= 2
	};

	// display size aliases
	enum SizeMode {
		FULLSCREEN	= -1
	};

	// default constructor
	Video(void)
	{
		// assure zeroed out buffers
		for(unsigned int i = 0; i < BUFFER_COUNT; ++i) {
			this->buffers[i] = nullptr;
		}
	}

	// destructor
	~Video(void)
	{
		this->shutdown();
	}

	// get the type enum for this instance
	virtual Type getType(void) const;

	// get the size of the display
	const util::geometry::dimensions_t &getSize(void) const
	{
		return this->screen_size;
	}

	// set the size of the display
	virtual bool setSize(const util::geometry::dimensions_t &d)
	{
		this->screen_size = d;
		this->update();
	}

	const util::geometry::dimensions_t &getCellSize(void) const
	{
		return this->cell_size;
	}

	// initialize the instance
	virtual bool initialize(void);

	// shutdown & cleanup the instance
	virtual bool shutdown(void);

protected:
	// count of video buffers
	static constexpr unsigned int BUFFER_COUNT = 2;

	// set size of a cell
	virtual void setCellSize(const util::geometry::dimensions_t &d)
	{
		this->cell_size = d;
	}

	// get current buffer's index
	unsigned int getBufferIndex(void) const
	{
		return this->buf_idx;
	}

	// get buffer #'s buffer
	void *getBuffer(unsigned int which) const
	{
		if(which < BUFFER_COUNT) {
			return const_cast<void*>(this->buffers[which]);
		}
		return nullptr;
	}

	// set buffer # to buffer given, return old buffer
	void *setBuffer(unsigned int which, void *buf)
	{
		void *prior = nullptr;
		if(which < BUFFER_COUNT) {
			prior = this->buffers[which];
			this->buffers[which] = buf;
		}
		return prior;
	}

	// which buffer is going to be drawn to
	/* NOTE: buffer[2+(!which)]
	 *  ! (0) -> (0xFF..FF) -> (-1 + 2) -> 1
	 *  !(-1) -> (0x00..00) -> (0 +
	 */
	// NOTE: to flip: `which = (1 + !which)'
	//char which{};

	// swap the back buffer to the front, and vice versa
	virtual void flip(void)
	{
		this->buf_idx = ((this->buf_idx + 1) % BUFFER_COUNT);
		this->update();
	}

	// update the screen
	virtual void update(void);

	// draw to the screen
	virtual void draw(void *buf);

private:
	// screen size
	util::geometry::dimensions_t screen_size{};

	// cell dimensions (single character)
	util::geometry::dimensions_t cell_size{};

	// screen buffers
	void *buffers[BUFFER_COUNT];
	unsigned int buf_idx = 0;
};

// Video singleton
std::unique_ptr<Video> video{nullptr};

}

#endif

