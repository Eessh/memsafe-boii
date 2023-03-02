#include "memsafe_boii.h"

typedef struct interval
{
	size_t seconds;
	size_t minutes;
	size_t hours;
} interval;

int main()
{
	printf("Hola\n");

	interval* t1 = (interval*)memsafe_boii_api__allocate(sizeof(interval));
	interval* t2 = (interval*)memsafe_boii_api__allocate(sizeof(interval));

	memsafe_boii_api__deallocate(t1);
	// forgetting to deallocate
	// memsafe_boii_api__deallocate(t2);

	memsafe_boii_api__clean();

	return 0;
}
