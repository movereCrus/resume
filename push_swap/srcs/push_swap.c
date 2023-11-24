/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwarlock <dwarlock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:30:31 by kirus             #+#    #+#             */
/*   Updated: 2022/03/06 14:49:44 by dwarlock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_stack **a_ptr, t_stack **b_ptr, int len, char **res)
{
	t_stack	*optimum;
	int		med;
	int		min;

	if (!chsort(*a_ptr) || !srtsb(a_ptr, len, &min) || !meds(a_ptr, len, &med))
		return ;
	while (len--)
	{
		if (!(*a_ptr)->sorted)
		{
			moveset_b(6, a_ptr, b_ptr, res);
			if ((*b_ptr)->next)
				if ((*b_ptr)->value >= med && (*b_ptr)->next->value < med)
					moveset_a(2, b_ptr, res);
		}
		else
			moveset_a(1, a_ptr, res);
	}
	while (*b_ptr)
	{
		score_evaluation(a_ptr, b_ptr);
		optimum = optimal_push(*b_ptr);
		make_moves(optimum, a_ptr, b_ptr, res);
	}
	final_rotation(a_ptr, min, res);
}

static void	three_sort(t_stack **ptr, char **res)
{
	if ((*ptr)->value < (*ptr)->next->value && (*ptr)->next->value
		< (*ptr)->next->next->value)
		return ;
	if ((*ptr)->value > (*ptr)->next->value && (*ptr)->next->value
		< (*ptr)->next->next->value
		&& (*ptr)->value < (*ptr)->next->next->value)
		moveset_a(0, ptr, res);
	else if ((*ptr)->value < (*ptr)->next->value && (*ptr)->next->value
		> (*ptr)->next->next->value
		&& (*ptr)->value < (*ptr)->next->next->value)
		moveset_c(7, ptr, res);
	else if ((*ptr)->value > (*ptr)->next->value && (*ptr)->value
		> (*ptr)->next->next->value
		&& (*ptr)->next->value < (*ptr)->next->next->value)
		moveset_a(1, ptr, res);
	else if ((*ptr)->value < (*ptr)->next->value && (*ptr)->value
		> (*ptr)->next->next->value
		&& (*ptr)->next->value > (*ptr)->next->next->value)
		moveset_a(3, ptr, res);
	else if ((*ptr)->value > (*ptr)->next->value && (*ptr)->next->value
		> (*ptr)->next->next->value)
		moveset_c(8, ptr, res);
}

static void	five_sort(t_stack **a_ptr, t_stack **b_ptr, int a_len, char **res)
{
	t_stack	*optimum;
	int		*arr;
	int		pivot;

	pivot = 0;
	arr = stack_to_array(*a_ptr, a_len);
	if (!arr || !(quicksort(&arr[0], 0, a_len - 1, pivot)))
		return ;
	while (a_len-- != 3)
		moveset_b(6, a_ptr, b_ptr, res);
	three_sort(a_ptr, res);
	while (*b_ptr)
	{
		score_evaluation(a_ptr, b_ptr);
		optimum = optimal_push(*b_ptr);
		make_moves(optimum, a_ptr, b_ptr, res);
	}
	final_rotation(a_ptr, arr[0], res);
	free(arr);
}

void	shortsorting(t_stack **a_ptr, t_stack **b_ptr, int a_len, char **res)
{
	if (a_len == 2 && (*a_ptr)->value > (*a_ptr)->next->value)
		ft_printf("sa\n");
	if (a_len == 3)
		three_sort(a_ptr, res);
	if (a_len > 3)
		five_sort(a_ptr, b_ptr, a_len, res);
	return ;
}

int	main(int argc, char **argv)
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	char	*result;
	int		a_len;

	if (argc < 2)
		return (0);
	a_stack = form_stack(argc, argv);
	if (!a_stack)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	result = ft_strdup("\0");
	if (!result)
		return (0);
	b_stack = NULL;
	a_len = ft_stack_size(a_stack);
	if (a_len < 6)
		shortsorting(&a_stack, &b_stack, a_len, &result);
	else
		sorting(&a_stack, &b_stack, a_len, &result);
	print_final_result(result);
	stack_clear(&a_stack);
}
