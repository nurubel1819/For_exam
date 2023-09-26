#include<bits/stdc++.h>
using namespace std;

double function_second_method(double p)
{
    return pow(p,3)+(2*p*p)-p+8;
}

double find_nexe_second_method(double xo , double xi)
{
    return (xi-((xi-xo)/(function_second_method(xi)-function_second_method(xo)))*function_second_method(xi));
}

int main()
{
    cout<< "find root using second method "<<endl;
    double a=-100,b=100;
    a=function_second_method(a);
    b=function_second_method(b);
    double root_value;
    for(int i=0;i<100;i++)
    {
        if(a==b) break;
        root_value = find_nexe_second_method(a,b);
        cout<<root_value<<endl;
        a=b;
        b=root_value;
    }
    return 0;
}
