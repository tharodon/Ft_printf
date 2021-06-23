#include "ft_printf.h"

static int	schet (int c)
{
	unsigned int	tmp;

	tmp = 0;
	if (c == 0)
	{
		tmp++;
	}
	if (c < 0)
	{
		c = c * -1;
		tmp++;
	}
	while (c)
	{
		c = c / 10;
		tmp++;
	}
	return (tmp);
}

static char	*otrizatelniy(char *r, unsigned int tmp, int sign, int n)
{
	while (tmp-- > 1)
	{
		r[tmp] = n % 10 * sign + 48;
		n = n / 10;
	}
	return (r);
}

char	*ft_itoa (int n)
{
	unsigned int	tmp;
	int				sign;
	char			*r;

	sign = 1;
	tmp = schet(n);
	r = (char *)malloc(tmp + 1);
	if (r == NULL)
		return (NULL);
	r[tmp] = '\0';
	if (n < 0)
	{
		sign = -1;
		r[0] = 45;
		r = otrizatelniy(r, tmp, sign, n);
		return (r);
	}		
	while (tmp-- > 0)
	{
		r[tmp] = n % 10 * sign + 48;
		n = n / 10;
	}
	return (r);
}
