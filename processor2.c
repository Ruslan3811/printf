#include "printf.h"

int				nbr_prec_more_len(int len, long long nbr)
{
	int			amount_zero;
	int			amount_spaces;

	if (g_struct.nbr_prec >= len)
	{
		amount_zero = g_struct.nbr_prec - len;
		amount_spaces = g_struct.nbr_wide - g_struct.nbr_prec;
		(g_struct.neg_nbr == '-' && g_struct.type != 'x'
					&& g_struct.type != 'X') ? amount_spaces-- : 0;
		while (g_struct.sign_minus != '-'
					&& amount_spaces >= 0 && amount_spaces--)
			ft_putchar(' ');
		if (nbr < 0 && g_struct.type != 'x' && g_struct.type != 'X')
			ft_putchar('-');
		while (amount_zero >= 0 && amount_zero--)
			ft_putchar('0');
		g_struct.add_spaces_at_the_back = amount_spaces;
		return (1);
	}
	return (0);
}

int				not_sign_minus(int len)
{
	int			amount_zero;
	int			amount_spaces;

	if (g_struct.sign_minus != '-')
	{
		amount_spaces = g_struct.nbr_wide - len;
		if (g_struct.sign_zero != '0')
			amount_spaces = g_struct.nbr_wide - len;
		(g_struct.neg_nbr == '-' && g_struct.type != 'x'
							&& g_struct.type != 'X') ? amount_spaces-- : 0;
		amount_zero = amount_spaces;
		while (amount_spaces >= 0 && amount_spaces--)
			ft_putchar(' ');
		(g_struct.neg_nbr == '-' && g_struct.type != 'x'
							&& g_struct.type != 'X') ? ft_putchar('-') : 0;
		while (amount_zero >= 0 && g_struct.sign_zero != '0'
							&& len <= g_struct.nbr_prec && amount_zero--)
			(g_struct.nbr_prec >= 0) ? ft_putchar('0') : 0;
		return (1);
	}
	return (0);
}

int				sign_minus(int len, long long nbr)
{
	int			amount_spaces;

	if (g_struct.sign_minus == '-')
	{
		amount_spaces = g_struct.nbr_wide - len;
		if (g_struct.neg_nbr == '-' && g_struct.type != 'x'
											&& g_struct.type != 'X')
			amount_spaces--;
		g_struct.add_spaces_at_the_back = amount_spaces;
		if (nbr < 0 && g_struct.type != 'x' && g_struct.type != 'X')
			ft_putchar('-');
		return (1);
	}
	return (0);
}

int				nbr_prec_more_eq_to_zero(int len, long long nbr)
{
	int			amount_spaces;

	if ((g_struct.nbr_wide >= 0 && g_struct.sign_minus == '-')
													|| g_struct.nbr_prec >= 0)
	{
		if (g_struct.nbr_prec >= 0)
		{
			if (nbr_prec_more_len(len, nbr) == 1)
				return (1);
			else if (not_sign_minus(len) == 1)
				return (1);
			else if (sign_minus(len, nbr) == 1)
				return (1);
		}
		amount_spaces = g_struct.nbr_wide - len;
		if (g_struct.neg_nbr == '-' && g_struct.type != 'x'
										&& g_struct.type != 'X')
		{
			amount_spaces--;
			ft_putchar('-');
		}
		g_struct.add_spaces_at_the_back = amount_spaces;
		return (1);
	}
	return (0);
}
