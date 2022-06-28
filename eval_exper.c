/*
** EPITECH PROJECT, 2021
** Evalxpr
** File description:
** projet
*/

#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "./include/my.h"

bool is_digit (char c) {
    return ('0' <= c && c <= '9');
}

int parsedigits(char **str)
{
    int nb1 = 0;

    if (is_digit(**str)) {
        while (is_digit(**str)) {
            nb1 = nb1 * 10 + **str - '0';
            *str += 1;
        }
        return nb1;
    }
}

int my_put_nbr(int nb)
{
    if (nb == -2147483648) {
        my_putchar('-');
        my_putchar('2');
        my_put_nbr(147483648);
        return (0);
    }
    if (nb < 0) {
        nb = nb * (-1);
        my_putchar('-');
    }
    if (nb > 9) {
        int c = nb % 10;
        nb = nb / 10;
        my_put_nbr(nb);
        my_putchar(c + 48);
    } else {
        my_putchar(nb + 48);
    }
    return (0);
}

int parse_expression (char **str);

int parse_term (char **str);

int parse_factor (char **str)
{
    int b = 0;

    if (**str == '(' || **str == ')') {
        *str += 1;
        b = parse_expression(str);
        *str += 1;
        return b;
    } else {
        return parsedigits(str);
    }
}

int parse_term (char **str)
{
    int b = parse_factor(str);
    int c;

    while (true) {
        if (**str == '*') {
            *str += 1;
            c = parse_factor(str);
            b *= c;
        }
        else if (**str == '/') {
            *str += 1;
            c = parse_factor(str);
            b = b / c;
        } else {
            break;
        }
    }
    return b;
}

int parse_expression (char **str)
{
    int b = parse_term(str);
    int c;

    while(true){
        if (**str == '-') {
            *str += 1;
            c = parse_term(str);
            b -= c;
        }
        else if (**str == '+') {
            *str += 1;
            c = parse_term(str);
            b += c;
        }
        else {
            break;
        }
    }
    return b;
}

int eval_expr(char const *str)
{
    int a = parse_expression((char**)&str);

    return a;
}

int main(int ac , char **av)
{
    if (ac == 2) {
        my_put_nbr(eval_expr(av[1]));
        my_putchar('\n');
        return (0);
    }
    return (84);
}
