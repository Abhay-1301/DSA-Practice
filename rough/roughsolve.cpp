#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack <int > st;
    queue <int > q;
    vector <int> arr;
    for(int i = 0;i<5;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    for(auto it = arr.begin();it!=arr.end();it++){
        cout<<*(it);
    }
    cout<<endl;
    sort(arr.begin(),arr.end());
    for(auto it = arr.begin();it!=arr.end();it++){
        cout<<*(it);
    }
    cout<<endl;
   reverse(arr.begin(),arr.end());
   for(auto it = arr.begin();it!=arr.end();it++){
        cout<<*(it);
    }
    cout<<endl;
    return 0;
}