#include <stdio.h>
int main()
{
    int i,j,rs[20],f,n,m[20],count=0,pf=0,k;
    printf("Enter the length of reference string\n");
    scanf("%d",&n);
    printf("Enter the refernce string\n");
    for(i=0;i<n;i++)
       scanf("%d",&rs[i]);
    printf("Enter the number of frames\n");
    scanf("%d",&f);
    for(i=0;i<f;i++)
       m[i]=-1;

    printf("Page replacement process is\n");
    for(i=0;i<n;i++)
    {
        for(k=0;k<f;k++)
           {
            if(m[k]==rs[i])
              break;
           }
        if(k==f)
           {
             m[count++]=rs[i];
             pf++;
           }
        if(k==f)
          printf("Page Fault%d",pf);
        else
          printf("\t\t");
        for(j=0;j<f;j++)
          printf("\t%d",m[j]);
        printf("\n");
        if(count==f)
          count=0;
    }
printf("The number of page faults is %d",pf);
return 0;
}