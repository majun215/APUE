#include "apue.h"
#include "errors.h"
#include <errno.h>

int
main(int argc,char *argv[])
{
    fprintf(stderr,"EACCES: %s\n",strerror(EACCES));
    errno = ENOMEM;
    perror(argv[0]);
    exit(0);
}
