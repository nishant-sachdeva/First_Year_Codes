#include<stdio.h>
#include<string.h>


void reverse( char arr[], int left, int right){
    //printf("left is %d and right is %d\n", left, right);
    if(left >= right) { printf("%s \n", arr) ; return ;}
    char temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
    reverse( arr, left +1, right -1);
}


int main()
{
    char arr[1000];
    scanf("%s", arr);
    // now we have the array , we'll do the normal thing now
    reverse(arr, 0, strlen(arr)-1);
    return 0;
}

