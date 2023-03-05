#include "memsafe_boii.h"

typedef struct interval
{
  size_t seconds;
  size_t minutes;
  size_t hours;
} interval;

int main()
{
  // static allocation of array
  // memory will be automatically freed
  interval sample_interval = (interval){.seconds = 1, .minutes = 2, .hours = 3};
  interval sample_intervals[2] = {
    (interval){.seconds = 1, .minutes = 2, .hours = 3},
    (interval){.seconds = 2, .minutes = 4, .hours = 6}};

  // dynamic allocation of memory
  // we should free memory manually
  interval* t = (interval*)memsafe_boii_api__allocate(sizeof(interval));

  // manually freeing memory
  memsafe_boii_api__deallocate(t);

  // dynamic allocation of array
  // we should free memory manually
  interval* dynamically_allocated_time_intervals =
    (interval*)memsafe_boii_api__allocate(5 * sizeof(interval));
  dynamically_allocated_time_intervals[0].hours = 1;
  dynamically_allocated_time_intervals[0].minutes = 2;
  dynamically_allocated_time_intervals[0].seconds = 3;

  // forgetting to deallocate
  // memsafe_boii_api__deallocate(dynamically_allocated_time_intervals);

  // cleanup function
  // frees/deallocates all of the memory which is not cleared manually
  memsafe_boii_api__clean();

  return 0;
}
