#include <iostream>
#include <string>
using namespace std;
class Human
{
protected:
    string name;
    int age;
public:
    Human(const string& n = "", int a = 0) : name(n), age(a) {}
    virtual ~Human() {}
    friend istream& operator>>(istream& in, Human& h)
     {
        cout << "Input name: ";
        getline(in, h.name);
        cout << "Input age: ";
        in >> h.age;
        in.ignore();
        return in;
    }
    friend ostream& operator<<(ostream& out, const Human& h)
    {
        out << "Name: " << h.name << "\nAge: " << h.age;
        return out;
    }
};
class Father : virtual public Human
{
protected:
    string job1;
public:
    Father(const string& n = "", int a = 0, const string& j = "")
        : Human(n, a), job1(j) {}
    virtual ~Father() {}
    friend istream& operator>>(istream& in, Father& f)
    {
        in >> static_cast<Human&>(f);
        cout << "Input father's job: ";
        getline (in, f.job1);
        return in;
    }
    friend ostream& operator<<(ostream& out, const Father& f)
    {
        out << static_cast<const Human&>(f);
        out << "\nFather's job: " << f.job1;
        return out;
    }
};
class Mother : virtual public Human
{
protected:
    string job2;
public:
    Mother(const string& n = "", int a = 0, const string& h = "")
        : Human(n, a), job2(h) {}
    virtual ~Mother() {}
    friend istream& operator>>(istream& in, Mother& m)
    {
        in >> static_cast<Human&>(m);
        cout << "Input mother's job: ";
        getline (in, m.job2);
        return in;
    }
    friend ostream& operator<<(ostream& out, const Mother& m)
    {
        out << static_cast<const Human&>(m);
        out << "\nMother's job: " << m.job2;
        return out;
    }
};
class Son : public Father, public Mother
{
private:
    string school;
public:
    Son(const string& n = "", int a = 0, const string& j = "", const string& h = "", const string& s = "")
        : Human(n, a), Father(n, a, j), Mother(n, a, h), school(s) {}
    virtual ~Son() {}
    friend istream& operator>>(istream& in, Son& s)
    {
        in >> static_cast<Human&>(s);
        cout << "Input father's job: ";
        getline (in, s.job1);
        cout << "Input mother's job: ";
        getline (in, s.job2);
        cout << "Input son's school: ";
        getline (in, s.school);
        return in;
    }
    friend ostream& operator<<(ostream& out, const Son& s)
    {
        out << static_cast<const Human&>(s);
        out << "\nFather's job: " << s.job1;
        out << "\nMother's job: " << s.job2;
        out << "\nSon's school: " << s.school;
        return out;
    }
};
int main()
{
    Son s;
    cin >> s;
    cout << "Info about son:\n";
    cout << s << endl;
    return 0;
}