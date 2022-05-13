#include <stdio.h>

int main (int argc, char *argv[]) {
    while(1){
        int ordens=0, cont=0, pos=0;
        scanf(" %d", &ordens);
        if(ordens !=0){
            char lados[ordens];
            scanf(" %s", lados);
            while (cont < ordens) {
/*                printf("%c\n", lados[cont]);*/
                if(lados[cont] == 'E'){
                    pos = pos-1;
                    if (pos == -2){
                        pos = 2;
                    }
                }
                else if (lados[cont] == 'D') {
                    pos = pos+1;
                    if(pos == 3){
                        pos = -1;
                    }
                }
                cont++;
            }
            switch (pos) {
                case 0:
                    printf("N\n");
                    break;
                case 1:
                    printf("L\n");
                    break;
                case 2:
                    printf("S\n");
                    break;
                case -1:
                    printf("O\n");
                    break;
            }
        }
        else {
            return 0;
        }
    }
}
