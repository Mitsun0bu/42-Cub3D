/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:26:49 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/30 17:26:52 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_get_line(int fd, char *line, char *buff);
static int	ft_find_nl_index(char *s);
static char	*ft_gnl_join(char *line, char *buff);
static void ft_fill_joined(char *line, char *buff, char *joined);

char	*ft_get_next_line(int fd)
{
	char		*line = NULL;
	static char	buff[BUFFER_SIZE + 1] = {};

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(sizeof(char) * 1);
	if (!line)
		return (NULL);
	line[0] = 0;
	line = ft_get_line(fd, line, buff);
	if (line && ft_strlen(line))
		return (line);
	free(line);
	return (NULL);
}

static char	*ft_get_line(int fd, char *line, char *buff)
{
	char	*buff_rest = NULL;
	int		read_ret = 1;

	while (read_ret > 0)
	{
		line = ft_gnl_join(line, buff);
		if (!line)
			return (NULL);
		if (ft_find_nl_index(buff) != NO_NL)
		{
			buff_rest = &buff[ft_find_nl_index(buff) + 1];
			while (*buff_rest)
				*buff++ = *buff_rest++;
			*buff = '\0';
			return (line);
		}
		read_ret = read(fd, buff, BUFFER_SIZE);
		if (read_ret == -1)
		{
			free(line);
			return (NULL);
		}
		buff[read_ret] = '\0';
	}
	return (line);
}

static int	ft_find_nl_index(char *s)
{
	int	i = 0;

	if (!s)
		return (NO_NL);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i ++;
	}
	return (NO_NL);
}

static char	*ft_gnl_join(char *line, char *buff)
{
	char	*joined = NULL;
	int		buff_size = 0;

	if (ft_find_nl_index(buff) == NO_NL)
		buff_size = ft_strlen(buff);
	else
		buff_size = ft_find_nl_index(buff);
	joined = malloc(sizeof(char) * (ft_strlen(line) + buff_size + 2));
	if (!joined)
		return (NULL);
	ft_fill_joined(line, buff, joined);
	free(line);
	return (joined);
}

static void ft_fill_joined(char *line, char *buff, char *joined)
{
	int	i_l;
	int	i_b;

	i_l = -1;
	while (line[++i_l])
		joined[i_l] = line[i_l];
	i_b = -1;
	while (buff[++i_b])
	{
		joined[i_l] = buff[i_b];
		if (buff[i_b] == '\n')
		{
			i_l++;
			break ;
		}
		i_l ++;
	}
	joined[i_l] = '\0';
}