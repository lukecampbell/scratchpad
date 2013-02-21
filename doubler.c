#include <stdlib.h>
#include "doubler.h"

int doubler(size_t len, double *arr) {
    int i=0;
    for(i=0;i<len;i++){
        arr[i]*=2;
    }
    return 0;
}


