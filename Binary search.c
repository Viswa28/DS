#include <stdio.h>
#include <stdbool.h>
void binary_search(int u, int l, int arr[], int num)
{
    int mid = (u + l) / 2;
    if (arr[mid] == num)
    {
        printf("Element found at %d th pos !!!",mid);
    }
    else if (num > arr[mid])
    {
        binary_search(u, mid + 1, arr, num);
    }
    else if (num < arr[mid])
    {
        binary_search(mid - 1, l, arr, num);
    }
    else
    {
        printf("Element not found!!!!!!");
    }
}
int main()
{
    int arr[] = {14, 55, 62, 68, 83};
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }

    int u, l, num;
    u = 5;
    l = 0;
    printf("\nEnter the element to be searched:");
    scanf("%d", &num);
    binary_search(u, l, arr, num);

    return 0;
}
