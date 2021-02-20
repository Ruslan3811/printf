#include "printf.h"

void					putchar_x_p(int i, unsigned int *ptr_int, int d)
{
	while (d >= 0)
	{
		if (ptr_int[d] <= 9 && ptr_int[d] >= 0)
		{
			if (i != 1 || g_struct.type != 'p')
				ft_putchar(ptr_int[d] + 48);
			else
				ft_putchar('x');
		}
		else if (ptr_int[d] > 9)
		{
			if (g_struct.type == 'x' || g_struct.type == 'p')
				ft_putchar(ptr_int[d] - 9 + 96);
			else if (g_struct.type == 'X')
				ft_putchar(ptr_int[d] - 9 + 64);
		}
		i++;
		d--;
	}
}

void					calculation(unsigned long nbr,
									int i, unsigned int *ptr_int)
{
	unsigned long		ost;
	int					d;

	d = 0;
	while (--i)
	{
		ost = nbr % 16;
		nbr = nbr / 16;
		ptr_int[d] = ost;
		d++;
	}
	ost = nbr % 16;
	nbr = nbr / 16;
	ptr_int[d] = ost;
	putchar_x_p(i, ptr_int, d);
}

int						amount_digits_x_p(unsigned long nbr)
{
	int					i;

	i = 0;
	if (g_struct.type == 'p')
		i = i + 2;
	if (nbr == 0 && g_struct.type != 'p')
		return (1);
	while (nbr >= 16)
	{
		nbr = nbr / 16;
		i++;
	}
	i++;
	return (i);
}

int						ft_putnbr_for_x_p(unsigned long nbr, int i)
{
	int					d;
	int					copy_nbr;
	unsigned int		*ptr_int;

	d = 0;
	copy_nbr = nbr;
	if (g_struct.type == 'p' && nbr == 0)
	{
		ft_putchar('0');
		ft_putchar('x');
		if (g_struct.nbr_prec != 0)
			ft_putchar('0');
		return (1);
	}
	ptr_int = (unsigned int *)malloc(sizeof(unsigned long) * (i));
	if (!ptr_int)
		return (-1);
	calculation(nbr, i, ptr_int);
	if (ptr_int)
		free(ptr_int);
	return (0);
}
