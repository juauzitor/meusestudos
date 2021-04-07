#include<stdio.h>

int main()
{
    int base, height;
    float area;
    printf("Digite e confirme a altura e depois a base\n");
    scanf("%i %i", &height, &base);
    area = ((float)(height*base)/2);
    printf("Sua área é de: %f\n", area);
    return 0;
}
