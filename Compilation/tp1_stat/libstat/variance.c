#include "variance.h"
#include "mean.h"
#include <math.h>

double variance(double *data_set, size_t data_set_len)
{
    double moy = 0.0;
    double variance_tmp = 0.0;

    for (int i = 0 ; i<data_set_len ; i++ )
    {
        moy = (data_set[i] - mean(data_set , data_set_len));
        variance_tmp = moy*moy + variance_tmp ;
    }

    return variance_tmp/ (double) data_set_len;
}


double stddev(double *data_set, size_t data_set_len) 
{
    return sqrt(variance (data_set , data_set_len));
}