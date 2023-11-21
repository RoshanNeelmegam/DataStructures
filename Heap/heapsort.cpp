#include <iostream>

using namespace std;


void Insert(int arr[], int n)
{
    // 50, 30, 40 -> insert 100
    int temp = arr[n];
    int i = n;
    while (i>1 && temp > arr[i/2]){
        arr[i] = arr[i/2];
        i = i/2;
    }
    arr[i] = temp;
}

void CreateHeap(int arr[], int size)
{
   int i;
   for (i=2; i<=size; i++){
       Insert(arr, i);
   }
}


void Delete(int arr[], int n){
    int temp = arr[1];
    arr[1] = arr[n];
    arr[n] = temp;
    int i = 1, left = 2*i;
    while (left <= n-1){
        int right = left + 1;
        if (right <= n-1){
            if (arr[left]>arr[i] && arr[left]>arr[right]){
                int lemp = arr[i];
                arr[i] = arr[left];
                arr[left] = lemp;
                i = left;
            }
            else if (arr[right]>arr[i] && arr[left]<arr[right]){
                int lemp = arr[i];
                arr[i] = arr[right];
                arr[right] = lemp;
                i = right;
            }
        }
        else{
            if (arr[left]>arr[i]){
                int lemp = arr[i];
                arr[i] = arr[left];
                arr[left] = lemp;
            }
            i = left;
        }
         left = 2*i;
    }
}
    
int main()
{
    int Heap[] = {0,1000, 10, 20, 30, 25, 5, 40, 35, 100};
    for (auto x: Heap){
        cout<<x<<" ";
    }
    cout<<endl;
    
    CreateHeap(Heap, 9);
    
    for (auto x: Heap){
        cout<<x<<" ";
    }
     
    cout<<endl;
    
    for (int i=9; i>1; i--){
         Delete(Heap, i);
    }
     
    for (auto x: Heap){
        cout<<x<<" ";
    }
     
    cout<<endl;
    
    return 0;
}
