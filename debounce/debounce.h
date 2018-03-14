#ifndef __DEBOUNCE_H__
#define __DEBOUNCE_H__

#include <stdint.h>

typedef struct _debounce_porcess{
  uint8_t read_counts;
  uint8_t effect_counts;
  uint8_t max_read_counts;
  uint8_t threshold_read_counts;
}DEBOUNCE_PROCCESS;

void debounce_init(uint8_t threshold_count, uint8_t max_count);
void debounce_process(uint8_t* process_value, uint8_t read_value);

#ifdef __cplusplus
}
#endif

#endif
