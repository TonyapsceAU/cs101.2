#include <stdio.h>
int _sum(int x,int y){
    int ans = x + y;
    return ans;
}

int _sub(int x,int y){
    int ans = x - y;
    return ans;
}

int _mult(int x,int y){
    int ans = x * y;
    return ans;
}

int _div(int x,int y){
    int ans = x / y;
    return ans;
}

int _pow(int x,int y){
    int ans = 1;
    for(int i=0;i<y;i++){
        ans *= x; 
    }
    return ans;
}





int main(){
    int x,y,choice;
    int (*ope[5])(int ,int);
    ope[0] = _sum;
    ope[1] = _sub;
    ope[2] = _mult;
    ope[3] = _div;
    ope[4] = _pow;
    
    printf("Enter 2 integer :");
    scanf("%d %d",&x,&y);
    
    printf("Enter 0 to 4 ( 0:+;1:-;2:*;3:/;4:^) :");
    scanf("%d",&choice);
    
    printf("result : %d",ope[choice](x,y));
    
    
    return 0;
}

