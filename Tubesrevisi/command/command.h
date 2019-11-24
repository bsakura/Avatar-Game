#ifndef COMMAND_H
#define COMMAND_H

void Command();
/*I.S: Sembarang
  F.S: Setelah memproses input dari mesin kata, akan dilakukan aksi command 
       dengan memanggil prosedur sesuai perintah.*/
void Attack();
/*I.S: Sembarang
  F.S: akan dikeluarkan output berupa daftar bangunan, bangunan yang dapat digunakan untuk menyerang,
       dan bangunan yang bisa diserang. Apabila tidak ada bangunan yang berhubungan langsung dengan 
       angunan penyerang, akan keluar output tidak ada bangunan yang dapat diserang.Jika ada bangunan 
       yang dapat diserang, akan keluar output hasil jumlah pasukan setelah penyerangan berhasil.*/
void Level_up();
/*I.S: Bangunan
  F.S: Output berupa list bangunan yang bisa dilevel-up lalu akan dikembalikan properti-properti
       bangunan yang telah diupgrade di layar.*/
void Skill();
/*I.S.: Sembarang.
  F.S.: Dihasilkan stack kosong untuk memasukkan skill-skill yang diperoleh oleh pemain
        dan apabila pemain menggunakan skill, skill tersebut akan menghilang dan tidak 
        dapat digunakan lagi. */
void UNDO();
/*I.S.: Sembarang
  F.S.: Segala aksi yang dilakukan oleh pemain kembali ke keadaan sebelum pemain melakukan aksi.
        Jika sebelumnya tidak ada command, akan muncul keluaran berupa tidak ada perintah untuk 
        dibatalkan.*/
void Move();
/*I.S: Sembarang.
  F.S: AKan ada keluaran berupa daftar bangunan dan bangunan terdekat yang dapat dipilih
       untuk memindahkan pasukkan. Jika pasukkan terlalu besar akan ada pembertitahuan bahwa
       pemindahan tidak berhasil. Apabila pemindahan berhasil akan keluar notifikasi tentang
       jumlah pasukan di bangunan tersebut.*/
void End_turn();
/*I.S.: Sembarang.
  F.S.: Mengakhiri giliran pemain.*/
void Save();
/* Prosedur untuk menyimpan data permainan*/
void EXIT();
/* Prosedur untuk keluar dari permainan*/


#endif