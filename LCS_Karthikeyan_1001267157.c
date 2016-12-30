//Karthikeyan Rajamani UTA ID:1001267157
//CSE 5311 Summer 2016
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char * argv [] ) {
	setvbuf(stdout, NULL, _IONBF, 0);
    char s1[100]="ACCGGTCGAGTGCGCGGAAGCCGGCCGAA";
    char s2[100]="GTCGTTCGGAATGCCGTTGCTCTGTAAA";
    if(argc>1){ 
    strcpy(s1,argv[1]);
    strcpy(s2,argv[2]);
    printf ("Using command line values s1=%s and s2=%s",s1,s2);
    }
    else printf("Using the default test values \ns1=%s\ns2=%s\n",s1,s2);
    int m=strlen(s1);
    int n=strlen(s2);
    int L[m+1][n+1];// create an array table with an extra row & column
	int i,j;
	printf("\n");
	for(i=0;i<=m;i++)
	{
		
		for(j=0;j<=n;j++)
		{
			
			if(i==0 || j==0) L[i][j]=0;
			else if(s1[i-1]==s2[j-1]) 
			{
				L[i][j]=L[i-1][j-1]+1;
				
			}
			else 
			{
				if (L[i-1][j]>L[i][j-1]) L[i][j]=L[i-1][j];
				else L[i][j]=L[i][j-1];
			}
			
	   }
	}   
printf("\n");
char option;
printf("Do you want to print the LCS table y/n:");
option=getchar();
if (option=='y'||option=='Y')
{
printf("The LCS table:\n");
for (i=0;i<=m;i++)
{

	for(j=0;j<=n;j++)
	{

		printf("%d",L[i][j]); // printing the formed table
		
	}

printf("\n");
	
}
}

int rc=L[m][n];//right corner element of the table
printf("The LCS value for string s1=%s and string s2=%s is=%d\n",s1,s2,rc);
i=m;// assign i to len(s1)
j=n;//assign j to len(s2)
char *result; // An array to hold the matched elements
result = malloc(rc+1);// assign it to the size of rightmost element+1

while(i>0 && j>0) // iterate from the right bottom of the formed table
{
	if (s1[i-1]==s2[j-1]) // if both elements match
	{
		result[rc-1]=s1[i-1];// add the matched chacter to the array
		i--;//move to upper throw
	    j--;//move the upper colum in the upper row(diagnol)
	    rc--;// change index of previous array
	    
	 }
	else 
	{
		if(L[i-1][j]>L[i][j-1]) i--;//move up on the same column
		else j--;//move to the previous column on the same row
	}
	
}

printf("\n");
printf("The LCS of s1=%s and s2=%s s3 is=%s\n",s1,s2,result);


}// end main

