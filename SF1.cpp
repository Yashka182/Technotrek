#include <iostream>
#include <cassert>

#define value 4


using namespace std;

class Stack {

private:
    int* sp; //pointer
    int cnt; //top of stack/(counter)
    int size;
public:
    Stack(int a);
    Stack();
    ~Stack();
    void Push(int a);
    int Pop();
    void printStack();

};

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

void Stack::printStack()
{
    for(int i=size-1; i>=0; i--)
        cout << sp[i]<< endl;
}    

int main()
{
    int n, i, v;
    cin >> n;
    Stack s(n);
    for(i = 1; i <= n; i++)
    {
        cin >> v;
        s.Push(v);
    }

    cout << "Top of the stack " << s.Pop() << endl;

    s.~Stack();
    return 0;
}
