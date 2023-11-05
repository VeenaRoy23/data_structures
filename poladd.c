#include<stdio.h>
int MAX=100;
struct poly
{
    int coeff;
    int exp;
};

void input(struct poly poln[],int n)
{
    printf("Enter the terms\n");
    for(int i=0;i<n;i++)
        scanf("%d%d",&poln[i].coeff,&poln[i].exp);
}

void display(struct poly poln[],int n)
{
        for (int i=0;i<n;i++)
        {
            if(poln[i].coeff!=0)
            {
                printf("%dx^%d" ,poln[i].coeff,poln[i].exp);
                if(i<n-1)
                    printf(" + ");
            }
        }
        printf("\n");
}
int add(struct poly pol1[],int p,struct poly pol2[],int q,struct poly result[])

{
    int i=0,j=0,k=0;
    while (i<p&&j<q)
    {
        if(pol1[i].exp>pol2[j].exp)
        {
            result[k++]=pol1[i++];
        }
        else if(pol1[i].exp<pol2[j].exp)
        {
            result[k++]=pol2[j++];
        }
        else if(pol1[i].exp==pol2[j].exp)
        {
            result[k].exp=pol1[i].exp;
            result[k].coeff=pol1[i].coeff+pol2[j].coeff;
            i++;
            j++;
            k++;
        }
    }
    while(i<p)
    {
        result[k++]=pol1[i++];
    }
    while(j<q)
    {
        result[k++]=pol2[j++];
    }

    return k;
    
    
}

int main()
{
    int n1,n2;
   
    printf("Enter the number of terms in first polynomial\n");
    scanf("%d",&n1);
    struct poly poly1[n1];
    printf("Enter the first polynomial\n");
    input(poly1,n1);
    printf("Enter the number of terms in the second polynomial\n");
    scanf("%d",&n2);
    struct poly poly2[n2];
    printf("Enter the second polynomial\n");
    input(poly2,n2);
    int d=n1+n2;
    struct poly result[d];
    int k=add(poly1,n1,poly2,n2,result);
    
    printf("The first polynomial is\n");
    display(poly1,n1);
    printf("The second polynomial is\n");
    display(poly2,n2);
    printf("The result polynomial is\n");
    display(result,k);

}

