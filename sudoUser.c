#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

int main()
{
  puts("This script/program will add a new user to the sudo group\nTested on Debian");
  const char *filePath = "/bin/sudo"; //Path of sudo
  char *argv[] = {"/bin/sudo", "usermod", "-aG", "sudo", "test", NULL}; //arg vector| test is the name of the user. Swap the value
  char *envp[] = {NULL};  
  int rootAdd = execve(filePath, argv, envp);
  if (!rootAdd) {
    fprintf(stderr, "Error code: %s", strerror(errno)); 
  }
  puts("The system may need a reboot or a sign in/sign out.\nTested rebooting");
}
