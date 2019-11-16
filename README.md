# The Number of Each Word in The Text
Ini adalah program menghitung jumlah setiap kata yang terdapat pada file text. Program dikembangkan menggunakan bahasa pemrograman C yang diimplementasikan dengan algoritma sebagai berikut.
* Baca file teks data.txt
* Split menjadi perkata
* Baca setiap kata dan lakukan pemeriksaan pada array setOfWord dengan kondisi berikut.
  * Jika kata belum ada di dalam array, maka tambahkan kata dan frekuensi menjadi 1
  * Jika kata sudah ada di dalam array, maka frekensi ditambah dengan 1
* Urutkan array setOfWord berdasarkan frekuensi dari besar ke kecil dengan menggunakan algoritma Bubble Sort
* Tampilkan seluruh data dari array setOfWord yang telah diurutkan.

## Improvement
Program masih dapat dikembangkan menjadi lebih baik dengan mengubah struktur data yang digunakan menjadi struktur data lainnya seperti LinkedList dan menggunakan algoritma pengurutan data yang lainnya seperti Quick Sort, Merge Sort, atau Heap Sort yang memiliki kompleksitas lebih baik dibandingkan dengan Bubble Sort.

## How To Run
Pastikan kamu sudah menyediakan file data.txt berisi text yang akan digunakan oleh program untuk menghitung setiap kata yang ada di dalamnya.

File Program : the-number-of-each-word-in-the-text.c <br>
Compile : gcc -o hasil the-number-of-each-word-in-the-text.c<br>
Run : ./hasil
