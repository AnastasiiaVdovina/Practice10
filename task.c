#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int global_var = 0;

int main(){
	pid_t pid;
	pid = fork();
	if(pid < 0){
		perror("fork failed");
		exit(1);
	}else if (pid == 0) {
		//child process
		printf("Child process: global var = %d\n", global_var);
		global_var++;
		printf("Child process after increment: global var = %d\n", global_var);
	} else{
		// parent process ( pid > 0)
		wait(NULL); //waiting for closing child process
		printf("Parent process: global var = %d\n", global_var);
		global_var = 10;
		printf("Parent process after change: global var = %d\n", global_var);
	}

	return 0;
}
