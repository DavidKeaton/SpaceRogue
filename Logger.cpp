//
// Created by robin on 6/1/19.
//
#include <cstdarg>

#include "Logger.h"

/**
 * Determine type of log message.
 *
 * @param type 		Log::TYPE
 * @return 			string representation
 */
const char *Logger::get_type(Logger::TYPE type)
 {
	 switch(type) {
		 case DEBUG:
			 return "DBG";
		 case INFO:
			 return "NFO";
		 case WARN:
			 return "WRN";
		 case ERROR:
			 return "ERR";
		 case FATAL:
			 return "FTL";
		 default:
			 return "???";
	 }
 }

/**
 * Writes the given buffer to the log file.
 *
 * @param ptr 		the buffer to write to the log
 */
void Logger::write(const void *ptr, const int size)
{
	// open if unopened - continues from lazy constructors
	if(!this->fd) {
		// append by default
		this->fd = fopen(this->filename.c_str(), "a+");
	}
	// write data to log file if given
	if(ptr) {
		fwrite(ptr, size, 1, this->fd);
	}
}

/**
 * Write log message @ref msg of @ref type with @ref tag to log file.
 *
 * @param type		type of log message
 * @param tag		tag of log message
 * @param msg		message itself
 * @param ...		variadic arguments field
 */
void Logger::log(Logger::TYPE type, const char *tag, const char *fmt, ...)
{
	va_list vl;
	va_start(vl, fmt);
	log(type, tag, fmt, vl);
	va_end(vl);
}

/**
 * Write log message @ref msg of @ref type with @ref tag to log file.
 *
 * @param type		type of log message
 * @param tag		tag of log message
 * @param msg		message itself
 * @param vl		va_list usually passed before function called
 */
void Logger::log(Logger::TYPE type, const char *tag, const char *fmt, va_list vl)
{
		// format variadic arguments into buf
		char va_buf[1 + vsnprintf(nullptr, 0, fmt, vl)];
		vsnprintf(va_buf, sizeof(va_buf), fmt, vl);
		// place type and tag into new buffer
		const char *log_fmt = "[%s] (%s): %s";
		char log_buf[1 + snprintf(nullptr, 0, log_fmt, get_type(type), tag, va_buf)];
		snprintf(log_buf, sizeof(log_buf), log_fmt, get_type(type), tag, va_buf);
		// write the formatted string to the log
		write(log_buf, sizeof(log_buf));
}

/**
 * Log DEBUG message @ref fmt.
 *
 * @param tag 	specifies class or routine called from
 * @param fmt 	the message to send to the log
 */
void Logger::d(const char *tag, const char *fmt, ...)
{
	va_list vl;
	va_start(vl, fmt);
	log(Logger::TYPE::DEBUG, tag, fmt, vl);
	va_end(vl);
}

/**
 * Log INFO message @ref fmt.
 *
 * @param tag 	specifies class or routine called from
 * @param fmt 	the message to send to the log
 */
void Logger::i(const char *tag, const char *fmt, ...)
{
	va_list vl;
	va_start(vl, fmt);
	log(Logger::TYPE::INFO, tag, fmt, vl);
	va_end(vl);
}

/**
 * Log WARN message @ref fmt.
 *
 * @param tag 	specifies class or routine called from
 * @param fmt 	the message to send to the log
 */
void Logger::w(const char *tag, const char *fmt, ...)
{
	va_list vl;
	va_start(vl, fmt);
	log(Logger::TYPE::WARN, tag, fmt, vl);
	va_end(vl);
}

/**
 * Log ERROR message @ref fmt.
 *
 * @param tag 	specifies class or routine called from
 * @param fmt 	the message to send to the log
 */
void Logger::e(const char *tag, const char *fmt, ...)
{
	va_list vl;
	va_start(vl, fmt);
	log(Logger::TYPE::ERROR, tag, fmt, vl);
	va_end(vl);
}

/**
 * Log FATAL message @ref fmt.
 *
 * @param tag 	specifies class or routine called from
 * @param fmt 	the message to send to the log
 */
void Logger::f(const char *tag, const char *fmt, ...)
{
	va_list vl;
	va_start(vl, fmt);
	log(Logger::TYPE::FATAL, tag, fmt, vl);
	va_end(vl);
}
