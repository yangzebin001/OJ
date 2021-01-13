#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<string> container;
int main(){
    int n;
    cin >> n;
    string op, name;
    while(n--){
        cin >> op;
        if(op == "touch"){
            cin >> name;
            int f = 0;
            for(int i = 0; i < container.size(); i++){
                if(container[i] == name){
                    f = 1;
                    break;
                }
            }
            if(f == 0) container.push_back(name);
        }else if(op == "rm"){
            cin >> name;
            for(int i = 0; i < container.size(); i++){
                if(container[i] == name){
                    container.erase(container.begin()+i);
                    break;
                }
            }
        }else if(op == "ls"){
            for(int i = 0; i < container.size(); i++){
                cout << container[i] << endl;
            }
        }else if(op == "rename"){
            string newname;
            cin >> name >> newname;
            int oldidx = -1, newidx = -1;
            for(int i = 0; i < container.size(); i++){
                if(container[i] == name){
                    oldidx = i;
                }
                if(container[i] == newname){
                    newidx = -1;
                }

            }
            if(oldidx != -1 && newidx == -1) container[oldidx] = newname;
        }
    }
    return 0;
}