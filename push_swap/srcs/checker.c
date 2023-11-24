/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirus <kirus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 00:40:51 by kirus             #+#    #+#             */
/*   Updated: 2022/03/05 13:50:03 by kirus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	do_comms(char *comms, t_stack **a_head, t_stack **b_head)
{
	if (ft_strequ(comms, "sa\n"))
		return (swap(a_head));
	if (ft_strequ(comms, "sb\n"))
		return (swap(b_head));
	if (ft_strequ(comms, "ss\n"))
		return (ss(a_head, b_head));
	if (ft_strequ(comms, "pa\n"))
		return (push(a_head, b_head));
	if (ft_strequ(comms, "pb\n"))
		return (push(b_head, a_head));
	if (ft_strequ(comms, "ra\n"))
		return (rotate(a_head));
	if (ft_strequ(comms, "rb\n"))
		return (rotate(b_head));
	if (ft_strequ(comms, "rr\n"))
		return (rr(a_head, b_head));
	if (ft_strequ(comms, "rra\n"))
		return (r_rotate(a_head));
	if (ft_strequ(comms, "rrb\n"))
		return (r_rotate(b_head));
	if (ft_strequ(comms, "rrr\n"))
		return (rrr(a_head, b_head));
	return (1);
}

static int	return_errors(char **line, t_stack **stack1, t_stack **stack2)
{
	if (*line)
		free(*line);
	line = NULL;
	if (*stack1)
		stack_clear(stack1);
	if (*stack2)
		stack_clear(stack2);
	write(2, "Error\n", 6);
	return (0);
}

static void	print_checker_res(t_stack **a_head, t_stack **b_head)
{
	if (!(chsort(*a_head)) && !(*b_head))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	if (*a_head)
		stack_clear(a_head);
	if (*b_head)
		stack_clear(b_head);
}

int	main(int argc, char **argv)
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	char	*comms;

	if (argc < 2)
		return (0);
	a_stack = form_stack(argc, argv);
	if (!a_stack)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	b_stack = NULL;
	comms = get_next_line(0);
	while (comms)
	{
		if (do_comms(comms, &a_stack, &b_stack))
			return (return_errors(&comms, &a_stack, &b_stack));
		free(comms);
		comms = get_next_line(0);
	}
	print_checker_res(&a_stack, &b_stack);
	return (0);
}
