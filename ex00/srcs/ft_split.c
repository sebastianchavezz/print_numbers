/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 06:29:58 by juliensilan       #+#    #+#             */
/*   Updated: 2023/03/12 14:20:04 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush02.h"

static int	ft_strchr(char *str, char c)
{
	int		i;

	i = 0;
	if (!c)
		return (0);
	while (str && str[i] && c)
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static int	ft_word_counter(char *str, char *charset)
{
	int	word;

	word = 0;
	while (str && *str)
	{
		if (ft_strchr(charset, *str) > -1)
			str++;
		else
		{
			while (*str && ft_strchr(charset, *str) == -1)
				str++;
			word++;
		}
	}
	return (word);
}

static char	*ft_strndup(char *str, int start, int end)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = malloc(sizeof(char) * end - start + 1);
	if (!ptr)
		return ((void *)0);
	while (start < end)
		ptr[i++] = str[start++];
	ptr[i] = '\0';
	return (ptr);
}

char	**ft_split(char *str, char *charset)
{
	char	**ptr;
	int		i;
	int		j;
	int		word_count;

	i = 0;
	word_count = ft_word_counter(str, charset);
	ptr = (char **)malloc (sizeof(char *) * (word_count + 1));
	if (!ptr)
		return ((void *)0);
	while (str && *str && i < word_count)
	{
		while (str && *str && ft_strchr(charset, *str) > -1)
			str++;
		j = 0;
		while (str && *str && ft_strchr(charset, str[j]) == -1)
			j++;
		ptr[i++] = ft_strndup(str, 0, j);
		str += j;
	}
	ptr[i] = 0;
	return (ptr);
}
