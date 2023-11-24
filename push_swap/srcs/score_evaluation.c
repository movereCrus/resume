/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_evaluation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwarlock <dwarlock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:08:29 by kirus             #+#    #+#             */
/*   Updated: 2022/03/05 19:57:25 by dwarlock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_score_eval(t_stack **b_head, int b_len)
{
	int		i;
	t_stack	*b_ptr;

	b_ptr = *b_head;
	i = 0;
	while (i < b_len / 2)
	{
		b_ptr->b_score = i;
		b_ptr = b_ptr->next;
		i++;
	}
	b_ptr->b_score = i;
	b_ptr = b_ptr->next;
	if (b_len % 2 == 1)
		b_ptr->b_score = -i;
	else
		i--;
	while (-i < 0)
	{
		b_ptr->b_score = -i;
		b_ptr = b_ptr->next;
		i--;
	}
}

static int	a_score_extension(t_ascore set)
{
	while (--set.i >= 0)
	{
		if (ft_abs(set.mdiff) > ft_abs(set.diff_arr[set.i]) || set.mdiff == 0)
		{
			set.mdiff = set.diff_arr[set.i];
			if (set.diff_arr[set.i] > 0)
			{
				if (set.i + 1 == set.a_len)
					set.score = 0;
				else
					set.score = ++set.i;
			}
			else
			{
				if (set.i - 1 < 0)
					set.score = 0;
				else
					set.score = set.i;
			}
		}
	}
	return (set.score);
}

static void	initialize_ascore(t_ascore *set, t_stack *a_ptr)
{
	set->i = 0;
	set->mdiff = 0;
	set->score = 0;
	set->a_len = ft_stack_size(a_ptr);
	set->diff_arr = (long *)malloc(set->a_len * sizeof(long));
}

void	a_score_eval(t_stack *a_ptr, t_stack **b_ptr)
{
	t_ascore	set;

	initialize_ascore(&set, a_ptr);
	while (set.i < set.a_len)
	{
		set.diff_arr[set.i] = (long)(*b_ptr)->value - (long)a_ptr->value;
		set.i++;
		a_ptr = a_ptr->next;
	}
	set.score = a_score_extension(set);
	if (set.score > set.a_len / 2)
	{
		set.score = set.a_len - set.score;
		set.score *= -1;
	}
	(*b_ptr)->a_score = set.score;
	free(set.diff_arr);
}

void	score_evaluation(t_stack **a_head, t_stack **b_head)
{
	int		b_len;
	t_stack	*a_ptr;
	t_stack	*b_ptr;

	b_len = ft_stack_size(*b_head);
	a_ptr = *a_head;
	b_ptr = *b_head;
	while (b_ptr)
	{
		a_score_eval(a_ptr, &b_ptr);
		if (!b_ptr->next)
			break ;
		b_ptr = b_ptr->next;
	}
	if (b_len < 2)
		b_ptr->b_score = 0;
	else
		b_score_eval(&(*b_head), b_len);
}
