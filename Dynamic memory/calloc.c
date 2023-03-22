#include<stdio.h>
#include<stdlib.h>
    
int main(){
    
    int n;
    printf("Enter the number of integers: ");
    scanf("%d",&n);
    int *ptr = (int *)calloc( n , sizeof(int));

    if(!ptr){
        printf("Memory not available.");
        exit(1);
    }
    for(int i= 0 ; i<n ;i++){
        printf("Enter an integers: ");
        scanf("%d",ptr + i);
    }
    
    for(int i= 0 ; i<n ;i++){
        printf("%d ",*(ptr+i));
    }
    return 0;
}