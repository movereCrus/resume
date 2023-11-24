/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirus <kirus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 23:53:42 by kirus             #+#    #+#             */
/*   Updated: 2022/03/04 23:53:43 by kirus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ss(t_stack **stack1, t_stack **stack2)
{
	swap(stack1);
	swap(stack2);
	return (0);
}

int	rr(t_stack **stack1, t_stack **stack2)
{
	rotate(stack1);
	rotate(stack2);
	return (0);
}

int	rrr(t_stack **stack1, t_stack **stack2)
{
	r_rotate(stack1);
	r_rotate(stack2);
	return (0);
}
