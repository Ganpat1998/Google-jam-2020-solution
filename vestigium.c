#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    int p=t;
    while(t--)
    {
        int n,i,j,sum=0,countc=0,countr=0,c=0,r=0,k,q;
        scanf("%d",&n);
        int a[n][n];
        int a1[n][n];
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&a[i][j]);
                a1[i][j]=a[i][j];
                if(i==j)
                {
                    sum=sum+a[i][j];
                }
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                for(k=(j+1);k<n;k++)
                {
                    if(a1[i][j]>a1[i][k])
                    {
                        q=a1[i][j];
                        a1[i][j]=a1[i][k];
                        a1[i][k]=q;
                    }
                }
            }
        }


        for(i=0;i<n;i++)
        {
            for(j=0;j<n-1;j++)
            {
                if(r<1)
                {
                    if(a1[i][j]==a1[i][j+1])
                    {
                        countr++;
                        r++;
                    }
                }
                else
                    break;
            }
            r=0;
        }
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    for(k=(i+1);k<n;k++)
                    {
                        if(a[i][j]>a[k][j])
                        {
                            q=a[i][j];
                            a[i][j]=a[k][j];
                            a[k][j]=q;
                        }
                    }
                }
            }


        for(i=0;i<n;i++)
        {
            for(j=0;j<n-1;j++)
            {
                if(c<1)
                {
                    if(a[j][i]==a[j+1][i])
                    {
                        countc++;
                        c++;
                    }
                }
                else
                    break;
            }
            c=0;
        }


        printf("Case #%d: %d %d %d\n",(p-t),sum,countr,countc);


    }
}
