// // WAP to find maximum of two numbers using function
// #include <stdio.h>
// int maximum(int a, int b){
//     if(a > b){
//         return a;
//     }
//     else{
//         return b;
//     }
// }
// int main(){
//     int num1, num2;
//     printf("Enter two numbers: ");
//     scanf("%d %d", &num1, &num2);
//     int max = maximum(num1, num2);
//     printf("The maximum of %d and %d is: %d\n", num1, num2, max);
//     return 0;
// }
// WAP to find maximum of using function
#include <stdio.h>
int maximum(int a, int b, int c){
    if(a > b && a > c){
        return a;
    }
    else if(b > a && b > c){
        return b;
    }
    else{
        return c;
    }
}
int main(){
    int num1, num2, num3;
    printf("Enter three numbers: ");
    scanf("%d %d %d", &num1, &num2, &num3);
    int max = maximum(num1, num2, num3);
    printf("The maximum of %d, %d and %d is: %d\n", num1, num2, num3, max);
    return 0;
}