Write a C program and run it in command prompt.
1--------------------------------
#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"hello world !!!!!!!!"<<endl;
    return 0;
}
Write a C program then create a makefile and run the program using that makefile.
2-----------------------------------------
#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"hello world ! ,,, using makefile"<<endl;
    return 0;
}
Write a C or C++ program that accepts a filename as command line argument and prints the file’s
contents on console. If the file does not exist, print some error on the screen.
3----------------------------------------------
#include<bits/stdc++.h>
using namespace std;
int main(int a,char* arg[])
{
    freopen(arg[1],"r",stdin);
    string s;
    getline(cin,s);
    cout<<s<<endl;
    return 0;
}
Create a program that creates a child process. The child process prints “I am a child process” 100
times in a loop. Whereas the parent process prints “I am a parent process” 100 times in a loop.
4------------------------------------------
#include<bits/stdc++.h>
using namespace std;
int main()
{
    pid_t pid = fork();
    if(pid<0) cout<< "No process has been created "<<endl;
    else if(pid==0) for(int i=0;i<101;i++) cout<< "I am child !!"<<endl;
    else for(int i=0;i<101;i++) cout<< "I am parent"<<endl;
    return 0;
}
write a program which uses fork ()/CreateProcess system-call to create a child process. The child
process prints the contents of the current directory and the parent process waits for the child
process to terminate.
5---------------------------------------------
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

