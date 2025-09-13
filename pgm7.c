/*program to display all possible pythagorean triplets
whose side length is <= length entered by user*/
#include<stdio.h>
#include<math.h>

int perfect(float n){
	/*basically checks if float square root
	has decimal places or not*/
	int i=(int)n;
	float diff=n-i;
	if(diff==0.0)return 0;//perfect root
	else return 1;//not perfect	root
}

int main(){
	int i,j,num;
	printf("Enter number:");
	scanf("%d",&num);
	printf("All possible pythagorean triplets with side less than %d:\n",num);
	for(i=1;i<=num;i++){
		for(j=i/*very imp*/;j<=num;j++){
			if(j==i)continue;
			else{
				int x=pow(i,2)+pow(j,2);
				float r=sqrt(x);
				int res=perfect(r);
				if(res==0&&(int)r<=num)printf("%d %d %d\n",i,j,(int)r);			
		    }
	    }
    }
	return 0;
}
