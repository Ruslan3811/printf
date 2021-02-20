#include "printf.h"

void			ft_putchar(char a)
{
	write(1, &a, 1);
	g_amount_symb++;
}

void			making_params_to_zero(void)
{
	g_struct.sign_minus = 0;
	g_struct.sign_star_wide = 0;
	g_struct.type = 0;
	g_struct.sign_plus = 0;
	g_struct.sign_star_presicion = 0;
	g_struct.sign_point_presicion = 0;
	g_struct.precision = 0;
	g_struct.nbr_prec = -1;
	g_struct.nbr_wide = 0;
	g_struct.neg_nbr = 0;
	g_struct.sign_zero = 0;
	g_struct.type = 0;
	g_struct.sign_tag = 0;
	g_struct.add_spaces_at_the_back = 0;
	g_struct.ind = 0;
}

size_t			ft_strlen(const char *mass)
{
	size_t		len;

	len = 0;
	while (mass[len])
		len++;
	return (len);
}

int				ft_strchr(char c)
{
	char		*str;

	str = "csduiXxp%%";
	while (*str != '\0')
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}

int				ft_atoi(const char **format)
{
	long long	nbr;
	int			tmp;

	nbr = 0;
	while (ft_isdigit(format))
	{
		tmp = **format - '0';
		nbr = nbr * 10 + tmp;
		(*format)++;
	}
	(*format)--;
	return ((int)nbr);
}
