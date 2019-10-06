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
    fgets(sentence, BUFFERSENTENCE, fp);
    while (!feof(fp)) {
        /* memilah kalimat menjadi kata */
        word = strtok(sentence, delimiter);
        while (word != NULL) {
        /* cek dan masukkan kata jika tidak ada */
        if (!adaKata(setOfWord, amountSetOfWord, word)) {
            amount = 0;
            for (i = 0; i < strlen(word); i++) {
                word[i] = tolower(word[i]);
                amount++;
            }

            /* memasukkan kata ke dalam struct */
            setOfWord[amountSetOfWord].amount = amount;
            strcpy(setOfWord[amountSetOfWord].word, word);
            setOfWord[amountSetOfWord].length = i;

            amountSetOfWord++;
        }

        word = strtok(NULL, delimiter);
        }

        fgets(sentence, BUFFERSENTENCE, fp);
    }

    fclose(fp);

    /* mengurutkan himpunan kata berdasarkan skor */
    sortSetOfWord(setOfWord, amountSetOfWord);

    /* menampilkan menu pada monitor */
    do {
        menu();
        scanf("%d", &choice);

        if (choice == 1) {
            writeToFile(setOfWord, amountSetOfWord);

            alreadySelected = 1;
        }else if(choice == 2){
            int n;

            do {
                printf("Masukkan nilai n : ");
                scanf("%d", &n);

                if (n > 0 && n <= 50) break;
            } while(1);

            /* jika user belum memilih pilihan sebelumnya */
            if (!alreadySelected) {
                writeToFile(setOfWord, amountSetOfWord);
            }

            readFile(n);
            alreadySelected = 1;
        }else if (choice == 3) {
            break;
        }else{
            printf("Harap periksa kembali inputan pilihan anda.\n");
        }
    } while(1);

    return 0;
}
