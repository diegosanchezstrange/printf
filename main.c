#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	char			*c = "hola";

	printf("--%p--\n", (void *)-1);
	ft_printf("--%p--\n", (unsigned long)-1);
	printf("--%p--\n", c);
	ft_printf("--%p--\n", c);
	//printf("\nc : %d", c);

	return (0);
}
