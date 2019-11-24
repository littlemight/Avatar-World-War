#include "mesinkata.h"

int main(){
    printf("Fungsi STARTKATA() : \n");
    if (STARTKATA("src/adt/mesinkata/driver.txt")){
        printf("TRUE\n\n");
    }
    else{
        printf("FALSE\n\n");
    }
    printf("Fungsi IgnoreBlank():\n");
    IgnoreBlank();
    printf("Current Character : %c\n\n", CC);

    printf("Fungsi SalinKata()\n");
    SalinKata();
    printf("Current Character : %c\n", CC);
    printf("Copied Kata (seharusnya 'testext') : "); PrintKata(CKata);

    printf("\n\nFungsi KCreateEmpty(Kata) : \n");
    KCreateEmpty(&CKata);
    printf("Current Kata : "); PrintKata(CKata);
    printf("Nge print kosong\n");

    printf("\n\nFungsi ADVKATA() : \n");
    ADVKATA();
    printf("Current Character : %c\n", CC);
    printf("Current Kata "); PrintKata(CKata);

    printf("\n\nFungsi ToInteger()\n");
    printf("Current Value : %d", ToInteger());


    int x;
    printf("\n\nFungsi InputInt(&x)\n");
    InputInt(&x);
    printf("Current Value : %d\n\n", x);

    Kata word;
    printf("Fungsi InputKata(&word)\n");
    InputKata(&word);
    printf("word Value : "); PrintKata(word);

    printf("\nFungsi cek Kata\n");
    Kata word2;
    printf("InputKata Baru\n");
    InputKata(&word2);
    printf("word2 value: "); PrintKata(word2);
    if (EQKata(word,word2)) {
        printf("\nkata sama\n");
    } else {
        printf("\nkata berbeda\n");
    }

    char eff[50];
    printf("Fungsi convert kata ke array char\n");
    KataToArrChar(word, &eff);

    char eff2[50];
    printf("fungsi convert kata ke array char bag2\n");
    KataToArrChar(word2, &eff2);

    if (IsStrEQ(eff,eff2)) {
        printf("string sama\n");
    } else {
        printf("string beda\n");
    }

    printf("%s %s\n", eff, eff2);
    PrintKata(StrToKata(eff)); printf(" ");
    PrintKata(StrToKata(eff2));

    printf("\n=====\n");
    Kata copy1;
    CopyKata(word, &copy1);
    PrintKata(copy1); printf(' ');

    Kata copy2;
    CopyKata(word, &copy2);
    PrintKata(copy2); printf(' ');

    Kata copy3;
    ConcatKata(copy1, copy2, &copy3);
    PrintKata(copy3);
    printf('\n');

    return 0;
}