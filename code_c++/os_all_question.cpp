1.
nano / gedit a.cpp
g++ -o a a.cpp
./a 
2.
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
3.
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
4.
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
5.
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
6.
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
