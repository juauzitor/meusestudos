#include <stdio.h>
#include <math.h>


int main (int argc, char *argv[]){
    long long int num_rep = 0, i = 0, sold = 0, n = 0, aux=0;
    scanf("%lld", &num_rep);
    for (i = 0; i < num_rep; i++) {
        scanf("%lld", &sold);
        aux = (1+8*sold);
        n = (sqrt(aux)-1)/2;
        printf("%lld\n", n);
    }
    return 0;
}
