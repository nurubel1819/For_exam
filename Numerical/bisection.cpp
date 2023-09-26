#include<bits/stdc++.h>
using namespace std;

double bisectin_method(double p)
{
    return pow(p,3)+(2*p*p)-p+8;
}

double find_root_bisection(double a, double b)
{
    return (a+b)/2;
}

int main()
{
    double a,b;
    cout<< "Enter lower and upper bound with space : ";
    cin>>a>>b;
    double f_a,f_b,f_c,c;
    for(int i=0;i<=100;i++)
    {
        c = find_root_bisection(a,b);
        cout<<"Iteration number : "<<i+1<<" = "<<c<<endl;
        f_a = bisectin_method(a);
        f_b = bisectin_method(b);
        f_c = bisectin_method(c);
        if(f_a*f_c>0) a=c;
        else b=c;

    }

    return 0;
}
