/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 23:04:05 by fstitou           #+#    #+#             */
/*   Updated: 2021/12/12 23:04:23 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main()
{
	char	*str;
	int	fd;
	int fd1;
	int fd2;
	
	fd = open("test", O_RDONLY);
	fd1 = open("test1", O_RDONLY);
	fd2 = open("test2", O_RDONLY);
	str	= "";
	while (str)
	{
		str = get_next_line(fd);
		printf ("fd==%s", str);
	}
	str = "";
	while (str)
	{
		str = get_next_line(fd1);
		printf ("fd1==%s", str);
	}
	str = "";
	while (str)
	{
		str = get_next_line(fd2);
		printf ("fd2==%s", str);
	}
	
	
}