
#include<stdio.h>
  
void remove_mid(int arr[], int N)
{
    int mid;
    //Write your logic here
    if(N%2 == 0){
        mid = N/2 - 1;
    }
    else{ 
        mid = N/2;
    }
    for(int i = mid; i < N; i++){
      arr[i] = arr[i+1];
    }
    N--;
}


//Do not edit the below code
int main()
{
    int N;

    scanf("%d",&N);

    int i, arr[N];

    for(i = 0; i < N; i++)
        scanf("%d",&arr[i]);

    remove_mid(arr,N);

    for(i = 0; i < N-1; i++)
        printf("%d ",arr[i]);

    return 0;
}
