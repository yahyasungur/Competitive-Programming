#include<stdio.h>

int main(){
    int i,hane=0,tek = 0,cift = 0,tetemp = 0;
    long int number,temp;
    scanf(" %ld",&number);
    temp = number;

    while (1){
        if(temp == 0){
            break;
        }
        temp = temp/10;
        hane ++;
    }
    temp = number;
    for ( i = 0; i < hane; i++){
        if(i % 2 == 0){
            tek += temp%10;
            temp /= 10; 
        }
        else{
            if (2*(temp%10) > 9){
                tetemp = 2*(temp%10);
                cift += tetemp%10;
                tetemp /= 10;
                cift += tetemp%10;
            }
            else{
                cift += 2*(temp%10);
            }
            temp /= 10;
        }
    }
    if ((tek + cift)%10 == 0){
        switch (hane){
        case 15:
            temp = number;
            for (i = 0; i < 13; i++){
                temp /= 10;
            }
            if (temp == 34 || temp == 37){
                printf("AMEX\n");
            }
            break;
        case 16:
            temp = number;
            for (i = 0; i < 14; i++){
                temp /= 10;
            }
            if (temp > 50 && temp < 56){
                printf("MASTERCARD\n");
            }
            temp /= 10;
            if (temp == 4){
                printf("VISA\n");
            }
            break;
        case 13:
            temp = number;
            for (i = 0; i < 15; i++){
                temp /= 10;
            }
            if (temp == 4){
                printf("VISA\n");
            }
            break;
        default:
            break;
        }
    }
    else{
        printf("INVALID\n");
    }
    return 0;
}