#include <stdio.h>

int removeElement(int *arr, int n, int val)
{
    int i, newlength = 0;
    
    for(i=0; i<n; i++)
        if(arr[i] != val) {
            arr[newlength] = arr[i];
            newlength++;
        }
            
    return newlength;
}

int main()
{
    int ary[6] = {10,30,40,10,10};
    int new_array_len = removeElement(ary, 5, 10);
    for (int i = 0; i < new_array_len; i++) {
        printf("novo array: %d\n", ary[i]);
    }
}