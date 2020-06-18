#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
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
*/

//---------------

class str {
private:
    char* S;
public:
    static int countInstances() {
        static int ctr = 0;
        return ctr++;
    }
    str();
    str(const char*);
    str(const str& s);
    ~str();
    char* rep();
    void rep(const char* msg);
    char* get();
    char& get(const int);
    void set(const int, const char);
    //void set(const char* msg);
    str& set(const char* msg);
};
str::str() {
    countInstances();
    this->S = nullptr;
}
str::str(const char* msg) {
    countInstances();
    this->S = new char[strlen(msg)+1];
    for (int i = 0; i < strlen(msg); i++) {
        this->S[i] = msg[i];
    }
    this->S[strlen(msg)] = '\0';
}
str::str(const str& s) {
    countInstances();
    if (s.S == nullptr) {
        this->S = nullptr;
        return;
    }
    this->S = new char[strlen(s.S) + 1];
    for (int i = 0; i < strlen(s.S); i++) {
        this->S[i] = s.S[i];
    }
    this->S[strlen(s.S)] = '\0';
}
str::~str() {
    delete this->S;
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

char* str::get() {
    return this->S;
}
char& str::get(const int i) {
    return this->S[i];
}

void str::set(const int i, const char CH) {
    this->S[i] = CH;
}
/*
void str::set(const char* msg) {
    if (this->S != nullptr) {
        delete(this->S);
    }
    this->S = new char[strlen(msg) + 1];
    this->S = strdup(msg);
}
*/
str& str::set(const char* msg){
    if (this->S != nullptr) {
        delete(this->S);
    }
    this->S = strdup(msg);
    return *this;
}
void Assert(bool cond, const char* message) {
    if (!cond) {
        std::cout << message;
    }
    else {
        cout << "GOOD" << endl;
    }
}
void assert(bool expression, const char* context, const char* message) {
    if (!expression) {
        std::cout << "Assertion failed in [" << context << "]: " << message << std::endl;
    }
}
void f(str s) { // copy constructor gets called
    str s2 = s; // copy of copy is made

    s.rep("another string");

    Assert(0 == strcmp("This is my string", s2.rep()), "Copy constructor should make a copy of the content.");
} //end of function, both copies get destroyed
//------------------------------------
/*
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
*/
/*
void test1() {
    str s = "This is my string";
    Assert(0 == strcmp("This is my string", s.rep()), "(1) s representation error.");
}
void test2() {
    str s;
    Assert(nullptr == s.rep(), "(2) s representation error.");
}
void test3() {
    str s = "This is a string";
    str s2 = s;
    Assert(0 == strcmp("This is a string", s2.rep()), "(3) s representation error.");
}
void test4() {
    str s = "This is a string";
    s.rep("This is MY string");
    Assert(0 == strcmp("This is MY string", s.rep()), "(4) s representation error.");
}
void test5() {
    str s = "This is a string";
    str s2;
    s2 = s;
    Assert(0 == strcmp("This is a string", s2.rep()), "(5.1) s representation error.");
    s.rep("String has changed");
    Assert(0 == strcmp("String has changed", s.rep()), "(5.2) s representation error.");
    Assert(0 == strcmp("This is a string", s2.rep()), "(5.3) s representation error.");
}
*/
/*
void testDefaultCtorShouldInitializeWithNull() {
    str s;
    assert(NULL == s.get(), "testDefaultCtorShouldInitializeWithNull", "internal representation error");
}
void testCtorShouldAllocateOwnMemory() {
    char* test = new char[strlen("Test") + 1];
    strcpy(test, "Test");

    str s{ test };
    assert(0 == strcmp(test, s.get()), "testCtorShouldAllocateOwnMemory", "internal representation error");

    test[1] = 'E';
    assert(0 == strcmp("TEst", test), "testCtorShouldAllocateOwnMemory", "shared memory error");
    assert(0 == strcmp("Test", s.get()), "testCtorShouldAllocateOwnMemory", "shared memory error");

    delete[] test;
}
void testCopyCtorShouldNotAlterSource() {
    const char* test = "Test";
    str s1{ test }, s2 = s1;
    assert(0 == strcmp(test, s1.get()), "testCopyCtorShouldNotAlterSource", "internal representation error");
    assert(0 == strcmp(test, s2.get()), "testCopyCtorShouldNotAlterSource", "internal representation error");
}
void testCopyCtorShouldDuplicateContent() {
    const char* test = "Test";
    str s1{ test }, s2 = s1;
    assert(0 == strcmp(test, s1.get()), "testCopyCtorShouldDuplicateContent", "internal representation error");
    assert(0 == strcmp(test, s2.get()), "testCopyCtorShouldDuplicateContent", "internal representation error");

    s1.set(3, 'T');
    assert(0 == strcmp("TesT", s1.get()), "testCopyCtorShouldDuplicateContent", "internal representation error");
    assert(0 == strcmp(test, s2.get()), "testCopyCtorShouldDuplicateContent", "internal representation error");
}
void testCopyCtorShouldInitializeWithNullOnNullSource() {
    str s1, s2 = s1;
    assert(NULL == s1.get(), "testCopyCtorShouldInitializeWithNullOnNullSource", "11internal representation error");
    assert(NULL == s2.get(), "testCopyCtorShouldInitializeWithNullOnNullSource", "internal representation error");
}
void testDestructorShouldNotFailOnNullString() {
    str* pstr = new str;
    delete pstr;
    assert(true, "testDestructorShouldNotFailOnNullString", "destructor failed on NULL content");
}
void testDestructorShouldShouldFreeOwnMemory() {
    const char* test = "Test";
    str s1{ test };
    str* pstr = new str{ s1 };
    delete pstr;
    assert(0 == strcmp(test, s1.get()), "testDestructorShouldShouldFreeOwnMemory", "memory deallocation failed");
}
void testSetShouldDuplicateContent() {
    char* test = new char[strlen("Test") + 1];
    strcpy(test, "Test");
    str s1, s2;
    assert(NULL == s1.get(), "testSetShouldDuplicateContent", "internal representation error");
    assert(NULL == s2.get(), "testSetShouldDuplicateContent", "internal representation error");

    s1.set(test);
    assert(0 == strcmp("Test", test), "testSetShouldDuplicateContent", "internal representation error");
    assert(0 == strcmp(test, s1.get()), "testSetShouldDuplicateContent", "internal representation error");

    test[3] = 'T';
    assert(0 == strcmp("TesT", test), "testSetShouldDuplicateContent", "internal representation error");
    assert(0 == strcmp("Test", s1.get()), "testSetShouldDuplicateContent", "internal representation error");
    delete test;
}
void testSetShoultNotAlterSource() {
    const char* test = "Test";
    str s1, s2;
    assert(NULL == s1.get(), "testSetShoultNotAlterSource", "internal representation error");
    assert(NULL == s2.get(), "testSetShoultNotAlterSource", "internal representation error");

    s1.set(test);
    assert(0 == strcmp("Test", test), "testSetShoultNotAlterSource", "internal representation error");
    assert(0 == strcmp(test, s1.get()), "testSetShoultNotAlterSource", "internal representation error");
}
void testGetShouldReturnNull() {
    assert(NULL == str{}.get(), "testGetShouldReturnNull", "internal representation error");
}
void testIndexedGetShouldReturnAModifiableReference() {
    const char* test = "Test";
    str s1{ test }, s2 = s1;
    assert(0 == strcmp(test, s1.get()), "testIndexedGetShouldReturnAModifiableReference", "internal representation error");
    assert(0 == strcmp(test, s2.get()), "testIndexedGetShouldReturnAModifiableReference", "internal representation error");

    s1.get(3) = 'T';
    assert(0 == strcmp("TesT", s1.get()), "testIndexedGetShouldReturnAModifiableReference", "internal representation error");
    assert(0 == strcmp(test, s2.get()), "testIndexedGetShouldReturnAModifiableReference", "internal representation error");
}
void testChainedSet() {
    str greet = "Hello";
    assert(0 == strcmp("Hello", greet.get()), "testChainedSet", "internal representation error");

    greet.set("Hi").set("Buna");
    assert(0 == strcmp("Buna", greet.get()), "testChainedSet", "set failed");
}
void testCounter() {

    str s1 = "This is test", s2, s3 = s1;
    Assert(3 == str::countInstances(), "Number of instances mismatch.");

}
*/
/*
struct C{
    int c;
    C(int i) {
        this->c = i;
        std::cout << "C::C(" << i << ")" << std::endl;
    }
    static C c0;
    static void f(C c);
};
C C::c0 = 0;
C c1 = 1;
void C::f(C c){
    C c2 = c.c;
}
*/
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
/*
            test1();
            test2();
            test3();
            test4();
            */
/*
                str s("A string"), s2 = s;
                f(s);
                */
/*
                    test1();
                    test2();
                    test3();
                    test4();
                    test5();
                    */
/*
                        testDefaultCtorShouldInitializeWithNull();
                        testCtorShouldAllocateOwnMemory();
                        testCopyCtorShouldNotAlterSource();
                        testCopyCtorShouldDuplicateContent();
                        testCopyCtorShouldInitializeWithNullOnNullSource();
                        testDestructorShouldNotFailOnNullString();
                        testDestructorShouldShouldFreeOwnMemory();
                        testSetShouldDuplicateContent();
                        testSetShoultNotAlterSource();
                        testGetShouldReturnNull();
                        testIndexedGetShouldReturnAModifiableReference();
                        testChainedSet();
                        */
/*
                            vector<int> V = { 1,2,3,4,7,8,9,10,11,12 };
                            sort(V.begin(), V.end());
                            cout << "Count >5: ";
                            std::vector<int>::iterator iter = std::find_if(V.begin(), V.end(), [](int i) {return i > 5; });
                            cout << V.size() - distance(V.begin(), iter);
                            */

class Tree {
    class Node {
    public:
        Node* right;
        Node* left;
        int value;
        Node(int);
        ~Node();
    };
    Node* root;
public:
    Tree();
    void inorder() const;
    void insert(int);
};
Tree::Tree() :root(NULL) {}
Tree::Node::Node(int a){
    this->value = a;
    this->left = NULL;
    this->right = NULL;
}
Tree::Node::~Node(){
    delete right;
    delete left;
}
// WRONG!~!!!!!
void Tree::insert(int a) {
    if (this->root == NULL) {
        this->root = new Tree::Node(a);
    }
    else if (a < this->root->value && this->root->left == NULL) {
        this->root->left = new Tree::Node(a);
    }
    else{
        this->root->right = new Tree::Node(a);
    }
}
// WRONG!~!!!!!
void Tree::inorder()const {
    if (this->root == NULL) {
        return;
    }
    cout << this->root->left->value << " " << this->root->value << " " << this->root->right->value;
}

int main() {
    Tree t;
    int i, n;
    cin >> n;
    while (n > 0) {
        cin >> i;
        t.insert(i);
        n--;
    }
    t.inorder();
    return 0;
}