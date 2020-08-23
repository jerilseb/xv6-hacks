#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

char buf[512];

int
main(int argc, char* argv[]) {
    if(argc < 3) {
        printf(1, "Usage: %s <source> <destination>\n", argv[0]);
        exit();
    }

    int fd1, fd2, n;

    if((fd1 = open(argv[1], O_RDONLY )) < 0) {
        printf(1, "cp: cannot open %s", argv[1]);
        exit();
    }

    if((fd2 = open(argv[2], O_CREATE|O_RDWR )) < 0) {
        printf(1, "cp: cannot open %s", argv[2]);
        exit();
    }

    while((n = read(fd1, buf, sizeof(buf))) > 0) {
        // printf(1, "Read %d bytes\n", n);
        write(fd2, buf, n);
    }
    close(fd1);
    close(fd2);

    exit();
}
