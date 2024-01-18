/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:03:48 by mvolkman          #+#    #+#             */
/*   Updated: 2024/01/17 08:52:55 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*constr;
	size_t	i;
	size_t	x;

	if (!s1 || !s2)
		return (NULL);
	constr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!constr)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		constr[i] = s1[i];
		i++;
	}
	x = 0;
	while (s2[x] != '\0')
		constr[i++] = s2[x++];
	constr[i] = '\0';
	return (constr);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && (unsigned char)s[i] != (unsigned char)c)
		i++;
	if (s[i] == (unsigned char)c)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t n)
{
	size_t	strlen;
	size_t	sublen;
	char	*newstr;
	size_t	i;

	if (!s)
		return (NULL);
	strlen = ft_strlen(s);
	if (start >= strlen)
		return (ft_strdup(""));
	sublen = n;
	if (sublen > (strlen - start))
		sublen = strlen - start;
	newstr = (char *)malloc(sublen + 1);
	if (!newstr)
		return (NULL);
	i = 0;
	while (i < sublen)
	{
		newstr[i] = s[start + i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
