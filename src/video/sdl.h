#ifndef _VIDEO_SDL_H_
#define _VIDEO_SDL_H_

#include "video/video.h"


namespace video
{

class SDL : public Video
{
public:
	SDL(void);

	// set up SDL components
	static void init();

protected:
	override flip(void);
	override update(void);
	override draw(void *buf);
	override setSize(Video::size *d);

private:
	// SDL VARIABLES
};

}

#endif

