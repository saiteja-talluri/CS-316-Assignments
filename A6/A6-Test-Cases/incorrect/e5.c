// multiple declaration of functions

int x;
int a,b;

int func1(int a,int b){
	return a;
}

int func1(int a,int b){
	return b;
}

void main(){
	a=1;b=2;
	int x;
	x=func1(a,b);
	print x;

}