/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirus <kirus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:45:45 by kirus             #+#    #+#             */
/*   Updated: 2022/03/04 21:29:16 by kirus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*add_operation(char *to, char *add)
{
	char	*del;

	del = to;
	to = ft_strjoin(to, add);
	if (del)
		free(del);
	del = NULL;
	return (to);
}

int	chsort(t_stack *a_ptr)
{
	while (a_ptr->next)
	{
		if (a_ptr->value > a_ptr->next->value)
			return (1);
		else
			a_ptr = a_ptr->next;
	}
	return (0);
}

int	*stack_to_array(t_stack *ptr, int len)
{
	int	*arr;
	int	i;

	i = 0;
	arr = (int *)malloc(len * sizeof(int));
	if (!arr)
		return (NULL);
	while (i < len)
	{
		if (ptr->sorted == 0)
		{
			arr[i] = ptr->value;
			i++;
		}
		else
			len--;
		ptr = ptr->next;
	}
	return (arr);
}

int	ft_stack_size(t_stack *begin_list)
{
	int	i;

	i = 0;
	if (begin_list == NULL)
		return (0);
	while (begin_list->next != NULL)
	{
		i++;
		begin_list = begin_list->next;
	}
	return (++i);
}

void	stack_clear(t_stack **lst)
{
	t_stack	*tmp;

	while (*lst)
	{
		tmp = (*lst);
		*lst = (*lst)->next;
		free(tmp);
	}
	lst = NULL;
}
