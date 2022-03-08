#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int RangedRand(int range_min, int range_max){
    int r = ((double)rand() / RAND_MAX) * (range_max - range_min) + range_min;
    return r;
}

int print_num(FILE* name,int num[]){
    for(int i=0;i<7;i++){
        if(num[i]<10){
            fprintf(name,"0");
        }
        fprintf(name,"%d ", num[i]);
    }
    fprintf(name,"\n");
}



int main () {
    srand(time(NULL));

    time_t Time;
    time(&Time);
    FILE* fp;

    int N;
    printf("歡迎光臨長庚樂透彩購買機台\n請問要買幾組樂透彩 : ");
    scanf("%d",&N);
    int ant = N;
    printf("已把您購買的 %d 組樂透組合輸出至 lotto.txt\n",ant);

    fp = fopen("lotto.txt","w+");
    fprintf(fp,"%s", ctime(&Time));
    fclose(fp); 

    char time_v[25];
    fp = fopen("lotto.txt","r");
    fgets(time_v, 25, fp);
    fclose(fp); 

    

    fp = fopen("lotto.txt","w+");
    fprintf(fp,"========= lotto649 =========\n");
    fprintf(fp,"= %s =\n",time_v);


    int num;
    for(int n=0;n<5;n++){
        int temp[6];

        if(n>=N){
            fprintf(fp,"  [%d]: -- -- -- -- -- -- \n",n+1);
        }else{
            fprintf(fp,"  [%d]: ",n+1);
            for(int i =0;i<6;i++){
                num = RangedRand(1,69);
                temp[i]=num;
            }
            num = RangedRand(1,10);
            temp[6]=num;

            for(int i=0;i<6;i++){
                int max_num_index = 0;
                for(int j=0;j<5;j++){
                    if(temp[j]>temp[j+1]){
                        int temp_num = temp[j];
                        temp[j] = temp[j+1];
                        temp[j+1] = temp_num;
                    }
                }
                
            }
            print_num(fp,temp);
            
        }
    }
        
    
    fprintf(fp,"========= csie@CGU =========\n");


 


    fclose(fp); 
}