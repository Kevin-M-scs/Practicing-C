#include <stdio.h>
/*Program to interchange words decided by user in a
string accepted as input*/
 int main(){
  	char s[100];//100 characters cap
  	printf("Enter desired string:");
  	fgets(s,100,stdin);
  	printf("\n");
  	printf("Original string:%s\n",s);
  	int i;
  	/*finding index of last character
  	and replacing \n at end(due to fgets()) with '\0'*/
  	int l;
  	for(i=0;;i++){
  		if(s[i]=='\0'){
  			l=i-2;
  			s[i-1]='\0';
  			break;
		  }
	}
  	int c=0;
	//space counter
  	for(i=0;i<=l;i++){
  		if(s[i]==' ')c++;
  	}
	
  	char *A[c+1];//an array of character pointers
  	A[0]=s;
  	int j=1;
	
  	for(i=0;i<=l;i++){
  		if(s[i]==' '){
  			A[j]=&(s[i+1]);//A[] stores decreasing parts of the sentence
  			j++;
  		}
  	}
  	/*cutting of the extra words in each
  	element of A so that we get only the 
  	first word from each substring presently present 
  	in A by inserting null characters*/
      for(j=0;j<c+1;j++){
      	char *p;
          p=A[j];
          while(*p!=' '&&*p!='\0'){//added extra and condition to
      	    p++;                  //handle last word
  	    }
  	    *p='\0';
  	}
  	int w1,w2;
  	printf("Enter word1 word2 to be interchanged:");
  	scanf("%d%d",&w1,&w2);
  	printf("\n");
  	
  	//swapping the words according to user input
  	char*temp;
  	temp=A[w1-1];
  	A[w1-1]=A[w2-1];
  	A[w2-1]=temp;
	printf("Final String:");
  	for(i=0;i<c+1;i++){
  		printf("%s ",A[i]);
  	}
  	/*this program modifies the original string by inserting
  	null characters in between*/
  	return 0;
  }
