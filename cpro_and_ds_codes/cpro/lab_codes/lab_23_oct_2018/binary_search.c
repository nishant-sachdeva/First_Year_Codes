#include<stdio.h>
int n;
int bs(int arr[], int key)
{
    int size, left, right, mid;
    left =0; int ans =0;
    right = n-1;
 //   printf("%d\n", right);
    while( left < right){
        mid = (right + left) /2;
        if(key  == arr[mid]) return mid;
        else if ( key < arr[mid])
            right = mid -1;
        else left = mid + 1;
    }
    return left;
}

int main()
{
    scanf("%d", &n);
    int arr[1000];
    for(int i =0; i<n; i++)
        scanf("%d", &arr[i]);
    int key; scanf("%d", &key);
    int ans = bs(arr, key);
    printf("%d \n", ans);
    return 0;
}
