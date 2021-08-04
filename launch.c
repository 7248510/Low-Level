#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
//https://www.ibm.com/docs/api/v1/content/ssw_ibm_i_74/rzarg/designators.htm
//https://www.geeksforgeeks.org/designated-initializers-c/
//https://www.tutorialspoint.com/c_standard_library/c_macro_errno.htm
//https://ece.uwaterloo.ca/~dwharder/icsrts/Tutorials/fork_exec/    Fork
//Based on my virtualbox script, but instead it's written in C
//Wall = maximum errors warnings(Get every potential error even if the default won't display)
//gcc -Wall launch.c -o launch && ./launch
void listVMS() {
	int pid = fork(); //A child process is needed as execve replaces the current process
	//The {} are designated initializers
	const char *filePath = "/usr/bin/vboxmanage";
	int virtualBox = 0;
	char *argv[] = {"/usr/bin/vboxmanage", "list", "vms", NULL}; //Programs argument vector
	char *envp[] = {NULL}; //environment pointer
	if (pid == 0) {
		virtualBox = execve(filePath, argv, envp);
		if (!virtualBox) {
			fprintf(stderr,"Error code: %s", strerror(errno));
		}
	}
}

void startVMS() {
	//The {} are designated initializers
	const char *filePath = "/usr/bin/vboxmanage";
	int virtualBox = 0;
	char *argv[] = {"/usr/bin/vboxmanage", "startvm" ,"bb55610d-2fbf-46d0-827e-6f9a7e0b64a1", "--type", "headless", NULL}; //Programs argument vector
	char *envp[] = {NULL}; //environment pointer
	printf("%s", argv[4]);
	virtualBox = execve(filePath, argv, envp);
	if (!virtualBox) {
		fprintf(stderr,"Error code: %s", strerror(errno));
	}
}
//To locate the path of a file use locate
int main(void)
{
	listVMS();
	startVMS();
	return EXIT_SUCCESS;
}
