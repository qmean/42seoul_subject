#include <stdio.h>
#include <stdlib.h>

char    *ft_substr(const char *s, unsigned int start, size_t len)
{
    char    *ret;
    int     idx;

    idx = 0;
    ret = (char *)malloc(sizeof(char) * len);
    if (ret == 0)
        return (0);
    while (s[start] != 0 && len--)
    {
        ret[idx] = s[start];
        start++;
        idx++;
    }
    ret[idx] = 0;
    return (ret);
}

int main(int argc, char **argv)
{
    char *s1 = "dfsfwfferwe34ref323";
    char *s2 = ft_substr(s1,3,10);

    printf("%p : %s\n%p : %s\n",s1,s1,s2,s2);
}

