#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

//ft_extra1.c
int ft_nbrLen(long nbr);
int ft_strlen(const char *str);
int ft_nbrlen(unsigned long value, int base_len);
char *ft_itoa_base(unsigned long value, char *base);

//ft_extra2.c
char *ft_itoa(int n);
int ft_found_u();
int print_string(va_list args);
int print_int(va_list args);
int print_hex(va_list args);
int ft_printf_write(int c, int i);