#include "ft_printf.h"

int	ft_parser_s_t (const char *s, va_list arg, t_ps *params, int i)
{
	params->zves = va_arg(arg, int);
	params->zvet = va_arg(arg, int);
	if (s[i + 3] == 'd' || s[i + 3] == 'i')
		return (ft_input_dst(arg, params, i));
	if (s[i + 3] == 'u')
		return (ft_input_ust(arg, params, i));
	if (s[i + 3] == 's')
		return (ft_input_sst(arg, params, i));
	if (s[i + 3] == 'x')
		return (ft_input_xlowst(arg, params, i));
	if (s[i + 3] == 'X')
		return (ft_input_xupst(arg, params, i));
	if (s[i + 3] == 'p')
		return (ft_input_pst(arg, params, i));
	ft_struct_zero(params);
	return (i);
}
