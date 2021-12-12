/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 22:19:53 by fstitou           #+#    #+#             */
/*   Updated: 2021/12/12 22:28:52 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	extract_line_modify_save(char **save, char **line)
{
	char	*temp;

	*line = ft_substr(*save, 0, (ft_strchr(*save, '\n') + 1));
	temp = *save;
	*save = ft_substr(*save, (ft_strchr(*save, '\n') + 1), (ft_strlen(*save)));
	free(temp);
}

char	*ft_free(char **str)
{
	if (*str)
		free(*str);
	*str = NULL;
	return (*str);
}

char	*get_next_line(int fd)
{
	static char	*save[1024];
	char		buf[BUFFER_SIZE + 1];
	char		*line;
	int			l;
	char		*temp;

	while (ft_strchr(save[fd], '\n') == -1)
	{
		l = read(fd, buf, BUFFER_SIZE);
		if (l == 0 || l == -1)
		{
			if ((save[fd] && save[fd][0] == '\0'))
				return (ft_free(&save[fd]));
			temp = save[fd];
			save[fd] = NULL;
			return (temp);
		}
		buf[l] = '\0';
		temp = save[fd];
		save[fd] = ft_strjoin(save[fd], buf);
		ft_free(&temp);
	}
	extract_line_modify_save(&save[fd], &line);
	return (line);
}
