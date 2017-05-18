static uint32_t crc_table[256]; 

void init_crc_table(void)    
{    
    uint32_t c;    
    uint32_t i, j;    
  
    for (i = 0; i < 256; i++) {    
        c = i;    
        for (j = 0; j < 8; j++) {    
            if (c & 1)    
                c = 0xedb88320L ^ (c >> 1);    
            else    
                c = c >> 1;    
        }    
        crc_table[i] = c;    
    }    
}

uint32_t crc32(unsigned int crc,unsigned char *buffer, unsigned int size)    
{    
    unsigned int i;    
    for (i = 0; i < size; i++) {    
        crc = crc_table[(crc ^ buffer[i]) & 0xff] ^ (crc >> 8);    
    }    
    return crc ;    
}



uint32_t cal_crc(void)
{
    int i;
    uint32_t crc = 0xffffffff;
    
    init_crc_table();
    
    /* user add, you shou give you calculate buffer and size, this call can repeat for slicing big file.
    crc = crc32(crc, buffer, size);
    */
    return (crc^0xffffffff);
}