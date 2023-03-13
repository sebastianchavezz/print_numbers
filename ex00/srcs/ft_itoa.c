/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:52:50 by jusilanc          #+#    #+#             */
/*   Updated: 2023/03/12 22:30:44 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"

// int to char
char	*ft_itoa(int num)
{	
	int		count;
	int		temp;
	int		j;
	char	*str;

	count = 0;
	temp = num;
	while (temp > 0)
	{
		count++;
		temp /= 10;
	}
	str = malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	j = count - 1;
	while (num > 0)
	{
		str[j] = num % 10 + '0';
		num /= 10;
		j--;
	}
	str[count] = '\0';
	return (str);
}
