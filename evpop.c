#include <stdio.h>
#include <stdlib.h>

typedef struct Chrom             		
{
    short int bit[6];
    int fit;

}chrom;


void evpop(chrom popcurrent[5]);
void pickchroms(chrom popcurrent[5]);
void crossover(chrom popcurrent[5]);
int find_fit_value(int value);
int getvalue(chrom popcurrent);

int main()
{
    chrom population[5];

	evpop(population);
    
	pickchroms(population);

	crossover(population);
    return (0);
}

void evpop(chrom population[])
{
    int j=0;
    int random;
    int i=0;
    int k=0;
    int value;
    for(int j=0;j<5;j++)
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

    for(j=0;j<5;j++)
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
    int random=rand()%10;
    int fit_value=(value*value)+random;
    return fit_value;
}

void pickchroms(chrom population[5])
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

    for(i=0;i<5;i++)
    {
        printf("chromoses=%d\t fitness=%d",i+1,population[i].fit);
        printf("\n");
    }
    printf("*******************************\n\n\n\n\n");

}

void crossover(chrom population[5])
{
	int i;
	int random_number;
	
	random_number = rand();		
	
	random_number = ((random_number%5)+1);	
	for(i=0;i<random_number;i++)	
	{
		population[3].bit[i]=population[2].bit[i];	
        population[4].bit[i]=population[1].bit[i];	
	}
	
	for(i=random_number;i<6;i++)
	{
		population[3].bit[i]=population[1].bit[i];	
        population[4].bit[i]=population[2].bit[i];	
	}
	
	for(i=0;i<5;i++)	
    	population[i].fit=find_fit_value(getvalue(population[i]));	
	printf("$ PERFORMING CROSSOVER ON SORTED SET OF CHROMOSOMES.........%\n");
	printf("$ AFTER CROSSOVER:\n");
	printf("*******************************");


	
	
    for(i=0;i<5;i++)                           
    	printf("\nChromosome %d\nSequence=%d%d%d%d%d%d\t    value=%d\t fitness = %d",i+1,population[i].bit[5],population[i].bit[4],population[i].bit[3],population[i].bit[2],population[i].bit[1],population[i].bit[0],getvalue(population[i]),population[i].fit);
        		
	printf("\n*********************************");

		
}