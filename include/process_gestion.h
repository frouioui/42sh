/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** process_gestion.h
*/

#ifndef _PROCESS_GESTION_H__
#define _PROCESS_GESTION_H__

#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdbool.h>

#define SYS_CALL_ERR (-1)

// pid connection
#define SAVES ((struct sigaction *[2]){&saves[0], &saves[1]})

typedef struct pid_connection_s {
	pid_t pid;
	bool usabel;
	bool stop;
} pid_connection_t;

// State ---------------------------
#define NB_STATE (3)
#define RUNNING_S ("Running")
#define SUSPEND_S ("Suspend")
#define DONE_S ("Done")

typedef enum state_process_e {
	DONT_SET,
	RUNNING,
	SUSPEND,
	DONE
} state_process_t;

// Process ---------------------------
typedef struct running_process_s {
	unsigned int id;
	pid_t pid_process;
	char *name;
	state_process_t state;
	struct running_process_s *next;
} running_process_t;

// Init -----------------------------
running_process_t *empty_running_process(void);

// Running --------------------------
//	Connection between process
bool change_action_of_signal(int signum,
void (*act)(int, siginfo_t *, void *));
bool init_connection(struct sigaction *save_one, struct sigaction *save_two,
void (*do_it_to_child)(int, siginfo_t *, void *));
bool init_child_connection(void);
bool finish_connection(struct sigaction *save_one,
struct sigaction *save_two);
void do_it_to_child(int signum, siginfo_t *info, void *env);
pid_connection_t get_or_set_pid(bool get, pid_t pid, bool usabel, bool stop);

// Core Function -------------------------
void update_running_process(running_process_t ** /*node*/);
running_process_t *get_process_from_args(running_process_t * /*node*/,
char ** /*args*/);
bool add_running_process(running_process_t ** /*node*/, pid_t /*pid_process*/,
unsigned int /*id*/, char * /*name*/);
running_process_t *get_the_unset_state(running_process_t * /*node*/);
running_process_t *get_process_from_pid(running_process_t * /*node*/,
pid_t /*pid*/);
void display_process(running_process_t /*node*/);

// Free -------------------------
void free_a_running_process(running_process_t ** /*node*/);
void free_all_running_process(running_process_t ** /*node*/);

#endif
