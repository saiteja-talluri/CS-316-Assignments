//tests recursion

int fibonacci(int a)
{
    int ans;
    int a1,a2;
    if(a == 0 || a == 1)
    {
    	ans = 1;
       return ans;
    }
    

    a1=a-1;
    a1 = fibonacci(a1);

    a2=a-2;
    a2 = fibonacci(a2);
    
    ans = a1+a2;

    return ans;
    
}


void main()
{   
    int b;
    int res;
    b=4;
    res = fibonacci(b);
    print res;
}



