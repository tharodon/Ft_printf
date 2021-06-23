#include "ft_printf.h"

int	ft_parser_t (const char *s, va_list arg, t_ps *params, int i)
{
	if (s[i] == '.' && ft_strchr(TYPE, s[i + 1]))
		return (ft_wrong_s(s, arg, params, i));
	if ((s[i + 1] >= '0' && s[i + 1] <= '9') || s[i + 1] == '-')
	{
		i = ft_parser_count_t(s, arg, params, i + 1);
		ft_struct_zero(params);
		return (i);
	}
	if (s[i] && ft_checker_void(s, i + 1))
	{
		params->vod = 1;
		ft_parser(s, arg, params, i + 1);
		ft_struct_zero(params);
		return (i + 1);
	}
	if (s[i] == '.' && s[i + 1] == '*')
	{
		i = ft_way_t(s, arg, params, i);
	}
	ft_struct_zero(params);
	return (i);
}

int	ft_way_t (const char *s, va_list arg, t_ps *params, int i)
{
	params->zvet = va_arg(arg, int);
	if (s[i + 2] == 'd' || s[i + 2] == 'i')
		return (ft_input_dt(arg, params, i));
	if (s[i + 2] == 'u')
		return (ft_input_ut(arg, params, i));
	if (s[i + 2] == 's')
		return (ft_input_st(arg, params, i));
	if (s[i + 2] == 'x')
		return (ft_input_xlowt(arg, params, i));
	if (s[i + 2] == 'X')
		return (ft_input_xupt(arg, params, i));
	if (s[i + 2] == 'p')
		return (ft_input_pt(arg, params, i));
	return (i);
}

int	ft_wrong_s (const char *s, va_list arg, t_ps *params, int i)
{
	params->wrong_s = 1;
	ft_parser(s, arg, params, i + 1);
	ft_struct_zero(params);
	return (i + 1);
}
