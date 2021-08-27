#include<stdio.h>
#include<math.h>
int main() {
    int a, b, c;
    float area,s;
    printf("Enter the triangle side's lengths : ");
    scanf("%d%d%d", &a, &b, &c);
    s = a+b+c;
    area = sqrt(s/2 * (s/2 - a) * (s/2 - b) * (s/2 - c));
    if (area!=0)printf("%.3f",area);
    else printf("0");
}
    
