//tests nth prime number

int isPrime(int n){
	int ans;
	int i;
	int j;
	int prod;
	if(n<2){return 0;}
	ans=1;
	i=2;
	while(i<n){
		j=i;
		prod=i*j;
		while(prod<=n){
			if(prod==n){ans=0;}
			j=j+1;
			prod=i*j;
		}
		i=i+1;
	}
	return ans;
}

void main(){
	int i;
	int ans;

	i=23;
	ans = isPrime(i);
	print ans;

	i=97;
	ans = isPrime(i);
	print ans;

	i=101;
	ans = isPrime(i);
	print ans;

	i=1001;
	ans = isPrime(i);
	print ans;

	i=123;
	ans = isPrime(i);
	print ans;

	i=129;
	ans = isPrime(i);
	print ans;

	i=41;
	ans = isPrime(i);
	print ans;

	i=49;
	ans = isPrime(i);
	print ans;

	i=51;
	ans = isPrime(i);
	print ans;

	i=53;
	ans = isPrime(i);
	print ans;
	
	

}
