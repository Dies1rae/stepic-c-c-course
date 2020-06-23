#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#define complexi complex<int>
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
//---------
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
/*
void f(str s) { // copy constructor gets called
    str s2 = s; // copy of copy is made

    s.rep("another string");

    Assert(0 == strcmp("This is my string", s2.rep()), "Copy constructor should make a copy of the content.");
} //end of function, both copies get destroyed
*/
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
/*
void test1() {
    Picture p = "http://test.png";
    Assert(0 == strcmp("http://test.png", p.url()), "(1) representation error.");
}
void test2() {
    // The following line would yield a compilation error
    // Picture p;
}
void test3() {
    Picture p{ "c:\\localfile\\test.png" };
    Picture p2{ p };
    Assert(0 == strcmp("c:\\localfile\\test.png", p2.url()), "(2) representation error.");
}
*/
/*
Tree t;
int i, n;
cin >> n;
while (n > 0) {
    cin >> i;
    t.insert(i);
    n--;
}
t.inorder();


test1();
test2();
test3();

str s{ "John" };
str ph{ "0700123456" };
str picUrl{ "http://example.com/pic.png" };
Member m(s, ph, Date(31, 3, 2020), picUrl), m2 = m;
m.setPicture(str("file:///home/user/pic.png"));
Picture p = m2.picture();
Group g(str("Group 1"), str("a description"), Date(2, 4, 2020), str("file:///home/user/groupPic.png"));
g.addMember(m);
g.addMember(m2);
g.showMEM(m);
g.showMEM(m2);
g.removeMember(m);
*/
/*
Account* pa = new Account;
Account* pm = new Member;
Account* pg = new Group;

pa->describe();
pm->describe();
pg->describe();
*/
/*
  str s{ "John" };
  str ph{ "0700123456" };
  str picUrl{ "http://example.com/pic.png" };
  Account* m = new Member(s, ph, Date(31, 3, 2020), picUrl);

  std::cout << m->getId() << " " << m->getName() << "\n";

  Account* g = new Group(str("Group 1"), str("a description"), Date(2, 4, 2020), str("file:///home/user/groupPic.png"));
  std::cout << g->getId() << " " << g->getName() << "\n";
  delete m;
  delete g;
  */
//---------
class Tree {
public:
    class Node {
        Node* right;
        Node* left;
        int value;
    public:
        Node(int);
        ~Node();
        int getval();
        void insertN(int);
        void printIN();
    };
private:
    Node* root;
public:
    Tree();
    void inorder() const;
    void insert(int a);
};
Tree::Tree() :root(NULL) {}
Tree::Node::Node(int a){
    this->value = a;
    this->left = NULL;
    this->right = NULL;
}
void Tree::Node::insertN(int a) {
    if(this->value > a) {
        if (this->left != NULL) {
            this->left->insertN(a);
        }
        else {
            this->left = new Node(a);
        }
    }
    else if (this->value < a) {
        if (this->right != NULL) {
            this->right->insertN(a);
        }
        else {
            this->right = new Node(a);
        }
    }
}
void Tree::Node::printIN() {
    if (this->left != NULL) {
        this->left->printIN();
    }
    cout << this->value << ' ';
    if(this->right != NULL) {
        this->right->printIN();
    }

}
Tree::Node::~Node(){
    delete right;
    delete left;
}
int Tree::Tree::Node::getval() {
    return this->value;
}
void Tree::insert(int a) {
    if (this->root == NULL) {
        this->root = new Node(a);
    }
    else {
        root->insertN(a);
    }
}
void Tree::inorder()const {
    if (this->root == NULL) {
        return;
    }
    else {
        this->root->printIN();
    }
}
//---------
class Account {
public:
    Account() { }
    virtual void describe() {
        std::cout << "I'm Account::describe()" << std::endl;
    }
    virtual int getId() {
        return 0;
    }
    virtual char *  getName() {
        char* res = (char*)malloc(15 * sizeof(char));
        strcpy_s(res,15,"Abstract fnctn\0");
        return res;
    }
};
//----------
class Picture: public Account {
private:
    char* S;
public:
    Picture();
    Picture(const char * msg);
    Picture(const Picture& obj);
    Picture(str obj);
    void rep(const char* msg);
    char* rep();
    ~Picture();
    char* url();
    void describe() override{
        std::cout << "I'm Picture::describe()" << std::endl;
    }
};
Picture::Picture(){
    this->S = nullptr;
}
Picture::Picture(const char* msg) {
    this->S = new char[strlen(msg) + 1];
    for (int i = 0; i < strlen(msg); i++) {
        this->S[i] = msg[i];
    }
    this->S[strlen(msg)] = '\0';
}
Picture::Picture(const Picture& obj) {
    if (obj.S == nullptr) {
        this->S = nullptr;
        return;
    }
    this->S = new char[strlen(obj.S) + 1];
    for (int i = 0; i < strlen(obj.S); i++) {
        this->S[i] = obj.S[i];
    }
    this->S[strlen(obj.S)] = '\0';
}
Picture::Picture(str msg) {
    this->S = new char[strlen(msg.get()) + 1];
    for (int i = 0; i < strlen(msg.get()); i++) {
        this->S[i] = msg.get()[i];
    }
    this->S[strlen(msg.get())] = '\0';
}
void Picture::rep(const char* msg) {
    if (this->S != nullptr) {
        delete(this->S);
    }
    this->S = new char[strlen(msg) + 1];
    for (int i = 0; i < strlen(msg); i++) {
        this->S[i] = msg[i];
    }
    this->S[strlen(msg)] = '\0';
}
char* Picture::rep() {
    return this->S;
}
Picture::~Picture() {
    delete this->S;
}
char* Picture::url() {
    return this->S;
}
//---------
class Member : public Account {
public:
    class Date {
    private:
        int DAY;
        int MONTH;
        int YEAR;
    public:
        Date() {
            this->DAY = NULL;
            this->MONTH = NULL;
            this->YEAR = NULL;
        }
        Date(int d, int m, int y) {
            this->DAY = d;
            this->MONTH = m;
            this->YEAR = y;
        }
        void setDate(int d, int m, int y) {
            this->DAY = d;
            this->MONTH = m;
            this->YEAR = y;
        }
        int* getDate() {
            int* arr;
            arr = (int*)malloc(3 * sizeof(int));
            arr[0] = this->DAY;
            arr[1] = this->MONTH;
            arr[2] = this->YEAR;
            return arr;
        }
        ~Date() {}
    };
private:
    static int Id() {
        static int ctr = 0;
        return ++ctr;
    }
    int ID;
    str Name;
    str phoneNumber;
    Date joinDate;
    Picture PIC;
public:
    Member(){}
    Member(str N, str PhN, Member::Date JD, str url) {
        this->ID = Id();
        this->Name.rep(N.get());
        this->phoneNumber.rep(PhN.get());
        this->joinDate.setDate(JD.getDate()[0], JD.getDate()[1], JD.getDate()[2]);
        this->PIC.rep(url.get());
    }
    int getID() {
        return this->ID;
    }
    void printMEMall() {
        cout << this->ID << ":" << this->Name.get() << ":" << this->phoneNumber.get() << ":" << this->PIC.rep() << ":" << this->joinDate.getDate()[0] << "//" << this->joinDate.getDate()[1] << "//" << this->joinDate.getDate()[2] << endl;
    }
    void setPicture(str nURL) {
        this->PIC.rep(nURL.get());
    }
    char* picture() {
        return this->PIC.rep();
    }
    char* getNameandPhN() {
        char* res;
        int LEN = strlen(this->Name.get()) + strlen(this->phoneNumber.get()) + 1;
        res = (char*)malloc(LEN * sizeof(char));
        for (int ptr = 0; ptr < strlen(this->Name.get()); ptr++) {
            res[ptr] = this->Name.get()[ptr];
        }
        for (int ptr = strlen(this->Name.get()); ptr < LEN; ptr++) {
            res[ptr] = this->phoneNumber.get()[ptr];
        }
        res[LEN] += '\0';
        return res;
    }
    void describe() override {
        Account::Account::describe();
        std::cout << "I'm Member::describe()" << std::endl;
    }
    int getId() override {
        return this->ID;
    }
    char* getName() override {
        return this->Name.get();
    }
};
Member::Date Date(int d, int m, int y) {
    Member::Date A(d,m,y);
    return A;
}
//---------
class Group : public Account {
public:
    class Date {
    private:
        int DAY;
        int MONTH;
        int YEAR;
    public:
        Date() {
            this->DAY = NULL;
            this->MONTH = NULL;
            this->YEAR = NULL;
        }
        Date(int d, int m, int y) {
            this->DAY = d;
            this->MONTH = m;
            this->YEAR = y;
        }
        void setDate(int d, int m, int y) {
            this->DAY = d;
            this->MONTH = m;
            this->YEAR = y;
        }
        int* getDate() {
            int* arr;
            arr = (int*)malloc(3 * sizeof(int));
            arr[0] = this->DAY;
            arr[1] = this->MONTH;
            arr[2] = this->YEAR;
            return arr;
        }
        ~Date() {}
    };
private:
    static int Id() {
        static int ctr = 1;
        return ++ctr;
    }
    int ID;
    str Name;
    str Description;
    Date joinDate;
    Picture PIC;
    vector<Member> MEM;
public:
    Group() { }
    Group(str N, str D, Member::Date JD, str url) {
        this->ID = Id();
        this->Name.rep(N.get());
        this->Description.rep(D.get());
        this->joinDate.setDate(JD.getDate()[0], JD.getDate()[1], JD.getDate()[2]);
        this->PIC.rep(url.get());
        this->MEM;
    }
    void addMember(const Member& M) {
        this->MEM.push_back(M);
    }
    void removeMember(const Member& M) {
        Member tmp = M;
        int tmpptr = 0;
        for (int ptr = 0; ptr < this->MEM.size(); ptr++) {
            if (strcmp(this->MEM[ptr].getNameandPhN(), tmp.getNameandPhN()) == 0) {
                tmpptr = ptr;
            }
        }
        this->MEM.erase(this->MEM.begin() + tmpptr);
    }
    void showMEM(const Member M) {
        Member tmp = M;
        tmp.printMEMall();
    }
    void describe() override {
        Account::Account::describe();
        std::cout << "I'm Group::describe()" << std::endl;
    }
    int getId() override {
        return this->ID;
    }
    char * getName() override {
        return this->Name.get();
    }
};
//---------
void test(){
    Account a;
    a.describe();

    Member m;
    m.describe();

    Group g;
    g.describe();
}
//---------
template <class T> class complex {
private:
    T R;
    T I;
public:
    complex() : R(0.0), I(0.0) {};
    complex(T r) : R(r), I(0.0) {};
    complex(T r, T i) : R(r), I(i) {};
    complex(const complex<T>& c):R(c.R), I(c.I) {};
    T real() {
        return this->R;
    }
    T imag() {
        return this->I;
    }
    complex<T> add(const complex<T>& c) {
        complex<T> tmpres(this->R+c.R, this->I+c.I);
        return tmpres;
    }
    complex<T> add(T r) {
        complex<T> tmpres(this->R + r, this->I);
        return tmpres;
    }
    void setReal(T r) {
        this->R = r;
    }
    void setImag(T i) {
        this->I = i;
    }
    T getReal() {
        return this->R;
    }
    T getImag() {
        return this->I;
    }
};
template <class T, class S>
complex<T> cast(complex<S> s) {
    complex<T> res;
    res.setReal(s.getReal());
    res.setImag(s.getImag());
    return res;
}
template <>
class complex<double> {
private:
    double Re;
    double Im;
public:
    constexpr complex(): Re(0.0), Im(0.0) {};
    complex(complex<float>& c):Re(c.getReal()), Im(c.getImag()) {};
    void setReal(double r) {
        this->Re = r;
    }
    void setImag(double i) {
        this->Im = i;
    }
    void setReal(float r) {
        this->Re = r;
    }
    void setImag(float i) {
        this->Im = i;
    }
    double real() {
        return this->Re;
    }
    double imag() {
        return this->Im;
    }
};
//---------
/*
void testComplexClass1() {
    complexi c{ 1, 2 };

    Assert(c.real() == 1, "Real part mismatch");
    Assert(c.imag() == 2, "Imag part mismatch");
}
void testComplexClass2() {
    complexi c1{ 1, 2 }, c2{ 2, 3 };

    Assert(c1.add(c2).real() == 3, "Addition: real part mismatch");
    Assert(c1.real() == 1, "Addition: operand has been modified");
    Assert(c2.add(c1).imag() == 5, "Addition: imag part mismatch");
    Assert(c2.real() == 2, "Addition: operand has been modified");
}
void testComplexClass3() {
    complexi c{ 1, 2 };

    Assert(c.add(2).real() == 3, "Scalar addition: real part mismatch");
    Assert(c.add(2).imag() == 2, "Scalar addition: imag part mismatch");
    Assert(c.real() == 1, "Scalar addition:operand has been changed");
    Assert(c.imag() == 2, "Scalar addition:operand has been changed");
}
void testComplexClass4() {
    complexi c1, c2{ 2 }, c3{ 3,4 }, c4{ 0, 1 }, c5 = c2;

    Assert(c1.real() == 0 && c1.imag() == 0, "c1 mis-initialized.");
    Assert(c2.real() == 2 && c2.imag() == 0, "c2 mis-initialized.");
    Assert(c3.real() == 3 && c3.imag() == 4, "c3 mis-initialized.");
    Assert(c4.real() == 0 && c4.imag() == 1, "c4 mis-initialized.");
    Assert(c5.real() == 2 && c5.imag() == 0, "c5 mis-initialized.");
}
void f(complexi c) {
    //std::cout << "Aha... copy ctor has been called." << std::endl;
    c.setReal(-1);
}
void g(complexi& c) {
    //std::cout << "Oohoo.. no ctor has been called." << std::endl;
    c.setReal(-1);
}
void testComplexClass5() {
    complexi c{ 3, 4 };
    f(c);
    Assert(c.real() == 3 && c.imag() == 4, "c has been modified.");
    g(c);
    Assert(c.real() == -1 && c.imag() == 4, "c not been modified.");
}
void testComplexClass6() {
    complex<double> c{ 3.5, 4.5 };
    Assert(c.real() == 3.5 && c.imag() == 4.5, "Real / imag part mismatch.");
}
*/
void testTemplateConstructor() {
    complex<float> cf{ 1.0f, 2.0f };
    complex<double> cd = cast<double,float>(cf);
    complex<double> cd = cf;

    Assert(cf.real() == cd.real(), "Real parts are different.");
    Assert(cf.imag() == cd.imag(), "Imaginary parts are different.");
}


int main() {
    testTemplateConstructor();
    return 0;
}

