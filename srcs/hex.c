#include "../includes/ft_printf.h"
/*
int put_hex(size_t n, char base, int count)
{
    char *basep;

    if (base == 'x')
        basep = "0123456789abcdef";
    else
        basep = "0123456789ABCDEF";
    if (n >= 16)
        put_hex(n / 16, base, count);
    ft_putchar_fd(basep[n % 16], 1);
    count++;
    return (count);
}
*/



static void	put_hex_static(size_t n, char *base, int *count)
{
    if (n >= 16)
        put_hex_static(n / 16, base, count);
    ft_putchar_fd(base[n % 16], 1);
    (*count)++;
}

int	put_pointer(void *pointer, int *count)
{
    ft_putstr_fd("0x", 1);
    put_hex_static((size_t)pointer, "0123456789abcdef", count);
    return (2);
}

/*
void	addyme(void *address, int *counter)
{
    unsigned long int	n;

    n = (unsigned long int)(address);
    ft_putstr_fd("0x", 1);
    *counter = *counter + 2;
    puthex_fd(n, "0123456789abcdef", 1, counter);
}
*/


void	put_hex(unsigned int n, int *count, char c)
{
    char	*base;

    if (c == 'x')
        base = "0123456789abcdef";
    else
        base = "0123456789ABCDEF";
    put_hex_static(n, base, count);
}
