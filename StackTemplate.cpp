#include <iostream>
#include <cassert>

using namespace std;

template <typename T>
class Stack
{
    private:
        T *sp; //pointer
        int size;
        T cnt; //counter
    public:
        Stack(int s);
        ~Stack();
        void push(const T );
        T pop();
        void printStack();
};


#define TYPE int
int main()
{
    int n, i ;
    cin >> n;
    Stack<int> S(n);
    for(i=1; i<=n; i++)
    {
        TYPE tmp;
        cin >> tmp;
        S.push(tmp);
    }
    for(i=1; i<=n; i++)
    {
        cout << "pop "<< S.pop()<< endl;
    }
    S.~Stack();
    return 0;
}



//конструктор
template <typename T>
Stack<T>::Stack(int a)
{
    cnt = a;
    sp = new T[a];
    size = 0;

};

//деструктор
template <typename T>
Stack<T>::~Stack()
{
    delete []sp;
    //cnt = poison;
};


template <typename T>
void Stack<T>::push(T value)
{
    assert((cnt > size)&& "stack is full" );
    sp[size++] = value;
};


template <typename T>
T Stack<T>::pop()
{
    assert((size > 0)&& "stack is empty");
    return(sp[--size]);
};

template <typename T>
void Stack<T>::printStack()
{
    for (int i= size; i>=0; i--)
        cout << sp[i] << endl;
};

