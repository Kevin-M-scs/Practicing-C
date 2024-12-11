#include<stdio.h>
/*this program counts the number of times the search word occurs 
in a given sentence, it has been built to tackle any
number of spaces between words and will even work if spaces
are present at the end of the sentence*/
int main(){
	char s[]="hello";//search string
	char str[]="hello       today  is    saturday hello bye  hello ";//sentence
	int count=0;
	int i;
	for(i=0;i<sizeof(str)-1;i++){
		/*the below condition ignores unecessary characters 
		at string beginning*/
		int j=i;//important line if string begins with spaces
		if((str[i]>='A'&&str[i]<='Z')||(str[i]>='a'&&str[i]<='z')){
			int c=0;//index for search string iteration
			int flag=0;
			for(j;;j++){
				if((str[j]==' '&&s[c]=='\0')||(str[j]=='\0'&&s[c]=='\0')){
					count++;
					break;
				}
				//crucial that this if block comes 2nd
				if(str[j]!=s[c]){
					break;
					flag=1;
				}
				c++;
		    }
		}
	    //getting i to the index of the next word
	    if(str[j]=='\0')break;//if search word was last word
	    else{
	    	//go to the next space
	    	for(j;;j++){
	    		if(str[j]==' '){
	    			i=j;//dont do +1 as the for loop does that automatically
	    			break;
				}
				//if you reached last word
				if(str[j]=='\0')break;	
			}
		}
    }  
    printf("\n");
	printf("value of count is %d",count);
	return 0;
}