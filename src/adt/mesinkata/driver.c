#include "mesinkata.h"

int main(){
    STARTKATA(0);
    printf("Fungsi STARTKATA() : \n");
    if (STARTKATA("mesinkata/driver.txt")){
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

    printf("\n\nFungsi ADVKATA() : \n");
    ADVKATA();
    printf("Current Character : %c\n", CC);
    printf("Current Kata : %s"); PrintKata(CKata);

    printf("\n\nFugsi ToInteger()\n");
    printf("Current Value : %d", ToInteger());

    int x;
    printf("\n\nFungsi InputIntBef(&x)\n");
    InputIntBef(&x);
    printf("Current Value : %d", x);

    printf("\n\nFungsi InputInt(&x)\n");
    InputInt(&x);
    printf("Current Value : %d\n\n", x);

    Kata word;
    printf("Fungsi InputKata(&word)\n");
    InputKata(&word);
    printf("word Value : "); PrintKata(word);

    printf("Fungsi cek Kata\n");
    Kata word2;
    printf("InputKata Baru\n");
    InputKata(&word2);
    printf("word2 value: \n"); PrintKata(word2);
    if (EQKata(word,word2)) {
        printf("kata sama\n");
    } else {
        printf("kata berbeda\n");
    }

    char eff;
    printf("Fungsi convert kata ke array char");
    KataToArrChar(word,&eff);

    char eff2;
    printf("fungsi convert kata ke array char bag2\n");
    KataToArrChar(word2,&eff2);

    if (IsStrEQ(eff,eff2)) {
        printf("string sama\n");
    } else {
        printf("string beda\n");
    }

    StrToKata(&eff);
    StrToKata(&eff2);

    Kata copy1;
    CopyKata(word, &copy1);

    Kata copy2;
    CopyKata(word, &copy2);

    Kata copy3;
    ConcatKata(copy1, copy2, &copy3);

    char concat3;
    CopyStr(&eff, &concat3);

    printf("\n");

    return 0;
}