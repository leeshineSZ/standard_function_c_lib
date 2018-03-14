#include "debounce.h"

static DEBOUNCE_PROCESS s_debounce_object;

void debounce_init(uint8_t threshold_count, uint8_t max_count)
{
  s_debounce_object.threshold_read_counts = threshold_count;
  s_debounce_object.max_read_counts = max_count;
  s_debounce_object.read_counts = 0;
  s_debounce_object.
}

void debounce_process(uint8_t* process_value, uint8_t read_value)
{
  if(read_value == 1)
  {
    s_debounce_object.effect_counts++;            
  }
  s_debounce_object.read_counts++;
  if(s_debounce_object.read_counts >= s_debounce_object.max_read_counts)
  {
    s_debounce_object.read_counts = 0;
    if(s_debounce_object.effect_counts > s_debounce_object.threshold_read_counts)
    {
      *process_value = 1;					
    }
    else
    {
      *process_value = 0;
    }
    s_debounce_object.effect_counts = 0;
  }
}