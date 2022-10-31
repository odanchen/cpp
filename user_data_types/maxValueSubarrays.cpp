#include <iostream>
#include <stack>

using namespace::std;

struct arrayElement
{
    int value;
    int idx;
};

struct subarray
{
    int leftIdx = -1;
    int rightIdx = -1;
};

bool operator<(arrayElement a, arrayElement b)
{
    if (a.value != b.value) return a.value < b.value;
    return a.idx < b.idx;
}

int main()
{
    stack<arrayElement> monostack;
    int cnt, value;
    cin >> cnt;
    subarray ans[cnt];
    
    for (int i = 0; i < cnt; i++)
    {
        cin >> value;
        arrayElement cur;
        cur.value = value;
        cur.idx = i;
        
        while(not(monostack.empty()) && monostack.top() < cur)
        {
            if(monostack.top().value == cur.value) ans[cur.idx].leftIdx = monostack.top().idx + 1;
            ans[monostack.top().idx].rightIdx = cur.idx;
            monostack.pop();
        }
        
        if (monostack.empty() && ans[cur.idx].leftIdx == -1) ans[cur.idx].leftIdx = 0;
        else if(ans[cur.idx].leftIdx == -1) ans[cur.idx].leftIdx = monostack.top().idx + 1;
        
        monostack.push(cur);
    }
    
    for (int i = 0; i < cnt; i++)
    {
        cout << ans[i].leftIdx + 1 << ' ';
        
        if (ans[i].rightIdx == -1) cout << cnt << '\n';
        else cout << ans[i].rightIdx << '\n';
    }
}
