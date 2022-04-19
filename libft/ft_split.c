/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 09:01:29 by hoomen            #+#    #+#             */
/*   Updated: 2022/04/03 10:57:38 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static size_t	ft_nsubs(char const *s, char c)
{
	size_t	i;
	size_t	nsubs;

	i = 0;
	nsubs = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			nsubs++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (nsubs);
}

static void	ft_free(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static char	*ft_makesub(char **arr, char *ptr, char c)
{
	char	*sub;
	char	*delim;
	size_t	sublen;

	delim = ft_strchr((const char *)ptr, c);
	if (delim == NULL)
		sublen = ft_strlen(ptr);
	else
		sublen = delim - ptr;
	sub = ft_calloc(sublen + 1, sizeof(char));
	if (sub == NULL)
	{
		ft_free(arr);
		return (NULL);
	}
	sub = ft_memcpy((void *)sub, (const void *)ptr, sublen);
	return (sub);
}

char	**ft_split(char const *s, char c)
{
	size_t	nsubs;
	size_t	i;
	char	**arr;
	char	*ptr;

	if (!s)
		return (NULL);
	nsubs = ft_nsubs(s, c);
	arr = ft_calloc(nsubs + 1, sizeof(char *));
	if (arr == NULL)
		return (NULL);
	i = 0;
	ptr = (char *)s;
	while (i < nsubs)
	{
		while (*ptr == c)
			ptr++;
		arr[i] = ft_makesub(arr, ptr, c);
		ptr = ptr + ft_strlen(arr[i]);
		i++;
	}
	return (arr);
}
