#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, observed[20], N, expected;
    float calculation[200], final, crutucal;
    N=0;
    final =0.0;
    cout<<"Enter the total class : ";
    cin>>n;
    for(int i=0; i<=n; i++)
    {
        cout<<"Enter Your object Frequency : ";
        cin>>observed[i];
    }
    for(int i=0; i < n; i++)
    {
        N = N+observed[i];
    }
    expected = N/n;
    for (int i = 0; i < n; i++)
    {
        calculation[i] =(float) ((observed[i]-expected)* (observed[i]-expected)) / expected;
        final = final + calculation[i];
    }
    cout<<endl;
    cout<<"Enter the critical value :"<<endl;
    cin>>crutucal;
    if(final <crutucal)
    {
        cout<<"The Test is Accepted"<<endl;
    }
    else
    {
        cout<<"The test is Rejected"<<endl;
    }
    return 0;
}