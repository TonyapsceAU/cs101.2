#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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

char* concat(const char *s1, const char *s2){
    char *result = malloc(strlen(s1) + strlen(s2) + 1);
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

int main () {
    srand(time(NULL));


    char No_count[6];
    FILE* fp2;
    int Fail = 0;
    if((fp2 = fopen("counter.txt","rb")) == NULL){
        Fail = 1;
    }else{
        Fail = 0;
    }
    // printf("%d",Fail);
    if(Fail==1){
        fp2 = fopen("counter.txt","wb+");
        fprintf(fp2,"00000");
        fclose(fp2);

        fp2 = fopen("counter.txt","rb");
        fgets(No_count,6,fp2);
        fclose(fp2);
    }else if(Fail==0){
        fp2 = fopen("counter.txt","rb");
        fgets(No_count,6,fp2);
        fclose(fp2);
        
        No_count[4] = No_count[4] + 1;
        // printf("%s\n",No_count);

        for(int k=4;k>0;k--){
            if(No_count[k]>48+9){
                No_count[k-1] = No_count[k-1] + 1;
                No_count[k] = 48; 
            }
            if(No_count[0]>48+9){
                printf("too many");
            }
        }


        fp2 = fopen("counter.txt","w+");
        fprintf(fp2,"%s",No_count);
        fclose(fp2);
    }
    

    // printf("%s",No_count);

    int N;
    printf("歡迎光臨長庚樂透彩購買機台\n請問要買幾組樂透彩 : ");
    scanf("%d",&N);
    int ant = N,op_id;
    // printf("%s",No_count);
    printf("請輸入操作員ID : ");
    scanf("%d",&op_id);
    if(op_id>5 || op_id<0){
        printf("you are not an operator");
        exit(1);
    }
    printf("已把您購買的 %d 組樂透組合輸出至 lotto[%s].txt\n",ant,No_count);
    
    int ID_record_Fail = 0;
    FILE* fp3;
    if((fp3 = fopen("ID_record.bin","rb")) == NULL){
        ID_record_Fail = 1;
    }
    // printf("ID_record_Fail = %d",ID_record_Fail);
    // printf("%s",No_count);
    if(ID_record_Fail){
        fp3 = fopen("ID_record.bin","wb+");
        fprintf(fp3,"%s : %d \n",No_count,op_id);
        fclose(fp3);
    }else{
        fp3 = fopen("ID_record.bin","a");
        fprintf(fp3,"%s : %d \n",No_count,op_id);
        fclose(fp3);
    }



    time_t Time;
    time(&Time);
    FILE* fp;
    
    
    // char* name1 = concat("lotto[",No_count);
    // char* name = concat(name1,"].txt");
    char name[17];
    sprintf(name,"lotto[%s].txt",No_count);
    // printf("%s",name);
    fp = fopen(name,"wb+");
    fprintf(fp,"%s", ctime(&Time));
    fclose(fp); 

    char time_v[25];
    fp = fopen(name,"rb");
    fgets(time_v, 25, fp);
    fclose(fp); 

    fp = fopen(name,"wb+");
    fprintf(fp,"========= lotto649 =========\n");
    fprintf(fp,"========+ No.%s +========\n",No_count);
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
        
    fprintf(fp,"========* Op.0000%d *========\n",op_id);
    fprintf(fp,"========= csie@CGU =========\n");


 


    fclose(fp); 
}