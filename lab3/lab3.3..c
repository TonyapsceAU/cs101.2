#include <stdio.h>

int len(char* arr, int counter){
    if(*(arr+counter)!=0){
        counter = len(arr,counter+1);
    }
    return counter;
}


char* short_f(char* arr){
    int length = len(arr,0);
    for(int i=0;i<length;i++){
        for(int j=0;j<length-1;j++){
            if(arr[j]>arr[j+1]){
                char temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    return arr;
}

int main(){
    char input[] = "snkc111as cm d";
    printf("%s",short_f(input));
    // printf("%d",len(input,0));

    return 0;
}




