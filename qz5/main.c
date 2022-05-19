#include <stdio.h>

int do_befor_adding(int* i){
    *i = *i + 1;
    return *i - 1;
}

int do_after_adding(int* i){
    return *i += 1;
}

void check_result(int x,int z,int t_x,int t_z){
    if(x==t_x&&z==t_z){
        printf(" pass\n");
    }else{
        printf(" fail\n");
    }
}

void test_do_befor_adding(){
    int x = 1;
    int z = 5 + do_befor_adding(&x);
    int t_x = 1;
    int t_z = 5 +  t_x++;
    printf("do_befor_adding()\n");
    printf("z=%d,x=%d, ",z,x);
    printf("t_z=%d, t_x=%d\n",t_z,t_x);
    check_result(x,z,t_x,t_z);
}

void test_do_after_adding(){
    int x = 1;
    int z = 5 + do_after_adding(&x);
    int t_x = 1;
    int t_z = 5 + ++t_x;
    printf("do_befor_adding()\n");
    printf("z=%d,x=%d, ",z,x);
    printf("t_z=%d, t_x=%d\n",t_z,t_x);
    check_result(x,z,t_x,t_z);
}


int main(){
    printf(" --- fun 1. --- ");
    test_do_befor_adding();
    printf(" --- fun 2. --- ");
    test_do_after_adding();

    return 0;
}
