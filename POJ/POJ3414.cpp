#include<iostream>
#include<cstdio>
#include<queue>
#include<string>
#include<utility>
using namespace std;

struct node{
    int a,b;
    string p;
    node(int _a,int _b,string _p):a(_a),b(_b),p(_p){

    }
};

/*full(1) ->> 1
full(2) --> 2
drop(1) ->> 3
drop(2) --> 4
pour(1,2) --> 5
pour(2,1) --> 6
*/

void print(string s){
    for(int i = 0; i <s.size(); i++){
        if(s[i] == '1'){
            printf("FILL(1)\n");
        }else if(s[i] == '2'){
            printf("FILL(2)\n");
        }else if(s[i] == '3'){
            printf("DROP(1)\n");
        }else if(s[i] == '4'){
            printf("DROP(2)\n");
        }else if(s[i] == '5'){
            printf("POUR(1,2)\n");
        }else if(s[i] == '6'){
            printf("POUR(2,1)\n");
        }
    }
}

/*full(1) ->> 1
full(2) --> 2
drop(1) ->> 3
drop(2) --> 4
pour(1,2) --> 5
pour(2,1) --> 6
*/
int flag = 0;
bool vis[200][200];
void bfs(int a,int b, int c){
    int step = 0;
    queue<node> q;
    q.push(node(0,0,""));
    while(q.size()){
        int len = q.size();
        for(int i = 0; i < len; i++){
            node cur = q.front();q.pop();
            if(cur.a == c || cur.b == c){
                printf("%d\n",step);
                print(cur.p);
                return;
            }
            if(vis[cur.a][cur.b]){
                continue;
            }
            vis[cur.a][cur.b] = 1;
            // full
            if(cur.a != a){
                q.push(node(a,cur.b,cur.p+"1"));
            }
            if(cur.b != b){
                q.push(node(cur.a,b,cur.p+"2"));
            }
            // drop
            if(cur.a != 0){
                q.push(node(0,cur.b,cur.p+"3"));
            }
            if(cur.b != 0){
                q.push(node(cur.a,0,cur.p+"4"));
            }
            // pour
            if(cur.a > 0 && cur.b != b){
                int x,y;
                if(cur.b + cur.a <= b){
                    x = 0;y = cur.b + cur.a;
                }else{
                    x = cur.a-(b-cur.b);
                    y = b;
                }

                q.push(node(x,y,cur.p+"5"));
            }

            if(cur.b > 0 && cur.a != a){
                int x,y;
                if(cur.b + cur.a <= a){
                    x = cur.b + cur.a; y = 0;
                }else{
                    x = a;
                    y = cur.b-(a-cur.a);
                }
                q.push(node(x,y,cur.p+"6"));
            }

        }
        step++;
    }
    flag = 1;
}

int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    bfs(a,b,c);
    if(flag == 1) printf("impossible");
    return 0;
}