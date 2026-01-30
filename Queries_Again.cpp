#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *prev;
    Node *next;

    Node(int v) : val(v), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;
    int sz;

public:
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
        sz = 0;
    }

    bool insertAt(int x, int v)
    {

        if (x < 0 || x > sz)
        {
            return false;
        }

        Node *newNode = new Node(v);

        if (x == 0)
        {
            newNode->next = head;
            if (head)
                head->prev = newNode;
            head = newNode;
            if (!tail)
                tail = newNode;
            sz++;
            return true;
        }

        if (x == sz)
        {
            newNode->prev = tail;
            if (tail)
                tail->next = newNode;
            tail = newNode;
            sz++;
            return true;
        }

        Node *curr = head;
        for (int i = 0; i < x; ++i)
        {
            curr = curr->next;
        }

        newNode->prev = curr->prev;
        newNode->next = curr;
        curr->prev->next = newNode;
        curr->prev = newNode;

        sz++;
        return true;
    }

    void printForward()
    {
        cout << "L ->";
        Node *curr = head;
        while (curr)
        {
            cout << " " << curr->val;
            curr = curr->next;
        }
        cout << "\n";
    }

    void printBackward()
    {
        cout << "R ->";
        Node *curr = tail;
        while (curr)
        {
            cout << " " << curr->val;
            curr = curr->prev;
        }
        cout << "\n";
    }

    ~DoublyLinkedList()
    {
        Node *curr = head;
        while (curr)
        {
            Node *temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    cin >> Q;

    DoublyLinkedList dll;

    while (Q--)
    {
        int X, V;
        cin >> X >> V;

        if (!dll.insertAt(X, V))
        {
            cout << "Invalid\n";
        }
        else
        {
            dll.printForward();
            dll.printBackward();
        }
    }

    return 0;
}