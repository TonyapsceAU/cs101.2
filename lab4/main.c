#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int RangedRand(int range_min, int range_max){
    int r = ((double)rand() / RAND_MAX) * (range_max - range_min) + range_min;
    return r;
}

int* get_target_index(int arr[], int num, int want){
    for(int i=0;i<num;i++){
        if(arr[i]== want){
            return &arr[i];
        }
    }
}

int main(){
    srand(time(NULL));

    int amount = 10;
    int target;
    int n[amount];
    int rec[amount];
    int* ap[amount];
    int small;
    int* p;
    
    for(int i=0;i<amount;i++){
        n[i] = RangedRand(0,100);
        rec[i] = n[i];
        printf("%d,",n[i]);
    }
    
    printf("\ntarget : ");
    scanf("%d",&target);
    printf("\n\n\n\n");
    
    p = get_target_index(n,amount,target);
    int j = 0;
    for(j;j<amount;j++){
        if(*p == n[j]){
            break;
        }
    }
    printf("\nNo.1 --------------------\n");
    printf("&n[%i]->%p, n[%i]=%i; p->%p, *p=%i",j,p,j,*p,p,*p);
    printf("\nNo.2 --------------------");
    
    
    for(int i=0;i<amount;i++){
        small = rec[0];
        for(int j=0;j<amount;j++){
            if(rec[j] < small){
                small = rec[j];
            }
        }
        for(int j=0;j<amount;j++){
            if(rec[j] == small){
                ap[i] = &n[j];
                rec[j] = 101;
                break;
            }
        }
        
    }
    
    
    
    for(int i=0;i<amount;i++){
        int j = 0;
        for(j;j<amount;j++){
            if(*ap[i] == n[j]){
                break;
            }
        }
        printf("\n&n[%i]->%p, n[%i]=%i; ap[%i]->%p, *ap[%i]=%i",j,ap[i],j,*ap[i],i,ap[i],i,*ap[i]);
    }

    return 0;
}


