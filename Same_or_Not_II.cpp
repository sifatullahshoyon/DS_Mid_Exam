#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    // Constructor
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

class MyStack
{
private:
    Node *top = nullptr;
    int size = 0;

public:
    void push(int x)
    {
        Node *newNode = new Node(x);
        newNode->next = top;
        top = newNode;
        size++;
    }

    void pop()
    {
        if (!top)
            return;
        Node *temp = top;
        top = top->next;
        delete temp;
        size--;
    }

    int getTop()
    {
        return top ? top->val : -1;
    }

    bool empty()
    {
        return size == 0;
    }

    int getSize()
    {
        return size;
    }

    ~MyStack()
    {
        while (top)
        {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }
};

class MyQueue
{
private:
    Node *front = nullptr;
    Node *rear = nullptr;
    int size = 0;

public:
    void enqueue(int x)
    {
        Node *newNode = new Node(x);
        if (!rear)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    void dequeue()
    {
        if (!front)
            return;
        Node *temp = front;
        front = front->next;
        if (!front)
            rear = nullptr;
        delete temp;
        size--;
    }

    int getFront()
    {
        return front ? front->val : -1;
    }

    bool empty()
    {
        return size == 0;
    }

    int getSize()
    {
        return size;
    }

    ~MyQueue()
    {
        while (front)
        {
            Node *temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    MyStack st;
    MyQueue qu;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.push(x);
    }

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        qu.enqueue(x);
    }

    if (st.getSize() != qu.getSize())
    {
        cout << "NO\n";
        return 0;
    }

    bool same = true;

    while (!st.empty())
    {
        if (st.getTop() != qu.getFront())
        {
            same = false;
            break;
        }
        st.pop();
        qu.dequeue();
    }

    cout << (same ? "YES" : "NO") << "\n";

    return 0;
}