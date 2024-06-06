# push-swap

Pseudo code:
For 2 values:
	- check if sorted, if not swap a
For 3 values:
	- store the values in a, b and. Swap, rotate and reverse rotate based on values order.
For up to 5 values:
	- find the min, move it to the top of a, push it to b X 2
	- use the sort 3 num algo or sort 2 num to sort a
	- push the two values in b back

For more than 5 values:
	- Find the average of stack a, keep pushing all numbers above average to stack b, until there is only 3 numbers left in a
	- Set index for stack a and stack b (index being part of the structure t_stack)
	- Go through stack_b, and find the cheapest move:
		- Find the target in stack_a for each num of stack_b (= the node that should be on top of a to push the num from b)
		- calculate how many rotations are needed to put the target on top of a and the num on top of b
	- Rotate stacks until both target and cheapest are on top
	- push b to a
	- do it as long as there is a node in stack_b
	- move min node to top of stack a
	- Free both stacks
