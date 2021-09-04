#include <stdio.h>

int fact(int);

int main() {
	int t,n,x;
	scanf("%d",&t);
	while(t-->0){
	scanf("%d",&n);
	x=fact(n);
	printf("%d",x);
	}
	return 0;
}

int fact(int n){
    if(n==1){
        return n;
    }else{
        n=n*fact(n-1);
        return n ;
    }
}
