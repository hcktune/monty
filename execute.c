#include "monty.h"
int custom_execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", custom_push}, {"pall", custom_pall}, {"pint", custom_pint},
				{"pop", custom_pop},
				{"swap", custom_swap},
				{"add", custom_add},
				{"nop", custom_nop},
				{"sub", custom_sub},
				{"div", custom_div},
				{"mul", custom_mul},
				{"mod", custom_mod},
				{"pchar", custom_pchar},
				{"pstr", custom_pstr},
				{"rotl", custom_rotl},
				{"rotr", custom_rotr},
				{"queue", custom_queue},
				{"stack", custom_stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		custom_free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}