#ifndef _VIDEO_CURSES_H_
#define _VIDEO_CURSES_H_

#include "util/geometry.h"
#include "video/video.h"


namespace video
{

class Curses : public Video
{
public:
	Curses(void);

	//~Curses(void);

	// get the type enum for this instance
	virtual Video::Type getType(void) const override;

	// set the size of the display
	virtual bool setSize(const util::geometry::dimensions_t &d) override;

	// initialize the instance
	virtual bool initialize(void) override;

	// shutdown & clean the instance
	virtual bool shutdown(void) override;

protected:
	// set size of a cell
	virtual void setCellSize(util::geometry::dimensions_t &d) override;

	// update the screen
	virtual void update(void) override;

	// draw to the screen
	virtual void draw(void *buf) override;

private:
	typedef Video super;

	// NCURSES VARIABLES
	SCREEN *screens[BUFFER_COUNT];
};

}

#endif

