#include "ps_header.h"


int check_empty(int ac, char **av)
{
    int i;
    int j;

    i = 1;
    j = 0;
    while(i < ac)
    {
        j = 0;
        if(av[i][0] == '\0')
            return 0;
        while(av[i][j] == ' ' || (av[i][j] >= 9 && av[i][j] <= 13))
            j++;
        if(av[i][j] == '\0')
            return 0;
        i++;
    }
    return 1;
}

void check_empty2(int ac, char **av)
{
    int check;

    if(ac <= 1)
        exit(1);
    check = check_empty(ac, av);
    if(check == 0)
    {
        write(2, "Error\n", 6);
        exit(1);
    }
}


int check_sign(char *str)
{
	int count;

	count = 0;
    
	while (*str)
	{
		if((*str >= '0' && *str <= '9') && (*(str + 1) && (*(str + 1) < '0' || *(str + 1) > '9')))
			count++;
		if((*str == '-' || *str == '+') || ((*str == '-' || *str == '+') && (ft_isdigit(str + 1) == 1)))
			count++;
		
		if((*str == '-' || *str == '+') && *(str + 1) == '\0')
			count++;

		if(count > 1)
			return (0);
		str++;
	}
	return (1);
}

void all_err(int ac, char **av)
{
    int i;

    i = 1;
    while(i < ac)
    {
        if(check_sign(av[i]) == 0 || ft_atoi(av[i]) > INT_MAX ||
        ft_atoi(av[i]) < INT_MIN)
        {
            write(2, "Error\n", 6);
            free_exit(NULL, av, NULL);
        }
        if(ft_isdigit(av[i]) == 0 || av[i] == NULL)
        {
            write(2, "Error\n", 6);
            free_exit(NULL, av, NULL);
        }
        i++;
    }
}

void dup_err(int ac, char **av)
{
    int *arr;
    int i;
    int j;

    arr = ft_array(ac, av);
    if(!arr)
        return;
    i = 0;
    while(i < ac - 2)
    {
        j = i + 1;
        while(j < ac - 1)
        {
            if(arr[i] == arr[j])
            {
                write(2, "Error\n", 6);
                free_exit(arr, av, NULL);
            }
            j++;
        }
        i++;
    }
    free(arr);
} 

