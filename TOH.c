#include <stdio.h>
#include <stdlib.h>//for system() function

void toh(char,char);
void display(int A1[],int A2[],int A3[]);
int top(int A[]);
int topindex(int A[]);
int transfer(int A1[],int A2[]);

int t1[]={1,2,3};//L
int t2[]={0,0,0};//C
int t3[]={0,0,0};//R

int main()
{
    printf("Welcome\n");
    printf("Enter x x for exit during runtime\n");
    printf("Tower names are L,C and R\n");
    display(t1,t2,t3);
    char c1='A',c2='B';
    while(c1!='x'&&c2!='x'){
    	printf("Enter tower1 tower2:");
    	scanf(" %c %c",&c1,&c2);
    	system("cls");
    	toh(c1,c2);
    	display(t1,t2,t3);
	}
	printf("EXITED\n");
	return 0;
}

int top(int A[]){
	int i;
	for(i=0;i<3;i++){
		if(A[i]!=0){
			return A[i];
		}
	}
	return 0;
}

int topindex(int A[]){
	int i;
	for(i=0;i<3;i++){
		if(A[i]!=0){
			return i;
		}
	}
	return 2;
}

int transfer(int A1[],int A2[]){
	//return 0 for success
	//return 1 for invalid move
	int a=top(A1);
	int i;
	for(i=0;i<3;i++){
		if(A2[i]!=0){
			if(a<A2[i]){
				A2[i-1]=a;
				break;
			}
			else{
				//invalid move
				return 1;
			}
		}
		else if(i==2){
			A2[2]=a;
		}	
	}
	int t;
	t=topindex(A1);
	A1[t]=0;
	return 0;
}

void toh(char r1,char r2){
	if(r1=='L'&&r2=='C'){
		int a=top(t1);
		if(a==0){
			printf("Rod %c is empty\n",r1);
			return;
		}
		else{
			int r=transfer(t1,t2);
			if(r==1){
				printf("Invalid Move\n");
				return;
			}	
		}
	}
	else if(r1=='C'&&r2=='L'){
		int a=top(t2);
		if(a==0){
			printf("Rod %c is empty\n",r1);
			return;
		}
		else{
			int r=transfer(t2,t1);
			if(r==1){
				printf("Invalid Move\n");
				return;
			}
	    }
	}
	else if(r1=='L'&&r2=='R'){
		int a=top(t1);
		if(a==0){
			printf("Rod %c is empty\n",r1);
			return;
		}
		else{
			int r=transfer(t1,t3);
			if(r==1){
				printf("Invalid Move\n");
				return;
			}
	    }	
	}
	else if(r1=='R'&&r2=='L'){
		int a=top(t3);
		if(a==0){
			printf("Rod %c is empty\n",r1);
			return;
		}
		else{
			int r=transfer(t3,t1);
			if(r==1){
				printf("Invalid Move\n");
				return;
			}
	    }	
	}
	else if(r1=='C'&&r2=='R'){
		int a=top(t2);
		if(a==0){
			printf("Rod %c is empty\n",r1);
			return;
		}
		else{
			int r=transfer(t2,t3);
			if(r==1){
				printf("Invalid Move\n");
				return;
			}
	    }	
	}
	else if(r1=='R'&&r2=='C'){
		int a=top(t3);
		if(a==0){
			printf("Rod %c is empty\n",r1);
			return;
		}
		else{
			int r=transfer(t3,t2);
			if(r==1){
				printf("Invalid Move\n");
				return;
			}
	    }	
	}
	else{
		if(r1!='x'&&r2!='x')printf("Combination Not Recognized\n");
	}
	return;//of toh
}

void display(int A1[],int A2[],int A3[]){
	//row 1 topmost
	if(A1[0]==1)printf("  *    |        |       \n");
	else if(A2[0]==1)printf("       |   *    |       \n");
	else if(A3[0]==1)printf("       |        |   *   \n");
	else printf("       |        |       \n");
	//row 2 middle
	if(A1[1]==1)printf("  *    |        |       \n");
	else if(A2[1]==1)printf("       |   *    |       \n");
	else if(A3[1]==1)printf("       |        |   *   \n");
	else if(A1[1]==2)printf(" ***   |        |       \n");
	else if(A2[1]==2)printf("       |  ***   |       \n");
	else if(A3[1]==2)printf("       |        |  ***  \n");
	else printf("       |        |       \n");
	//row 3 bottom most
	// permutations of 1,2,3
	if(A1[2]==1&&A2[2]==2&&A3[2]==3)printf("  *    |  ***   | ***** \n");
	else if(A1[2]==1&&A2[2]==3&&A3[2]==2)printf("  *    | *****  |  ***  \n");
	else if(A1[2]==2&&A2[2]==1&&A3[2]==3)printf(" ***   |   *    | ***** \n");
	else if(A1[2]==2&&A2[2]==3&&A3[2]==1)printf(" ***   | *****  |   *   \n");
	else if(A1[2]==3&&A2[2]==1&&A3[2]==2)printf("*****  |   *    |  ***  \n");
	else if(A1[2]==3&&A2[2]==2&&A3[2]==1)printf("*****  |  ***   |   *   \n");
	//permutations of 3,1,0
	else if(A1[2]==1&&A2[2]==3&&A3[2]==0)printf("  *    | *****  |       \n");
	else if(A1[2]==1&&A2[2]==0&&A3[2]==3)printf("  *    |        | ***** \n");
	else if(A1[2]==3&&A2[2]==1&&A3[2]==0)printf("*****  |   *    |       \n");
	else if(A1[2]==3&&A2[2]==0&&A3[2]==1)printf("*****  |        |   *   \n");
	else if(A1[2]==0&&A2[2]==1&&A3[2]==3)printf("       |   *    | ***** \n");
	else if(A1[2]==0&&A2[2]==3&&A3[2]==1)printf("       | *****  |   *   \n");
	//permutations of 2,3,0
	else if(A1[2]==3&&A2[2]==0&&A3[2]==2)printf("*****  |        |  ***  \n");
	else if(A1[2]==3&&A2[2]==2&&A3[2]==0)printf("*****  |  ***   |       \n");
	else if(A1[2]==2&&A2[2]==0&&A3[2]==3)printf(" ***   |        | ***** \n");
	else if(A1[2]==2&&A2[2]==3&&A3[2]==0)printf(" ***   | *****  |       \n");
	else if(A1[2]==0&&A2[2]==2&&A3[2]==3)printf("       |  ***   | ***** \n");
	else if(A1[2]==0&&A2[2]==3&&A3[2]==2)printf("       | *****  |  ***  \n");
	//permutations of 3 alone, ie 1 and 2 are on 3
	else if(A1[2]==3&&A2[2]==0&&A3[2]==0)printf("*****  |        |       \n");
	else if(A1[2]==0&&A2[2]==3&&A3[2]==0)printf("       | *****  |       \n");
	else if(A1[2]==0&&A2[2]==0&&A3[2]==3)printf("       |        | ***** \n");
	else{
		printf("Check if some combination is missing in bottom row\n");
	}	
}
   