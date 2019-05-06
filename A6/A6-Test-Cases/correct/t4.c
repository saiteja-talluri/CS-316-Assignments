//tests while

void main(){
	int counter;
	int i;
	int sum;
	float f;
	float sumf; 

	f=1.0;
	counter=1;
	sumf=0.0;
	while(counter<=11){
		sumf=sumf+f;
		f=f+2.0;
		counter=counter+1;
	}
	print sumf;

	i=1;
	counter=1;
	sum=0;
	while(counter<11){
		sum=sum+i*i;
		i=i+1;
		counter=counter+1;
	}
	print sum;
	
}
