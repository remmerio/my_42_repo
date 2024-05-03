/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:09:20 by mbellard          #+#    #+#             */
/*   Updated: 2023/12/27 16:09:23 by mbellard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	*range;
	int	i;
	int	size;
	
	
	if (start > end)
		size = (start - end + 1);
	else
		size = (end - start + 1);
	range = (int *)malloc(sizeof(int) * size);
	if (range == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (end <= start)
		{
			range[i] = start;
			start--;
		}
		else
			range[i] = end + i;
		i++;
	}
	return (range);
}

int        main(void)
{
    int *nums;
    int start = 10;
    int end = 10;
    int size = 0;

    nums = ft_range(start, end);
    while (size < 1)
    {
    	printf("%d\n", nums[size]);
    	size++;
    }
    return (0);
}
