/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 22:57:02 by jusilanc          #+#    #+#             */
/*   Updated: 2023/03/12 23:13:13 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"

void	ft_number_printer(t_list *list, char *nbr)
{
	char	c;

	if (ft_atoi(nbr) > 20)
	{
		if (nbr[0] > '0' && ft_atoi(nbr) > 99)
		{
			c = nbr[0];
			ft_putstr(ft_list_find(list, ft_atoi(&c))->data);
			write(1, " ", 1);
			ft_putstr(ft_list_find(list, 100)->data);
			write(1, " ", 1);
		}
		if (ft_atoi(&nbr[1]) <= 20 && ft_atoi(&nbr[1]) > 0 && ft_atoi(nbr) > 99)
			ft_putstr(ft_list_find(list, ft_atoi(&nbr[1]))->data);
		else if (ft_atoi(&nbr[1]) > 20)
		{
			ft_putstr(ft_list_find(list, ft_atoi(&nbr[1]) / 10 * 10)->data);
			write(1, " ", 1);
			if (ft_atoi(&nbr[1]) % 10 > 0)
				ft_putstr(ft_list_find(list, ft_atoi(&nbr[1]) % 10)->data);
		}
	}
	else if (ft_atoi(nbr) <= 20)
		ft_putstr(ft_list_find(list, ft_atoi(nbr))->data);
}

void	ft_print_cutter_next(t_list *list, int len)
{
	write(1, " ", 1);
	if (len > 9)
		ft_putstr(ft_list_find(list, 1000000000)->data);
	else if (len > 6)
		ft_putstr(ft_list_find(list, 1000000)->data);
	else if (len > 3)
		ft_putstr(ft_list_find(list, 1000)->data);
	write(1, " ", 1);
}

void	ft_print_cutter_second(t_list *list, int len, char *tab_nbr)
{
	if (ft_atoi(tab_nbr) || len < 3)
		ft_number_printer(list, tab_nbr);
	if (len > 3 && ft_atoi(tab_nbr))
		ft_print_cutter_next(list, len);
}

void	ft_print_cutter(t_list *list, char *nbr)
{
	int		len;
	int		i;
	char	*tab_nbr;

	len = ft_strlen(nbr);
	tab_nbr = malloc(sizeof(char) * 4);
	while (nbr && *nbr && len > 0)
	{
		i = 0;
		if (!(len % 3) && *nbr)
			while (i < 3)
				tab_nbr[i++] = *nbr++;
		else
		{
			tab_nbr[i++] = '0';
			if (len % 3 == 2)
				tab_nbr[i++] = *nbr++;
			else
				tab_nbr[i++] = '0';
			tab_nbr[i++] = *nbr++;
		}
		tab_nbr[i] = '\0';
		ft_print_cutter_second(list, len, tab_nbr);
		if (tab_nbr[0] == '0')
			i--;
		if (tab_nbr[1] == '0')
			i--;
		len -= i;
	}
	free(tab_nbr);
}
