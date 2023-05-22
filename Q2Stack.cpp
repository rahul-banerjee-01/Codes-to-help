#include <bits/stdc++.h>
 
using namespace std;
 
class Stack {
    // Two inbuilt queues
    queue<int> q1, q2;
 
public:
    void push(int x)
    {
        // Push x first in empty q2
        q2.push(x);
 
        // Push all the remaining
        // elements in q1 to q2.
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
 
        // swap the names of two queues
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }
 
    void pop()
    {
        // if no elements are there in q1
        if (q1.empty())
        {
            cout<<"Underflow...\n";
            return;
        }
        q1.pop();
    }
 
    int top()
    {
        if (q1.empty())
        {
            cout<<"Underflow...\n";
            return -1;
        }
        return q1.front();
    }
 
    int size() { return q1.size(); }
};
 
// Driver code
int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
 
    cout << "Current size: " << s.size() << endl;
    cout << s.top() << endl;
    s.pop();
    s.pop();
    cout << "Current size: " << s.size() << endl;
    s.pop();
    cout << s.top() << endl;
    s.push(2);
    cout << "Current size: " << s.size() << endl;
    s.push(3);
    cout << s.top() << endl;
    s.pop();
    s.pop();
    cout << "Current size: " << s.size() << endl;
    cout << s.top() << endl;
    return 0;
}