/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmalawl <asmalawl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:43:05 by shmohamm          #+#    #+#             */
/*   Updated: 2024/04/22 13:04:44 by asmalawl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc < 2) // min 2 stack 
		return (0);
	validate_arguments(argc, argv); // we check for thats num and sign
	initialize_stacks(argc, argv, &stack);
	combine_arguments(argc, argv, &stack); // we join the numbers into big arg
	read_numbers(&stack);
	check_for_dup_or_sorted(&stack, 0); // check any sort or dup numbers
	create_index(&stack);
	if (stack.stack_a_size == 2 && stack.stack_a[0] > stack.stack_a[1]) //If the size of stack A is 2 and the number at index 0 (the first number) is greater than the number at index 1 (the second number), 
		swap_elements("sa", stack.stack_a, stack.stack_a_size);  //hen swap them.
	else if (stack.stack_a_size == 3) // if there is 3 numbers 
		sort_three_items(&stack); //sort them
	else if (stack.stack_a_size >= 4 && stack.stack_a_size <= 5) // 4 or 5 numbers  
		sort_four_to_five_items(&stack);// sort them 
	else
		apply_radix_sort(&stack);
	check_for_dup_or_sorted(&stack, 1);  // we cant have 2 dup or sorted stack
	exit_program(&stack, "Error\n");// Exits the program if there's an error.
	return (0);
}
