#include "ft_printf.h"
int ft_checker (const char *s, int i)
{
	char *t;
	char *r;

	// if (params->min == 1)
	// 	return (1);
	t = ft_strchr(TYPE, s[i]);
	r = ft_strchr(".", s[i]);
	while (t == NULL)
	{
		if (r)
			return (1);
		t = ft_strchr(TYPE, s[i]);
		r = ft_strchr(".", s[i]);
		i++;
	}
	return (0);
}

int ft_checker_minus (const char *s, int i)
{
	char *t;
	char *r;

	t = ft_strchr(TYPE, s[i]);
	r = ft_strchr("-", s[i]);
	while (t == NULL)
	{
		if (r)
			return (1);
		t = ft_strchr(TYPE, s[i]);
		r = ft_strchr("-", s[i]);
		i++;
	}
	return (0);
}

int ft_checker_void (const char *s, int i)
{
	char *t;

	t = ft_strchr(TYPE, s[i]);
	if (t)
		return (1);
	// r = ft_strchr(".", s[i]);
	// while (t == NULL)
	// {
	// 	if (t)
	// 		return (1);
	// 	t = ft_strchr(TYPE, s[i]);
	// 	r = ft_strchr(".", s[i]);
	// 	i++;
	// }
	return (0);
}

int ft_checker_percent (const char *s, int i, t_ps *params)
{
	char *r;

	if (s[i] == '%')
		return (1);
	r = ft_strchr("0123456789.-", s[i]);
	while (*r == '0' || *r == '-')
	{
		if(*r == '-')
		{
			params->minus = 1;
			params->zero = 0;
		}
		if(*r == '0' && params->minus == 0)
			params->zero = 1;
		i++;
		r = ft_strchr("0123456789.-", s[i]);
	}
	while (s[i] != '%' && r && s[i] != '\0')
	{
		r = ft_strchr("0123456789.-", s[i]);
		i++;
	}
	if (s[i] == '%')
		return (1);
	ft_struct_zero(params);
	return (0);
}

int ft_checker_wrong_percent (const char *s, int i)
{
	char *r;

	if (s[i] == '\0')
		return (1);
	r = ft_strchr("0123456789.-", s[i]);
	while (r)
	{
		i++;
		r = ft_strchr("0123456789.-", s[i]);
	}
	r = ft_strchr(TYPE, s[i]);
	if (s[i] == '%' || r != NULL || s[i] == '*' || s[i] == '.')
		return (0);
	return (1);
}


int ft_checker_percent_type (const char *s, int i)
{
	char *r;

	if (s[i] == '%')
		return (1);
	r = ft_strchr(TYPE, s[i]);
	while (s[i] && s[i] != '%')
	{
		if (r)
			return (0);
		i++;
		r = ft_strchr(TYPE, s[i]);
	}
	return (1);
}

int ft_checker_percent_null (const char *s, int i)
{
	char *r;

	if (s[i] == '\0')
		return (1);
	r = ft_strchr("scpdiuxX%", s[i]);
	while (!r && s[i] && (!(s[i] >= '0' && s[i] <= '9') || s[i] == '-'))
	{
		r = ft_strchr("scpdiuxX%", s[i]);
		i++;
	}
	if (r)
		return (0);
	if (s[i] == '\0')
		return (1);
	return (0);
}

int ft_checker_zero_st (const char *s, int i)
{
	int t;

	t = 0;
	// char *r;

	// r = ft_strchr("scpdiuxX%.*", s[i]);
	while (s[i] && (s[i] == '0' || s[i] == '-'))
	{
		if (s[i] == '0' || s[i] == '-')
			t++;
		i++;
	}
	if (t == 0)
		return (0);
	if (s[i] == '*' || s[i] == '.')
		return (1);
	return (0);
	
}

int	ft_checker_tcount (const char *s, int i, t_ps *params)
{
	if (s[i] == '.' && (s[i + 1] == '0' || s[i + 1] == '-'))
	{
		i++;
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
		if (s[i] == '*')
			return (1);
	}
	return (0);

}