#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM 100 //The total number of people who sit around a table in a circle .
#define REP 16  //The counting number the REP-th person who calls this number will leave the table .

int *jos(int n,int rec)
{
    int a[n+1],b[n],i,j=1;   //From a[1] to a[n] is the number of 1 to n; and the numbers from b[0] to b[n-1] is the result of Josephus permutation.
    int *pio=a;
    a[0]=999;              //The count begins at 0(zero),and the next count is 1.a[0] can be assigned any value beyong 0 and NUM.
    for(i=1;i<=n;i++){    //Assign the value from 1 to n to a[1]......a[n] respectively .
	    pio++;
	    *pio=i;
    }
   
    pio=&a[0];         //Initialize *pio.

   for(i=0;i<n+1;i++){
      
       for(j=1;j<=rec;j++){
	       if(i==n)
			  break;        //Once i=n,
		   if(pio==&a[n+1])
	          pio=&a[1];   //When the counting comes to the end a[n+1] , it should restart from a[1].
	       else
   	          pio=pio+1;    
	       //printf("%ld\t",(pio-&a[0]));

/*Psb. 1*/if((pio==&a[n+1])&&(a[n+1]==0)){  //When the counting comes to the end a[n+1] , and a[n+1]=0, the counting should be canceled , and restart from a[1]
	           pio=&a[0];
	           j=j-1;
	       } 

/*Psb. 2*/else if((pio==&a[n+1])&&(a[n+1]!=0)&&(j!=rec)) //When the counting comes to the end a[n+1] ,a[n+1]!=0,and j<rec , it restarts from a[1]
     	           pio=&a[0];	   
	       
/*Psb. 3*/else if((pio==&a[n+1])&&(a[n+1]!=0)&&(j==rec)){
	               b[i]=*pio;
		           *pio=0;                               //Once the counting number(REP)comes to a person , we set the value to zero .
   	               j=1;                   
		           break;
	      }

/*Psb. 4*/else if(*pio==0){
	           j=j-1;
	      }

/*Psb. 5*/else if((j==rec)&&(pio!=&a[n+1])){
		          b[i]=*pio;
		          *pio=0;
		          j=1;	                         
		          break;
	      }
	   }	      
    }
   for(i=0;i<n;i++)
       if(i%10==9)
		  printf("b[%d]=%d\n",i,b[i]);
       else                                    
          printf("b[%d]=%d  ",i,b[i]);  //Print b[], 10 numbers per row.
    //pio = (int *)malloc(sizeof(int)*n);
    //pio=b;
    return pio;
}

int main(void)
{
    clock_t start, end;
	start = clock();    // Time on.

	if(REP>NUM){
	   printf("ERROR !\nThe counting number is bigger than the total number of people !\n ");
	   return 1;             
	}

	int *mp,i=0;

	mp = jos(NUM,REP);

	/*for(i=0;i<NUM;i++){
        if(i%10==9)
		  printf("%d\n",*mp);
        else                                    
          printf("%d  ",*mp); 
		mp++;
	}*/
    free(mp);
	end = clock();   //Time off .
    printf("time=%.4f\n", (double)(end - start) / CLOCKS_PER_SEC);	
	return 0;
}
