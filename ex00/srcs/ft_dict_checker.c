/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:11:59 by jusilanc          #+#    #+#             */
/*   Updated: 2023/03/12 21:47:35 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"

int	ft_dict_checker(t_list *list)
{
	if (ft_list_size(list) < 32)
		return (0);
	while (list && list->next != NULL)
		if (ft_list_find(list->next, list->nb) != NULL)
			return (0);
	return (1);
}
