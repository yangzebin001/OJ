#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main(){
	string a;
	int count[26] = {0};
	int maxdig = 0,maxind=0;
	for(int i = 0;i < 4; i++){
		getline(cin,a);
		for(int j = 0; j < a.size(); j++){
			count[a[j]-'A']++;
		} 
	}
	for(int i = 0; i < 26; i++){
		if(count[i] > maxdig){
			maxdig = count[i];
			maxind = i;
		}
	}

	int last = maxind;
	for(int i = 0; i < maxdig; i++){
		for(int j = 0; j < 26; j++){
			for(int k = j; k < 26; k++){
				if(k >= last && count[k] >= maxdig-i){
					last = k;
				}
			}
			
			if(j <= last){
				if(count[j] < maxdig-i){
					printf(" ");
				}else{
					printf("*");
				}
				if(j != last){
					printf(" ");
				}
			}
		}
		printf("\n");
	} 
	
	for(int i = 0; i < 26; i++){
		if(i != 0){
			printf(" ");
		}
		printf("%c",i+'A');
	}
	return 0;
}
