#ifndef _VIDEO_CURSES_H_
#define _VIDEO_CURSES_H_

#include "video/video.h"


namespace video
{

class Curses : public Video
{
public:
	Curses(void);

protected:
	override flip(void);
	override update(void);
	override draw(void *buf);
	override setSize(Video::size *d);

private:
	// NCURSES VARIABLES
	SCREEN *screens{};

	// dimensions of console characters
	const Video::size char_dim;

	// set up NCURSES components
	static void init();
};

}

#endif

