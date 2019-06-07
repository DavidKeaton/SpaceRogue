//
// Created by robin on 6/1/19.
//
#ifndef SPACEROGUE_LOGGER_H
	#define SPACEROGUE_LOGGER_H

#include <cstdio>
#include <string>

/**
 * Handles logging messages to a log file, or 'captains.log' by default.
 * 		(works like Android logger)
 */
class Logger
{
private:
	// default log name
	const char *DEFAULT_LOG = "captains.log";
	// file descriptor of log file
	FILE *fd;
	// filename of log
	std::string filename;

	// types of log entries
	enum TYPE {
		DEBUG   = 0,
		INFO    = 1,
		WARN    = 2,
		ERROR   = 3,
		FATAL   = 4
	};

	/**
	 * Determine type of log message.
	 *
	 * @param type 		Log::TYPE
	 * @return 			string representation
	 */
	static const char *get_type(Logger::TYPE type);
	/**
	 * Write log message @ref msg of @ref type with @ref tag to log file.
	 *
	 * @param type		type of log message
	 * @param tag		tag of log message
	 * @param msg		message itself
	 */
	void log(TYPE type, const char *tag, const char *msg, ...);
	void log(TYPE type, const char *tag, const char *msg, va_list list);

public:

	/**
	 * Opens default log file.
	 */
	Logger()
	{
		// lazy open
		filename = DEFAULT_LOG;
		/*
		// unable to open log file?
		if(!(Logger::fd = fopen(DEFAULT_LOG, "a+"))) {
			e("Logger::open()", "unable to open default log file!");
		}
		*/
	}

	/**
	 * Opens log file @ref fname.
	 *
	 * @param fname 	filename of log to use
	 */
	Logger(const char *fname)
	{
		// lazy open
		filename = fname;
		/*
		// unable to open log file?
		if(!(fd = fopen(fname, "a+"))) {
			e("Logger::open()", "unable to open %s for R/W", fname);
		}
		*/
	}

	/**
	 * Safely closes log file.
	 */
	~Logger()
	{
		if(fd) {
			// flush and close file stream
			fflush(fd);
			fclose(fd);
		}
	}

	/**
	 * Writes the given buffer to the log file.
	 *
	 * @param ptr 		the buffer to write to the log
	 */
	void write(const void *ptr, int size);
	/**
	 * Log DEBUG message @ref msg.
	 *
	 * @param tag 	specifies class or routine called from
	 * @param msg 	the message to send to the log
	 */
	void d(const char *tag, const char *fmt, ...);
	/**
	 * Log INFO message @ref fmt, ....
	 *
	 * @param tag 	specifies class or routine called from
	 * @param fmt, ... 	the message to send to the log
	 */
	void i(const char *tag, const char *fmt, ...);
	/**
	 * Log WARN message @ref fmt, ....
	 *
	 * @param tag 	specifies class or routine called from
	 * @param fmt, ... 	the message to send to the log
	 */
	void w(const char *tag, const char *fmt, ...);
	/**
	 * Log ERROR message @ref fmt, ....
	 *
	 * @param tag 	specifies class or routine called from
	 * @param fmt, ... 	the message to send to the log
	 */
	void e(const char *tag, const char *fmt, ...);
	/**
	 * Log FATAL message @ref fmt, ....
	 *
	 * @param tag 	specifies class or routine called from
	 * @param fmt, ... 	the message to send to the log
	 */
	void f(const char *tag, const char *fmt, ...);
};

#endif //SPACEROGUE_LOGGER_H
