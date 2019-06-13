//
// Created by robin on 6/1/19.
//

#ifndef SPACEROGUE_VIDEO_H
#define SPACEROGUE_VIDEO_H

#include <ncurses.h>

class Video
{
// TODO: continue class design
private:
	void *context;
	// back and front buffers
	void *buffer[2];
	// which buffer is going to be drawn to
	/* NOTE:
	 *
	 */
	/* NOTE: buffer[2+(!which)]
	 *  ! (0) -> (0xFF..FF) -> (-1 + 2) -> 1
	 *  !(-1) -> (0x00..00) -> (0 +
	 */
	// NOTE: to flip: `which = (1 + !which)'
	char which;

	enum TYPE {
		NCURSES = 0,
		SDL     = 1
	};

	virtual void flip(void) = 0;
	void init(TYPE type);

protected:
	virtual void update(void) = 0;
	virtual void draw(void *buffer) = 0;

public:
	virtual void get(void) = 0;
};

/**
 * NCURSES
 */
class Console : Video
{
private:
	//
protected:
	void update(void);
	void draw(void *buffer);
public:
	//
};

#endif //SPACEROGUE_VIDEO_H
