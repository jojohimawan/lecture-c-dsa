//
// Created by jordan on 4/26/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char kata[10];

void cetakPalindrom(int);

int main()
{
    printf("Masukkan kata: ");
    scanf(" %[^\n]%*c", &kata);
    cetakPalindrom(strlen(kata));
    return 0;
}

void cetakPalindrom(int len)
{
    if(len < 0) {
        return ;
    } else {
        printf("%c", kata[len]);
        cetakPalindrom(len - 1);
    }
}