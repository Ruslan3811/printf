#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int g_amount_symb;
va_list g_argptr;

int					ft_printf(const char *format, ...);
int					ft_parse(void);
int					count_digits_in_nbr(long long nbr);
int					ft_atoi(const char **format);
int					ft_isdigit(const char **format);
int					ft_putnbr_for_x_p(unsigned long nbr, int i);
int					amount_digits_x_p(unsigned long nbr);
int					ft_strchr(char c);
int					nbr_prec_more_eq_to_zero(int len, long long nbr);
int					nbr_wide_more_0_not_minus(int len, long long nbr);
int					prec_less_0_wide_more_len(int len);
int					neg_nbr(int len);
int					neg_prec(int len);
void				ft_putchar(char a);
void				ft_put_str_char(char *str, int i);
void				making_params_to_zero(void);
void				making_width_prec(int i, long long nbr);
void				making_percent(void);
void				making_exp(int i, long long copy_nbr, long long nbr);
size_t				ft_strlen(const char *mass);

typedef struct		s_elements
{
	char			*str;
	char			symb;
	char			type;
	char			precision;
	char			sign_minus;
	char			sign_plus;
	char			sign_tag;
	char			sign_zero;
	char			sign_star_wide;
	char			sign_point_presicion;
	char			sign_star_presicion;
	char			neg_nbr;
	int				nbr_wide;
	int				nbr_prec;
	int				add_spaces_at_the_back;
	long long		nbr;
	size_t			ind;
}					t_elements;

t_elements			g_struct;
#endif
