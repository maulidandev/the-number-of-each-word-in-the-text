#include "prototype.h"

int main(int argc, char const *argv[])
{
    word setOfWord[10000];
    char nameOfFile[255], *word, sentence[BUFFERSENTENCE], delimiter[] = " \n\t\r`~!@#$%^&*()_-+=[{]}\\|];:'\"<,.>/?1234567890";
    int amount = 0, i, amountSetOfWord = 0, choice = 0, alreadySelected = 0;
    FILE *fp;

    printf("Masukkan nama file input (txt) : ");
    scanf("%s", nameOfFile);

    fp = fopen(nameOfFile, "r");
    if (fp == NULL) {
        printf("File yang anda masukkan tidak ditemukan.\n");
        return 1;
    }

    /* mengambil per baris yang terdapat pada file */
    while (fgets(sentence, BUFFERSENTENCE, fp) != NULL) {
        /* memilah kalimat menjadi kata */
        word = strtok(sentence, delimiter);
        while (word != NULL) {
            amountSetOfWord = addWord(setOfWord, amountSetOfWord, word);

            word = strtok(NULL, delimiter);
        }
    }

    fclose(fp);

    /* mengurutkan himpunan kata berdasarkan skor */
    sortSetOfWord(setOfWord, amountSetOfWord);

    /* menampilkan menu pada monitor */
    do {
        menu();
        scanf("%d", &choice);

        if (choice == 1) {
            showSetOfWord(setOfWord, amountSetOfWord);
        }else if(choice == 2){
            writeToFile(setOfWord, amountSetOfWord);
        }else if (choice == 3) {
            break;
        }else{
            printf("Harap periksa kembali inputan pilihan anda.\n");
        }
    } while(1);

    return 0;
}
