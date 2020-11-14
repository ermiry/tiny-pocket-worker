#ifndef _UTILS_LOG_H_
#define _UTILS_LOG_H_

#include <stdio.h>
#include <stdbool.h>

#define LOG_DEFAULT_PATH		"logs"

#define LOG_POOL_INIT			32

#define LOG_DATETIME_SIZE		32
#define LOG_HEADER_SIZE			32
#define LOG_HEADER_HALF_SIZE	LOG_HEADER_SIZE / 2

#define LOG_MESSAGE_SIZE		4096

#define LOG_COLOR_RED       "\x1b[31m"
#define LOG_COLOR_GREEN     "\x1b[32m"
#define LOG_COLOR_YELLOW    "\x1b[33m"
#define LOG_COLOR_BLUE      "\x1b[34m"
#define LOG_COLOR_MAGENTA   "\x1b[35m"
#define LOG_COLOR_CYAN      "\x1b[36m"
#define LOG_COLOR_RESET     "\x1b[0m"

#pragma region types

#define LOG_TYPE_MAP(XX)						\
	XX(0, 	NONE, 		[NONE])					\
	XX(1, 	ERROR, 		[ERROR])				\
	XX(2, 	WARNING, 	[WARNING])				\
	XX(3, 	SUCCESS, 	[SUCCESS])				\
	XX(4, 	DEBUG, 		[DEBUG])				\
	XX(5, 	TEST, 		[TEST])					\
	XX(6, 	HANDLER, 	[HANDLER])				\
	XX(7, 	FILE, 		[FILE])

typedef enum LogType {

	#define XX(num, name, string) LOG_TYPE_##name = num,
	LOG_TYPE_MAP (XX)
	#undef XX
	
} LogType;

#pragma endregion

#pragma region configuration

typedef enum LogOutputType {

	LOG_OUTPUT_TYPE_NONE		= 0,
	LOG_OUTPUT_TYPE_STD			= 1,	// log to stdout & stderr
	LOG_OUTPUT_TYPE_FILE		= 2,	// log to a file
	LOG_OUTPUT_TYPE_BOTH		= 3		// log to both std output and file

} LogOutputType;

// returns the current log output type
extern LogOutputType pocket_log_get_output_type (void);

// sets the log output type to use
extern void pocket_log_set_output_type (LogOutputType type);

// sets the path where logs files will be stored
// returns 0 on success, 1 on error
extern unsigned int pocket_log_set_path (const char *pathname);

#define LOG_TIME_TYPE_MAP(XX)										\
	XX(0, 	NONE, 		None,		Logs without time)				\
	XX(1, 	TIME, 		Time,		Logs with time)					\
	XX(2, 	DATE, 		Date,		Logs with date)					\
	XX(3, 	BOTH, 		Both,		Logs with date and time)

typedef enum LogTimeType {

	#define XX(num, name, string, description) LOG_TIME_TYPE_##name = num,
	LOG_TIME_TYPE_MAP (XX)
	#undef XX

} LogTimeType;

extern const char *pocket_log_time_type_to_string (LogTimeType type);

extern const char *pocket_log_time_type_description (LogTimeType type);

// returns the current log time configuration
extern LogTimeType pocket_log_get_time_config (void);

// sets the log time configuration to be used by log methods
// none: print logs with no dates
// time: 24h time format
// date: day/month/year format
// both: day/month/year - 24h date time format
extern void pocket_log_set_time_config (LogTimeType type);

// set if logs datetimes will use local time or not
extern void pocket_log_set_local_time (bool value);

#pragma endregion

#pragma region public

// creates and prints a message of custom types
// based on the first type, the message can be printed with colors to stdout
extern void pocket_log (
	LogType first_type, LogType second_type,
	const char *format, ...
);

// prints a message with no type, effectively making this a custom printf ()
extern void pocket_log_msg (const char *msg, ...);

// prints a red error message to stderr
extern void pocket_log_error (const char *msg, ...);

// prints a yellow warning message to stderr
extern void pocket_log_warning (const char *msg, ...);

// prints a green success message to stdout
extern void pocket_log_success (const char *msg, ...);

// prints a debug message to stdout
extern void pocket_log_debug (const char *msg, ...);

#pragma endregion

#pragma region main

extern void pocket_log_init (void);

extern void pocket_log_end (void);

#pragma endregion

#endif