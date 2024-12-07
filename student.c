#include<stdio.h>
struct student{
		char name[20];
		int rn;
		float cgpa;
	};
int scmp(char str1[],char str2[]);
struct student *search(struct student l[],char s[20]);
int num=5;//number of students
int main(){
	struct student A[num];
	//accepting inputs for num students
	int i;
	for(i=0;i<num;i++){
		fflush(stdin);
		printf("Enter student name:");
		gets(A[i].name);
		printf("Enter your roll no:");
		scanf("%d",&A[i].rn);
		printf("Enter cgpa:");
		scanf("%f",&A[i].cgpa);
		printf("\n");
	}
	//searching for string
	char sch[20];
	fflush(stdin);
	printf("Enter name for search:");
	gets(sch);
	struct student *p=search(A,sch);
	//display findings
	printf("Name:%s\n",(*p).name);
	printf("RollNo:%d\n",(*p).rn);
	printf("CGPA:%f\n",(*p).cgpa);
	return 0;
}


struct student *search(struct student l[],char s[20]){
	int i=0,flag=0;
	for(i;i<num;i++){
		if(scmp(l[i].name,s)==0){
			flag=1;//student found
			break;
		}
	}
	if(flag==1){
		return &l[i];	
	}
	else{
		static struct student blank={"",0,0.0};//very important
		//here we cant do blank.name="";
		/*made it static as its locally created and we want it to be
		available to main funtion too ie dont want it to be deleted after
		execution of search() function*/
		return &blank;
	}	
}


//created a funtion for comparing two strings
int scmp(char str1[],char str2[]){
	int i,flag=0;
	for(i=0;;i++){
		if(str1[i]!=str2[i]){
			flag=1;
			break;
		}
		if(str1[i]==str2[i]&&str1[i]=='\0'){
			break;
		}
	}
	if(flag==0)return 0;//strings are same
	else return 1;//strings are different	
}

