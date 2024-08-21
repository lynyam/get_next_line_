/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynyamets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 23:30:07 by ynyamets          #+#    #+#             */
/*   Updated: 2024/07/29 06:54:07 by ynyamets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# define TRUE 1
# define FALSE 0
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef int	t_bool;
char	*get_next_line(int fd);
t_bool	has_line(char *buf, char **line);
void	join_count_buf_to_line(char *buf, char **line, int count);
void	moove_back_buf_to_count(char *buf, int count);
t_bool	check_new_line(char *buf, int *count);

#endif
