#include <stdio.h>

int main()
{
    long long n;
    int count = 0;
    printf("Enter an integer whith 10 numbers all diferent: ");
    scanf("%lld", &n);
    int digit_counter = n;
    int final = n;

    // seeing if it has 10 digits
    do {
        n /= 10;
        ++count;
    } while (n != 0);

    if(count != 10){
        printf("Doesn`t have 10 digits");
        return 0;
    }
    
    // put digits into array
    int digits[10];
    for(int i = 0; i < 10; i++){
        digits[i] = digit_counter % 10;
        digit_counter /= 10;
    }
    

    // seeing if all digits are different
    for(int i = 0; i < 10; i++){
        if(i == 9){
            printf("All digits are different\n");
            break;
        }

        for(int j = i+1; j < 10; j++){
            
            if(digits[i] == digits[j]){
                printf("%d%d", i, j);
                printf("%d%d", digits[i], digits[j]);
                printf("Equal digits\n");
                return 0;
            }
        }
    }


    // check if their division by the length number 

    int divisible = 1000000000;
    for(int i = 1; i < 10; i++){
        int temp = final / divisible;
        if(!(temp % i)){
            printf("Not divisible\n");
            return 0;
        }
    }
    printf("Divisible\n");


    return 0;
}