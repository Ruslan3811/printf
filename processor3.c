#include "printf.h"

void			helping_function(int amount_spaces, int nbr, int amount_zero)
{
	while (amount_spaces >= 0 && amount_spaces--)
		ft_putchar(' ');
	if (nbr < 0 && g_struct.type != 'x' && g_struct.type != 'X')
		ft_putchar('-');
	while (amount_zero >= 0 && amount_zero--)
		ft_putchar('0');
}

int				neg_prec(int len)
{
	int			amount_zero;
	int			amount_spaces;

	amount_spaces = 0;
	if (g_struct.nbr_prec == -1)
	{
		amount_spaces = g_struct.nbr_wide - len;
		if (g_struct.neg_nbr == '-' && g_struct.type != 'x'
										&& g_struct.type != 'X')
			amount_spaces--;
		amount_zero = amount_spaces;
		while (amount_spaces >= 0 && g_struct.sign_zero != '0'
												&& amount_spaces--)
			ft_putchar(' ');
		if (g_struct.neg_nbr == '-' && g_struct.type != 'x'
											&& g_struct.type != 'X')
			ft_putchar('-');
		while (amount_zero >= 0 && g_struct.sign_zero == '0' && amount_zero--)
			ft_putchar('0');
		return (1);
	}
	return (0);
}

int				part_of_smth(int len, long long nbr, int amount_zero)
{
	int			amount_spaces;

	amount_spaces = 0;
	if (len >= g_struct.nbr_wide && g_struct.nbr_prec > len)
	{
		helping_function(amount_spaces, nbr, amount_zero);
		return (1);
	}
	else if (g_struct.nbr_wide >= g_struct.nbr_prec
									&& len <= g_struct.nbr_prec)
	{
		amount_spaces = g_struct.nbr_wide - g_struct.nbr_prec;
		if (g_struct.neg_nbr == '-' && g_struct.type != 'x'
											&& g_struct.type != 'X')
			amount_spaces--;
		helping_function(amount_spaces, nbr, amount_zero);
		return (1);
	}
	return (0);
}

int				nbr_prec_more_0(int len, long long nbr)
{
	int			amount_zero;
	int			amount_spaces;

	amount_spaces = 0;
	if (g_struct.nbr_prec >= 0)
	{
		amount_zero = g_struct.nbr_prec - len;
		if (part_of_smth(len, nbr, amount_zero) == 1)
			return (1);
		else if (g_struct.nbr_wide < g_struct.nbr_prec
											&& len < g_struct.nbr_wide)
		{
			if (nbr < 0 && g_struct.type != 'x' && g_struct.type != 'X')
				ft_putchar('-');
			while (amount_zero >= 0 && amount_zero--)
				ft_putchar('0');
			return (1);
		}
	}
	return (0);
}

int				nbr_wide_more_0_not_minus(int len, long long nbr)
{
	int			amount_zero;
	int			amount_spaces;

	amount_zero = 0;
	amount_spaces = 0;
	if ((g_struct.nbr_wide >= 0 && g_struct.sign_minus != '-')
											|| g_struct.nbr_prec >= 0)
	{
		if (nbr_prec_more_0(len, nbr) == 1)
			return (1);
		else if (neg_prec(len))
			return (1);
		else if (neg_nbr(len) == 1)
			return (1);
		else if (prec_less_0_wide_more_len(len) == 1)
			return (1);
	}
	return (0);
}
