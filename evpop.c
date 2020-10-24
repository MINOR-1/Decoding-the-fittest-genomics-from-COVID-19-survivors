#include <stdio.h>
#include <stdlib.h>

struct Chrom
{
    int bit[6];
    int fit;
}chrom;

void evpop(struct Chrom population[]);
void pickchroms(struct Chrom popcurrent[]);
int find_fit_value(int value);

int main()
{
    struct Chrom population[4];
    evpop(population);
    pickchroms(population);

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
    printf("# HERE IS THE COMPLETE INFORMATION ABOUT THE ENTIRE POPULATION SET OF CHROMOSOMES\n");
    printf("*********************************************************************************\n");

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
        printf("fit_value=%d" ,population[j].fit);
        printf("\n");
        printf("\n");


    }

}

int getvalue(struct Chrom human)
{
    int value;
    value=(human.bit[5]*1)+(human.bit[4]*2)+(human.bit[3]*4)+(human.bit[2]*8)+(human.bit[1]*16)+(human.bit[0]*32);
    return value;
}

int find_fit_value(int value)
{
    int random=rand()%10;
    int fit_value=(value*value)+random;
    return fit_value;
}
void pickchroms(struct Chrom popcurrent[])
{

 int i,j;
   struct Chrom temp;

    for(i=0;i<3;i++)
       for(j=0;j<3;j++)
         {
             if(popcurrent[j+1].fit>popcurrent[j].fit)
               {
                 temp=popcurrent[j+1];
                 popcurrent[j+1]=popcurrent[j];
                 popcurrent[j]=temp;

               }
         }
        printf("# Performing the required sorting opertion in order to achieve the best chromosomes.................%\n");
        printf("# After Performing The sorting on the chromoses we ll get the reuired sequence in the descending order of fit_value\n");
        printf("*******************************************************************************************************************\n\n");

    for(i=0;i<4;i++)
    {
        printf("chromoses=%d\t fitness=%d",i,popcurrent[i].fit);
        printf("\n");
    }
  return(0);
}
