/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirus <kirus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:18:24 by kirus             #+#    #+#             */
/*   Updated: 2022/03/04 21:18:26 by kirus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	qsort_init(int *top, int *arr2, int start, int end)
{
	*top = 1;
	arr2[0] = start;
	arr2[1] = end;
}

static int	partition(int *arr1, int start, int end)
{
	int	end_value;
	int	strt_indx;
	int	curr_indx;

	end_value = arr1[end];
	strt_indx = start - 1;
	curr_indx = start;
	while (curr_indx <= end - 1)
	{
		if (arr1[curr_indx] <= end_value)
		{
			strt_indx++;
			ft_swap(&arr1[strt_indx], &arr1[curr_indx]);
		}
		curr_indx++;
	}
	ft_swap(&arr1[strt_indx + 1], &arr1[end]);
	return (strt_indx + 1);
}

int	quicksort(int *arr1, int start, int end, int pivot)
{
	int	*arr2;
	int	top;

	arr2 = (int *)malloc(end + 4 * sizeof(int));
	if (!arr2)
		return (0);
	qsort_init(&top, &arr2[0], start, end);
	while (top >= 0)
	{
		end = arr2[top--];
		start = arr2[top--];
		pivot = partition(arr1, start, end);
		if (pivot - 1 > start)
		{
			arr2[++top] = start;
			arr2[++top] = pivot - 1;
		}
		if (pivot + 1 < end)
		{
			arr2[++top] = pivot + 1;
			arr2[++top] = end;
		}
	}
	free(arr2);
	return (1);
}
