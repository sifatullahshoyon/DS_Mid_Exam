#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<string> history;
    string addr;
    while (cin >> addr)
    {
        if (addr == "end")
            break;
        history.push_back(addr);
    }

    int Q;
    cin >> Q;

    auto it = history.begin();

    while (Q--)
    {
        string command;
        cin >> command;

        if (command == "visit")
        {
            string target;
            cin >> target;

            auto found = find(history.begin(), history.end(), target);

            if (found != history.end())
            {
                it = found;
                cout << *it << "\n";
            }
            else
            {
                cout << "Not Available\n";
            }
        }
        else if (command == "next")
        {
            if (it != history.end() && next(it) != history.end())
            {
                ++it;
                cout << *it << "\n";
            }
            else
            {
                cout << "Not Available\n";
            }
        }
        else if (command == "prev")
        {
            if (it != history.begin())
            {
                --it;
                cout << *it << "\n";
            }
            else
            {
                cout << "Not Available\n";
            }
        }
    }
    return 0;
}