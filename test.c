#include "push_swap.h"

void test(t_list **stack_a, t_list **stack_b)
{
	t_list *a = *stack_a;
	t_list *b = *stack_b;

	printf("%s\n%s\n%s\n%s\n", "------------------------", "stack_a", "------------------------", "value | order |   flag |");
	while (a != NULL)
	{
		printf("%6d", a->chislo);
		printf("%s", "|");
		printf("%7d", a->order);
		printf("%s", "|");
		printf("%8d", a->flag);
		printf("%s", "|\n");
		a = a->prev;
	}
	printf("%s\n%s\n%s\n%s\n", "------------------------", "stack_b", "------------------------", "value | order | flag |");
	while (b != NULL)
	{
		printf("%6d", b->chislo);
		printf("%s", "|");
		printf("%7d", b->order);
		printf("%s", "|");
		printf("%8d", b->flag);
		printf("%s", "|\n");
		b = b->prev;
	}
		printf("%s\n", "------------------------");
}