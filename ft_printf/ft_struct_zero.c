#include "ft_printf.h"
void	ft_struct_zero(t_ps *params)
{
	params->d = 0;
	params->c = 0;
	params->u = 0;
	params->src = NULL;
	params->zves = 0;
	params->zvet = 0;
	params->minus = 0;
	params->mzves = 0;
	params->zero = 0;
	params->vod = 0;
	params->min = 0;
	params->zero = 0;
	params->min_val = 0;
	params->wrong_s = 0;
	params->only_s = 0;
	params->point = 0;
	params->min_n = 0;
	params->zero_n = 0;
}

// void	ft_min_int(t_ps *params)
// {
// 	if (params->d == -2147483648)
// 		params->min_int = 1;
// }