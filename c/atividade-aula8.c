#include<stdio.h>

int main()
{
    float base, height;
    printf("Digite e confirme a altura e depois a base\n");
    scanf("%f %f", &height, &base);
    printf("Sua área é de: %.2f\n", ((height*base)/2));
    return 0;
}
