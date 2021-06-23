#include "ft_printf.h"

int	ft_lennbr(int i)
{
	int	p;

	p = 0;
	if (i == 0)
		return (1);
	if (i < 0)
	{
		p++;
	}
	while (i)
	{
		i /= 10;
		p++;
	}
	return (p);
}

int	ft_lennbr_unsigned(unsigned int i)
{
	int	p;

	p = 0;
	if (i == 0)
		return (1);
	if (i < 0)
	{
		p++;
	}
	while (i)
	{
		i /= 10;
		p++;
	}
	return (p);
}
