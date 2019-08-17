#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 200001;
int N,K,M;

struct student{
    int id;
    int score[6] = {-2,-2,-2,-2,-2,-2};
    int c = 0;
};
student users[MAXN];
int fullscore[6] = {0};

int gettotalscore(const student &a){
    int ans = 0;
    for(int j = 0; j < K; j++){
        if(a.score[j] > 0) ans += a.score[j];
    }
    return ans;
}
int getfullnum(const student &a){
    int n = 0;
    for(int j = 0; j < K; j++){
        if(a.score[j] == fullscore[j]) n++;
    }
    return n;
}

int getnozeronum(const student &a){
    int n = 0;
    for(int j = 0; j < K; j++){
        if(a.score[j] >= 0) n++;
    }
    return n;
}

bool cmp(const student &a, const student &b){
    if(gettotalscore(a) == gettotalscore(b)){
        if(b.c == a.c){
            return a.id < b.id;
        }
        return a.c > b.c;
    }
    return gettotalscore(a) > gettotalscore(b);
}

int main(){
    scanf("%d%d%d",&N,&K,&M);
    for(int i = 0; i < K; i++){
        scanf("%d",&fullscore[i]);
    }
    for(int i = 0; i < M; i++){
        int ith,si,s;
        scanf("%d%d%d",&ith,&si,&s);
        // if(s < 0) s = 0;
        users[ith].id = ith;
        users[ith].score[si-1] = max(users[ith].score[si-1],s);
        if(users[ith].score[si-1] == fullscore[si-1]) users[ith].c++;
    }
    sort(users+1,users+N+1,cmp);
    int qq = 0;
    int curs = 0;
    int z = 0;
    for(int i = 1; i <= N; i++){
        int ts = gettotalscore(users[i]);
        if(ts < 0 || getnozeronum(users[i]) == 0){
            z++;
            continue;
        }
        if(curs != ts){
            curs = ts;
            qq = i-z;
        }
        printf("%d %05d %d",qq,users[i].id,ts);
        for(int j = 0; j < K; j++){
            printf(" ");
            if(users[i].score[j] >= 0){
                printf("%d",users[i].score[j]);
            }else if(users[i].score[j] == -1){
                printf("0");
            }else{
                putchar('-');
            }
        }
        printf("\n");
    }
    return 0;
}

// 9 4 22
// 20 25 25 30
// 00002 2 12
// 00007 4 17
// 00005 1 19
// 00007 2 25
// 00005 1 20
// 00002 2 2
// 00005 1 15
// 00001 1 18
// 00004 3 25
// 00002 2 25
// 00005 3 22
// 00006 4 -1
// 00001 2 18
// 00002 1 20
// 00004 1 15
// 00002 4 18
// 00001 3 4
// 00001 4 2
// 00005 2 -1
// 00004 2 0
// 00008 2 0
// 00009 3 0