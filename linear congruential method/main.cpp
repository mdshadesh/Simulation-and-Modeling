#include <bits/stdc++.h>
using namespace std;

/* Returns Random Number as Integer */
int nextRandomInt(int x, int a, int c, int m)
{
    int xi = (a*x + c) % m;
    return xi;
}

int main()
{
    int n, a, c, x, m;
    printf("Enter value of x(seed value): ");
    scanf("%d", &x);
    printf("Enter value of a: ");
    scanf("%d", &a);
    printf("Enter value of c: ");
    scanf("%d", &c);
    printf("Enter value of m: ");
    scanf("%d", &m);
    printf("Enter total random number to be generated: ");
    scanf("%d", &n);

    int i;
    for(i=0; i<n; i++) {
        x = nextRandomInt(x, a, c, m);
        double r = (double)x/(double)m;
        printf("%f\n", r);
    }

    return 0;
}
