#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int MAX = 10001;
pair<char, char> node[MAX];

void first(char cur){
    if(cur=='.')
       return;
       
       cout<<cur;
    first(node[cur-'A'].first);
    first(node[cur-'A'].second);
}
void second(char cur){
    if(cur=='.')
        return;

    second(node[cur-'A'].first);
    cout<<cur;
    second(node[cur-'A'].second);
}
void third(char cur){
    if(cur=='.')
    return;

    third(node[cur-'A'].first);
    third(node[cur-'A'].second);
    cout<<cur;
    
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
        
    int n;
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        char p, l, r;
        cin >> p >> l >> r;
        node[p-'A'].first = l;
        node[p-'A'].second = r;
    }
    
    first('A');
    cout << '\n';
    second('A');
    cout << '\n';
    third('A');
    cout << '\n';
    
}
