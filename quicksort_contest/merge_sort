#include<iostream>

using namespace::std;

void Merge(int m[],int temp[],int Left,int Middle,int Right)
{
    int i=Left, j=Middle+1;
    for (int k=Left; k<=Right; k++)
    {
        if(i>Middle)
        {
            temp[k]=m[j]; j++;
        }
        else if (j>Right)
        {
            temp[k]=m[i]; i++;
        }
        else if(m[i]>m[j])
        {
            temp[k]=m[j]; j++;
        }
        else
        {
            temp[k]=m[i]; i++;
        }
    }
}

bool findPair(int m[],int N, int Left, int & Middle, int &Right)
{
    if (Left>=N) return false;
    Middle=Left;
    while(Middle<N-1 && m[Middle]<=m[Middle+1]) Middle++;
    if (Middle==N-1)
    {
        Right=N-1;
        return false;
    }
    Right=Middle+1;
    while (Right<N-1 && m[Right]<=m[Right+1]) Right++;
    return true;
}

void copyAr(int m[], int temp[], int Left, int Right)
{
    for (int i=Left; i<=Right; i++)
        temp[i]=m[i];
}

bool mergeStep(int m[], int temp[], int N)
{
    int Left=0, Middle, Right;
    while (findPair(m,N,Left,Middle,Right))
    {
        Merge(m,temp,Left,Middle,Right);
        Left=Right+1;
    }
    if (Left==0 && Right==N-1) return false;
    if (Left<=N-1)copyAr(m,temp,Left,N-1);
    return true;
}

void SortByMrg(int m[], int N)
{
    int temp[100000];
    int step=0;
    bool notSorted=true;
    while (notSorted)
    {
        step++;
        if (step%2!=0)
            notSorted=mergeStep(m,temp,N);
        else
            notSorted=mergeStep(temp,m,N);
    }
    if (step%2==0) copyAr(temp,m,0,N-1);
}


void read_arr(int arr[], int &length)
{
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> arr[i];
}

void print_arr(int arr[], int length)
{
    for (int i = 0; i < length; i++)
        cout << arr[i] << " ";
}

int main()
{
    int arr[100000], length;
    read_arr(arr, length);
    SortByMrg(arr, length);
    print_arr(arr, length);
    return 0;
}
