#include<bits/stdc++.h>

using namespace std;


void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
void print(int arr[],int n)
{
    for(int i = 0; i < n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
void BubbleSort(int n,int arr[])
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n - 1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j],arr[j + 1]);
            }
        }
    }
    print(arr,n);
}
void insertSort(int arr[], int n)
{
    int i,key,j;
    for(int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    print(arr,n);
}

void selectionSort(int arr[], int n)
{
    int i,j,min_indx;
    for(i = 0; i < n; i++)
    {
        min_indx = i;
        for (j = i + 1 ; j < n; j++)
        {
            if(arr[j] < arr[min_indx])
            {
                min_indx = j;
            }
        }
        swap(arr[min_indx], arr[i]);
    }
    print(arr,n);
}
int main()
{
    int arr[5] = {5,4,3,2,1};
    int n = sizeof(arr)/4;
    insertSort(arr,n);
    BubbleSort(n,arr);
}