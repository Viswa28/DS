#include <stdio.h>
#include <stdbool.h>
int main()
{
    int num;
    int arr[] = {14, 62, 83, 55, 16};

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nEnter the element to be searched:");
    scanf("%d", &num);
    for (int i = 0; i < 5; i++)
    {
        if (arr[i]==num)
        {
            printf("Element found at the %d th position ",i+1);
            break;

        }
        
    }

    
    return 0;
}
