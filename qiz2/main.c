#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


struct Lotto_record_t{
    int lotto_no;
    float lotto_receipt;
    int emp_id;
    char lotto_date[10];
    char lotto_time[10];
};
struct Empolyee{
    int em_id;
    char em_name[100];
    int em_salary;
};

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

int power(int num,int powerof){
    int temp = 1;
    for(int i=0;i<powerof;i++){
        temp = temp * num; 
    }
    return temp;
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
    FILE* fp5;
    int Fail = 0;
    if((fp2 = fopen("counter.bin","rb")) == NULL){
        fp2 = fopen("counter.bin","wb+");
        fprintf(fp2,"00000");
        fclose(fp2);

        fp2 = fopen("counter.bin","rb");
        fgets(No_count,6,fp2);
        fclose(fp2);
    }else{
        fp2 = fopen("counter.bin","rb");
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


        fp2 = fopen("counter.bin","w+");
        fprintf(fp2,"%s",No_count);
        fclose(fp2);
    }
    

    int N;
    printf("歡迎光臨長庚樂透彩購買機台\n請問要買幾組樂透彩 : ");
    scanf("%d",&N);
    int ant = N,op_id;
    // printf("%s",No_count);
    printf("請輸入操作員ID : ");
    scanf("%d",&op_id);
    if(op_id == 0){
        if((fp5 = fopen("operator_id.bin","rb")) == NULL){
            fp5 = fopen("operator_id.bin","wb+");
            fclose(fp5); 
        }

        struct Empolyee employee;
        int temp_v;
        char temp_a[100];

        //ID
        printf("employee's ID : ");
        scanf("%d",&temp_v);
        if(temp_v<100 && temp_v>0){
            employee.em_id = temp_v;
        }else{
            printf("ID out of range , plz be >0 and <100\n");
            printf("employee's ID : ");
            scanf("%d",&temp_v);
            employee.em_id = temp_v;
        }

        //name
        printf("employee's Name : ");
        scanf("%s",temp_a);
        strcpy(employee.em_name,temp_a);
        
        //salary
        printf("employee's $$ : ");
        scanf("%d",&temp_v);
        if(temp_v>0){
            employee.em_salary = temp_v;
        }else{
            printf("You are going too far.\n");
            printf("employee's $$ : ");
            scanf("%d",&temp_v);
            employee.em_salary = temp_v;
        }

        fp5 = fopen("operator_id.bin","ab");
        fwrite( &employee,sizeof(employee),1,fp5);
        fclose(fp5);


    }else{
        if(op_id>5 || op_id<0){
            printf("you are not an operator");
            exit(1);
        }
        printf("已把您購買的 %d 組樂透組合輸出至 lotto[%s].txt\n",ant,No_count);
        
        FILE* fp;
        FILE* fp3;
        
        time_t Time;
        time(&Time);

        if((fp3 = fopen("ID_record.bin","rb")) == NULL){
            fp3 = fopen("ID_record.bin","wb+");
            fprintf(fp3,"%s : %d \n",No_count,op_id);
            fclose(fp3);
        }else{
            fp3 = fopen("ID_record.bin","a");
            fprintf(fp3,"%s : %d \n",No_count,op_id);
            fclose(fp3);
        }

        

        char name[17];
        sprintf(name,"lotto[%s].txt",No_count);
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




        FILE* fp4;
        char buff[10];
        time_t now = time(0);
        int no = 0;
        
        if((fp4 = fopen("record.bin","rb")) == NULL){
            fp4 = fopen("record.bin","wb+");
            fclose(fp4); 
        }
        struct Lotto_record_t lott;
        fp4 = fopen("record.bin","ab+");
        for(int i=0;i<sizeof(No_count);i++){
            no += ((int)No_count[i]-48) * power(10,sizeof(No_count)-i-1);
        }
        lott.lotto_no = no ;
        lott.lotto_receipt = N*50*1.1;
        lott.emp_id = op_id;
        strftime(buff,100,"%Y/%m/%d",localtime(&now));
        strcpy(lott.lotto_date,buff);
        strftime(buff,100,"%H:%M:%S\n",localtime(&now));
        strcpy(lott.lotto_time,buff);
        fwrite( &lott,sizeof(lott),1,fp4);
        fclose(fp4); 

        // FILE* fp6;
        // if((fp6 = fopen("report.txt","rb")) == NULL){
        //     fp6 = fopen("report.txt","wb+");
        //     fclose(fp4); 
        // }

    
    }

}