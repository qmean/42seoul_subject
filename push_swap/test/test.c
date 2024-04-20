#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "push_swap.h"

void print_stack(t_stack *stack)
{
	t_node *tmp = stack->first;
	printf("=== print stack ===\n");
	printf("===== size: %d =====\n",stack->size);
	while (tmp != NULL)
	{
		printf("===> %d\n", tmp->data);
		tmp = tmp->next;
	}
}

void print_stack2(t_stack_set *set)
{
	t_node *tmp = set->stack_a->first;
	printf("=== print stack A===\n");
	printf("===== size: %d =====\n",set->stack_a->size);
	while (1)
	{
		if (set->stack_a->size == 0)
			break;
		printf("===> %d\n", tmp->data);
		tmp = tmp->next;
		if (set->stack_a->size == 1)
			break;
		if (tmp == set->stack_a->last)
		{
			printf("===> %d\n", tmp->data);
			break;
		}
	}

	tmp = set->stack_b->first;
	printf("=== print stack B===\n");
	printf("===== size: %d =====\n",set->stack_b->size);
	while (1)
	{
		if (set->stack_b->size == 0)
			break;
		printf("===> %d\n", tmp->data);
		tmp = tmp->next;
		if (set->stack_b->size == 1)
			break;
		if (tmp == set->stack_b->last)
		{
			printf("===> %d\n", tmp->data);
			break;
		}
	}
}

int main()
{
	int		cmd = 0;
	t_stack_set set;
	t_stack a;
	t_stack b;
	a.first = NULL;
	a.last = NULL;
	a.size = 0;
	b.first = NULL;
	b.last = NULL;
	b.size = 0;
	set.stack_a = &a;
	set.stack_b = &b;

	while (cmd != -1)
	{
		scanf("%d", &cmd);
		push_back(set.stack_a, new_node(cmd));
	}
	print_stack(set.stack_a);
	cmd = 1;

	while (cmd != -1)
	{
		scanf("%d", &cmd);
		push_back(set.stack_b, new_node(cmd));
	}
	cmd = 1;
	while (cmd != -1)
	{
		printf("1:sa 2:sb 3:pa 4:pb 5:ra 6:rb 7:rr 8:rra 9:rrb -1:종료 = ");
		scanf("%d", &cmd);
		switch (cmd)
		{
		case 1:
			sa(&set);
			break;
		case 2:
			sb(&set);
			break;
		case 3:
			pa(&set);
			break;
		case 4:
			pb(&set);
			break;
		case 5:
			ra(&set);
			break;
		case 6:
			rb(&set);
			break;
		case 7:
			rr(&set);
			break;
		case 8:
			rra(&set);
			break;
		case 9:
			rrb(&set);
			break;
		default:
			break;
		}
		print_stack2(&set);
	}
	return 0;
}