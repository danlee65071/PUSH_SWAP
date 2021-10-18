#include "push_swap.h"

void test(t_list **stack_a, t_list **stack_b)
{
	printf("%s\n%s\n%s\n%s\n", "------------------------", "stack_a", "------------------------", "value | order |   flag |");
	while (*stack_a != NULL)
	{
		printf("%6d", (*stack_a)->chislo);
		printf("%s", "|");
		printf("%7d", (*stack_a)->order);
		printf("%s", "|");
		printf("%8d", (*stack_a)->flag);
		printf("%s", "|\n");
		*stack_a = (*stack_a)->prev;
	}
	printf("%s\n%s\n%s\n%s\n", "------------------------", "stack_b", "------------------------", "value | order | flag |");
	while (*stack_b != NULL)
	{
		printf("%6d", (*stack_b)->chislo);
		printf("%s", "|");
		printf("%7d", (*stack_b)->order);
		printf("%s", "|");
		printf("%8d", (*stack_b)->flag);
		printf("%s", "|\n");
		*stack_b = (*stack_b)->prev;
	}
		printf("%s\n", "------------------------");
}