#include "printf.h"

void	ft_put_str_char(char *str, int len)
{
	int smb;
	int amount_spaces;

	smb = (g_struct.nbr_prec >= 0 && len >= g_struct.nbr_prec) ?
													g_struct.nbr_prec : len;
	amount_spaces = (g_struct.nbr_prec >= 0 || g_struct.nbr_wide >= smb) ?
													g_struct.nbr_wide - smb : 0;
	g_struct.add_spaces_at_the_back = (g_struct.sign_minus == '-') ?
													g_struct.nbr_wide - smb : 0;
	while (g_struct.sign_minus != '-' && amount_spaces >= 0 && amount_spaces--)
		ft_putchar(' ');
	while (g_struct.type == 's' && *str && smb >= 0 && smb--)
	{
		(g_struct.nbr_prec != 0) ? ft_putchar(*str) : 0;
		str++;
	}
	(g_struct.type == 'c') ? ft_putchar(*str) : 0;
}
