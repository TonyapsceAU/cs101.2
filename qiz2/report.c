#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct Lotto_record_t{
    int lotto_no;
    float lotto_receipt;
    int emp_id;
    char lotto_date[11];
    char lotto_time[11];
}lotto_t;

int check_diff(char arr[],char arr2[]){
    // printf("%s,%s\n",arr,arr2);
    for(int i=9;i>=0;i--){
        // printf("%c,%c\n",arr[i],arr2[i]);
        if(arr[i]!=arr2[i]){
            return 1;
        }
    }
    return 0;
}


int main(){
    FILE* fp;
    FILE* fp2;
    char line[100];
    lotto_t temp[1];
    lotto_t p_temp[1];
    
    char buff[10];
    time_t now = time(0);
    
    if((fp = fopen("report.txt","rb")) == NULL){
        fp = fopen("report.txt","wb+");
        fclose(fp);
    }

    
    
    fp = fopen("report.txt","ab+");
    fprintf(fp,"======== lotto649 Report =======\n");
    fprintf(fp,"- Date ----- Num. ------ Recepit\n");
    fclose(fp);
    

    fp = fopen("record.bin","rb");
    int st_c = 0;
    int income = 0;
    int can_buy = 0;
    int bought = 0;
    
    
    
    int day_count = 0 ;
    int T_can_buy = 0;
    int T_bought = 0;
    int T_income = 0;
    
    while((fread(temp,sizeof(lotto_t),1,fp)  == 1)){
        if(st_c==0){
            p_temp[0] = temp[0];
            st_c++;
        }
        if(!check_diff(temp[0].lotto_date,p_temp[0].lotto_date)){
            can_buy += 5;
            bought  += (p_temp[0].lotto_receipt/1.1)/50;
            income  += p_temp[0].lotto_receipt;
        }else{
            day_count++;
            can_buy += 5;
            bought  += (p_temp[0].lotto_receipt/1.1)/50;
            income  += p_temp[0].lotto_receipt;
            fp2 = fopen("report.txt","ab+");
            fprintf(fp2,"%s   %d/%d       %d\n",p_temp[0].lotto_date,bought,can_buy,income);
            if(can_buy<10){
                fprintf(fp2,"%s   0%d/0%d       %d\n",p_temp[0].lotto_date,bought,can_buy,income); 
            }else{
                fprintf(fp2,"%s   %d/%d       %d\n",p_temp[0].lotto_date,bought,can_buy,income);        
            }
            fclose(fp2);
            T_can_buy += can_buy;
            T_bought += bought;
            T_income += income;
            income = 0;
            can_buy = 0;
            bought = 0;
        }
        p_temp[0] = temp[0];
    }
    day_count++;
    // can_buy += 5;
    bought  += (p_temp[0].lotto_receipt/1.1)/50;
    income  += p_temp[0].lotto_receipt;
    fp2 = fopen("report.txt","ab+");
    if(can_buy<10){
        fprintf(fp2,"%s   0%d/0%d       %d\n",p_temp[0].lotto_date,bought,can_buy,income); 
    }else{
        fprintf(fp2,"%s   %d/%d       %d\n",p_temp[0].lotto_date,bought,can_buy,income);        
    }
    fclose(fp2);
    T_can_buy += can_buy;
    T_bought += bought;
    T_income += income;
    
    
    fclose(fp);



    fp = fopen("report.txt","ab+");
    fprintf(fp,"--------------------------------\n");
    fprintf(fp,"      %d      %d/%d       %d\n",day_count,T_bought,T_can_buy,T_income);
    strftime(buff,100,"%Y/%m/%d",localtime(&now));
    fprintf(fp,"====== %s Printed ======\n\n\n",buff);
    fclose(fp);
    
    
}