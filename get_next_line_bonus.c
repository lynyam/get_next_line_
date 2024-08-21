/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynyamets <ynyamets@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:11:35 by ynyamets          #+#    #+#             */
/*   Updated: 2024/07/29 07:02:14 by ynyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	buf[FD_SETSIZE + 1][BUFFER_SIZE];
	int			n;

	line = NULL;
	if (BUFFER_SIZE < 1 || fd < 0 || fd >= FD_SETSIZE)
		return (NULL);
	if (has_line(buf[fd], &line))
		return (line);
	while (1)
	{
		n = read(fd, buf[fd], BUFFER_SIZE);
		if (n <= 0)
			return (line);
		if (n < BUFFER_SIZE)
			buf[fd][n] = '\0';
		if (has_line(buf[fd], &line))
			return (line);
	}
}
