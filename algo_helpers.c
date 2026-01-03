#include "ps_header.h"


int *ft_array(int ac, char **av)
{
    int *arr;
    int i;
    int j;

    i = 0;
    j = 1;
    arr = malloc((ac - 1) * 4);
	if(!arr)
		return NULL;
    while(i < ac - 1)
        arr[i++] = ft_atoi(av[j++]);
    return (arr);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void ft_indexing(int ac, char **av, t_stack *stack)
{
    int *arr;
    int i;
    
    i = 0;
    arr = ft_array(ac, av);
    ft_sort_int_tab(arr, ac - 1);
    while(stack)
    {
		i = 0;
		while(1)
		{
			if(stack->content == arr[i])
			{
				stack->index = i;
				break;
			}
			i++;
		}
		stack = stack->next;
    }
	free(arr);
}
