/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:41:12 by jusilanc          #+#    #+#             */
/*   Updated: 2023/03/12 14:51:45 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"

t_list	*ft_list_find(t_list *begin_list, int nb)
{
	while (begin_list)
	{
		if (begin_list->nb == nb)
			return (begin_list);
		begin_list = begin_list->next;
	}
	return (NULL);
}
