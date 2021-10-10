/*

            single linked list
        --->1. Add at the begining of the list
        --->2. Add at the end of the list
        --->3. Add at the random position
        --->4. Delete at the begining of the list
        --->5. Delete at the end of the list
        --->6. Delete at the random position 
        --->7. printing the list 
        --->8. counting the number of nodes 
        --->9. exit 
        -->10. Search the node in the list  

*/

#include <iostream>
#include <conio.h>
using namespace std;

// defining the structure for nodes
struct node
{
    int data;
    node *link;
};

// add at begining function goes here
void addAtBegin(node **head, int data)
{
    node *ptr = new node;
    ptr->data = data;
    ptr->link = *head;

    *head = ptr;
}

// add at certain position
node *addAtCertain(node *head, int data, int pos)
{
    node *ptr = new node;
    ptr->data = data;
    ptr->link = NULL;

    node *temp = head;

    pos--;

    while (pos != 1)
    {
        temp = temp->link;
        pos--;
    }

    ptr->link = temp->link;
    temp->link = ptr;

    return head;
}

// add at the end of list function
void addAtEnd(node *head, int data)
{
    node *ptr = new node;
    ptr->data = data;
    ptr->link = NULL;

    node *temp = head;

    while (temp->link != NULL)
    {
        temp = temp->link;
    }

    temp->link = ptr;
}

// to delete the node from the beginning 
node * deleteAtBegin(node * head){
    if (head == NULL)
    {
        cout<<"The list is empty! "<<endl;
        return head;
    }

    node * temp = head;

    head = head->link;

    delete temp;
    temp = NULL;

    return head;
    
}

// delete from the random position 
void deleteAtRandom(node * head, int pos){
    if (head == NULL)
    {
        cout<<"The list is empty!"<<endl;
    }
    
    node * temp = head;
    node * temp1 = head;

    while (pos != 1)
    {
        temp1 = temp;
        temp = temp->link;
        pos--;
    }
    
    temp1->link = temp->link;

    delete temp;

}

// delete node from the end 
void deleteAtEnd(node * head){
    if (head == NULL)
    {
        cout<<"The list is empty!"<<endl;
    }

    node * temp = head;
    node * temp1 = head;

    while (temp->link != NULL)
    {
        temp1 = temp;
        temp = temp->link;
    }
    
    temp1->link = NULL;

    delete temp;

}

// to print the entire list
void print(node *head)
{
    if (head == NULL)
    {
        cout << "The list is empty!" << endl;
        return;
    }
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << ' ';
        temp = temp->link;
    }
    cout << "\nThe list is here!" << endl;
}

// to count the number of nodes
void count(node *head)
{
    if (head == NULL)
    {
        cout << "The list is empty! " << endl;
        return;
    }

    int count = 0;
    node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->link;
    }
    cout << "The number of nodes are here = " << count << endl;
}

// to search the node in the list 
void search(node * head, int value){
    if(head == NULL){
        cout<<"The list is empty! "<<endl;
        return;
    }

    node * ptr = head;

    int pos = -1;

    while (ptr != NULL)
    {
        pos++;
        if (ptr->data == value)
        {
            cout<<"The item found at position "<<++pos<<endl;
            return;
        }else
        {
            ptr = ptr->link;
        }
    }

    cout<<"The item has not found in the list! "<<endl;
    
}

// main function called here
int main()
{

    node * head = NULL;

    int choice;
    int val;
    int pos;

    while (1)
    {
        cout<<"Enter your choice ==> ";
        cin>>choice;
        
        switch (choice)
        {
        case 1:
            cout<<"Enter the value ==> ";
            cin>>val;
            addAtBegin(&head,val);
            break;
        case 2:
            cout<<"Enter the value ==> ";
            cin>>val;
            cout<<"Enter the position ==> ";
            cin>>pos;
            head = addAtCertain(head, val, pos);
            break;
        case 3:
            cout<<"Enter the value ==> ";
            cin>>val;
            addAtEnd(head, val);
            break;
        case 4:
            head = deleteAtBegin(head);
            break;
        case 5:
            cout<<"Enter the position ==> "<<endl;
            cin>>pos;
            deleteAtRandom(head, pos);
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
            cout<<"Enter the value to search position ==> ";
            cin>>val;
            search(head, val);
            break;
        case 10:
            cout<<"System exit!"<<endl;
            exit(0);
            break;
        
        default:
            cout<<"Wrong choice! "<<endl;
            break;
        }
    }

    getch();
    return 0;
}