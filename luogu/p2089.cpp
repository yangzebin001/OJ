#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector< vector<int> > v;
int main(){
    int n;
    scanf("%d",&n);

    for(int a = 1; a < 4; a++){
        for(int b = 1; b < 4; b++){
            for(int c = 1; c < 4; c++){
                for(int d = 1; d < 4; d++){
                    for(int e = 1; e < 4; e++){
                        for(int f = 1; f < 4; f++){
                            for(int g = 1; g < 4; g++){
                                for(int h = 1; h < 4; h++){
                                    for(int i = 1; i < 4; i++){
                                        for(int j = 1; j < 4; j++){
                                            if(a + b + c + d + e + f + g + h + i + j == n){
                                                vector<int > z;
                                                z.push_back(a);
                                                z.push_back(b);
                                                z.push_back(c);
                                                z.push_back(d);
                                                z.push_back(e);
                                                z.push_back(f);
                                                z.push_back(g);
                                                z.push_back(h);
                                                z.push_back(i);
                                                z.push_back(j);
                                                v.push_back(z); 
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            
            }
        }
    }
    printf("%d\n",v.size());
    for(int i = 0;i < v.size(); i++){
        for(int j = 0; j < v[i].size(); j++){
            if(j != 0) printf(" ");
            printf("%d",v[i][j]);
        }
        printf("\n");
    }
    return 0; 
}