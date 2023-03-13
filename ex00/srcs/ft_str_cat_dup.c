/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_cat_dup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:59:53 by jusilanc          #+#    #+#             */
/*   Updated: 2023/03/12 23:02:27 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"

char	*ft_strdup(char *str)
{
	char	*newstr;
	int		i;

	i = 0;
	while (str && str[i])
		i++;
	newstr = malloc(sizeof(char) * (i + 1));
	if (!newstr)
		return ((void *)0);
	i = -1;
	while (str && str[++i])
		newstr[i] = str[i];
	newstr[i] = '\0';
	return (newstr);
}

char	*ft_str_cat_dup(char *str, char *ptr)
{
	int		str_len;
	int		ptr_len;
	int		i;
	int		j;
	char	*new_ptr;

	str_len = ft_strlen(str);
	ptr_len = ft_strlen(ptr);
	new_ptr = malloc(sizeof(char) * (ptr_len + str_len + 1));
	if (!new_ptr)
		return (NULL);
	i = 0;
	j = -1;
	while (ptr && ptr[i])
	{
		new_ptr[i] = ptr[i];
		i++;
	}
	while (str && str[++j])
		new_ptr[i + j] = str[j];
	new_ptr[i + j] = '\0';
	free(ptr);
	return (new_ptr);
}
