#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv){

    int triangulares[atoi(argv[1])];
    int results[atoi(argv[1])];
    int N;


    // puts the triangular numbers in the array
    for(int i = 0; N < atoi(argv[1]); i++){

        N = i * (i + 1) / 2;
        if(N > atoi(argv[1])){
            break;
        }

        triangulares[i] = N;
        printf("%d\n", N);

    }

    int indice_sum2 = 0;

    // sum of 2 numbers, if number is in array, because 0 is in it
    for(int i = 0; i < atoi(argv[1]); i++){
        for(int j = 0; j < atoi(argv[1]); j++){
            if(i == triangulares[j]){
                results[indice_sum2] = i;
                break;
            }
        }
    }

    // sum of 2 numbers, 2 others than 0
    int sum2 = 0;
    for(int i = 1; i < atoi(argv[1]) - 1; i++){
        for(int j = 2; j < atoi(argv[1]); j++){
            if((triangulares[i] + triangulares[j]) == sum2){
                results[indice_sum2] = sum2;
            }
        }
        sum2++;
    }




    // for(int i = 0; i < atoi(argv[1]); i++){
    //     int temp = triangulares[i];
    //     if(temp == 0 && i != 0){
    //         break;
    //     }else{
    //         printf("%d\n", temp);
    //     }
    // }

    return 0;
    // para verifivcar a soma de 2 numeros temos duas hipoteses, o numero existe no array ou entao double for loop para verificar se esta contifdo
    // no caso de 3 numeros, usar 
}