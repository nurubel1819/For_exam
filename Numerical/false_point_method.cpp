/*
#include<bits/stdc++.h>
using namespace std;

double find_function_value(double p)
{
    return pow(p,3)+(2*p*p)-p+8;
}

double find_root(double a,double b)
{
    return ((a*find_function_value(b))-(b*find_function_value(a)))/(find_function_value(b)-find_function_value(a));
}

int main()
{
    cout<< "Find root false point method"<<endl;
    cout<< "Enter lower and upper bound with space : ";
    double a,b;
    cin>>a>>b;

    double f_a,f_b,f_c,c;

    for(int i=0;i<10000;i++)
    {

        c = find_root(a,b);
        //cout<< "value of "<<i+1<<"th iteration is = "<<c<<endl;
        f_a = find_function_value(a);
        f_b = find_function_value(b);
        f_c = find_function_value(c);
        if(f_a*f_c>0) a = c;
        else b = c;
    }
    cout<<c<<endl;
    return 0;
}
*/
// C++ program for implementation of Regular Falsi Method for
// solving equations
#include<bits/stdc++.h>
using namespace std;
#define MAX_ITER 1000000

// An example function whose solution is determined using
// Regular Falsi Method. The function is x^3 - x^2 + 2
double func(double p)
{
	return pow(p,3)+(2*p*p)-p+8;
}

// Prints root of func(x) in interval [a, b]
void regulaFalsi(double a, double b)
{
	if (func(a) * func(b) >= 0)
	{
		cout << "You have not assumed right a and b\n";
		return;
	}

	double c = a; // Initialize result

	for (int i=0; i < MAX_ITER; i++)
	{
		// Find the point that touches x axis
		c = (a*func(b) - b*func(a))/ (func(b) - func(a));

		// Check if the above found point is root
		if (func(c)==0)
			break;

		// Decide the side to repeat the steps
		else if (func(c)*func(a) < 0)
			b = c;
		else
			a = c;
	}
	cout << "The value of root is : " << c;
}

// Driver program to test above function
int main()
{
	// Initial values assumed
	double a =-100, b = 100;
	regulaFalsi(a, b);
	return 0;
}

