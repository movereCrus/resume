/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirus <kirus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 20:43:54 by kirus             #+#    #+#             */
/*   Updated: 2022/03/04 21:28:46 by kirus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*optimal_push(t_stack *b_ptr)
{
	t_stack	*optimum;
	int		min;

	min = ft_abs(b_ptr->a_score) + ft_abs(b_ptr->b_score);
	optimum = b_ptr;
	while (b_ptr->next)
	{
		if (!min)
			break ;
		b_ptr = b_ptr->next;
		if (min > ft_abs(b_ptr->a_score) + ft_abs(b_ptr->b_score))
		{
			min = ft_abs(b_ptr->a_score) + ft_abs(b_ptr->b_score);
			optimum = b_ptr;
		}
	}
	return (optimum);
}

int	meds(t_stack **head, int len, int *med)
{
	int	*arr;
	int	arr_len;
	int	pivot;

	pivot = 0;
	arr_len = 0;
	arr = stack_to_array(*head, len);
	if (!arr)
		return (0);
	while (arr_len < len)
		arr_len++;
	if (!quicksort(&arr[0], 0, arr_len - 1, pivot))
		return (0);
	if (arr_len % 2)
		*med = arr[arr_len / 2];
	else
		*med = arr[len / 2 - 1];
	free(arr);
	return (1);
}

static void	initialize_set(t_sort *set, int *i, t_stack **head)
{
	*i = 0;
	set->sort_count = 0;
	set->sort_max = 0;
	set->ptr = *head;
	set->sort_elem = NULL;
	set->sort_start = NULL;
}

static t_sort	find_sorted(t_sort set, int *arr, int len, int i)
{
	while (set.ptr->next)
	{
		set.sort_elem = set.ptr;
		while (arr[i] != set.ptr->value && i < len)
			i++;
		while (arr[i] == set.ptr->value && i < len)
		{
			i++;
			set.sort_count++;
			if (set.ptr->next == NULL)
				break ;
			set.ptr = set.ptr->next;
			if (i == len)
				break ;
		}
		if (set.sort_count > set.sort_max)
		{
			set.sort_max = set.sort_count;
			set.sort_start = set.sort_elem;
		}
		i = 0;
		set.sort_count = 0;
	}
	return (set);
}

int	srtsb(t_stack **head, int len, int *min)
{
	t_sort	set;
	int		i;
	int		*arr;

	i = 0;
	arr = stack_to_array(*head, len);
	if (!arr)
		return (0);
	if (!quicksort(&arr[0], 0, len - 1, i))
		return (0);
	initialize_set(&set, &i, &(*head));
	*min = arr[0];
	set = find_sorted(set, arr, len, i);
	if (set.sort_max > 1)
	{
		while (set.sort_max)
		{
			set.sort_start->sorted = 1;
			set.sort_start = set.sort_start->next;
			set.sort_max--;
		}
	}
	free(arr);
	return (1);
}
