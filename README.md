# push-swap - 42 Project

**Overview**

The Push Swap project involves sorting a set of integers using two stacks (a and b). The objective is to sort all the elements in stack a in ascending order using a limited set of operations. Stack b is initially empty, and the challenge is to use less than 5500 operations to achieve a fully sorted stack of 500 integers.

**Rules**

    Stacks:
        Stack a contains a random set of non-duplicated integers (both positive and negative).
        Stack b starts empty.
    Goal: Sort all numbers in stack a in ascending order using specific stack operations like swaps, pushes, and rotations.

**Operations**

    sa / sb: Swap the first two elements of stacks a or b.
    pa: Push the top element from b to a.
    pb: Push the top element from a to b.
    ra / rb: Rotate stack a or b (shift elements up).
    rra / rrb: Reverse rotate stack a or b (shift elements down).
    ss, rr, rrr: Simultaneous operations for both stacks.

**Approach**

Solution Strategy

    For 2 values:
        Check if the stack is sorted; if not, swap the top two elements (sa).

    For 3 values:
        Use a combination of swaps, rotations, and reverse rotations based on the order of the elements.

    For up to 5 values:
        Find the minimum values, move them to the top of a, and push them to b.
        Sort the remaining values in a using the previous 3-value algorithm.
        Push the sorted values back from b to a.

    For more than 5 values:
        Split the stack using the average value as a pivot, pushing numbers above the average to b.
        Assign indexes to the elements for easier targeting.
        Calculate the most "cost-effective" moves to minimize the number of operations for sorting.
        Rotate stacks to align the target and perform efficient pushes from b to a.
        Once b is empty, ensure a is sorted with minimal operations.

**Results**

The program will output the smallest set of operations required to sort the stack. If errors occur (e.g., invalid input, duplicates, etc.), the program will display appropriate error messages.
