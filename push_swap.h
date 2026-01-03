#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				*array;
	int				size;
	int				capacity;
}	t_stack;

// Stack operations
t_stack	*init_stack(int capacity);
void	free_stack(t_stack *stack);
int		is_empty(t_stack *stack);
int		is_full(t_stack *stack);

// Push_swap operations
void	sa(t_stack *a, int print);
void	sb(t_stack *b, int print);
void	ss(t_stack *a, t_stack *b, int print);
void	pa(t_stack *a, t_stack *b, int print);
void	pb(t_stack *a, t_stack *b, int print);
void	ra(t_stack *a, int print);
void	rb(t_stack *b, int print);
void	rr(t_stack *a, t_stack *b, int print);
void	rra(t_stack *a, int print);
void	rrb(t_stack *b, int print);
void	rrr(t_stack *a, t_stack *b, int print);

// Parsing and validation
int		parse_args(int argc, char **argv, t_stack *a);
int		ft_atoi(const char *str);
int		is_valid_number(const char *str);
int		has_duplicates(t_stack *stack);

// Sorting algorithms
void	sort_stack(t_stack *a, t_stack *b);
void	sort_three(t_stack *a);
void	sort_small(t_stack *a, t_stack *b);
void	radix_sort(t_stack *a, t_stack *b);

// Utils
int		is_sorted(t_stack *stack);
int		get_max_bits(t_stack *stack);
void	normalize_stack(t_stack *stack);
void	ft_putstr_fd(char *s, int fd);
int		find_min_index(t_stack *stack);

#endif
