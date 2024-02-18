#include "kernel/types.h"
#include "user/user.h"

char err_msg[] = "Error! No input.\n";

int main(int argc, char *argv[]) {
    int num_tick = 0;
    if (argc < 2) {
        fprintf(1, err_msg);
        exit(1);
    }
    num_tick = atoi(argv[1]);
    sleep(num_tick);
    exit(0);
}