/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Check conditional operator
*/

#include "script.h"

static int send_to_operator(shell_t *shell, cond_t *cond, char **words_array)
{
	int status = -1;
	int len = 0;
	ope_t ope_redir[NB_OPE] = {{"==", &op_equal}, {"!=", &op_diff},
		{"<", &op_inf}, {">", &op_sup}, {"<=", &op_inf_eq},
		{">=", &op_sup_eq}};

	for (int i = 0; words_array[i]; i += 1)
		len += 1;
	if (len != 3)
		return (false);
	for (int i = 0; i < NB_OPE; i += 1)
		if (!strcmp(words_array[1], ope_redir[i].ope))
			status = ope_redir[i].redir_comp(shell, cond,
			&(words_array[0]), &(words_array[2]));
	if (status == -1) {
		print_error_syntax(cond);
		return (FAILURE);
	}
	return (status);
}

int check_script_condition(shell_t *shell, cond_t *cond)
{
	char **words_array = cut_line(cond->condition);
	int status = 0;

	if (!words_array)
		return (FAILURE);
	status = send_to_operator(shell, cond, words_array);
	free_array_string(words_array);
	return (status);
}
