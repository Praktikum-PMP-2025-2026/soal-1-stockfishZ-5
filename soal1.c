/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 4
 *   Hari dan Tanggal    : 5 Mei 2026
 *   Nama (NIM)          : 13224074
 *   Nama File           : soal1.c
 *   Deskripsi           : Mensortir s
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char c;
    int filled;
};

void check(struct Node* arr[]){
    
}

int main(){
    char input[50];
    struct Node arr[50];
    scanf("%s", input);

    for (int i = 0; i < 50; i++){
        arr[i].filled = 0;
    }

    for (int i = 0; i < strlen(input); i++){
        arr[i].c = input[i]; 
        arr[i].filled = 1;
    }

    //check(&arr);

    int i = 0;
    while (arr[i].filled == 1){
        if (arr[i].c == '('){
            int k = i+1;

            while (arr[k].filled == 1){
                if (arr[k].c == ')'){
                    arr[k].c = '0';
                    arr[i].c = '0';
                    break;
                }else{
                    k++;
                }
            }
        }else if (arr[i].c == '{'){
            int k = i+1;

            while (arr[k].filled == 1){
                if (arr[k].c == '}'){
                    arr[k].c = '0';
                    arr[i].c = '0';
                    break;
                }else{
                    k++;
                }
            }
        }else if (arr[i].c == '['){
            int k = i+1;

            while (arr[k].filled == 1){
                if (arr[k].c == ']'){
                    arr[k].c = '0';
                    arr[i].c = '0';
                    break;
                }else{
                    k++;
                }
            }
        }
        i++;
    }

    int valid = 1;
    int k = 0;
    while (arr[k].filled == 1){
        if (arr[k].c == '(' || arr[k].c == ')' || arr[k].c == '[' || arr[k].c == ']' || arr[k].c == '{' || arr[k].c == '}'){
            printf("INVALID");
            valid = 0;
        }
        k++;
    }

    if (valid == 1){
        printf("VALID");
    }

    return 0;
}
