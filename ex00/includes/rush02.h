/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusilanc <jusilanc@s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:55:02 by jusilanc          #+#    #+#             */
/*   Updated: 2023/03/12 23:10:06 by jusilanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_list	t_list;

struct		s_list
{
	int		nb;
	void	*data;
	t_list	*next;
};

char	*ft_itoa(int num);
char	**ft_split(char *str, char *charset);
int		*keys_parse(char *buf, int size);
void	value_parser(char *buf, char *c);
void	number_parse(int num, int keys[], int s, char *buf);

int		how_long_dinct(char *buf);
char	*get_memory_place(char *str, char *to_find);

t_list	*ft_create_elem(void *data, int nb);
void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *));
void	ft_list_push_back(t_list **begin_list, void *data, int nb);
t_list	*ft_list_find(t_list *begin_list, int nb);

char	*ft_str_cat_dup(char *src, char *dest);
int		ft_atoi(char *str);
char	*ft_strdup(char *str);
void	ft_split_frier(char **tab);
t_list	*ft_split_to_list(char **tab);

char	*ft_reader(int fd);
int		ft_is_numeric(char *str);
int		ft_list_size(t_list *begin_list);
int		ft_dict_checker(t_list *list);

void	ft_print_cutter(t_list *list, char *nbr);
void	ft_print_cutter_second(t_list *list, int len, char *tab_nbr);
void	ft_print_cutter_next(t_list *list, int len);
void	ft_number_printer(t_list *list, char *nbr);
int		ft_strlen(char *str);
int		ft_error(int nb);
void	ft_putstr(char *str);

#endif