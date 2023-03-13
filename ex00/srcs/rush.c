/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 10:53:44 by schavez           #+#    #+#             */
/*   Updated: 2023/03/12 23:12:56 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"

int	how_long_dinct(char *buf)
{
	int	teller;
	int	i;

	i = 0;
	teller = 0;
	while (*(buf + i) != '\0')
	{
		if (*(buf + i) == '\n')
		{
			teller++;
		}
		i++;
	}
	return (teller);
}

int	ft_error(int nb)
{
	if (nb == 2)
		write(2, "Error\n", 6);
	else if (nb == 1)
		write(2, "Dict Error\n", 11);
	return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && *str++)
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	while (str && *str)
		write(1, str++, 1);
}

int	main(int ac, char **ag)
{
	int		fd;
	char	*file_path;
	char	*nbr;
	char	*ptr;
	t_list	*t_ptr;

	file_path = "numbers.dict";
	nbr = ag[1];
	if (ac == 3)
	{
		file_path = ag[1];
		nbr = ag[2];
	}
	fd = open(file_path, O_RDONLY);
	if (fd == -1 || !ft_is_numeric(nbr))
		return (ft_error(2));
	ptr = ft_reader(fd);
	t_ptr = ft_split_to_list(ft_split(ptr, "\n"));
	ft_print_cutter(t_ptr, nbr);
	write(1, "\n", 1);
	ft_list_clear(t_ptr, free);
	free(ptr);
	close(fd);
	return (0);
}
