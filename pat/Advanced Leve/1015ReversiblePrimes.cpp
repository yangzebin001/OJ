#include<iostream>
#include<string>
#include<cmath>
using namespace std;


int revers(int n){
	int ans = 0;
	while(n){
		ans = ans * 10 + n%10;
		n /= 10; 
	}
	return ans;
}

bool isPrime(int n){
	for(int i = 2; i*i <= n; i++){
		if(n % i == 0) return false;
	}
	return true;
} 
int toD(int n,int d){
	int ans = 0;
	while(n){
		ans *= 10;
		ans += n%d;
		n/=d;
	}
	return ans;
}
int to10(int n,int d){
	int ans = 0;
	int i = 0;
	while(n){
		ans = ans + (n%10)*pow(d,i++);
		n/=10;
	}
	return ans;
}
int main(){
	int a,n;
	cin >> a; 
	while(a >= 0){
		cin >> n;
		int ans1 = toD(a,n);
		int ans2 = to10(ans1,n);
//		cout << a << " " << ans2 << endl;
		if(a == 1 || a == 0 || ans2 == 0 || ans2 == 1){
			cout << "No" << endl;
		}else
		if(isPrime(a) && isPrime(ans2)){
			cout << "Yes" << endl;
		}else{
			
			cout << "No" << endl;
		}
		cin >> a; 
	}
	
	return 0;
}
