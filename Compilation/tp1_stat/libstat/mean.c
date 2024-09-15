
#include "mean.h"

double mean(double *data_set, size_t data_set_len)
{
    double X = 0.0;
    for (size_t i = 0 ; i < data_set_len ; i++) {
        X = data_set[i] + X;
    }
    return X / (double)data_set_len ;     
}

/*#include "mean.h"

double mean(double *data_set, size_t data_set_len)
{
    double sum = 0.0;
    for(size_t i = 0; i < data_set_len; i += 1)
    {
        sum += data_set[i];
    }
    
    return sum / (double)data_set_len;
}*/

