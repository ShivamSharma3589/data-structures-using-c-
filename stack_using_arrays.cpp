#include <iostream>
#include <conio.h>
using namespace std;

class stack
{

      int *arr;         //pointer for holding arrays
      int size;         //to declare the size of the array
      int pointer = -1; //stack pointer

public:
      // default constructor
      stack()
      {
            size = 5;            //declaring default size
            arr = new int[size]; //creating array
      }

      // parameterized contructor
      stack(int size)
      {
            this->size = size;   //declaring size at obj creation
            arr = new int[size]; //creating array
      }

      // push function
      void push()
      {

            // in case if stack is full
            if (pointer == size - 1)
            {
                  cout << "The stack is full" << endl;
                  return;
            }

            // asking user to enter the value
            cout << "Enter the value: " << endl;
            cin >> arr[++pointer];                             //increasing the pointer by 1 & getting the value in it
            cout << "Value entered: " << arr[pointer] << endl; //displaying the value was entered
      }

      // pop function
      void pop()
      {
            // in case stack is empty
            if (pointer == -1)
            {
                  cout << "The stack is empty!" << endl;
                  return;
            }

            // popping out the value from the stack and decreasing the pointer by 1
            cout << arr[pointer--] << " is poped out of the stack" << endl;
      }

      // to display all the elements present in stack
      void display()
      {
            //checking if stack is empty
            if (pointer == -1)
            {
                  cout << "The stack is empty!" << endl;
                  return;
            }

            // printing all the elements present in array
            for (int i = 0; i <= pointer; i++)
            {
                  cout << arr[i] << " ";
            }
            cout << endl;
      }

      // checking stack is full or not function
      void isFull()
      {
            // checking if stack is full or not
            if (pointer == size - 1)
            {
                  cout << "The stack  is not full." << endl;
                  return;
            }

            //printing if stack is not full
            cout << "The stack is not full." << endl;
      }

      // checking if stack is empty or not
      void isEmpty()
      {
            // checking if stack is empty
            if (pointer == -1)
            {
                  cout << "The stack is empty!!!" << endl;
                  return;
            }

            //printing if stack is not empty
            cout << "The stack is not empty." << endl;
      }

      // counting number of elements
      void count()
      {
            // checking if stack is empty
            if (pointer == -1)
            {
                  cout << "The stack is empty!!!" << endl;
                  return;
            }

            // printing the number of counts
            cout << "The number of elements are " << pointer + 1 << " in the stack." << endl;
      }

      //to show the topmost value of the stack
      void top()
      {
            //checking if the stack is empty
            if (pointer == -1)
            {
                  cout << "The stack is empty!" << endl;
                  return;
            }

            // printing the topmost value of stack
            cout << "The top value is: " << arr[pointer] << endl;
      }
};

int main()
{
      stack obj;              //creating object with default constructor
      // stack obj(10);       //creating object with parameterized constructor

      int choice;             //to get the choice from user 

      while (choice != 4)     //running the while loop
      {

            cout << "Enter the choice: " << endl;
            cin >> choice;

            switch (choice)
            {
            case 1:
                  //to insert the value 
                  obj.push();
                  break;
            case 2:
                  //to remove the value 
                  obj.pop();
                  break;
            case 3:
                  //to display the value 
                  obj.display();
                  break;
            case 4:
                  //to exiting the main function
                  cout << "Exiting..." << endl;
                  break;
            case 5:
                  //to check if stack is full or not 
                  obj.isFull();
                  break;
            case 6:
                  //to count the number of elements
                  obj.count();
                  break;
            case 7:
                  //to check if stack is empty
                  obj.isEmpty();
                  break;
            case 8:
                  //to check the value of top pointer 
                  obj.top();
                  break;
            default:
                  cout << "Wrong choice!!!" << endl;
            }
      }

      return 0;
}