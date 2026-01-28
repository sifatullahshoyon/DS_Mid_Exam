#include <bits/stdc++.h>
using namespace std;

int main() 
{  
    int n, m;
    cin >> n >> m;
    
    stack<int> st;
    queue<int> qu;
    
  
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        st.push(x);
    }
    
    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        qu.push(x);
    }
    
    if(n != m) {
        cout << "NO" << endl;
        return 0;
    }
    
   
    bool flag = false;
    
    while(!st.empty()) {
        if(st.top() != qu.front()) {
            flag = true;
            break;
        }
        st.pop();
        qu.pop();
    }
    
    cout << (!flag ? "YES" : "NO") << endl;
    
    return 0;
}