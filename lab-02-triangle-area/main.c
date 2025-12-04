#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
   
    double a, b, c, u, area;

    printf("enter the edges of triangle (e.g. 3 4 5): ");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (a + b > c && a + c > b && b + c > a) {

        u = (a + b + c) / 2.0;
        area = sqrt(u * (u - a) * (u - b) * (u - c));

        printf("the area of the triangle is: %.2f\n", area);
    }
    else {
        printf("the given values do not form a valid triangle\n");
    }

    return 0;
}