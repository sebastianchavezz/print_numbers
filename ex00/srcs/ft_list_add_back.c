/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_add_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:34:21 by jusilanc          #+#    #+#             */
/*   Updated: 2023/03/12 18:45:50 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"

static t_list	*ft_list_last(t_list *begin_list)
{
	while (begin_list && begin_list->next)
		begin_list = begin_list->next;
	return (begin_list);
}

void	ft_list_push_back(t_list **begin_list, void *data, int nb)
{
	if (!begin_list || !*begin_list)
		*begin_list = ft_create_elem(data, nb);
	else
		ft_list_last(*begin_list)->next = ft_create_elem(data, nb);
}
