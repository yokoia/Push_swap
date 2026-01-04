/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoia <ykoia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 20:59:19 by ykoia             #+#    #+#             */
/*   Updated: 2026/01/04 12:48:32 by ykoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_HEADER_H
# define PS_HEADER_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}					t_stack;

///// MAIN /////
void				choose_algo(t_stack **a, t_stack **b);
void				already_sorted(int ac, char **av);

///// HELPERS /////
char				*ft_strdup(const char *s);
long				ft_atoi(const char *str);
int					ft_isdigit(char *str);
int					ft_strslen(char **strs);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_strlen(const char *str);

//// STACK ////
int					stack(t_stack *stack);
int					find_min(t_stack **stack);
int					find_max(t_stack **stack);
int					stack_len(t_stack *stack);
int					find_position(t_stack *stack, int min, int max);

///// SPLIT //////
char				**ft_split(char const *s, char c);
void				free_split(char **result, int count);
char				*ft_avjoin(int ac, char **av);

///// LINKING /////
t_stack				*ft_stack(int ac, char **av);

///// OPERATIONS /////
void				ft_swap(t_stack **stack, char c);
void				ft_swap_both(t_stack **stacka, t_stack **stackb);
void				ft_push(t_stack **from, t_stack **to, char c);
void				ft_rotate(t_stack **stack, char c);
void				ft_rotate_both(t_stack **stacka, t_stack **stackb);
void				ft_rrotate(t_stack **stack, char c);
void				ft_rrotate_both(t_stack **stacka, t_stack **stackb);

///// SPECIAL SORTING /////
void				sort_two(t_stack **stack);
void				sort_three(t_stack **stack);
void				sort_four(t_stack **stacka, t_stack **stackb);
void				sort_five(t_stack **stacka, t_stack **stackb);

////// ERRORS /////
void				free_exit(int *arr, char **strs, t_stack **stack);
void				dup_err(int ac, char **av);
void				all_err(int ac, char **av);
int					check_sign(char *str);
int					check_empty(int ac, char **av);
void				check_empty2(int ac, char **av);

//// ALGO HELPERS ////
int					*ft_array(int ac, char **av);
void				ft_sort_int_tab(int *tab, int size);
void				ft_indexing(int ac, char **av, t_stack *stack);
void				ft_chunking_pushing(t_stack **stacka, t_stack **stackb,
						int chunk_size);

//// algoooooooooo ////
void				sort_all(t_stack **stacka, t_stack **stackb,
						int chunk_size);

///////////////// get next line
char				*ft_strchr(char *s, char c);
void				*ft_calloc(size_t count, size_t size);
char				*ft_leak(char *buffer, char *str);
char				*read_bytes(int fd, char *buffer);
char				*get_lline(char *buffer);
char				*get_leftovers(char *buffer);
char				*get_next_line(int fd);

//// BONUS ////
void				valid_line2(char *line, t_stack **stacka, t_stack **stackb,
						char **av);
int					is_sorted(t_stack **stacka);
void				ok_ko(t_stack **stacka, t_stack **stackb, char **av);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_swap_both_bonus(t_stack **stacka, t_stack **stackb);
void				ft_rotate_both_bonus(t_stack **stacka, t_stack **stackb);
void				ft_rrotate_both_bonus(t_stack **stacka, t_stack **stackb);
void				free_stack(char *line, t_stack **stacka, t_stack **stackb,
						char **strs);
void				valid_line1(char *line, t_stack **stacka, t_stack **stackb,
						char **av);
void				ft_read_check(t_stack **stacka, t_stack **stackb,
						char **av);
#endif