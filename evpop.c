#include <stdio.h>
#include <stdlib.h>

struct Chrom
{
    int bit[6];
    int fit;
}chrom;
void evpop(struct Chrom population[]);
int main()
{
    struct Chrom population[4];
    evpop(population);
    return 0;
}
void evpop(struct Chrom population[])
{
    int j=0;
    int random;
    int i=0;
    int k=0;
    int value;
    for(int j=0;j<4;j++)
    {
        for(int i=0;i<6;i++)
        {
            random=rand();
            random=random%2;
            population[j].bit[i]=random;
        }
        
    }
    for(int j=0;j<4;j++)
    {
        printf("Chromosome %d\t",j+1);
        for(int i=0;i<6;i++)
        {
            printf("%d",population[j].bit[i]);
        }
        printf("\n");
        
    }
    
for(j=0;j<4;j++)
    {
    value=getvalue(population[j]);
    printf("Chromosome %d\t%d\n",j+1,value);
    }
}
int getvalue(struct Chrom human)
{
    int value;
    value=(human.bit[5]*1)+(human.bit[4]*2)+(human.bit[3]*4)+(human.bit[2]*8)+(human.bit[1]*16)+(human.bit[0]*32);
    return value;
}
