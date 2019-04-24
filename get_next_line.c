/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitruk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 19:56:07 by ssitruk           #+#    #+#             */
/*   Updated: 2019/04/24 17:18:10 by ssitruk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	int				ret;
	char 			*tmp;
	char			buf[BUFF_SIZE + 1];
	int				c;
	static char		*rest;

	c = 0;
	if (!rest)
		rest = ft_strdup("");
	if (fd < 0 || !line)
		return (-1);
	while (!(ft_strchr(rest, '\n')) && ((ret = read(fd, buf, BUFF_SIZE)) > 0))
	{
		buf[ret] = '\0';
		rest = ft_strjoin_free(rest, buf, 1);
	}
	if (ret == -1)
	{
		ft_strclr(rest);
		return (-1);
	}
	while (rest[c] && rest[c] != '\n')
		c++;
	(*line) = ft_strsub(rest, 0, c);
	tmp = rest;
	if (rest[c] == '\n')
		rest = ft_strdup(rest + c + 1);
	else
		rest = ft_strnew(0);
	free(tmp);
	if (ft_strlen(*line))
		return (1);
	return (ret > 0 ? 1 : 0);
}
