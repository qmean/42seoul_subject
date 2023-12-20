#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    int fd = open(argv[1], O_RDONLY);
    
    char *output;

    output = get_next_line(fd);
    printf("%s",output);

    // while ((output = get_next_line(fd)) != 0)
    // {
    //     printf("%s",output);
    // }
}