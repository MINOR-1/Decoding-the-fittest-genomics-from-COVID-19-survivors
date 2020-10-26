#include <stdio.h>
#include <stdlib.h>

typedef struct Chrom
{
    short int bit[6];
    int fit;

}chrom;


void evpop(chrom popcurrent[4]);
void pickchroms(chrom popcurrent[4]);
void crossover(chrom popcurrent[4]);
int find_fit_value(int value);
int getvalue(chrom popcurrent);

int main()
{
   int num;
   int i,j;

   enter: printf("\nPlease enter the no. of iterations:  ");
   scanf("%d",&num);
   chrom popcurrent[4];
   chrom popnext[4];
   if(num<1)
   goto enter;

   evpop(popcurrent);
   for(i=0;i<num;i++)
{3

     printf("\n\n\niteration = %d\n",i);

     for(j=0;j<4;j++)
        popnext[j]=popcurrent[j];
     pickchroms(popnext);
     crossover(popnext);

     for(j=0;j<4;j++)
        popcurrent[j]=popnext[j];

    }
}

void evpop(chrom population[])
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
    printf("$ INITIAL SET OF CHROMOSOMES:\n");
    printf("*******************************\n");

    for(j=0;j<4;j++)
    {
     value=getvalue(population[j]);
     population[j].fit=find_fit_value(value);

     printf("Chromosome %d\t",j+1);
     printf("\n");
     printf("sequence=");
        for(int i=0;i<6;i++)
        {
            printf("%d",population[j].bit[i]);
        }
        printf("     ");
        printf("value=%d\t",value);
        printf("fitness=%d" ,population[j].fit);
        printf("\n");


    }
    printf("*******************************\n\n\n\n\n");


}

int getvalue(chrom population)
{
    int value;
    value=(population.bit[5]*1)+(population.bit[4]*2)+(population.bit[3]*4)+(population.bit[2]*8)+(population.bit[1]*16)+(population.bit[0]*32);
    return value;
}

int find_fit_value(int value)
{
    
    int fit_value=(value*value)+5;
    return fit_value;
}

void pickchroms(chrom population[4])
{

 int i,j;
   struct Chrom temp;

    for(i=0;i<3;i++)
       for(j=0;j<3;j++)
         {
             if(population[j+1].fit>population[j].fit)
               {
                 temp=population[j+1];
                 population[j+1]=population[j];
                 population[j]=temp;

               }
         }
        printf("$ PERFORMING SORTING ON INITIAL SET OF CHROMOSOMES.........%\n");
        printf("$ AFTER SORTING:\n");
    printf("*******************************\n");

    for(i=0;i<4;i++)
    {
        printf("chromoses=%d\t fitness=%d",i+1,population[i].fit);
        printf("\n");
    }
    printf("*******************************\n\n\n\n\n");

}

void crossover(chrom population[4])
{
    int i;
    int random_number;
    
    random_number = rand();
    
    random_number = ((random_number%5)+1);
    for(i=0;i<random_number;i++)
    {
        population[2].bit[i]=population[1].bit[i];
        population[3].bit[i]=population[0].bit[i];
    }
    
    for(i=random_number;i<6;i++)
    {
        population[2].bit[i]=population[0].bit[i];
        population[3].bit[i]=population[1].bit[i];
    }
    
    for(i=0;i<4;i++)
        population[i].fit=find_fit_value(getvalue(population[i]));
    printf("$ PERFORMING CROSSOVER ON SORTED SET OF CHROMOSOMES.........%\n");
    printf("$ AFTER CROSSOVER:\n");
    printf("*******************************");


    
    
    for(i=0;i<4;i++)
        printf("\nChromosome %d\nSequence=%d%d%d%d%d%d\t    value=%d\t fitness = %d",i+1,population[i].bit[5],population[i].bit[4],population[i].bit[3],population[i].bit[2],population[i].bit[1],population[i].bit[0],getvalue(population[i]),population[i].fit);
                
    printf("\n*******************************");

        
}
