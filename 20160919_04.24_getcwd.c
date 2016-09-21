#include "apue.h"
#include "path_alloc_2.16.h"

int
main(void)
{
	char *ptr;
	size_t size;
	if(chdir("/home/dmtsai/github") < 0)
		err_sys("chdir failed");
	ptr = path_alloc(&size);
	if(getcwd(ptr,size) == NULL)
		err_sys("getcwd failed");
	printf("cwd = %s\n",ptr);
	exit(0);
}
