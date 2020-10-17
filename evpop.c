#include <stdio.h>
#include <stdlib.h>

struct Chrom
{
    int arr[6];
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
    for(int j=0;j<4;j++)
    {
        for(int i=0;i<6;i++)
        {
            random=rand();
            random=random%2;
            population[j].arr[i]=random;
        }
        
    }
    for(int j=0;j<4;j++)
    {
        printf("Chromosome %d\t",j+1);
        for(int i=0;i<6;i++)
        {
            printf("%d",population[j].arr[i]);
        }
        printf("\n");
        
    }
    
    
    
}
