//Implementing binary search and linear search
//Developed by Viddesh Gharpure

#include<stdlib.h>
#include <stdio.h>
int inputS, inputA, inputM, inputH, loopMain, arrayCheck=0;
int array[20], max, i,j;
int first, last, mid, inputNum, inputB, temp,found;

int main();
void createArray();
void displayArray();
void bSearch();
void lSearch();

void createArray()
{
    printf("\nCREATING ARRAY\n");
    printf("Enter number of elements you wish to have::");
    scanf("%d",&max);    
    for (i=0; i<max; i++)
    {
        printf("Input value number %d::",i+1);
        scanf("%d",&inputA);
        array[i] = inputA;
    }
    
    printf("\n::Array created::\n");
    arrayCheck++; //flag to check if array is created
}

void displayArray()
{
    //checks if an array is created
    if(arrayCheck==0)
    {
        printf("\n::You first need to create an array::\n");
        createArray();
    }
    
    printf("\nDISPLAYING ARRAY\n");
    for (i=0; i<max; i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
}

void bSearch()
{    
    
    //checks if an array is created
    if(arrayCheck==0)
    {
        printf("\n::You first need to create an array::\n");
        createArray();
        bSearch();
    }
    
    else{
            printf("\nBINARY SEARCH");
            //Sorting the array using BUBBLE SORT
            for(i=0; i<max; i++)
            {
                for (j=0; j<(max-1); j++)
                {
                    if(array[j]>array[j+1])
                    {
                        temp = array[j];
                        array[j] = array[j+1];
                        array[j+1] = temp;
                    }
                }
            }
            
            printf("\nSorted array is::");
            for (i=0; i<max; i++)
            {
                printf("%d ",array[i]);
            }
        
            SEARCH:
            printf("\nEnter the number you want to search::");
            scanf("%d",&inputNum);
            
            found = 0; //flag to check if number is found
            first = 0;
            last = max-1;            
        
            while (first <= last)
            {
                mid = (first+last)/2;
                
                if(array[mid]==inputNum)
                {
                    printf("\n::Number %d found on location %d::\n",inputNum,mid+1);
                    found++;
                    goto END;
                }
                
                if(inputNum < mid)
                {
                    last  = mid -1;
                }
                if(inputNum > mid)
                {
                    first = mid + 1;
                }
            }
        
            if(found==0)
            {
                printf("\n::Number %d not found::\n",inputNum);
                printf("Do you want to search again?(1/0)::");
                scanf("%d",&inputB);
                if(inputB==1)
                {
                    goto SEARCH;
                }
                else
                {
                    goto END;
                }
            }
    }
    END:;
    
}

void lSearch()
{
    //checks if an array is created
    if(arrayCheck==0)
    {
        printf("\n::You first need to create an array::\n");
        createArray();
        lSearch();
    }
    else
    {
        printf("\nLINEAR SEARCH\n");
        
        SEARCH:
        printf("Enter the number you want to search::");
        scanf("%d",&inputNum);
        
        found = 0; //flag to check if number is found
        
        for(i=0; i<max; i++)
        {
            if(array[i]==inputNum)
            {
                found++;
                printf("\n::Number %d found on location %d::\n",inputNum,i+1);
                goto END;

            }
            
            if(found==0)
            {
                printf("\n::Number %d not found::\n",inputNum);
                printf("Do you want to search again?(1/0)::");
                scanf("%d",&inputB);
                if(inputB==1)
                {
                    goto SEARCH;
                }
                else
                {
                    goto END;
                }
            }
        }
        
    }
    END:;
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
        loopMain=0;
        printf("\nChoose an operation::\n");
        printf("1. Create an array\n2. Binary Search\n3. Linear Search\n4. Display array\n5. Exit\nResponse::");
        scanf("%d",&inputS);

        switch(inputS)
        {
            case 1: createArray();
                    break;

            case 2: bSearch();
                    break;

            case 3: lSearch();
                    break;

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