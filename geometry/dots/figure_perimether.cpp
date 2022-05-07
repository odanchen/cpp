#include<iostream>
#include<cmath>
#include<iomanip>

using namespace::std;

struct cord
{
    double x;
    double y;
};

double sqr(double num)
{
    return num * num;
}

double distance(cord dot1, cord dot2)
{
    return sqrt(sqr(dot1.x - dot2.x) + sqr(dot1.y - dot2.y));
}

void read_arr(cord arr[], int &len)
{
    cin >> len;
    
    for (int i = 0; i < len; i++)
        cin >> arr[i].x >> arr[i].y;
}

double count_perimether(cord nodes[], int len)
{
    double sum = 0;
    
    for (int i = 0; i < len - 1; i++)
        sum += distance(nodes[i], nodes[i + 1]);
    
    sum += distance(nodes[0], nodes[len - 1]);
    
    return sum;
}

int main()
{
    int len;
    cord nodes[100];
    read_arr(nodes, len);
    
    cout << fixed << setprecision(3) << count_perimether(nodes, len);
}
