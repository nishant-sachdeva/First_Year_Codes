#include<stdio.h>
#include<string.h>

char arr[1000];
int size;

int find ( int left)
{
    if( arr[left] >= 'A' && arr[left] <= 'Z')
        return left;
    if( left >= size ) return -1;
    return find( left + 1);
}

int main()
{
    scanf("%s", arr);
    int i =0;
    while(arr[i] != '\0')
        i++;
    size = i;
    int ans = find(0);
    printf("%d\n", ans);
    return 0;
}
