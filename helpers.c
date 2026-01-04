/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoia <ykoia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 20:58:59 by ykoia             #+#    #+#             */
/*   Updated: 2026/01/04 12:55:01 by ykoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_header.h"

int	ft_isdigit(char *str)
{
	while (*str)
	{
		if ((*str < '0' || *str > '9') && (*str != '-' && *str != '+'))
			return (0);
		str++;
	}
	return (1);
}

long	ft_atoi(const char *str)
{
	long	result;
	int		x;

	result = 0;
	x = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			x = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * x);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	dst = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dst)
		return (NULL);
	str = dst;
	while (*s1)
		*(str++) = *(s1++);
	while (*s2)
		*(str++) = *(s2++);
	*str = 0;
	return (dst);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_avjoin(int ac, char **av)
{
	int		i;
	char	*str;
	char	*tmp;

	str = ft_strjoin(av[0], " ");
	i = 1;
	while (i < ac)
	{
		tmp = str;
		str = ft_strjoin(tmp, av[i]);
		free(tmp);
		tmp = str;
		str = ft_strjoin(tmp, " ");
		free(tmp);
		i++;
	}
	return (str);
}
