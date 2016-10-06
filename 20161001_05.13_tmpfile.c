#include "apue.h"
#include "errors.h"
#include <errno.h>

void make_tmp(char *template);

int
main()
{
	char good_template[] = "/tmp/dirXXXXXX";
	char *bad_template = "/tmp/dirXXXXXX";

	printf("trying to create first temp file...\n");
	make_tmp(good_template);
	printf("trying to create second temp file...\n");
	make_tmp(bad_template);
	exit(0);
}

void
make_tmp(char *template)
{
	int fd;
	struct stat sbuf;

	if((fd = mkstemp(template)) < 0)
		err_sys("can't create temp file");
	printf("temp name = %s\n",template);
	close(fd);
	if(stat(template,&sbuf) < 0)
	{
		if(errno == ENOENT)
			printf("file dosen't exist\n");
		else
			err_sys("stat failed");
	}
	else
	{
		printf("file exists\n");
		unlink(template);
	}
}
















