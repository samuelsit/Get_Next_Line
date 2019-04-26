/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitruk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 19:56:07 by ssitruk           #+#    #+#             */
/*   Updated: 2019/04/24 18:02:15 by ssitruk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

int		len_line(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char		*new_line(char *rest)
{
	if (rest[len_line(rest)] == '\n')
		rest = ft_strdup(&rest[len_line(rest) + 1]);
	else
		rest = ft_strnew(0);
	return (rest);
}

int		get_next_line(const int fd, char **line)
{
	int				ret;
	char			*tmp;
	char			buf[BUFF_SIZE + 1];
	static char		*rest;

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
	(*line) = ft_strsub(rest, 0, len_line(rest));
	tmp = rest;
	rest = new_line(rest);
	free(tmp);
	if (len_line(*line))
		return (1);
	return (ret > 0 ? 1 : 0);
}
