/*

            Double linked list
      ----->1. Add at the begining of the list
      ----->2. Add at the end of the list
      ----->3. Add at the random position
      ----->4. Delete at the begining of the list
      ----->5. Delete at the end of the list
      ----->6. Delete at the random position 
      ----->7. printing the list 
      ----->8. counting the number of nodes 
      ----->9. Search the node in the list  
      ---->10. exit 

*/

#include<iostream>
#include<conio.h>
using namespace std;

// defining structure of node of double linked list
struct node
{
      int data;
      node * prev;
      node * next;
};

// function for adding at the beginning of the list 
node * addAtBegin(node * head, int data){

      // creating a node 
      node * ptr = new node;
      ptr->data = data;
      ptr->prev = NULL;
      ptr->next = head;

      head = ptr;
      return head;

}

// function for adding nodes at the end of list 
node * addAtEnd(node * head, int data){

      // creating node 
      node * ptr = new node;
      ptr->data = data;
      ptr->prev = NULL;
      ptr->next = NULL;

      // adding node to the end of the list 

      // checking if head is NULL already
      if (head == NULL)
      {
            head = ptr;
            return head;
      }

      node * temp = head;

      // to find the end of the list       
      while (temp->next != NULL)
      {
            temp = temp->next;
      }
      
      temp->next = ptr;
      ptr->prev = temp;
      
      return head;
}

// function for add at random position 
void addAtRandom(node * head, int data, int pos){

      // checking if the list is already empty 
      if(head == NULL){
            cout<<"The list is empty!"<<endl;
            return;
      }

      // creating a node 
      node * ptr = new node;
      ptr->data = data;
      ptr->next = NULL;
      ptr->prev = NULL;

      // reaching out to that position 
      pos--;
      node * temp = head;

      while (pos != 1)
      {
            pos--;
            temp = temp->next;
      }

      ptr->next = temp->next;
      temp->next = ptr;
      ptr->prev = temp;
      
}

// to delete the first node of list 
node * deleteAtBegin(node * head){

      // checking if the list is empty 
      if (head == NULL)
      {
            cout<<"The list is empty!"<<endl;
            return head;
      }

      // checking if the list has only one node 
      if (head->next == NULL)
      {
            delete head;
            head = NULL;
            return head;
      }
      
      // incrementing head pointer by one 
      head = head->next;
      // freeing the memory of first node by deleting it 
      delete head->prev;
      // setting the prev pointer of first node to NULL
      head->prev = NULL;
      return head;
}

// to delete the end node 
void deleteAtEnd(node * head){
      
      // checking if the list already empty  
      if (head == NULL)
      {
            cout<<"The list is empty!"<<endl;
            return;
      }

      node * temp = head;

      // finding the end of the list 
      while (temp->next != NULL)
      {
            temp = temp->next;
      }
      
      temp->prev->next = NULL;
      delete temp;      
}

// to delete at a random position 
node * deleteAtRandom(node * head, int pos){

      // checking if the list is empty 
      if (head == NULL)
      {
            cout<<"The list is empty! "<<endl;
            return head;
      }

      if (head->next == NULL)
      {
            delete head;
            head = NULL;
            return head;
      }
      
      node * temp = head;

      // reaching out to the node to delete 
      while (pos != 1)
      {
            temp = temp->next;
            pos--;
      }
      
      temp->prev->next = temp->next;

      delete temp;
      
      return head;
}

// to print the list 
void print(node * head){

      // checking if list is empty 
      if (head == NULL)
      {
            cout<<"The list is empty! "<<endl;
            return;
      }

      node * temp = head;

      while (temp != NULL)
      {
            cout<<temp->data<<" ";
            temp = temp->next;
      }
      
      cout<<" <== The list is here "<<endl;   
      
}

// to count the the number of nodes in the list 
void count(node * head){

      // checking if the list is empty 
      if(head == NULL){
            cout<<"The list is empty!"<<endl;
            return;
      }

      // counting the nodes of the linked list 
      node * temp = head;
      int counter = 0;

      while (temp != NULL)
      {
            counter++;
            temp = temp->next;
      }
      
      cout<<"The number of nodes in this list is: "<<counter<<endl;

}

// to search the position of node in the list 
void search(node * head, int val){

      // checking if the node is empty or not 
      if (head == NULL)
      {
            cout<<"The list is empty!"<<endl;
            return;
      }
      
      node * temp = head;
      int pos = 1;

      while (temp != NULL)
      {
            if (temp->data == val)
            {
                  cout<<"The node is at position: "<<pos<<endl;
                  return;
            }
            
            temp = temp->next;
            pos++;
      }
      
      cout<<"The value is not in the list!"<<endl;
}

int main(){
      
      // the head of the list is here 
      node * head = NULL;

      int choice;
      int val;
      int pos;

      while (1)
      {
            cout<<"Enter your choice: "<<endl;
            cin>>choice;

            switch (choice)
            {
            case 1:
                  cout<<"Enter the value: ";
                  cin>>val;
                  head = addAtBegin(head,val);
                  break;
            
            case 2:
                  cout<<"Enter the value: ";
                  cin>>val;
                  cout<<"Enter the position: ";
                  cin>>pos;
                  addAtRandom(head,val,pos);
                  break;

            case 3:
                  cout<<"Enter the value: "<<endl;
                  cin>>val;
                  head = addAtEnd(head,val);
                  break;

            case 4:
                  head = deleteAtBegin(head);
                  break;

            case 5:
                  cout<<"Enter the position: ";
                  cin>>pos;
                  head = deleteAtRandom(head,pos);
                  break;

            case 6:
                  deleteAtEnd(head);
                  break;
            
            case 7:
                  print(head);
                  break;
            
            case 8:
                  count(head);
                  break;

            case 9:
                  cout<<"Enter the value: ";
                  cin>>val;
                  search(head,val);
                  break;

            case 10:
                  cout<<"Exiting the program!"<<endl;
                  exit(0);
                  break;
            default:
                  cout<<"Wrong choice!"<<endl;
                  break;
            }
      }
      

      return 0;
}