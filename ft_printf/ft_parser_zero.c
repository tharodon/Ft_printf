#include "ft_printf.h"
int ft_parser_zero(const char *s, va_list arg, t_ps *params, int i)
{
	char *r;
	int c;

	c = i;
	while (s[i] == '0' || s[i] == '-')
	{
		if (s[i] == '0')
			params->zero = 1;
		if (s[i] == '-')
		{
			params->min = 1;
			params->zero = 0;
			break ;
		}
		i++;
	}
	while (s[i] && (s[i] == '0' || s[i] == '-'))
		i++;
	r = ft_strchr("dxXiscpu.", s[i]);
	if (r && (s[i - 1] == '0' || s[i - 1] == '-'))
	{
		i = ft_parser_count(s, arg, params, c);
		return (i);
	}
	if (s[i] >= '1' && s[i] <= '9')
	{
		i = ft_parser_count(s, arg, params, c);
		return (i);
	}
	if (s[i] == '*' && s[i + 1] == '.' && s[i + 2] == '*')
	{
		i = ft_parser_s_t(s, arg, params, i);
	}
	else if (s[i] == '*' && s[i + 2] != '*')
	{
		i = ft_parser_s(s, arg, params, i);
	}
	else if (s[i] == '.')
	{
		i = ft_parser_t(s, arg, params, i);
	}
	return (i);
}