#include "ft_printf.h"
int ft_parser_scount_t(const char *s, va_list arg, t_ps *params, int i)
{
	char *temp;

	params->zves = va_arg(arg, int);
	while (s[i + 2] == '0' || s[i + 2] == '-')
	{
		if (s[i + 2] == '0')
			params->zero_n = 1;
		if (s[i + 2] == '-')
		{
			params->min_n = 1;
			params->zero_n = 0;
			break ;
		}
		i++;
	}
	while (s[i + 2] == '0' || s[i + 2] == '-')
		i++;
	params->zvet = ft_atoi(&s[i + 2]);
	temp = ft_strchr(TYPE, s[i]);
	while (!temp)
	{
		temp = ft_strchr(TYPE, s[i]);
		i++;
	}
	if (*temp == 'd' || *temp == 'i')
	{
	//	 params->d = (long)va_arg(arg, int);
	//	 if ((int)params->d == 0 && params->zvet == 0)
	//	 {
	//		 if (params->zves < 0)
	//			 params->zves *= -1;
	//		 ft_flag_s(params);
	//		 return (i - 1);
	//	 }
	//	 if ((int)params->d < 0)
	//	 {
	//		 params->d *= -1;
	//		 params->minus = 1;
	//	 }
	//	 if ((params->zves < 0 && params->zvet < 0) || (params->zves < 0 && params->min_n == 1))
	//	 {
	//		 if (params->minus == 1)
	//			 params->d *= -1;
	//		 if (params->zvet < 0)
	//			 params->zves = (params->zvet * -1) - ft_lennbr((int)params->d);
	//		 else
	//			 params->zves = params->zvet - ft_lennbr((int)params->d);
	//		 ft_putstr_fd(ft_itoa(params->d), params);
	//		 ft_flag_s(params);
	//		 ft_struct_zero(params);
	//		 return (i - 1);
	//	 }
	//	 if (params->zvet < 0 || params->min_n == 1)
	//	 {
	//		 if (params->minus == 1)
	//			 params->d *= -1;
	//		 if (params->zvet < 0)
	//			 params->zves = (params->zvet * -1) - ft_lennbr((int)params->d);
	//		 else
	//			 params->zves = params->zvet - ft_lennbr((int)params->d);
	//		 // params->mzves = 1;
	//		 ft_putstr_fd(ft_itoa(params->d), params);
	//		 ft_flag_s(params);
	//		 ft_struct_zero(params);
	//		 return (i - 1);
	//	 }
	//	 if (params->zves < 0 || params->zero == 1)
	//	 {
	//		 if (params->zves < 0)
	//			 params->zves = params->zves * -1;
	//		 params->mzves = 1;
	//		 ft_flag_minus(params);
	//		 ft_struct_zero(params);
	//		 return (i - 1);
	//	 }
	//	 ft_flag_s_t(params);
	//	 ft_putstr_fd(ft_itoa(params->d), params);
	//	 ft_struct_zero(params);
	//	 return (i - 1);
	// }
		params->d = (long)va_arg(arg, int);
		if ((int)params->d == 0 && params->zvet == 0)
		{
			if (params->zves < 0)
				params->zves *= -1;
			ft_flag_s(params);
			return (i - 1);
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
			return (i - 1);
		}
		if (params->zves < 0 && params->zvet < 0)
		{
			if (params->minus == 1)
				params->d *= -1;
			params->zves = (params->zves * -1) - ft_lennbr(params->d);
			ft_putstr_fd(ft_itoa(params->d), params);
			ft_flag_s(params);
			ft_struct_zero(params);
			return (i - 1);
		}
		if (params->zves < 0)
		{
			params->zves = params->zves * -1;
			params->mzves = 1;
			ft_flag_minus(params);
			ft_struct_zero(params);
			return (i - 1);
		}
		if (params->zvet < 0 && params->zero == 1)//Если стоит флаг ноль перед шириной
		{
			if (params->minus == 1)
				params->d *= -1;
			params->zvet = params->zves - ft_lennbr((int)params->d);
			ft_flag_t(params);
			ft_putstr_fd(ft_itoa(params->d), params);
			ft_struct_zero(params);
			return (i - 1);
		}
		if (params->zvet < 0 && params->zero == 0)
		{
			if (params->minus == 1)
				params->d *= -1;
			params->zves -= ft_lennbr((int)params->d);
			ft_flag_s(params);
			ft_putstr_fd(ft_itoa(params->d), params);
			ft_struct_zero(params);
			return (i - 1);
		}
//		params->zvet = params->zvet - ft_lennbr(params->d);
		ft_flag_s_t(params);
		ft_putstr_fd(ft_itoa(params->d), params);
		ft_struct_zero(params);
		return (i - 1);
	}
	// if (*temp == 'u')
	// {
	//	 params->u = (unsigned int)va_arg(arg, unsigned int);
	//	 if ((params->zves < 0 && params->zvet < 0) || (params->zves < 0 && params->min_n == 1))
	//	 {
	//		 if (params->zvet < 0)
	//			 params->zves = (params->zvet * -1) - ft_lennbr_unsigned(params->u);
	//		 else
	//			 params->zves = params->zvet - ft_lennbr_unsigned(params->u);
	//		 params->len += ft_lennbr_unsigned(params->u);
	//		 ft_putnbr_unsigned(params->u);
	//		 ft_flag_s(params);
	//		 ft_struct_zero(params);
	//		 return (i - 1);
	//	 }
	//	 if (params->zvet < 0 || params->min_n == 1)
	//	 {
	//		 if (params->zvet < 0)
	//			 params->zves = (params->zvet * -1) - ft_lennbr_unsigned(params->u);
	//		 else
	//			 params->zves = params->zvet - ft_lennbr_unsigned(params->u);
	//		 params->len += ft_lennbr_unsigned(params->u);
	//		 ft_putnbr_unsigned(params->u);
	//		 ft_flag_s(params);
	//		 ft_struct_zero(params);
	//		 return (i - 1);
	//	 }
	//	 if (params->zves < 0)
	//	 {
	//		 params->zves = params->zves * -1;
	//		 params->mzves = 1;
	//		 ft_flag_minus_unsigned(params);
	//		 ft_struct_zero(params);
	//		 return (i - 1);
	//	 }
	//	 ft_flag_s_t(params);
	//	 params->len += ft_lennbr_unsigned(params->u);
	//	 ft_putnbr_unsigned(params->u);
	//	 ft_struct_zero(params);
	//	 return (i - 1);
	// }
	if (*temp == 'u')
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
			return (i - 1);
		}
		if (params->zves < 0 && params->zvet < 0)
		{
			params->zves = (params->zves * -1) - ft_lennbr_unsigned(params->u);
			params->len += ft_lennbr_unsigned(params->u);
			ft_putnbr_unsigned(params->u);
			ft_flag_s(params);
			ft_struct_zero(params);
			return (i - 1);
		}
		if (params->zvet < 0 && params->zero == 1)//Если стоит флаг ноль перед шириной
		{
			params->zvet = params->zves - ft_lennbr_unsigned(params->u);
			ft_flag_t(params);
			params->len += ft_lennbr_unsigned(params->u);
			ft_putnbr_unsigned(params->u);
			ft_struct_zero(params);
			return (i - 1);
		}
		if (params->zvet < 0 && params->zero_n == 0)
		{
			params->zves = params->zves - ft_lennbr_unsigned(params->u);
			ft_flag_s(params);
			params->len += ft_lennbr_unsigned(params->u);
			ft_putnbr_unsigned(params->u);
			ft_struct_zero(params);
			return (i - 1);
		}
		if (params->zves < 0)
		{
			params->zves = params->zves * -1;
			params->mzves = 1;
			ft_flag_minus_unsigned(params);
			ft_struct_zero(params);
			return (i - 1);
		}
//		params->zvet = params->zvet - ft_lennbr_unsigned(params->u);
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
			params->src = "(null)";
		if (params->zvet < 0)
		{
			params->zves = params->zvet * -1;
			ft_flag_s(params);
			ft_struct_zero(params);
			return (i - 1);
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
			 if (params->zves < 0 || params->min == 1)
			{
				if (params->min == 1 && params->zves > 0)//Больше или равна?????
					params->zves -= ft_strlen(params->src);
				else
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
		if ((params->zves < 0 && params->zvet < 0) || (params->zves < 0 && params->min_n == 1))
		{
			if (params->zvet < 0)
				params->zves = (params->zvet * -1) - ft_lennbr_hex((unsigned int)params->d);
			else
				params->zves = params->zvet - ft_lennbr_hex((unsigned int)params->d);
			ft_hexal_low((unsigned long long)params->u, params);
			ft_flag_s(params);
			ft_struct_zero(params);
			return (i - 1);
		}
		if (params->zvet < 0 || params->min_n == 1)
		{
			if (params->zvet < 0)
				params->zves = (params->zvet * -1) - ft_lennbr_hex((unsigned int)params->d);
			else
				params->zves = params->zvet - ft_lennbr_hex((unsigned int)params->d);
			ft_hexal_low((unsigned long long)params->d, params);
			ft_flag_s(params);
			ft_struct_zero(params);
			return (i - 1);
		}
		if (params->zves < 0)
		{
			params->zves = params->zves * -1;
			params->mzves = 1;
			ft_flag_minhex_l(params);
			ft_struct_zero(params);
			return (i - 1);
		}
		ft_flag_s_t_hex(params);
		ft_hexal_low((unsigned long long)params->d, params);
		ft_struct_zero(params);
		return (i - 1);
	}
	if (*temp == 'X')
	{
		params->d = (unsigned int)va_arg(arg, int);
		if ((params->zves < 0 && params->zvet < 0) || (params->zves < 0 && params->min_n == 1))
		{
			if (params->zvet < 0)
				params->zves = (params->zvet * -1) - ft_lennbr_hex(params->d);
			else
				params->zves = params->zvet - ft_lennbr_hex(params->d);
			ft_hexal_up((unsigned long long)params->d, params);
			ft_flag_s(params);
			ft_struct_zero(params);
			return (i - 1);
		}
		if (params->zvet < 0 || params->min_n == 1)
		{
			if (params->zvet < 0)
				params->zves = (params->zvet * -1) - ft_lennbr_hex((unsigned int)params->d);
			else
				params->zves = params->zvet - ft_lennbr_hex((unsigned int)params->d);
			ft_hexal_up((unsigned long long)params->u, params);
			ft_flag_s(params);
			ft_struct_zero(params);
			return (i - 1);
		}
		if (params->zves < 0)
		{
			params->zves = params->zves * -1;
			params->mzves = 1;
			ft_flag_minhex_up(params);
			ft_struct_zero(params);
			return (i - 1);
		}
		ft_flag_s_t_hex(params);
		ft_hexal_up((unsigned long long)params->d, params);
		ft_struct_zero(params);
		return (i - 1);
	}
	if (*temp == 'p')
	{
		params->point = va_arg(arg, unsigned long long);
		if ((params->zves < 0 && params->zvet < 0) || (params->zves < 0 && params->min_n == 1))
		{
			if (params->zvet < 0)
				params->zves = (params->zvet * -1) - ft_lennbr_point(params->point);
			else
				params->zves = params->zvet - ft_lennbr_point(params->point);
			ft_hexal_point((unsigned long long)params->point, params);
			ft_flag_s(params);
			ft_struct_zero(params);
			return (i - 1);
		}
		if (params->zvet < 0 || params->min_n == 1)
		{
			if (params->zvet < 0)
				params->zves = (params->zvet * -1) - ft_lennbr_point(params->point);
			else
				params->zves = params->zvet - ft_lennbr_point(params->u);
			ft_hexal_point((unsigned long long)params->point, params);
			ft_flag_s(params);
			ft_struct_zero(params);
			return (i - 1);
		}
		if (params->zves < 0)
		{
			params->zves = params->zves * -1;
			params->mzves = 1;
			ft_flag_minhex_point(params);
			ft_struct_zero(params);
			return (i - 1);
		}
		ft_flag_s_t_point(params);
		ft_hexal_point((unsigned long long)params->point, params);
		ft_struct_zero(params);
		return (i - 1);
	}
	ft_struct_zero(params);
	return (i);
}