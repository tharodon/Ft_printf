#include "ft_printf.h"
int	ft_parser_count_s(const char *s, va_list arg, t_ps *params, int i)
{
	if (s[i] == 'd' || s[i] == 'i')
		return (ft_input_dcs(arg, params, i));
	if (s[i] == 'c')
		return (ft_input_ccs(arg, params, i));
	if (s[i] == 'u')
		return (ft_input_ucs(arg, params, i));
	if (s[i] == 's')
		return (ft_input_scs(arg, params, i));
	if (s[i] == 'x')
		return (ft_input_xlowcs(arg, params, i));
	if (s[i] == 'X')
		return (ft_input_xupcs(arg, params, i));
	if (s[i] == 'p')
		return (ft_input_pcs(arg, params, i));
	ft_struct_zero(params);
	return (i);
}
