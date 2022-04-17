#include <stdio.h>


typedef struct my_mm{
    int memory[10];
} my_mm_t;
int g_mem[10];
my_mm_t mms;


int* my_calloc(int n,int siz){
    int gap = 0;
    int front;
    int end;
    int st = 0;
    for(st;st<10;st++){
        int i = st;
        for(i;i<10;i++){
            if(mms.memory[i] == 0){
                front = i;
                break;
            }
        }
        if(i>=10){
            front = 10;
        }
        i = st;
        for(i;i<10;i++){
            if(mms.memory[i] != 0){
                end = i;
                break;
            }
        }
        if(i>=10){
            end = 10;
        }
        gap = end - front;
        // printf("%d\n",gap);
        if(gap>=siz){
            break;
        }
    }
    // printf("%d\n",st);
    if(st>=10){
        printf("mms:");
        for(int i=0;i<10;i++){
            printf("%d",mms.memory[i]);
        }
        printf("\n");
        return NULL;
    }
    
    if(front+siz>10){
        return NULL;
    }
    for(int i=0;i<n;i++){           
        for(int j=0;j<10;j++){ 
            if(j<siz){
                g_mem[front+j] = siz;
                mms.memory[front+i*siz+j] = 1; 
            }
        }
    }
    
    // printf("g_mem:");
    // for(int i=0;i<10;i++){
    //     printf("%d",g_mem[i]);
    // }
    // printf("\n");
    printf("mms:");
    for(int i=0;i<10;i++){
        printf("%d",mms.memory[i]);
    }
    printf("\n");
    
    return &g_mem[front];
}

void my_free(int *p){
    int temp = *p;
    for(int i=0;i<10;i++){
        if(g_mem[i] == temp){
            g_mem[i] = 0;
            mms.memory[i] = 0; 
        }
    }
    // printf("g_mem:");
    // for(int i=0;i<10;i++){
    //     printf("%d",g_mem[i]);
    // }
    // printf("\n");
    printf("mms:");
    for(int i=0;i<10;i++){
        printf("%d",mms.memory[i]);
    }
    printf("\n");
}


int main(){
    for(int i=0;i<10;i++){
        mms.memory[i] = 0;
    }
    
    int* np1 = my_calloc(1,1);
    int* np2 = my_calloc(1,2);
    int* np3 = my_calloc(1,3);
    int* np4 = my_calloc(1,4);
    my_free(np1);
    my_free(np4);
    int* np5 = my_calloc(1,5);
    int* np6 = my_calloc(1,1);

    return 0;
}




