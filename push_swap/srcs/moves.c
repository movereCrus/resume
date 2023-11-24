/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirus <kirus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:47:08 by kirus             #+#    #+#             */
/*   Updated: 2022/03/04 19:47:10 by kirus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	moveset_a(int oper, t_stack **head, char **res)
{
	if (oper == 0)
	{
		swap(head);
		*res = add_operation(*res, "sa\n");
	}
	if (oper == 1)
	{
		rotate(head);
		*res = add_operation(*res, "ra\n");
	}
	if (oper == 2)
	{
		rotate(head);
		*res = add_operation(*res, "rb\n");
	}
	if (oper == 3)
	{
		r_rotate(head);
		*res = add_operation(*res, "rra\n");
	}
	if (oper == 4)
	{
		r_rotate(head);
		*res = add_operation(*res, "rrb\n");
	}
}

void	moveset_b(int oper, t_stack **a_head, t_stack **b_head, char **res)
{
	if (oper == 5)
	{
		push(a_head, b_head);
		*res = add_operation(*res, "pa\n");
	}
	if (oper == 6)
	{
		push(b_head, a_head);
		*res = add_operation(*res, "pb\n");
	}
}

void	moveset_c(int oper, t_stack **head, char **res)
{
	if (oper == 7)
	{
		r_rotate(head);
		swap(head);
		*res = add_operation(*res, "rra\nsa\n");
	}
	if (oper == 8)
	{
		rotate(head);
		swap(head);
		*res = add_operation(*res, "ra\nsa\n");
	}
}
