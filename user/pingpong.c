// #include <stdio.h>
#include "kernel/types.h"
#include "user/user.h"
// 编写一个程序，使用UNIX系统调用在一对管道上的两
// 个进程之间“乒乓”一个字节，每个方向一个。父级应向子
// 级发送一个字节；子进程应该打印“：received ping”，
// 其中是其进程ID，将管道上的字节写入父进程，然后退出；
// 父进程应该从子进程读取字节，打印“：received pong”，
// 然后退出。您的解决方案应该在文件“user/pingpong.c”中。
#define READEND 0
#define WRITTEND 1
int main()
{
    int p[2];
    int pid;
    char buf[2];
    char *parmsg = "a";
    char *chimsg = "b";

    pipe(p);

    pid = fork();
    if (pid < 0)
    {
        exit(1);
    }
    else if (pid == 0) // child processs
    {
        read(p[READEND], buf, 1);
        printf("child receive: %c\n", buf[0]);
        printf("%d: received ping\n", getpid());
        write(p[WRITTEND], chimsg, 1);
        close(p[READEND]);
        close(p[WRITTEND]);

        exit(0);
    }
    else
    {
        write(p[WRITTEND], parmsg, 1);
        wait(0);
        read(p[READEND], buf, 1);

        printf("parent receive: %c\n", buf[0]);
        printf("%d: received pong\n", getpid());
        close(p[WRITTEND]);
        close(p[READEND]);
        exit(0);
    }
}

// yutao@ubuntu:~/xv6-labs-2020$ sudo python3 grade-lab-util pingpong
// make: 'kernel/kernel' is up to date.
// == Test pingpong == pingpong: OK (1.9s)