# Gale-Shapley Algorithm for Stable Matching Problem

Naufal Aulia - 140810180074

## Hasil Akhir Program

```
Amy     ><  Yancy
Bertha  ><  Victor
Claire  ><  Zeus
Diane   ><  Wyatt
Wyatt   ><  Xavier
```

## Analisis

### **Apakah jawaban Saya di Worksheet 01 dan Program sama persis? Jika Tidak? Kenapa?**
    
Tidak karena dari yang [saya kerjakan manual](https://docs.google.com/document/d/2mdCz270Rhyc6mPFgQIRRF4jAB9OM_ZV7krpWT_zLVjU/edit?usp=sharing) ada pencocokan yang salah, contohnya pada saat Xavier memilih Bertha saya menulis Bertha menerima Xavier dan meninggalkan Victor sementara di prograp Xavier ditolak.

### **Teorema (1.3) Algoritma G-S berakhir setelah paling banyak $n^2$ iterasi menggunakan While Loop. Buktikan!**

Proses dari algoritma di ukur sebagai berikut,

${P(t) := \#\{(m,w) | hasproposed(m,n)\}}$

saat iterasi *t*, kita mendapatkan ${P(t) < P(t+1) }$ karena
* pada setiap iterasi, kita menjalankan ${hasproposed(m,w) := true}$,
* kecuali saat kita keluar loop.

Total jumlah pasangan adalah $n\times n$, yang membuat batas atas pada jumlah lamaran.

$\Rightarrow P(t)$ bisa meningkat sampai $n^2$ kali.

### **Teorema (1.4) Jika seorang pria bebas di beberapa titik dalam eksekusi algoritma, maka ada seorang wanita yang belum dia ajak bertunangan. Buktikan!**

Teorema ini **Salah** dengan asumsi sebagai berikut.

Misalkan seorang pria tidak berpasangan dan telah melamar semua wanita.

Ingat kembali cara kerja wanita dalam algoritma ini :
* Setelah seorang wanita di lamar, dia tidak akan selalu berpasangan.
* Entah dia tetap bersama pasangan awal nya, atau berpasangan dengan pria baru yang melamar nya jika pria tersebut lebih tinggi dalam preferensi nya daripada pasangan awal nya.

dari situ kita bisa mengambil kesimpulan bahwa semua wanita pasti berpasangan dan karena setiap satu wanita pasti berpasangan dengan satu pria, semua pria juga pasti berpasangan.

### **Teorema (1.5) Himpunan S yang dikembalikan saat terminasi adalah *perfect matching* Buktikan!**

Pertama, kita memastikan bahwa himpunan pasangan sudah cocok dengan menganalisis cara wanita bekerja di algoritma ini. Seorang wanita bisa bebas, atau berpasangan hanya dengan satu pria, jadi setiap wanita hanya muncul sekali dalam himpunan. Pria yang sudah berpasangan tidak boleh melamar. Seorang pria bebas atau berpasangan dengan satu wanita, sehingga setiap pria juga hanya muncul sekali dalam himpunan. Dengan itu, himpunan yang dikembalikan saat terminasi adalah yang *perfect match*.

Kedua, Kita membuktikan bahwa himpunan ini *perfect match* dengan kontradiksi. Misalkan algoritma berakhir dengan seora pria tidk berpasangan. Dari teorema sebelumnya, ada seorang wanita yang belum dilamar oleh pria tidak berpasangan itu. Tetapi algoritma hanya berakhir jika tidak ada pria bebas yang belum melamar setiap wanita. Ini bertentangan dengan asumsi, kita memiliki *perfect matching*.

### **Teorema (1.6) Sebuah eksekusi algoritma G-S mengembalikan satu set pasangan S. Set S adalah pasangan yang stabil. Buktikan!**
   
Dari Teorema sebelumnya, kita sudah membuktikan *perfect matching*.Kita bisa membuktikan stabilitas melalui kontradisi. 

Misalkan ${(m, w), (m', w') \in S}$ memiliki ketidakstabilan ${(m, w')}$: m lebih suka w' daripada w dan w' lebih suka m daripada m'. m melamar terakhir ke w. Apakah m melamar w'? 
* Jika m tidak meelamar w', maka dalam daftar preferensi m w lebih tinggi, mengikat asumsi bahwa m lebih suka w' daripada w.
* Jika m memang melamar w', maka
    * Antara w' berpasangan dengan m'', peringkat lebih tinggi dari m, dan karena itu w' menolak proposal m'
    * atau w' menerima lamaran dari m'', peringkat lebih tinggi dari m, dan oleh karena itu w' meninggalkan m. 

Kontradiksi nya sama jika m' sama dengan m''. Jika m' tidak sama dengan m', maka w' lebih suka m' daripada m'', w' lebih suka m'' daripada m, dan dengan demikian w' lebih suka m' daripada m. Ini bertentangan dengan asumsi, S adalah *stable matching*.