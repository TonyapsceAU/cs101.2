#include <stdio.h>

int len(char* arr,int counter){
    while(*(arr+counter)!=0){
        counter++;
    }
    return counter;
}

int main(){
    char input[] = "snkcas cm d";
    printf("%d",len(input));

    return 0;
}
