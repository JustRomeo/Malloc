/*
** EPITECH PROJECT, 2019
** Minishell 2
** File description:
** Unit Test for project
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "prototype.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(asserts, string)
{
    cr_assert_str_empty("");
    cr_assert_str_not_empty("foo");
    cr_assert_str_eq("hello", "hello");
    cr_assert_str_neq("hello", "olleh");
    cr_assert_str_gt("hello", "hell");
    cr_assert_str_geq("hello", "hell");
    cr_assert_str_geq("hello", "hello");
    cr_assert_str_lt("hell", "hello");
    cr_assert_str_leq("hell", "hello");
    cr_assert_str_leq("hello", "hello");
}

Test(return_v1, simple_string, .init = redirect_all_std)
{
    int y = 0;
    int result = value_r(y);

    cr_expect_eq(result, 0);
}
