#include <iostream>
#include <string>
using namespace std;
/*
int a = 1;

int f(int) { a = 2000; return a; };

int g(int x = f(a)) { return x; };

void h()
{
    a = 2;
    {
        int a = 3;
        cout << g();
    }
}

int main()
{
    h();
    return 0;
}
*/

int main() {
    string str;
    getline(cin,str);
    cout << str<<endl;
    return 0;
}