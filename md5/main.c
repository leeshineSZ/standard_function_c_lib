#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "md5.h"

#define BUFF_SIZE  1024

static MD5_CTX context;

int main(int argc, char** argv)
{
    int fd = 0;
    uint8_t buf[BUFF_SIZE] = {0};
    uint8_t digest[16] = {0};
    int size_read = 0;
    char* calculate_file = NULL;
    int i = 0;
    
    if(argc < 2){
        printf("you should entry the name of the file to calculate!\n");
        return -1;
    }
    
    calculate_file = argv[1];
    if((fd = open(calculate_file, O_RDONLY)) == -1){
        printf("Open %s fail : %d, error:%s\n", calculate_file,  errno, strerror(errno));
        return -1;
    }
    
    MD5_Init(&context);
    
    while(((size_read = read(fd, buf, BUFF_SIZE)) > 0)){
        MD5_Update(&context, buf, size_read);
    }
    if(size_read < 0){
        printf("read fail : %s\n", strerror(errno));
        return -1;
    }
    
    if(size_read == 0){
        MD5_Final(digest, &context);
    }
    
    printf("%s md5:", calculate_file);
    for(i = 0; i < 16 ; i++)
    {
        printf("%02x", digest[i]);
    }
    
    close(fd);
    exit(0);
}