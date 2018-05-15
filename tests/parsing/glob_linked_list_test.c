/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Unit tests on linked list
*/

#include <criterion/criterion.h>
#include "globbing.h"
#include "mylib.h"

static void free_array(char **array)
{
	if (!array)
		return;
	for (int i = 0; array[i]; i += 1)
		free(array[i]);
	free(array);
}

Test(linked_list, built_free)
{
	args_list_t *list = NULL;
	args_list_t *tmp = NULL;
	char **array = cut_line("ls *s lib");

	list = built_list(array);
	tmp = list;
	for (int i = 0; array[i]; i += 1, tmp = tmp->next)
		cr_assert_str_eq(tmp->arg, array[i]);
	free_args_list(list);
	free_array(array);
}

Test(linked_list, insert_link)
{
	args_list_t *list = NULL;
	args_list_t *tmp = NULL;
	char **array = cut_line("ls *s lib");
	char **wait = cut_line("ls bonus tests lib");

	list = built_list(array);
	tmp = list;
	while (tmp)
		search_glob_args(list, &tmp);
	tmp = list;
	for (int i = 0; wait[i]; i += 1, tmp = tmp->next)
		cr_assert_str_eq(tmp->arg, wait[i]);
	free_args_list(list);
	free_array(array);
	free_array(wait);
}
