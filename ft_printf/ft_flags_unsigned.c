#include "ft_printf.h"
#include <stdio.h>

//void  ft_flag_s_unsigned(const char *s, int i, t_ps params, va_list arg)
//{
//  while (params->zves > 0)
//  {
//	write(1, " ", 1);
//	params->zves--;
//  }
//}

//
//void  ft_flag_t_unsigned(const char *s, int i, t_ps params, va_list arg)
//{
//  while (params->zvet > 0)
//  {
//	write(1, "0", 1);
//	params->zvet--;
//  }
//}

void	ft_flag_s_t_kost_unsigned(t_ps *params)
{
	while (params->zves > ft_lennbr_unsigned(params->u))
	{
		write(1, " ", 1);
		params->zves--;
		params->len++;
	}
}

void	ft_flag_s_t_kost_hex(t_ps *params)
{
	while (params->zves > ft_lennbr_hex(params->d))
	{
		write(1, " ", 1);
		params->zves--;
		params->len++;
	}
}

void	ft_flag_s_t_unsigned(t_ps *params)
{
	if (params->zvet <= ft_lennbr_unsigned(params->u))
	{
		ft_flag_s_t_kost_unsigned(params);
		return ;
	}
	if (params->zvet >= params->zves)
	{
		while (params->zvet > ft_lennbr_unsigned(params->u))
		{
			write(1, "0", 1);
			params->zvet--;
			params->len++;
		}
	}
	else
	{
		while (params->zves > params->zvet)
		{
			write(1, " ", 1);
			params->zves--;
			params->len++;
		}
		while (params->zvet > ft_lennbr_unsigned(params->u))
		{
			write(1, "0", 1);
			params->zvet--;
			params->len++;
		}
	}
}

void	ft_flag_minus_unsigned(t_ps *params)
{
//  if (params->minus == 1)
//  {
//	write(1, "-", 1);
//	params->zves--;
//  }
	if (params->mzves == 1)
	{
		while (params->zvet > ft_lennbr_unsigned(params->u))
		{
			write(1, "0", 1);
			params->zvet--;
			params->zves--;
			params->len++;
		}
		params->len += ft_lennbr_unsigned(params->u);
		ft_putnbr_unsigned(params->u);
		if (params->zves > params->zvet && params->zvet < ft_lennbr_unsigned(params->u))
		{
			while (params->zves > ft_lennbr_unsigned(params->u))
			{
				write(1, " ", 1);
				params->zves--;
				params->len++;
			}
			return ;
		}
		// params->len += ft_lennbr_unsigned(params->u);//закомментил и заработало кек не сноси пока что
		while (params->zves > params->zvet)
		{
			write(1, " ", 1);
			params->zves--;
			params->len++;
		}
	}
}

void	ft_flag_minhex_l(t_ps *params)
{
	if (params->mzves == 1)
	{
		while (params->zvet > ft_lennbr_hex(params->d))
		{
			write(1, "0", 1);
			params->zvet--;
			params->zves--;
			params->len++;
		}
		ft_hexal_low((unsigned int)params->d, params);
	   if (params->zves > params->zvet && params->zvet < ft_lennbr_hex(params->d))
	   {
		   while (params->zves > ft_lennbr_hex(params->d))
		   {
			   write(1, " ", 1);
			   params->zves--;
			   params->len++;
		   }
		   return ;
	   }
		while (params->zves > params->zvet)
		{
			write(1, " ", 1);
			params->zves--;
			params->len++;
		}
	}
}

void	ft_flag_minhex_up(t_ps *params)
{
	if (params->mzves == 1)
	{
		while (params->zvet > ft_lennbr_hex(params->d))
		{
			write(1, "0", 1);
			params->zvet--;
			params->zves--;
			params->len++;
		}
		ft_hexal_up((unsigned long long)params->d, params);
		if (params->zves > params->zvet && params->zvet < ft_lennbr_hex(params->d))
	   {
		   while (params->zves > ft_lennbr_hex(params->d))
		   {
			   write(1, " ", 1);
			   params->zves--;
			   params->len++;
		   }
		   return ;
	   }
		while (params->zves > params->zvet)
		{
			write(1, " ", 1);
			params->zves--;
			params->len++;
		}
	}
}

void	ft_flag_wronghex_l(t_ps *params)
{
	if (params->mzves == 1)
	{
		while (params->zvet > 8)
		{
			write(1, "0", 1);
			params->zvet--;
			params->zves--;
			params->len++;
		}
		ft_hexal_low((unsigned int)params->d, params);
		if (params->zvet < 8)
		{
			while (params->zves > 8)
			{
				write(1, " ", 1);
				params->zves--;
				params->len++;
			}
			return ;
		}
		while (params->zves > params->zvet)
		{
			write(1, " ", 1);
			params->zves--;
			params->len++;
		}
	}
}

void	ft_flag_wronghex_up(t_ps *params)
{
	if (params->mzves == 1)
	{
		while (params->zvet > 8)
		{
			write(1, "0", 1);
			params->zvet--;
			params->zves--;
			params->len++;
		}
		ft_hexal_low((unsigned int)params->d, params);
		if (params->zvet < 8)
		{
			while (params->zves > 8)
			{
				write(1, " ", 1);
				params->zves--;
				params->len++;
			}
			return ;
		}
		while (params->zves > params->zvet)
		{
			write(1, " ", 1);
			params->zves--;
			params->len++;
		}
	}
}
void	ft_flag_minhex_point(t_ps *params)
{
	if (params->mzves == 1)
	{
		ft_putstr_fd("0x", params);
		while (params->zvet > ft_lennbr_hex(params->point))
		{
			write(1, "0", 1);
			params->zvet--;
			params->zves--;
			params->len++;
		}
		ft_hexal_low(params->point, params);
	   if (params->zves > params->zvet && params->zvet < ft_lennbr_hex(params->point))
	   {
		   while (params->zves > ft_lennbr_hex(params->point))
		   {
			   write(1, " ", 1);
			   params->zves--;
			   params->len++;
		   }
		   return ;
	   }
		while (params->zves > params->zvet)
		{
			write(1, " ", 1);
			params->zves--;
			params->len++;
		}
	}
}