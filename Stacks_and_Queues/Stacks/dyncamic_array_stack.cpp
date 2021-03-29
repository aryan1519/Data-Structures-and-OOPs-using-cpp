// Only slight changes in Constructor ,the push function and removing input given while creating object .

#include <iostream>
#include <climits>

using namespace std;

class Stack
{
private:
  int *array;     //dynamic since we dont know the size yet
  int nextIndex;
  int capacity;   //total size of the stack

public:

  //Constructor
  Stack()
  {
    capacity = 4;   // Giving it a random initial size. If filled a new array must be formed of double the capacity.
    nextIndex = 0;
    array = new int[4];
  }

  //
  // Function that gives the current size of the stack
  int size()
  {
    return nextIndex;
  }

  // Function to check if the stack is empty or not
  bool Empty()
  {
    return nextIndex == 0;
  }

  //  Function to insert elements into the stack
    void push(int element)
    {
        if(nextIndex == capacity)
          {
            int *newArray = new int[2*capacity]; // Creating a new array of double the capacity.

            //Now copying the data of old array into new newArray

            for(int i=0;i<capacity;i++)
            {
              newArray[i] = array[i];
            }

            //Updating the value of capacity variable
            capacity*=2;

            //Deleting the old array
            delete [] array;

            //Now making array pointer point to newArray
            array = newArray;

          }

        array[nextIndex] = element;
        nextIndex++;
    }
    //  Function to delete elements from stack. Type int so as to even return the element deleted.
     int pop()
     {
       if(Empty())
          {
            cout<<"The stack is empty"<<endl;
            return INT_MIN; // Since this is an int type function we need to return something so we return INT_MIN
          }

       nextIndex--; //We go to the last element of the stack now any next element inserted will overwrite this.
       return array[nextIndex];

     }

     // To return the last element/ topmost element of the Stack
     int top()
     {
       if(Empty())
          {
            cout<<"The stack is empty"<<endl;
            return INT_MIN; // Since this is an int type function we need to return something so we return INT_MIN
          }

       return array[nextIndex-1];
     }
};
///////////////////////////////////////////////////////////////////////////
///Testing the stack class in main
int main()
{
Stack s;

s.push(10);
s.push(20);
s.push(30);
s.push(40);
s.push(50);  

cout<<s.top()<<endl;

cout<<s.pop()<<endl;
cout<<s.pop()<<endl;
cout<<s.pop()<<endl;

cout<<s.size()<<endl;

cout<<s.Empty()<<endl;


  return 0;
}
