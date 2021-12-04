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



static void	put_hex_fd(size_t n, char *base, int fd, int *count)
{
    if (n >= 16)
        put_hex_fd(n / 16, base, fd, count);
    ft_putchar_fd(base[n % 16], fd);
    (*count)++;
}

int	put_pointer(void *pointer, int *count)
{
    count = 0;
    ft_putstr_fd("0x", 1);
    put_hex_fd(*(size_t *)pointer, "0123456789abcdef", 1, count);
    return (2);
}

void	put_hex(unsigned int n, int *count, char c)
{
    char	*base;

    if (c == 'x')
        base = "0123456789abcdef";
    else
        base = "0123456789ABCDEF";
    put_hex_fd(n, base, 1, count);
}
