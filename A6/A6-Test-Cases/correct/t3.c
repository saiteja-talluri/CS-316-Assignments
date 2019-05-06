//tests if else elseif

void main(){
	int i1,i2,i3;
	float f1;
	int val;
	i1=5;i2=3;i3=1;
	f1=0.5;
	val=10;
	
	if (i1==5 && (i2==3 || i3==0)){
		val=20;
	}
	else if(i3==1){
		val=30;
	}
	print val;


	if(f1<=0.4){
		val=40;
	}
	else if(f1!=0.5){
		val=50;
	}
	else{
		val=60;
	}
	print val;
}
