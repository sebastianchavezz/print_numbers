/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:53:45 by jusilanc          #+#    #+#             */
/*   Updated: 2023/03/12 22:24:38 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"

char	*ft_reader(int fd)
{
	int		buff_size;
	int		ret;
	char	*buff;
	char	*ptr;

	buff_size = 32;
	ret = 1;
	ptr = (void *)0;
	buff = malloc(sizeof(char) * buff_size + 1);
	if (!buff)
		return (NULL);
	while (ret > 0)
	{
		ret = read(fd, buff, buff_size);
		buff[ret] = '\0';
		ptr = ft_str_cat_dup(buff, ptr);
		if (ret < buff_size)
			break ;
	}
	free(buff);
	return (ptr);
}
