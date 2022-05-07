#include<iostream>
#include<cmath>
#include<iomanip>

using namespace::std;

struct cord
{
    double x;
    double y;
};

void read_arr(cord arr[], int &len)
{
    cin >> len;
    
    for(int i = 0; i < len; i++)
        cin >> arr[i].x >> arr[i].y;
}

double find_space(cord figure[], int len)
{
    double space = 0;
    
    for  (int i = 0 ; i < len - 1; i++)
        space += ((figure[i + 1].x - figure[i].x) * (figure[i + 1].y + figure[i].y)) / 2;
    
    space += ((figure[0].x - figure[len - 1].x) * (figure[0].y + figure[len - 1].y)) / 2;
    return fabs(space);
}

int main()
{
    cord figure[50000];
    int len;
    
    read_arr(figure, len);
    cout << fixed << setprecision(3) << find_space(figure, len);
}
