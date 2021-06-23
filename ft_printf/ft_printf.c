#include "ft_printf.h"
#include <stdio.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

//t_ps    ft_nul(t_ps p)
//{
//    p.d = 0;
//    p.c = 0;
//    p.u = 0;
//    p.src = NULL;
//    p.zves = 0;
//    p.zvet = 0;
//    p.minus = 0;
//    p.mzves = 0;
//    return(p);
//}

void ft_parser(const char *s, va_list arg, t_ps *params, int i)
{
	char *temp;

	temp = ft_strchr(TYPE, s[i]);
	if (*temp == 'd' || *temp == 'i')
	{
		if (params->vod == 1)
			return ;
		params->d = va_arg(arg, int);
		if (params->wrong_s == 1 && params->d == 0)
			return ;
		ft_putstr_fd(ft_itoa(params->d), params);
	}
	if (*temp == 's')
	{
		if (params->vod == 1)
			return ;
		params->src = va_arg(arg, char *);
		if (params->wrong_s == 1)
			return ;
		if (!params->src) //КОСТЫЛЬ ДЛЯ СТРОКИ ЕСЛИ ОНА НУЛЛ
		{
			params->src = "(null)";
		}
		ft_putstr_fd(params->src, params);
	}
	//    if (*temp == 'p')
	//        params.pointer = f; //функция которая из десятичной переводит в шестнадцатиричную ну и "0.x" (буквы адреса нижнего регистра)
	//    if (*temp == 'x')
	//        params.hexal = f; //функция которая переводит в шестнадцатиричную систему/буквы строчные
	//    if (*temp == 'X')
	//        params.hexal_up = f; //функция которая переводит в шестнадцатиричную систему/буквы верхнего регистра
	if (*temp == 'c')
	{
		if (params->vod == 1)
			return ;
		if (params->wrong_s == 1)
			return ;
		params->c = va_arg(arg, int);
		ft_putchar(params->c);
		params->len++;
	}
	if (*temp == 'u')
	{
		if (params->vod == 1)
			return ;
		if (params->wrong_s == 1 && params->d == 0)
			return ;
		params->u = (unsigned int)va_arg(arg, unsigned int);
		ft_putnbr_unsigned(params->u);
		params->len += ft_lennbr_unsigned(params->u);
	}
	if (*temp == 'x')
	{
		if (params->vod == 1)
			return ;
		if (params->wrong_s == 1 && params->d == 0)
			return ;
		params->u = va_arg(arg, unsigned int);
		ft_hexal_low(params->u, params);
	}
	if (*temp == 'p')
	{
		if (params->vod == 1)
		{
			ft_putstr_fd("0x", params);
			return ;
		}
		if (params->wrong_s == 1 && params->point == 0)
		{
			ft_putstr_fd("0x", params);
			return ;
		}
		params->point = va_arg(arg, unsigned long);
		ft_putstr_fd("0x", params);
		ft_hexal_low(params->point, params);
	}
	if (*temp == 'X')
	{
		if (params->vod == 1)
			return ;
		if (params->wrong_s == 1 && params->d == 0)
			return ;
		params->u = va_arg(arg, unsigned int);
		ft_hexal_up((unsigned long long)params->u, params);
	}
	//    if (*temp == ' ')
	//        params.probel = 1;
	//    if (*temp == '-')
	//        params.minus = 1;
	//    if (*temp == '+')
	//        params.plus = 1;
}

int ft_printf(const char *s, ...)
{
	va_list arg;
	int i;
	t_ps params;
	//    char o;
	i = 0;
	params.d = 0;
	params.c = 0;
	params.u = 0;
	params.src = NULL;
	params.zves = 0;
	params.zvet = 0;
	params.minus = 0;
	params.mzves = 0;
	params.len = 0;
	params.zero = 0;
	params.vod = 0;
	params.min = 0;
	params.min_val = 0;
	params.wrong_s = 0;
	params.only_s = 0;
	params.point = 0;
	params.min_n = 0;
	params.zero_n = 0;
	va_start(arg, s);
	//    o = (char)va_arg(arg, int);
	while (s[i])
	{ //              ПОПРОБУЙ ПЕРЕПИСАТЬ ПРИНТФ С БОЛЕЕ ПОНЯТНЫМИ ФЛАГАМИ И ПУТЯМИ
		if (s[i] == '%')//НАПИШИ УСЛОВИЕБ ЕСЛИ НОЛЬ В НАЧАЛЕ ЧТОБЫ БЫЛО РАСПРЕДЕЛЕНИЕ А ТО 0*.* НЕ ОБРАБАТЫВАЕТСЯ
		{
			if (ft_checker_percent_null(s, i + 1))
			{
				return (params.len);
			}
			else if (ft_checker_percent_type(s, i + 1) && ft_checker_percent(s, i + 1, &params))//здесь обработка если два процента
			{
				i = ft_parser_percent(s, &params, i + 1);
			}
			else if (s[i + 1] == '0' || s[i + 1] == '-')
			{
				i = ft_parser_zero(s, arg, &params, i + 1);
			}
			else if (s[i + 1] >= '1' && s[i + 1] <= '9')
			{
				i = ft_parser_count(s, arg, &params, i + 1);
			}
			else if (s[i + 1] == '*' && s[i + 2] == '.' && s[i + 3] == '*')
			{
				i = ft_parser_s_t(s, arg, &params, i + 1);
			}
			else if (s[i + 1] == '*')
			{
				i = ft_parser_s(s, arg, &params, i + 1);
			}
			else if (s[i + 1] == '.')
			{
				i = ft_parser_t(s, arg, &params, i + 1);
			}
			else
			{
				ft_parser(s, arg, &params, i + 1);
				i++;
			}
		}
		else
		{
			ft_putchar(s[i]);
			params.len++;
		}
		i++;
	} //ВНИМАТЕЛЬНО ПРОВЕРЬ С ОДИНАКОВЫМИ ЛИ ПЕРЕМЕННАМИ РАБОТАЮТ АРГУМЕНТЫ В РАЗНЫХ ФУНКЦИЯХ!!!!!!!! А ТО БОЛЬШОЙ ИКС С АНСАЙНТ МАЛЕНЬКИЙ С Д ПОЧЕМУ-ТО
	// printf("VOZVRAT FT_PRINTEF: |%d|\n", params.len);
	return (params.len);
}

// int main()
// {
//  	int		a = 4;
//  	int		b = 3;
//  	char	c = 'a';
//  	int		d = 2147483647;
//  	int		e = -2147483648;
//  	int		f = 42;
//  	int		g = 25;
//  	int		h = 4200;
//  	int		i = 8;
//  	int		j = -12;
//  	int		k = 123456789;
//  	int		l = 0;
//  	int		m = -12345678;
//  	char	*n = "abcdefghijklmnop";
//  	char	*o = "-a";
//  	char	*p = "-12";
//  	char	*q = "0";
//  	char	*r = "%%";
//  	char	*s = "-2147483648";
//  	char	*t = "0x12345678";
//  	char	*u = "-0";

//  	int kek;
//  	int kok;
// 	// kek = ft_printf("%##x", 42);
// 	printf("\n");
// 	kok = printf("%##x", 42);
// 	printf("\n%d\t\t\t%d\n", kek, kok);
// 	// ft_printf("{%00000000*.0-0-0-0-05d}\n", 15, 42);
//  	// printf("{%00000000*.0-0-0-0-0-0-05d}\n", 15, 42);
//  	// printf ( "mypf %d\n", ft_printf("%-2s, %.s, %-4s, %-2.4s, %-8.12s, %3s, %8s, %---2s, %.*s, %.0s, %.1s, %.2s, %.4s, %.8s", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, -2, NULL, NULL, NULL, NULL, NULL, NULL));
//  	// printf ( "mypf %d\n", printf("%-2s, %.s, %-4s, %-2.4s, %-8.12s, %3s, %8s, %---2s, %.*s, %.0s, %.1s, %.2s, %.4s, %.8s", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, -2, NULL, NULL, NULL, NULL, NULL, NULL));
//  	// printf ( "mypf %d\n", ft_printf("%% *.5i 42 == |% *.5i|", 4, 42));
//  	// printf ( "mypf %d\n", printf("%% *.5i 42 == |% *.5i|", 4, 42));
//  }




