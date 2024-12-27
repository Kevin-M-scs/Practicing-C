#include<stdio.h>
int main(){
	/*program to copy alternate lines
    from firstktm.txt and hello.txt into new.txt*/
	FILE *f1,*f2,*f3;
	f1=fopen("firstktm.txt","r");
	f2=fopen("hello.txt","r");
	f3=fopen("new.txt","w");
	
	int c1=0,c2=0;
	char c;
	int i;
	for(i=0;c1!=1&&c2!=1;i++){
		while(c1!=1){
	        if(fscanf(f1,"%c",&c)==EOF){
		        c1=1;
		        break;
	        }
	        else{
		       if(c!='.')fprintf(f3,"%c",c);
		       else{
		       	fprintf(f3,"%c",'.');
		       	break;
			   }
	        }
        }
        while(c2!=1){
	        if(fscanf(f2,"%c",&c)==EOF){
		        c2=1;
		        break;
	        }
	        else{
		       if(c!='.')fprintf(f3,"%c",c);
		       else{
		       	fprintf(f3,"%c",'.');
		       	break;
			   }
	        }
        }	
	}
	fclose(f1);
	fclose(f2);
	fclose(f3);	
	return 0;
}
