/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynyamets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:07:06 by ynyamets          #+#    #+#             */
/*   Updated: 2024/07/29 07:15:43 by ynyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_bool	check_new_line(char *buf, int *count)
{
	t_bool	ans;

	ans = FALSE;
	while (*count < BUFFER_SIZE && buf[*count])
	{
		if (buf[*count] == '\n')
		{
			*count += 1;
			ans = TRUE;
			break ;
		}
		*count += 1;
	}
	return (ans);
}

void	moove_back_buf_to_count(char *buf, int count)
{
	int	i;

	i = 0;
	while (count < BUFFER_SIZE && buf[count] != '\0')
	{
		buf[i] = buf[count];
		count++;
		i++;
	}
	if (i < BUFFER_SIZE)
		buf[i] = '\0';
}

void	join_count_buf_to_line(char *buf, char **line, int count)
{
	char	*str;
	int		len_line;
	int		i;
	int		j;

	str = NULL;
	len_line = 0;
	i = 0;
	while (*line && (*line)[len_line])
		len_line++;
	str = malloc (sizeof(char) * (len_line + count + 1));
	if (!str)
		return ;
	while (*line && (*line)[i])
	{
		str[i] = (*line)[i];
		i++;
	}
	if (*line)
		free(*line);
	j = 0;
	while (j < count)
		str[i++] = buf[j++];
	str[i] = '\0';
	*line = str;
}

void	init_buf(char *str)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
		str[i++] = '\0';
}

t_bool	has_line(char *buf, char **line)
{
	t_bool	ans;
	int		count;

	ans = FALSE;
	count = 0;
	if (buf[0] == '\0')
		return (FALSE);
	ans = check_new_line(buf, &count);
	join_count_buf_to_line(buf, line, count);
	if (ans == FALSE)
		init_buf(buf);
	else
		moove_back_buf_to_count(buf, count);
	return (ans);
}
