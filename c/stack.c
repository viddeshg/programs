//Implementing stack operations with array
//Developed by Viddesh Gharpure

#include <stdio.h>
#include <stdlib.h>
int top = -1, max=4, flag=0, num, status, loop=0, pLoop=0, pStatus=0,i=0,c;
int stack[5];

int main();
void push();
void pop();
void display();
void handler();


void push()
{
    while(top<max)
    {
        i++;
        printf("\nEnter element number %d:: ",i);
        scanf("%d",&num);
        
        if (top<max)
        {
            top++;
            stack[top] = num;
        }
        
        if(top==max)
        {
            flag++;
            printf("\n::STACK IS FULL::\n");
        }
        
        if(flag==0)
        {
            printf("Do you want to add another element?(1/0):: ");
            scanf("%d",&status);
            if(status == 0)
            {
                goto END;
            }            
        }

    } 
    END:;
}

void pop()
{
    printf(" ");
    while(pLoop==0)
    {
        printf("\nDo you want to pop value from stack(1/0)::");
        scanf("%d",&pStatus);
        if(pStatus==0)
        {
            goto END;   
        }

        if(top==0)
        {
            printf("\n::STACK IS EMPTY::\n");
        }
        else
        {
            printf("Top value %d is popped from the stack.\n",stack[top]);
            top--;
        }   
    }
    END:;
}


void display()
{
    
    printf("\nSTACK CONTENTS::\n");
    printf("\nTOP\n---\n");
    for(flag=top; flag>=0; flag--)
    {
        printf(" %d\n",stack[flag]);
    }
    printf("---\n");
    
}

//handler() handles invalid input in the switch case.
void handler()
{
    printf("\n*Invalid choice*");
    printf("\nDo you still wish to continue?(1/0)::");
    scanf("%d",&status);
    
    if(status == 1)
    {
        main();
    }
    else
    {
        if(status == 0)
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
    while(loop==0)
    {
        loop=0;
        printf("\n**STACK OPERATIONS**\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\nResponse::");
        scanf("%d",&c);


        switch(c)
        {
            case 1: push();
                    break;
                
            case 2: pop();
                    break;

            case 3: display();
                    break;
                
            case 4: goto END;
                    break;

            default: handler();
                     break;
        }

        printf("Do you want to exit?(1/0)::");
        scanf("%d",&status);
        if(status==1)
        {
            END:
            loop++;
            printf("\nEND\n");
        }   
    }

    return 0;
}