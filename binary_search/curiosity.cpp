#include<iostream>

using namespace::std;

int count_details(int speed1, int speed2, int time)
{
    int details;
    details = 1 + (time - min(speed1, speed2)) / speed1 + (time - min(speed1, speed2)) / speed2;
    return details;
}

int count_time(int goal, int speed1, int speed2)
{
    int mid = 1, left = 1, right = 1;
    
    while (count_details(speed1, speed2, right) <= goal)
        right *= 2;
    
    while(left < right || count_details(speed1, speed2, mid) == goal)
    {
        mid = (left + right) / 2;
        
        if (count_details(speed1, speed2, mid) >= goal && count_details(speed1, speed2, mid - 1) < goal)
            return mid;
        if (count_details(speed1, speed2, left) >= goal) return left;
        if (count_details(speed1, speed2, mid) == goal)
        {
            while (count_details(speed1, speed2, mid) == goal) mid--;
            return mid + 1;
        }
        if (count_details(speed1, speed2, right) == goal)
        {
            while (count_details(speed1, speed2, right) == goal) right--;
            return right + 1;
        }
        
        if (count_details(speed1, speed2, mid) > goal) right = mid - 1;
        else if (count_details(speed1, speed2, mid) < goal) left = mid + 1;
    }
    
    if (count_details(speed1, speed2, left) >= goal && count_details(speed1, speed2, left - 1) < goal) return left;
    if (count_details(speed1, speed2, mid) >= goal && count_details(speed1, speed2, mid - 1) < goal) return mid;
    return right;
}

int main()
{
    int goal, speed1, speed2;
    cin >> goal >> speed1 >> speed2;
    
    cout << count_time(goal, speed1, speed2);
}
