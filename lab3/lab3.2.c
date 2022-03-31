#include <stdio.h>

int len(char* arr, int counter){
    if(*(arr+counter)!=0){
        counter = len(arr,counter+1);
    }
    return counter;
}

int main(){
    char input[] = "snkc111as cm d";
    printf("%d",len(input,0));

    return 0;
}
