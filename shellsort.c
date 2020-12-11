#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
void SV(int * m, int d)
{
    int key;
    int i;
    for(int j = 1;j<d;j++)
    {
        key = m[j];
        i = j-1;
        while((i>-1) && (m[i]>key))
        {
            m[i+1] = m[i];
            i--;
        }
        m[i+1] = key;
    }
    return;
}
int inc(int * w, int n)
{
    int i = -1;
    int h;
    int dop;
    while(3*h <= n)
    {
        i++;
        dop = 2;
        if(i%2 == 0)
        {
            for(int r = 1;r<(i/2);r++)
            {
                dop = dop*2;
            }
            h = -9*dop;
            for(int r = i/2;r<i;r++)
            {
                dop = dop*2;
            }
            h += 9*dop + 1;
        }else
        {
            for(int r = 1;r<((i+1)/2);r++)
            {
                dop = dop*2;
            }
            h = -6*dop;
            for(int r = (1+i)/2;r<i;r++)
            {
                dop = dop*2;
            }
            h += 8*dop + 1;
        }
        w[i] = h;
        //printf("%d\n",h);
    }
    return (i-1);
}
void SS(int * m, int d)
{
    int *w = malloc(d*sizeof(int));
    int shag;
    int f = inc(w,d);
    //printf("%d", f);
    while(f>-1)
    {
        shag = w[f];
        f--;
        for(int i = 0;i<shag;i++)
        {
            int key;
            int k;
            for(int j = shag+i;j<d;(j+=shag))
            {
                key = m[j];
                k = j-shag;
                while((k>-1) && (m[k]>key))
                {
                    m[k+shag] = m[k];
                    k -= shag;
                }
                m[k+shag] = key;
            }
        }
    }
    free(w);
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

    SS(q,n);

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
