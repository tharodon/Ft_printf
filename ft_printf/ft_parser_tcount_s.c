#include "ft_printf.h"
int ft_parser_tcount_s(const char *s, va_list arg, t_ps *params, int i)//НАПИСАТЬ ПРАВИЛЬНЫЕ УСЛОВИЯ А ТО НЕ РАБОТАЕТ НОРМАЛЬНО
{
	while (s[i] == '0' || s[i] == '-')
	{
		if (s[i] == '0')
			params->zero_n = 1;
		if (s[i] == '-')
		{
			params->min_n = 1;
			params->zero_n = 0;
			break ;
		}
		i++;
	}
	while (s[i] == '0' || s[i] == '-' || s[i] == '*')
		i++;
	params->zvet = va_arg(arg, int);
	if (s[i] == 'd' || s[i] == 'i')
	{
		params->minus = 0;
		params->d = (long)va_arg(arg, int);
		if ((int)params->d == 0 && params->zvet == 0)
		{
			if (params->zves < 0)
				params->zves *= -1;
			ft_flag_s(params);
			return (i);
		}
		if (params->d < 0)
		{
			params->d *= -1; //ОБРАТИ ВНИМАНИЕ!!! Возможно тут бабахнется из-за макимального int
			params->minus = 1;
		}
		if (params->zero_n == 1 || params->min_n == 1)
		{
			 if (params->minus == 1)
				params->d *= -1;
			if (params->zvet < 0)
				params->zves = (params->zvet * -1) - ft_lennbr((int)params->d);
			else
				params->zves = params->zvet - ft_lennbr((int)params->d);
			ft_putstr_fd(ft_itoa(params->d), params);
			ft_flag_s(params);
			ft_struct_zero(params);
			return (i);
		}
		if (params->zves < 0 && params->zvet < 0)
		{
			if (params->minus == 1)
				params->d *= -1;
			params->zves = (params->zves * -1) - ft_lennbr(params->d);
			ft_putstr_fd(ft_itoa(params->d), params);
			ft_flag_s(params);
			ft_struct_zero(params);
			return (i);
		}
		if (params->zves < 0)
		{
			params->zves = params->zves * -1;
			params->mzves = 1;
			ft_flag_minus(params);
			ft_struct_zero(params);
			return (i);
		}
		if (params->zvet < 0 && params->zero == 1)//Если стоит флаг ноль перед шириной
		{
			if (params->minus == 1)
				params->d *= -1;
			params->zvet = params->zves - ft_lennbr((int)params->d);
			ft_flag_t(params);
			ft_putstr_fd(ft_itoa(params->d), params);
			ft_struct_zero(params);
			return (i);
		}
		if (params->zvet < 0 && params->zero == 0)
		{
			if (params->minus == 1)
				params->d *= -1;
			params->zves -= ft_lennbr((int)params->d);
			ft_flag_s(params);
			ft_putstr_fd(ft_itoa(params->d), params);
			ft_struct_zero(params);
			return (i);
		}
//		params->zvet = params->zvet - ft_lennbr(params->d);
		ft_flag_s_t(params);
		ft_putstr_fd(ft_itoa(params->d), params);
		ft_struct_zero(params);
		return (i);
	}
	if (s[i] == 'u')
	{
		params->u = (unsigned int)va_arg(arg, unsigned int);
		if (params->zero_n == 1 || params->min_n == 1)
		{
			if (params->zvet < 0)
				params->zves = (params->zvet * -1) - ft_lennbr_unsigned(params->u);
			else
				params->zves = params->zvet - ft_lennbr_unsigned(params->u);
			params->len += ft_lennbr_unsigned(params->u);
			ft_putnbr_unsigned(params->u);
			ft_flag_s(params);
			ft_struct_zero(params);
			return (i);
		}
		if (params->zves < 0 && params->zvet < 0)
		{
			params->zves = (params->zves * -1) - ft_lennbr_unsigned(params->u);
			params->len += ft_lennbr_unsigned(params->u);
			ft_putnbr_unsigned(params->u);
			ft_flag_s(params);
			ft_struct_zero(params);
			return (i);
		}
		if (params->zvet < 0 && params->zero == 1)//Если стоит флаг ноль перед шириной
		{
			params->zvet = params->zves - ft_lennbr_unsigned(params->u);
			ft_flag_t(params);
			params->len += ft_lennbr_unsigned(params->u);
			ft_putnbr_unsigned(params->u);
			ft_struct_zero(params);
			return (i);
		}
		if (params->zvet < 0 && params->zero_n == 0)
		{
			params->zves = params->zves - ft_lennbr_unsigned(params->u);
			ft_flag_s(params);
			params->len += ft_lennbr_unsigned(params->u);
			ft_putnbr_unsigned(params->u);
			ft_struct_zero(params);
			return (i);
		}
		if (params->zves < 0)
		{
			params->zves = params->zves * -1;
			params->mzves = 1;
			ft_flag_minus_unsigned(params);
			ft_struct_zero(params);
			return (i);
		}
//		params->zvet = params->zvet - ft_lennbr_unsigned(params->u);
		ft_flag_s_t_unsigned(params);
		params->len += ft_lennbr_unsigned(params->u);
		ft_putnbr_unsigned(params->u);
		ft_struct_zero(params);
		return (i);
	}
	if (s[i] == 's')
	{
		params->src = va_arg(arg, char *);
		if (!params->src)
			params->src = "(null)";
		if (params->zvet < 0)
		{
			if (params->zves < 0 || params->min == 1)
			{
				if (params->min == 1 && params->zves > 0)//Больше или равна?????
					params->zves -= ft_strlen(params->src);
				else
					params->zves = (params->zves * -1) - ft_strlen(params->src);
				ft_putstr_fd(params->src, params);
				ft_flag_s(params);
				ft_struct_zero(params);
				return (i);
			}
			params->zves -= (int)ft_strlen(params->src);
			ft_flag_s(params);
			ft_putstr_fd(params->src, params);
//			params->zves = params->zvet * -1;
//			ft_flag_s(s, i, params, arg);
			ft_struct_zero(params);
			return (i);
		}

		else if (params->zvet < (int)ft_strlen(params->src))
		{
			 if (params->zves < 0 || params->min == 1)
			{
				if (params->min == 1 && params->zves > 0)//Больше или равна?????
					params->zves -= params->zvet;
				else
					params->zves = (params->zves * -1) - params->zvet;
				ft_putstr_t(params->src, params);
				ft_flag_s(params);
				ft_struct_zero(params);
				return (i);
			}
			params->zves -= params->zvet;
			ft_flag_s(params);
			ft_putstr_t(params->src, params);
			ft_struct_zero(params);
			return (i);
		}
		else
		{
			if (params->zves < 0)
			{
				params->zves = (params->zves * -1) - ft_strlen(params->src);
				ft_putstr_t(params->src, params);
				ft_flag_s(params);
				ft_struct_zero(params);
				return (i);
			}
			params->zves -= ft_strlen(params->src);
			ft_flag_s(params);
			ft_putstr_t(params->src, params);
		}
		ft_struct_zero(params);
		return (i);
	}
	if (s[i] == 'x')
	{
		params->u = va_arg(arg, unsigned int);
		if (params->u == 0 && params->zvet == 0)
		{
			if (params->zves < 0)
				params->zves *= -1;
			ft_flag_s(params);
			ft_struct_zero(params);
			return (i);
		}
		if (params->zero_n == 1 || params->min_n == 1)
		{
			if (params->zvet < 0)
				params->zves = (params->zvet * -1) - ft_lennbr_hex(params->u);
			else
				params->zves = params->zvet - ft_lennbr_hex(params->u);
			ft_hexal_low((unsigned long long)params->u, params);
			ft_flag_s(params);
			ft_struct_zero(params);
			return (i);
		}
		if (params->zves < 0 && params->zvet < 0)
		{
			params->zves = (params->zves * -1) - ft_lennbr_hex(params->u);
			ft_hexal_low((unsigned long long)params->u, params);
			ft_flag_s(params);
			ft_struct_zero(params);
			return (i);
		}
		if (params->zvet < 0 && params->zero == 1)//Если стоит флаг ноль перед шириной
		{
			params->zvet = params->zves - ft_lennbr_hex(params->u);
			ft_flag_t(params);
			ft_hexal_low((unsigned long long)params->u, params);
			ft_struct_zero(params);
			return (i);
		}
		if (params->zvet < 0 && params->zero == 0)
		{
			params->zves = params->zves - ft_lennbr_unsigned(params->u);
			ft_flag_s(params);
			ft_hexal_low((unsigned long long)params->u, params);
			ft_struct_zero(params);
			return (i);
		}
		if (params->zves < 0)
		{
			params->zves = params->zves * -1;
			params->mzves = 1;
			ft_flag_minhex_l(params);
			ft_struct_zero(params);
			return (i);
		}
		ft_flag_s_t_hex(params);
		ft_hexal_low((unsigned long long)params->u, params);
		ft_struct_zero(params);
		return (i);
	}
	if (s[i] == 'X')
	{
		params->u = va_arg(arg, unsigned int);
		if (params->u == 0 && params->zvet == 0)
		{
			if (params->zves < 0)
				params->zves *= -1;
			ft_flag_s(params);
			ft_struct_zero(params);
			return (i);
		}
		if (params->zero_n == 1 || params->min_n == 1)
		{
			if (params->zvet < 0)
				params->zves = (params->zvet * -1) - ft_lennbr_hex(params->u);
			else
				params->zves = params->zvet - ft_lennbr_hex(params->u);
			ft_hexal_up((unsigned long long)params->u, params);
			ft_flag_s(params);
			ft_struct_zero(params);
			return (i);
		}
		if (params->zves < 0 && params->zvet < 0)
		{
			params->zves = (params->zves * -1) - ft_lennbr_hex(params->u);
			ft_hexal_up((unsigned long long)params->u, params);
			ft_flag_s(params);
			ft_struct_zero(params);
			return (i);
		}
		if (params->zvet < 0 && params->zero == 1)//Если стоит флаг ноль перед шириной
		{
			params->zvet = params->zves - ft_lennbr_hex(params->u);
			ft_flag_t(params);
			ft_hexal_up((unsigned long long)params->u, params);
			ft_struct_zero(params);
			return (i);
		}
		if (params->zvet < 0 && params->zero == 0)
		{
			params->zves = params->zves - ft_lennbr_hex(params->u);
			ft_flag_s(params);
			ft_hexal_up((unsigned long long)params->u, params);
			ft_struct_zero(params);
			return (i);
		}
		if (params->zves < 0)
		{
			params->zves = params->zves * -1;
			params->mzves = 1;
			ft_flag_minhex_up(params);
			ft_struct_zero(params);
			return (i);
		}
		ft_flag_s_t_hex(params);
		ft_hexal_up((unsigned long long)params->u, params);
		ft_struct_zero(params);
		return (i);
	}
	if (s[i] == 'p')
	{
		params->point = va_arg(arg, unsigned long long);
		if (params->point == 0 && params->zvet == 0)
		{
			if (params->zves < 0)
				params->zves *= -1;
			ft_flag_s(params);
			return (i);
		}
		if (params->zero_n == 1 || params->min_n == 1)
		{
			if (params->zvet < 0)
				params->zves = (params->zvet * -1) - ft_lennbr_point(params->point);
			else
				params->zves = params->zvet - ft_lennbr_point(params->point);
			ft_hexal_point((unsigned long long)params->point, params);
			ft_flag_s(params);
			ft_struct_zero(params);
			return (i);
		}
		if (params->zves < 0 && params->zvet < 0)
		{
			params->zves = (params->zves * -1) - ft_lennbr_point(params->point);
			ft_hexal_point((unsigned long long)params->point, params);
			ft_flag_s(params);
			ft_struct_zero(params);
			return (i);
		}
		if (params->zvet < 0 && params->zero == 1)//Если стоит флаг ноль перед шириной
		{
			params->zvet = params->zves - ft_lennbr_point(params->point);
			ft_flag_t(params);
			ft_hexal_point((unsigned long long)params->point, params);
			ft_struct_zero(params);
			return (i);
		}
		if (params->zvet < 0 && params->zero == 0)
		{
			params->zves = params->zves - ft_lennbr_point(params->point);
			ft_flag_s(params);
			ft_hexal_point((unsigned long long)params->point, params);
			ft_struct_zero(params);
			return (i);
		}
		if (params->zves < 0)
		{
			params->zves = params->zves * -1;
			params->mzves = 1;
			ft_flag_minhex_point(params);
			ft_struct_zero(params);
			return (i);
		}
		ft_flag_s_t_point(params);
		ft_hexal_point((unsigned long long)params->point, params);
		ft_struct_zero(params);
		return (i);
	}
	ft_struct_zero(params);
	return (i);
}