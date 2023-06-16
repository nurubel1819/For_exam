1. Write a C program and run it in command prompt************************************
nano / gedit a.cpp
g++ -o a a.cpp
./a 
2. Write a C program then create a makefile and run the program using that makefile*****************
nano main.cpp 
#include<bits/stdc++.h> 
using namespace std;
#include<head.h>
int main() {
    cout << "I am main" << endl;
    a();
    b();
}
nano a.cpp
nano b.cpp
nano head.h -> void a(); void b();
g++ main.cpp a.cpp b.cpp -o makefile
./makefile
3. Write a C or C++ program that accepts a filename as command line argument and prints the file’s
contents on console. If the file does not exist, print some error on the screen.***********************************

gedit input.txt
gedit code.cpp
g++ -o code code.cpp
./code input.txt

#include<bits/stdc++h>
using namespace std;
int main(int c, char *arg[])
{
    if (freopen(arg[1],"r",stdin) == NULL) {
        cout << "No File Created" << endl;
        exit(0);
    }
    freopen(arg[1],"r",stdin);
    string s;
    while(cin >> s) cout << s << endl;
    return 0;
}
a ab abc abcd abcde
4 Create a program that creates a child process. The child process prints “I am a child process” 100
times in a loop. Whereas the parent process prints “I am a parent process” 100 times in a loop.******************************
gedit code.cpp
g++ -o code code.cpp
./code 

#include<bits/stdc++.h>
using namespace std;
int main() {
    pid_t pid = fork();
    if (pid < 0) cout << "NO File" << endl;
    else if (pid == 0) {
        for (int i = 0; i < 100; i++) cout << "Child" << endl;
    }
    else if (pid == 1) {
        for (int i = 0; i < 100; i++) cout << "parent" << endl;
    }
    return 0;
}
5.Write a program which uses fork ()/CreateProcess system-call to create a child process. The child
process prints the contents of the current directory and the parent process waits for the child
process to terminate.***********************************************************************************************

gedit code.cpp
g++ -o code code.cpp
./code 

#include<bits/stdc++.h>
using namespace std;
int main() {
    pid_t pid = fork();
    if (pid < 0) {
        cout << "Failed to fork process" << endl;
        return 1;
    }
    else if (pid == 0) {
        cout << "Child process starting" << endl;
        execl("/bin/ls","ls","-l",NULL);
        cout << "Child process finished" << endl;
        return 0;
    }
    else {
        cout << "Parent process waiting for child" << endl;
        cout << "Parent process finished" << endl;
        return 0;
    }
    return 0;
}
6.Calculate the waiting time, turn around time, average waiting time, and average turn
around time using the SJF, FCFS, priority scheduling, and Round Robin CPU scheduling
algorithms.************************************************************************************
//fcfs
#include <iostream>
using namespace std;
int main()
{
    int n=3;
    int ct[n], wt[n], tat[n];
    int  at[n] = {1,5,6};
    int  bt[n]= {4,8,10};
    ct[0] = at[0] + bt[0];
    for (int i = 1; i < n; i++) {
        ct[i] = ct[i-1] + bt[i];
    }
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }
    cout << "Process\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << i << "\t" << at[i] << "\t" << bt[i] << "\t" << ct[i] << "\t" << tat[i] << "\t" << wt[i] << endl;
    }
    return 0;
}
