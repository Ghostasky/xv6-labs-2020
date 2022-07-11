#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
int main(int argc, char **argv)
{
    int n;
    if (argc != 2)
    {
        printf("please enter a number!");
        exit(1);
    }
    else
    {
        n = atoi( argv[1]);
        sleep(n);
        exit(0);
    }
}

// yutao@ubuntu:~/xv6-labs-2020$ sudo python3 grade-lab-util sleep
// make: 'kernel/kernel' is up to date.
// == Test sleep, no arguments == sleep, no arguments: OK (1.6s) 
// == Test sleep, returns == sleep, returns: OK (1.0s) 
// == Test sleep, makes syscall == sleep, makes syscall: OK (0.9s) 