/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int x,y;
};
int k=0;
struct Node visited[100000000];
int checkVisited(struct Node curr)
{
    for(int i=0;i<k;i++)
    if(curr.x==visited[i].x&&curr.y==visited[i].y)
        return 1;
    return 0;

}

int flag=0;
///TAKING maxX=4 and maxY=3 litres only
void dfs(struct Node current, struct Node goal)
{



    if(flag==1)
        return;
        printf("(%d, %d)\n",current.x,current.y);

    if(current.x==goal.x && current.y==goal.y)
        {
            flag=1;
        }

        if(checkVisited(current))
        return;
    visited[k++]=current;

if(flag==1)
        return;
    ///Transfer x to y
    if(current.y<3&&current.x>0)
    {
        printf("Transfer x->y in (%d, %d) : ",current.x,current.y);
        int tempx=current.x;
        int tempy=current.y;
        int temp1;
        if(current.y>=3-current.y)
        temp1=(3-current.y);
        else
        temp1=current.x;
        current.y+=temp1;
        current.x-=temp1;
        dfs(current,goal);
        current.x=tempx;
        current.y=tempy;
    }
    if(flag==1)
        return;
        ///Transfer y to x
    if(current.x<4&&current.y>0)
    {
        printf("Transfer y->x in (%d, %d) : ",current.x,current.y);
        int tempx=current.x;
        int tempy=current.y;
        int temp1;
        if(current.x>=4-current.x)
        temp1=(4-current.x);
        else
        temp1=current.y;
        current.x+=temp1;
        current.y-=temp1;
        dfs(current,goal);
        current.x=tempx;
        current.y=tempy;
    }
    if(flag==1)
        return;

    ///FILL x
    if(current.x<4)
    {
        printf("FILL x in (%d, %d) : ",current.x,current.y);
        int temp=current.x;
        current.x=4;
        dfs(current,goal);
        current.x=temp;
    }
    if(flag==1)
        return;
    ///FILL y
    if(current.y<3)
    {
        printf("FILL y in (%d, %d) : ",current.x,current.y);
        int temp=current.y;
        current.y=3;
        dfs(current,goal);
        current.y=temp;
    }
if(flag==1)
        return;
       ///Empty x
       if(current.y>0&&current.x>0)
       {
            printf("Empty x in (%d, %d) : ",current.x,current.y);
           int temp=current.x;
            current.x=0;
            dfs(current,goal);
            current.x=temp;

       }
if(flag==1)
        return;
       ///Empty y
       if(current.y>0&&current.x>0)
       {
           printf("Empty y in (%d, %d) : ",current.x,current.y);
           int temp=current.y;
            current.y=0;
            dfs(current,goal);
            current.y=temp;

       }
}


void main()
{
    struct Node initial;
    initial.x=0;
    initial.y=0;

    struct Node goal;
    goal.x=2;
    goal.y=0;
    dfs(initial,goal);
}