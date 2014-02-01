#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
main()
{
    float x,y;
    char k;
    int s,n;
    printf("what do u want to do????\n");
    printf("for arithmetic operations press 1\n");
    printf("for trignometric operations press 2");
    printf("for finding square and square root press 3");
    scanf("%d",&s);
    if(s==1)
     {
    printf("hey.. hello...enter the two numbers X and Y");
         scanf("%f%f",&x,&y);
         
         printf("what to do with these numbers....??");
         
                       
         k=getch();
         switch(k)
         {
         case'+':   
          printf("result is %f",(x+y));
          break;
          case'-':
          printf("result is %f",(x-y));
          break;
          case'*':
          printf("result is %f",(x*y));
          break;
          case'/':  
          printf("result is %f",(x/y));
          break;
          case'%':
          printf("result is %f",(x/y)*100);
                  }
                  }
         if(s==2)
         {
          printf("enter the angle");
          scanf("%f",&x);
          x=(3.14/180)*x;
          printf("press s for sin\n c for cos\n t for tan\n o for cot\n");
          k=getch();
          switch(k)
          {
          case's':
                  printf("sin of the angle is %f",sin(x));
                  break;
                  case'c':
                          printf("cos of  anngle is %f,cos(x)");
                          break;
                          case't':
                                  printf("tan of the angle is %f",tan(x));
                                  break;
                                  case'o':
                                           printf("cot of the angle is %f",1/tan(x));
                                           break;
                                           }
                                           if(s==3)
                                           {
                                                    printf( "enter value of no");
                                                    scanf("%f",&x);
                                            printf("for nthroot press 1\nfor nth square press 2");
                                            k=getch();
          switch(k)
          {
          case 1:
              printf("enter the value of n");
              scanf("%d",&n);
              printf("ans is %f",pow(x,(1/n));
              break;
              case 2;
               printf("enter the value of n");
                scanf("%d",&n);
              printf("ans is %f",pow(x,n);
                                           
                                                   
                                                   }
                                                                                      
                                           
                                           
          
                   
                   }
         }
          getch();
          }
          
         
                       
