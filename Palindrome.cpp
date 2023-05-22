#include<bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    Node *next;
};

class List
{
    public:
    Node *head;
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
            while(trav!=NULL)
            {
                cout<<trav->data;
                trav=trav->next;
            }
        }
        cout<<"\n";
    }

    List reverse()
    {
        List L;
        if(head == NULL)
            L.head = NULL;
        else
        {
            Node *trav = head;
            while(trav!=NULL)
            {
                L.insert(trav->data);
                trav=trav->next;
            }
        }
        L.head= recrev(L.head);

        return L;
        
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

    bool compare(List L)
    {
        bool flag = true;

        Node *trav1 = this->head;
        Node *trav2 = L.head;
            
        while(trav1!=NULL || trav2!=NULL)
        {
            if(trav1->data != trav2->data)
                flag=0;
            
            trav1=trav1->next;
            trav2=trav2->next;
        }
        return flag;
    }
};


main()
{
    
    cout<<"\n\nPalindrome Check...Enter String: \n";
    string str;
    cin>>str;  
    List L1,L2;
    for(int i=0; i<str.length(); i++)
    {
        L1.insert(str[i]);
    }
    
    L2 = L1.reverse();


    if(L1.compare(L2))
        cout<<"Palindrome String !!";
    else    
        cout<<"Not Palindrome !!";
    cout<<"\n\n\n";
}
