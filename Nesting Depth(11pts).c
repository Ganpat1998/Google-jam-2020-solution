#include<math.h>
#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d",&t);
    int p=0;
    while(t--)
    {
        p++;
        int i,j,c=0,temp;
        char a[101];
        char b[1000];
        scanf("%s",a);
        printf("Case #%d: ",p);
        int aa=a[0]-'0';
        for(int x=0;x<aa;x++)
                printf("(");
        for(i=0;i<strlen(a)-1;i++ )
        {
            int q=a[i]-'0';
            int r=a[i+1]-'0';
            if(q>r)
            {
                printf("%d",q);
            for(int x=0;x<q-r;x++)
                printf(")");
            }
            else
            {
                printf("%d",q);
                for(int x=0;x<r-q;x++)
                    printf("(");

            }
        }
        int v=a[strlen(a)-1]-'0';
        printf("%d",v);
        for(int i=0;i<v;i++)
            printf(")");
        printf("\n");
        // b[c]='\0';
       // printf("Case #%d: %s\n",p,b);
    }
}
