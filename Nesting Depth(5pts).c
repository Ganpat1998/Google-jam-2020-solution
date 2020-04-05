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
        int i,j,c=0;
        char a[101];
        char b[100000];
        scanf("%s",a);
        for(i=0;i<strlen(a);i++)
        {
            if(a[i]-'0'>0 && a[i]-'0'<=9)
            {
                b[c]='(';
                c++;
                for(j=i;j<strlen(a);j++,i++)
                {
                    if(a[i]=='1')
                    {
                        b[c]=a[i];
                        c++;
                    }

                    else
                        break;
                }
                i--;
                 b[c]=')';
                c++;
            }
            else
            {
                 b[c]=a[i];
                        c++;
            }
        }
        b[c]='\0';
        printf("Case #%d: %s\n",p,b);
    }
}
