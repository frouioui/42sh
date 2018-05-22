/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Unit tests on script file
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "script.h"

static void redirect_all_std(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

Test(script_access, access_ok)
{
	bool status = check_script_access("./tests/scripting/script_test.sh");
	cr_assert_eq(status, true);
}

Test(script_access, access_exist_ko, .init = redirect_all_std)
{
	bool status = check_script_access("./script.sh");

	cr_assert_eq(status, false);
	cr_assert_stdout_eq_str("./script.sh: Command not found.\n");
}

Test(script_access, access_exec_ko, .init = redirect_all_std)
{
	bool status = check_script_access("./tests/scripting/script_exec.sh");

	cr_assert_eq(status, false);
	cr_assert_stdout_eq_str("./tests/scripting/script_exec.sh:\
 Permission denied.\n");
}
