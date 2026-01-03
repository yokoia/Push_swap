#include "ps_header.h"


void	ft_chunking_pushing(t_stack **stacka, t_stack **stackb, int chunk_size)
{
	int	i;

	i = 0;
	while (*stacka)
	{
		if ((*stacka)->index < i) // if its not in the chunk range and < i
		{
			ft_push(stacka, stackb, 'b');
			ft_rotate(stackb, 'b');
			i++;
		}
		else if ((*stacka)->index < i + chunk_size) // if its in the range
		{
			ft_push(stacka, stackb, 'b');
			i++;
		}
		else
			ft_rotate(stacka, 'a');
	}
}

void sort_all(t_stack **stacka, t_stack **stackb, int chunk_size)
{
    int index;
    int size;
    
    ft_chunking_pushing(stacka, stackb, chunk_size);
    while(*stackb)
    {
        index = find_max(stackb);
        size = stack_len(*stackb);
        if(index <= size / 2)
        {
            while (index-- > 0)
		    {
			    ft_rotate(stackb, 'b');
		    }
        }
        else
        {
            while (index++ < size)
		    {
			    ft_rrotate(stackb, 'b');
		    }
        }
        ft_push(stackb, stacka, 'a');
    }
}