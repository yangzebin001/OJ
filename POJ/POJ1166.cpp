#include<cstdio>

using namespace std;

int m[20];
int i1,i2,i3,i4,i5,i6,i7,i8,i9;
int num[20];
int main(){
    freopen("in.txt","r",stdin);
    for(int i = 0; i <9; i++){
            scanf("%d",&m[i]);
    }
    for(i1 = 0; i1 < 4; i1++){
        for(i2 = 0; i2 < 4; i2++){
            for(i3 = 0; i3 < 4; i3++){
                for(i4 = 0; i4 < 4; i4++){
                    for(i5 = 0; i5 < 4; i5++){
                        for(i6 = 0; i6 < 4; i6++){
                            for(i7 = 0; i7 < 4; i7++){
                                for(i8 = 0; i8 < 4; i8++){
                                    for(i9 = 0; i9 < 4; i9++){
                                        num[0] = (m[0] + i1+i2+i4)%4;
                                        num[1] = (m[1] + i1+i2+i3+i5)%4;
                                        num[2] = (m[2] + i2+i3+i6)%4;
                                        num[3] = (m[3] + i1+i4+i5+i7)%4;
                                        num[4] = (m[4] + i1+i3+i5+i7+i9)%4;
                                        num[5] = (m[5] + i3+i5+i6+i9)%4;
                                        num[6] = (m[6] + i4+i7+i8)%4;
                                        num[7] = (m[7] + i7+i8+i5+i9)%4;
                                        num[8] = (m[8] + i6+i8+i9)%4;
                                        int sum = 0;
                                        for(int i = 0; i < 9; i++){
                                            sum += num[i];
                                        }
                                        if(sum == 0){
                                            for(int j = 1; j <=i1; j++){
                                                printf("%d ",1);
                                            }
                                            for(int j = 1; j <=i2; j++){
                                                printf("%d ",2);
                                            }
                                            for(int j = 1; j <=i3; j++){
                                                printf("%d ",3);
                                            }
                                            for(int j = 1; j <=i4; j++){
                                                printf("%d ",4);
                                            }
                                            for(int j = 1; j <=i5; j++){
                                                printf("%d ",5);
                                            }
                                            for(int j = 1; j <=i6; j++){
                                                printf("%d ",6);
                                            }
                                            for(int j = 1; j <=i7; j++){
                                                printf("%d ",7);
                                            }
                                            for(int j = 1; j <=i8; j++){
                                                printf("%d ",8);
                                            }
                                            for(int j = 1; j <=i9; j++){
                                                printf("%d ",9);
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
    return 0;
}