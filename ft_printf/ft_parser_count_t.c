#include "ft_printf.h"
int	ft_parser_count_t(const char *s, va_list arg, t_ps *params, int i)
{
	params->zvet += ft_atoi(&s[i]);
	while ((s[i] >= '0' && s[i] <= '9') || s[i] == '-')
		i++;
	if (s[i] == 'd' || s[i] == 'i')
		return (ft_input_dct(arg, params, i));
	if (s[i] == 'u')
		return (ft_input_uct(arg, params, i));
	if (s[i] == 's')
		return (ft_input_sct(arg, params, i));
	if (s[i] == 'x')
		return (ft_input_xlowct(arg, params, i));
	if (s[i] == 'X')
		return (ft_input_xupct(arg, params, i));
	if (s[i] == 'p')
		return (ft_input_pct(arg, params, i));
	ft_struct_zero(params);
	return (i);
}
