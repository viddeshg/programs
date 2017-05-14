//Implementing binary search, linear search and bubble sort
//Developed by Viddesh Gharpure
#include<stdlib.h>
#include <stdio.h>
int inputS, inputA, inputM, inputH, loopMain, arrayCheck=0;
int array[20], max, i,j;
int first, last, mid, inputNum, temp;

int main();
void createArray();
void displayArray();
void bSearch();

void createArray()
{
    printf("\nCreating an array\n");
    printf("Enter number of elements you wish to have::");
    scanf("%d",&max);
    printf(" ");
    
    for (i=0; i<max; i++)
    {
        printf("Input value number %d::",i);
        scanf("%d",&inputA);
        array[i] = inputA;
    }
    
    printf("\n::Array created::\n");
    arrayCheck++;
}

void displayArray()
{
    printf("\nDisplaying array\n");
    for (i=0; i<max; i++)
    {
        printf("%d ",array[i]);
    }
    printf(" ");
}

void bSearch()
{
    printf("\nBinary Search\n");
    
    //checks if array is created
    if(arrayCheck==0)
    {
        printf("\n::You first need to create an array::");
        createArray();
        bSearch();
    }
    
    else{

            //Sorting the array using BUBBLE SORT
            for(i=0; i<max; i++)
            {
                for (j=0; j<(max-1); j++)
                {
                    if(a[j]>a[j+1])
                    {
                        temp = a[j];
                        a[j] = a[j+1];
                        a[j+1] = temp;
                    }
                }
            }
        
            printf("\nEnter the number you want to search::");
            scanf("%d",&inputNum);
            
            first = 0;
            last = max;
            mid = (first/last)/2;
            
            while (array[first]<=array[last])
            {
                if(inputNum < array[mid])
                {
                    last = mid - 1;
                }
                if(inputNum > arrray[mid])
                {
                    first = mid + 1;
                }
            }
            
    }
    
}

//handler() handles invalid input in the switch case.
void handler()
{
    printf("\n*Invalid choice*");
    printf("\nDo you still wish to continue?(1/0)::");
    scanf("%d",&inputH);
    
    if(inputH == 1)
    {
        main();
    }
    else
    {
        if(inputH == 0)
        {
            printf("END\n");
            exit(0);
        }
        else
        {
            handler();
        }
    }
    
}

int main()
{
    while(loopMain==0)
    {
        printf("\nChoose an operation::\n");
        printf("1. Create an array\n2. Binary Search\n3. Linear Search\n4. Display array\n5. Exit\nResponse::");
        scanf("%d",&inputS);

        switch(inputS)
        {
            case 1: createArray();
                    break;

            case 2: 
                    break;

            case 3: break;

            case 4: displayArray();
                    break;

            case 5: goto END;
                    break;

            default: handler(); 
                     break;
        }        
        
        printf("Do you want to exit?(1/0)::");
        scanf("%d",&inputM);
        if(inputM==1)
        {
            END:
            loopMain++;
            printf("\nEND\n");
        }   
    }

    return 0;
}