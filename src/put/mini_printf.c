/*
** EPITECH PROJECT, 2023
** mini_printf
** File description:
** printf
*/

#include "my.h"

int my_switch(const char *format, int compt, va_list ap, int car)
{
    switch (format[compt]) {
    case 's':
        car += my_putstr(va_arg(ap, char *));
        break;
    case 'c':
        car += my_putchar(va_arg(ap, int));
        break;
    case 'd':
    case 'i':
        car += my_put_nbr(va_arg(ap, int));
        break;
    case '%':
        car += my_putchar('%');
        break;
    }
    return car;
}

int mini_printf(const char *format, ...)
{
    va_list ap;
    int car = 0;
    int compt = 0;

    va_start(ap, format);
    while (format[compt] != '\0') {
        if (format[compt] != '%') {
            car += my_putchar(format[compt]);
            compt++;
        } else {
            compt++;
            car = my_switch(format, compt, ap, car);
            compt++;
        }
    }
    va_end(ap);
    return car;
}
