// Created by davek on 11/17/19.

#include "Video.h"

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
