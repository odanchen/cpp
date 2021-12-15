#include <iostream>

using namespace std;

void read_arr(int arr[][2], int &length)
{
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        cin >> arr[i][0];
        cin >> arr[i][1];
    }
}

void place_3_elements(int arr[][2], int left, int right, int arg_idx) {
    if (arr[left][arg_idx] > arr[(left + right) / 2][arg_idx])
        swap(arr[left], arr[(left + right) / 2]);
    if (arr[(left + right) / 2][arg_idx] > arr[right][arg_idx])
        swap (arr[(left + right) / 2], arr[right]);
    if (arr[left][arg_idx] > arr[(left + right) / 2][arg_idx])
        swap(arr[left], arr[(left + right) / 2]);
}

void quicksort(int arr[][2], int left, int right, int arg_idx) {
    place_3_elements(arr, left, right, arg_idx);
    int i = left, j = right;
    int etalon = arr[(left + right) / 2][arg_idx];
    while (i < j) {
        while(arr[i][arg_idx] < etalon) i++;
        while(arr[j][arg_idx] > etalon) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (left < j) quicksort(arr, left, j, arg_idx);
    if (i < right) quicksort(arr, i, right, arg_idx);
}

void print_arr(int arr[][2], int length)
{
    for (int i = 0; i < length; i++)
        cout << arr[i][0] << " ";
}

int main()
{
    int arr[100000][2], length;
    read_arr(arr, length);
    quicksort(arr, 0, length - 1, 1);
    print_arr(arr, length);
}
