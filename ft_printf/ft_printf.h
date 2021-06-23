#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define TYPE "scpdiuxX"
# define TOOL "*."
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>//удоли//
#include <limits.h>
// #include </Users/tharodon/Osnova/ft_printf/printf/libft/libft.h>
typedef struct s_params
{
    long			d;
    unsigned int	u;
    int				c;
    short			minus;//просто флаг
    short			mzves;
    int				only_s;
    char			*src; // для строк и для записи указателяю указатель сначала прогнать через функцию, которая приводит из int в char, из десятичной в шестнадцатиричную систему
    short			zero;//хз зачем/потом разберусь
    char			*hexal;
    char			*hexal_up;
    unsigned long	point;
    int				zves;
    int				zvet;
    int				vod;
    int				len;
    int				min;
    int				min_val;
    int				wrong_s;
    int min_n;
    int zero_n;
}   t_ps;
void    ft_flag_s(t_ps *params);
void    ft_flag_t(t_ps *params);
void    ft_flag_s_t_kost(t_ps *params);
void    ft_flag_s_t(t_ps *params);
void    ft_flag_minus(t_ps *params);
void    ft_putstr_t(const char *s, t_ps *params);
void    ft_flag_s_t_kost_unsigned(t_ps *params);
void    ft_flag_s_t_unsigned(t_ps *params);
void    ft_flag_minus_unsigned(t_ps *params);
void    ft_flag_minhex_l(t_ps *params);
void    ft_flag_minhex_up(t_ps *params);
void    ft_flag_wronghex_l(t_ps *params);
void    ft_flag_wronghex_up(t_ps *params);
void    ft_hexal_low(unsigned long long n, t_ps *params);
void    ft_hexal_up(unsigned long long n, t_ps *params);
int ft_lennbr_hex(unsigned int h);
int ft_lennbr(int i);
int ft_lennbr_unsigned(unsigned int i);
int ft_parser_count(const char *s, va_list arg, t_ps *params, int i);
int ft_parser_count_s(const char *s, va_list arg, t_ps *params, int i);
int ft_parser_count_t(const char *s, va_list arg, t_ps *params, int i);
int    ft_parser_s (const char *s, va_list arg, t_ps *params, int i);
int ft_parser_s_t (const char *s, va_list arg, t_ps *params, int i);
int ft_parser_scount_t(const char *s, va_list arg, t_ps *params, int i);
int ft_parser_t (const char *s, va_list arg, t_ps *params, int i);
int ft_parser_tcount_s(const char *s, va_list arg, t_ps *params, int i);
void    ft_putchar(char c);
void    ft_parser(const char *s, va_list arg, t_ps *params, int i);
int     ft_printf(const char *s, ...);
void	ft_putnbr_unsigned(unsigned int n);
void	ft_putstr_fd(char *s, t_ps *params);
void	ft_putnbr_fd(int n, t_ps *params);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
int	ft_atoi(const char *str);
int ft_checker (const char *s, int i);
int ft_checker_minus (const char *s, int i);
int ft_checker_void (const char *s, int i);
void    ft_flag_s_t_hex(t_ps *params);
void	ft_struct_zero(t_ps *params);
int		ft_parser_percent(const char *s, t_ps *params, int i);
int ft_checker_percent (const char *s, int i, t_ps *params);
int ft_checker_percent_type (const char *s, int i);
int ft_checker_percent_null (const char *s, int i);
int ft_checker_zero_st (const char *s, int i);
int ft_parser_zero(const char *s, va_list arg, t_ps *params, int i);
char	*ft_itoa (int n);
int ft_lennbr_point(unsigned long long h);
void    ft_hexal_point(unsigned long long n, t_ps *params);
void    ft_flag_minhex_point(t_ps *params);
void    ft_flag_s_t_point(t_ps *params);
void    ft_flag_s_t_kost_point(t_ps *params);
void    ft_flag_s_t_kost_hex(t_ps *params);
int	ft_checker_tcount (const char *s, int i, t_ps *params);
int	ft_input_ds (va_list arg, t_ps *params, int i);
int	ft_input_cs (va_list arg, t_ps *params, int i);
int	ft_input_us (va_list arg, t_ps *params, int i);
int	ft_input_ss (va_list arg, t_ps *params, int i);
int	ft_input_xlows (va_list arg, t_ps *params, int i);
int	ft_input_xups (va_list arg, t_ps *params, int i);
int	ft_input_ps (va_list arg, t_ps *params, int i);
int	ft_way_s (const char *s, va_list arg, t_ps *params, int i);
int	ft_input_dt (va_list arg, t_ps *params, int i);
int	ft_input_ut (va_list arg, t_ps *params, int i);
int	ft_input_st (va_list arg, t_ps *params, int i);
int	ft_input_xlowt (va_list arg, t_ps *params, int i);
int	ft_input_xupt (va_list arg, t_ps *params, int i);
int	ft_input_pt (va_list arg, t_ps *params, int i);
int	ft_way_t (const char *s, va_list arg, t_ps *params, int i);
int	ft_wrong_s (const char *s, va_list arg, t_ps *params, int i);
int	ft_input_dst (va_list arg, t_ps *params, int i);
int	ft_input_ust (va_list arg, t_ps *params, int i);
int	ft_input_sst (va_list arg, t_ps *params, int i);
int	ft_input_xlowst (va_list arg, t_ps *params, int i);
int	ft_input_xupst (va_list arg, t_ps *params, int i);
int	ft_input_pst (va_list arg, t_ps *params, int i);
int	ft_input_dcs (va_list arg, t_ps *params, int i);
int	ft_input_ccs (va_list arg, t_ps *params, int i);
int	ft_input_ucs (va_list arg, t_ps *params, int i);
int	ft_input_scs (va_list arg, t_ps *params, int i);
int	ft_input_xlowcs (va_list arg, t_ps *params, int i);
int	ft_input_xupcs (va_list arg, t_ps *params, int i);
int	ft_input_pcs (va_list arg, t_ps *params, int i);
int	ft_input_dct (va_list arg, t_ps *params, int i);
int	ft_input_uct (va_list arg, t_ps *params, int i);
int	ft_input_sct (va_list arg, t_ps *params, int i);
int	ft_input_xlowct (va_list arg, t_ps *params, int i);
int	ft_input_xupct (va_list arg, t_ps *params, int i);
int	ft_input_pct (va_list arg, t_ps *params, int i);


#endif