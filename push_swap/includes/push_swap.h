/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwarlock <dwarlock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:30:53 by kirus             #+#    #+#             */
/*   Updated: 2022/03/06 14:48:59 by dwarlock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_stack
{
	int				value;
	int				a_score;
	int				b_score;
	int				sorted;
	struct s_stack	*next;
}	t_stack;

typedef struct s_sort
{
	int		sort_count;
	int		sort_max;
	t_stack	*ptr;
	t_stack	*sort_start;
	t_stack	*sort_elem;
}	t_sort;

typedef struct s_ascore
{
	int		i;
	int		score;
	long	mdiff;
	long	*diff_arr;
	int		a_len;
}	t_ascore;

typedef struct s_formstack
{
	int		i;
	char	**num;
	t_stack	*head;
	t_stack	*tmp;
}	t_formstack;

t_stack	*form_stack(int argc, char **argv);
int		swap(t_stack **head);
int		push(t_stack **head_to, t_stack **head_from);
int		rotate(t_stack **head);
int		r_rotate(t_stack **head);
int		ss(t_stack **stack1, t_stack **stack2);
int		rr(t_stack **stack1, t_stack **stack2);
int		rrr(t_stack **stack1, t_stack **stack2);
int		ft_stack_size(t_stack *begin_list);
void	stack_clear(t_stack **lst);
int		*stack_to_array(t_stack *ptr, int len);
int		quicksort(int *arr1, int start, int end, int pivot);
int		srtsb(t_stack **head, int len, int *min);
int		meds(t_stack **head, int len, int *med);
void	score_evaluation(t_stack **a_ptr, t_stack **b_ptr);
void	b_score_eval(t_stack **b_head, int b_len);
void	a_score_eval(t_stack *a_ptr, t_stack **b_ptr);
void	score_evaluation(t_stack **a_head, t_stack **b_head);
t_stack	*optimal_push(t_stack *b_ptr);
void	make_moves(t_stack *o, t_stack **a_head, t_stack **b_head, char **res);
void	final_rotation(t_stack	**a_head, int min, char **res);
void	moveset_a(int oper, t_stack **head, char **res);
void	moveset_b(int oper, t_stack **a_head, t_stack **b_head, char **res);
void	moveset_c(int oper, t_stack **head, char **res);
char	*add_operation(char *to, char *add);
int		add_pa_pb(char **origin, char **res, int i);
int		add_rr(char **origin, char **res, int i);
int		add_rrr(char **origin, char **res, int i);
int		add_others(char **tmp, char **res, int i);
int		chsort(t_stack *a_ptr);
void	print_final_result(char *origin);

#endif