#include <stdio.h>

int main (int argc, char *argv[]){
    int num_casos, i, aux, aux2;
    int unused __attribute__((unused));
    while (1) {     
        unused = scanf("%d", &num_casos);
        int casos[num_casos];
        int t = 10;
        for (i = 0;i < num_casos; i++) {
            unused = scanf("%d", &aux);
            casos[i] = aux;
        }
        if(num_casos != 0){
            for (i = 1;i < num_casos; i++) {
                aux2 = casos[i]-casos[i-1];
                if(aux2 < 10){
                    t=t+aux2;
                }
                else{
                    t=t+10;
                }
            }
            printf("%d\n", t);
        }
    else{
        return 0;
    }
    }
}
