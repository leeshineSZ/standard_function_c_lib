#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "md5.h"

#define BUFF_SIZE  1024

static MD5_CTX context;

int main(int argc, char** argv)
{
    int fd = 0;
    char buf[BUFF_SIZE] = {0};
    char digest[16] = {0};
    int size_read = 0;
    char* calculate_file = NULL;
    
    if(argc < 2){
        printf("you should entry the name of the file to calculate!\n");
    }
    
    calculate_file = argv[1];
    if(fd = open(calculate_file, O_RDONLY)){
        printf("Open fail : %s\n", strerror(errno));
        return -1;
    }
    
    MD5Init(&context);
    
    while((size_read = read(fd, buf, BUFF_SIZE) > 0){
        printf("read  end: %s\n", strerror(errno));
        MD5Update(&context, buf, size_read);
    }
    if(size_read < 0){
        printf("read fail : %s\n", strerror(errno));
        return -1;
    }
    
    if(size_read == 0){
        MD5Final(digest, &context);
    }
    
    printf("%s md5:%s\n", calculate_file, digest);
    close(fd);
    return 0;
}