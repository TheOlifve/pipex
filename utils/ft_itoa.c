/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:03:00 by hrahovha          #+#    #+#             */
/*   Updated: 2023/03/16 01:54:53 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	num_len(int n)
{
	int	i;

	i = 1;
	if (n > 9)
	{
		while (n > 9)
		{
			n = n / 10;
			i++;
		}
	}
	else if (n <= -1)
	{
		while (n < -9)
		{
			n = n / 10;
			i++;
		}
		i++;
	}
	return (i);
}

char	*is_pos(int n)
{
	int		len;
	char	*s;

	len = num_len(n);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	s[len] = '\0';
	while (len > 0)
	{
		len--;
		s[len] = n % 10 + 48;
		n = n / 10;
	}
	return (s);
}

char	*is_neg(int n)
{
	int		len;
	char	*s;

	len = num_len(n);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	s[len] = '\0';
	s[0] = '-';
	while (len > 1)
	{
		len--;
		s[len] = -(n % 10) + 48;
		n = n / 10;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	if (n >= 0)
		return (is_pos(n));
	else
		return (is_neg(n));
	return (NULL);
}
