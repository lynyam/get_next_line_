/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynyamets <ynyamets@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:11:35 by ynyamets          #+#    #+#             */
/*   Updated: 2024/07/29 06:40:57 by ynyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	buf[BUFFER_SIZE];
	int			n;

	line = NULL;
	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	if (has_line(buf, &line))
		return (line);
	while (1)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n <= 0)
			return (line);
		if (n < BUFFER_SIZE)
			buf[n] = '\0';
		if (has_line(buf, &line))
			return (line);
	}
}
