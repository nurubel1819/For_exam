
\\\\\\\\\\\\\\ Bisection Method //////////////
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include<bits/stdc++.h>
using namespace std;

// Define the function for which you want to find the root
double f(double x) {
    return x * x * x - x * x + 2; //which has a root at x = 2.
}

// Bisection method implementation
double bisectionMethod(double a, double b, double epsilon, int maxIterations) {
    if (f(a) * f(b) >= 0.0) {
        cout << "The function has the same sign at both endpoints. Bisection method cannot be applied." << endl;
        return NAN; // Return NaN (Not-a-Number) to indicate an error.
    }

    double c;
    int iteration = 0;

    do {
        c = (a + b) / 2.0;

        cout << f(c) << endl;
        if (fabs(f(c)) < epsilon) {
            cout << "Converged to root within epsilon after " << iteration << " iterations." << endl;
            return c;
        }

        if (f(c) * f(a) < 0) {
            b = c;
        } else {
            a = c;
        }

        iteration++;
    } while (iteration < maxIterations);

    cout << "Maximum number of iterations reached." << endl;
    return c;
}

int main() {
    double a = -100.0; // Left endpoint of the interval
    double b = 300.0; // Right endpoint of the interval
    double epsilon = 0.01; // Tolerance for convergence
    int maxIterations = 100; // Maximum number of iterations

    double root = bisectionMethod(a, b, epsilon, maxIterations);

    cout << "Approximate root: " << root << endl;

    return 0;
}


\\\\\\\\\\\\\\ False Position Method //////////////
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include<bits/stdc++.h>
using namespace std;

// Define the function for which you want to find the root
double f(double x) {
    return pow(x, 3) + x - 1; // Example: f(x) = x^2 - 4, which has a root at x = 2.
}

// False position method implementation
double falsePositionMethod(double a, double b, double epsilon, int maxIterations) {
    if (f(a) * f(b) >= 0) {
        cout << "The function has the same sign at both endpoints. False position method cannot be applied." << endl;
        return NAN; // Return NaN (Not-a-Number) to indicate an error.
    }

    double c;
    int iteration = 0;

    do {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));

        if (c == 0) break;
        if (fabs(f(c)) < epsilon) {
            cout << "Converged to root within epsilon after " << iteration << " iterations." << endl;
            return c;
        }

        if (f(c) * f(a) < 0) {
            b = c;
        } else {
            a = c;
        }

        iteration++;
    } while (iteration < maxIterations);

    cout << "Maximum number of iterations reached." << endl;
    return c;
}

int main() {
    double a = 0.0; // Left endpoint of the interval
    double b = 1.0; // Right endpoint of the interval
    double epsilon = 0.0001; // Tolerance for convergence
    int maxIterations = 100; // Maximum number of iterations

    double root = falsePositionMethod(a, b, epsilon, maxIterations);

    cout << "Approximate root: " << root << endl;

    return 0;
}


\\\\\\\\\\\\\\ Secant Method //////////////
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include<bits/stdc++.h>
using namespace std;

// Define the function for which you want to find the root
double f(double x) {
    return pow(x, 3) + x - 1; // Example: f(x) = x^2 - 4, which has a root at x = 2.
}

// Secant method implementation
double secantMethod(double x0, double x1, double epsilon, int maxIterations) {
    double x2;
    int iteration = 0;

    do {
        if (fabs(x1 - x0) < epsilon) {
            cout << "Converged to root within epsilon after " << iteration << " iterations." << endl;
            return x1;
        }

        x2 = x1 - (f(x1) * (x1 - x0)) / (f(x1) - f(x0));

        cout << fixed << setprecision(6) << x2 << " " << f(x2) << endl;
        x0 = x1;
        x1 = x2;

        iteration++;
    } while (iteration < maxIterations);

    cout << "Maximum number of iterations reached." << endl;
    return x1;
}

int main() {
    double x0 = 0.0; // Initial guess 1
    double x1 = 1.0; // Initial guess 3
    double epsilon = 0.0001; // Tolerance for convergence
    int maxIterations = 100; // Maximum number of iterations

    double root = secantMethod(x0, x1, epsilon, maxIterations);

    cout << "Approximate root: " << root << endl;

    return 0;
}


\\\\\\\\\\\\\\ Trapezoidal Rule //////////////
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include<bits/stdc++.h>
using namespace std;

// Define the function to be integrated
double f(double x) {
    return x * x; // Example: f(x) = x^2.
}

// Trapezoidal rule implementation for numerical integration
double trapezoidalRule(double a, double b, int n) {
   double h = (b - a) / n;
   double integral = 0.5 * (f(a) + f(b)); // Initialize integral with the values at the endpoints
   for (int i = 1; i < n; ++i) {
       double x = a + i * h;
       integral += f(x);
   }
   integral *= h;
   return integral;
}

int main() {
    double a = 0.0; // Lower limit of integration
    double b = 2.0; // Upper limit of integration
    int n = 1000;   // Number of subintervals (higher values provide better accuracy)

    double integral = trapezoidalRule(a, b, n);

    cout << "Approximate integral: " << integral << endl;

    return 0;
}


\\\\\\\\\\\\\\ Simpson Rule 1/3: //////////////
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <bits/stdc++.h>
using namespace std;

// Define the function to be integrated
double f(double x)
{
   return x * x; // Example: f(x) = x^2.
}

// Simpson's 1/3 rule implementation for numerical integration
double simpsonsOneThirdRule(double a, double b, int n)
{
   double h = (b - a) / n;        // Calculate the width of each subinterval
   double integral = f(a) + f(b); // Initialize integral with the values at the endpoints

   // Loop to calculate the sum of areas using Simpson's 1/3 rule
   for (int i = 1; i < n; ++i)
   {
      double x = a + i * h; // Calculate the x-coordinate of the current point

      // Determine whether the current term should be multiplied by 4 or 2
      if (i % 2 == 0)
      {
         integral += 2 * f(x);
      }
      else
      {
         integral += 4 * f(x);
      }
   }

   integral *= h / 3.0; // Multiply by h/3 to get the final integral estimate

   return integral;
}

int main()
{
   double a = 0.0; // Lower limit of integration
   double b = 2.0; // Upper limit of integration
   int n = 4;      // Number of subintervals (should be an even number for Simpson's 1/3 rule)

   double integral = simpsonsOneThirdRule(a, b, n);

   cout << "Approximate integral: " << integral << endl;

   return 0;
}



\\\\\\\\\\\\\\ Simpson Rule 3 / 8: //////////////
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <bits/stdc++.h>
using namespace std;

// Define the function to be integrated
double f(double x)
{
   return x * x; // Example: f(x) = x^2.
}

// Simpson's 3/8 rule implementation for numerical integration
double simpsonsThreeEighthRule(double a, double b, int n)
{
   double h = (b - a) / n;        // Calculate the width of each subinterval
   double integral = f(a) + f(b); // Initialize integral with the values at the endpoints

   // Loop to calculate the sum of areas using Simpson's 3/8 rule
   for (int i = 1; i < n; ++i)
   {
      double x = a + i * h; // Calculate the x-coordinate of the current point

      // Determine whether the current term should be multiplied by 3 or 2
      if (i % 3 == 0)
      {
         integral += 2 * f(x);
      }
      else
      {
         integral += 3 * f(x);
      }
   }

   integral *= 3.0 * h / 8.0; // Multiply by 3h/8 to get the final integral estimate

   return integral;
}

int main()
{
   double a = 0.0; // Lower limit of integration
   double b = 2.0; // Upper limit of integration
   int n = 6;      // Number of subintervals (should be a multiple of 3 for Simpson's 3/8 rule)

   double integral = simpsonsThreeEighthRule(a, b, n);

   cout << "Approximate integral: " << integral << endl;

   return 0;
}
