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
        int minW = __INT_MAX__;
        int mw; //max Profit index among left
        for(int i = 0 ; i < 7; i++){
            if(x[i] == 0.0 && w[i]<minW){
                mw = i;
                minW = w[i];
            }
        }
        if(weight + w[mw] < Cap){
            x[mw] = 1.0;
        }
        else{
            x[mw] = (Cap - weight)/ w[mw];
        }
        weight = weight + w[mw] * x[mw];
        profit = profit + p[mw] * x[mw];
        // printf("i: %d x[i]: %f Weight : %f , Profit : %f\n",mw ,x[mw] ,weight ,profit);
    }
    printf("The x table :\n");
    for(int i = 0; i< 7; i++){
        printf("%.2f \n", x[i]);
    }
    printf("Weight: %.2f\n", weight);
    printf("Profit : %.2f", profit);
    return 0;
}