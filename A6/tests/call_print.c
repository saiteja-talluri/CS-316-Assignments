int a,b,c;
float x,y,z;

int f1(int,int,int);

int f2(int a){
    int c;
    float x;
	if(a == 1)
		return 1;
	else{
        // c = f1(a-1, a*a, a);
        c = a*c;
        return c;
    }
    return 1;
}   

int f1(int p, int q) {
    return (p+q)*(p+q);
}

float maina(float a, int b) {
    float x;
    x = a;
    c = f1(b,b);
    return x*x;
}

void main() {
    int a,b,c,d;
    float e;
    a = 1;
    b = 3;
    // c = f1(a, b);
    d = f2(b);
    print c;
    print d;
    e = maina(2.0,1);
    print e;
}



