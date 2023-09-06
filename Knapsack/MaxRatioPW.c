#include<stdio.h>
int main(){
    int p[7]={10,5,15,7,6,18,3};
    int w[7]={2,3,5,7,1,4,1};
    float weight = 0, profit = 0;
    int Cap = 15;
    float x[7];
    for(int i = 0 ; i < 7;i++)
        x[i] = 0.0;


    while(weight<Cap){
        float maxR = 0;
        int mr; //max Profit index among left
        for(int i = 0 ; i < 7; i++){
            if(x[i] == 0.0 && p[i]/w[i]>maxR){
                mr = i;
                maxR = p[i]/w[i];
            }
        }
        if(weight + w[mr] < Cap){
            x[mr] = 1.0;
        }
        else{
            x[mr] = (Cap - weight)/ w[mr];
        }
        weight = weight + w[mr] * x[mr];
        profit = profit + p[mr] * x[mr];
        // printf("i: %d x[i]: %f Weight : %f , Profit : %f\n",mr ,x[mr] ,weight ,profit);
    }
    printf("The x table :\n");
    for(int i = 0; i< 7; i++){
        printf("%.2f \n", x[i]);
    }
    printf("Weight: %.2f\n", weight);
    printf("Profit : %.2f", profit);
    return 0;
}