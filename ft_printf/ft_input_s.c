#include "ft_printf.h"
int	ft_input_ds (va_list arg, t_ps *params, int i)
{
	params->d = (long)va_arg(arg, int);
	if (params->zero == 1 && params->zves > 0)
	{
		if ((int)params->d < 0)
		{
			if ((int)params->d == -2147483648)
				params->min_val = 1;
			params->d *= -1;
			params->len += write(1, "-", 1);
			params->zvet--;
		}
		params->zvet += params->zves - ft_lennbr(params->d);
		ft_flag_t(params);
		ft_putstr_fd(ft_itoa(params->d), params);
		ft_struct_zero(params);
		return (i + 1);
	}
	if (params->zves < 0 || params->min == 1)
	{
		if (params->zves < 0)
			params->zves = (params->zves * -1) - ft_lennbr(params->d);
		else
			params->zves -= ft_lennbr(params->d);
		ft_putstr_fd(ft_itoa(params->d), params);
		ft_flag_s(params);
		ft_struct_zero(params);
		return (i + 1);
	}
	params->zves = params->zves - ft_lennbr(params->d);
	ft_flag_s(params);
	ft_putstr_fd(ft_itoa(params->d), params);
	ft_struct_zero(params);
	return (i + 1);
}

int	ft_input_cs (va_list arg, t_ps *params, int i)
{
	params->c = va_arg(arg, int);
	if (params->zves < 0 || params->min == 1)
	{
		if (params->zves < 0)
			params->zves = (params->zves * -1) - 1;
		else
			params->zves -= 1;
		write (1, &params->c, 1);
		params->len++;
		ft_flag_s(params);
		ft_struct_zero(params);
		return (i + 1);
	}
	params->zves = params->zves - 1;
	ft_flag_s(params);
	write (1, &params->c, 1);
	params->len++;
	ft_struct_zero(params);
	return (i + 1);
}

int	ft_input_us (va_list arg, t_ps *params, int i)
{
	params->u = (unsigned int) va_arg(arg, int);
	if (params->zero == 1 && params->zves > 0)
	{
		params->zvet += params->zves - ft_lennbr_unsigned(params->u);
		ft_flag_t(params);
		params->len += ft_lennbr_unsigned(params->u);
		ft_putnbr_unsigned(params->u);
		ft_struct_zero(params);
		return (i + 1);
	}
	if (params->zves < 0 || params->min == 1)
	{
		if (params->zves < 0)
			params->zves = (params->zves * -1) - ft_lennbr_unsigned(params->u);
		else
			params->zves -= ft_lennbr_unsigned(params->u);
		params->len += ft_lennbr_unsigned(params->u);
		ft_putnbr_unsigned(params->u);
		ft_flag_s(params);
		ft_struct_zero(params);
		return (i + 1);
	}
	params->zves = params->zves - ft_lennbr_unsigned(params->u);
	ft_flag_s(params);
	params->len += ft_lennbr_unsigned(params->u);
	ft_putnbr_unsigned(params->u);
	ft_struct_zero(params);
	return (i + 1);
}
int	ft_input_ss (va_list arg, t_ps *params, int i)
{
	params->src = va_arg(arg, char *);
	if (!params->src)
		params->src = "(null)";
	if (params->zves < 0 || params->min == 1)
	{
		if (params->min == 1 && params->zves > 0)
			params->zves -= ft_strlen(params->src);
		else
			params->zves = (params->zves * -1) - ft_strlen(params->src);
		ft_putstr_fd(params->src, params);
		ft_flag_s(params);
		ft_struct_zero(params);
		return (i + 1);
	}
	params->zves = params->zves - ft_strlen(params->src);
	ft_flag_s(params);
	ft_putstr_fd(params->src, params);
	ft_struct_zero(params);
	return (i + 1);
}

int	ft_input_xlows (va_list arg, t_ps *params, int i)
{
	params->u = (unsigned int)va_arg(arg, int);
	if (params->zero == 1 && params->zves > 0)//если есть 0 флаг))
	{
		params->zvet += params->zves - ft_lennbr_hex(params->u);
		ft_flag_t(params);
		ft_hexal_low(params->u, params);
		ft_struct_zero(params);
		return (i + 1);
	}
	if (params->zves < 0 || params->min == 1)
	{
		if (params->zves < 0)
		 	params->zves = (params->zves * -1) - ft_lennbr_hex(params->u);
		else
			params->zves -= ft_lennbr_hex(params->u);
		ft_hexal_low(params->u, params);
		ft_flag_s(params);
		ft_struct_zero(params);
		return (i + 1);
	}
	params->zves = params->zves - ft_lennbr_hex(params->u);
	ft_flag_s(params);
	ft_hexal_low(params->u, params);
	ft_struct_zero(params);
	return (i + 1);
}

int	ft_input_xups (va_list arg, t_ps *params, int i)
{
	params->u = (unsigned int)va_arg(arg, int);
	if (params->zero == 1 && params->zves > 0)//если есть 0 флаг))
	{
		params->zvet += params->zves - ft_lennbr_hex(params->u);
		ft_flag_t(params);
		ft_hexal_up(params->u, params);
		ft_struct_zero(params);
		return (i + 1);
	}
	if (params->zves < 0 || params->min == 1)
	{
		if (params->zves < 0)
	 		params->zves = (params->zves * -1) - ft_lennbr_hex(params->u);
		else
			params->zves -= ft_lennbr_hex(params->u);
		ft_hexal_up(params->u, params);
		ft_flag_s(params);
		ft_struct_zero(params);
		return (i + 1);
	}
	params->zves = params->zves - ft_lennbr_hex(params->u);
	ft_flag_s(params);
	ft_hexal_up(params->u, params);
	ft_struct_zero(params);
	return (i + 1);
}

int	ft_input_ps (va_list arg, t_ps *params, int i)
{
	params->point = (unsigned long)va_arg(arg, int);
	if (params->zves < 0 || params->min == 1)
		{
		if (params->zves < 0)
			params->zves = (params->zves * -1) - ft_lennbr_point(params->point);
		else
			params->zves -= ft_lennbr_point(params->point);
		ft_hexal_point(params->point, params);
		ft_flag_s(params);
		ft_struct_zero(params);
		return (i + 1);
	}
	params->zves = params->zves - ft_lennbr_point(params->point);
	ft_flag_s(params);
	ft_hexal_point(params->point, params);
	ft_struct_zero(params);
	return (i + 1);
}
