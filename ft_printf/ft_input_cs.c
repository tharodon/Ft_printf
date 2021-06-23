#include "ft_printf.h"
int	ft_input_dcs (va_list arg, t_ps *params, int i)
{
	params->d = va_arg(arg, int);
	if (params->zves < 0)
	{
		params->zves = (params->zves * -1) - ft_lennbr(params->d);
		ft_putstr_fd(ft_itoa(params->d), params);
		ft_flag_s(params);
		ft_struct_zero(params);
		return (i);
	}
	params->zves = params->zves - ft_lennbr(params->d);
	ft_flag_s(params);
	ft_putstr_fd(ft_itoa(params->d), params);
	ft_struct_zero(params);
	return (i);
}

int	ft_input_ccs (va_list arg, t_ps *params, int i)
{
	params->c = va_arg(arg, int);
	if (params->zves < 0)
	{
		params->zves = (params->zves * -1) - 1;
		write (1, &params->c, 1);
		params->len++;
		ft_flag_s(params);
		ft_struct_zero(params);
		return (i);
	}
	params->zves--;
	ft_flag_s(params);
	write (1, &params->c, 1);
	params->len++;
	ft_struct_zero(params);
	return (i);
}

int	ft_input_ucs (va_list arg, t_ps *params, int i)
{
	params->u = (unsigned int)va_arg(arg, unsigned int);
	if (params->zves < 0)
	{
		params->zves = (params->zves * -1) - ft_lennbr_unsigned(params->u);
		params->len += ft_lennbr_unsigned(params->u);
		ft_putnbr_unsigned(params->u);
		ft_flag_s(params);
		ft_struct_zero(params);
		return (i);
	}
	params->zves = params->zves - ft_lennbr_unsigned(params->u);
	ft_flag_s(params);
	params->len += ft_lennbr_unsigned(params->u);
	ft_putnbr_unsigned(params->u);
	ft_struct_zero(params);
	return (i);
}

int	ft_input_scs (va_list arg, t_ps *params, int i)
{
	params->src = va_arg(arg, char *);
	if (!params->src)
		params->src = "(null)";
	if (params->zves < 0)
	{
		params->zves = (params->zves * -1) - ft_strlen(params->src);
		ft_putstr_fd(params->src, params);
		ft_flag_s(params);
		ft_struct_zero(params);
		return (i);
	}
	params->zves = params->zves - ft_strlen(params->src);
	ft_flag_s(params);
	ft_putstr_fd(params->src, params);
	ft_struct_zero(params);
	return (i);
}

int	ft_input_xlowcs (va_list arg, t_ps *params, int i)
{
	params->d = va_arg(arg, int);
	if (params->zves < 0)
	{
		params->zves = (params->zves * -1) - ft_lennbr_hex(params->d);
		ft_hexal_low((unsigned int)params->d, params);
		ft_flag_s(params);
		ft_struct_zero(params);
		return (i);
	}
	params->zves = params->zves - ft_lennbr_hex(params->d);
	ft_flag_s(params);
	ft_hexal_low((unsigned int)params->d, params);
	params->minus = 0;
	ft_struct_zero(params);
	return (i);
}

int	ft_input_xupcs (va_list arg, t_ps *params, int i)
{
	params->d = va_arg(arg, int);
	if (params->zves < 0)
	{
		params->zves = (params->zves * -1) - ft_lennbr_hex(params->d);
		ft_hexal_up((unsigned int)params->d, params);
		ft_flag_s(params);
		ft_struct_zero(params);
		return (i);
	}
	params->zves = params->zves - ft_lennbr_hex(params->d);
	ft_flag_s(params);
	ft_hexal_up((unsigned int)params->d, params);
	params->minus = 0;
	ft_struct_zero(params);
	return (i);
}

int	ft_input_pcs (va_list arg, t_ps *params, int i)
{
	params->point = va_arg(arg, unsigned long);
	if (params->zves < 0)
	{
		params->zves = (params->zves * -1) - ft_lennbr_point(params->point);
		ft_hexal_point(params->point, params);
		ft_flag_s(params);
		ft_struct_zero(params);
		return (i);
	}
	params->zves = params->zves - ft_lennbr_point(params->point);
	ft_flag_s(params);
	ft_hexal_point(params->point, params);
	ft_struct_zero(params);
	return (i);
}