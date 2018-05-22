/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Test file of the initialisation_backup function
*/

#include <criterion/criterion.h>
#include "shell.h"
#include "echec.h"
#include "mylib.h"

Test(initialisation_backup_1, check_value)
{
	backup_t *backup = NULL;
	char **env = malloc(sizeof(char *) * (5));
	char str[4][17] = {"PATH=/bin", "USER=pflorent", "HOME=/home",
		"PWD=/home/marvin"};

	for (int i = 0; i < 4; i++) {
		env[i] = malloc(sizeof(char) * my_strlen(str[i]));
		env[i] = my_strcpy(env[i], str[i]);
	}
	env[4] = NULL;
	backup = initialisation_backup(env);
	cr_assert_str_eq(backup->path, "/bin");
	cr_assert_str_eq(backup->current_pwd, "/home/marvin");
	cr_assert_str_eq(backup->user, "pflorent");
	cr_assert_str_eq(backup->home, "/home");
}

Test(initialisation_backup_2, check_value)
{
	backup_t *backup = NULL;
	char **env = malloc(sizeof(char *) * (5));
	char str[4][41] = {"PATH=/usr/bin:/bin", "USER=jean_micho989",
	"HOME=/home/pflorent", "PWD=/home/marvin/delivery/user/toto/PSU"};

	for (int i = 0; i < 4; i++) {
		env[i] = malloc(sizeof(char) * my_strlen(str[i]));
		env[i] = my_strcpy(env[i], str[i]);
	}
	env[4] = NULL;
	backup = initialisation_backup(env);
	cr_assert_str_eq(backup->path, "/usr/bin:/bin");
	cr_assert_str_eq(backup->current_pwd, "/home/marvin/delivery/user"\
		"/toto/PSU");
	cr_assert_str_eq(backup->user, "jean_micho989");
	cr_assert_str_eq(backup->home, "/home/pflorent");
}

Test(initialisation_backup_3, check_default_backup_mode)
{
	backup_t *backup = NULL;
	char **env = malloc(sizeof(char *) * (5));
	char str[3][20] = {"TOTO=", "SALUT=/toto", "COOL=looc"};

	for (int i = 0; i < 3; i++) {
		env[i] = malloc(sizeof(char) * my_strlen(str[i]));
		env[i] = my_strcpy(env[i], str[i]);
	}
	env[3] = NULL;
	backup = initialisation_backup(env);
	cr_assert_str_eq(backup->path, PATH_ECHEC);
	cr_assert_str_eq(backup->current_pwd, PWD);
	cr_assert_str_eq(backup->user, USER);
	cr_assert_str_eq(backup->home, PATH_HOME);
}
