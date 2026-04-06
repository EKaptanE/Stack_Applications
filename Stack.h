#ifndef STACK
#define STACK
#include <stdexcept>
using namespace std;

template <typename Temp>
class Stack{
    private:
        Temp* stackArr;
        int capacity;
        int topIndex;
    public:
        Stack(int cap = 100): capacity(cap){
            stackArr = new Temp[capacity];
            topIndex = -1;
        }
        ~Stack(){
            delete[] stackArr;
        }

        bool isEmpty() const {return topIndex == -1;}
        bool isFull() const {return topIndex == capacity - 1;}

        void push(Temp value){
            if(isFull()){
                throw overflow_error("Stack Overflow");
            }
            stackArr[++topIndex] = value;
        }

        Temp top(){
            if(isEmpty()){
                throw out_of_range("Stack Empty");
            }
            return stackArr[topIndex];
        }

        void pop(){
            if(isEmpty()){
                throw out_of_range("Stack Underflow");
            }
            topIndex--;
        }
};
#endif