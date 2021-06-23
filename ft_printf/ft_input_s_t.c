#include "ft_printf.h"
int	ft_input_dst (va_list arg, t_ps *params, int i)
{
	params->d = (long)va_arg(arg, int); // ! был int
	if ((int)params->d == 0 && params->zvet == 0)
	{
		if (params->zves < 0)
			params->zves *= -1;
		ft_flag_s(params);
		return (i + 3);
	}
	if ((int)params->d < 0)
	{
		if ((int)params->d == -2147483648)
			params->min_val = 1;
		params->d *= -1; //ОБРАТИ ВНИМАНИЕ!!! Возможно тут бабахнется из-за макимального int
		params->minus = 1;
	}
	if (params->zves < 0 && params->zvet < 0)
	{
		if (params->minus == 1 && params->min_val != 1)
			params->d *= -1;
		params->zves = (params->zves * -1) - ft_lennbr(params->d);
		params->min_val = 0;
		ft_putstr_fd(ft_itoa(params->d), params);
		ft_flag_s(params);
		ft_struct_zero(params);
		return (i + 3);
	}
	else if (params->zvet < 0 && params->zero == 1)
	{
		if (params->minus == 1 && params->min_val != 1)
		{
			ft_putstr_fd("-", params);
			params->zvet = params->zves - ft_lennbr(params->d) - 1;
			params->min_val = 0;
			ft_flag_t(params);
			ft_putstr_fd(ft_itoa(params->d), params);
			ft_struct_zero(params);
			return (i + 3);
		}
		params->zvet = params->zves - ft_lennbr(params->d);
		params->min_val = 0;
		ft_flag_t(params);
		ft_putstr_fd(ft_itoa(params->d), params);
		ft_struct_zero(params);
		return (i + 3);
	}
	else if (params->zves < 0 || params->min == 1)
	{
		if (params->zves < 0)
			params->zves = (params->zves * -1);
		params->mzves = 1;
		ft_flag_minus(params);
		ft_struct_zero(params);
		return (i + 3);
	}
	ft_flag_s_t(params);
	ft_putstr_fd(ft_itoa(params->d), params);
	ft_struct_zero(params);
	return (i + 3);
}

int	ft_input_ust (va_list arg, t_ps *params, int i)
{
	params->u = (unsigned int)va_arg(arg, unsigned int);
	if (params->u == 0 && params->zvet == 0)
	{
		if (params->zves < 0)
			params->zves *= -1;
		ft_flag_s(params);
		return (i + 3);
	}
	else if (params->zvet < 0 && params->zero == 1)
	{
		params->zvet = params->zves - ft_lennbr_unsigned(params->u);
		ft_flag_t(params);
		params->len += ft_lennbr_unsigned(params->u);
		ft_putnbr_unsigned(params->u);
		ft_struct_zero(params);
		return (i + 3);
	}
	else if (params->zves < 0 || params->min == 1)
	{
		if (params->zves < 0)
			params->zves = (params->zves * -1);
		params->mzves = 1;
		ft_flag_minus_unsigned(params);
		ft_struct_zero(params);
		return (i + 3);
	}
	ft_flag_s_t_unsigned(params);
	params->len += ft_lennbr_unsigned(params->u);
	ft_putnbr_unsigned(params->u);
	ft_struct_zero(params);
	return (i + 3);
}

int	ft_input_sst (va_list arg, t_ps *params, int i)
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
			return (i + 3);
		}
		params->zves -= ft_strlen(params->src);
		ft_flag_s(params);
		ft_putstr_fd(params->src, params);
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
			return (i + 3);
		}
		params->zves -= params->zvet;
		ft_flag_s(params);
		ft_putstr_t(params->src, params);
		ft_struct_zero(params);
		return (i + 3);
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
			return (i + 3);
		}
		params->zves -= ft_strlen(params->src);
		ft_flag_s(params);
		ft_putstr_t(params->src, params);
	}
	ft_struct_zero(params);
	return (i + 3);
}

int	ft_input_xlowst (va_list arg, t_ps *params, int i)
{
	params->d = (unsigned int)va_arg(arg, int);
	if ((unsigned int)params->d == 0 && params->zvet == 0)
	{
		if (params->zves < 0)
			params->zves *= -1;
		ft_flag_s(params);
		return (i + 3);
	}
	if (params->zves < 0 && params->zvet < 0)
	{
		params->zves = (params->zves * -1) - ft_lennbr_hex(params->d);
		ft_hexal_low((unsigned int)params->d, params);
		ft_flag_s(params);
		ft_struct_zero(params);
		return (i + 3);
	}
	else if (params->zvet < 0 && params->zero == 1)
	{
		params->zvet = params->zves - ft_lennbr_hex(params->d);
		ft_flag_t(params);
		ft_hexal_low((unsigned int)params->d, params);
		ft_struct_zero(params);
		return (i + 3);
	}
	else if (params->zves < 0 || params->min == 1)
	{
		if (params->zves < 0)
			params->zves = (params->zves * -1);
		params->mzves = 1;
		ft_flag_minhex_l(params);
		ft_struct_zero(params);
		return (i + 3);
	}
	ft_flag_s_t_hex(params);
	ft_hexal_low((unsigned int)params->d, params);
	ft_struct_zero(params);
	return (i + 3);
}

int	ft_input_xupst (va_list arg, t_ps *params, int i)
{
	params->d = (unsigned int)va_arg(arg, int);
	if ((unsigned int)params->d == 0 && params->zvet == 0)
	{
		if (params->zves < 0)
			params->zves *= -1;
		ft_flag_s(params);
		return (i + 3);
	}
	if (params->zves < 0 && params->zvet < 0)
	{
		params->zves = (params->zves * -1) - ft_lennbr_hex(params->d);
		ft_hexal_up((unsigned int)params->d, params);
		ft_flag_s(params);
		ft_struct_zero(params);
		return (i + 3);
	}
	else if (params->zvet < 0 && params->zero == 1)
	{
		params->zvet = params->zves - ft_lennbr_hex(params->d);
		ft_flag_t(params);
		ft_hexal_up((unsigned int)params->d, params);
		ft_struct_zero(params);
		return (i + 3);
	}
	else if (params->zves < 0 || params->min == 1)
	{
		if (params->zves < 0)
			params->zves = (params->zves * -1);
		params->mzves = 1;
		ft_flag_minhex_up(params);
		ft_struct_zero(params);
		return (i + 3);
	}
	ft_flag_s_t_hex(params);
	ft_hexal_up((unsigned int)params->d, params);
	ft_struct_zero(params);
	return (i + 3);
}

int	ft_input_pst (va_list arg, t_ps *params, int i)
{
	params->point = va_arg(arg, unsigned long long);
	if (params->point == 0 && params->zvet == 0)
	{
		if (params->zves < 0)
			params->zves *= -1;
		ft_flag_s(params);
		return (i + 3);
	}
	if (params->zves < 0 && params->zvet < 0)
	{
		params->zves = (params->zves * -1) - ft_lennbr_point(params->point);
		ft_hexal_point(params->point, params);
		ft_flag_s(params);
		ft_struct_zero(params);
		return (i + 3);
	}
	else if (params->zvet < 0 && params->zero == 1)
	{
		params->zvet = params->zves - ft_lennbr_point(params->point);
		ft_flag_t(params);
		ft_hexal_point(params->point, params);
		ft_struct_zero(params);
		return (i + 3);
	}
	else if (params->zves < 0 || params->min == 1)
	{
		if (params->zves < 0)
			params->zves = (params->zves * -1);
		params->mzves = 1;
		ft_flag_minhex_point(params);
		ft_struct_zero(params);
		return (i + 3);
	}
	ft_flag_s_t_point(params);
	ft_hexal_point(params->point, params);
	ft_struct_zero(params);
	return (i + 3);
}