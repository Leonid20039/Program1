// 112-Чудновский-Леонид
#include <stdlib.h>
double random(double Low, double High){
    return ((double)rand() * (High-Low))/
(double)RAND_MAX + Low;
}