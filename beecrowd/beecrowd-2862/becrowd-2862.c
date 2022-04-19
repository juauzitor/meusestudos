#include <stdio.h>

int main (int argc, char *argv[]){
    int n, p, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &p);
        if (p > 8000) {
            printf("Mais de 8000!\n");
        } else{
            printf("Inseto!\n");
        }
    }
    return 0;
}
