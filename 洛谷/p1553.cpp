#include<iostream>
#include<string>

using namespace std;

void reverse(string &a){
	char temp;
	for(int i = 0; i < a.size()/2; i++){
		temp = a[i];
		a[i] = a[a.size()-1-i];
		a[a.size()-1-i] = temp;
	}
}

void removespaceatlast(string &a){
	int i = a.size();
	while(i > 1 && a[--i] == '0' ){
		a.resize(a.size()-1);
	}
}

int main(){
	string data;
	cin >> data;
	if(data.find('.') != string::npos){
		string b = data.substr(data.find('.')+1);
		string a = data.substr(0,data.find('.'));
		removespaceatlast(b);
		reverse(b);
		removespaceatlast(b);
		removespaceatlast(a);
		reverse(a);
		removespaceatlast(a);
		cout << a << "." << b;
	}else if(data.find('%') != string::npos){
		string a = data.substr(0,data.find('%'));
		removespaceatlast(a);
		reverse(a);
		removespaceatlast(a);
		cout << a << "%";
	}else if(data.find('/') != string::npos){
		string b = data.substr(data.find('/')+1);
		string a = data.substr(0,data.find('/'));
		removespaceatlast(b);
		reverse(b);
		removespaceatlast(b);
		removespaceatlast(a);
		reverse(a);
		removespaceatlast(a);
//		if(a == "0"){
//			cout << 0;
//		}else{
//			cout << a << "/" << b;
//		}
		cout << a << "/" << b;
		
	}else{
		removespaceatlast(data);
		reverse(data);
		removespaceatlast(data);
		cout << data ;
	}
	return 0;
} 
