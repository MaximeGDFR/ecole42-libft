#include <stdio.h>
#include <string.h>

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    size_t i;
    const unsigned char *s_1;
    const unsigned char *s_2;

    i = 0;
    s_1 = (const unsigned char *)s1;
    s_2 = (const unsigned char *)s2;
    //Cast en char* pour copier octet par octet directement dans la boucle

    while (i < n)
    {
        if (s_1[i] != s_2[i])
            return (s_1[i] - s_2[i]);
        i++;
    }

    return (0);
}

/*int main()
{
    char s1 [] = "Hello world";
    char s2 [] = "Hello world !";
    size_t n = 13;

    printf("%d\n", memcmp(s1, s2, n));
    printf("%d\n", ft_memcmp(s1, s2, n));

    return (0);
}*/