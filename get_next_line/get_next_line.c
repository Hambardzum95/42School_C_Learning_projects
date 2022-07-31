/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 14:59:54 by hmkrtchy          #+#    #+#             */
/*   Updated: 2021/03/21 18:36:57 by hmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	const	char	*ptr;
	size_t			count;

	count = 0;
	ptr = str;
	while (*ptr)
	{
		++ptr;
		++count;
	}
	return (count);
}

char	*ft_strnew(size_t size)
{
	return (ft_memalloc((size + 1) * sizeof(char)));
}

void	*ft_memalloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, size);
	return (ptr);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned	char	*ub;

	ub = (unsigned char *)b;
	while (len > 0)
	{
		*ub = c;
		len--;
		ub++;
	}
	return (b);
}

int		get_next_line(int fd, char **line)
{
	ssize_t		p;
	char		bf[BUFFER_SIZE + (p = 1)];
	static char	*s_line = NULL;
	char		*tmp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	s_line == NULL ? s_line = ft_strnew(0) : NULL;
	while (!ft_strchr(s_line, '\n') && (p = read(fd, bf, BUFFER_SIZE)) > 0)
	{
		bf[p] = '\0';
		tmp = ft_strjoin(s_line, bf);
		ft_memdel((void **)&s_line);
		s_line = tmp;
	}
	if (p == 0)
		*line = ft_strdup(s_line);
	else if (p > 0)
		*line = ft_substr(s_line, 0, (ft_strchr(s_line, '\n') - s_line));
	else
		return (-1);
	tmp = ft_strdup(s_line + (ft_strlen(*line) + ((p > 0) ? +1 : +0)));
	ft_memdel((void **)&s_line);
	s_line = tmp;
	return (p == 0 ? 0 * ft_memdel((void **)&s_line) : 1);
}
