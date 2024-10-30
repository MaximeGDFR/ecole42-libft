#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
/* ft_strchr sert a trouver '\n' ou '\0' dans la reserve de read() */
char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return ((char *)(str + i));
		i++;
	}
	if (str[i] == (unsigned char)c)
		return ((char *)(str + i));
	return (0);
}
/* ft_strdup sert a creer un duplicata du buffer de read() */
char	*ft_strdup(const char *str)
{
	int		i;
	int		size;
	char	*dup;

	i = 0;
	size = ft_strlen(str);
	dup = (char *)malloc((size + 1) * sizeof(char));
	if (!dup)
	{
		printf("Error allocation.\n");
		return (NULL);
	}
	while (i < size)
	{
		dup[i] = str[i];
		i++;
	}
	return (dup);
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	len_str;
	size_t	i;
	char	*sub_str;

	if (!str)
		return (NULL);
	len_str = ft_strlen(str);
	if (start >= len_str)
		return (ft_strdup(""));
	if (len > len_str - start)
		len = len_str - start;
	sub_str = (char *)malloc((len + 1) * sizeof(char));
	if (!sub_str)
	{
		printf("Erreur allocation.\n");
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		sub_str[i] = str[start + i];
		i++;
	}
	sub_str[len] = '\0';
	return (sub_str);
}

char	*ft_strjoin(char const *str1, char const *str2)
{
	size_t	len_str1;
	size_t	len_str2;
	char	*result;
	size_t	i;
	size_t	j;

	if (!str1 || !str2)
		return (NULL);
	len_str1 = ft_strlen(str1);
	len_str2 = ft_strlen(str2);
	result = (char *)malloc((len_str1 + len_str2 + 1) * sizeof (char));
	if (!result)
	{
		printf("Erreur allocation.\n");
		return (NULL);
	}
	ft_strlcpy(result, str1, len_str1 + 1);
	ft_strlcpy(result + len_str1, str2, len_str2 + 1);
	return (result);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}