#include "util/geometry.h"
#include "video/video.h"
#include "video/curses.h"


namespace video
{

Curses::Curses(void)
{
	for(unsigned int i = 0; i < BUFFER_COUNT; ++i) {
		this->screens[i] = nullptr;
	}
}

#if 0
Curses::~Curses(void)
{
	this->shutdown();
}
#endif

Video::Type Curses::getType(void) const
{
	return Video::Type::CURSES;
}

// TODO
void Curses::initialize(void)
{
	// TODO: set the size of 1 cell, defaults to 8x8
	this->setCellSize({8, 8});

	// TODO: initialize curses

	// TODO: create screens
}

// TODO
bool Curses::shutdown(void)
{
	// TODO: destroy screens

	// TODO: shutdown curses
}

// TODO
void Curses::setCellSize(util::geometry::dimensions_t &d)
{
	super::setCellSize(d);
}

// TODO
void Curses::update(void)
{
}

// TODO
void Curses::draw(void *buf)
{
}

// TODO
void Curses::flip(void)
{
	super::flip();
}

// TODO
// translate screen dimensions into the appropriate console dimensions
bool Curses::setSize(const util::geometry::dimensions_t &d)
{
	// maximum width?
	if(this->dim.width == Video::FULLSCREEN) {
	// width a valid number?
	} else if(this->dim.width > 0) {
	// invalid width provided
	} else {
	}

	// maximum height?
	if(this->dim.height == Video::FULLSCREEN) {
	// width a valid number?
	} else if(this->dim.height > 0) {
	// invalid width provided
	} else {
	}
}

}

