#include <iostream>
#include <string>
#include <cstring>
#pragma warning(disable : 4996)
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
class Point2D {
private:
    int x;
    int y;
public:
    Point2D(int, int);
    Point2D(const Point2D&);
    int getX();
    int getY();

};
Point2D::Point2D(int x, int y) {
    this->x = x;
    this->y = y;
}
int Point2D::getX() {
    return this->x;
}
int Point2D::getY() {
    return this->y;
}
Point2D::Point2D(const Point2D& p) {
    this->x = p.x;
    this->y = p.y;
    cout << "Copy constructor called for point(" << this->getX() << ", " << this->getY() << ")" << endl;
}
void f(Point2D p) {
    
}

class str {
private:
    char* S;
public:
    str();
    str(const char*);
    str(const str& s);
    char* rep();
    void rep(const char* msg);
};

str::str() {
    this->S = nullptr;
}
str::str(const char* msg) {
    this->S = new char[strlen(msg)+1];
    for (int i = 0; i < strlen(msg); i++) {
        this->S[i] = msg[i];
    }
    this->S[strlen(msg)] = '\0';
}
str::str(const str& s) {
    if (&s == nullptr) {
        this->S = nullptr;
    }
    this->S = new char[strlen(s.S) + 1];
    for (int i = 0; i < strlen(s.S); i++) {
        this->S[i] = s.S[i];
    }
    this->S[strlen(s.S)] = '\0';
}

char* str::rep() {
    return this->S;
}

void str::rep(const char* msg) {
    if (this->S != nullptr) {
        delete(this->S);
    }
    this->S = new char[strlen(msg) + 1];
    for (int i = 0; i < strlen(msg); i++) {
        this->S[i] = msg[i];
    }
    this->S[strlen(msg)] = '\0';
}


void Assert(bool cond, const char* message) {
    if (!cond) {
        std::cout << message;
    }
    else {
        cout << "GOOD" << endl;
    }
}

void test1() {
    str s = "This is my string";
    Assert(0 == strcmp("This is my string", s.rep()), "s representation error.");
}

void test2() {
    str s;
    Assert(nullptr == s.rep(), "s representation error.");
}

void test3() {
    str s = "This is a string";
    s.rep("This is MY string");
    Assert(0 == strcmp("This is MY string", s.rep()), "s representation error.");
}

void test4() {

    str s = "This is my string", s2 = s;
    s.rep("another string");

    Assert(0 == strcmp("This is my string", s2.rep()), "Copy constructor should make a copy of the content.");

}

int main() {
    /*
    string str;
    getline(cin,str);
    cout << str<<endl;
    */
    /*
    int x, y;
    std::cin >> x >> y;
    Point2D p1 = Point2D(x, y);
    Point2D p2 = p1;
    //cout << p1.getX() << " " << p1.getY() << endl;
    f(p2);
    */
        
    test1();
    test2();
    test3();
    test4();
    return 0;

}