/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:07:00 by hcduller          #+#    #+#             */
/*   Updated: 2022/05/05 17:43:46 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	l;
	char	*ptr;

	l = ft_strlen((const char *)s1);
	ptr = ft_calloc(l + 1, sizeof(char));
	if (ptr)
	{
		ptr[l--] = 0;
		while (l + 1 >= 1)
		{
			ptr[l] = s1[l];
			l--;
		}
		return (ptr);
	}
	return (0);
}
