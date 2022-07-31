/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapyan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:40:10 by rpapyan           #+#    #+#             */
/*   Updated: 2022/07/31 21:28:11 by rpapyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char *str;
	size_t		cnt;
	size_t		i;
	char		**str2;

	str = malloc(BUFFER_SIZE + 1);
	cnt = read(fd, str, BUFFER_SIZE);
	str[BUFFER_SIZE] = '\0';
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			str2 = ft_split(str, '\n');
			str = str2[1];
			return (str2[0]);
		}
		i++;
	}
	if ((cnt == 0 && ft_strlen(str) == 0) || !(str))
		return (NULL);
	return (str);
}
