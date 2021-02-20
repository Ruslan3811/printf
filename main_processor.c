#include "printf.h"

void				nulling_parameters(void)
{
	g_struct.nbr = 0;
	g_struct.symb = '\0';
	g_struct.str = NULL;
}

int					ft_put_char_d_x_i_u_s_c_p_signs(int i_for_spaces, int i)
{
	long long		copy_nbr;

	copy_nbr = g_struct.nbr;
	if (g_struct.type != 'c' && g_struct.type != 's')
		making_width_prec(i_for_spaces, g_struct.nbr);
	if (g_struct.nbr == 0 && g_struct.nbr_prec != 0 && g_struct.type != 'p'
						&& g_struct.type != 's' && g_struct.type != 'c')
		ft_putchar('0');
	if (g_struct.type == 'd' || g_struct.type == 'i' || g_struct.type == 'u')
		making_exp(i, copy_nbr, g_struct.nbr);
	else if (g_struct.type == 's')
		ft_put_str_char(g_struct.str, i);
	else if (g_struct.type == 'c')
		ft_put_str_char(&g_struct.symb, 1);
	else if (((g_struct.type == 'x' || g_struct.type == 'X')
								&& g_struct.nbr > 0) || g_struct.type == 'p')
	{
		if (ft_putnbr_for_x_p((unsigned long)g_struct.nbr, i) == -1)
			return (-1);
	}
	while (g_struct.add_spaces_at_the_back >= 0
							&& g_struct.add_spaces_at_the_back--)
		ft_putchar(' ');
	return (0);
}

int					count_symb(void)
{
	int				i_for_spaces;
	int				copy_nbr;
	int				i;

	i = 0;
	if (g_struct.type == 'd' || g_struct.type == 'u' || g_struct.type == 'i')
		i = count_digits_in_nbr(g_struct.nbr);
	else if (g_struct.type == 'x' || g_struct.type == 'X'
									|| g_struct.type == 'p')
		i = amount_digits_x_p(g_struct.nbr);
	else if (g_struct.type == 's')
		i = (int)ft_strlen(g_struct.str);
	else if (g_struct.type == 'c')
		i = 1;
	i_for_spaces = i;
	copy_nbr = (long long)g_struct.nbr;
	if (ft_put_char_d_x_i_u_s_c_p_signs(i_for_spaces, i) == -1)
		return (-1);
	return (0);
}

int					ft_parse(void)
{
	nulling_parameters();
	if (g_struct.type == '%')
	{
		making_percent();
		return (1);
	}
	g_struct.nbr = (g_struct.type == 'd' || g_struct.type == 'i')
				? (long long)va_arg(g_argptr, int) : g_struct.nbr;
	if (g_struct.type == 'x' || g_struct.type == 'X' || g_struct.type == 'u')
		g_struct.nbr = (long long)va_arg(g_argptr, unsigned int);
	g_struct.nbr = (g_struct.type == 'p')
				? (long long)va_arg(g_argptr, size_t) : g_struct.nbr;
	if (g_struct.type == 's')
	{
		g_struct.str = va_arg(g_argptr, char *);
		g_struct.str = (!g_struct.str) ? "(null)" : g_struct.str;
	}
	else if (g_struct.type == 'c')
		g_struct.symb = (char)va_arg(g_argptr, unsigned int);
	if (g_struct.nbr < 0 && g_struct.type != 'x' && g_struct.type != 'X'
													&& g_struct.type != 'p')
		g_struct.neg_nbr = '-';
	if (count_symb() == -1)
		return (-1);
	return (0);
}
