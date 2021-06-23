#include "ft_printf.h"
int	ft_input_dt (va_list arg, t_ps *params, int i)
{
	params->d = (long)va_arg(arg, int);
	if (params->zvet == 0 && (int)params->d == 0)
		return (i + 2);
	if (params->d < 0)
	{
		if (params->d != -2147483648)
			params->len += write(1, "-", 1);
		params->d *= -1; //ОБРАТИ ВНИМАНИЕ!!! Возможно тут бабахнется из-за макимального int
	}
	params->zvet = params->zvet - ft_lennbr(params->d);
	ft_flag_t(params);
	ft_putstr_fd(ft_itoa(params->d), params);
	ft_struct_zero(params);
	return (i + 2);
}

int	ft_input_ut (va_list arg, t_ps *params, int i)
{
	params->u = (unsigned int)va_arg(arg, unsigned int);
	if (params->zvet == 0 && params->u == 0)
		return (i + 2);
	params->zvet = params->zvet - ft_lennbr_unsigned(params->u);
	ft_flag_t(params);
	params->len += ft_lennbr_unsigned(params->u);
	ft_putnbr_unsigned(params->u);
	ft_struct_zero(params);
	return (i + 2);
}

int	ft_input_st (va_list arg, t_ps *params, int i)
{
	params->src = va_arg(arg, char *);
	if (!params->src)//ЗДЕСЬ КОСТЫЛЬ ДЛЯ СТРОКИ ЕСЛИ ОНА НУЛЛ
	{
		params->src = "(null)";
	}
	if (params->zvet < 0)
		ft_putstr_fd(params->src, params);
	ft_putstr_t(params->src, params);
	ft_struct_zero(params);
	return (i + 2);
}

int	ft_input_xlowt (va_list arg, t_ps *params, int i)
{
	params->u = va_arg(arg, unsigned int);
	if (params->zvet == 0 && params->u == 0)
		return (i + 2);
	params->zvet = params->zvet - ft_lennbr_unsigned(params->u);
	ft_flag_t(params);
	ft_hexal_low((unsigned long long)params->u, params);
	ft_struct_zero(params);
	return (i + 2);
}

int	ft_input_xupt (va_list arg, t_ps *params, int i)
{
	params->u = va_arg(arg, unsigned int);
	if (params->zvet == 0 && params->u == 0)
		return (i + 2);
	params->zvet = params->zvet - ft_lennbr_unsigned(params->u);
	ft_flag_t(params);
	ft_hexal_up((unsigned long long)params->u, params);
	ft_struct_zero(params);
	return (i + 2);
}

int	ft_input_pt (va_list arg, t_ps *params, int i)
{
	params->point = va_arg(arg, unsigned long);
	if (params->zvet == 0 && params->point == 0)
		return (i + 2);
	params->zvet = params->zvet + 2 - ft_lennbr_point(params->point);
	ft_putstr_fd("0x", params);
	ft_flag_t(params);
	ft_hexal_low((unsigned long long)params->point, params);
	ft_struct_zero(params);
	return (i + 2);
}
