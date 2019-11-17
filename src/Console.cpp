// Created by davek on 11/17/19.

#include "Video.h"

/**
 * Initialize NCURSES and set up appropriate paramaters.
 */
void Curses::init()
{
}

Curses::Curses(void)
{
	//
	this->char_dim = (const) {8, 8};
	// setup
	init();
}

override Curses::update(void)
{}

override Curses::draw(void *buf)
{}

override Curses::flip(void)
{}

// translate screen dimensions into the appropriate console dimensions
override Curses::setSize(Video::size *d)
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
