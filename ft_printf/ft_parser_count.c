#include "ft_printf.h"
int	ft_parser_count(const char *s, va_list arg, t_ps *params, int i)//эта функция для выводы ширины и точности указанные вместо звездочек
{
	char	*temp;
	if (s[i] == '0' && !ft_checker(s, i) && params->min == 0)//если перед шириной флаг НОЛЬ
	{
		i = ft_parser_count_t(s, arg, params, i + 1);
		ft_struct_zero(params);
		return (i);
	}
	else if (params->min == 1)
	{
		while (s[i] == '-' || s[i] == '0')
			i++;
		params->zves = ft_atoi(&s[i]) * -1;
	}
	else
		params->zves = ft_atoi(&s[i]);
	while ((s[i] >= '0' && s[i] <= '9') || s[i] == '-')
		i++;
	if (s[i] == '.' && s[i + 1] == '*')
	{
		i = ft_parser_tcount_s(s, arg, params, i + 2);
		ft_struct_zero(params);
		return (i);
	}
	if (ft_checker_tcount(s, i, params))
	{
		i = ft_parser_tcount_s(s, arg, params, i + 1);
		ft_struct_zero(params);
		return (i);
	}
	if (s[i] == '.' && ((s[i + 1] >= '0' && s[i + 1] <= '9') || s[i + 1] == '-'))
		params->zvet = ft_atoi(&s[i + 1]);
	if (ft_strchr(TYPE, s[i]))//тут вызывается функция которая вычисляет какая буква дана и что выводить в случае если дана ТОЛЬКО ШИРИНА
	{
		params->only_s = 1;
		i = ft_parser_count_s(s, arg, params, i);
		ft_struct_zero(params);
		return (i);
	}
	temp = ft_strchr(TYPE, s[i]);
	while (!temp)
	{
		temp = ft_strchr(TYPE, s[i]);
		i++;
	}
	if (*temp == 'd' || *temp == 'i')
	{
		params->d = va_arg(arg, int);
		if (s[i - 2] == '.' && params->d == 0)
		 {
			 if (params->zves < 0)
				params->zves *= -1;
			ft_flag_s(params);
			return (i - 1);
		 }
		if ((params->zves == 0 || params->zvet == 0) && params->d == 0)
		{
//			if (params->zves != 0 && params->zvet == 0 && params->d == 0)
//			{
//				ft_flag_s(params);
//				params->vod = 1;
//				ft_parser(s, arg, params, i - 1);
//				return (i - 1);
//			}
			if (params->zves < 0)
				params->zves *= -1;
			ft_flag_s_t(params);
			 if (params->zves == 0 && params->zvet == 0 && params->d == 0)
				return(i - 1);
			if (params->zvet == 0)
				ft_putstr_fd(" ", params);
			if (params->zves == 0)
				ft_putstr_fd("0", params);
			ft_struct_zero(params);
			return (i - 1);
		}
		if (params->d < 0)
		{
			if (params->d == -2147483648)
				params->min_val = 1;
			params->d *= -1;
			params->minus = 1;
		}
		if (params->zvet < 0)
		{
			if (params->minus == 1)
				params->d *= -1;
			params->zvet = (params->zvet * -1) - ft_lennbr(params->d);
			ft_putstr_fd(ft_itoa(params->d), params);
			params->zves = params->zvet;
			ft_flag_s(params);
			ft_struct_zero(params);
			return (i - 1);
		}
		else if (params->zves < 0)
		{
			params->zves = params->zves * -1;
			params->mzves = 1;
			ft_flag_minus(params);
			ft_struct_zero(params);
			return (i - 1);
		}
		ft_flag_s_t(params);
		ft_putstr_fd(ft_itoa(params->d), params);
		ft_struct_zero(params);
		return (i - 1);
	}
	if (*temp == 'u')
	{
		params->u = (unsigned int)va_arg(arg, unsigned int);
		 if ((params->zves == 0 || params->zvet == 0) && params->u == 0)
		{
			if (params->zves < 0)
				params->zves *= -1;
			ft_flag_s_t_unsigned(params);
			if (params->zvet == 0)
				ft_putstr_fd(" ", params);
			if (params->zves == 0)
				ft_putstr_fd("0", params);
			ft_struct_zero(params);
			return (i - 1);
		}
		if (params->zvet < 0)
		{
			params->zvet = (params->zvet * -1) - ft_lennbr_unsigned(params->u);
			params->len += ft_lennbr_unsigned(params->u);
			ft_putnbr_unsigned(params->u);
			params->zves = params->zvet;
			ft_flag_s(params);
			ft_struct_zero(params);
			return (i - 1);
		}
		else if (params->zves < 0)
		{
			params->zves = params->zves * -1;
			params->mzves = 1;
			ft_flag_minus_unsigned(params);
			ft_struct_zero(params);
			return (i - 1);
		}
		ft_flag_s_t_unsigned(params);
		 params->len += ft_lennbr_unsigned(params->u);
		ft_putnbr_unsigned(params->u);
		ft_struct_zero(params);
		return (i - 1);
	}
	if (*temp == 's')
	{
		params->src = va_arg(arg, char *);
		if (!params->src)
		{
			params->src = "(null)";
		}
		if (params->zvet < 0)
		{
			params->zves = params->zvet * -1;
			ft_flag_s(params);
			ft_struct_zero(params);
			return (i - 1);
		}
		else if (params->zvet < (int)ft_strlen(params->src))
		{
			if (params->zves < 0)
			{
				params->zves = (params->zves * -1) - params->zvet;
				ft_putstr_t(params->src, params);
				ft_flag_s(params);
				ft_struct_zero(params);
				return (i - 1);
			}
			params->zves -= params->zvet;
			ft_flag_s(params);
			ft_putstr_t(params->src, params);
			ft_struct_zero(params);
			return (i - 1);
		}
		else
		{
			if (params->zves < 0)
			{
				params->zves = (params->zves * -1) - ft_strlen(params->src);
				ft_putstr_t(params->src, params);
				ft_flag_s(params);
				ft_struct_zero(params);
				return (i - 1);
			}
			params->zves -= ft_strlen(params->src);
			ft_flag_s(params);
			ft_putstr_t(params->src, params);
		}
		ft_struct_zero(params);
		return (i - 1);
	}
	if (*temp == 'x')
	{
		params->d = (unsigned int)va_arg(arg, int);
		if ((params->zves == 0 || params->zvet == 0) && params->d == 0)
		{
			if (params->zves < 0)
				params->zves *= -1;
			ft_flag_s_t(params);
			if (params->zvet == 0)
				ft_putstr_fd(" ", params);
			if (params->zves == 0)
				ft_putstr_fd("0", params);
			ft_struct_zero(params);
			return (i - 1);
		}
		if (params->zvet < 0)
		{
			params->zvet = (params->zvet * -1) - ft_lennbr_hex(params->d);
			ft_hexal_low(params->d, params);
			params->zves = params->zvet;
			ft_flag_s(params);
			ft_struct_zero(params);
			return (i - 1);
		}
		else if (params->zves < 0)
		{
			params->zves = params->zves * -1;
			params->mzves = 1;
			ft_flag_minhex_l(params);
			ft_struct_zero(params);
			return (i - 1);
		}
		ft_flag_s_t_hex(params);
		ft_hexal_low(params->d, params);
		ft_struct_zero(params);
		return (i - 1);
	}
	if (*temp == 'X')
	{
		params->d = (unsigned int)va_arg(arg, int);
		if ((params->zves == 0 || params->zvet == 0) && params->d == 0)
		{
			if (params->zves < 0)
				params->zves *= -1;
			ft_flag_s_t(params);
			if (params->zvet == 0)
				ft_putstr_fd(" ", params);
			if (params->zves == 0)
				ft_putstr_fd("0", params);
			ft_struct_zero(params);
			return (i - 1);
		}
		if (params->zvet < 0)
		{
			params->zvet = (params->zvet * -1) - ft_lennbr_hex(params->d);
			ft_hexal_up(params->d, params);
			params->zves = params->zvet;
			ft_flag_s(params);
			ft_struct_zero(params);
			return (i - 1);
		}
		else if (params->zves < 0)
		{
			params->zves = params->zves * -1;
			params->mzves = 1;
			ft_flag_minhex_up(params);
			ft_struct_zero(params);
			return (i - 1);
		}
		ft_flag_s_t_hex(params);
		ft_hexal_up(params->d, params);
		ft_struct_zero(params);
		return (i - 1);
	}
	if (*temp == 'p')
	{
		params->point = va_arg(arg, unsigned long);
		if (s[i - 2] == '.' && params->point == 0)
		{
			if (params->zves < 0)
			{
				params->zves = (params->zves * -1) - 2;
				ft_putstr_fd("0x", params);
				ft_flag_s(params);
				return (i - 1);
			}
			params->zves -= 2;
			ft_flag_s(params);
			ft_putstr_fd("0x", params);
			return (i - 1);
		}
		if ((params->zves == 0 || params->zvet == 0) && params->point == 0)
		{
			if (params->zves < 0)
				params->zves *= -1;
			ft_flag_s_t_point(params);
			if (params->zvet == 0)
				ft_putstr_fd(" ", params);
			if (params->zves == 0)
				ft_putstr_fd("0", params);
			ft_struct_zero(params);
			return (i - 1);
		}
		if (params->zvet < 0)
		{
			params->zvet = (params->zvet * -1) - ft_lennbr_point(params->point);
			ft_hexal_point(params->point, params);
			params->zves = params->zvet;
			ft_flag_s(params);
			ft_struct_zero(params);
			return (i - 1);
		}
		else if (params->zves < 0)
		{
			params->zves = params->zves * -1;
			params->mzves = 1;
			ft_flag_minhex_point(params);
			ft_struct_zero(params);
			return (i - 1);
		}
		ft_flag_s_t_point(params);
		ft_hexal_low(params->point, params);
		ft_struct_zero(params);
		return (i - 1);
	}
	ft_struct_zero(params);
	return (i - 1);
}
