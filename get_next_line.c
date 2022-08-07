/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapyan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:40:10 by rpapyan           #+#    #+#             */
/*   Updated: 2022/08/07 18:40:18 by rpapyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char *str;
	size_t		cnt;
	size_t		i;
	char		*rtn;
	size_t		pin;

	if (!str)
	{
		str = malloc(BUFFER_SIZE);
		if (!str)
			return (NULL);
	}
	cnt = read(fd, str, BUFFER_SIZE);
	str[BUFFER_SIZE] = '\0';
	i = 0;
//	printf("%s", str);
	while (str[i])
	{
		if (str[i] == '\n')
		{
//			printf("%c", str[i - 1]);
			rtn = malloc(i);
			rtn[i] = '\0';
//			printf("%s", rtn);
			pin = i + 1;
			while (str[i])
			{
//				printf("%c", str[i]);
				rtn[i] = str[i];
				i--;
			}
			i = 0;
			while (str[pin])
			{
				str[i] = str[pin];
				pin++;
				i++;
			}
			return (rtn);	
		}				
		i++;
	}
	
	cnt = 0;
/*	if (str)
	{
		while (str[i])
		{	
			if (str[i] == '\n')
			{
				rtn = malloc(i + 1);
				ft_strncpy(rtn, str, i);
				rtn[i] == '\0';
				i++;
				j = 0;
				while (i <= BUFFER_SIZE)
				{
					str[j] = str[i];
					j++;
					i++;
				}
				return (rtn);
			}	
			i++;
		}
	}
	*/
	if ((cnt == 0 && ft_strlen(str) == 0) || !(str))
		return (NULL);
	return (str);
}
