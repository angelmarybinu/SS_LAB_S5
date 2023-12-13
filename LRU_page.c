#include <stdio.h>
int main()
{
    int i,j,rs[20],f,n,m[20],count=0,pf=0,k,rev,maxdist,dist[20],index;
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
        if(i<f)
        {
            pf++;
            m[i]=rs[i];
            printf("\t\t");
            for(j=0;j<f;j++)
               printf("\t%d",m[j]);
            printf("\n");
        }
        else
        {
            for(k=0;k<f;k++)
               {
                if(rs[i]==m[k])
                   {
                    printf("\t\t");
                    for(j=0;j<f;j++)
                        printf("\t%d",m[j]);
                    break;
                   }
                
               }
            if(k==f)
              {
                maxdist=-1;
                for(j=0;j<f;j++)
                   {
                    dist[j]=0;
                    for(rev=i-1;rev>=0;rev--)
                       {
                        dist[j]++;
                       
                        if(m[j]==rs[rev])
                          {
                            break;
                          }
                       }
                    if(dist[j]>maxdist)
                      {
                      maxdist=dist[j];
                      index=j;
                      }
                   }
                m[index]=rs[i];
                pf++;
                printf("\nPage Fault%d\t",pf);
                for(j=0;j<f;j++)
                   printf("%d\t",m[j]);
                printf("\n");
              }
        }
    }
printf("Number of page Faults is %d",pf);
return 0;
}