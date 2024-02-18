#include "kernel/types.h"
#include "user/user.h"


int main(int argc, char *argv[]) {
    int n, pid;
    int fds_a[2], fds_b[2];
    char child_buf[2];
    char parent_buf[2];

    pipe(fds_a);
    pipe(fds_b);
    // write a byte.
    write(fds_a[1], "a", 1);

    pid = fork();
    if (pid == 0) {
        n = read(fds_a[0], child_buf, 1);
        printf("%d: received ping\n", getpid());
        write(fds_b[1], child_buf, n);
    } else {
        read(fds_b[0], parent_buf, 1);
        printf("%d: received pong\n", getpid());
    }

    exit(0);
}