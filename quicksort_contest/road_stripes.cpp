#include<iostream>

using namespace::std;

struct point_t {
    int start;
    int finish;
};

int compare(point_t a, point_t b)
{
    return a.start > b.start;
}

void quicksort(point_t bus[], int left, int right)
{
    int i = left, j = right;
    point_t etalon;
    etalon = bus[(left + right) / 2];
    while(i < j)
    {
            while (compare(etalon, bus[i])) i++;
            while (compare(bus[j], etalon)) j--;
        if (i <= j)
        {
            swap(bus[i], bus[j]);
            i++;
            j--;
        }
    }
    if(left < j) quicksort(bus, left, j);
    if(i < right) quicksort(bus, i, right);
}

void read_arr(point_t arr[], int &length, int &plan) {
    int a, b;
    cin >> length;
    for (int i=0; i < length; i++) {
        cin >> a;
        cin >> b;
        arr[i].start = min(a, b);
        arr[i].finish = max(a, b);
    }
    cin >> plan;
}

void merge(point_t arr[], int &length, point_t ans_arr[], int &ans_length)
{
    ans_length = 0;
    int start = arr[0].start;
    int finish = arr[0].finish;
    
    for (int i = 1; i < length - 1; i++)
    {
        if (finish >= arr[i].start)
        {
            finish = max(arr[i].finish, finish);
        }
        else{
            ans_arr[ans_length].start = start;
            ans_arr[ans_length].finish = finish;
            ans_length++;
            start = arr[i].start;
            finish = arr[i].finish;
        }
    }
    ans_arr[ans_length].start = start;
    ans_arr[ans_length].finish = finish;
    ans_length++;
}

int count_length(point_t arr[], int length)
{
    int sum = 0;
    for (int i = 0; i < length; i++)
        sum += (arr[i].finish - arr[i].start);
    return sum;
}

int __main() {
    point_t sectors[1000000], merged_sectors[1000000];
    int length, plan, merged_length;
    read_arr(sectors, length, plan);
    quicksort(sectors, 0, length - 1);
    merge(sectors, length, merged_sectors, merged_length);
    int line_length = count_length(merged_sectors, merged_length);
    cout << line_length << "\n";
    if (line_length > plan)
        cout << "He had overdone the plan.";
        else if(line_length == plan)
            cout << "He had managed with the plan.";
            else
                cout << "He didn't cope with the plan.";
    return 0;
}

