
#include "../include/push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}




int	ft_atoi(const char *str)
{
	int		i;
	int		nb;
	int		is_negative;

	is_negative = 1;
	i = 0;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			is_negative *= -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (nb * is_negative);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write (fd, &s[i], 1);
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*memory;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	memory = NULL;
	memory = (void *)malloc(count * size);
	if (memory == NULL)
		return (NULL);
	ft_bzero (memory, count * size);
	return (memory);
}


void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
	s = str;
}

int	ft_countwords(char const *s, char c)
{
	int	count;

	count = 0;
	if (*s == 0)
		return (0);
	if (*s != '\0' && *s != c)
		count++;
	while (*++s != '\0')
		if (*s != c && *(s - 1) == c)
			count++;
	s++;
	return (count);
}

char const	*ft_skip_c (char const *s, char c)
{
	while (*s != '\0' && *s == c)
		s++;
	return (s);
}

char const	*ft_go_toc(char const *s, char c)
{
	while (*s != '\0' && *s != c)
		s++;
	return (s);
}

char	*ft_copyword(char const *s, char c)
{
	char		*str;
	char const	*p;
	int			length;

	p = s;
	length = 0;
	while (*p && *p != c)
	{
		length++,
		p++;
	}
	str = ft_substr(s, 0, length);
	if (str == 0)
		return (NULL);
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t		words;
	char		**split;
	size_t		i;	

	words = ft_countwords(s, c);
	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (split == NULL)
		return (NULL);
	i = 0;
	while (i < words)
	{
		 s = ft_skip_c (s, c);
		 split[i] = ft_copyword(s, c);
		 s = ft_go_toc(s, c);
		 i++;
	}
	split[i] = NULL;
	return (split);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = NULL;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}


// char	*ft_strdup (const char *s1)
// {
// 	char	*copy;
// 	int		i;

// 	copy = NULL;
// 	copy = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
// 	if (copy == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (s1[i] != '\0')
// 	{
// 		copy[i] = s1[i];
// 		i++;
// 	}
// 	copy[i] = '\0';
// 	return (copy);
// }