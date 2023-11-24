/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirus <kirus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 23:53:59 by kirus             #+#    #+#             */
/*   Updated: 2022/03/04 23:54:00 by kirus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack **head)
{
	t_stack	*stack;

	stack = *head;
	if (stack && stack->next)
		ft_swap(&stack->value, &stack->next->value);
	return (0);
}

int	push(t_stack **head_to, t_stack **head_from)
{
	t_stack	*tmp;
	t_stack	*to;
	t_stack	*from;

	to = *head_to;
	from = *head_from;
	if (!from)
		return (0);
	tmp = from;
	from = from->next;
	*head_from = from;
	if (!to)
	{
		to = tmp;
		to->next = NULL;
		*head_to = to;
	}
	else
	{
		tmp->next = to;
		*head_to = tmp;
	}
	return (0);
}

int	rotate(t_stack **head)
{
	t_stack	*tmp_first;
	t_stack	*tmp_last;
	t_stack	*stack;

	stack = *head;
	if (!(stack && stack->next))
		return (0);
	tmp_first = stack;
	stack = stack->next;
	tmp_last = stack;
	while (tmp_last->next)
	{
		tmp_last = tmp_last->next;
	}
	tmp_last->next = tmp_first;
	tmp_first->next = NULL;
	*head = stack;
	return (0);
}

int	r_rotate(t_stack **head)
{
	t_stack	*tmp_last;
	t_stack	*previous;
	t_stack	*stack;

	stack = *head;
	if (!(stack && stack->next))
		return (0);
	tmp_last = stack;
	while (tmp_last->next)
	{
		previous = tmp_last;
		tmp_last = tmp_last->next;
	}
	tmp_last->next = stack;
	previous->next = NULL;
	*head = tmp_last;
	return (0);
}
