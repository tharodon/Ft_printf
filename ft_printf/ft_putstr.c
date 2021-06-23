#include "ft_printf.h"
void	ft_putstr_fd(char *s, t_ps *params)
{
	size_t	i;

	i = 0;
	if (params->min_val == 1)
		i++;
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
		params->len++;
	}
}
