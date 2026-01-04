*This project has been created as part of the 42 curriculum by ykoia.*

# Push_swap

## Description

This project is about sorting a stack of integers using a limited set of operations. The goal is to find the most efficient sequence of moves to sort the stack with the minimum number of instructions. 

You are given two stacks, `a` and `b`. Stack `a` is pre-filled with a random set of unique integers. Stack `b` is empty. Your task is to sort the integers in stack `a` in ascending order using only a defined set of operations.

## Instructions

1. **Compile the project:**
    ```bash
    make
    ```

2. **Run the sorter:**
    Provide a list of space-separated integers as arguments.
    ```bash
    ./push_swap 4 67 3 87 23
    ```
    The program will output the sequence of operations to sort the list.

3. **Use the Checker (Bonus):**
    Verify if the output of `push_swap` correctly sorts the list by piping it into the `checker` program.
    ```bash
    ./push_swap 4 67 3 87 23 | ./checker 4 67 3 87 23
    ```
    The `checker` will output `OK` if the stack is sorted, and `KO` otherwise.

## Allowed Operations

| Operation | Description |
| :--- | :--- |
| `sa` | Swap the first two elements at the top of stack `a`. |
| `sb` | Swap the first two elements at the top of stack `b`. |
| `ss` | `sa` and `sb` at the same time. |
| `pa` | Take the top element from stack `b` and move it to the top of stack `a`. |
| `pb` | Take the top element from stack `a` and move it to the top of stack `b`. |
| `ra` | Shift up all elements of stack `a` by one. The first element becomes the last. |
| `rb` | Shift up all elements of stack `b` by one. The first element becomes the last. |
| `rr` | `ra` and `rb` at the same time. |
| `rra` | Shift down all elements of stack `a` by one. The last element becomes the first. |
| `rrb` | Shift down all elements of stack `b` by one. The last element becomes the first. |
| `rrr` | `rra` and `rrb` at the same time. |

## Algorithm Overview

- **Small Stacks (2–5 elements):** Simple hard-coded logic using `sa`, `ra`, `rra`, and `pb/pa`.  
- **Medium to Large Stacks (100–500+ elements):** Radix Sort and Chunk Sort algorithms using the indices of elements.  

## Features

- Efficient sorting for small stacks with minimal operations.
- Scalable sorting for large datasets using optimized algorithms.
- Includes a checker program to verify the correctness of the sorting sequence.
- Handles invalid input with error messages.

## Technical Choices

- Language: C
- Compilation: `make`
- Algorithms: Radix Sort for large stacks, hard-coded sequences for small stacks
- Data structure: Linked lists for stacks `a` and `b`.

## Resources

- [C Programming Language Documentation](https://en.cppreference.com/w/c)
- [Radix Sort Algorithm](https://www.geeksforgeeks.org/radix-sort/)
- Tutorials on stack operations and sorting algorithms.
