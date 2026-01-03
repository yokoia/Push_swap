# Push_swap

A sorting algorithm project from 42 school. Sort a stack of integers using a limited set of operations with the minimum number of moves.

## Description

Push_swap is a program that takes a list of integers as arguments and outputs a series of operations to sort them. The program uses two stacks (a and b) and can only perform specific operations:

### Operations

- `sa` : swap a - swap the first 2 elements at the top of stack a
- `sb` : swap b - swap the first 2 elements at the top of stack b
- `ss` : sa and sb at the same time
- `pa` : push a - take the first element at the top of b and put it at the top of a
- `pb` : push b - take the first element at the top of a and put it at the top of b
- `ra` : rotate a - shift up all elements of stack a by 1
- `rb` : rotate b - shift up all elements of stack b by 1
- `rr` : ra and rb at the same time
- `rra` : reverse rotate a - shift down all elements of stack a by 1
- `rrb` : reverse rotate b - shift down all elements of stack b by 1
- `rrr` : rra and rrb at the same time

## Compilation

```bash
make
```

## Usage

```bash
./push_swap [list of integers]
```

### Examples

```bash
# Sort 3 numbers
./push_swap 2 1 3
# Output: sa

# Sort 5 numbers
./push_swap 5 1 3 4 2
# Output: series of operations to sort the stack

# Already sorted (no output)
./push_swap 3 2 1
```

## Algorithm

The program implements different sorting strategies based on stack size:

- **2-3 elements**: Hardcoded optimal solutions
- **4-5 elements**: Small sort algorithm (pushes smallest elements to stack b, sorts remaining, then pushes back)
- **6+ elements**: Radix sort algorithm for efficient sorting of larger sets

## Error Handling

The program will output "Error\n" to stderr and return 1 in the following cases:
- Non-numeric arguments
- Numbers larger than INT_MAX or smaller than INT_MIN
- Duplicate numbers

## Testing

Run the included test script:
```bash
./push_swap 3 2 1        # Already sorted - no output
./push_swap 1 2 3        # Needs sorting
./push_swap 2 1 2        # Duplicate error
./push_swap abc          # Invalid input error
```

## Project Structure

- `main.c` - Entry point
- `stack.c` - Stack data structure implementation
- `operations_*.c` - Implementation of all push_swap operations
- `parse.c` - Input parsing and validation
- `sort*.c` - Sorting algorithms
- `utils.c` - Helper functions
- `push_swap.h` - Header file

## Cleaning

```bash
make clean    # Remove object files
make fclean   # Remove object files and executable
make re       # Recompile everything
```

## Performance

- 3 elements: Maximum 3 operations
- 5 elements: Maximum 12 operations (typically 8-10)
- 100 elements: Approximately 700-1500 operations
- 500 elements: Approximately 5500-7500 operations
