#include<stdio.h>
int moveCount=0;
void tower(int,char,char,char);
void main()
{
  	int n;
  	printf("Enter the no.of discs\n");
  	scanf("%d",&n);
 	tower(n,'S','D','T');
    printf("Total moves: %d\n", moveCount);
    return 0;
 }
 void tower(int n,char from,char to,char temp)
 {
  	 if(n==0)
   		return;
  	 else
  	 {
    		 tower(n-1,from,temp,to);
    		 printf("Move disc %d from %c to %c\n",n,from,to);
    		 moveCount++;
    		 tower(n-1,temp,to,from);
   	}
 }
