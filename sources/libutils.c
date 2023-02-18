/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyildir <beyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:03:36 by beyildir          #+#    #+#             */
/*   Updated: 2023/01/25 00:07:17 by beyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_strequ(char *s1, char *s2)
{
	int	i;
	int	j;
	int	k;

	j = ft_strlen(s1);
	i = 0;
	k = 0;
	if (s1 && s2)
	{
		while (s1[i])
		{
			if (s1[i] == s2[i])
				k++;
			i++;
		}
		if (j == k)
			return (1);
		return (0);
	}
	return (0);
}

void	ft_putendl(char *s)
{
	if (s)
		write(1, s, ft_strlen(s));
	write(1, "\n", 1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	number;

	sign = 1;
	number = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '.')
	{
		number = (number * 10) + (str[i] - 48);
		i++;
	}
	return (number * sign);
}

double	ft_atod(char *str)
{
	int		i;
	double	res;
	int		j;
	int		kk;
	double	res2;

	kk = 0;
	res = 0;
	j = 0;
	i = 0;
	res2 = ft_atoi(str);
	while (str[i++] != '.')
		if (str[i - 1] == '-')
			kk++;
	if (str[i - 1] == '.')
		j = ft_strlen(&str[i]);
	res = ft_atoi(&str[i]);
	while (j-- > 0)
		res /= 10;
	if (res2 < 0)
		return (res2 - res);
	else if (kk % 2 == 1 && res2 == 0)
		return (-1 * res);
	return (res + res2);
}
