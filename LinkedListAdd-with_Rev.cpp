#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class List
{
    Node *head;
    public:
    List()
    {
        head=NULL;
    }

    void insert(int x)
    {
        Node *newn = new Node;
        newn->data = x;
        newn->next=NULL;

        if(head == NULL)
            head = newn;
        else
        {
            Node *trav=head;
            while(trav->next!=NULL)
                trav=trav->next;
                
            trav->next=newn;
        }
    }

    void traverse()
    {
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

    List operator + (List L)
    {
        List LNew;
        if(this->head==NULL && L.head==NULL)
            LNew.head=NULL;
    
        if(this->head==NULL)
            LNew.head = L.head;
        
        if(L.head==NULL)
            LNew.head = this->head;

        
        else
        {
            int carry = 0;

            Node *trav1 = this->head;
            Node *trav2 = L.head;
            
            while(trav1!=NULL || trav2!=NULL)
            {
                if(trav1!=NULL && trav2!=NULL)
                {
                    int x = trav1->data + trav2->data + carry;
                    LNew.insert(x%10);
                    carry = x/10;

                    trav1=trav1->next;
                    trav2=trav2->next;
                }
                else if(trav1!=NULL)
                {
                    int x = trav1->data + carry;
                    LNew.insert(x%10);
                    carry = x/10;

                    trav1=trav1->next;
                }
                else if(trav2!=NULL)
                {
                    int x = trav2->data + carry;
                    LNew.insert(x%10);
                    carry = x/10;

                    trav2=trav2->next;
                }
            }

            if(carry == 1)
                LNew.insert(1);
        }
        return LNew;
    }

    void reverse()
    {
        head = recrev(head);

        if(head == NULL)
        {
            cout<<"0";
            return;
        }
            
        Node *trav = head;
        while(trav!=NULL)
        {
            cout<<trav->data;
            trav=trav->next;
        }
    }

    Node *recrev(Node *node) 
    {
        if(node==NULL || node->next==NULL) 
            return node;
        
        Node *ahead = recrev(node->next);
        node->next->next=node;
        node->next=NULL;
        return ahead;
    }
};


main()
{
    
    cout<<"\n\nAddition using LinkedList...Enter Two Numbers to add: \n";

    int num1, num2;   
    cin>>num1>>num2;
    List L1,L2;
    while(num1!=0)
    {
        L1.insert(num1%10);
        num1/=10;
    }
    while(num2!=0)
    {
        L2.insert(num2%10);
        num2/=10;
    }


    List L3 = L1 + L2;

    cout<<"\n\nList-1: ";L1.traverse();
    cout<<"List-2: ";L2.traverse();
    cout<<"List-3: ";L3.traverse();

    cout<<"\nAddition: ";L1.reverse();
    cout<<" + ";L2.reverse();
    cout<<" = ";L3.reverse();
    cout<<"\n\n\n";
}
