#include "prototype.h"

int checkWord(word *setOfWord, int amountSetOfWord, char *word){
    int i;
    for (i = 0; i < amountSetOfWord; i++){
        if (strcmp(word, setOfWord[i].word) == 0)
            return 1;
    }

    return 0;
}

int addWord(word *setOfWord, int amountSetOfWord, char *word){
    int i;

    for (i = 0; i < amountSetOfWord; i++){
        if (strcmp(word, setOfWord[i].word) == 0){
            setOfWord[i].amount++;
            strcpy(setOfWord[i].word, word);
            setOfWord[i].length = strlen(word);

            return amountSetOfWord;
        }            
    }

    setOfWord[i].amount=1;
    strcpy(setOfWord[i].word, word);
    setOfWord[i].length = strlen(word);

    return (amountSetOfWord + 1);
}

void sortSetOfWord(word *setOfWord, int amountSetOfWord){
    int i, j;

    for (i = 0; i < amountSetOfWord; i++) {
        for (j = 0; j < amountSetOfWord-1-i; j++) {
            if (setOfWord[j].amount < setOfWord[j+1].amount) {
                word temp = setOfWord[j];
                setOfWord[j] = setOfWord[j+1];
                setOfWord[j+1] = temp;
            }else if (setOfWord[j].amount == setOfWord[j+1].amount) {
                if (setOfWord[j].length < setOfWord[j+1].length) {
                    word temp = setOfWord[j];
                    setOfWord[j] = setOfWord[j+1];
                    setOfWord[j+1] = temp;
                }
            }
        }
    }
}

void menu(){
    printf("Pilihan :\n\n");
    printf("1) Tampilkan hasil perhitungan dan pengurutan kata.\n");
    printf("2) Simpan hasil perhitungan dan pengurutan kata ke dalam file.\n");
    printf("3) Selesai\n\n");
    printf("Pilihan Anda : ");
}

void writeToFile(word *setOfWord, int amountSetOfWord){
    FILE *fp = fopen("hasil.txt", "w");
    int skor = 0, i;

    for (i = 0; i < amountSetOfWord; i++) {
        fprintf(fp, "%s, banyak : %d, panjang : %d\n", setOfWord[i].word, setOfWord[i].amount, setOfWord[i].length);
    }

    fclose(fp);
}

void showSetOfWord(word *setOfWord, int amountSetOfWord){
    printf("-----------------------------------\n");
    printf("|     Kata     | Jumlah | Panjang |\n");
    printf("-----------------------------------\n");
   
    for (int i = 0; i < amountSetOfWord; i++)
        printf("| %-12s | %-6d | %-7d |\n", setOfWord[i].word, setOfWord[i].amount, setOfWord[i].length);
   
    printf("-----------------------------------\n");

}