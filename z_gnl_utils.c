#include "ps_header.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	dst = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dst)
		return (NULL);
	str = dst;
	while (*s1)
		*(str++) = *(s1++);
	while (*s2)
		*(str++) = *(s2++);
	*str = 0;
	return (dst);
}

char	*ft_strchr(char *s, char c)
{
	if (!s)
		return (NULL);
	while (*s != c && *s)
		s++;
	if (*s == c)
		return (s);
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*str;
	size_t			i;

	str = malloc(count * size);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		str[i] = 0;
		i++;
	}
	return ((void *)str);
}