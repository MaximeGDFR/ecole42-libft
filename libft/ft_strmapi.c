#include <stdio.h>
#include <stdlib.h>

int ft_strlen(const char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int ft_toupper(int c)
{
    if (c >= 'a' && c <= 'z')
        return (c - ('a' - 'A'));
    else
        return (c);
}

char    my_function(unsigned int i, char c)
{
    (void)i;
    return (ft_toupper(c)); // Remplacer par la fonction voulue
}

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    unsigned int i;
    char *result;

    if (s == NULL || f == NULL)
        return (NULL);

    result = (char *)malloc((ft_strlen((char *)s) + 1) * sizeof(char));
    if (result == NULL)
        return (NULL);
    
    i = 0;
    while (s[i])
    {
        result[i] = f(i, s[i]);
        i++;
    }
    result[i] = '\0';
    return (result);
}

/*int main()
{
    char str [] = "Hello world !";
    char *new_str = ft_strmapi(str, my_function);

    if (new_str != NULL)
    {
        printf("%s\n", str);
        printf("%s\n", new_str);
        free(new_str);
    }
    return (0);
}*/