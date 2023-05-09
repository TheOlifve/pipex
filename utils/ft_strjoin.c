/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 21:27:28 by hrahovha          #+#    #+#             */
/*   Updated: 2023/03/17 17:56:40 by hrahovha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;
	char	*str;

	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = malloc(s1_len + s2_len + 1);
	if (!str)
		return (NULL);
	while (s1 && i < s1_len)
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && i < s1_len + s2_len)
	{
		str[i] = *s2++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
