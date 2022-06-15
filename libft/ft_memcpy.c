/* ************************************************************************** */
/**/
/*:::  ::::::::   */
/*   ft_memcpy.c:+:  :+::+:   */
/*+:+ +:+ +:+ */
/*   By: llethuil <llethuil@student.42lyon.fr>  +#+  +:+   +#+*/
/*+#+#+#+#+#+   +#+   */
/*   Created: 2021/10/07 17:08:06 by llethuil  #+##+# */
/*   Updated: 2021/12/15 13:55:16 by llethuil ###   ########lyon.fr   */
/**/
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}
