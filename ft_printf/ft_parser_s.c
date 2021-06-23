#include "ft_printf.h"

int	ft_parser_s (const char *s, va_list arg, t_ps *params, int i)
{
	if (s[i] == '*' && s[i + 1] == '.')
	{
		i = ft_parser_scount_t(s, arg, params, i);
		ft_struct_zero(params);
		return (i);
	}
	if (s[i] == '*' && s[i + 1] != '.')
	{
		i = ft_way_s(s, arg, params, i);
	}
	ft_struct_zero(params);
	return (i);
}

int	ft_way_s (const char *s, va_list arg, t_ps *params, int i)
{
	params->zves = va_arg(arg, int);
	if (s[i + 1] == 'd' || s[i + 1] == 'i')
		return (ft_input_ds(arg, params, i));
	if (s[i + 1] == 'c')
		return (ft_input_cs(arg, params, i));
	if (s[i + 1] == 'u')
		return (ft_input_us(arg, params, i));
	if (s[i + 1] == 's')
		return (ft_input_ss(arg, params, i));
	if (s[i + 1] == 'x')
		return (ft_input_xlows(arg, params, i));
	if (s[i + 1] == 'X')
		return (ft_input_xups(arg, params, i));
	if (s[i + 1] == 'p')
		return (ft_input_ps(arg, params, i));
	return (i);
}
