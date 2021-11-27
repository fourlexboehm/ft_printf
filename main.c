#include "includes/ft_printf.h"
int main ()
{
//	ft_printf("test\n");
//	ft_printf("test number: %d", -9341520);
	ft_printf("\ntest char: %c", 'f');
	ft_printf("\ntest unsigned int: %u", 28300033);
	ft_printf("\ntest string: %s", "I'm a string");

	ft_printf("\n\nMultitest Char: %c\n Int: %i\n String: %s", 'y', 42, "I'm also a string");
	ft_printf("\n");
}
