#include "printf.h"

void		check_precision(const char **format)
{
	(*format)++;
	if (**format == '.')
	{
		g_struct.sign_point_presicion = '.';
		(*format)++;
		g_struct.nbr_prec = 0;
		if (**format == '*')
		{
			g_struct.sign_star_presicion = '*';
			g_struct.nbr_prec = va_arg(g_argptr, int);
			(*format)++;
		}
		else if (ft_isdigit(format))
		{
			g_struct.nbr_prec = ft_atoi(format);
			(*format)++;
		}
	}
}

void		check_wide(const char **format)
{
	(*format)++;
	if (**format == '*')
	{
		g_struct.sign_star_wide = '*';
		g_struct.nbr_wide = va_arg(g_argptr, int);
		if (g_struct.nbr_wide < 0)
		{
			g_struct.nbr_wide = g_struct.nbr_wide * -1;
			g_struct.sign_minus = '-';
		}
		(*format)++;
	}
	if (ft_isdigit(format))
	{
		g_struct.nbr_wide = ft_atoi(format);
		(*format)++;
	}
	(*format)--;
}

void		check_flags(const char **format)
{
	(*format)++;
	while (**format == '-' || **format == '+' || **format == '0')
	{
		if (**format == '-')
		{
			g_struct.sign_minus = '-';
			(*format)++;
		}
		else if (**format == '+')
		{
			g_struct.sign_plus = '+';
			(*format)++;
		}
		else if (**format == '0')
		{
			g_struct.sign_zero = '0';
			(*format)++;
		}
	}
	(*format)--;
}

int			type(int ind, const char **format)
{
	if (ft_strchr(format[0][ind]) == 1)
	{
		g_struct.type = format[0][ind];
		check_flags(format);
		check_wide(format);
		check_precision(format);
		if (ft_parse() == -1)
			return (-1);
		(*format)++;
		return (1);
	}
	return (0);
}

int			ft_printf(const char *format, ...)
{
	g_amount_symb = 0;
	va_start(g_argptr, format);
	while (*format != 0)
	{
		if (*format == '%')
		{
			making_params_to_zero();
			while (format[g_struct.ind] && !ft_strchr(g_struct.type))
			{
				if (g_struct.ind > 0 && type(g_struct.ind, &format) == 1)
				{
					making_params_to_zero();
					break ;
				}
				g_struct.ind++;
			}
		}
		if (*format != '%' && *format != '\0')
		{
			ft_putchar(*format);
			format++;
		}
	}
	va_end(g_argptr);
	return (g_amount_symb);
}
