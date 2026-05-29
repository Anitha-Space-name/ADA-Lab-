#include <stdio.h>

#define MAX 10

struct Element
{
    int value;
    int dir;
};

void printPermutation(struct Element a[], int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i].value);
    }

    printf("\n");
}

int getMobile(struct Element a[], int n)
{
    int i;
    int mobile = 0;
    int mobileIndex = -1;

    for(i = 0; i < n; i++)
    {
        if(a[i].dir == 0 && i != 0)
        {
            if(a[i].value > a[i-1].value && a[i].value > mobile)
            {
                mobile = a[i].value;
                mobileIndex = i;
            }
        }

        if(a[i].dir == 1 && i != n-1)
        {
            if(a[i].value > a[i+1].value && a[i].value > mobile)
            {
                mobile = a[i].value;
                mobileIndex = i;
            }
        }
    }

    return mobileIndex;
}

int main()
{
    int n, i;
    struct Element a[MAX], temp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        a[i].value = i + 1;
        a[i].dir = 0;
    }

    printf("\nPermutations are:\n");

    printPermutation(a, n);

    while(1)
    {
        int mobileIndex = getMobile(a, n);

        if(mobileIndex == -1)
            break;

        int mobileValue = a[mobileIndex].value;

        if(a[mobileIndex].dir == 0)
        {
            temp = a[mobileIndex];
            a[mobileIndex] = a[mobileIndex - 1];
            a[mobileIndex - 1] = temp;

            mobileIndex--;
        }
        else
        {
            temp = a[mobileIndex];
            a[mobileIndex] = a[mobileIndex + 1];
            a[mobileIndex + 1] = temp;

            mobileIndex++;
        }

        for(i = 0; i < n; i++)
        {
            if(a[i].value > mobileValue)
            {
                a[i].dir = 1 - a[i].dir;
            }
        }

        printPermutation(a, n);
    }

    return 0;
}
