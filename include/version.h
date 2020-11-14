#ifndef _POCKET_WORKER_VERSION_H_
#define _POCKET_WORKER_VERSION_H_

#define POCKET_WORKER_VERSION                    	"0.1"
#define POCKET_WORKER_VERSION_NAME               	"Version 0.1"
#define POCKET_WORKER_VERSION_DATE			    	"13/11/2020"
#define POCKET_WORKER_VERSION_TIME			    	"22:34 CST"
#define POCKET_WORKER_VERSION_AUTHOR			    "Erick Salas"

// print full pocket worker version information
extern void pocket_worker_version_print_full (void);

// print the version id
extern void pocket_worker_version_print_version_id (void);

// print the version name
extern void pocket_worker_version_print_version_name (void);

#endif