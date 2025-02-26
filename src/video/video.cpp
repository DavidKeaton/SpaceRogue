#include "video/video.h"


/**
 * Initialize the display with the @ref Video::TYPE of UI.
 *
 * @param type 		@ref Video::TYPE of UI to create
 */
void Video::init(Video::TYPE type)
{
	// 'new` class will call its constructor, thus ->'init()`
	switch(type) {
		case NCURSES:
			context = (Video*) new class Curses;
			break;
		case SDL:
			context = (Video*) new class SDL;
			break;
		default:
			context = nullptr;
			// TODO: log error on creation of NO type
			return;
	}
}

/**
 * Default constructor that sets
 * @param type
 */
Video::Video(Video::TYPE type, const Video::size *d)
{
	// set default buffer
	which = 0;
	// create video buffers
	buffer = new void*[BUFFER_COUNT];
	// initialize the type of Video class to be used
	init(type);
	// set up dimensions of the screen
	// XXX: for now, just use all of screen
	setSize(d);
	// validate everything set up properly
}

/**
 * Set the video size of the display.
 *
 * @param d 	@ref Video::size dimensions
 * @return 		true iff valid dimensions given
 */
override Video::setSize(const Video::size *d)
{
	// sanity check
	if(context != nullptr) {
		// set dimensions for screen
		this->dim = d;
		return true;
	}
	// TODO: log error
	return false;
}

