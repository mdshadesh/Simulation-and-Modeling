#include<bits/stdc++.h>
#include<conio.h>

using namespace std;

int random(int x0, int a, int c, int m)
{
    int x1 = (a * x0 + c) % m ;
    return x1 ;
}

int main()
{
    int a, c, x0, m, n;
    cin>> a>>x0>>c>>m>>n;
	 double x, r1;

    for(int i = 0; i < n; i++)
    {
        x =random(x0,a,c,m);

        r1 = x / m;

        cout<<"random nunber is : " <<r1<<endl;

    }


    return 0;
}