//
// Created by robin on 6/1/19.
//

#include "Video.h"

/*
 * 		XXX: [[VIDEO]]
 */
void Video::init(TYPE type)
{
	switch(type) {
		case NCURSES:
			break;
		case SDL:
			break;
		default:
			return;
	}
}

void Video::flip(void)
{}

/**
 * 		XXX: [[NCURSES]]
 */
void Console::update(void)
{}

void Console::draw(void *buffer)
{}
