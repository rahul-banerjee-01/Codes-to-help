#insert
#trav
#delete

#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

Node* createNode(int val)
{
    Node *newn = (Node *)malloc(sizeof(Node));
    newn->data = val;
    newn->next = NULL;
    return newn;
}

void insertNode()
{
    if(head == NULL)
    {
        cout<<"\n\nList empty, Creating new List...\n\n";
        cout<<"\nEnter value: ";
        int i;
        cin>>i;
        head = createNode(i);
    }
    else
    {
        cout<<"\nEnter target for new Node: ";
        int x;
        cin>>x;

        Node *trav = head;
        while(trav!=NULL)
        {
            if(trav->data == x)
                break;
            trav=trav->next;
        }
            

        if(!trav)
        {
            cout<<"\nTarget not found, try again...";
            getch();
        }
        else
        {
            cout<<"\nEnter value: ";
            int i;
            cin>>i;
            Node *temp = createNode(i);
            temp->next = trav->next;
            trav->next = temp;
        }  
    }
}

void traverse()
{
    cout<<"\nExisting List:\t";
    if(head == NULL)
        cout<<"Empty List\n\n";
    else
    {
        Node *trav = head;
        while(trav->next!=NULL)
        {
            cout<<trav->data<<" -> ";
            trav=trav->next;
        }
        cout<<trav->data<<endl;
    }
}

void deleteNode()
{
    if(head == NULL)
    {
        cout<<"\n\nList empty, Underflow Condition...\n\n";
        getch();
    }

    else
    {
        cout<<"\nEnter value to delete: ";
        int x;
        cin>>x;
        while(head->data == x && head!=NULL)
        {
            if(head->next == NULL)
            {
                head=NULL;
                return;
            }
            else
            {
                Node *temp = head;
                head=head->next;
                delete temp;
            }
        }

        Node *trav = head;
        Node *del = head->next;
        while(del!=NULL)
        {
            if(del->data == x)
            {
                Node *temp = del;
                del=del->next;
                trav->next=del;
                delete temp;
            }
            else
            {
                trav=trav->next;
                del=del->next;
            }
        }
    }


}

main()
{
    while(true)
    {
        system("cls");
        traverse();
        cout<<"\n\t ***Menu*** \n";
    	cout<<"\n\t1.Insert Node";
        cout<<"\n\t2.Delete Node";
    	cout<<"\n\t0.Exit\n\n";

		int i;
		cout<<"Enter your Choice: ";
		cin>>i;
		switch(i)
        {
            case 1:
            {
                insertNode();
                break;
            }

            case 2:
            {
                deleteNode();
                break;
            }

            case 0:
            {
                system("cls");
                exit(0);
            }

            default:
            {
                cout<<"\nInvalid Choice, please try again..."<<endl;
                getch();
                break;
            }
        }
    }
}