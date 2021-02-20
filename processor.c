#include "printf.h"

int			neg_nbr(int len)
{
	int		amount_zero;
	int		amount_spaces;

	amount_zero = 0;
	amount_spaces = 0;
	if (g_struct.neg_nbr == '-')
	{
		if (g_struct.nbr_wide > len && g_struct.sign_zero != '0')
		{
			amount_spaces = g_struct.nbr_wide - len - 1;
			while (amount_spaces >= 0 && amount_spaces--)
				ft_putchar(' ');
		}
		ft_putchar('-');
		if (g_struct.nbr_wide > len && g_struct.sign_zero == '0')
		{
			amount_zero = g_struct.nbr_wide - len - 1;
			while (amount_zero >= 0 && amount_zero--)
				ft_putchar('0');
		}
		return (1);
	}
	return (0);
}

int			prec_less_0_wide_more_len(int len)
{
	int		amount_zero;
	int		amount_spaces;

	amount_zero = 0;
	amount_spaces = 0;
	if (g_struct.nbr_prec < 0 && g_struct.nbr_wide > len)
	{
		amount_spaces = g_struct.nbr_wide - len;
		if (g_struct.neg_nbr == '-' && g_struct.type != 'x'
												&& g_struct.type != 'X')
			amount_spaces--;
		if (g_struct.sign_zero == '0')
			amount_zero = g_struct.nbr_wide - len;
		while (amount_zero >= 0 && amount_zero--)
			ft_putchar('0');
		while (amount_spaces >= 0 && g_struct.sign_zero != '0'
												&& amount_spaces--)
			ft_putchar(' ');
		return (1);
	}
	return (0);
}

int			zero_prec_0_nbr_not_s_not_c(int len, long long nbr)
{
	int		amount_spaces;

	if (g_struct.type != 's' && g_struct.type != 'c'
									&& g_struct.nbr_prec == 0 && nbr == 0)
	{
		amount_spaces = g_struct.nbr_wide - len + 1;
		while (g_struct.type != 's' && amount_spaces >= 0 && amount_spaces--)
			ft_putchar(' ');
		return (1);
	}
	return (0);
}

void		making_width_prec(int i, long long nbr)
{
	int		amount_zero;

	amount_zero = 0;
	if (zero_prec_0_nbr_not_s_not_c(i, nbr) == 1)
		return ;
	else if (nbr_prec_more_eq_to_zero(i, nbr) == 1)
		return ;
	else if (nbr_wide_more_0_not_minus(i, nbr) == 1)
		return ;
}
