/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_to_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:59:48 by jusilanc          #+#    #+#             */
/*   Updated: 2023/03/12 22:22:12 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"

static char	*ft_second_param(char *str)
{
	while (str && *str && *str >= '0' && *str <= '9')
		str++;
	while (str && *str && *str == 32)
		str++;
	if (str && *str && *str == ':')
		str++;
	while (str && *str && *str == 32)
		str++;
	return (str);
}

static char	*ft_strdup_to_newl(char *str)
{
	char	*newstr;
	int		i;

	i = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	newstr = malloc(sizeof(char) * (i + 1));
	if (!newstr)
		return ((void *)0);
	i = -1;
	while (str && str[++i] && str[i] != '\n')
		newstr[i] = str[i];
	newstr[i] = '\0';
	return (newstr);
}

t_list	*ft_split_to_list(char **tab)
{
	int		i;
	int		t;
	t_list	*ptr;

	i = 0;
	ptr = (void *)0;
	while (tab && tab[i])
	{
		t = ft_atoi(tab[i]);
		ft_list_push_back(&ptr, ft_strdup_to_newl(ft_second_param(tab[i])), t);
		i++;
	}
	ft_split_frier(tab);
	return (ptr);
}
