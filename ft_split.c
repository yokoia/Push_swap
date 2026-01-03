#include "ps_header.h"


int	ft_strslen(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

static int	count_words(const char *s, char c)
{
	int	count;

	count = 0;
	if (*s && *s != c)
		count++;
	while (*s)
	{
		if (*s == c && *(s + 1) != c && *(s + 1))
			count++;
		s++;
	}
	return (count);
}

static char	*get_next_word(const char **s, char c)
{
	char		*word;
	const char	*start;
	int			len;
	int			i;

	while (**s == c && **s)
		(*s)++;
	start = *s;
	while (**s && **s != c)
		(*s)++;
	len = (*s) - start;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

void	free_split(char **result, int count)
{
	int	j;

	j = 0;
	while (j < count)
		free(result[j++]);
	free(result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		word_count;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	result = malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);

	while (i < word_count)
	{
		result[i] = get_next_word(&s, c);
		if (!result[i])
		{
			free_split(result, i);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;          
	return (result);
}