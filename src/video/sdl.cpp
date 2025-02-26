#include "video/video.h"
#include "video/sdl.h"


namespace video
{

void SDL::init()
{
}

SDL::SDL(void)
{
	init();
}

override SDL::update(void)
{}

override SDL::draw(void *buf)
{}

override SDL::flip(void)
{}

override SDL::setSize(Video::size *d)
{
	return Video::setSize(d);
}

}

