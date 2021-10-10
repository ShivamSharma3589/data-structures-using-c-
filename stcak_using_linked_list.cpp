#include <iostream>
#include <conio.h>
using namespace std;

class stack
{
      int data;
      stack *link;

public:
      void push(stack **head, int data)
      {
            stack *ptr = new stack;
            if (ptr == NULL)
            {
                  cout << "The stack is full" << endl;
                  return;
            }

            ptr->data = data;

            if (*head == NULL)
            {
                  ptr->link = NULL;
                  *head = ptr;
            }
            else
            {
                  ptr->link = *head;
                  *head = ptr;
            }

            cout << ptr->data << " is inserted." << endl;
      }

      void pop(stack **head)
      {
            if (*head == NULL)
            {
                  cout << "The stack is empty!" << endl;
                  return;
            }

            stack *temp = *head;

            *head = (*head)->link;

            cout << temp->data << " is poped out of the stack." << endl;

            delete temp;
      }

      void display(stack *head)
      {
            if (head == NULL)
            {
                  cout << "The stack is empty!" << endl;
                  return;
            }

            while (head != NULL)
            {
                  cout << head->data << " ";
                  head = head->link;
            }
            cout << endl;
      }

      void count(stack *head)
      {
            int counter = 0;

            while (head != NULL)
            {
                  counter++;
                  head = head->link;
            }

            cout << "The number of nodes in the stack: " << counter << endl;
      }

      void top(stack *head)
      {
            if (head == NULL)
            {
                  cout << "The stack is empty!" << endl;
                  return;
            }

            cout << "The top value: " << head->data << endl;
      }

      void isEmpty(stack *head)
      {
            if (head == NULL)
            {
                  cout << "Stack is empty!" << endl;
                  return;
            }

            cout << "The stack is not empty." << endl;
      }

      void isFull()
      {

            stack *temp = new stack;

            if (temp == NULL)
            {
                  cout << "The stack is full!" << endl;
                  return;
            }

            delete temp;
            temp = NULL;

            cout << "The stack is not full." << endl;
      }
};

int main()
{

      stack *head = NULL;

      int value;
      int choice = 0;

      while (choice != 8)
      {
            cout << "Enter the choice: " << endl;
            cin >> choice;

            switch (choice)
            {
            case 1:
                  cout << "Enter the value: " << endl;
                  cin >> value;
                  head->push(&head, value);
                  break;
            case 2:
                  head->pop(&head);
                  break;
            case 3:
                  head->display(head);
                  break;
            case 4:
                  head->top(head);
                  break;
            case 5:
                  head->isFull();
                  break;
            case 6:
                  head->isEmpty(head);
                  break;
            case 7:
                  head->count(head);
                  break;
            case 8:
                  cout << "Exiting..." << endl;

            default:
                  cout << "Wrong choice!!!" << endl;
                  break;
            }
      }

      return 0;
}