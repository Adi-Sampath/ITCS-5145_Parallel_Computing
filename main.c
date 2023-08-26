#include <math.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif
    
    float f1(float x, int intensity);
    float f2(float x, int intensity);
    float f3(float x, int intensity);
    float f4(float x, int intensity);
    
#ifdef __cplusplus
}
#endif

double calc_numerical_integration(int functionid, int a, int b, int n, int intensity){

    float con = (b - a) / n;
    float sum = 0;
    for(int i = 0; i <= (n - 1); i++) {
        float x = a + (i + 0.5) * con;
        if(functionid == 1) {
            sum += f1(x, intensity);
        }
        else if(functionid == 2) {
            sum += f2(x, intensity);
        }
        else if(functionid == 3) {
            sum += f3(x, intensity);
        }
        else if(functionid == 4) {
            sum += f4(x, intensity);
        }
    }
    return con * sum;
}
int main (int argc, char* argv[]) {
    
    if (argc < 6) {
        fprintf(stderr, "usage: %s <functionid> <a> <b> <n> <intensity>", argv[0]);
        return -1;
    }
    
    for(int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }
    
    clock_t t; // t represents clock ticks which is of type 'clock_t'
    t = clock(); // start clock
    double r = calc_numerical_integration(function_id, a, b, n, intensity);
    t = clock()-t; // end clock=
    float time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds; CLOCKS_PER_SEC is the number of clock ticks per second
    printf("%lf\n", r);
    fprintf(stderr, "%f\n", time_taken);
    
    return 0;
}

