//
// Created by robin on 6/1/19.
//

#ifndef SPACEROGUE_VIDEO_H
#define SPACEROGUE_VIDEO_H

// compilation dependent UI
#include <ncurses.h>

#if defined(CONSOLE)
	#include <ncurses.h>
#elif defined(SDL)
	#include <sdl.h>
#endif

class Video
{
public:
	// video mode of this class
	enum TYPE {
		NCURSES = 0,
		SDL     = 1
	};

	// display size aliases
	enum {
		FULLSCREEN = 0
	};
	// used to hold size of display
	struct size {
		int width;
		int height;
		// size = *{w, h}
		struct size& operator=(const struct size& rhs)
		{
			this->width  = rhs.width;
			this->height = rhs.height;
			return *this;
		}
		// size = {w, h}
		struct size& operator=(const struct size *rhs)
		{
			*this = *rhs;
			return *this;
		}
	};

// TODO: continue class design
private:
	// initialize the correct type of Video instance
	static void init(enum TYPE type);

protected:
	// video context pointer
	static Video *context;
	// screen size
	struct size dim{};

	// set the size of the display
	virtual bool setSize(const struct size *d);

	// video buffers and count of buffers
	// TODO: variable buffer counts?
	const int BUFFER_COUNT = 2;
	void *buffer{};

	// which buffer is going to be drawn to
	/* NOTE:
	 *
	 */
	/* NOTE: buffer[2+(!which)]
	 *  ! (0) -> (0xFF..FF) -> (-1 + 2) -> 1
	 *  !(-1) -> (0x00..00) -> (0 +
	 */
	// NOTE: to flip: `which = (1 + !which)'
	char which{};

	virtual void flip(void)
	{
		context->flip();
	}

	// update the screen
	virtual void update(void)
	{
		context->update();
	}
	// draw to the screen
	virtual void draw(void *buf)
	{
		context->draw(buf);
	}

public:
	Video(void) = default;

	explicit Video(Video::TYPE type,
		const struct size *d = {Video::FULLSCREEN, Video::FULLSCREEN});

	// return the instance of the Video class created
	virtual Video *get(void)
	{
		return context;
	}
};

/**
 * NCURSES
 */
class Curses : protected Video
{
private:
	// NCURSES VARIABLES
	SCREEN *screens{};

	// dimensions of console characters
	const Video::size char_dim;

	// set up NCURSES components
	static void init();
protected:
	override flip(void);
	override update(void);
	override draw(void *buf);
	override setSize(Video::size *d);
public:
	Curses(void);
};

/**
 * SDL
 */
class SDL : protected Video
{
private:
	// SDL VARIABLES

	// set up SDL components
	static void init();
protected:
	override flip(void);
	override update(void);
	override draw(void *buf);
	override setSize(Video::size *d);

public:
	SDL(void);
};

#endif //SPACEROGUE_VIDEO_H
