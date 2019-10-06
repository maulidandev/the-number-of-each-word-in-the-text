#include "prototype.h"

int checkWord(word *setOfWord, int amountSetOfWord, char *word){
    int i;
    for (i = 0; i < amountSetOfWord; i++)
        if (strcmp(word, setOfWord[i].word) == 0)
            return 1;

    return 0;
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
    // printf("1) Simpan keluaran dalam sebuah file binari dalam susunan yang telah diuraikan sebelumnya.\n\n");
    // printf("2) Tampilkan di layar monitor maksimum n buah kata (0<n<=50). Nilai n diinputkan oleh user via keyboard. Setelah nilai n diinputkan, tampilkan n kata beserta skornya ke layar monitor.\n\n");
    // printf("Contoh keluaran untuk n = 4 adalah sebagai berikut:\n\n");
    // printf("74,vokal,5\n57,owils,5\n57,piko,4\n57,kopi,4\n\n");
    // printf("Kolom pertama adalah skor, kolom kedua adalah kata, dan kolom ketiga adalah panjang kata tersebut.\n\n");
    printf("1) Tampilkan hasil perhitungan dan pengurutan kata.");
    printf("2) Simpan hasil perhitungan dan pengurutan kata ke dalam file.");
    printf("3) Selesai\n\n");
    printf("Pilihan Anda : ");
}

void writeToFile(word *setOfWord, int amountSetOfWord){
    FILE *fp = fopen("hasil.txt", "w");
    int skor = 0, i;

    for (i = 0; i < amountSetOfWord; i++) {
        // if (skor != setOfWord[i].skor) {
        //     skor = setOfWord[i].skor;
        //     int banyakKata = getJumlahKataDariSkor(setOfWord, i, skor, banyakHimpunanKata);

        //     // printf("[%d][%d]", himpunanKata[i].skor, banyakKata);
        //     // fwrite(&skor, 1, sizeof(skor), fp);
        //     // fwrite(&banyakKata, 1, sizeof(banyakKata), fp);
        // }

        // fwrite(&setOfWord[i].panjangKata, 1, sizeof(setOfWord[i].panjangKata), fp);
        // fwrite(setOfWord[i].kata, 1, sizeof(setOfWord[i].kata), fp);

        fprintf(fp, "%s %d\n", setOfWord[i].word, setOfWord[i].amount);
    }

    printf("\n\n");

    fclose(fp);
}

void readFile(int n){
    FILE *fp = fopen("hasil-bin.txt", "r");
    int skor, i, banyakKata, panjangKata, j;
    char kata[255];

    for (i = 0; i < n;) {
        fread(&skor, sizeof(skor), 1, fp);

        fread(&banyakKata, sizeof(banyakKata), 1, fp);

        for (j = 0; i < n && j < banyakKata; i++, j++) {
        fread(&panjangKata, sizeof(panjangKata), 1, fp);
        fread(kata, sizeof(kata), 1, fp);

        printf("%d, %s, %d\n", skor, kata, panjangKata);
        }
    }

    // printf("==================\n\n");

    fclose(fp);
}