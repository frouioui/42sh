/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Include file for the env echec mode
*/

#ifndef ECHEC_H
#define ECHEC_H

#define ENV_SIZE_ECHEC 4
#define PATH_ECHEC "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:"\
		"/sbin:/bin"
#define PATH_HOME "HOME=/home"
#define PWD "PWD=/"
#define USER "USER=anonyme"
#define ENV_ECHEC {PATH_ECHEC, PATH_HOME, PWD, USER}

char **set_env_echec_mode(void);

#endif /* end of include guard: ECHEC_H */
