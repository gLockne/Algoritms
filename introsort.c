#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
void PS(int *m,int d)
{
    int r;
    int e = 0;
    for(int j = d/2 - 1;j>=0;j--)
    {
        e = 0;
        int i = j;
        while(e == 0)
        {
            if(2*i+2<=d-1)
            {
                if(m[2*i+1]>m[2*i+2])
                {
                    if(m[2*i+1]>m[i])
                    {
                        r = m[i];
                        m[i] = m[2*i+1];
                        m[2*i+1] = r;
                        i = 2*i+1;
                    }else
                    {
                        e = 1;
                    }
                }else
                {
                    if(m[2*i+2]>m[i])
                    {
                        r = m[i];
                        m[i] = m[2*i+2];
                        m[2*i+2] = r;
                        i = 2*i+2;
                    }else
                    {
                        e = 1;
                    }
                }
            }else
            {
                if(2*i+1<=d-1)
                {
                    if(m[2*i+1]>m[i])
                    {
                        r = m[i];
                        m[i] = m[2*i+1];
                        m[2*i+1] = r;
                        i = 2*i+1;
                    }else
                    {
                        e = 1;
                    }
                }else
                {
                    e = 1;
                }
            }
        }
    }
    printf("\n");
    for(int i = 0;i<d;i++)
    {
        printf("%d\n",m[i]);
    }
    for(int j = d-1;j>=1;j--)
    {
        r = m[0];
        m[0] = m[j];
        m[j] = r;
        e = 0;
        int i = 0;
        while(e == 0)
        {
            if(2*i+2<=j-1)
            {
                if(m[2*i+1]>m[2*i+2])
                {
                    if(m[2*i+1]>m[i])
                    {
                        r = m[i];
                        m[i] = m[2*i+1];
                        m[2*i+1] = r;
                        i = 2*i+1;
                    }else
                    {
                        e = 1;
                    }
                }else
                {
                    if(m[2*i+2]>m[i])
                    {
                        r = m[i];
                        m[i] = m[2*i+2];
                        m[2*i+2] = r;
                        i = 2*i+2;
                    }else
                    {
                        e = 1;
                    }
                }
            }else
            {
                if(2*i+1<=j-1)
                {
                    if(m[2*i+1]>m[i])
                    {
                        r = m[i];
                        m[i] = m[2*i+1];
                        m[2*i+1] = r;
                        i = 2*i+1;
                    }else
                    {
                        e = 1;
                    }
                }else
                {
                    e = 1;
                }
            }
        }
    }
    return;
}
void QS(int * m, int n, int k, int d, int y)
{
    if(y < log(d))
    {
        int l = n;
        int r = k;
        int o;
        int key = m[(n+k)/2];
        do
        {
            while(m[l]<key)
            {
                l++;
            }
            while(m[r]>key)
            {
                r--;
            }
            if(l<=r)
            {
                o = m[l];
                m[l] = m[r];
                m[r] = o;
                l++;
                r--;
            }

        }while(l<=r);
        y++;
        if (n<r)
        {
            QS(m, n, r, r, y);
        }
        if (l<k)
        {
            QS(m, l, k, k-l, y);
        }
    }
    return;
}
void IS(int * m, int d)
{
    QS(m, 0, d-1, d, 0);
    printf("\n");
    for(int i = 0;i<d;i++)
    {
        printf("%d\n",m[i]);
    }
    PS(m, d);
    return;
}
int main(int argc, char * argv[])
{
    FILE *inpf;
    inpf = fopen(argv[1], "r");
    int n;
    fscanf(inpf, "%d", &n);
    //scanf("\n%d\n", &n);
    int *q = malloc(n*sizeof(int));
    for(int i = 0; i < n; i++)
	{
		fscanf(inpf, "%d", &q[i]);
	}
    //for(int i = 0;i<n;i++)
    //{
    //    scanf("\n%d",&q[i]);
    //}

    clock_t begin=clock();

    IS(q,n);

    clock_t end=clock();

    printf("Time taken:%lf",(double)(end-begin)/CLOCKS_PER_SEC);

    printf("\n");
    for(int i = 0;i<n;i++)
    {
        printf("%d\n",q[i]);
        //fprintf(fp,"%d\n",q[i]);
    }
    fclose(inpf);
    free(q);
    return 0;
}
