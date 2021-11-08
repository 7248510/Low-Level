#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
//Keep your VPN file in the same location as the binary
//chmod +s startup
int main()
{
	puts("Attempting to connect to the VPN");
	const char *filePath = "/bin/sudo"; //Path of sudo
	char *argv[] = {"/bin/sudo", "openvpn", "nameoffile.ovpn", NULL}; //arg vector| test is the name of the user. Swap the value
	char *envp[] = {NULL};  
	int openVPN = execve(filePath, argv, envp);
	if (!openVPN) {
	fprintf(stderr, "Error code: %s", strerror(errno)); 
	}
}
