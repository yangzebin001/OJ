#include<iostream>
#include<set>
#include<string>

using namespace std;

string deleteonechar(string a, int index){
	string b = a.replace(index,1,"");
	return b;
} 

int main(){
	string data;
	set<string> s1,s2,s3;
	int cot = 1;
	
	cin >> data;
	for(int i = 0; i < data.size(); i++){
		s1.insert(deleteonechar(data,i));
	}
		
	for(std::set<string>::iterator it = s1.begin(); it !=s1.end(); it++){
		for(int i = 0; i < (*it).size(); i++){
			s2.insert(deleteonechar(*it,i));
		}
	}
	for(std::set<string>::iterator it = s2.begin(); it !=s2.end(); it++){
		for(int i = 0; i < (*it).size(); i++){
			s3.insert(deleteonechar(*it,i));
		}
	}

//	for(std::set<string>::iterator it = s3.begin(); it !=s3.end(); it++){
//		cout << *it <<endl;
//	}
	
	cout << cot + s1.size() + s2.size() + s3.size();
	return 0;
} 

