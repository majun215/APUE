#include "apue.h"
#include "errors.h"

int
main(void)
{
    printf("uid = %d,gid = %d\n",getuid(),getgid());
    exit(0);
}
