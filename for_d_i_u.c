#include "printf.h"

int				count_digits_in_nbr(long long nbr)
{
	int			i;

	i = 0;
	if (nbr == 0)
		i++;
	while (nbr)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

void			making_percent(void)
{
	int			amount_spaces;
	int			amount_zero;

	amount_spaces = g_struct.nbr_wide - 1;
	amount_zero = amount_spaces;
	while (g_struct.sign_minus == 0 && g_struct.sign_zero == 0
									&& amount_spaces >= 0 && amount_spaces--)
	{
		ft_putchar(' ');
	}
	while (g_struct.sign_minus == 0 && g_struct.sign_zero == '0'
									&& amount_zero >= 0 && amount_zero--)
	{
		ft_putchar('0');
	}
	ft_putchar('%');
	if (g_struct.sign_minus == '-')
	{
		while (amount_spaces >= 0 && amount_spaces--)
			ft_putchar(' ');
	}
}

void			making_exp(int i, long long copy_nbr, long long nbr)
{
	int			exponent;
	char		digit;

	exponent = 1;
	if (copy_nbr < 0)
		copy_nbr = copy_nbr * -1;
	while (--i)
	{
		exponent = exponent * 10;
	}
	while (exponent)
	{
		digit = ((copy_nbr / exponent) % 10) + 48;
		if (nbr != 0)
			ft_putchar(digit);
		exponent = exponent / 10;
	}
}

int				ft_isdigit(const char **format)
{
	if (**format >= '0' && **format <= '9')
		return (1);
	return (0);
}
