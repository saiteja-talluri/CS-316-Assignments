// different argument types in calling and definition of same function

int x;
int a,b;

int func1(float a,int b);

int func1(float a,int b){
	return b;
}

void main(){
	a=1;b=2;
	x=func1(a,b);
	print x;

}