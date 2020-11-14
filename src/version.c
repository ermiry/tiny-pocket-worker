#include "version.h"

#include "utils/log.h"

// print full pocket version information
void pocket_worker_version_print_full (void) {

	pocket_log_msg ("\n\nTiny Pocket Worker Version: %s\n", POCKET_WORKER_VERSION_NAME);
	pocket_log_msg ("Release Date & time: %s - %s\n", POCKET_WORKER_VERSION_DATE, POCKET_WORKER_VERSION_TIME);
	pocket_log_msg ("Author: %s\n\n", POCKET_WORKER_VERSION_AUTHOR);

}

// print the version id
void pocket_worker_version_print_version_id (void) {

	pocket_log_msg ("\n\nTiny Pocket Version ID: %s\n", POCKET_WORKER_VERSION);

}

// print the version name
void pocket_worker_version_print_version_name (void) {

	pocket_log_msg ("\n\nTiny Pocket Version: %s\n", POCKET_WORKER_VERSION_NAME);

}