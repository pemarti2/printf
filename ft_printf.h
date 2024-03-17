#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "Libft/libft.h"

//ft_extra1.c
int ft_nbrLen(long nbr);
int ft_nbrlen(unsigned long value, int base_len);
char *ft_itoa_base(unsigned long value, char *base);

//ft_extra2.c
int print_string(va_list args);
int print_int(va_list args);
int print_hex(va_list args, char c);
int ft_printf_write(int c, int i);