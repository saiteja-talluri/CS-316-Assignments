//tests single function definition-calling (no decl)

int a,b;
float c;
int x;

int func1(int i1,int i2,float f1){
	
	i1=i1+i2;
	print f1;
	return i1;
	print f1;
}

void main(){
	a=7;b=3;
	c=3.5;
	x=func1(a,b,c);
	print x;
}

