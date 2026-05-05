/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 4
 *   Hari dan Tanggal    : 5 Mei 2026
 *   Nama (NIM)          : 13224074
 *   Nama File           : soal1.c
 *   Deskripsi           : Valid or invalid string of ()[]{}
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct Node {
    char c;
    int filled;
};


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

    // () tipe 1, [] tipe 2, {} tipe 3
    int i = 0;
    while (arr[i].filled == 1){
        int behind = 0; int front = 0; int disq = 0; int type; int done = 0; int hold_k = INT_MAX;
        if (arr[i].c == '('){
            int k = i+1;
            while (arr[k].filled == 1){
                if (arr[k].c == '['){
                    type = 2; behind = 1;
                }else if (arr[k].c == '{'){
                    type = 3; behind = 1;
                }else if (arr[k].c == '}' && behind == 1 && type == 3 && k>hold_k){
                    arr[hold_k].c = '1';
                    done = 1;
                }else if (arr[k].c == ']' && behind == 1 && type == 2 && k>hold_k){
                    arr[hold_k].c = '1';
                    done = 1;
                }

                if (arr[k].c == ')'){
                    if (done == 0){
                        arr[k].c = '0';
                        arr[i].c = '0';
                        hold_k = k;
                        done = 1;
                    }
                }
                
                k++;
            }
            behind = 0; front = 0;  disq = 0; type = 0;  done = 0;
        }else if (arr[i].c == '{'){
            int k = i+1;

            while (arr[k].filled == 1){
                if (arr[k].c == '('){
                    type = 1; behind = 1;
                }else if (arr[k].c == '['){
                    type = 3; behind = 2;
                }else if (arr[k].c == '(' && behind == 1 && type == 1 && k>hold_k){
                    done = 1;
                    arr[hold_k].c = '1';
                }else if (arr[k].c == '[' && behind == 1 && type == 2 && k>hold_k){
                    done = 1;
                    arr[hold_k].c = '1';
                }

                if (arr[k].c == '}'){
                    if (done == 0){
                        arr[k].c = '0';
                        arr[i].c = '0';
                        hold_k = k;
                        done = 1;
                    }
                }
                k++;
            }
            behind = 0; front = 0;  disq = 0; type = 0;  done = 0;
        }else if (arr[i].c == '['){
            int k = i+1;

            while (arr[k].filled == 1){
                if (arr[k].c == '('){
                    type = 1; behind = 1;
                }else if (arr[k].c == '{'){
                    type = 3; behind = 2;
                }else if (arr[k].c == '(' && behind == 1 && type == 1 && k>hold_k){
                    done = 1;
                    arr[hold_k].c = '1';
                }else if (arr[k].c == '{' && behind == 1 && type == 3 && k>hold_k){
                    done = 1;
                    arr[hold_k].c = '1';
                }

                if (arr[k].c == ']'){
                    if (done == 0){
                        arr[k].c = '0';
                        arr[i].c = '0';
                        hold_k = k;
                        done = 1;
                    }
                }
                k++;
            }
            behind = 0; front = 0;  disq = 0; type = 0;  done = 0; hold_k = 0;
        }
        i++;
    }

    int valid = 1;
    int k = 0;

    while (arr[k].filled == 1){
        if (arr[k].c == '(' || arr[k].c == ')' || arr[k].c == '[' || arr[k].c == ']' || arr[k].c == '{' || arr[k].c == '}' || arr[k].c == '1'){
            printf("INVALID");
            valid = 0;
            break;
        }
        k++;
    }

    if (valid == 1){
        printf("VALID");
    }

    return 0;
}
