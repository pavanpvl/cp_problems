#include <iostream>
#include <array>
#include <cassert>
/*
The class should be named Stack, and should contain:
* A private fixed array of integers of length 10.
* A private integer to keep track of the size of the stack.
* A public member function named reset() that sets the size to 0.
* A public member function named push() that pushes a value on the stack. push() should return false if the array is already full, and true otherwise.
* A public member function named pop() that pops a value off the stack and returns it. If there are no values on the stack, the code should exit via an assert.
* A public member function named print() that prints all the values in the stack.
*/
const int m_max = 10;
class Stack
{
private:
    //constexpr int m_max=10;
    std::array<int, m_max> a;
    int m_size;
public:
    void reset()
    {
        m_size = 0;
    }
    bool push(int val)
    {
        if (m_size == m_max)
            return false;
        else
        {
            a[m_size] = val;
            ++m_size;
            return true;
        }
    }
    int pop()
    {
        if (m_size == 0)
            return -1;
        else
        {
            return a[--m_size];
        }
    }
    void print()
    {
        std::cout<<"( ";
        for(int i=0;i<m_size;i++) std::cout<<a[i]<<" ";
        std::cout<<" )\n";
    }
};
int main()
{
	Stack stack;
	stack.reset();
 
	stack.print();
 
	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();
 
	stack.pop();
	stack.print();
 
	stack.pop();
	stack.pop();
 
	stack.print();
 
	return 0;
}
