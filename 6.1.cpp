#include <iostream>
using namespace std;
class A
{
public:
    int dataA;
};
class B : public A
{
public:
    int dataB;
};
class C : public A
{
public:
    int dataC;
};
class E : public A, public C
{
public:
    int dataE;
};

class D : public B
{
public:
    int dataD;
};

class F : public D, public E
{
public:
    int dataF;
};
class A_v
{
public:
    int dataA;
};
class B_v : virtual public A_v
{
public:
    int dataB;
};
class C_v : virtual public A_v
{
public:
    int dataC;
};
class E_v : virtual public A_v, virtual public C_v
{
public:
    int dataE;
};
class D_v : public B_v
{
public:
    int dataD;
};
class F_v : public D_v, public E_v
{
public:
    int dataF;
};
int main()
{
    cout << "No virtual inheritance:" << endl;
    cout << "sizeof(A) = " << sizeof(A) << endl;
    cout << "sizeof(B) = " << sizeof(B) << endl;
    cout << "sizeof(C) = " << sizeof(C) << endl;
    cout << "sizeof(E) = " << sizeof(E) << endl;
    cout << "sizeof(D) = " << sizeof(D) << endl;
    cout << "sizeof(F) = " << sizeof(F) << endl;
    cout << "\nVirtual inheritance:" << endl;
    cout << "sizeof(A_v) = " << sizeof(A_v) << endl;
    cout << "sizeof(B_v) = " << sizeof(B_v) << endl;
    cout << "sizeof(C_v) = " << sizeof(C_v) << endl;
    cout << "sizeof(E_v) = " << sizeof(E_v) << endl;
    cout << "sizeof(D_v) = " << sizeof(D_v) << endl;
    cout << "sizeof(F_v) = " << sizeof(F_v) << endl;
    return 0;
}