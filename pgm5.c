#include<stdio.h>
#include<stdlib.h>
/*Creating a function which reads a string
and overcomes the shortfalls of %s format specifier*/
/*The function takes two inputs 1.address of a char pointer
2.address of integer where size of inputted string (excluding
final null character) is stored.*/
/*The pointer whose address is inputted will point to the
created string*/

void tstring(char **pt_p,int *pt_n);

int main(){
	
	char *p;int num;
	tstring(&p,&num);
	//display string
	printf("%s",p);
	return 0;
}

void tstring(char **pt_p,int *pt_n){
	printf("Enter your string:");
	char *ptr,c;
	int i,flag=0;
	for(i=1;;i++){
		if(i==1){
			scanf("%c",&c);
			if(c!='\n'){
				ptr=(char *)malloc(i);
		        ptr[i-1]=c;
			}
			else{
				flag=1;//indicates failure in reading
				/*as first character read was newline
				meaning user didnt input anything*/
				break;
			}
		}
		else{
			scanf("%c",&c);
		    if(c!='\n'){
		    	ptr=(char *)realloc(ptr,i);
		        ptr[i-1]=c;
			}
			else break;
		}	
	}
	ptr[i-1]='\0';
	if(flag==1){
		*pt_p=NULL;
		*pt_n=0;
	}
	else{
		*pt_p=ptr;
		*pt_n=i-1;
	}	
}
