#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct Lotto_record_t{
    int lotto_no;
    float lotto_receipt;
    int emp_id;
    char lotto_date[10];
    char lotto_time[10];
}lotto_t;



int main(){
    FILE* fp;
    FILE* fp2;
    char line[100];
    lotto_t temp[1];
    // time_t Time;
    // time(&Time);
    char buff[10];
    time_t now = time(0);
    
    if((fp = fopen("report.txt","rb")) == NULL){
        fp = fopen("report.txt","wb+");
        fclose(fp);
    }
    
    int counter = 0;
    fp = fopen("record.bin","rb");
    fread(temp,sizeof(lotto_t),1,fp);
    printf("%s\n",temp[0].lotto_date);
    // fread(temp,sizeof(lotto_t),1,fp);
    // printf("%s\n",temp[0].lotto_date);
    // fread(temp,sizeof(lotto_t),1,fp);
    // printf("%s\n",temp[0].lotto_date);
    // while(temp[0].lotto_date){
    //     fread(temp,sizeof(lotto_t),1,fp);
    //     printf("%s\n",temp[0].lotto_date);
    // }
    fclose(fp);
    
    
    fp = fopen("report.txt","ab+");
    fprintf(fp,"======== lotto649 Report =======\n");
    fprintf(fp,"- Date ----- Num. ------ Recepit\n");
    // for(int i=0;i<){
    //     fprintf(fp,"%s     %d/%d          %d\n",);
    // }
    fprintf(fp,"--------------------------------\n");
    
    
    strftime(buff,100,"%Y/%m/%d",localtime(&now));
    fprintf(fp,"====== %s Printed ======\n\n\n",buff);
    // fwrite(temp,sizeof(lotto_t),1,fp2);
    fclose(fp);
    
    
}