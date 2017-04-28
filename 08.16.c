#include "apue.h"
#include "errors.h"
#include <sys/wait.h>

char *env_init[] = {"USER=root","PATH=/tmp",NULL};

int
main(void)
{
	pid_t pid;
	
	if((pid = fork()) < 0)
	{
		err_sys("fork error");
	}
	else if(pid == 0)
	{
		if(execle("/bin/ls","ls","/home/dmtsai","/home/dmtsai/majun/apue",(char *)0,env_init) < 0)
			err_sys("execle error");
	}

	if(waitpid(pid,NULL,0) < 0)
		err_sys("wait error");

	if((pid = fork()) < 0)
	{
		err_sys("fork error");
	}
	else if(pid == 0)
	{
		if(execlp("ls","ls","/home/dmtsai/majun/github/git-learn",(char *)0) < 0)
			err_sys("execlp error");
	}	

	exit(0);
}
