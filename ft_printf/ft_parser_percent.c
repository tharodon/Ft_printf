#include "ft_printf.h"
int		ft_parser_percent(const char *s, t_ps *params, int i)
{
	if (s[i] == '%')
	{
		write(1, "%", 1);
		params->len++;
	}
	if ((s[i] >= '0' && s[i] <= '9') || s[i] == '-')
	{
	    while (s[i] == '0' || s[i] == '-')
	        i++;
		params->zves = ft_atoi(&s[i]);
		if (params->zves < 0)
			params->zves *= -1;
		params->zves--;
		while (s[i] != '%' && s[i] != '\0')
			i++;
		if (params->minus == 1)
		{
			write(1, "%", 1);
			params->len++;
			ft_flag_s(params);
			ft_struct_zero(params);
			return (i);
		}
		if (params->zero == 1)
		{
			params->zvet = params->zves;
			ft_flag_t(params);
			write(1, "%", 1);
			params->len++;
			return (i);
		}
		ft_flag_s(params);
		write(1, "%", 1);
		params->len++;
		ft_struct_zero(params);
		return (i);
	}
	ft_struct_zero(params);
	return (i);
}

int		ft_parser_wrong_percent(const char *s, t_ps *params, int i)
{
	params->zves = ft_atoi(&s[i]);
	while(params->zves >= 0)
	{
		ft_putstr_fd(" ", params);
		params->zves--;
	}
	return (i);
}