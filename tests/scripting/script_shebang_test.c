/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** Unit tests on script shebang
*/

#include <criterion/criterion.h>
#include "script.h"

Test(script_shebang, shebang_ok)
{
	bool status = check_script_shebang("./tests/scripting/script_test.sh");
	cr_assert_eq(status, true);
}

Test(script_shebang, shebang_ko)
{
	bool status = check_script_shebang("./tests/scripting/\
script_shebang.sh");
	cr_assert_eq(status, false);
}
