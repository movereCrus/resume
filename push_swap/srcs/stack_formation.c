/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_formation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwarlock <dwarlock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 20:40:08 by kirus             #+#    #+#             */
/*   Updated: 2022/03/06 14:54:49 by dwarlock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_stack_node(void)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = 0;
	node->a_score = 0;
	node->b_score = 0;
	node->sorted = 0;
	node->next = NULL;
	return (node);
}

int	assign_vals(char **num, t_stack **ptr, int argc, int i)
{
	while (*num != NULL)
	{
		(*ptr)->value = ft_atoi(*num);
		if ((**num == '-' && (*ptr)->value > 0)
			|| (**num != '-' && (*ptr)->value < 0))
		{
			free(*num);
			free(num);
			return (0);
		}
		if (i < argc - 1 || *(num + 1))
		{
			(*ptr)->next = new_stack_node();
			if (!(*ptr)->next)
				return (0);
			(*ptr) = (*ptr)->next;
		}
		free(*num);
		num++;
	}
	return (1);
}

void	dups_check(t_stack **head)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = (*head);
	tmp2 = (*head)->next;
	if (!tmp2)
		return ;
	while (tmp1->value != tmp2->value && tmp2->next != NULL)
	{
		tmp2 = tmp2->next;
		if (tmp2->next == NULL && tmp1->value != tmp2->value)
		{
			tmp1 = tmp1->next;
			tmp2 = tmp1->next;
		}
	}
	if (tmp1->value == tmp2->value)
		stack_clear(head);
}

int	argv_check(char *str)
{
	size_t	i;
	int		d;

	i = 0;
	d = 0;
	while (str[i] == ' ')
		i++;
	if ((str[i] == '+' || str[i] == '-') && ft_isdigit(str[i + 1]))
		i++;
	if ((str[i] == '+' || str[i] == '-') && !ft_isdigit(str[i + 1]))
		return (0);
	while (str[i] && str[i] != ' ')
	{
		if (!ft_isdigit(str[i]) || d > 9)
			return (0);
		i++;
		d++;
	}
	if (str[i])
		i = argv_check(&str[i]);
	return (i);
}

t_stack	*form_stack(int argc, char **argv)
{
	t_formstack	set;

	set.i = 0;
	set.head = new_stack_node();
	if (!set.head)
		return (0);
	set.tmp = set.head;
	while (++set.i < argc)
	{
		if (!argv_check(argv[set.i]))
		{
			stack_clear(&set.head);
			return (NULL);
		}
		else
			set.num = ft_split(argv[set.i], ' ');
		if (!assign_vals(set.num, &set.tmp, argc, set.i))
		{
			stack_clear(&set.head);
			return (NULL);
		}
		free(set.num);
	}
	dups_check(&set.head);
	return (set.head);
}
