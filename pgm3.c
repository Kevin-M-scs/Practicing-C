#include<stdio.h>
/*Menu driven program using structures storing name,
roll no and cg.Includes operations like search and display*/
typedef struct{
	char name[20];
	int roll_no;
	float cgpa;
}student;

student search_name(char *str,student *B,int n);
student search_roll(int r,student *B,int n);
void gdisplay(float cg,student *B,int n);
int check(char *str1,char *str2);
/*gdisplay displays details of students with 
cg greater than entered lower limit*/

int main(){
	student A[100];
    int n,i;
	printf("Enter number of students:");
	scanf("%d",&n);
	//accepting input
	for(i=0;i<n;i++){
		printf("Name of student %d:",i+1);
		scanf("%s",A[i].name);
		printf("Roll No of student %d:",i+1);
		scanf("%d",&A[i].roll_no);
		printf("CGPA of student %d:",i+1);
		scanf("%f",&A[i].cgpa);	
	}
    //MENU
    int ch=256;
    printf("1.search name 2.Search roll 3.Cg greater than 4.EXIT\n");
    while(ch!=4){
    	printf("Enter choice: ");
    	scanf("%d",&ch);
    	if(ch==1){
    		char s[20];
            printf("Enter search name:");
            scanf("%s",s);
            student R=search_name(s,A,n);
            printf("Name:%s Roll:%d CGPA:%f\n",R.name,R.roll_no,R.cgpa);	
		}
		else if(ch==2){
			int s;
			printf("Enter roll no for search:");
			scanf("%d",&s);
			student R=search_roll(s,A,n);
			printf("Name:%s Roll:%d CGPA:%f\n",R.name,R.roll_no,R.cgpa);
		}
		else if(ch==3){
			float c;
			printf("Enter lower limit cg:");
			scanf("%f",&c);
			gdisplay(c,A,n);
			
		}
		else if(ch==4)printf("EXITED\n");
		else printf("Invalid Option\n");
	}
	return 0;
}

student search_name(char *str,student *B,int n){
	int i;
	for(i=0;i<n;i++){
		if(check(B[i].name,str)==1){
			return B[i];
		}
	}
	//if you reached here means name not found
	student blank={'\0',0,0.0};
	return blank;
	};
	
student search_roll(int r,student *B,int n){
	int i;
	for(i=0;i<n;i++){
		if(B[i].roll_no==r){
			return B[i];
		}
	}
	//if you reached here means rollno not found
	student blank={'\0',0,0.0};
	return blank;
}

void gdisplay(float cg,student *B,int n){
	int i,flag=0;
	for(i=0;i<n;i++){
		if(B[i].cgpa>cg){
			flag=1;
			printf("Name:%s Roll:%d CGPA:%f\n",B[i].name,B[i].roll_no,B[i].cgpa);
		}
	}
	if(flag==0)printf("No Student found\n");
}
	
int check(char *str1,char *str2){
	int i,r=0;
	for(i=0;;i++){
		if(str1[i]=='\0'&&str2[i]=='\0'){
			r=1;
			break;
		}
		if(str1[i]!=str2[i])break;
	}
	return r;
}
