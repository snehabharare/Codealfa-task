#include<stdio.h>
#include<conio.h>
int main()
{
char operation ;
double a, b,result;

    printf("Enter a operator(+,-,*,/):");
    scanf("%c",&operation);
    //read the two numbers 
    printf("Enter two operands");
    scanf ("%lf%lf", &a,&b);
    
    
    switch(operation )
    
    {
    case'+':
    result=a+b;
    break ;
    case'-':
    result=a-b;
    break ;
    
    case'*' :
    result =a*b;
    break ;
     case'/':
     result =a/b;
     break ;
     default :
     printf("ERROR ! incorrect opration value n");
     result =-DBL_MAX;
     }
     
     if(result!=-DBL_MAX)
     printf("%2lf" ,result);
    
    return 0;
}