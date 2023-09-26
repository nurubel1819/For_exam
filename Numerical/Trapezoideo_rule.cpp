#include<bits/stdc++.h>
using namespace std;

double function_trapezoida_rule(double x)
{
    return 1/x;
}

double del_x_function(double upper_limit,double lower_limit,int n)
{
    return (upper_limit-lower_limit)/n;
}

int main()
{
    cout<< "Trapezoidal rule "<<endl;
    double l,u,n;
    l=1;///lower limit
    u=2;///upper limit
    n=10;
    double del_x = del_x_function(u,l,n);
    double xi,ans=0;
    for(int i=0;i<=n;i++)
    {
        xi = l+(i*del_x);
        if(i==0 or i==n) ans+=function_trapezoida_rule(xi);
        else ans+=function_trapezoida_rule(xi)*2;
    }
    ans = ans * (del_x/2);
    cout<< "Ans is : "<<ans<<endl;
    return 0;
}
