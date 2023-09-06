#include<stdio.h>
int main(){
    int p[7]={10,5,15,7,6,18,3};
    int w[7]={2,3,5,7,1,4,1};
    float weight = 0, profit = 0;
    float Cap = 15.0;
    float x[7];
    for(int i = 0 ; i < 7;i++)
        x[i] = 0.0;


    while(weight<Cap){
        int maxP = 0;
        int mp; //max Profit index among left
        for(int i = 0 ; i < 7; i++){
            if(x[i] == 0.0 && p[i]>maxP){
                mp = i;
                maxP = p[i];
            }
        }
        if(weight + w[mp] < Cap){
            x[mp] = 1.0;
        }
        else{
            x[mp] = (Cap - weight)/ w[mp];
        }
        weight = weight + w[mp] * x[mp];
        profit = profit + p[mp] * x[mp];
        // printf("i: %d x[i]: %f Weight : %f , Profit : %f\n",mp ,x[mp] ,weight ,profit);
    }
    printf("The x table :\n");
    for(int i = 0; i< 7; i++){
        printf("%.2f \n", x[i]);
    }
    printf("Weight: %.2f\n", weight);
    printf("Profit : %.2f", profit);
    return 0;
}