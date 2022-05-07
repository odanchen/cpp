#include<iostream>
#include<cmath>

using namespace::std;

struct cord
{
    double x;
    double y;
};

int main()
{
    cord dot, ldot1, ldot2;
    double k, b;
    
    
    cin >> dot.x >> dot.y >> ldot1.x >> ldot1.y >> ldot2.x >> ldot2.y;
    
    if (ldot2.x == ldot1.x)
    {
        if (dot.x == ldot2.x)
        {
            cout << "YES" << '\n';
            if ((ldot1.y < ldot2.y && dot.y >= ldot1.y) || (ldot1.y > ldot2.y && dot.y <= ldot1.y))
            {
                cout << "YES" << '\n';
                if (dot.y <= max(ldot2.y, ldot1.y) && dot.y >= min(ldot2.y, ldot1.y)) cout << "YES";
                else cout << "NO" << '\n';
            }
            else cout << "NO" << '\n' << "NO" << '\n';
        }
        else cout << "NO" << '\n' << "NO" << '\n' << "NO" << '\n';
    }
    else
    {
        k = ((ldot1.y - ldot2.y) / (ldot1.x - ldot2.x));
        b = ldot1.y - ldot1.x * k;
        
        if (k == 0)
        {
            if (dot.y == b)
            {
                cout << "YES" << '\n';
                if ((ldot1.x < ldot2.x && dot.x >= ldot1.x) || (ldot1.x > ldot2.x && dot.x <= ldot1.x))
                {
                    cout << "YES" << '\n';
                    if (dot.x <= max(ldot2.x, ldot1.x) && dot.x >= min(ldot2.x, ldot1.x)) cout << "YES";
                    else cout << "NO" << '\n';
                }
                else cout << "NO" << '\n' << "NO" << '\n';
            }
            else cout << "NO" << '\n' << "NO" << '\n' << "NO" << '\n';
        }
        else
        {
            if (dot.x == (dot.y - b) / k)
            {
                cout << "YES" << '\n';
                if ((ldot1.x < ldot2.x && dot.x >= ldot1.x) || (ldot1.x > ldot2.x && dot.x <= ldot1.x))
                {
                    cout << "YES" << '\n';
                    if (dot.x <= max(ldot2.x, ldot1.x) && dot.x >= min(ldot2.x, ldot1.x)) cout << "YES";
                    else cout << "NO" << '\n';
                }
                else cout << "NO" << '\n' << "NO" << '\n';
            }
            else cout << "NO" << '\n' << "NO" << '\n' << "NO" << '\n';
        }
    }
}
