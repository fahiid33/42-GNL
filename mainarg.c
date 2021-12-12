/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 01:59:44 by fstitou           #+#    #+#             */
/*   Updated: 2021/12/12 22:40:08 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(int ac, char **av)
{
	int		i;
	int		j;
	int	tab[ac];
	char	*str;

	i = 1;	
	while (i < ac)
	{
		tab[i - 1] = open(av[i], O_RDONLY);	
		i++;
	}
	i = 0 ;
	j = 0;
	while (j < 9)
	{
		i = 0;
		while (i < ac - 1)
		{
			str = get_next_line(tab[i]);
			printf ("%s", str);
			i++;
		}
		j++;
		str = "";
	}
}
