#include <iostream>
#include <cassert>

#define value 4


using namespace std;

class Stack {

private:

    int cnt; //top of stack/(counter)
    int size;
public:
    int* sp; //pointer
    Stack(int a);
    Stack();
    Stack(const Stack &cc);
    ~Stack();
    void Push(int a);
    int Pop();

};

Stack::Stack(const Stack &cc)
{
    int i;
    size = cc.size;
    cnt = cc.cnt;
    sp = new int[cc.size];
    for(i=0; i<cc.size; i++)
    {
        sp[i]= cc.sp[i];
    }
}


Stack::Stack(int a)
{
    cnt = a;
    sp = new int[a];
    size = 0;
}

Stack::Stack(): cnt(value)
{
        sp = new int[cnt];
        size = 0;
}


Stack::~Stack()
{
    delete []sp;
}

void Stack::Push(int a)
{
    assert((cnt > size )&& "stack is full" );
    sp[size++] = a;
}

int Stack::Pop()
{
    assert((size > 0)&& "stack is empty");
    return(sp[--size]);
}

int main()
{
    int i;
    Stack a(3);
    a.Push(1);
    a.Push(2);
    a.Push(3);

    Stack b= a;
    cout << "Elements of b: "<< endl;
    for( i = 0; i< 3; i++)
        cout << b.sp[i]<< endl;
    a.Pop();
    a.Push(9000);

    cout << "Elements of a after changes in a: "<< endl;
    for( i = 0; i< 3; i++)
        cout << a.sp[i]<< endl;

    cout << "Elements of b after changes in a: "<< endl;
    for( i = 0; i< 3; i++)
        cout << b.sp[i]<< endl;
    return 0;
}
