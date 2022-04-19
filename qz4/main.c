#include <stdio.h>
#include <stdlib.h>

int swap_int(int* a,int* b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int swap_int_arr(int s[],int d[],int siz){
    for(int i=0;i<siz;i++){
        int temp = s[i];
        s[i] = d[i];
        d[i] = temp;
    }
}

int printarr(int arr[],int siz){
    printf("%d",arr[0]);
    for(int i=1;i<siz;i++){
        printf(",%d",arr[i]);
    }
    printf("]\n");
}

char* copy_string(char* s){
    int amount = 0;
    while(*(s+amount)) amount++;
    // printf("%d",amount);
    char* p = (char*)calloc(amount , sizeof(char) );
    for(int i=0;i<amount;i++){
        p[i] = *s++;
    }
    
    return p;
}

int main(){
    int n = 1;
    int m = 2;
    int siz = 10;
    int souce[10] = {0,9,8,7,6,5,4,3,2,1};
    int dest[10] = {10,20,30,40,50,60,70,80,90,100};
    char str[] = "IU!IU!IU!IU!";
    
    
    swap_int(&n,&m);
    printf("No#1 -----------\n");
    printf("after swap, n = %d, m = %d\n",n,m);
    printf("No#2 -----------\n");
    swap_int_arr(souce,dest,siz);
    printf("after swap array, source array = [");
    printarr(souce,siz);
    printf("after swap array, dest array = [");
    printarr(dest,siz);
    printf("No#3 -----------\n");
    char* cp_str = copy_string(str);
    printf("copy string = %s\n",cp_str);
    free(cp_str);

    return 0;
}

