#include <stdio.h>
#include <math.h>
int main()
{
    int n,head,i,a[20],current,dist,seekcount=0;
    printf("Enter the number of elements in request array\n");
    scanf("%d",&n);
    printf("Enter the requested array\n");
    for(i=0;i<n;i++)
       scanf("%d",&a[i]);
    printf("Enter the head position\n");
    scanf("%d",&head);
    
    for(i=0;i<n;i++)
       {
        current=a[i];
        dist=fabs(head-current);
        seekcount=seekcount+dist;
        head=current;
       }
    printf("Total Seek Count is %d",seekcount);
    return 0;
}