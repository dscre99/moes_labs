#include "DownCounter.h"

void DownCounter::count_down_behav(void) {
    for (int i = 3; i >= 0; i--)
    {
        std::cout << "Count:: " << i << std::endl;
    }
    
}