#include "ft_printf.h"
int	ft_input_dct (va_list arg, t_ps *params, int i)
{
	params->d = va_arg(arg, int);
	if (params->zvet == 0 && params->d == 0 && params->zero == 0)
		return (i);
	if (params->d < 0)
	{
	   if (params->d != -2147483648)
			params->len += write(1, "-", 1);//закомментил на  шару хз почему работает, но пока не удоляй кек
	   params->d *= -1; //ОБРАТИ ВНИМАНИЕ!!! Возможно тут бабахнется из-за макимального int
	   if ((params->zero == 1 && params->zvet >= 1) || (params->zvet >= 1 && params->min == 1))
	   {
		   params->zvet--;
	   }
	   if ((params->zero == 1 && params->zvet < 0) || (params->zvet < 0 && params->min == 1))
	   {
		   params->zvet++;
	   }
	}
	if (params->zvet < 0)
	{
		if (params->minus == 1)
			params->d *= -1;
		params->zves = (params->zvet * -1) - ft_lennbr(params->d);
		ft_putstr_fd(ft_itoa(params->d), params);
		ft_flag_s(params);
		ft_struct_zero(params);
		return (i);
	}
	params->zvet = params->zvet - ft_lennbr(params->d);
	ft_flag_t(params);
	ft_putstr_fd(ft_itoa(params->d), params);
	ft_struct_zero(params);
	return (i);
}

int	ft_input_uct (va_list arg, t_ps *params, int i)
{
	params->u = (unsigned int)va_arg(arg, unsigned int);
	if (params->zvet == 0 && params->u == 0)
		return (i);
	if (params->zvet < 0)
	{
		params->zves = (params->zvet * -1) - ft_lennbr_unsigned(params->u);
		params->len += ft_lennbr_unsigned(params->u);
		ft_putnbr_unsigned(params->u);
		ft_flag_s(params);
		ft_struct_zero(params);
		return (i);
	}
	params->zvet = params->zvet - ft_lennbr_unsigned(params->u);
	ft_flag_t(params);
	params->len += ft_lennbr_unsigned(params->u);
	ft_putnbr_unsigned(params->u);
	ft_struct_zero(params);
	return (i);
}

int	ft_input_sct (va_list arg, t_ps *params, int i)
{
	params->src = va_arg(arg, char *);
	if (!params->src)
		params->src = "(null)";
	if (params->zero == 1)
	{
		params->zvet -= ft_strlen(params->src);
		ft_flag_t(params);
		ft_putstr_fd(params->src, params);
		ft_struct_zero(params);
		return (i);
	}
	if (params->zvet < 0)
	{
		params->zves = params->zvet * -1;
		ft_flag_s(params);
		ft_struct_zero(params);
		return (i);
	}
	ft_putstr_t(params->src, params);
	ft_struct_zero(params);
	return (i);
}

int	ft_input_xlowct (va_list arg, t_ps *params, int i)
{
	params->u = va_arg(arg, unsigned int);
	if (params->zvet == 0 && params->u == 0)
		return (i);
	if (params->zvet < 0)
	{
		params->zves = (params->zvet * -1) - ft_lennbr_hex(params->u);
		ft_hexal_low((unsigned long long)params->u, params);
		ft_flag_s(params);
		ft_struct_zero(params);
		return (i);
	}
	params->zvet = params->zvet - ft_lennbr_hex(params->u);
	ft_flag_t(params);
	ft_hexal_low((unsigned long long)params->u, params);
	return (i);
}

int	ft_input_xupct (va_list arg, t_ps *params, int i)
{
	params->u = va_arg(arg, unsigned int);
	if (params->zvet == 0 && params->u == 0)
		return (i);
	if (params->zvet < 0)
	{
		params->zves = (params->zvet * -1) - ft_lennbr_hex(params->u);
		ft_hexal_up((unsigned long long)params->u, params);
		ft_flag_s(params);
		ft_struct_zero(params);
		return (i);
	}
	params->zvet = params->zvet - ft_lennbr_hex(params->u);
	ft_flag_t(params);
	ft_hexal_up((unsigned long long)params->u, params);
	ft_struct_zero(params);
	return (i);
}

int	ft_input_pct (va_list arg, t_ps *params, int i)
{
	params->point = va_arg(arg, unsigned long);
	if (params->zvet == 0 && params->point == 0)
	{
		ft_putstr_fd("0x", params);
		return (i);
	}
	if (params->zvet < 0)
	{
		params->zves = (params->zvet * -1) - ft_lennbr_point(params->point);
		ft_putstr_fd("0x", params);
		ft_hexal_low(params->point, params);
		ft_flag_s(params);
		ft_struct_zero(params);
		return (i);
	}
	params->zvet = params->zvet - ft_lennbr_hex(params->point);
	ft_putstr_fd("0x", params);
	ft_flag_t(params);
	ft_hexal_low(params->point, params);
	return (i);
}