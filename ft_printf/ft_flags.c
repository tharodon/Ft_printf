#include "ft_printf.h"
#include <stdio.h>

void	ft_flag_s(t_ps *params)
{
	while (params->zves > 0)
	{
		write(1, " ", 1);
		params->zves--;
		params->len++;
	}
}

void	ft_flag_t(t_ps *params)
{
	while (params->zvet > 0)
	{
		write(1, "0", 1);
		params->zvet--;
		params->len++;
	}
}

void	ft_flag_s_t_kost(t_ps *params)
{
	if (params->minus == 1)
		params->zves--;
	while (params->zves > ft_lennbr(params->d))
	{
		write(1, " ", 1);
		params->zves--;
		params->len++;
	}
	if (params->minus == 1)
	{
		write(1, "-", 1);
		params->len++;
	}
}
void	ft_flag_s_t_kost_point(t_ps *params)
{
	if (params->minus == 1)
		params->zves--;
	while (params->zves > ft_lennbr_point(params->point))
	{
		write(1, " ", 1);
		params->zves--;
		params->len++;
	}
}

void	ft_flag_s_t(t_ps *params)
{
	if (params->zvet <= ft_lennbr(params->d))
	{
		ft_flag_s_t_kost(params);
		return ;
	}
	if (params->zvet >= params->zves)
	{
		while (params->zvet > ft_lennbr(params->d))
		{
			if (params->minus == 1)
			{
				write(1, "-", 1);
				params->minus = 0;
				params->len++;
			}
			write(1, "0", 1);
			params->zvet--;
			params->len++;
		}
	}
	else
	{
		if (params->minus == 1)
		{
			while (params->zves - 1 > params->zvet)
			{
				write(1, " ", 1);
				params->zves--;
				params->len++;
			}
			write(1, "-", 1);
			params->minus = 0;
			params->len++;
		}
		else
			while (params->zves > params->zvet)
			{
				write(1, " ", 1);
				params->zves--;
				params->len++;
			}
			while (params->zvet > ft_lennbr(params->d))
			{
				write(1, "0", 1);
				params->zvet--;
				params->len++;
			}
	}
}

void	ft_flag_minus(t_ps *params)
{
	if (params->minus == 1)
	{
		write(1, "-", 1);
		params->zves--;
		params->len++;
	}
	if (params->mzves == 1)
	{
		while (params->zvet > ft_lennbr(params->d))
		{
			write(1, "0", 1);
			params->zvet--;
			params->zves--;
			params->len++;
		}
		ft_putstr_fd(ft_itoa(params->d), params);
		if (params->zves > params->zvet && params->zvet < ft_lennbr(params->d))
		{
			while (params->zves > ft_lennbr(params->d))
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

void	ft_flag_s_t_hex(t_ps *params)
{
	if (params->zvet <= ft_lennbr_hex((unsigned int)params->d))
	{
		ft_flag_s_t_kost_hex(params);
		return ;
	}
	if (params->zvet >= params->zves)
	{
		while (params->zvet > ft_lennbr_hex(params->d))
		{
			if (params->minus == 1)
			{
				write(1, "-", 1);
				params->minus = 0;
				params->len++;
			}
			write(1, "0", 1);
			params->zvet--;
			params->len++;
		}
	}
	else
	{
		if (params->minus == 1)
		{
			while (params->zves - 1 > params->zvet)
			{
				write(1, " ", 1);
				params->zves--;
				params->len++;
			}
			write(1, "-", 1);
			params->minus = 0;
			params->len++;
		}
		else
			while (params->zves > params->zvet)
			{
				write(1, " ", 1);
				params->zves--;
				params->len++;
			}
			while (params->zvet > ft_lennbr_hex(params->d))
			{
				write(1, "0", 1);
				params->zvet--;
				params->len++;
			}
	}
}

void	ft_putstr_t(const char *s, t_ps *params)
{
	int  i;

	i = 0;
	while (s[i] && params->zvet > 0)
	{
		write (1, &s[i], 1);
		i++;
		params->zvet--;
		params->len++;
	}
//  while (params.zvet > 0)
//  {
//	write (1," ", 1);
//	params.zvet--;
//  }
}

//void  ft_flag_wrong_st(const char *s, int i, t_ps params, va_list arg)
//{
//  if (params.zvet <= 8)
//  {
//	while (params.zves > 8)
//	{
//	  write(1, " ", 1);
//	  params.zves--;
//	}
//	return ;
//  }
//  if (params.zvet >= params.zves)
//  {
//	while (params.zvet > 8)
//	{
//	  write(1, "0", 1);
//	  params.zvet--;
//	}
//  }
//  else
//  {
//	if (params.minus == 1)
//	{
//	  while (params.zves - 1 > params.zvet)
//	  {
//		write(1, " ", 1);
//		params.zves--;
//	  }
//	  write(1, "-", 1);
//	  params.minus = 0;
//	}
//	else
//	  while (params.zves > params.zvet)
//	  {
//		write(1, " ", 1);
//		params.zves--;
//	  }
//	while (params.zvet > 8)
//	{
//	  write(1, "0", 1);
//	  params.zvet--;
//	}
//  }
//}
void	ft_flag_s_t_point(t_ps *params)
{
	if (params->zvet <= ft_lennbr_point(params->point))
	{
		ft_flag_s_t_kost_point(params);
		ft_putstr_fd("0x", params);
		return ;
	}
	ft_putstr_fd("0x", params);
	if (params->zvet >= params->zves)
	{
		while (params->zvet > ft_lennbr_point(params->point))
		{
			if (params->minus == 1)
			{
				write(1, "-", 1);
				params->minus = 0;
				params->len++;
			}
			write(1, "0", 1);
			params->zvet--;
			params->len++;
		}
	}
	else
	{
		if (params->minus == 1)
		{
			while (params->zves - 1 > params->zvet)
			{
				write(1, " ", 1);
				params->zves--;
				params->len++;
			}
			write(1, "-", 1);
			params->minus = 0;
			params->len++;
		}
		else
			while (params->zves > params->zvet)
			{
				write(1, " ", 1);
				params->zves--;
				params->len++;
			}
			while (params->zvet > ft_lennbr_point(params->point))
			{
				write(1, "0", 1);
				params->zvet--;
				params->len++;
			}
	}
}