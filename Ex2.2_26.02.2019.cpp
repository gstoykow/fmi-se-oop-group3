#include <iostream>

using namespace std;

//structure members are public by default
struct A
{
    int a;
};

//class members are private by defalut
class B
{
    //private members can be reached only from inside of the class
    private:

    int d = 6;
    int c;

    //public members can be reached from everywhere in the code
    public:

    //- writing const after the argument brackets tells the compiler to throw an
    //error if some of the classes data members are modified
    //- get functions are typically used for accessing the private data members of a class
    int getD()const
    {
        return d;
    }

    //- set functions provide a safe way for changing private data member of a class
    //- logic -> set
    void setD(int d)
    {
        if(d > 0)
        {
            this->d = d;
        }
    }

    //getter
    int getC()const
    {
        return c;
    }

    //setter
    void setC(int c)
    {
        if(c > 0)
        {
            this->c = c;
        }
    }

    //setting data member values is logical only through the setters
    B(int b, int c)
    {
        setB(b);
        setC(c);
    }


};

//accessing public members is possible everywhere in the code
void foo()
{
    A i2;
    i2.a = 6;
}

int main()
{

    cin.get();
    return 0;
}

