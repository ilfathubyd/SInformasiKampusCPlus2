#include <iostream>
#include <string.h>
#include <conio.h>
#include <windows.h>
using namespace std;

int termin=0;
char loop[5];
int totalMHS = 2;

struct dataraw{
	char pw[20],nbi[20];
}raw[2];

struct mahasiswa{
	char nama[30];
	char nbi[20];
	char jurusan[40];
	char fakultas[40];
	char id[20];
	char pass[20];
	int total ;
	char kode[20];
	string matkul[10];
	string dosen[10];
	string kelas[10];
	string kodeMatkul[10];
	int sks[10];
	
	mahasiswa *next;
	mahasiswa *daftar;
}*head, *tail, *pos, *pos2, *pos3, *baru, *simpan, *fakultas[5], *feb[5], *fh[5], *fib[5], *ft[5];

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void login();
void mhs();
void tambahUrut();
void tampil();
void adminpg();
void userpg();
void hapusdata();
void tampilSemuaNode();
void Cari();
void logout();
void pilihSKS();
void SKS();
void tampilKRS();
void tambahSKS();

void cetak (int klm, int brs, char * teks){
	gotoxy(klm,brs); cout<<teks;
}


int main(){
	do{
		mhs();
		login();
	}while(strcmp (loop, "y") == 0 || strcmp(loop, "Y") == 0);	
}


void admin(){
	strcpy(raw[0].nbi, "admin");
	strcpy(raw[0].pw, "admin");
	
	strcpy(raw[1].nbi, "user");
	strcpy(raw[1].pw, "user");
}


void mhs(){
	mahasiswa *maha, *mhs;
	
	fakultas[0] = new mahasiswa;
	strcpy(fakultas[0]->nama, "Fakultas Ekonomi dan Bisnis");
	strcpy(fakultas[0]->kode, "1100");
	
	feb[0] = new mahasiswa;
	strcpy(feb[0]->nama, "Manajemen");
	strcpy(feb[0]->kode, "111");
	fakultas[0]->next = feb[0];
	
	maha = new mahasiswa;
	strcpy(maha->nama, "Anak Manajemen");
	strcpy(maha->nbi, "1112200111");
	strcpy(maha->fakultas,"Fakultas Ekonomi dan Bisnis");
	strcpy(maha->jurusan,"Manajemen");
	feb[0]->daftar = maha;
	strcpy(maha->id,maha->nbi);
	strcpy(maha->pass,"123");
	maha->next = NULL;
	
	feb[1] = new mahasiswa;
	strcpy(feb[1]->nama, "Ekonomi Pembangunan");
	strcpy(feb[1]->kode, "112");
	feb[0]->next = feb[1];
	
	maha = new mahasiswa;
	strcpy(maha->nama, "Anak Ekonomi Pembangunan");
	strcpy(maha->nbi, "1122200222");
	strcpy(maha->fakultas,"Fakultas Ekonomi dan Bisnis");
	strcpy(maha->jurusan,"Ekonomi Pembangunan");
	feb[1]->daftar = maha;
	strcpy(maha->id,maha->nbi);
	strcpy(maha->pass,"123");
	maha->next = NULL;
	
	feb[2] = new mahasiswa;
	strcpy(feb[2]->nama, "Akuntansi");
	strcpy(feb[2]->kode, "113");
	feb[1]->next = feb[2];
	feb[2]->next = NULL;
	
	maha = new mahasiswa;
	strcpy(maha->nama, "Anak Akuntansi");
	strcpy(maha->nbi, "1132200333");
	strcpy(maha->fakultas,"Fakultas Ekonomi dan Bisnis");
	strcpy(maha->jurusan,"Akuntansi");
	feb[2]->daftar = maha;
	strcpy(maha->id,maha->nbi);
	strcpy(maha->pass,"123");
	maha->next = NULL;
	
	fakultas[1] = new mahasiswa;
	strcpy(fakultas[1]->nama, "Fakultas Hukum");
	strcpy(fakultas[1]->kode, "1200");
	
	fh[0] = new mahasiswa;
	strcpy(fh[0]->nama, "Ilmu Hukum");
	strcpy(fh[0]->kode, "121");
	fakultas[1]->next = fh[0];
	fh[0]->next = NULL;
	
	maha = new mahasiswa;
	strcpy(maha->nama, "Anak Ilmu Hukum");
	strcpy(maha->nbi, "1212200111");
	strcpy(maha->fakultas,"Fakultas Hukum");
	strcpy(maha->jurusan,"Ilmu Hukum");
	fh[0]->daftar = maha;
	strcpy(maha->id,maha->nbi);
	strcpy(maha->pass,"123");
	maha->next = NULL;
	
	fakultas[2] = new mahasiswa;
	strcpy(fakultas[2]->nama, "Fakultas Ilmu dan Budaya");
	strcpy(fakultas[2]->kode, "130");
	
	fib[0] = new mahasiswa;
	strcpy(fib[0]->nama, "Sastra Jepang");
	strcpy(fib[0]->kode, "131");
	fakultas[2]->next = fib[0];
	fib[0]->next = NULL;
	
	maha = new mahasiswa;
	strcpy(maha->nama, "Anak Sasjep");
	strcpy(maha->nbi, "1312200111");
	strcpy(maha->fakultas,"Fakultas Ilmu Budaya");
	strcpy(maha->jurusan,"Sastra Jepang");
	fib[0]->daftar = maha;
	strcpy(maha->id,maha->nbi);
	strcpy(maha->pass,"123");
	maha->next = NULL;
	
	fakultas[3] = new mahasiswa;
	strcpy(fakultas[3]->nama, "Fakultas Teknik");
	strcpy(fakultas[3]->kode, "140");
	
	ft[0] = new mahasiswa;
	strcpy(ft[0]->nama, "Teknik Sipil");
	strcpy(ft[0]->kode, "141");
	fakultas[3]->next = ft[0];
	
	maha = new mahasiswa;
	strcpy(maha->nama, "Anak Sipil");
	strcpy(maha->nbi, "1412200111");
	strcpy(maha->fakultas,"Fakultas Teknik");
	strcpy(maha->jurusan,"Teknik Sipil");
	ft[0]->daftar = maha;
	strcpy(maha->id,maha->nbi);
	strcpy(maha->pass,"123");
	maha->next = NULL;
	
	ft[1] = new mahasiswa;
	strcpy(ft[1]->nama, "Teknik Arsitektur");
	strcpy(ft[1]->kode, "142");
	ft[0]->next = ft[1];
	
	maha = new mahasiswa;
	strcpy(maha->nama, "Anak Aristek");
	strcpy(maha->nbi, "1422200111");
	strcpy(maha->fakultas,"Fakultas Teknik");
	strcpy(maha->jurusan,"Teknik Arsitektur");
	ft[1]->daftar = maha;
	strcpy(maha->id,maha->nbi);
	strcpy(maha->pass,"123");
	maha->next = NULL;
	
	ft[2] = new mahasiswa;
	strcpy(ft[2]->nama, "Teknik Mesin");
	strcpy(ft[2]->kode, "143");
	ft[1]->next = ft[2];
	
	maha = new mahasiswa;
	strcpy(maha->nama, "Anak Mesin");
	strcpy(maha->nbi, "1432200111");
	strcpy(maha->fakultas,"Fakultas Teknik");
	strcpy(maha->jurusan,"Teknik Mesin");
	ft[2]->daftar = maha;
	strcpy(maha->id,maha->nbi);
	strcpy(maha->pass,"123");
	maha->next = NULL;
	
	ft[3] = new mahasiswa;
	strcpy(ft[3]->nama, "Teknik Elektro");
	strcpy(ft[3]->kode, "144");
	ft[2]->next = ft[3];
	
	maha = new mahasiswa;
	strcpy(maha->nama, "Anak Elektro");
	strcpy(maha->nbi, "1442200111");
	strcpy(maha->fakultas,"Fakultas Teknik");
	strcpy(maha->jurusan,"Teknik Elektro");
	ft[3]->daftar = maha;
	strcpy(maha->id,maha->nbi);
	strcpy(maha->pass,"123");
	maha->next = NULL;
	
	ft[4] = new mahasiswa;
	strcpy(ft[4]->nama, "Teknik Pertambangan");
	strcpy(ft[4]->kode, "145");
	ft[3]->next = ft[4];
	
	maha = new mahasiswa;
	strcpy(maha->nama, "Anak Tambang");
	strcpy(maha->nbi, "1422200111");
	strcpy(maha->fakultas,"Fakultas Teknik");
	strcpy(maha->jurusan,"Teknik Pertambangan");
	ft[4]->daftar = maha;
	strcpy(maha->id,maha->nbi);
	strcpy(maha->pass,"123");
	maha->next = NULL;
	
	ft[5] = new mahasiswa;
	strcpy(ft[5]->nama, "Teknik Informatika");
	strcpy(ft[5]->kode, "146");
	ft[4]->next = ft[5];
	ft[5]->next = NULL;
	
	maha = new mahasiswa;
	strcpy(maha->nama,"Ilfath Ubaydillah Mudzaki");
	strcpy(maha->nbi,"1462200135");
	strcpy(maha->fakultas,"Teknik");
	strcpy(maha->jurusan,"Teknik Informatika");
	strcpy(maha->id,maha->nbi);
	strcpy(maha->pass,"123");
	ft[5]->daftar = maha;
	
	mhs = new mahasiswa;
	strcpy(mhs->nama,"Abdul Azizur Rokhman");
	strcpy(mhs->nbi,"1462200139");
	strcpy(mhs->fakultas,"Teknik");
	strcpy(mhs->jurusan,"Teknik Informatika");
	strcpy(mhs->id, mhs->nbi);
	strcpy(mhs->pass,"123");
	maha->next = mhs;
	mhs->next = NULL;
}


	char usr[20];
	char pss[20];
	
	
void login(){
//	mahasiswa *baru;
	bool acc,log=false;
	int kodeFak, kodeJur;
	pos = head;
	admin();
	//mhs();
//	do {
		system ("cls");
		cetak(38,4, "==============================================");
		cetak(38,5,"||                LOGIN PAGE                ||");
		cetak(38,6, "||  ======================================  ||");
		cetak(38,7, "||                                          ||");
		cetak(38,8, "||                                          ||");
		cetak(38,9, "||                                          ||");
		cetak(38,11, "||                                          ||");
		cetak(38,10, "||  ID       :                              ||");
		cetak(38,12, "||                                          ||");
		cetak(38,14, "||  PASSWORD :                              ||");
		cetak(38,13, "||                                          ||");
		cetak(38,15, "||                                          ||");
		cetak(38,16, "||                                          ||");
		cetak(38,17, "||                                          ||");
		cetak(38,18, "||                                          ||");
		cetak(38,19, "||                                          ||");
		cetak(38,20, "==============================================");
		gotoxy(54,10); cin>>usr;
		gotoxy(54,14); cin>>pss;
		
		for (int i = 0; i<=3; i++){
			if (strcmp(raw[i].nbi, usr) == 0 && strcmp(raw[i].pw, pss) == 0){
				cetak(54,22, "Login Berhasil!");
				acc = true;
				log=true;
				getch();
				adminpg();
				break;
			}
		}
		
		if (log!=true){
			kodeFak = ((atoi(usr) / 100000000) % 10) - 1;
			kodeJur = atoi(usr) / 10000000;
			
			pos = fakultas[kodeFak]->next;
			while (atoi(pos->kode) != kodeJur){
				pos = pos->next;
				if (pos == NULL){
					termin++;
					cout<<termin;
					cetak(41, 19, "Percobaan ke-");
					gotoxy(56,19);cout<<termin;
					cetak(48,22, "ID atau kata sandi salah !");
					getch();
					if(termin >= 3){
						cetak(40,22, "Anda sudah gagal 3 kali!, Coba lagi nanti");
						getch();
						termin = 0;
						login();
					}
					break;
				}
			}
			if (pos != NULL){
				pos = pos->daftar;

				while (pos != NULL){
					if (strcmp(pos->id, usr) == 0 && strcmp(pos->pass,pss) == 0){
						cetak(54,22, "Login Berhasil!");
						acc = true;
						userpg();
						break;
						getch();
					} else pos = pos->next;
				}
				if (acc != true || strlen(usr) != 10){
					termin++;
					cetak(41, 19, "Percobaan ke-");
					gotoxy(56,19);cout<<termin;
					cetak(48,22, "ID atau kata sandi salah !");
					getch();
					if(termin>=3){
						cetak(40,22, "Anda sudah gagal 3 kali!, Coba lagi nanti");
						getch();
						exit(0);
						termin = 0;
					}	
				} else login();
			}
		}
		login();
}

void logout(){
	
	system("cls");
	gotoxy(56,7); cout<<"________";
	gotoxy(55,8); cout<<"|        |";
	gotoxy(55,9); cout<<"|        |";
	gotoxy(55,10); cout<<"|        |    \\";
	gotoxy(55,11); cout<<"|    ---------->";
	gotoxy(55,12); cout<<"|        |    /";
	gotoxy(55,13); cout<<"|        |";
	gotoxy(55,14); cout<<"|________|";
	gotoxy(57,16); cout<<"Log Out";
	gotoxy(30,25); cout<<"Anda telah berhasil Logout, Terimakasih telah berkunjung:)";
	getch();
	login();
	
}

void adminpg(){
	int pil;
	
	while (pil <= 6){
		system("cls");
		gotoxy(16,3); cout<<"========================================================================================";
		gotoxy(16,4); cout<<"||"; gotoxy(102,4); cout<<"||";
		gotoxy(16,5); cout<<"||"; gotoxy(102,5); cout<<"||";
		gotoxy(16,6); cout<<"||"; gotoxy(102,6); cout<<"||";
		gotoxy(54,5); cout<<"ADMIN PAGE";
		gotoxy(16,7); cout<<"========================================================================================";
		gotoxy(25,10); cout<<"(1)Tambah Data Mahasiswa";
		gotoxy(25,14); cout<<"(2)Hapus Data Mahasiswa";
		gotoxy(65,10); cout<<"(3)Tampilkan Data Mahasiswa";
		gotoxy(67,14); cout<<"(4)Cari Data Mahasiswa";
		gotoxy (51,12); cout<<"(5)Tambah SKS";
		gotoxy(16,8); cout<<"||"; gotoxy(102,8); cout<<"||";
		gotoxy(16,9); cout<<"||"; gotoxy(102,9); cout<<"||";
		gotoxy(16,10); cout<<"||"; gotoxy(102,10); cout<<"||";
		gotoxy(16,11); cout<<"||"; gotoxy(102,11); cout<<"||";
		gotoxy(16,12); cout<<"||"; gotoxy(102,12); cout<<"||";
		gotoxy(16,13); cout<<"||"; gotoxy(102,13); cout<<"||";
		gotoxy(16,14); cout<<"||"; gotoxy(102,14); cout<<"||";
		gotoxy(16,15); cout<<"||"; gotoxy(102,15); cout<<"||";
		gotoxy(16,16); cout<<"||"; gotoxy(102,16); cout<<"||";
		gotoxy(16,17); cout<<"========================================================================================";
		gotoxy(90,18); cout<<"(6)Logout";
		gotoxy(16,18); cout<<"||"; gotoxy(102,18); cout<<"||";
		gotoxy(16,19); cout<<"========================================================================================";
		gotoxy(16,21); cout<<"Pilihan Anda :";
		gotoxy(32,21); cin>>pil;
		
		if (pil == 1){
			tambahUrut();
		} else if (pil == 2){
			hapusdata();
		} else if (pil == 3){
			tampilSemuaNode();
		} else if (pil == 4){
			Cari();
	
		} else if (pil == 6){
			gotoxy(90,20); cout<<"Logout?"; 
			gotoxy (99,20); cin>>loop;
			if (strcmp(loop, "y") == 0 || (strcmp(loop, "Y") == 0)) logout();
		} else if (pil > 6){
			gotoxy(16,23); cout<<"Pilihan anda tidak tersedia";
			getch();
			adminpg();
		}	
	}	
}

void tambahUrut(){
		mahasiswa *pos1, *pos2;
	char name[30];
	char nim[20];
	int kodeFak, kodeJur;
	char dataKrs;
	
	system("cls");
	baru = new mahasiswa;
	gotoxy(16,3); cout<<"========================================================================================";
	gotoxy(16,4); cout<<"||"; gotoxy(102,4); cout<<"||";
	gotoxy(16,5); cout<<"||"; gotoxy(102,5); cout<<"||";
	gotoxy(16,6); cout<<"||"; gotoxy(102,6); cout<<"||";
	gotoxy(54,5); cout<<"TAMBAH MAHASISWA";
	gotoxy(16,7); cout<<"========================================================================================";
	gotoxy(25,10); cout<<"Nama : ";
	gotoxy(25,12); cout<<"NBI  : ";
	gotoxy(16,8); cout<<"||"; gotoxy(102,8); cout<<"||";
	gotoxy(16,9); cout<<"||"; gotoxy(102,9); cout<<"||";
	gotoxy(16,10); cout<<"||"; gotoxy(102,10); cout<<"||";
	gotoxy(16,11); cout<<"||"; gotoxy(102,11); cout<<"||";
	gotoxy(16,12); cout<<"||"; gotoxy(102,12); cout<<"||";
	gotoxy(16,13); cout<<"||"; gotoxy(102,13); cout<<"||";
	gotoxy(16,14); cout<<"||"; gotoxy(102,14); cout<<"||";
	gotoxy(16,15); cout<<"||"; gotoxy(102,15); cout<<"||";
	gotoxy(16,16); cout<<"||"; gotoxy(102,16); cout<<"||";
	gotoxy(16,17); cout<<"||"; gotoxy(102,17); cout<<"||";
	gotoxy(16,18); cout<<"||"; gotoxy(102,18); cout<<"||";
	gotoxy(16,19); cout<<"========================================================================================";
	gotoxy(32,10); cin>>ws;
	gotoxy(32,10); cin.getline(name, 30);
	strcpy(baru->nama, name);
	gotoxy(32,12); cin>>nim;
	strcpy(baru->nbi, nim);
	
	strcpy(baru->id, baru->nbi);
	strcpy(baru->pass, "123");
	
	kodeFak = ((atoi(baru->nbi) / 100000000) % 10) - 1;
	kodeJur = atoi(baru->nbi) / 10000000;
	
	strcpy(baru->fakultas, fakultas[kodeFak]->nama);
	pos3 = fakultas[kodeFak]->next;
	while (atoi(pos3->kode) != kodeJur) pos3 = pos3->next;
	
	strcpy(baru->jurusan, pos3->nama);
	pos2 = pos3;
	pos1 = pos2 = pos2->daftar;
	
	while (pos2!=NULL && atoi(pos2->nbi) < atoi(baru->nbi)) {
		pos1 = pos2;
		if (pos2->next == NULL) break;
		else pos2 = pos2->next;
	}
	
	if (pos2 == NULL){
		pos1->next = baru;
		baru->next = NULL;
	} else if (pos1 == pos2){
		baru->next = pos1;
		pos3->daftar = baru;
	} else {
		baru->next = pos2;
		pos1->next = baru;
	}
	
	//totalMHS++;
	
	gotoxy(19,18); cout<<"Ingin menambah data KRS ?";
	gotoxy(45,18); cin>>dataKrs;
	
	if (dataKrs == 'y'){
		tambahSKS();	
	}
}

void tambahSKS(){
	mahasiswa *pos1;
	
	int pil, pilmat, jumlah, sks;
	int batas = 0;
	int kodeFak, kodeJur;
	string matkul;
	string kodeMatkul;
	string dosen;
	string kelas;
	int i = 1 ;
	char ulang = 'y';
	kodeFak = ((atoi(baru->nbi) / 100000000) % 10) - 1;
	
	if (fakultas[kodeFak] == fakultas[0] && pos3 == feb[0]){
		while ( ulang == 'y'){
	
			system("cls");
			
			gotoxy(16,2); cout<<"Nama : "<<baru->nama;
			gotoxy(16,3); cout<<"NBI  : "<<baru->nbi;
			gotoxy(66,2); cout<<"Fakultas : "<<baru->fakultas;
			gotoxy(66,3); cout<<"Jurusan  : "<<baru->jurusan;
			gotoxy(15,4); cout<<"=========================================================================================";
			gotoxy(50,5); cout<<"PILIHAN MATA KULIAH";
			gotoxy(32,6); cout<<"=========================================================";
			gotoxy(32,7); cout<<"| PIL |                  NAMA                     | SKS |";
			gotoxy(32,8); cout<<"=========================================================";
			gotoxy(32,9); cout<<"|  1  | PENDIDIKAN AGAMA ISLAM						|  3  |";
			gotoxy(32,10); cout<<"|  2  | PENDIDIKAN KEWARGANEGARAAN				|  4  |";
			gotoxy(32,11); cout<<"|  3  | BAHASA INDONESIA							|  3  |";
			gotoxy(32,12); cout<<"|  4  | PENGANTAR MANAJEMEN						|  2  |";
			gotoxy(32,13); cout<<"|  5  | STATISTIK									|  4  |";
			gotoxy(32,14); cout<<"|  6  | PENGANTAR FILSAFAT ILMU					|  3  |";
			gotoxy(32,15); cout<<"=========================================================";
			gotoxy(32,16); cout<<"|                                              (7) EXIT |";
			gotoxy(32,17); cout<<"=========================================================";
			gotoxy(32,19); cout<<"Pilihan Anda : ";
			gotoxy(47,19); cin>>pil;
			
			system("cls");
			gotoxy(16,2); cout<<"Nama : "<<baru->nama;
			gotoxy(16,3); cout<<"NBI  : "<<baru->nbi;
			gotoxy(66,2); cout<<"Fakultas : "<<baru->fakultas;
			gotoxy(66,3); cout<<"Jurusan  : "<<baru->jurusan;
			gotoxy(15,4); cout<<"=========================================================================================";
			gotoxy(50,5); cout<<"PILIHAN MATA KULIAH";
			gotoxy(32,6); cout<<"=========================================================";
			gotoxy(32,7); cout<<"| PIL |                  NAMA                   | KELAS |";
			gotoxy(32,8); cout<<"=========================================================";
				
			if (pil == 1){
				
				gotoxy(32,9); cout<<"|  1  | PENDIDIKAN AGAMA ISLAM                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | PENDIDIKAN AGAMA ISLAM                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | PENDIDIKAN AGAMA ISLAM                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | PENDIDIKAN AGAMA ISLAM                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | PENDIDIKAN AGAMA ISLAM                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | PENDIDIKAN AGAMA ISLAM                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | PENDIDIKAN AGAMA ISLAM                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
				
				if (pilmat == 1){
	
					matkul = "PENDIDIKAN AGAMA ISLAM";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "A";
	
				} else if (pilmat == 2){
					matkul = "PENDIDIKAN AGAMA ISLAM";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "B";
	
				} else if (pilmat == 3){
					matkul = "PENDIDIKAN AGAMA ISLAM";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "C";
	
				}else if (pilmat == 4){
					matkul = "PENDIDIKAN AGAMA ISLAM";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "D";
					
				}else if (pilmat == 5){
					matkul = "PENDIDIKAN AGAMA ISLAM";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "E";
				
				} else if (pilmat == 6) {
					matkul = "PENDIDIKAN AGAMA ISLAM";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "F";
					
				} else if (pilmat == 7){
					matkul = "PENDIDIKAN AGAMA ISLAM";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "R";
				}	
			}
			else if (pil == 2){
				
				gotoxy(32,9); cout<<"|  1  | PENDIDIKAN KEWARGANEGARAAN                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | PENDIDIKAN KEWARGANEGARAAN                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | PENDIDIKAN KEWARGANEGARAAN                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | PENDIDIKAN KEWARGANEGARAAN                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | PENDIDIKAN KEWARGANEGARAAN                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | PENDIDIKAN KEWARGANEGARAAN                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | PENDIDIKAN KEWARGANEGARAAN                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
				
				if (pilmat == 1){
					matkul = "PENDIDIKAN KEWARGANEGARAAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "A";
					
				}
				else if (pilmat == 2){
					matkul = "PENDIDIKAN KEWARGANEGARAAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "B";
					
				} 
				else if (pilmat == 3){
					matkul = "PENDIDIKAN KEWARGANEGARAAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "C";
					
				}
				else if (pilmat == 4){
					matkul = "PENDIDIKAN KEWARGANEGARAAN";
					kodeMatkul = "Unknown";
					dosen = "MATKUL FEB 1 2";
					sks = 4;
					kelas = "D";
					
				} else if (pilmat == 5){
					matkul = "PENDIDIKAN KEWARGANEGARAAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "E";
					
				} else if (pilmat == 6){
					matkul = "PENDIDIKAN KEWARGANEGARAAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "F";		
					
				} else if (pilmat == 7){
					matkul = "PENDIDIKAN KEWARGANEGARAAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "R";
					
				}
			}
			else if (pil == 3){
				
				gotoxy(32,9); cout<<"|  1  | BAHASA INDONESIA                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | BAHASA INDONESIA                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | BAHASA INDONESIA                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | BAHASA INDONESIA                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | BAHASA INDONESIA                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | BAHASA INDONESIA                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | BAHASA INDONESIA                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
					
				if (pilmat == 1){
					matkul = "BAHASA INDONESIA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "A";
				} 
				else if (pilmat == 2){
					matkul = "BAHASA INDONESIA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "B";	
				} 
				else if (pilmat == 3){
					matkul = "BAHASA INDONESIA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "C";	
				} 
				else if (pilmat == 4){
					matkul = "BAHASA INDONESIA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "D";	
				} 
				else if (pilmat == 5){
					matkul = "BAHASA INDONESIA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "E";	
				} 
				else if (pilmat == 6){
					matkul = "BAHASA INDONESIA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "F";
				} 
				else if (pilmat == 7){
					matkul = "BAHASA INDONESIA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "R";
				}	
			}	
			else if (pil == 4){
				
				gotoxy(32,9); cout<<"|  1  | PENGANTAR MANAJEMEN                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | PENGANTAR MANAJEMEN                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | PENGANTAR MANAJEMEN                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | PENGANTAR MANAJEMEN                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | PENGANTAR MANAJEMEN                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | PENGANTAR MANAJEMEN                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | PENGANTAR MANAJEMEN                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
					
				if (pilmat == 1){
					
					matkul = "PENGANTAR MANAJEMEN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IA";		
				} 
				else if (pilmat == 2){
					
					matkul = "PENGANTAR MANAJEMEN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IB";		
				} 
				else if (pilmat == 3){
							
					matkul = "PENGANTAR MANAJEMEN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IC";		
				} 
				else if (pilmat == 4){
						
					matkul = "PENGANTAR MANAJEMEN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "ID";
						
				} 
				else if (pilmat == 5){
						
					matkul = "PENGANTAR MANAJEMEN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IE";		
				} 
				else if (pilmat == 6){
						
					matkul = "PENGANTAR MANAJEMEN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IF";		
				} 
				else if (pilmat == 7){
						
					matkul = "PENGANTAR MANAJEMEN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IR";		
				}	
			}
			
			else if (pil == 5){
				
				gotoxy(32,9); cout<<"|  1  | STATISTIK                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | STATISTIK                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | STATISTIK                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | STATISTIK                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | STATISTIK                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | STATISTIK                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | STATISTIK                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
					
				if (pilmat == 1){
				
					matkul = "STATISTIK";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "A";
				} 	
				else if (pilmat == 2){
				
					matkul = "STATISTIK";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "B";
				} 				
				else if (pilmat == 3){
				
					matkul = "STATISTIK";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "C";
				} 
				
				else if (pilmat == 4){
				
					matkul = "STATISTIK";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "D";	
				} 
				
				else if (pilmat == 5){
				
					matkul = "STATISTIK";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "E";
				} 
				
				else if (pilmat == 6){
				
					matkul = "STATISTIK";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "F";
				} 
				else if (pilmat == 7){
				
					matkul = "STATISTIK";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "R";
				}	
			}
			
			else if (pil == 6){
				
				gotoxy(32,9); cout<<"|  1  | PENGANTAR FILSAFAT ILMU                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | PENGANTAR FILSAFAT ILMU                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | PENGANTAR FILSAFAT ILMU                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | PENGANTAR FILSAFAT ILMU                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | PENGANTAR FILSAFAT ILMU                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | PENGANTAR FILSAFAT ILMU                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | PENGANTAR FILSAFAT ILMU                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
					
				if (pilmat == 1){
					
					matkul = "PENGANTAR FILSAFAT ILMU";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "A";
				} 
				else if (pil == 2){
					
					matkul = "PENGANTAR FILSAFAT ILMU";
					kodeMatkul = "14620063";
					dosen = "Unknown";
					sks = 3;
					kelas = "B";
				}
				else if (pil == 3){
					
					matkul = "PENGANTAR FILSAFAT ILMU";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "C";
				} 
				else if (pil == 4){
					
					matkul = "PENGANTAR FILSAFAT ILMU";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "D";
	
				} else if (pil == 5){
					matkul = "PENGANTAR FILSAFAT ILMU";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "E";
				} else if (pil == 6){
					matkul = "PENGANTAR FILSAFAT ILMU";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "F";
				} else if (pil == 7){
					matkul = "PENGANTAR FILSAFAT ILMU";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "R";
				}
					
			}
			if (pil == 7) {
				break;
			}
			batas = batas + sks;
			
			if(batas > 24){
				cout << endl<<endl;
				cout << "input SKS anda melebihi batas !! "<<endl<<endl;
				
				cout << "Jumlah SKS yang Melebihi Batas : ";
				cout << batas<<endl;
				
				cout << "Matkul yang tidak bisa Diinputkan : ";
				cout << matkul<<endl;
				
				cout << "SKS dari Mata Kuliah " << matkul << " adalah : "; 
				cout << sks<<endl;
			
				cout << "Total Mata Kuliah yang Telah Diambil : ";
				cout << baru->total<<endl;
				
				cout << "Index : ";
				cout << i<<endl<<endl;
				
				getch();
				
				cout << "Mau memperbarui data sks terakhir anda ?" ;
				cin >> ulang;
					
				batas = batas - sks;
					
				if(ulang == 'y')
					continue;
				else
					break;
			}	
						
			if (batas <= 24){
							
				if(batas == 24){
					
					cout << endl;
					cout << endl;
					cout<<"Batas SKS tercapai !!";
				}
							
				baru->matkul[i] = matkul;
				baru->sks[i] = sks;
				baru->kodeMatkul[i] = kodeMatkul;
				baru->dosen[i] = dosen;
				baru->kelas[i] = kelas;
				baru->total++;
//				i++;
				
				if (batas < 24){
					cout << "tambah ? ";
					cin >> ulang;
						
						
					if (ulang == 't'){
						break;
					}	
				}
				
				cout << endl;
				cout << endl;
				cout << "Jumlah SKS yang sudah diambil : ";
				cout << batas;
				cout << endl << endl;
				
				cout << "Matkul yang Diinputkan : ";
				cout << matkul;
				cout << endl << endl;
				
				cout << "SKS dari Mata Kuliah " << matkul << " adalah : "; 
				cout << sks;
				cout << endl << endl;
			
				cout << "Total Mata Kuliah yang Telah Diambil : ";
				cout << baru->total;
				cout << endl << endl;
				
				cout << "Index : ";
				cout << i;
				cout << endl;
				cout << endl;
				
				i++;
				
				getch();
							
			}
		}
	} 
	
	else if (fakultas[kodeFak] == fakultas[0] && pos3 == feb[1]){
		while ( ulang == 'y'){
	
			system("cls");
			gotoxy(16,2); cout<<"Nama : "<<baru->nama;
			gotoxy(16,3); cout<<"NBI  : "<<baru->nbi;
			gotoxy(66,2); cout<<"Fakultas : "<<baru->fakultas;
			gotoxy(66,3); cout<<"Jurusan  : "<<baru->jurusan;
			gotoxy(15,4); cout<<"=========================================================================================";
			gotoxy(50,5); cout<<"PILIHAN MATA KULIAH";
			gotoxy(32,6); cout<<"=========================================================";
			gotoxy(32,7); cout<<"| PIL |                  NAMA                     | SKS |";
			gotoxy(32,8); cout<<"=========================================================";
			gotoxy(32,9); cout<<"|  1  | PENDIDIKAN AGAMA ISLAM                     |  3  |";
			gotoxy(32,10); cout<<"|  2  | PENDIDIKAN KEWARGANEGARAAN                |  4  |";
			gotoxy(32,11); cout<<"|  3  | STATISTIK                                 |  3  |";
			gotoxy(32,12); cout<<"|  4  | EKONOMI PEMBANGUNAN                       |  2  |";
			gotoxy(32,13); cout<<"|  5  | TEORI EKONOMI MAKRO                       |  4  |";
			gotoxy(32,14); cout<<"|  6  | PENGANTAR MANAJEMEN                       |  3  |";
			gotoxy(32,15); cout<<"=========================================================";
			gotoxy(32,16); cout<<"|                                              (7) EXIT |";
			gotoxy(32,17); cout<<"=========================================================";
			gotoxy(32,19); cout<<"Pilihan Anda : ";
			gotoxy(47,19); cin>>pil;
			
			system("cls");
			gotoxy(16,2); cout<<"Nama : "<<baru->nama;
			gotoxy(16,3); cout<<"NBI  : "<<baru->nbi;
			gotoxy(66,2); cout<<"Fakultas : "<<baru->fakultas;
			gotoxy(66,3); cout<<"Jurusan  : "<<baru->jurusan;
			gotoxy(15,4); cout<<"=========================================================================================";
			gotoxy(50,5); cout<<"PILIHAN MATA KULIAH";
			gotoxy(32,6); cout<<"=========================================================";
			gotoxy(32,7); cout<<"| PIL |                  NAMA                   | KELAS |";
			gotoxy(32,8); cout<<"=========================================================";
				
			if (pil == 1){
				
				gotoxy(32,9); cout<<"|  1  | PENDIDIKAN AGAMA ISLAM                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | PENDIDIKAN AGAMA ISLAM                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | PENDIDIKAN AGAMA ISLAM                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | PENDIDIKAN AGAMA ISLAM                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | PENDIDIKAN AGAMA ISLAM                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | PENDIDIKAN AGAMA ISLAM                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | PENDIDIKAN AGAMA ISLAM                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
				
				if (pilmat == 1){
	
					matkul = "PENDIDIKAN AGAMA ISLAM";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "A";
	
				} else if (pilmat == 2){
					matkul = "PENDIDIKAN AGAMA ISLAM";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "B";
	
				} else if (pilmat == 3){
					matkul = "PENDIDIKAN AGAMA ISLAM";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "C";
	
				}else if (pilmat == 4){
					matkul = "PENDIDIKAN AGAMA ISLAM";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "D";
					
				}else if (pilmat == 5){
					matkul = "PENDIDIKAN AGAMA ISLAM";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "E";
				
				} else if (pilmat == 6) {
					matkul = "PENDIDIKAN AGAMA ISLAM";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "F";
					
				} else if (pilmat == 7){
					matkul = "PENDIDIKAN AGAMA ISLAM";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "R";
				}	
			}
			else if (pil == 2){
				
				gotoxy(32,9); cout<<"|  1  | PENDIDIKAN KEWARGANEGARAAN                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | PENDIDIKAN KEWARGANEGARAAN                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | PENDIDIKAN KEWARGANEGARAAN                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | PENDIDIKAN KEWARGANEGARAAN                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | PENDIDIKAN KEWARGANEGARAAN                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | PENDIDIKAN KEWARGANEGARAAN                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | PENDIDIKAN KEWARGANEGARAAN                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
				
				if (pilmat == 1){
					matkul = "PENDIDIKAN KEWARGANEGARAAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "A";
					
				}
				else if (pilmat == 2){
					matkul = "PENDIDIKAN KEWARGANEGARAAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "B";
					
				} 
				else if (pilmat == 3){
					matkul = "PENDIDIKAN KEWARGANEGARAAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "C";
					
				}
				else if (pilmat == 4){
					matkul = "PENDIDIKAN KEWARGANEGARAAN";
					kodeMatkul = "Unknown";
					dosen = "MATKUL FEB 1 2";
					sks = 4;
					kelas = "D";
					
				} else if (pilmat == 5){
					matkul = "PENDIDIKAN KEWARGANEGARAAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "E";
					
				} else if (pilmat == 6){
					matkul = "PENDIDIKAN KEWARGANEGARAAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "F";		
					
				} else if (pilmat == 7){
					matkul = "PENDIDIKAN KEWARGANEGARAAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "R";
					
				}
			}
			else if (pil == 3){
				
				gotoxy(32,9); cout<<"|  1  | STATISTIK                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | STATISTIK                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | STATISTIK                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | STATISTIK                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | STATISTIK                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | STATISTIK                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | STATISTIK                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
					
				if (pilmat == 1){
					matkul = "STATISTIK";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "A";
				} 
				else if (pilmat == 2){
					matkul = "STATISTIK";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "B";	
				} 
				else if (pilmat == 3){
					matkul = "STATISTIK";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "C";	
				} 
				else if (pilmat == 4){
					matkul = "STATISTIK";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "D";	
				} 
				else if (pilmat == 5){
					matkul = "STATISTIK";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "E";	
				} 
				else if (pilmat == 6){
					matkul = "STATISTIK";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "F";
				} 
				else if (pilmat == 7){
					matkul = "STATISTIK";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "R";
				}	
			}	
			else if (pil == 4){
				
				gotoxy(32,9); cout<<"|  1  | EKONOMI PEMBANGUNAN                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | EKONOMI PEMBANGUNAN                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | EKONOMI PEMBANGUNAN                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | EKONOMI PEMBANGUNAN                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | EKONOMI PEMBANGUNAN                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | EKONOMI PEMBANGUNAN                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | EKONOMI PEMBANGUNAN                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
					
				if (pilmat == 1){
					
					matkul = "EKONOMI PEMBANGUNAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IA";		
				} 
				else if (pilmat == 2){
					
					matkul = "EKONOMI PEMBANGUNAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IB";		
				} 
				else if (pilmat == 3){
							
					matkul = "EKONOMI PEMBANGUNAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IC";		
				} 
				else if (pilmat == 4){
						
					matkul = "EKONOMI PEMBANGUNAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "ID";
						
				} 
				else if (pilmat == 5){
						
					matkul = "EKONOMI PEMBANGUNAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IE";		
				} 
				else if (pilmat == 6){
						
					matkul = "EKONOMI PEMBANGUNAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IF";		
				} 
				else if (pilmat == 7){
						
					matkul = "EKONOMI PEMBANGUNAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IR";		
				}	
			}
			
			else if (pil == 5){
				
				gotoxy(32,9); cout<<"|  1  | TEORI EKONOMI MAKRO                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | TEORI EKONOMI MAKRO                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | TEORI EKONOMI MAKRO                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | TEORI EKONOMI MAKRO                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | TEORI EKONOMI MAKRO                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | TEORI EKONOMI MAKRO                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | TEORI EKONOMI MAKRO                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
					
				if (pilmat == 1){
				
					matkul = "TEORI EKONOMI MAKRO";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "A";
				} 	
				else if (pilmat == 2){
				
					matkul = "TEORI EKONOMI MAKRO";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "B";
				} 				
				else if (pilmat == 3){
				
					matkul = "TEORI EKONOMI MAKRO";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "C";
				} 
				
				else if (pilmat == 4){
				
					matkul = "TEORI EKONOMI MAKRO";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "D";	
				} 
				
				else if (pilmat == 5){
				
					matkul = "TEORI EKONOMI MAKRO";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "E";
				} 
				
				else if (pilmat == 6){
				
					matkul = "TEORI EKONOMI MAKRO";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "F";
				} 
				else if (pilmat == 7){
				
					matkul = "TEORI EKONOMI MAKRO";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "R";
				}	
			}
			
			else if (pil == 6){
				
				gotoxy(32,9); cout<<"|  1  | PENGANTAR MANAJEMEN                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | PENGANTAR MANAJEMEN                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | PENGANTAR MANAJEMEN                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | PENGANTAR MANAJEMEN                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | PENGANTAR MANAJEMEN                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | PENGANTAR MANAJEMEN                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | PENGANTAR MANAJEMEN                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
					
				if (pilmat == 1){
					
					matkul = "PENGANTAR MANAJEMEN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "A";
				} 
				else if (pil == 2){
					
					matkul = "PENGANTAR MANAJEMEN";
					kodeMatkul = "14620063";
					dosen = "Unknown";
					sks = 3;
					kelas = "B";
				}
				else if (pil == 3){
					
					matkul = "PENGANTAR MANAJEMEN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "C";
				} 
				else if (pil == 4){
					
					matkul = "PENGANTAR MANAJEMEN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "D";
	
				} else if (pil == 5){
					matkul = "PENGANTAR MANAJEMEN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "E";
				} else if (pil == 6){
					matkul = "PENGANTAR MANAJEMEN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "F";
				} else if (pil == 7){
					matkul = "PENGANTAR MANAJEMEN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "R";
				}
					
			}
			if (pil == 7) {
				break;
			}
			batas = batas + sks;
			
			if(batas > 24){
				cout << endl<<endl;
				cout << "input SKS anda melebihi batas !! "<<endl<<endl;
				
				cout << "Jumlah SKS yang Melebihi Batas : ";
				cout << batas<<endl;
				
				cout << "Matkul yang tidak bisa Diinputkan : ";
				cout << matkul<<endl;
				
				cout << "SKS dari Mata Kuliah " << matkul << " adalah : "; 
				cout << sks<<endl;
			
				cout << "Total Mata Kuliah yang Telah Diambil : ";
				cout << baru->total<<endl;
				
				cout << "Index : ";
				cout << i<<endl<<endl;
				
				getch();
				
				cout << "Mau memperbarui data sks terakhir anda ?" ;
				cin >> ulang;
					
				batas = batas - sks;
					
				if(ulang == 'y')
					continue;
				else
					break;
			}	
						
			if (batas <= 24){
							
				if(batas == 24){
					
					cout << endl;
					cout << endl;
					cout<<"Batas SKS tercapai !!";
				}
							
				baru->matkul[i] = matkul;
				baru->sks[i] = sks;
				baru->kodeMatkul[i] = kodeMatkul;
				baru->dosen[i] = dosen;
				baru->kelas[i] = kelas;
				baru->total++;
//				i++;
				
				if (batas < 24){
					cout << "tambah ? ";
					cin >> ulang;
						
						
					if (ulang == 't'){
						break;
					}	
				}
				
				cout << endl;
				cout << endl;
				cout << "Jumlah SKS yang sudah diambil : ";
				cout << batas;
				cout << endl << endl;
				
				cout << "Matkul yang Diinputkan : ";
				cout << matkul;
				cout << endl << endl;
				
				cout << "SKS dari Mata Kuliah " << matkul << " adalah : "; 
				cout << sks;
				cout << endl << endl;
			
				cout << "Total Mata Kuliah yang Telah Diambil : ";
				cout << baru->total;
				cout << endl << endl;
				
				cout << "Index : ";
				cout << i;
				cout << endl;
				cout << endl;
				
				i++;
				
				getch();
							
			}
		}
	}
	
	
	else if (fakultas[kodeFak] == fakultas[0] && pos3 == feb[2]){
		while ( ulang == 'y'){
	
			system("cls");
			gotoxy(16,2); cout<<"Nama : "<<baru->nama;
			gotoxy(16,3); cout<<"NBI  : "<<baru->nbi;
			gotoxy(66,2); cout<<"Fakultas : "<<baru->fakultas;
			gotoxy(66,3); cout<<"Jurusan  : "<<baru->jurusan;
			gotoxy(15,4); cout<<"=========================================================================================";
			gotoxy(50,5); cout<<"PILIHAN MATA KULIAH";
			gotoxy(32,6); cout<<"=========================================================";
			gotoxy(32,7); cout<<"| PIL |                  NAMA                     | SKS |";
			gotoxy(32,8); cout<<"=========================================================";
			gotoxy(32,9); cout<<"|  1  | PENDIDIKAN AGAMA ISLAM                     |  3  |";
			gotoxy(32,10); cout<<"|  2  | AKUNTANSI KEUANGAN                        |  4  |";
			gotoxy(32,11); cout<<"|  3  | AKUNTANSI BIAYA                           |  3  |";
			gotoxy(32,12); cout<<"|  4  | BAHASA INGGRIS                            |  2  |";
			gotoxy(32,13); cout<<"|  5  | PENGANTAR MANAJEMEN                       |  4  |";
			gotoxy(32,14); cout<<"|  6  | HUKUM BISNIS                              |  3  |";
			gotoxy(32,15); cout<<"=========================================================";
			gotoxy(32,16); cout<<"|                                              (7) EXIT |";
			gotoxy(32,17); cout<<"=========================================================";
			gotoxy(32,19); cout<<"Pilihan Anda : ";
			gotoxy(47,19); cin>>pil;
			
			system("cls");
			gotoxy(16,2); cout<<"Nama : "<<baru->nama;
			gotoxy(16,3); cout<<"NBI  : "<<baru->nbi;
			gotoxy(66,2); cout<<"Fakultas : "<<baru->fakultas;
			gotoxy(66,3); cout<<"Jurusan  : "<<baru->jurusan;
			gotoxy(15,4); cout<<"=========================================================================================";
			gotoxy(50,5); cout<<"PILIHAN MATA KULIAH";
			gotoxy(32,6); cout<<"=========================================================";
			gotoxy(32,7); cout<<"| PIL |                  NAMA                   | KELAS |";
			gotoxy(32,8); cout<<"=========================================================";
				
			if (pil == 1){
				
				gotoxy(32,9); cout<<"|  1  | PENDIDIKAN AGAMA ISLAM                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | PENDIDIKAN AGAMA ISLAM                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | PENDIDIKAN AGAMA ISLAM                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | PENDIDIKAN AGAMA ISLAM                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | PENDIDIKAN AGAMA ISLAM                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | PENDIDIKAN AGAMA ISLAM                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | PENDIDIKAN AGAMA ISLAM                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
				
				if (pilmat == 1){
	
					matkul = "PENDIDIKAN AGAMA ISLAM";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "A";
	
				} else if (pilmat == 2){
					matkul = "PENDIDIKAN AGAMA ISLAM";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "B";
	
				} else if (pilmat == 3){
					matkul = "PENDIDIKAN AGAMA ISLAM";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "C";
	
				}else if (pilmat == 4){
					matkul = "PENDIDIKAN AGAMA ISLAM";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "D";
					
				}else if (pilmat == 5){
					matkul = "PENDIDIKAN AGAMA ISLAM";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "E";
				
				} else if (pilmat == 6) {
					matkul = "PENDIDIKAN AGAMA ISLAM";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "F";
					
				} else if (pilmat == 7){
					matkul = "PENDIDIKAN AGAMA ISLAM";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "R";
				}	
			}
			else if (pil == 2){
				
				gotoxy(32,9); cout<<"|  1  | AKUNTANSI KEUANGAN                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | AKUNTANSI KEUANGAN                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | AKUNTANSI KEUANGAN                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | AKUNTANSI KEUANGAN                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | AKUNTANSI KEUANGAN                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | AKUNTANSI KEUANGAN                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | AKUNTANSI KEUANGAN                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
				
				if (pilmat == 1){
					matkul = "AKUNTANSI KEUANGAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "A";
					
				}
				else if (pilmat == 2){
					matkul = "AKUNTANSI KEUANGAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "B";
					
				} 
				else if (pilmat == 3){
					matkul = "AKUNTANSI KEUANGAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "C";
					
				}
				else if (pilmat == 4){
					matkul = "AKUNTANSI KEUANGAN";
					kodeMatkul = "Unknown";
					dosen = "MATKUL FEB 1 2";
					sks = 4;
					kelas = "D";
					
				} else if (pilmat == 5){
					matkul = "AKUNTANSI KEUANGAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "E";
					
				} else if (pilmat == 6){
					matkul = "AKUNTANSI KEUANGAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "F";		
					
				} else if (pilmat == 7){
					matkul = "AKUNTANSI KEUANGAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "R";
					
				}
			}
			else if (pil == 3){
				
				gotoxy(32,9); cout<<"|  1  | AKUNTANSI BIAYA                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | AKUNTANSI BIAYA                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | AKUNTANSI BIAYA                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | AKUNTANSI BIAYA                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | AKUNTANSI BIAYA                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | AKUNTANSI BIAYA                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | AKUNTANSI BIAYA                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
					
				if (pilmat == 1){
					matkul = "AKUNTANSI BIAYA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "A";
				} 
				else if (pilmat == 2){
					matkul = "AKUNTANSI BIAYA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "B";	
				} 
				else if (pilmat == 3){
					matkul = "AKUNTANSI BIAYA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "C";	
				} 
				else if (pilmat == 4){
					matkul = "AKUNTANSI BIAYA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "D";	
				} 
				else if (pilmat == 5){
					matkul = "AKUNTANSI BIAYA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "E";	
				} 
				else if (pilmat == 6){
					matkul = "AKUNTANSI BIAYA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "F";
				} 
				else if (pilmat == 7){
					matkul = "AKUNTANSI BIAYA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "R";
				}	
			}	
			else if (pil == 4){
				
				gotoxy(32,9); cout<<"|  1  | BAHASA INGGRIS                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | BAHASA INGGRIS                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | BAHASA INGGRIS                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | BAHASA INGGRIS                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | BAHASA INGGRIS                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | BAHASA INGGRIS                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | BAHASA INGGRIS                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
					
				if (pilmat == 1){
					
					matkul = "BAHASA INGGRIS";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IA";		
				} 
				else if (pilmat == 2){
					
					matkul = "BAHASA INGGRIS";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IB";		
				} 
				else if (pilmat == 3){
							
					matkul = "BAHASA INGGRIS";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IC";		
				} 
				else if (pilmat == 4){
						
					matkul = "BAHASA INGGRIS";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "ID";
						
				} 
				else if (pilmat == 5){
						
					matkul = "BAHASA INGGRIS";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IE";		
				} 
				else if (pilmat == 6){
						
					matkul = "BAHASA INGGRIS";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IF";		
				} 
				else if (pilmat == 7){
						
					matkul = "BAHASA INGGRIS";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IR";		
				}	
			}
			
			else if (pil == 5){
				
				gotoxy(32,9); cout<<"|  1  | PENGANTAR MANAJEMEN                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | PENGANTAR MANAJEMEN                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | PENGANTAR MANAJEMEN                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | PENGANTAR MANAJEMEN                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | PENGANTAR MANAJEMEN                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | PENGANTAR MANAJEMEN                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | PENGANTAR MANAJEMEN                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
					
				if (pilmat == 1){
				
					matkul = "PENGANTAR MANAJEMEN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "A";
				} 	
				else if (pilmat == 2){
				
					matkul = "PENGANTAR MANAJEMEN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "B";
				} 				
				else if (pilmat == 3){
				
					matkul = "PENGANTAR MANAJEMEN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "C";
				} 
				
				else if (pilmat == 4){
				
					matkul = "PENGANTAR MANAJEMEN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "D";	
				} 
				
				else if (pilmat == 5){
				
					matkul = "PENGANTAR MANAJEMEN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "E";
				} 
				
				else if (pilmat == 6){
				
					matkul = "PENGANTAR MANAJEMEN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "F";
				} 
				else if (pilmat == 7){
				
					matkul = "PENGANTAR MANAJEMEN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "R";
				}	
			}
			
			else if (pil == 6){
				
				gotoxy(32,9); cout<<"|  1  | HUKUM BISNIS                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | HUKUM BISNIS                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | HUKUM BISNIS                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | HUKUM BISNIS                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | HUKUM BISNIS                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | HUKUM BISNIS                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | HUKUM BISNIS                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
					
				if (pilmat == 1){
					
					matkul = "HUKUM BISNIS";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "A";
				} 
				else if (pil == 2){
					
					matkul = "HUKUM BISNIS";
					kodeMatkul = "14620063";
					dosen = "Unknown";
					sks = 3;
					kelas = "B";
				}
				else if (pil == 3){
					
					matkul = "HUKUM BISNIS";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "C";
				} 
				else if (pil == 4){
					
					matkul = "HUKUM BISNIS";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "D";
	
				} else if (pil == 5){
					matkul = "HUKUM BISNIS";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "E";
				} else if (pil == 6){
					matkul = "HUKUM BISNIS";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "F";
				} else if (pil == 7){
					matkul = "HUKUM BISNIS";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "R";
				}
					
			}
			if (pil == 7) {
				break;
			}
			batas = batas + sks;
			
			if(batas > 24){
				cout << endl<<endl;
				cout << "input SKS anda melebihi batas !! "<<endl<<endl;
				
				cout << "Jumlah SKS yang Melebihi Batas : ";
				cout << batas<<endl;
				
				cout << "Matkul yang tidak bisa Diinputkan : ";
				cout << matkul<<endl;
				
				cout << "SKS dari Mata Kuliah " << matkul << " adalah : "; 
				cout << sks<<endl;
			
				cout << "Total Mata Kuliah yang Telah Diambil : ";
				cout << baru->total<<endl;
				
				cout << "Index : ";
				cout << i<<endl<<endl;
				
				getch();
				
				cout << "Mau memperbarui data sks terakhir anda ?" ;
				cin >> ulang;
					
				batas = batas - sks;
					
				if(ulang == 'y')
					continue;
				else
					break;
			}	
						
			if (batas <= 24){
							
				if(batas == 24){
					
					cout << endl;
					cout << endl;
					cout<<"Batas SKS tercapai !!";
				}
							
				baru->matkul[i] = matkul;
				baru->sks[i] = sks;
				baru->kodeMatkul[i] = kodeMatkul;
				baru->dosen[i] = dosen;
				baru->kelas[i] = kelas;
				baru->total++;
//				i++;
				
				if (batas < 24){
					cout << "tambah ? ";
					cin >> ulang;
						
						
					if (ulang == 't'){
						break;
					}	
				}
				
				cout << endl;
				cout << endl;
				cout << "Jumlah SKS yang sudah diambil : ";
				cout << batas;
				cout << endl << endl;
				
				cout << "Matkul yang Diinputkan : ";
				cout << matkul;
				cout << endl << endl;
				
				cout << "SKS dari Mata Kuliah " << matkul << " adalah : "; 
				cout << sks;
				cout << endl << endl;
			
				cout << "Total Mata Kuliah yang Telah Diambil : ";
				cout << baru->total;
				cout << endl << endl;
				
				cout << "Index : ";
				cout << i;
				cout << endl;
				cout << endl;
				
				i++;
				
				getch();
							
			}
		}
	}
	
	else if (fakultas[kodeFak] == fakultas[1] && pos3 == fh[0]){
		while ( ulang == 'y'){
	
			system("cls");
			
			gotoxy(16,2); cout<<"Nama : "<<baru->nama;
			gotoxy(16,3); cout<<"NBI  : "<<baru->nbi;
			gotoxy(66,2); cout<<"Fakultas : "<<baru->fakultas;
			gotoxy(66,3); cout<<"Jurusan  : "<<baru->jurusan;
			gotoxy(15,4); cout<<"=========================================================================================";
			gotoxy(50,5); cout<<"PILIHAN MATA KULIAH";
			gotoxy(32,6); cout<<"=========================================================";
			gotoxy(32,7); cout<<"| PIL |                  NAMA                     | SKS |";
			gotoxy(32,8); cout<<"=========================================================";
			gotoxy(32,9); cout<<"|  1  | PENGANTAR ILMU HUKUM                      |  3  |";
			gotoxy(32,10); cout<<"|  2  | SOSIOLOGI HUKUM                           |  4  |";
			gotoxy(32,11); cout<<"|  3  | BAHASA INGGRIS                            |  3  |";
			gotoxy(32,12); cout<<"|  4  | ILMU NEGARA                               |  2  |";
			gotoxy(32,13); cout<<"|  5  | SEJARAH HUKUM                             |  4  |";
			gotoxy(32,14); cout<<"|  6  | BAHSA INDONESIA                           |  3  |";
			gotoxy(32,15); cout<<"=========================================================";
			gotoxy(32,16); cout<<"|                                              (7) EXIT |";
			gotoxy(32,17); cout<<"=========================================================";
			gotoxy(32,19); cout<<"Pilihan Anda : ";
			gotoxy(47,19); cin>>pil;
			
			system("cls");
			gotoxy(16,2); cout<<"Nama : "<<baru->nama;
			gotoxy(16,3); cout<<"NBI  : "<<baru->nbi;
			gotoxy(66,2); cout<<"Fakultas : "<<baru->fakultas;
			gotoxy(66,3); cout<<"Jurusan  : "<<baru->jurusan;
			gotoxy(15,4); cout<<"=========================================================================================";
			gotoxy(50,5); cout<<"PILIHAN MATA KULIAH";
			gotoxy(32,6); cout<<"=========================================================";
			gotoxy(32,7); cout<<"| PIL |                  NAMA                   | KELAS |";
			gotoxy(32,8); cout<<"=========================================================";
				
			if (pil == 1){
				
				gotoxy(32,9); cout<<"|  1  | PENGANTAR ILMU HUKUM                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | PENGANTAR ILMU HUKUM                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | PENGANTAR ILMU HUKUM                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | PENGANTAR ILMU HUKUM                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | PENGANTAR ILMU HUKUM                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | PENGANTAR ILMU HUKUM                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | PENGANTAR ILMU HUKUM                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
				
				if (pilmat == 1){
	
					matkul = "PENGANTAR ILMU HUKUM";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "A";
	
				} else if (pilmat == 2){
					matkul = "PENGANTAR ILMU HUKUM";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "B";
	
				} else if (pilmat == 3){
					matkul = "PENGANTAR ILMU HUKUM";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "C";
	
				}else if (pilmat == 4){
					matkul = "PENGANTAR ILMU HUKUM";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "D";
					
				}else if (pilmat == 5){
					matkul = "PENGANTAR ILMU HUKUM";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "E";
				
				} else if (pilmat == 6) {
					matkul = "PENGANTAR ILMU HUKUM";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "F";
					
				} else if (pilmat == 7){
					matkul = "PENGANTAR ILMU HUKUM";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "R";
				}	
			}
			else if (pil == 2){
				
				gotoxy(32,9); cout<<"|  1  | SOSIOLOGI HUKUM			  	|  A  |";
				gotoxy(32,10); cout<<"|  2  | SOSIOLOGI HUKUM			 	|  B  |";
				gotoxy(32,11); cout<<"|  3  | SOSIOLOGI HUKUM			 	|  C  |";
				gotoxy(32,12); cout<<"|  4  | SOSIOLOGI HUKUM	 		 	|  D  |";
				gotoxy(32,13); cout<<"|  5  | SOSIOLOGI HUKUM	 		 	|  E  |";
				gotoxy(32,14); cout<<"|  6  | SOSIOLOGI HUKUM	 		 	|  F  |";
				gotoxy(32,15); cout<<"|  7  | SOSIOLOGI HUKUM	 		 	|  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
				
				if (pilmat == 1){
					matkul = "SOSIOLOGI HUKUM";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "A";
					
				}
				else if (pilmat == 2){
					matkul = "SOSIOLOGI HUKUM";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "B";
					
				} 
				else if (pilmat == 3){
					matkul = "SOSIOLOGI HUKUM";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "C";
					
				}
				else if (pilmat == 4){
					matkul = "SOSIOLOGI HUKUM";
					kodeMatkul = "Unknown";
					dosen = "MATKUL FT 1 2";
					sks = 4;
					kelas = "D";
					
				} else if (pilmat == 5){
					matkul = "SOSIOLOGI HUKUM";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "E";
					
				} else if (pilmat == 6){
					matkul = "SOSIOLOGI HUKUM";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "F";		
					
				} else if (pilmat == 7){
					matkul = "SOSIOLOGI HUKUM";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "R";
					
				}
			}
			else if (pil == 3){
				
				gotoxy(32,9); cout<<"|  1  | BAHASA INGGRIS                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | BAHASA INGGRIS                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | BAHASA INGGRIS                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | BAHASA INGGRIS                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | BAHASA INGGRIS                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | BAHASA INGGRIS                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | BAHASA INGGRIS                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
					
				if (pilmat == 1){
					matkul = "BAHASA INGGRIS";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "A";
				} 
				else if (pilmat == 2){
					matkul = "BAHASA INGGRIS";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "B";	
				} 
				else if (pilmat == 3){
					matkul = "BAHASA INGGRIS";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "C";	
				} 
				else if (pilmat == 4){
					matkul = "BAHASA INGGRIS";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "D";	
				} 
				else if (pilmat == 5){
					matkul = "BAHASA INGGRIS";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "E";	
				} 
				else if (pilmat == 6){
					matkul = "BAHASA INGGRIS";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "F";
				} 
				else if (pilmat == 7){
					matkul = "BAHASA INGGRIS";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "R";
				}	
			}	
			else if (pil == 4){
				
				gotoxy(32,9); cout<<"|  1  | ILMU NEGARA                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | ILMU NEGARA                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | ILMU NEGARA                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | ILMU NEGARA                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | ILMU NEGARA                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | ILMU NEGARA                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | ILMU NEGARA                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
					
				if (pilmat == 1){
					
					matkul = "ILMU NEGARA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IA";		
				} 
				else if (pilmat == 2){
					
					matkul = "ILMU NEGARA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IB";		
				} 
				else if (pilmat == 3){
							
					matkul = "ILMU NEGARA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IC";		
				} 
				else if (pilmat == 4){
						
					matkul = "ILMU NEGARA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "ID";
						
				} 
				else if (pilmat == 5){
						
					matkul = "ILMU NEGARA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IE";		
				} 
				else if (pilmat == 6){
						
					matkul = "ILMU NEGARA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IF";		
				} 
				else if (pilmat == 7){
						
					matkul = "ILMU NEGARA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IR";		
				}	
			}
			
			else if (pil == 5){
				
				gotoxy(32,9); cout<<"|  1  | SEJARAH HUKUM                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | SEJARAH HUKUM                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | SEJARAH HUKUM                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | SEJARAH HUKUM                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | SEJARAH HUKUM                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | SEJARAH HUKUM                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | SEJARAH HUKUM                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
					
				if (pilmat == 1){
				
					matkul = "SEJARAH HUKUM";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "A";
				} 	
				else if (pilmat == 2){
				
					matkul = "SEJARAH HUKUM";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "B";
				} 				
				else if (pilmat == 3){
				
					matkul = "SEJARAH HUKUM";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "C";
				} 
				
				else if (pilmat == 4){
				
					matkul = "SEJARAH HUKUM";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "D";	
				} 
				
				else if (pilmat == 5){
				
					matkul = "SEJARAH HUKUM";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "E";
				} 
				
				else if (pilmat == 6){
				
					matkul = "SEJARAH HUKUM";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "F";
				} 
				else if (pilmat == 7){
				
					matkul = "SEJARAH HUKUM";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "R";
				}	
			}
			
			else if (pil == 6){
				
				gotoxy(32,9); cout<<"|  1  | BAHSA INDONESIA                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | BAHSA INDONESIA                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | BAHSA INDONESIA                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | BAHSA INDONESIA                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | BAHSA INDONESIA                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | BAHSA INDONESIA                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | BAHSA INDONESIA                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
					
				if (pilmat == 1){
					
					matkul = "BAHSA INDONESIA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "A";
				} 
				else if (pil == 2){
					
					matkul = "BAHSA INDONESIA";
					kodeMatkul = "14620063";
					dosen = "Unknown";
					sks = 3;
					kelas = "B";
				}
				else if (pil == 3){
					
					matkul = "BAHSA INDONESIA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "C";
				} 
				else if (pil == 4){
					
					matkul = "BAHSA INDONESIA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "D";
	
				} else if (pil == 5){
					matkul = "BAHSA INDONESIA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "E";
				} else if (pil == 6){
					matkul = "BAHSA INDONESIA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "F";
				} else if (pil == 7){
					matkul = "BAHSA INDONESIA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "R";
				}
					
			}
			if (pil == 7) {
				break;
			}
			batas = batas + sks;
			
			if(batas > 24){
				cout << endl<<endl;
				cout << "input SKS anda melebihi batas !! "<<endl<<endl;
				
				cout << "Jumlah SKS yang Melebihi Batas : ";
				cout << batas<<endl;
				
				cout << "Matkul yang tidak bisa Diinputkan : ";
				cout << matkul<<endl;
				
				cout << "SKS dari Mata Kuliah " << matkul << " adalah : "; 
				cout << sks<<endl;
			
				cout << "Total Mata Kuliah yang Telah Diambil : ";
				cout << baru->total<<endl;
				
				cout << "Index : ";
				cout << i<<endl<<endl;
				
				getch();
				
				cout << "Mau memperbarui data sks terakhir anda ?" ;
				cin >> ulang;
					
				batas = batas - sks;
					
				if(ulang == 'y')
					continue;
				else
					break;
			}	
						
			if (batas <= 24){
							
				if(batas == 24){
					
					cout << endl;
					cout << endl;
					cout<<"Batas SKS tercapai !!";
				}
							
				baru->matkul[i] = matkul;
				baru->sks[i] = sks;
				baru->kodeMatkul[i] = kodeMatkul;
				baru->dosen[i] = dosen;
				baru->kelas[i] = kelas;
				baru->total++;
//				i++;
				
				if (batas < 24){
					cout << "tambah ? ";
					cin >> ulang;
						
						
					if (ulang == 't'){
						break;
					}	
				}
				
				cout << endl;
				cout << endl;
				cout << "Jumlah SKS yang sudah diambil : ";
				cout << batas;
				cout << endl << endl;
				
				cout << "Matkul yang Diinputkan : ";
				cout << matkul;
				cout << endl << endl;
				
				cout << "SKS dari Mata Kuliah " << matkul << " adalah : "; 
				cout << sks;
				cout << endl << endl;
			
				cout << "Total Mata Kuliah yang Telah Diambil : ";
				cout << baru->total;
				cout << endl << endl;
				
				cout << "Index : ";
				cout << i;
				cout << endl;
				cout << endl;
				
				i++;
				
				getch();
							
			}
		}
}

	else if (fakultas[kodeFak] == fakultas[2] && pos3 == fib[0]){
		while ( ulang == 'y'){
	
			system("cls");
			
			gotoxy(16,2); cout<<"Nama : "<<baru->nama;
			gotoxy(16,3); cout<<"NBI  : "<<baru->nbi;
			gotoxy(66,2); cout<<"Fakultas : "<<baru->fakultas;
			gotoxy(66,3); cout<<"Jurusan  : "<<baru->jurusan;
			gotoxy(15,4); cout<<"=========================================================================================";
			gotoxy(50,5); cout<<"PILIHAN MATA KULIAH";
			gotoxy(32,6); cout<<"=========================================================";
			gotoxy(32,7); cout<<"| PIL |                  NAMA                     | SKS |";
			gotoxy(32,8); cout<<"=========================================================";
			gotoxy(32,9); cout<<"|  1  | PENDIDIKAN AGAMA                          |  3  |";
			gotoxy(32,10); cout<<"|  2  | PENDIDIKAN KEWARGANEGARAAN                |  4  |";
			gotoxy(32,11); cout<<"|  3  | KISO NIHONGO                              |  3  |";
			gotoxy(32,12); cout<<"|  4  | NIHONGGO MANTAPPU                         |  2  |";
			gotoxy(32,13); cout<<"|  5  | KAWAIKUTE GOMEN                           |  4  |";
			gotoxy(32,14); cout<<"|  6  | KIMI NO NAWA                              |  3  |";
			gotoxy(32,15); cout<<"=========================================================";
			gotoxy(32,16); cout<<"|                                              (7) EXIT |";
			gotoxy(32,17); cout<<"=========================================================";
			gotoxy(32,19); cout<<"Pilihan Anda : ";
			gotoxy(47,19); cin>>pil;
			
			system("cls");
			gotoxy(16,2); cout<<"Nama : "<<baru->nama;
			gotoxy(16,3); cout<<"NBI  : "<<baru->nbi;
			gotoxy(66,2); cout<<"Fakultas : "<<baru->fakultas;
			gotoxy(66,3); cout<<"Jurusan  : "<<baru->jurusan;
			gotoxy(15,4); cout<<"=========================================================================================";
			gotoxy(50,5); cout<<"PILIHAN MATA KULIAH";
			gotoxy(32,6); cout<<"=========================================================";
			gotoxy(32,7); cout<<"| PIL |                  NAMA                   | KELAS |";
			gotoxy(32,8); cout<<"=========================================================";
				
			if (pil == 1){
				
				gotoxy(32,9); cout<<"|  1  | PENDIDIKAN AGAMA                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | PENDIDIKAN AGAMA                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | PENDIDIKAN AGAMA                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | PENDIDIKAN AGAMA                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | PENDIDIKAN AGAMA                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | PENDIDIKAN AGAMA                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | PENDIDIKAN AGAMA                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
				
				if (pilmat == 1){
	
					matkul = "PENDIDIKAN AGAMA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "A";
	
				} else if (pilmat == 2){
					matkul = "PENDIDIKAN AGAMA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "B";
	
				} else if (pilmat == 3){
					matkul = "PENDIDIKAN AGAMA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "C";
	
				}else if (pilmat == 4){
					matkul = "PENDIDIKAN AGAMA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "D";
					
				}else if (pilmat == 5){
					matkul = "PENDIDIKAN AGAMA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "E";
				
				} else if (pilmat == 6) {
					matkul = "PENDIDIKAN AGAMA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "F";
					
				} else if (pilmat == 7){
					matkul = "PENDIDIKAN AGAMA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "R";
				}	
			}
			else if (pil == 2){
				
				gotoxy(32,9); cout<<"|  1  | PENDIDIKAN KEWARGANEGARAAN                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | PENDIDIKAN KEWARGANEGARAAN                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | PENDIDIKAN KEWARGANEGARAAN                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | PENDIDIKAN KEWARGANEGARAAN                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | PENDIDIKAN KEWARGANEGARAAN                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | PENDIDIKAN KEWARGANEGARAAN                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | PENDIDIKAN KEWARGANEGARAAN                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
				
				if (pilmat == 1){
					matkul = "PENDIDIKAN KEWARGANEGARAAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "A";
					
				}
				else if (pilmat == 2){
					matkul = "PENDIDIKAN KEWARGANEGARAAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "B";
					
				} 
				else if (pilmat == 3){
					matkul = "PENDIDIKAN KEWARGANEGARAAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "C";
					
				}
				else if (pilmat == 4){
					matkul = "PENDIDIKAN KEWARGANEGARAAN";
					kodeMatkul = "Unknown";
					dosen = "MATKUL FIB 1 2";
					sks = 4;
					kelas = "D";
					
				} else if (pilmat == 5){
					matkul = "PENDIDIKAN KEWARGANEGARAAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "E";
					
				} else if (pilmat == 6){
					matkul = "PENDIDIKAN KEWARGANEGARAAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "F";		
					
				} else if (pilmat == 7){
					matkul = "PENDIDIKAN KEWARGANEGARAAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "R";
					
				}
			}
			else if (pil == 3){
				
				gotoxy(32,9); cout<<"|  1  | KISO NIHONGO                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | KISO NIHONGO                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | KISO NIHONGO                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | KISO NIHONGO                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | KISO NIHONGO                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | KISO NIHONGO                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | KISO NIHONGO                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
					
				if (pilmat == 1){
					matkul = "KISO NIHONGO";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "A";
				} 
				else if (pilmat == 2){
					matkul = "KISO NIHONGO";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "B";	
				} 
				else if (pilmat == 3){
					matkul = "KISO NIHONGO";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "C";	
				} 
				else if (pilmat == 4){
					matkul = "KISO NIHONGO";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "D";	
				} 
				else if (pilmat == 5){
					matkul = "KISO NIHONGO";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "E";	
				} 
				else if (pilmat == 6){
					matkul = "KISO NIHONGO";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "F";
				} 
				else if (pilmat == 7){
					matkul = "KISO NIHONGO";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "R";
				}	
			}	
			else if (pil == 4){
				
				gotoxy(32,9); cout<<"|  1  | NIHONGGO MANTAPPU                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | NIHONGGO MANTAPPU                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | NIHONGGO MANTAPPU                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | NIHONGGO MANTAPPU                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | NIHONGGO MANTAPPU                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | NIHONGGO MANTAPPU                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | NIHONGGO MANTAPPU                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
					
				if (pilmat == 1){
					
					matkul = "NIHONGGO MANTAPPU";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IA";		
				} 
				else if (pilmat == 2){
					
					matkul = "NIHONGGO MANTAPPU";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IB";		
				} 
				else if (pilmat == 3){
							
					matkul = "NIHONGGO MANTAPPU";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IC";		
				} 
				else if (pilmat == 4){
						
					matkul = "NIHONGGO MANTAPPU";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "ID";
						
				} 
				else if (pilmat == 5){
						
					matkul = "NIHONGGO MANTAPPU";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IE";		
				} 
				else if (pilmat == 6){
						
					matkul = "NIHONGGO MANTAPPU";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IF";		
				} 
				else if (pilmat == 7){
						
					matkul = "NIHONGGO MANTAPPU";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IR";		
				}	
			}
			
			else if (pil == 5){
				
				gotoxy(32,9); cout<<"|  1  | KAWAIKUTE GOMEN                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | KAWAIKUTE GOMEN                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | KAWAIKUTE GOMEN                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | KAWAIKUTE GOMEN                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | KAWAIKUTE GOMEN                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | KAWAIKUTE GOMEN                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | KAWAIKUTE GOMEN                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
					
				if (pilmat == 1){
				
					matkul = "KAWAIKUTE GOMEN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "A";
				} 	
				else if (pilmat == 2){
				
					matkul = "KAWAIKUTE GOMEN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "B";
				} 				
				else if (pilmat == 3){
				
					matkul = "KAWAIKUTE GOMEN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "C";
				} 
				
				else if (pilmat == 4){
				
					matkul = "KAWAIKUTE GOMEN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "D";	
				} 
				
				else if (pilmat == 5){
				
					matkul = "KAWAIKUTE GOMEN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "E";
				} 
				
				else if (pilmat == 6){
				
					matkul = "KAWAIKUTE GOMEN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "F";
				} 
				else if (pilmat == 7){
				
					matkul = "KAWAIKUTE GOMEN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "R";
				}	
			}
			
			else if (pil == 6){
				
				gotoxy(32,9); cout<<"|  1  | KIMI NO NAWA                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | KIMI NO NAWA                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | KIMI NO NAWA                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | KIMI NO NAWA                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | KIMI NO NAWA                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | KIMI NO NAWA                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | KIMI NO NAWA                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
					
				if (pilmat == 1){
					
					matkul = "KIMI NO NAWA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "A";
				} 
				else if (pil == 2){
					
					matkul = "KIMI NO NAWA";
					kodeMatkul = "14620063";
					dosen = "Unknown";
					sks = 3;
					kelas = "B";
				}
				else if (pil == 3){
					
					matkul = "KIMI NO NAWA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "C";
				} 
				else if (pil == 4){
					
					matkul = "KIMI NO NAWA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "D";
	
				} else if (pil == 5){
					matkul = "KIMI NO NAWA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "E";
				} else if (pil == 6){
					matkul = "KIMI NO NAWA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "F";
				} else if (pil == 7){
					matkul = "KIMI NO NAWA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "R";
				}
					
			}
			if (pil == 7) {
				break;
			}
			batas = batas + sks;
			
			if(batas > 24){
				cout << endl<<endl;
				cout << "input SKS anda melebihi batas !! "<<endl<<endl;
				
				cout << "Jumlah SKS yang Melebihi Batas : ";
				cout << batas<<endl;
				
				cout << "Matkul yang tidak bisa Diinputkan : ";
				cout << matkul<<endl;
				
				cout << "SKS dari Mata Kuliah " << matkul << " adalah : "; 
				cout << sks<<endl;
			
				cout << "Total Mata Kuliah yang Telah Diambil : ";
				cout << baru->total<<endl;
				
				cout << "Index : ";
				cout << i<<endl<<endl;
				
				getch();
				
				cout << "Mau memperbarui data sks terakhir anda ?" ;
				cin >> ulang;
					
				batas = batas - sks;
					
				if(ulang == 'y')
					continue;
				else
					break;
			}	
						
			if (batas <= 24){
							
				if(batas == 24){
					
					cout << endl;
					cout << endl;
					cout<<"Batas SKS tercapai !!";
				}
							
				baru->matkul[i] = matkul;
				baru->sks[i] = sks;
				baru->kodeMatkul[i] = kodeMatkul;
				baru->dosen[i] = dosen;
				baru->kelas[i] = kelas;
				baru->total++;
//				i++;
				
				if (batas < 24){
					cout << "tambah ? ";
					cin >> ulang;
						
						
					if (ulang == 't'){
						break;
					}	
				}
				
				cout << endl;
				cout << endl;
				cout << "Jumlah SKS yang sudah diambil : ";
				cout << batas;
				cout << endl << endl;
				
				cout << "Matkul yang Diinputkan : ";
				cout << matkul;
				cout << endl << endl;
				
				cout << "SKS dari Mata Kuliah " << matkul << " adalah : "; 
				cout << sks;
				cout << endl << endl;
			
				cout << "Total Mata Kuliah yang Telah Diambil : ";
				cout << baru->total;
				cout << endl << endl;
				
				cout << "Index : ";
				cout << i;
				cout << endl;
				cout << endl;
				
				i++;
				
				getch();
							
			}
		}
	}
	
	if (fakultas[kodeFak] == fakultas[3] && pos3 == ft[0]){
		while ( ulang == 'y'){
	
			system("cls");
			
			gotoxy(16,2); cout<<"Nama : "<<baru->nama;
			gotoxy(16,3); cout<<"NBI  : "<<baru->nbi;
			gotoxy(66,2); cout<<"Fakultas : "<<baru->fakultas;
			gotoxy(66,3); cout<<"Jurusan  : "<<baru->jurusan;
			gotoxy(15,4); cout<<"=========================================================================================";
			gotoxy(50,5); cout<<"PILIHAN MATA KULIAH";
			gotoxy(32,6); cout<<"=========================================================";
			gotoxy(32,7); cout<<"| PIL |                  NAMA                     | SKS |";
			gotoxy(32,8); cout<<"=========================================================";
			gotoxy(32,9); cout<<"|  1  | PENDIDIKAN AGAMA                         |  3  |";
			gotoxy(32,10); cout<<"|  2  | PENDIDIKAN PANCASILA                     |  4  |";
			gotoxy(32,11); cout<<"|  3  | KEWIRAUSAHAAN DASAR                      |  3  |";
			gotoxy(32,12); cout<<"|  4  | MATEMATIKA REKAYASA                      |  2  |";
			gotoxy(32,13); cout<<"|  5  | MEKANIKA FLUIDA DAN HIDROLIKA            |  4  |";
			gotoxy(32,14); cout<<"|  6  | STATISTIKA                               |  3  |";
			gotoxy(32,15); cout<<"=========================================================";
			gotoxy(32,16); cout<<"|                                              (7) EXIT |";
			gotoxy(32,17); cout<<"=========================================================";
			gotoxy(32,19); cout<<"Pilihan Anda : ";
			gotoxy(47,19); cin>>pil;
			
			system("cls");
			gotoxy(16,2); cout<<"Nama : "<<baru->nama;
			gotoxy(16,3); cout<<"NBI  : "<<baru->nbi;
			gotoxy(66,2); cout<<"Fakultas : "<<baru->fakultas;
			gotoxy(66,3); cout<<"Jurusan  : "<<baru->jurusan;
			gotoxy(15,4); cout<<"=========================================================================================";
			gotoxy(50,5); cout<<"PILIHAN MATA KULIAH";
			gotoxy(32,6); cout<<"=========================================================";
			gotoxy(32,7); cout<<"| PIL |                  NAMA                   | KELAS |";
			gotoxy(32,8); cout<<"=========================================================";
				
			if (pil == 1){
				
				gotoxy(32,9); cout<<"|  1  | PENDIDIKAN AGAMA                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | PENDIDIKAN AGAMA                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | PENDIDIKAN AGAMA                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | PENDIDIKAN AGAMA                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | PENDIDIKAN AGAMA                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | PENDIDIKAN AGAMA                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | PENDIDIKAN AGAMA                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
				
				if (pilmat == 1){
	
					matkul = "PENDIDIKAN AGAMA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "A";
	
				} else if (pilmat == 2){
					matkul = "PENDIDIKAN AGAMA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "B";
	
				} else if (pilmat == 3){
					matkul = "PENDIDIKAN AGAMA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "C";
	
				}else if (pilmat == 4){
					matkul = "PENDIDIKAN AGAMA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "D";
					
				}else if (pilmat == 5){
					matkul = "PENDIDIKAN AGAMA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "E";
				
				} else if (pilmat == 6) {
					matkul = "PENDIDIKAN AGAMA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "F";
					
				} else if (pilmat == 7){
					matkul = "PENDIDIKAN AGAMA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "R";
				}	
			}
			else if (pil == 2){
				
				gotoxy(32,9); cout<<"|  1  | PENDIDIKAN PANCASILA                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | PENDIDIKAN PANCASILA                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | PENDIDIKAN PANCASILA                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | PENDIDIKAN PANCASILA                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | PENDIDIKAN PANCASILA                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | PENDIDIKAN PANCASILA                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | PENDIDIKAN PANCASILA                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
				
				if (pilmat == 1){
					matkul = "PENDIDIKAN PANCASILA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "A";
					
				}
				else if (pilmat == 2){
					matkul = "PENDIDIKAN PANCASILA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "B";
					
				} 
				else if (pilmat == 3){
					matkul = "PENDIDIKAN PANCASILA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "C";
					
				}
				else if (pilmat == 4){
					matkul = "PENDIDIKAN PANCASILA";
					kodeMatkul = "Unknown";
					dosen = "MATKUL FT 1 2";
					sks = 4;
					kelas = "D";
					
				} else if (pilmat == 5){
					matkul = "PENDIDIKAN PANCASILA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "E";
					
				} else if (pilmat == 6){
					matkul = "PENDIDIKAN PANCASILA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "F";		
					
				} else if (pilmat == 7){
					matkul = "PENDIDIKAN PANCASILA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "R";
					
				}
			}
			else if (pil == 3){
				
				gotoxy(32,9); cout<<"|  1  | KEWIRAUSAHAAN DASAR                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | KEWIRAUSAHAAN DASAR                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | KEWIRAUSAHAAN DASAR                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | KEWIRAUSAHAAN DASAR                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | KEWIRAUSAHAAN DASAR                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | KEWIRAUSAHAAN DASAR                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | KEWIRAUSAHAAN DASAR                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
					
				if (pilmat == 1){
					matkul = "KEWIRAUSAHAAN DASAR";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "A";
				} 
				else if (pilmat == 2){
					matkul = "KEWIRAUSAHAAN DASAR";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "B";	
				} 
				else if (pilmat == 3){
					matkul = "KEWIRAUSAHAAN DASAR";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "C";	
				} 
				else if (pilmat == 4){
					matkul = "KEWIRAUSAHAAN DASAR";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "D";	
				} 
				else if (pilmat == 5){
					matkul = "KEWIRAUSAHAAN DASAR";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "E";	
				} 
				else if (pilmat == 6){
					matkul = "KEWIRAUSAHAAN DASAR";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "F";
				} 
				else if (pilmat == 7){
					matkul = "KEWIRAUSAHAAN DASAR";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "R";
				}	
			}	
			else if (pil == 4){
				
				gotoxy(32,9); cout<<"|  1  | MATEMATIKA REKAYASA                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | MATEMATIKA REKAYASA                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | MATEMATIKA REKAYASA                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | MATEMATIKA REKAYASA                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | MATEMATIKA REKAYASA                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | MATEMATIKA REKAYASA                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | MATEMATIKA REKAYASA                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
					
				if (pilmat == 1){
					
					matkul = "MATEMATIKA REKAYASA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IA";		
				} 
				else if (pilmat == 2){
					
					matkul = "MATEMATIKA REKAYASA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IB";		
				} 
				else if (pilmat == 3){
							
					matkul = "MATEMATIKA REKAYASA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IC";		
				} 
				else if (pilmat == 4){
						
					matkul = "MATEMATIKA REKAYASA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "ID";
						
				} 
				else if (pilmat == 5){
						
					matkul = "MATEMATIKA REKAYASA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IE";		
				} 
				else if (pilmat == 6){
						
					matkul = "MATEMATIKA REKAYASA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IF";		
				} 
				else if (pilmat == 7){
						
					matkul = "MATEMATIKA REKAYASA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IR";		
				}	
			}
			
			else if (pil == 5){
				
				gotoxy(32,9); cout<<"|  1  | MEKANIKA FLUIDA DAN HIDROLIKA                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | MEKANIKA FLUIDA DAN HIDROLIKA                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | MEKANIKA FLUIDA DAN HIDROLIKA                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | MEKANIKA FLUIDA DAN HIDROLIKA                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | MEKANIKA FLUIDA DAN HIDROLIKA                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | MEKANIKA FLUIDA DAN HIDROLIKA                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | MEKANIKA FLUIDA DAN HIDROLIKA                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
					
				if (pilmat == 1){
				
					matkul = "MEKANIKA FLUIDA DAN HIDROLIKA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "A";
				} 	
				else if (pilmat == 2){
				
					matkul = "MEKANIKA FLUIDA DAN HIDROLIKA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "B";
				} 				
				else if (pilmat == 3){
				
					matkul = "MEKANIKA FLUIDA DAN HIDROLIKA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "C";
				} 
				
				else if (pilmat == 4){
				
					matkul = "MEKANIKA FLUIDA DAN HIDROLIKA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "D";	
				} 
				
				else if (pilmat == 5){
				
					matkul = "MEKANIKA FLUIDA DAN HIDROLIKA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "E";
				} 
				
				else if (pilmat == 6){
				
					matkul = "MEKANIKA FLUIDA DAN HIDROLIKA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "F";
				} 
				else if (pilmat == 7){
				
					matkul = "MEKANIKA FLUIDA DAN HIDROLIKA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "R";
				}	
			}
			
			else if (pil == 6){
				
				gotoxy(32,9); cout<<"|  1  | STATISTIKA                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | STATISTIKA                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | STATISTIKA                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | STATISTIKA                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | STATISTIKA                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | STATISTIKA                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | STATISTIKA                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
					
				if (pilmat == 1){
					
					matkul = "STATISTIKA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "A";
				} 
				else if (pil == 2){
					
					matkul = "STATISTIKA";
					kodeMatkul = "14620063";
					dosen = "Unknown";
					sks = 3;
					kelas = "B";
				}
				else if (pil == 3){
					
					matkul = "STATISTIKA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "C";
				} 
				else if (pil == 4){
					
					matkul = "STATISTIKA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "D";
	
				} else if (pil == 5){
					matkul = "STATISTIKA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "E";
				} else if (pil == 6){
					matkul = "STATISTIKA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "F";
				} else if (pil == 7){
					matkul = "STATISTIKA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "R";
				}
					
			}
			if (pil == 7) {
				break;
			}
			batas = batas + sks;
			
			if(batas > 24){
				cout << endl<<endl;
				cout << "input SKS anda melebihi batas !! "<<endl<<endl;
				
				cout << "Jumlah SKS yang Melebihi Batas : ";
				cout << batas<<endl;
				
				cout << "Matkul yang tidak bisa Diinputkan : ";
				cout << matkul<<endl;
				
				cout << "SKS dari Mata Kuliah " << matkul << " adalah : "; 
				cout << sks<<endl;
			
				cout << "Total Mata Kuliah yang Telah Diambil : ";
				cout << baru->total<<endl;
				
				cout << "Index : ";
				cout << i<<endl<<endl;
				
				getch();
				
				cout << "Mau memperbarui data sks terakhir anda ?" ;
				cin >> ulang;
					
				batas = batas - sks;
					
				if(ulang == 'y')
					continue;
				else
					break;
			}	
						
			if (batas <= 24){
							
				if(batas == 24){
					
					cout << endl;
					cout << endl;
					cout<<"Batas SKS tercapai !!";
				}
							
				baru->matkul[i] = matkul;
				baru->sks[i] = sks;
				baru->kodeMatkul[i] = kodeMatkul;
				baru->dosen[i] = dosen;
				baru->kelas[i] = kelas;
				baru->total++;
//				i++;
				
				if (batas < 24){
					cout << "tambah ? ";
					cin >> ulang;
						
						
					if (ulang == 't'){
						break;
					}	
				}
				
				cout << endl;
				cout << endl;
				cout << "Jumlah SKS yang sudah diambil : ";
				cout << batas;
				cout << endl << endl;
				
				cout << "Matkul yang Diinputkan : ";
				cout << matkul;
				cout << endl << endl;
				
				cout << "SKS dari Mata Kuliah " << matkul << " adalah : "; 
				cout << sks;
				cout << endl << endl;
			
				cout << "Total Mata Kuliah yang Telah Diambil : ";
				cout << baru->total;
				cout << endl << endl;
				
				cout << "Index : ";
				cout << i;
				cout << endl;
				cout << endl;
				
				i++;
				
				getch();
							
			}
		}
}

	else if (fakultas[kodeFak] == fakultas[3] && pos3 == ft[1]){
		while ( ulang == 'y'){
	
			system("cls");
			gotoxy(16,2); cout<<"Nama : "<<baru->nama;
			gotoxy(16,3); cout<<"NBI  : "<<baru->nbi;
			gotoxy(66,2); cout<<"Fakultas : "<<baru->fakultas;
			gotoxy(66,3); cout<<"Jurusan  : "<<baru->jurusan;
			gotoxy(15,4); cout<<"=========================================================================================";
			gotoxy(50,5); cout<<"PILIHAN MATA KULIAH";
			gotoxy(32,6); cout<<"=========================================================";
			gotoxy(32,7); cout<<"| PIL |                  NAMA                     | SKS |";
			gotoxy(32,8); cout<<"=========================================================";
			gotoxy(32,9); cout<<"|  1  | PENDIDIKAN AGAMA                         |  3  |";
			gotoxy(32,10); cout<<"|  2  | PENDIDIKAN PANCASILA                     |  4  |";
			gotoxy(32,11); cout<<"|  3  | TEKNIK KOMUNIKASI ARSITEKTUR             |  3  |";
			gotoxy(32,12); cout<<"|  4  | METODE PERANCANGAN                       |  2  |";
			gotoxy(32,13); cout<<"|  5  | RUPA DASAR 3D                            |  4  |";
			gotoxy(32,14); cout<<"|  6  | KEWIRAUSAHAAN DASAR                      |  3  |";
			gotoxy(32,15); cout<<"=========================================================";
			gotoxy(32,16); cout<<"|                                              (7) EXIT |";
			gotoxy(32,17); cout<<"=========================================================";
			gotoxy(32,19); cout<<"Pilihan Anda : ";
			gotoxy(47,19); cin>>pil;
			
			system("cls");
			gotoxy(16,2); cout<<"Nama : "<<baru->nama;
			gotoxy(16,3); cout<<"NBI  : "<<baru->nbi;
			gotoxy(66,2); cout<<"Fakultas : "<<baru->fakultas;
			gotoxy(66,3); cout<<"Jurusan  : "<<baru->jurusan;
			gotoxy(15,4); cout<<"=========================================================================================";
			gotoxy(50,5); cout<<"PILIHAN MATA KULIAH";
			gotoxy(32,6); cout<<"=========================================================";
			gotoxy(32,7); cout<<"| PIL |                  NAMA                   | KELAS |";
			gotoxy(32,8); cout<<"=========================================================";
				
			if (pil == 1){
				
				gotoxy(32,9); cout<<"|  1  | PENDIDIKAN AGAMA                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | PENDIDIKAN AGAMA                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | PENDIDIKAN AGAMA                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | PENDIDIKAN AGAMA                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | PENDIDIKAN AGAMA                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | PENDIDIKAN AGAMA                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | PENDIDIKAN AGAMA                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
				
				if (pilmat == 1){
	
					matkul = "PENDIDIKAN AGAMA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "A";
	
				} else if (pilmat == 2){
					matkul = "PENDIDIKAN AGAMA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "B";
	
				} else if (pilmat == 3){
					matkul = "PENDIDIKAN AGAMA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "C";
	
				}else if (pilmat == 4){
					matkul = "PENDIDIKAN AGAMA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "D";
					
				}else if (pilmat == 5){
					matkul = "PENDIDIKAN AGAMA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "E";
				
				} else if (pilmat == 6) {
					matkul = "PENDIDIKAN AGAMA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "F";
					
				} else if (pilmat == 7){
					matkul = "PENDIDIKAN AGAMA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "R";
				}	
			}
			else if (pil == 2){
				
				gotoxy(32,9); cout<<"|  1  | PENDIDIKAN PANCASILA                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | PENDIDIKAN PANCASILA                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | PENDIDIKAN PANCASILA                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | PENDIDIKAN PANCASILA                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | PENDIDIKAN PANCASILA                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | PENDIDIKAN PANCASILA                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | PENDIDIKAN PANCASILA                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
				
				if (pilmat == 1){
					matkul = "PENDIDIKAN PANCASILA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "A";
					
				}
				else if (pilmat == 2){
					matkul = "PENDIDIKAN PANCASILA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "B";
					
				} 
				else if (pilmat == 3){
					matkul = "PENDIDIKAN PANCASILA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "C";
					
				}
				else if (pilmat == 4){
					matkul = "PENDIDIKAN PANCASILA";
					kodeMatkul = "Unknown";
					dosen = "MATKUL FT 1 2";
					sks = 4;
					kelas = "D";
					
				} else if (pilmat == 5){
					matkul = "PENDIDIKAN PANCASILA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "E";
					
				} else if (pilmat == 6){
					matkul = "PENDIDIKAN PANCASILA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "F";		
					
				} else if (pilmat == 7){
					matkul = "PENDIDIKAN PANCASILA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "R";
					
				}
			}
			else if (pil == 3){
				
				gotoxy(32,9); cout<<"|  1  | TEKNIK KOMUNIKASI ARSITEKTUR                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | TEKNIK KOMUNIKASI ARSITEKTUR                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | TEKNIK KOMUNIKASI ARSITEKTUR                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | TEKNIK KOMUNIKASI ARSITEKTUR                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | TEKNIK KOMUNIKASI ARSITEKTUR                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | TEKNIK KOMUNIKASI ARSITEKTUR                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | TEKNIK KOMUNIKASI ARSITEKTUR                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
					
				if (pilmat == 1){
					matkul = "TEKNIK KOMUNIKASI ARSITEKTUR";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "A";
				} 
				else if (pilmat == 2){
					matkul = "TEKNIK KOMUNIKASI ARSITEKTUR";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "B";	
				} 
				else if (pilmat == 3){
					matkul = "TEKNIK KOMUNIKASI ARSITEKTUR";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "C";	
				} 
				else if (pilmat == 4){
					matkul = "TEKNIK KOMUNIKASI ARSITEKTUR";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "D";	
				} 
				else if (pilmat == 5){
					matkul = "TEKNIK KOMUNIKASI ARSITEKTUR";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "E";	
				} 
				else if (pilmat == 6){
					matkul = "TEKNIK KOMUNIKASI ARSITEKTUR";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "F";
				} 
				else if (pilmat == 7){
					matkul = "TEKNIK KOMUNIKASI ARSITEKTUR";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "R";
				}	
			}	
			else if (pil == 4){
				
				gotoxy(32,9); cout<<"|  1  | METODE PERANCANGAN                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | METODE PERANCANGAN                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | METODE PERANCANGAN                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | METODE PERANCANGAN                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | METODE PERANCANGAN                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | METODE PERANCANGAN                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | METODE PERANCANGAN                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
					
				if (pilmat == 1){
					
					matkul = "METODE PERANCANGAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IA";		
				} 
				else if (pilmat == 2){
					
					matkul = "METODE PERANCANGAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IB";		
				} 
				else if (pilmat == 3){
							
					matkul = "METODE PERANCANGAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IC";		
				} 
				else if (pilmat == 4){
						
					matkul = "METODE PERANCANGAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "ID";
						
				} 
				else if (pilmat == 5){
						
					matkul = "METODE PERANCANGAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IE";		
				} 
				else if (pilmat == 6){
						
					matkul = "METODE PERANCANGAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IF";		
				} 
				else if (pilmat == 7){
						
					matkul = "METODE PERANCANGAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IR";		
				}	
			}
			
			else if (pil == 5){
				
				gotoxy(32,9); cout<<"|  1  | RUPA DASAR 3D                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | RUPA DASAR 3D                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | RUPA DASAR 3D                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | RUPA DASAR 3D                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | RUPA DASAR 3D                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | RUPA DASAR 3D                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | RUPA DASAR 3D                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
					
				if (pilmat == 1){
				
					matkul = "RUPA DASAR 3D";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "A";
				} 	
				else if (pilmat == 2){
				
					matkul = "RUPA DASAR 3D";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "B";
				} 				
				else if (pilmat == 3){
				
					matkul = "RUPA DASAR 3D";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "C";
				} 
				
				else if (pilmat == 4){
				
					matkul = "RUPA DASAR 3D";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "D";	
				} 
				
				else if (pilmat == 5){
				
					matkul = "RUPA DASAR 3D";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "E";
				} 
				
				else if (pilmat == 6){
				
					matkul = "RUPA DASAR 3D";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "F";
				} 
				else if (pilmat == 7){
				
					matkul = "RUPA DASAR 3D";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "R";
				}	
			}
			
			else if (pil == 6){
				
				gotoxy(32,9); cout<<"|  1  | KEWIRAUSAHAAN DASAR                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | KEWIRAUSAHAAN DASAR                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | KEWIRAUSAHAAN DASAR                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | KEWIRAUSAHAAN DASAR                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | KEWIRAUSAHAAN DASAR                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | KEWIRAUSAHAAN DASAR                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | KEWIRAUSAHAAN DASAR                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
					
				if (pilmat == 1){
					
					matkul = "KEWIRAUSAHAAN DASAR";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "A";
				} 
				else if (pil == 2){
					
					matkul = "KEWIRAUSAHAAN DASAR";
					kodeMatkul = "14620063";
					dosen = "Unknown";
					sks = 3;
					kelas = "B";
				}
				else if (pil == 3){
					
					matkul = "KEWIRAUSAHAAN DASAR";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "C";
				} 
				else if (pil == 4){
					
					matkul = "KEWIRAUSAHAAN DASAR";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "D";
	
				} else if (pil == 5){
					matkul = "KEWIRAUSAHAAN DASAR";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "E";
				} else if (pil == 6){
					matkul = "KEWIRAUSAHAAN DASAR";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "F";
				} else if (pil == 7){
					matkul = "KEWIRAUSAHAAN DASAR";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "R";
				}
					
			}
			if (pil == 7) {
				break;
			}
			batas = batas + sks;
			
			if(batas > 24){
				cout << endl<<endl;
				cout << "input SKS anda melebihi batas !! "<<endl<<endl;
				
				cout << "Jumlah SKS yang Melebihi Batas : ";
				cout << batas<<endl;
				
				cout << "Matkul yang tidak bisa Diinputkan : ";
				cout << matkul<<endl;
				
				cout << "SKS dari Mata Kuliah " << matkul << " adalah : "; 
				cout << sks<<endl;
			
				cout << "Total Mata Kuliah yang Telah Diambil : ";
				cout << baru->total<<endl;
				
				cout << "Index : ";
				cout << i<<endl<<endl;
				
				getch();
				
				cout << "Mau memperbarui data sks terakhir anda ?" ;
				cin >> ulang;
					
				batas = batas - sks;
					
				if(ulang == 'y')
					continue;
				else
					break;
			}	
						
			if (batas <= 24){
							
				if(batas == 24){
					
					cout << endl;
					cout << endl;
					cout<<"Batas SKS tercapai !!";
				}
							
				baru->matkul[i] = matkul;
				baru->sks[i] = sks;
				baru->kodeMatkul[i] = kodeMatkul;
				baru->dosen[i] = dosen;
				baru->kelas[i] = kelas;
				baru->total++;
//				i++;
				
				if (batas < 24){
					cout << "tambah ? ";
					cin >> ulang;
						
						
					if (ulang == 't'){
						break;
					}	
				}
				
				cout << endl;
				cout << endl;
				cout << "Jumlah SKS yang sudah diambil : ";
				cout << batas;
				cout << endl << endl;
				
				cout << "Matkul yang Diinputkan : ";
				cout << matkul;
				cout << endl << endl;
				
				cout << "SKS dari Mata Kuliah " << matkul << " adalah : "; 
				cout << sks;
				cout << endl << endl;
			
				cout << "Total Mata Kuliah yang Telah Diambil : ";
				cout << baru->total;
				cout << endl << endl;
				
				cout << "Index : ";
				cout << i;
				cout << endl;
				cout << endl;
				
				i++;
				
				getch();
							
			}
	}
}

	else if (fakultas[kodeFak] == fakultas[3] && pos3 == ft[2]){
		while ( ulang == 'y'){
	
			system("cls");
			gotoxy(16,2); cout<<"Nama : "<<baru->nama;
			gotoxy(16,3); cout<<"NBI  : "<<baru->nbi;
			gotoxy(66,2); cout<<"Fakultas : "<<baru->fakultas;
			gotoxy(66,3); cout<<"Jurusan  : "<<baru->jurusan;
			gotoxy(15,4); cout<<"=========================================================================================";
			gotoxy(50,5); cout<<"PILIHAN MATA KULIAH";
			gotoxy(32,6); cout<<"=========================================================";
			gotoxy(32,7); cout<<"| PIL |                  NAMA                     | SKS |";
			gotoxy(32,8); cout<<"=========================================================";
			gotoxy(32,9); cout<<"|  1  | PENDIDIKAN PANCASILA                     |  3  |";
			gotoxy(32,10); cout<<"|  2  | BAHASA INGGRIS                           |  4  |";
			gotoxy(32,11); cout<<"|  3  | FISIKA DASAR II                          |  3  |";
			gotoxy(32,12); cout<<"|  4  | MATEMATIKA II                            |  2  |";
			gotoxy(32,13); cout<<"|  5  | MENGAMBAR MESIN                          |  4  |";
			gotoxy(32,14); cout<<"|  6  | ALGORITMA PEMROGAMAN                     |  3  |";
			gotoxy(32,15); cout<<"=========================================================";
			gotoxy(32,16); cout<<"|                                              (7) EXIT |";
			gotoxy(32,17); cout<<"=========================================================";
			gotoxy(32,19); cout<<"Pilihan Anda : ";
			gotoxy(47,19); cin>>pil;
			
			system("cls");
			gotoxy(16,2); cout<<"Nama : "<<baru->nama;
			gotoxy(16,3); cout<<"NBI  : "<<baru->nbi;
			gotoxy(66,2); cout<<"Fakultas : "<<baru->fakultas;
			gotoxy(66,3); cout<<"Jurusan  : "<<baru->jurusan;
			gotoxy(15,4); cout<<"=========================================================================================";
			gotoxy(50,5); cout<<"PILIHAN MATA KULIAH";
			gotoxy(32,6); cout<<"=========================================================";
			gotoxy(32,7); cout<<"| PIL |                  NAMA                   | KELAS |";
			gotoxy(32,8); cout<<"=========================================================";
				
			if (pil == 1){
				
				gotoxy(32,9); cout<<"|  1  | PENDIDIKAN PANCASILA                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | PENDIDIKAN PANCASILA                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | PENDIDIKAN PANCASILA                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | PENDIDIKAN PANCASILA                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | PENDIDIKAN PANCASILA                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | PENDIDIKAN PANCASILA                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | PENDIDIKAN PANCASILA                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
				
				if (pilmat == 1){
	
					matkul = "PENDIDIKAN PANCASILA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "A";
	
				} else if (pilmat == 2){
					matkul = "PENDIDIKAN PANCASILA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "B";
	
				} else if (pilmat == 3){
					matkul = "PENDIDIKAN PANCASILA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "C";
	
				}else if (pilmat == 4){
					matkul = "PENDIDIKAN PANCASILA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "D";
					
				}else if (pilmat == 5){
					matkul = "PENDIDIKAN PANCASILA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "E";
				
				} else if (pilmat == 6) {
					matkul = "PENDIDIKAN PANCASILA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "F";
					
				} else if (pilmat == 7){
					matkul = "PENDIDIKAN PANCASILA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "R";
				}	
			}
			else if (pil == 2){
				
				gotoxy(32,9); cout<<"|  1  | BAHASA INGGRIS                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | BAHASA INGGRIS                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | BAHASA INGGRIS                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | BAHASA INGGRIS                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | BAHASA INGGRIS                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | BAHASA INGGRIS                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | BAHASA INGGRIS                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
				
				if (pilmat == 1){
					matkul = "BAHASA INGGRIS";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "A";
					
				}
				else if (pilmat == 2){
					matkul = "BAHASA INGGRIS";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "B";
					
				} 
				else if (pilmat == 3){
					matkul = "BAHASA INGGRIS";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "C";
					
				}
				else if (pilmat == 4){
					matkul = "BAHASA INGGRIS";
					kodeMatkul = "Unknown";
					dosen = "MATKUL FT 1 2";
					sks = 4;
					kelas = "D";
					
				} else if (pilmat == 5){
					matkul = "BAHASA INGGRIS";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "E";
					
				} else if (pilmat == 6){
					matkul = "BAHASA INGGRIS";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "F";		
					
				} else if (pilmat == 7){
					matkul = "BAHASA INGGRIS";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "R";
					
				}
			}
			else if (pil == 3){
				
				gotoxy(32,9); cout<<"|  1  | FISIKA DASAR II                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | FISIKA DASAR II                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | FISIKA DASAR II                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | FISIKA DASAR II                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | FISIKA DASAR II                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | FISIKA DASAR II                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | FISIKA DASAR II                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
					
				if (pilmat == 1){
					matkul = "FISIKA DASAR II";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "A";
				} 
				else if (pilmat == 2){
					matkul = "FISIKA DASAR II";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "B";	
				} 
				else if (pilmat == 3){
					matkul = "FISIKA DASAR II";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "C";	
				} 
				else if (pilmat == 4){
					matkul = "FISIKA DASAR II";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "D";	
				} 
				else if (pilmat == 5){
					matkul = "FISIKA DASAR II";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "E";	
				} 
				else if (pilmat == 6){
					matkul = "FISIKA DASAR II";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "F";
				} 
				else if (pilmat == 7){
					matkul = "FISIKA DASAR II";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "R";
				}	
			}	
			else if (pil == 4){
				
				gotoxy(32,9); cout<<"|  1  | MATEMATIKA II                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | MATEMATIKA II                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | MATEMATIKA II                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | MATEMATIKA II                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | MATEMATIKA II                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | MATEMATIKA II                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | MATEMATIKA II                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
					
				if (pilmat == 1){
					
					matkul = "MATEMATIKA II";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IA";		
				} 
				else if (pilmat == 2){
					
					matkul = "MATEMATIKA II";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IB";		
				} 
				else if (pilmat == 3){
							
					matkul = "MATEMATIKA II";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IC";		
				} 
				else if (pilmat == 4){
						
					matkul = "MATEMATIKA II";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "ID";
						
				} 
				else if (pilmat == 5){
						
					matkul = "MATEMATIKA II";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IE";		
				} 
				else if (pilmat == 6){
						
					matkul = "MATEMATIKA II";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IF";		
				} 
				else if (pilmat == 7){
						
					matkul = "MATEMATIKA II";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IR";		
				}	
			}
			
			else if (pil == 5){
				
				gotoxy(32,9); cout<<"|  1  | MENGAMBAR MESIN                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | MENGAMBAR MESIN                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | MENGAMBAR MESIN                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | MENGAMBAR MESIN                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | MENGAMBAR MESIN                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | MENGAMBAR MESIN                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | MENGAMBAR MESIN                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
					
				if (pilmat == 1){
				
					matkul = "MENGAMBAR MESIN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "A";
				} 	
				else if (pilmat == 2){
				
					matkul = "MENGAMBAR MESIN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "B";
				} 				
				else if (pilmat == 3){
				
					matkul = "MENGAMBAR MESIN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "C";
				} 
				
				else if (pilmat == 4){
				
					matkul = "MENGAMBAR MESIN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "D";	
				} 
				
				else if (pilmat == 5){
				
					matkul = "MENGAMBAR MESIN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "E";
				} 
				
				else if (pilmat == 6){
				
					matkul = "MENGAMBAR MESIN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "F";
				} 
				else if (pilmat == 7){
				
					matkul = "MENGAMBAR MESIN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "R";
				}	
			}
			
			else if (pil == 6){
				
				gotoxy(32,9); cout<<"|  1  | ALGORITMA PEMROGAMAN                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | ALGORITMA PEMROGAMAN                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | ALGORITMA PEMROGAMAN                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | ALGORITMA PEMROGAMAN                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | ALGORITMA PEMROGAMAN                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | ALGORITMA PEMROGAMAN                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | ALGORITMA PEMROGAMAN                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
					
				if (pilmat == 1){
					
					matkul = "ALGORITMA PEMROGAMAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "A";
				} 
				else if (pil == 2){
					
					matkul = "ALGORITMA PEMROGAMAN";
					kodeMatkul = "14620063";
					dosen = "Unknown";
					sks = 3;
					kelas = "B";
				}
				else if (pil == 3){
					
					matkul = "ALGORITMA PEMROGAMAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "C";
				} 
				else if (pil == 4){
					
					matkul = "ALGORITMA PEMROGAMAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "D";
	
				} else if (pil == 5){
					matkul = "ALGORITMA PEMROGAMAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "E";
				} else if (pil == 6){
					matkul = "ALGORITMA PEMROGAMAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "F";
				} else if (pil == 7){
					matkul = "ALGORITMA PEMROGAMAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "R";
				}
					
			}
			if (pil == 7) {
				break;
			}
			batas = batas + sks;
			
			if(batas > 24){
				cout << endl<<endl;
				cout << "input SKS anda melebihi batas !! "<<endl<<endl;
				
				cout << "Jumlah SKS yang Melebihi Batas : ";
				cout << batas<<endl;
				
				cout << "Matkul yang tidak bisa Diinputkan : ";
				cout << matkul<<endl;
				
				cout << "SKS dari Mata Kuliah " << matkul << " adalah : "; 
				cout << sks<<endl;
			
				cout << "Total Mata Kuliah yang Telah Diambil : ";
				cout << baru->total<<endl;
				
				cout << "Index : ";
				cout << i<<endl<<endl;
				
				getch();
				
				cout << "Mau memperbarui data sks terakhir anda ?" ;
				cin >> ulang;
					
				batas = batas - sks;
					
				if(ulang == 'y')
					continue;
				else
					break;
			}	
						
			if (batas <= 24){
							
				if(batas == 24){
					
					cout << endl;
					cout << endl;
					cout<<"Batas SKS tercapai !!";
				}
							
				baru->matkul[i] = matkul;
				baru->sks[i] = sks;
				baru->kodeMatkul[i] = kodeMatkul;
				baru->dosen[i] = dosen;
				baru->kelas[i] = kelas;
				baru->total++;
//				i++;
				
				if (batas < 24){
					cout << "tambah ? ";
					cin >> ulang;
						
						
					if (ulang == 't'){
						break;
					}	
				}
				
				cout << endl;
				cout << endl;
				cout << "Jumlah SKS yang sudah diambil : ";
				cout << batas;
				cout << endl << endl;
				
				cout << "Matkul yang Diinputkan : ";
				cout << matkul;
				cout << endl << endl;
				
				cout << "SKS dari Mata Kuliah " << matkul << " adalah : "; 
				cout << sks;
				cout << endl << endl;
			
				cout << "Total Mata Kuliah yang Telah Diambil : ";
				cout << baru->total;
				cout << endl << endl;
				
				cout << "Index : ";
				cout << i;
				cout << endl;
				cout << endl;
				
				i++;
				
				getch();
							
			}
	}
}

	else if (fakultas[kodeFak] == fakultas[3] && pos3 == ft[3]){
		while ( ulang == 'y'){
	
			system("cls");
			gotoxy(16,2); cout<<"Nama : "<<baru->nama;
			gotoxy(16,3); cout<<"NBI  : "<<baru->nbi;
			gotoxy(66,2); cout<<"Fakultas : "<<baru->fakultas;
			gotoxy(66,3); cout<<"Jurusan  : "<<baru->jurusan;
			gotoxy(15,4); cout<<"=========================================================================================";
			gotoxy(50,5); cout<<"PILIHAN MATA KULIAH";
			gotoxy(32,6); cout<<"=========================================================";
			gotoxy(32,7); cout<<"| PIL |                  NAMA                     | SKS |";
			gotoxy(32,8); cout<<"=========================================================";
			gotoxy(32,9); cout<<"|  1  | MATEMATIKA II                            |  3  |";
			gotoxy(32,10); cout<<"|  2  | FISIKA II                                |  4  |";
			gotoxy(32,11); cout<<"|  3  | KIMIA                                    |  3  |";
			gotoxy(32,12); cout<<"|  4  | RANGKAIAN LISTRIK                        |  2  |";
			gotoxy(32,13); cout<<"|  5  | ALJABAR LINEAR DAN STRUKTUR DISKRIT      |  4  |";
			gotoxy(32,14); cout<<"|  6  | BAHASA INDONESIA                         |  3  |";
			gotoxy(32,15); cout<<"=========================================================";
			gotoxy(32,16); cout<<"|                                              (7) EXIT |";
			gotoxy(32,17); cout<<"=========================================================";
			gotoxy(32,19); cout<<"Pilihan Anda : ";
			gotoxy(47,19); cin>>pil;
			
			system("cls");
			gotoxy(16,2); cout<<"Nama : "<<baru->nama;
			gotoxy(16,3); cout<<"NBI  : "<<baru->nbi;
			gotoxy(66,2); cout<<"Fakultas : "<<baru->fakultas;
			gotoxy(66,3); cout<<"Jurusan  : "<<baru->jurusan;
			gotoxy(15,4); cout<<"=========================================================================================";
			gotoxy(50,5); cout<<"PILIHAN MATA KULIAH";
			gotoxy(32,6); cout<<"=========================================================";
			gotoxy(32,7); cout<<"| PIL |                  NAMA                   | KELAS |";
			gotoxy(32,8); cout<<"=========================================================";
				
			if (pil == 1){
				
				gotoxy(32,9); cout<<"|  1  | MATEMATIKA II                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | MATEMATIKA II                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | MATEMATIKA II                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | MATEMATIKA II                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | MATEMATIKA II                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | MATEMATIKA II                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | MATEMATIKA II                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
				
				if (pilmat == 1){
	
					matkul = "MATEMATIKA II";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "A";
	
				} else if (pilmat == 2){
					matkul = "MATEMATIKA II";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "B";
	
				} else if (pilmat == 3){
					matkul = "MATEMATIKA II";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "C";
	
				}else if (pilmat == 4){
					matkul = "MATEMATIKA II";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "D";
					
				}else if (pilmat == 5){
					matkul = "MATEMATIKA II";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "E";
				
				} else if (pilmat == 6) {
					matkul = "MATEMATIKA II";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "F";
					
				} else if (pilmat == 7){
					matkul = "MATEMATIKA II";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "R";
				}	
			}
			else if (pil == 2){
				
				gotoxy(32,9); cout<<"|  1  | FISIKA II                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | FISIKA II                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | FISIKA II                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | FISIKA II                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | FISIKA II                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | FISIKA II                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | FISIKA II                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
				
				if (pilmat == 1){
					matkul = "FISIKA II";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "A";
					
				}
				else if (pilmat == 2){
					matkul = "FISIKA II";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "B";
					
				} 
				else if (pilmat == 3){
					matkul = "FISIKA II";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "C";
					
				}
				else if (pilmat == 4){
					matkul = "FISIKA II";
					kodeMatkul = "Unknown";
					dosen = "MATKUL FT 1 2";
					sks = 4;
					kelas = "D";
					
				} else if (pilmat == 5){
					matkul = "FISIKA II";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "E";
					
				} else if (pilmat == 6){
					matkul = "FISIKA II";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "F";		
					
				} else if (pilmat == 7){
					matkul = "FISIKA II";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "R";
					
				}
			}
			else if (pil == 3){
				
				gotoxy(32,9); cout<<"|  1  | KIMIA                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | KIMIA                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | KIMIA                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | KIMIA                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | KIMIA                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | KIMIA                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | KIMIA                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
					
				if (pilmat == 1){
					matkul = "KIMIA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "A";
				} 
				else if (pilmat == 2){
					matkul = "KIMIA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "B";	
				} 
				else if (pilmat == 3){
					matkul = "KIMIA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "C";	
				} 
				else if (pilmat == 4){
					matkul = "KIMIA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "D";	
				} 
				else if (pilmat == 5){
					matkul = "KIMIA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "E";	
				} 
				else if (pilmat == 6){
					matkul = "KIMIA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "F";
				} 
				else if (pilmat == 7){
					matkul = "KIMIA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "R";
				}	
			}	
			else if (pil == 4){
				
				gotoxy(32,9); cout<<"|  1  | RANGKAIAN LISTRIK                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | RANGKAIAN LISTRIK                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | RANGKAIAN LISTRIK                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | RANGKAIAN LISTRIK                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | RANGKAIAN LISTRIK                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | RANGKAIAN LISTRIK                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | RANGKAIAN LISTRIK                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
					
				if (pilmat == 1){
					
					matkul = "RANGKAIAN LISTRIK";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IA";		
				} 
				else if (pilmat == 2){
					
					matkul = "RANGKAIAN LISTRIK";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IB";		
				} 
				else if (pilmat == 3){
							
					matkul = "RANGKAIAN LISTRIK";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IC";		
				} 
				else if (pilmat == 4){
						
					matkul = "RANGKAIAN LISTRIK";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "ID";
						
				} 
				else if (pilmat == 5){
						
					matkul = "RANGKAIAN LISTRIK";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IE";		
				} 
				else if (pilmat == 6){
						
					matkul = "RANGKAIAN LISTRIK";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IF";		
				} 
				else if (pilmat == 7){
						
					matkul = "RANGKAIAN LISTRIK";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IR";		
				}	
			}
			
			else if (pil == 5){
				
				gotoxy(32,9); cout<<"|  1  | ALJABAR LINEAR DAN STRUKTUR DISKRIT                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | ALJABAR LINEAR DAN STRUKTUR DISKRIT                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | ALJABAR LINEAR DAN STRUKTUR DISKRIT                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | ALJABAR LINEAR DAN STRUKTUR DISKRIT                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | ALJABAR LINEAR DAN STRUKTUR DISKRIT                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | ALJABAR LINEAR DAN STRUKTUR DISKRIT                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | ALJABAR LINEAR DAN STRUKTUR DISKRIT                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
					
				if (pilmat == 1){
				
					matkul = "ALJABAR LINEAR DAN STRUKTUR DISKRIT";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "A";
				} 	
				else if (pilmat == 2){
				
					matkul = "ALJABAR LINEAR DAN STRUKTUR DISKRIT";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "B";
				} 				
				else if (pilmat == 3){
				
					matkul = "ALJABAR LINEAR DAN STRUKTUR DISKRIT";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "C";
				} 
				
				else if (pilmat == 4){
				
					matkul = "ALJABAR LINEAR DAN STRUKTUR DISKRIT";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "D";	
				} 
				
				else if (pilmat == 5){
				
					matkul = "ALJABAR LINEAR DAN STRUKTUR DISKRIT";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "E";
				} 
				
				else if (pilmat == 6){
				
					matkul = "ALJABAR LINEAR DAN STRUKTUR DISKRIT";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "F";
				} 
				else if (pilmat == 7){
				
					matkul = "ALJABAR LINEAR DAN STRUKTUR DISKRIT";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "R";
				}	
			}
			
			else if (pil == 6){
				
				gotoxy(32,9); cout<<"|  1  | ALJABAR LINEAR DAN STRUKTUR DISKRIT                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | ALJABAR LINEAR DAN STRUKTUR DISKRIT                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | ALJABAR LINEAR DAN STRUKTUR DISKRIT                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | ALJABAR LINEAR DAN STRUKTUR DISKRIT                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | ALJABAR LINEAR DAN STRUKTUR DISKRIT                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | ALJABAR LINEAR DAN STRUKTUR DISKRIT                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | ALJABAR LINEAR DAN STRUKTUR DISKRIT                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
					
				if (pilmat == 1){
					
					matkul = "ALJABAR LINEAR DAN STRUKTUR DISKRIT";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "A";
				} 
				else if (pil == 2){
					
					matkul = "ALJABAR LINEAR DAN STRUKTUR DISKRIT";
					kodeMatkul = "14620063";
					dosen = "Unknown";
					sks = 3;
					kelas = "B";
				}
				else if (pil == 3){
					
					matkul = "ALJABAR LINEAR DAN STRUKTUR DISKRIT";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "C";
				} 
				else if (pil == 4){
					
					matkul = "ALJABAR LINEAR DAN STRUKTUR DISKRIT";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "D";
	
				} else if (pil == 5){
					matkul = "ALJABAR LINEAR DAN STRUKTUR DISKRIT";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "E";
				} else if (pil == 6){
					matkul = "ALJABAR LINEAR DAN STRUKTUR DISKRIT";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "F";
				} else if (pil == 7){
					matkul = "ALGORITMA PEMROGAMAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "R";
				}
					
			}
			if (pil == 7) {
				break;
			}
			batas = batas + sks;
			
			if(batas > 24){
				cout << endl<<endl;
				cout << "input SKS anda melebihi batas !! "<<endl<<endl;
				
				cout << "Jumlah SKS yang Melebihi Batas : ";
				cout << batas<<endl;
				
				cout << "Matkul yang tidak bisa Diinputkan : ";
				cout << matkul<<endl;
				
				cout << "SKS dari Mata Kuliah " << matkul << " adalah : "; 
				cout << sks<<endl;
			
				cout << "Total Mata Kuliah yang Telah Diambil : ";
				cout << baru->total<<endl;
				
				cout << "Index : ";
				cout << i<<endl<<endl;
				
				getch();
				
				cout << "Mau memperbarui data sks terakhir anda ?" ;
				cin >> ulang;
					
				batas = batas - sks;
					
				if(ulang == 'y')
					continue;
				else
					break;
			}	
						
			if (batas <= 24){
							
				if(batas == 24){
					
					cout << endl;
					cout << endl;
					cout<<"Batas SKS tercapai !!";
				}
							
				baru->matkul[i] = matkul;
				baru->sks[i] = sks;
				baru->kodeMatkul[i] = kodeMatkul;
				baru->dosen[i] = dosen;
				baru->kelas[i] = kelas;
				baru->total++;
//				i++;
				
				if (batas < 24){
					cout << "tambah ? ";
					cin >> ulang;
						
						
					if (ulang == 't'){
						break;
					}	
				}
				
				cout << endl;
				cout << endl;
				cout << "Jumlah SKS yang sudah diambil : ";
				cout << batas;
				cout << endl << endl;
				
				cout << "Matkul yang Diinputkan : ";
				cout << matkul;
				cout << endl << endl;
				
				cout << "SKS dari Mata Kuliah " << matkul << " adalah : "; 
				cout << sks;
				cout << endl << endl;
			
				cout << "Total Mata Kuliah yang Telah Diambil : ";
				cout << baru->total;
				cout << endl << endl;
				
				cout << "Index : ";
				cout << i;
				cout << endl;
				cout << endl;
				
				i++;
				
				getch();
							
			}
	}
}

	else if (fakultas[kodeFak] == fakultas[3] && pos3 == ft[4]){
		while ( ulang == 'y'){
	
			system("cls");
			gotoxy(16,2); cout<<"Nama : "<<baru->nama;
			gotoxy(16,3); cout<<"NBI  : "<<baru->nbi;
			gotoxy(66,2); cout<<"Fakultas : "<<baru->fakultas;
			gotoxy(66,3); cout<<"Jurusan  : "<<baru->jurusan;
			gotoxy(15,4); cout<<"=========================================================================================";
			gotoxy(50,5); cout<<"PILIHAN MATA KULIAH";
			gotoxy(32,6); cout<<"=========================================================";
			gotoxy(32,7); cout<<"| PIL |                  NAMA                     | SKS |";
			gotoxy(32,8); cout<<"=========================================================";
			gotoxy(32,9); cout<<"|  1  | BAHASA INDONESIA                         |  3  |";
			gotoxy(32,10); cout<<"|  2  | PENGETAHUAN KEBENCANAAN DAN LINGKUNGAN   |  4  |";
			gotoxy(32,11); cout<<"|  3  | BAHASA INGGRIS                           |  3  |";
			gotoxy(32,12); cout<<"|  4  | KALKULUS II                              |  2  |";
			gotoxy(32,13); cout<<"|  5  | FISIKA DASAR II                          |  4  |";
			gotoxy(32,14); cout<<"|  6  | KRISTALOGRAFI DAN MINERALOGI             |  3  |";
			gotoxy(32,15); cout<<"=========================================================";
			gotoxy(32,16); cout<<"|                                              (7) EXIT |";
			gotoxy(32,17); cout<<"=========================================================";
			gotoxy(32,19); cout<<"Pilihan Anda : ";
			gotoxy(47,19); cin>>pil;
			
			system("cls");
			gotoxy(16,2); cout<<"Nama : "<<baru->nama;
			gotoxy(16,3); cout<<"NBI  : "<<baru->nbi;
			gotoxy(66,2); cout<<"Fakultas : "<<baru->fakultas;
			gotoxy(66,3); cout<<"Jurusan  : "<<baru->jurusan;
			gotoxy(15,4); cout<<"=========================================================================================";
			gotoxy(50,5); cout<<"PILIHAN MATA KULIAH";
			gotoxy(32,6); cout<<"=========================================================";
			gotoxy(32,7); cout<<"| PIL |                  NAMA                   | KELAS |";
			gotoxy(32,8); cout<<"=========================================================";
				
			if (pil == 1){
				
				gotoxy(32,9); cout<<"|  1  | BAHASA INDONESIA                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | BAHASA INDONESIA                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | BAHASA INDONESIA                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | BAHASA INDONESIA                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | BAHASA INDONESIA                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | BAHASA INDONESIA                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | BAHASA INDONESIA                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
				
				if (pilmat == 1){
	
					matkul = "BAHASA INDONESIA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "A";
	
				} else if (pilmat == 2){
					matkul = "BAHASA INDONESIA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "B";
	
				} else if (pilmat == 3){
					matkul = "BAHASA INDONESIA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "C";
	
				}else if (pilmat == 4){
					matkul = "BAHASA INDONESIA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "D";
					
				}else if (pilmat == 5){
					matkul = "BAHASA INDONESIA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "E";
				
				} else if (pilmat == 6) {
					matkul = "BAHASA INDONESIA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "F";
					
				} else if (pilmat == 7){
					matkul = "BAHASA INDONESIA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "R";
				}	
			}
			else if (pil == 2){
				
				gotoxy(32,9); cout<<"|  1  | PENGETAHUAN KEBENCANAAN DAN LINGKUNGAN                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | PENGETAHUAN KEBENCANAAN DAN LINGKUNGAN                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | PENGETAHUAN KEBENCANAAN DAN LINGKUNGAN                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | PENGETAHUAN KEBENCANAAN DAN LINGKUNGAN                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | PENGETAHUAN KEBENCANAAN DAN LINGKUNGAN                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | PENGETAHUAN KEBENCANAAN DAN LINGKUNGAN                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | PENGETAHUAN KEBENCANAAN DAN LINGKUNGAN                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
				
				if (pilmat == 1){
					matkul = "PENGETAHUAN KEBENCANAAN DAN LINGKUNGAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "A";
					
				}
				else if (pilmat == 2){
					matkul = "PENGETAHUAN KEBENCANAAN DAN LINGKUNGAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "B";
					
				} 
				else if (pilmat == 3){
					matkul = "PENGETAHUAN KEBENCANAAN DAN LINGKUNGAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "C";
					
				}
				else if (pilmat == 4){
					matkul = "PENGETAHUAN KEBENCANAAN DAN LINGKUNGAN";
					kodeMatkul = "Unknown";
					dosen = "MATKUL FT 1 2";
					sks = 4;
					kelas = "D";
					
				} else if (pilmat == 5){
					matkul = "PENGETAHUAN KEBENCANAAN DAN LINGKUNGAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "E";
					
				} else if (pilmat == 6){
					matkul = "PENGETAHUAN KEBENCANAAN DAN LINGKUNGAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "F";		
					
				} else if (pilmat == 7){
					matkul = "PENGETAHUAN KEBENCANAAN DAN LINGKUNGAN";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "R";
					
				}
			}
			else if (pil == 3){
				
				gotoxy(32,9); cout<<"|  1  | BAHASA INGGRIS                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | BAHASA INGGRIS                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | BAHASA INGGRIS                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | BAHASA INGGRIS                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | BAHASA INGGRIS                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | BAHASA INGGRIS                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | BAHASA INGGRIS                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
					
				if (pilmat == 1){
					matkul = "BAHASA INGGRIS";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "A";
				} 
				else if (pilmat == 2){
					matkul = "BAHASA INGGRIS";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "B";	
				} 
				else if (pilmat == 3){
					matkul = "BAHASA INGGRIS";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "C";	
				} 
				else if (pilmat == 4){
					matkul = "BAHASA INGGRIS";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "D";	
				} 
				else if (pilmat == 5){
					matkul = "BAHASA INGGRIS";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "E";	
				} 
				else if (pilmat == 6){
					matkul = "BAHASA INGGRIS";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "F";
				} 
				else if (pilmat == 7){
					matkul = "BAHASA INGGRIS";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "R";
				}	
			}	
			else if (pil == 4){
				
				gotoxy(32,9); cout<<"|  1  | KALKULUS II                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | KALKULUS II                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | KALKULUS II                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | KALKULUS II                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | KALKULUS II                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | KALKULUS II                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | KALKULUS II                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
					
				if (pilmat == 1){
					
					matkul = "KALKULUS II";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IA";		
				} 
				else if (pilmat == 2){
					
					matkul = "KALKULUS II";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IB";		
				} 
				else if (pilmat == 3){
							
					matkul = "KALKULUS II";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IC";		
				} 
				else if (pilmat == 4){
						
					matkul = "KALKULUS II";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "ID";
						
				} 
				else if (pilmat == 5){
						
					matkul = "KALKULUS II";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IE";		
				} 
				else if (pilmat == 6){
						
					matkul = "KALKULUS II";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IF";		
				} 
				else if (pilmat == 7){
						
					matkul = "KALKULUS II";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IR";		
				}	
			}
			
			else if (pil == 5){
				
				gotoxy(32,9); cout<<"|  1  | FISIKA DASAR II                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | FISIKA DASAR II                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | FISIKA DASAR II                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | FISIKA DASAR II                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | FISIKA DASAR II                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | FISIKA DASAR II                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | FISIKA DASAR II                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
					
				if (pilmat == 1){
				
					matkul = "FISIKA DASAR II";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "A";
				} 	
				else if (pilmat == 2){
				
					matkul = "FISIKA DASAR II";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "B";
				} 				
				else if (pilmat == 3){
				
					matkul = "FISIKA DASAR II";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "C";
				} 
				
				else if (pilmat == 4){
				
					matkul = "FISIKA DASAR II";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "D";	
				} 
				
				else if (pilmat == 5){
				
					matkul = "FISIKA DASAR II";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "E";
				} 
				
				else if (pilmat == 6){
				
					matkul = "FISIKA DASAR II";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "F";
				} 
				else if (pilmat == 7){
				
					matkul = "FISIKA DASAR II";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "R";
				}	
			}
			
			else if (pil == 6){
				
				gotoxy(32,9); cout<<"|  1  | KRISTALOGRAFI DAN MINERALOGI                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | KRISTALOGRAFI DAN MINERALOGI                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | KRISTALOGRAFI DAN MINERALOGI                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | KRISTALOGRAFI DAN MINERALOGI                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | KRISTALOGRAFI DAN MINERALOGI                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | KRISTALOGRAFI DAN MINERALOGI                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | KRISTALOGRAFI DAN MINERALOGI                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
					
				if (pilmat == 1){
					
					matkul = "KRISTALOGRAFI DAN MINERALOGI";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "A";
				} 
				else if (pil == 2){
					
					matkul = "KRISTALOGRAFI DAN MINERALOGI";
					kodeMatkul = "14620063";
					dosen = "Unknown";
					sks = 3;
					kelas = "B";
				}
				else if (pil == 3){
					
					matkul = "KRISTALOGRAFI DAN MINERALOGI";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "C";
				} 
				else if (pil == 4){
					
					matkul = "KRISTALOGRAFI DAN MINERALOGI";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "D";
	
				} else if (pil == 5){
					matkul = "KRISTALOGRAFI DAN MINERALOGI";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "E";
				} else if (pil == 6){
					matkul = "KRISTALOGRAFI DAN MINERALOGI";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "F";
				} else if (pil == 7){
					matkul = "KRISTALOGRAFI DAN MINERALOGI";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "R";
				}
					
			}
			if (pil == 7) {
				break;
			}
			batas = batas + sks;
			
			if(batas > 24){
				cout << endl<<endl;
				cout << "input SKS anda melebihi batas !! "<<endl<<endl;
				
				cout << "Jumlah SKS yang Melebihi Batas : ";
				cout << batas<<endl;
				
				cout << "Matkul yang tidak bisa Diinputkan : ";
				cout << matkul<<endl;
				
				cout << "SKS dari Mata Kuliah " << matkul << " adalah : "; 
				cout << sks<<endl;
			
				cout << "Total Mata Kuliah yang Telah Diambil : ";
				cout << baru->total<<endl;
				
				cout << "Index : ";
				cout << i<<endl<<endl;
				
				getch();
				
				cout << "Mau memperbarui data sks terakhir anda ?" ;
				cin >> ulang;
					
				batas = batas - sks;
					
				if(ulang == 'y')
					continue;
				else
					break;
			}	
						
			if (batas <= 24){
							
				if(batas == 24){
					
					cout << endl;
					cout << endl;
					cout<<"Batas SKS tercapai !!";
				}
							
				baru->matkul[i] = matkul;
				baru->sks[i] = sks;
				baru->kodeMatkul[i] = kodeMatkul;
				baru->dosen[i] = dosen;
				baru->kelas[i] = kelas;
				baru->total++;
//				i++;
				
				if (batas < 24){
					cout << "tambah ? ";
					cin >> ulang;
						
						
					if (ulang == 't'){
						break;
					}	
				}
				
				cout << endl;
				cout << endl;
				cout << "Jumlah SKS yang sudah diambil : ";
				cout << batas;
				cout << endl << endl;
				
				cout << "Matkul yang Diinputkan : ";
				cout << matkul;
				cout << endl << endl;
				
				cout << "SKS dari Mata Kuliah " << matkul << " adalah : "; 
				cout << sks;
				cout << endl << endl;
			
				cout << "Total Mata Kuliah yang Telah Diambil : ";
				cout << baru->total;
				cout << endl << endl;
				
				cout << "Index : ";
				cout << i;
				cout << endl;
				cout << endl;
				
				i++;
				
				getch();
							
			}
	}
}

	else if (fakultas[kodeFak] == fakultas[3] && pos3 == ft[5]){
		while ( ulang == 'y'){
	
			system("cls");
			gotoxy(16,2); cout<<"Nama : "<<baru->nama;
			gotoxy(16,3); cout<<"NBI  : "<<baru->nbi;
			gotoxy(66,2); cout<<"Fakultas : "<<baru->fakultas;
			gotoxy(66,3); cout<<"Jurusan  : "<<baru->jurusan;
			gotoxy(15,4); cout<<"=========================================================================================";
			gotoxy(50,5); cout<<"PILIHAN MATA KULIAH";
			gotoxy(32,6); cout<<"=========================================================";
			gotoxy(32,7); cout<<"| PIL |                  NAMA                     | SKS |";
			gotoxy(32,8); cout<<"=========================================================";
			gotoxy(32,9); cout<<"|  1  | PEMROGAMAN BERORIENTASI OBJEK FUNGSIONAL |  3  |";
			gotoxy(32,10); cout<<"|  2  | MATEMATIKA KOMPUTASI                     |  4  |";
			gotoxy(32,11); cout<<"|  3  | STRUKTUR DATA DAN ALGORITMA              |  3  |";
			gotoxy(32,12); cout<<"|  4  | GRAF DAN OTOMATA                         |  2  |";
			gotoxy(32,13); cout<<"|  5  | ARSITEKTUR DAN ORGANISASI KOMPUTER       |  4  |";
			gotoxy(32,14); cout<<"|  6  | PENDIDIKAN PANCASILA                     |  3  |";
			gotoxy(32,15); cout<<"=========================================================";
			gotoxy(32,16); cout<<"|                                              (7) EXIT |";
			gotoxy(32,17); cout<<"=========================================================";
			gotoxy(32,19); cout<<"Pilihan Anda : ";
			gotoxy(47,19); cin>>pil;
			
			system("cls");
			gotoxy(16,2); cout<<"Nama : "<<baru->nama;
			gotoxy(16,3); cout<<"NBI  : "<<baru->nbi;
			gotoxy(66,2); cout<<"Fakultas : "<<baru->fakultas;
			gotoxy(66,3); cout<<"Jurusan  : "<<baru->jurusan;
			gotoxy(15,4); cout<<"=========================================================================================";
			gotoxy(50,5); cout<<"PILIHAN MATA KULIAH";
			gotoxy(32,6); cout<<"=========================================================";
			gotoxy(32,7); cout<<"| PIL |                  NAMA                   | KELAS |";
			gotoxy(32,8); cout<<"=========================================================";
				
			if (pil == 1){
				
				gotoxy(32,9); cout<<"|  1  | PEMROGAMAN BERORIENTASI OBJEK FUNGSIONAL |  A  |";
				gotoxy(32,10); cout<<"|  2  | PEMROGAMAN BERORIENTASI OBJEK FUNGSIONAL |  B  |";
				gotoxy(32,11); cout<<"|  3  | PEMROGAMAN BERORIENTASI OBJEK FUNGSIONAL |  C  |";
				gotoxy(32,12); cout<<"|  4  | PEMROGAMAN BERORIENTASI OBJEK FUNGSIONAL |  D  |";
				gotoxy(32,13); cout<<"|  5  | PEMROGAMAN BERORIENTASI OBJEK FUNGSIONAL |  E  |";
				gotoxy(32,14); cout<<"|  6  | PEMROGAMAN BERORIENTASI OBJEK FUNGSIONAL |  F  |";
				gotoxy(32,15); cout<<"|  7  | PEMROGAMAN BERORIENTASI OBJEK FUNGSIONAL |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
				
				if (pilmat == 1){
	
					matkul = "PEMROGAMAN BERORIENTASI OBJEK FUNGSIONAL";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "A";
	
				} else if (pilmat == 2){
					matkul = "PEMROGAMAN BERORIENTASI OBJEK FUNGSIONAL";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "B";
	
				} else if (pilmat == 3){
					matkul = "PEMROGAMAN BERORIENTASI OBJEK FUNGSIONAL";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "C";
	
				}else if (pilmat == 4){
					matkul = "PEMROGAMAN BERORIENTASI OBJEK FUNGSIONAL";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "D";
					
				}else if (pilmat == 5){
					matkul = "PEMROGAMAN BERORIENTASI OBJEK FUNGSIONAL";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "E";
				
				} else if (pilmat == 6) {
					matkul = "PEMROGAMAN BERORIENTASI OBJEK FUNGSIONAL";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "F";
					
				} else if (pilmat == 7){
					matkul = "PEMROGAMAN BERORIENTASI OBJEK FUNGSIONAL";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "R";
				}	
			}
			else if (pil == 2){
				
				gotoxy(32,9); cout<<"|  1  | MATEMATIKA KOMPUTASI |  A  |";
				gotoxy(32,10); cout<<"|  2  | MATEMATIKA KOMPUTASI |  B  |";
				gotoxy(32,11); cout<<"|  3  | MATEMATIKA KOMPUTASI |  C  |";
				gotoxy(32,12); cout<<"|  4  | MATEMATIKA KOMPUTASI |  D  |";
				gotoxy(32,13); cout<<"|  5  | MATEMATIKA KOMPUTASI |  E  |";
				gotoxy(32,14); cout<<"|  6  | MATEMATIKA KOMPUTASI |  F  |";
				gotoxy(32,15); cout<<"|  7  | MATEMATIKA KOMPUTASI |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
				
				if (pilmat == 1){
					matkul = "MATEMATIKA KOMPUTASI";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "A";
					
				}
				else if (pilmat == 2){
					matkul = "MATEMATIKA KOMPUTASI";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "B";
					
				} 
				else if (pilmat == 3){
					matkul = "MATEMATIKA KOMPUTASI";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "C";
					
				}
				else if (pilmat == 4){
					matkul = "MATEMATIKA KOMPUTASI";
					kodeMatkul = "Unknown";
					dosen = "MATKUL FT 1 2";
					sks = 4;
					kelas = "D";
					
				} else if (pilmat == 5){
					matkul = "MATEMATIKA KOMPUTASI";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "E";
					
				} else if (pilmat == 6){
					matkul = "MATEMATIKA KOMPUTASI";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "F";		
					
				} else if (pilmat == 7){
					matkul = "MATEMATIKA KOMPUTASI";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "R";
					
				}
			}
			else if (pil == 3){
				
				gotoxy(32,9); cout<<"|  1  | STRUKTUR DATA DAN ALGORITMA |  A  |";
				gotoxy(32,10); cout<<"|  2  | STRUKTUR DATA DAN ALGORITMA |  B  |";
				gotoxy(32,11); cout<<"|  3  | STRUKTUR DATA DAN ALGORITMA |  C  |";
				gotoxy(32,12); cout<<"|  4  | STRUKTUR DATA DAN ALGORITMA |  D  |";
				gotoxy(32,13); cout<<"|  5  | STRUKTUR DATA DAN ALGORITMA |  E  |";
				gotoxy(32,14); cout<<"|  6  | STRUKTUR DATA DAN ALGORITMA |  F  |";
				gotoxy(32,15); cout<<"|  7  | STRUKTUR DATA DAN ALGORITMA |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
					
				if (pilmat == 1){
					matkul = "STRUKTUR DATA DAN ALGORITMA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "A";
				} 
				else if (pilmat == 2){
					matkul = "STRUKTUR DATA DAN ALGORITMA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "B";	
				} 
				else if (pilmat == 3){
					matkul = "STRUKTUR DATA DAN ALGORITMA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "C";	
				} 
				else if (pilmat == 4){
					matkul = "STRUKTUR DATA DAN ALGORITMA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "D";	
				} 
				else if (pilmat == 5){
					matkul = "STRUKTUR DATA DAN ALGORITMA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "E";	
				} 
				else if (pilmat == 6){
					matkul = "STRUKTUR DATA DAN ALGORITMA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "F";
				} 
				else if (pilmat == 7){
					matkul = "STRUKTUR DATA DAN ALGORITMA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "R";
				}	
			}	
			else if (pil == 4){
				
				gotoxy(32,9); cout<<"|  1  | GRAF DAN OTOMATA |  A  |";
				gotoxy(32,10); cout<<"|  2  | GRAF DAN OTOMATA |  B  |";
				gotoxy(32,11); cout<<"|  3  | GRAF DAN OTOMATA |  C  |";
				gotoxy(32,12); cout<<"|  4  | GRAF DAN OTOMATA |  D  |";
				gotoxy(32,13); cout<<"|  5  | GRAF DAN OTOMATA |  E  |";
				gotoxy(32,14); cout<<"|  6  | GRAF DAN OTOMATA |  F  |";
				gotoxy(32,15); cout<<"|  7  | GRAF DAN OTOMATA |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
					
				if (pilmat == 1){
					
					matkul = "GRAF DAN OTOMATA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IA";		
				} 
				else if (pilmat == 2){
					
					matkul = "GRAF DAN OTOMATA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IB";		
				} 
				else if (pilmat == 3){
							
					matkul = "GRAF DAN OTOMATA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IC";		
				} 
				else if (pilmat == 4){
						
					matkul = "GRAF DAN OTOMATA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "ID";
						
				} 
				else if (pilmat == 5){
						
					matkul = "GRAF DAN OTOMATA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IE";		
				} 
				else if (pilmat == 6){
						
					matkul = "GRAF DAN OTOMATA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IF";		
				} 
				else if (pilmat == 7){
						
					matkul = "GRAF DAN OTOMATA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 2;
					kelas = "IR";		
				}	
			}
			
			else if (pil == 5){
				
				gotoxy(32,9); cout<<"|  1  | ARSITEKTUR DAN ORGANISASI KOMPUTER |  A  |";
				gotoxy(32,10); cout<<"|  2  | ARSITEKTUR DAN ORGANISASI KOMPUTER |  B  |";
				gotoxy(32,11); cout<<"|  3  | ARSITEKTUR DAN ORGANISASI KOMPUTER |  C  |";
				gotoxy(32,12); cout<<"|  4  | ARSITEKTUR DAN ORGANISASI KOMPUTER |  D  |";
				gotoxy(32,13); cout<<"|  5  | ARSITEKTUR DAN ORGANISASI KOMPUTER |  E  |";
				gotoxy(32,14); cout<<"|  6  | ARSITEKTUR DAN ORGANISASI KOMPUTER |  F  |";
				gotoxy(32,15); cout<<"|  7  | ARSITEKTUR DAN ORGANISASI KOMPUTER |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
					
				if (pilmat == 1){
				
					matkul = "ARSITEKTUR DAN ORGANISASI KOMPUTER";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "A";
				} 	
				else if (pilmat == 2){
				
					matkul = "ARSITEKTUR DAN ORGANISASI KOMPUTER";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "B";
				} 				
				else if (pilmat == 3){
				
					matkul = "ARSITEKTUR DAN ORGANISASI KOMPUTER";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "C";
				} 
				
				else if (pilmat == 4){
				
					matkul = "ARSITEKTUR DAN ORGANISASI KOMPUTER";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "D";	
				} 
				
				else if (pilmat == 5){
				
					matkul = "ARSITEKTUR DAN ORGANISASI KOMPUTER";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "E";
				} 
				
				else if (pilmat == 6){
				
					matkul = "ARSITEKTUR DAN ORGANISASI KOMPUTER";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "F";
				} 
				else if (pilmat == 7){
				
					matkul = "ARSITEKTUR DAN ORGANISASI KOMPUTER";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 4;
					kelas = "R";
				}	
			}
			
			else if (pil == 6){
				
				gotoxy(32,9); cout<<"|  1  | PENDIDIKAN PANCASILA                       |  A  |";
				gotoxy(32,10); cout<<"|  2  | PENDIDIKAN PANCASILA                       |  B  |";
				gotoxy(32,11); cout<<"|  3  | PENDIDIKAN PANCASILA                       |  C  |";
				gotoxy(32,12); cout<<"|  4  | PENDIDIKAN PANCASILA                       |  D  |";
				gotoxy(32,13); cout<<"|  5  | PENDIDIKAN PANCASILA                       |  E  |";
				gotoxy(32,14); cout<<"|  6  | PENDIDIKAN PANCASILA                       |  F  |";
				gotoxy(32,15); cout<<"|  7  | PENDIDIKAN PANCASILA                       |  R  |";
				gotoxy(32,16); cout<<"=========================================================";
				gotoxy(32,18); cout<<"Pilihan Anda : ";
				gotoxy(47,18); cin>>pilmat;
					
				if (pilmat == 1){
					
					matkul = "PENDIDIKAN PANCASILA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "A";
				} 
				else if (pil == 2){
					
					matkul = "PENDIDIKAN PANCASILA";
					kodeMatkul = "14620063";
					dosen = "Unknown";
					sks = 3;
					kelas = "B";
				}
				else if (pil == 3){
					
					matkul = "PENDIDIKAN PANCASILA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "C";
				} 
				else if (pil == 4){
					
					matkul = "PENDIDIKAN PANCASILA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "D";
	
				} else if (pil == 5){
					matkul = "PENDIDIKAN PANCASILA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "E";
				} else if (pil == 6){
					matkul = "PENDIDIKAN PANCASILA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "F";
				} else if (pil == 7){
					matkul = "PENDIDIKAN PANCASILA";
					kodeMatkul = "Unknown";
					dosen = "Unknown";
					sks = 3;
					kelas = "R";
				}
					
			}
			if (pil == 7) {
				break;
			}
			batas = batas + sks;
			
			if(batas > 24){
				cout << endl<<endl;
				cout << "input SKS anda melebihi batas !! "<<endl<<endl;
				
				cout << "Jumlah SKS yang Melebihi Batas : ";
				cout << batas<<endl;
				
				cout << "Matkul yang tidak bisa Diinputkan : ";
				cout << matkul<<endl;
				
				cout << "SKS dari Mata Kuliah " << matkul << " adalah : "; 
				cout << sks<<endl;
			
				cout << "Total Mata Kuliah yang Telah Diambil : ";
				cout << baru->total<<endl;
				
				cout << "Index : ";
				cout << i<<endl<<endl;
				
				getch();
				
				cout << "Mau memperbarui data sks terakhir anda ?" ;
				cin >> ulang;
					
				batas = batas - sks;
					
				if(ulang == 'y')
					continue;
				else
					break;
			}	
						
			if (batas <= 24){
							
				if(batas == 24){
					
					cout << endl;
					cout << endl;
					cout<<"Batas SKS tercapai !!";
				}
							
				baru->matkul[i] = matkul;
				baru->sks[i] = sks;
				baru->kodeMatkul[i] = kodeMatkul;
				baru->dosen[i] = dosen;
				baru->kelas[i] = kelas;
				baru->total++;
//				i++;
				
				if (batas < 24){
					cout << "tambah ? ";
					cin >> ulang;
						
						
					if (ulang == 't'){
						break;
					}	
				}
				
				cout << endl;
				cout << endl;
				cout << "Jumlah SKS yang sudah diambil : ";
				cout << batas;
				cout << endl << endl;
				
				cout << "Matkul yang Diinputkan : ";
				cout << matkul;
				cout << endl << endl;
				
				cout << "SKS dari Mata Kuliah " << matkul << " adalah : "; 
				cout << sks;
				cout << endl << endl;
			
				cout << "Total Mata Kuliah yang Telah Diambil : ";
				cout << baru->total;
				cout << endl << endl;
				
				cout << "Index : ";
				cout << i;
				cout << endl;
				cout << endl;
				
				i++;
				
				getch();
							
			}
	}
}

	
	/*while ( ulang == 'y'){
	
			system("cls");
			cout<<"1. STRUKTUR DATA DAN ALGORITMA\n";
			cout<<"2. MATEMATIKA KOMPUTASI\n";
			cout<<"3. ARSITEKTUR DAN ORGANISASI KOMPUTER\n";
			cout<<"4. PENDIDIKAN PANCASILA DAN KEWARGANEGARAAN\n";
			cout<<"5. PEMROGRAMAN BERBASIS OBJEK FUNGSIONAL\n";
			cout<<"6. GRAF DAN OTOMATA\n";
			cout<<"7. EXIT\n";
			cout<<"Pilihan Anda : "; 
			cin>>pil;
				
			if (pil == 1){
				system("cls");
				cout<<"1. STRUKTUR DATA DAN ALGORITMA (A)\n";
				cout<<"2. STRUKTUR DATA DAN ALGORITMA (B)\n";
				cout<<"3. STRUKTUR DATA DAN ALGORITMA (C)\n";
				cout<<"4. STRUKTUR DATA DAN ALGORITMA (D)\n";
				cout<<"5. STRUKTUR DATA DAN ALGORITMA (E)\n";
				cout<<"6. STRUKTUR DATA DAN ALGORITMA (F)\n";
				cout<<"7. STRUKTUR DATA DAN ALGORITMA (R)\n";
				cout<<"Pilihan Anda : ";
				cin>>pilmat;
				
				if (pilmat == 1){
	
					matkul = "STRUKTUR DATA DAN ALGORITMA";
					kodeMatkul = "14620103";
					dosen = "Unknown";
					sks = 3;
					kelas = "A";
	
				} else if (pilmat == 2){
					matkul = "STRUKTUR DATA DAN ALGORITMA";
					kodeMatkul = "14620103";
					dosen = "Unknown";
					sks = 3;
					kelas = "B";
	
				} else if (pilmat == 3){
					matkul = "STRUKTUR DATA DAN ALGORITMA";
					kodeMatkul = "14620103";
					dosen = "Unknown";
					sks = 3;
					kelas = "C";
	
				}else if (pilmat == 4){
					matkul = "STRUKTUR DATA DAN ALGORITMA";
					kodeMatkul = "14620103";
					dosen = "Geri Kusnanto, S.Kom., M.M.";
					sks = 3;
					kelas = "D";
					
				}else if (pilmat == 5){
					matkul = "STRUKTUR DATA DAN ALGORITMA";
					kodeMatkul = "14620103";
					dosen = "Unknown";
					sks = 3;
					kelas = "E";
				
				} else if (pilmat == 6) {
					matkul = "STRUKTUR DATA DAN ALGORITMA";
					kodeMatkul = "14620103";
					dosen = "Unknown";
					sks = 3;
					kelas = "F";
					
				} else if (pilmat == 7){
					matkul = "STRUKTUR DATA DAN ALGORITMA";
					kodeMatkul = "14620103";
					dosen = "Unknown";
					sks = 3;
					kelas = "R";
				}
				
				
			}
			
			else if (pil == 2){
				system("cls");
				cout<<"1. MATEMATIKA KOMPUTASI (A)\n";
				cout<<"2. MATEMATIKA KOMPUTASI (B)\n";
				cout<<"3. MATEMATIKA KOMPUTASI (C)\n";
				cout<<"4. MATEMATIKA KOMPUTASI (D)\n";
				cout<<"5. MATEMATIKA KOMPUTASI (E)\n";
				cout<<"6. MATEMATIKA KOMPUTASI (F)\n";
				cout<<"7. MATEMATIKA KOMPUTASI (R)\n";
				cout<<"Pilihan Anda : "; 
				cin>>pilmat;
				
				if (pilmat == 1){
					matkul = "MATEMATIKA KOMPUTASI";
					kodeMatkul = "14620094";
					dosen = "Unknown";
					sks = 4;
					kelas = "A";
				}
				
				else if (pilmat == 2){
					matkul = "MATEMATIKA KOMPUTASI";
					kodeMatkul = "14620094";
					dosen = "Unknown";
					sks = 4;
					kelas = "B";
				} 
				
				else if (pilmat == 3){
					matkul = "MATEMATIKA KOMPUTASI";
					kodeMatkul = "14620094";
					dosen = "Unknown";
					sks = 4;
					kelas = "C";
					
				}
				
				else if (pilmat == 4){
					matkul = "MATEMATIKA KOMPUTASI";
					kodeMatkul = "14620094";
					dosen = "Mochamad Sidqon, S.Si., M.Si.";
					sks = 4;
					kelas = "D";
					
				} else if (pilmat == 5){
					matkul = "MATEMATIKA KOMPUTASI";
					kodeMatkul = "14620094";
					dosen = "Unknown";
					sks = 4;
					kelas = "E";
					
				} else if (pilmat == 6){
					matkul = "MATEMATIKA KOMPUTASI";
					kodeMatkul = "14620094";
					dosen = "Unknown";
					sks = 4;
					kelas = "F";
					
				} else if (pilmat == 7){
					matkul = "MATEMATIKA KOMPUTASI";
					kodeMatkul = "14620094";
					dosen = "Unknown";
					sks = 4;
					kelas = "R";
					}
					
			}
				
			else if (pil == 3){
				system("cls");
				cout<<"1. ARSITEKTUR DAN ORGANISASI KOMPUTER (A)\n";
				cout<<"2. ARSITEKTUR DAN ORGANISASI KOMPUTER (B)\n";
				cout<<"3. ARSITEKTUR DAN ORGANISASI KOMPUTER (C)\n";
				cout<<"4. ARSITEKTUR DAN ORGANISASI KOMPUTER (D)\n";
				cout<<"5. ARSITEKTUR DAN ORGANISASI KOMPUTER (E)\n";
				cout<<"6. ARSITEKTUR DAN ORGANISASI KOMPUTER (F)\n";
				cout<<"7. ARSITEKTUR DAN ORGANISASI KOMPUTER (R)\n";
				cout<<"Pilihan Anda : "; cin>>pilmat;
					
				if (pilmat == 1){
					matkul = "ARSITEKTUR DAN ORGANISASI KOMPUTER";
					kodeMatkul = "14620103";
					dosen = "Unknown";
					sks = 3;
					kelas = "A";
	
				} 
				
				else if (pilmat == 2){
					matkul = "ARSITEKTUR DAN ORGANISASI KOMPUTER";
					kodeMatkul = "14620103";
					dosen = "Unknown";
					sks = 3;
					kelas = "B";
					
				} 
				
				else if (pilmat == 3){
					matkul = "ARSITEKTUR DAN ORGANISASI KOMPUTER";
					kodeMatkul = "14620103";
					dosen = "Unknown";
					sks = 3;
					kelas = "C";
					
				} 
				
				else if (pilmat == 4){
					matkul = "ARSITEKTUR DAN ORGANISASI KOMPUTER";
					kodeMatkul = "14620103";
					dosen = "Anton Breva Yunanda, S.T., M.MT";
					sks = 3;
					kelas = "D";
					
				} 
				
				else if (pilmat == 5){
					matkul = "ARSITEKTUR DAN ORGANISASI KOMPUTER";
					kodeMatkul = "14620103";
					dosen = "Unknown";
					sks = 3;
					kelas = "E";
					
				} 
				
				else if (pilmat == 6){
					matkul = "ARSITEKTUR DAN ORGANISASI KOMPUTER";
					kodeMatkul = "14620103";
					dosen = "Unknown";
					sks = 3;
					kelas = "F";
				} 
				
				else if (pilmat == 7){
					matkul = "ARSITEKTUR DAN ORGANISASI KOMPUTER";
					kodeMatkul = "14620103";
					dosen = "Unknown";
					sks = 3;
					kelas = "R";
				}
					
			}	
				
			else if (pil == 4){
				system("cls");
				cout<<"1. PENDIDIKAN PANCASILA DAN KEWARGANEGARAAN (IA)\n";
				cout<<"2. PENDIDIKAN PANCASILA DAN KEWARGANEGARAAN (IB)\n";
				cout<<"3. PENDIDIKAN PANCASILA DAN KEWARGANEGARAAN (IC)\n";
				cout<<"4. PENDIDIKAN PANCASILA DAN KEWARGANEGARAAN (ID)\n";
				cout<<"5. PENDIDIKAN PANCASILA DAN KEWARGANEGARAAN (IE)\n";
				cout<<"6. PENDIDIKAN PANCASILA DAN KEWARGANEGARAAN (IF)\n";
				cout<<"7. PENDIDIKAN PANCASILA DAN KEWARGANEGARAAN (IR)\n";
				cout<<"Pilihan Anda : "; 
				cin>>pilmat;
					
				if (pilmat == 1){
					
					matkul = "PENDIDIKAN PANCASILA DAN KEWARGANEGARAAN";
					kodeMatkul = "000102";
					dosen = "Unknown";
					sks = 2;
					kelas = "IA";
						
				} 
				
				else if (pilmat == 2){
					
					matkul = "PENDIDIKAN PANCASILA DAN KEWARGANEGARAAN";
					kodeMatkul = "000102";
					dosen = "Unknown";
					sks = 2;
					kelas = "IB";
						
				} 
				
				else if (pilmat == 3){
							
					matkul = "PENDIDIKAN PANCASILA DAN KEWARGANEGARAAN";
					kodeMatkul = "000102";
					dosen = "Unknown";
					sks = 2;
					kelas = "IC";
						
				} 
				
				else if (pilmat == 4){
						
					matkul = "PENDIDIKAN PANCASILA DAN KEWARGANEGARAAN";
					kodeMatkul = "000102";
					dosen = "Abraham Ferry Rosando, S.H., M.H.";
					sks = 2;
					kelas = "ID";
						
				} 
				
				else if (pilmat == 5){
						
					matkul = "PENDIDIKAN PANCASILA DAN KEWARGANEGARAAN";
					kodeMatkul = "000102";
					dosen = "Unknown";
					sks = 2;
					kelas = "IE";
						
				} 
				
				else if (pilmat == 6){
						
					matkul = "PENDIDIKAN PANCASILA DAN KEWARGANEGARAAN";
					kodeMatkul = "000102";
					dosen = "Unknown";
					sks = 2;
					kelas = "IF";
						
				} 
				
				else if (pilmat == 7){
						
					matkul = "PENDIDIKAN PANCASILA DAN KEWARGANEGARAAN";
					kodeMatkul = "000102";
					dosen = "Unknown";
					sks = 2;
					kelas = "IR";
						
				}
					
			}
			
			else if (pil == 5){
				system("cls");
				cout<<"1. PEMROGRAMAN BERBASIS OBJEK FUNGSIONAL (A)\n";
				cout<<"2. PEMROGRAMAN BERBASIS OBJEK FUNGSIONAL (B)\n";
				cout<<"3. PEMROGRAMAN BERBASIS OBJEK FUNGSIONAL (C)\n";
				cout<<"4. PEMROGRAMAN BERBASIS OBJEK FUNGSIONAL (D)\n";
				cout<<"5. PEMROGRAMAN BERBASIS OBJEK FUNGSIONAL (E)\n";
				cout<<"6. PEMROGRAMAN BERBASIS OBJEK FUNGSIONAL (F)\n";
				cout<<"7. PEMROGRAMAN BERBASIS OBJEK FUNGSIONAL (R)\n";
				cout<<"Pilihan Anda : "; cin>>pilmat;
					
				if (pilmat == 1){
				
					matkul = "PEMROGRAMAN BERBASIS OBJEK FUNGSIONAL";
					kodeMatkul = "14620074";
					dosen = "Unknown";
					sks = 4;
					kelas = "A";
	
				} 
				
				else if (pilmat == 2){
				
					matkul = "PEMROGRAMAN BERBASIS OBJEK FUNGSIONAL";
					kodeMatkul = "14620074";
					dosen = "Unknown";
					sks = 4;
					kelas = "B";
	
				} 
				
				else if (pilmat == 3){
				
					matkul = "PEMROGRAMAN BERBASIS OBJEK FUNGSIONAL";
					kodeMatkul = "14620074";
					dosen = "Unknown";
					sks = 4;
					kelas = "C";
	
				} 
				
				else if (pilmat == 4){
				
					matkul = "PEMROGRAMAN BERBASIS OBJEK FUNGSIONAL";
					kodeMatkul = "14620074";
					dosen = "Chaidir Chalaf Islamy, S.Kom., M.Kom.";
					sks = 4;
					kelas = "D";
	
				} 
				
				else if (pilmat == 5){
				
					matkul = "PEMROGRAMAN BERBASIS OBJEK FUNGSIONAL";
					kodeMatkul = "14620074";
					dosen = "Unknown";
					sks = 4;
					kelas = "E";
	
				} 
				
				else if (pilmat == 6){
				
					matkul = "PEMROGRAMAN BERBASIS OBJEK FUNGSIONAL";
					kodeMatkul = "14620074";
					dosen = "Unknown";
					sks = 4;
					kelas = "F";
	
				} 
				
				else if (pilmat == 7){
				
					matkul = "PEMROGRAMAN BERBASIS OBJEK FUNGSIONAL";
					kodeMatkul = "14620074";
					dosen = "Unknown";
					sks = 4;
					kelas = "R";
	
				}
					
			}
			
			else if (pil == 6){
				system("cls");
				cout<<"1. GRAF DAN OTOMATA (A)\n";
				cout<<"2. GRAF DAN OTOMATA (B)\n";
				cout<<"3. GRAF DAN OTOMATA (C)\n";
				cout<<"4. GRAF DAN OTOMATA (D)\n";
				cout<<"5. GRAF DAN OTOMATA (E)\n";
				cout<<"6. GRAF DAN OTOMATA (F)\n";
				cout<<"7. GRAF DAN OTOMATA (R)\n";
				cout<<"Pilihan Anda : "; 
				cin>>pilmat;
					
				if (pilmat == 1){
					
					matkul = "GRAF DAN OTOMATA";
					kodeMatkul = "14620063";
					dosen = "Unknown";
					sks = 3;
					kelas = "A";
	
				} 
				
				else if (pil == 2){
					
					matkul = "GRAF DAN OTOMATA";
					kodeMatkul = "14620063";
					dosen = "Unknown";
					sks = 3;
					kelas = "B";
	
				} 
				
				else if (pil == 3){
					
					matkul = "GRAF DAN OTOMATA";
					kodeMatkul = "14620063";
					dosen = "Unknown";
					sks = 3;
					kelas = "C";
	
				} 
				
				else if (pil == 4){
					
					matkul = "GRAF DAN OTOMATA";
					kodeMatkul = "14620063";
					dosen = " Geri Kusnanto, S.Kom., M.M.";
					sks = 3;
					kelas = "D";
	
				} 
				
				else if (pil == 5){
					
					matkul = "GRAF DAN OTOMATA";
					kodeMatkul = "14620063";
					dosen = "Unknown";
					sks = 3;
					kelas = "E";
	
				} 
				
				else if (pil == 6){
					
					matkul = "GRAF DAN OTOMATA";
					kodeMatkul = "14620063";
					dosen = "Unknown";
					sks = 3;
					kelas = "F";
	
				} 
				
				else if (pil == 7){
					
					matkul = "GRAF DAN OTOMATA";
					kodeMatkul = "14620063";
					dosen = "Unknown";
					sks = 3;
					kelas = "R";
	
				}
					
			}
			
			if (pil == 7) {
					
				break;
				
			}		
			batas = batas + sks;
			
				
			if(batas > 24){
				cout << endl;
				cout << endl;
				cout << "input SKS anda melebihi batas !! ";
				cout << endl;
				cout << endl;
				
				cout << "Jumlah SKS yang Melebihi Batas : ";
				cout << batas;
				cout << endl;
				
				cout << "Matkul yang tidak bisa Diinputkan : ";
				cout << matkul;
				cout << endl;
				
				cout << "SKS dari Mata Kuliah " << matkul << " adalah : "; 
				cout << sks;
				cout << endl;
			
				cout << "Total Mata Kuliah yang Telah Diambil : ";
				cout << baru->total;
				cout << endl;
				
				cout << "Index : ";
				cout << i;
				cout << endl;
				cout << endl;
				
				getch();
				
				cout << "Mau memperbarui data sks terakhir anda ?" ;
				cin >> ulang;
				cout << endl;
					
				batas = batas - sks;
					
					
				if(ulang == 'y')
					continue;
						
				else
					break;
					
			}
				
				
						
			if (batas <= 24){
							
				if(batas == 24){
					
					cout << endl;
					cout << endl;
					cout<<"Batas SKS tercapai !!";
	
				}
							
				baru->matkul[i] = matkul;
				baru->sks[i] = sks;
				baru->kodeMatkul[i] = kodeMatkul;
				baru->dosen[i] = dosen;
				baru->kelas[i] = kelas;
				baru->total++;
//				i++;
				
				if (batas < 24){
					cout << "tambah ? ";
					cin >> ulang;
						
						
					if (ulang == 't'){
						break;
					}	
				}
				
				cout << endl;
				cout << endl;
				cout << "Jumlah SKS yang sudah diambil : ";
				cout << batas;
				cout << endl << endl;
				
				cout << "Matkul yang Diinputkan : ";
				cout << matkul;
				cout << endl << endl;
				
				cout << "SKS dari Mata Kuliah " << matkul << " adalah : "; 
				cout << sks;
				cout << endl << endl;
			
				cout << "Total Mata Kuliah yang Telah Diambil : ";
				cout << baru->total;
				cout << endl << endl;
				
				cout << "Index : ";
				cout << i;
				cout << endl;
				cout << endl;
				
				i++;
				
				getch();
							
			}	
		}*/		
}

void hapusdata(){
	mahasiswa *pos1, *pos2;
	char name[30];
	char nim[20];
	int kodeFak, kodeJur;
	char dataKrs;
	
	system("cls");
	baru = new mahasiswa;
	gotoxy(16,3); cout<<"========================================================================================";
	gotoxy(16,4); cout<<"||"; gotoxy(102,4); cout<<"||";
	gotoxy(16,5); cout<<"||"; gotoxy(102,5); cout<<"||";
	gotoxy(16,6); cout<<"||"; gotoxy(102,6); cout<<"||";
	gotoxy(54,5); cout<<"HAPUS MAHASISWA";
	gotoxy(16,7); cout<<"========================================================================================";
	gotoxy(25,10); cout<<"Masukkan NBI mahasiswa yang ingin dihapus : ";
	gotoxy(16,8); cout<<"||"; gotoxy(102,8); cout<<"||";
	gotoxy(16,9); cout<<"||"; gotoxy(102,9); cout<<"||";
	gotoxy(16,10); cout<<"||"; gotoxy(102,10); cout<<"||";
	gotoxy(16,11); cout<<"||"; gotoxy(102,11); cout<<"||";
	gotoxy(16,12); cout<<"||"; gotoxy(102,12); cout<<"||";
	gotoxy(16,13); cout<<"||"; gotoxy(102,13); cout<<"||";
	gotoxy(16,14); cout<<"||"; gotoxy(102,14); cout<<"||";
	gotoxy(16,15); cout<<"||"; gotoxy(102,15); cout<<"||";
	gotoxy(16,16); cout<<"||"; gotoxy(102,16); cout<<"||";
	gotoxy(16,17); cout<<"||"; gotoxy(102,17); cout<<"||";
	gotoxy(16,18); cout<<"||"; gotoxy(102,18); cout<<"||";
	gotoxy(16,19); cout<<"========================================================================================";
	gotoxy(69,10); cin>>nim;
	
	kodeFak = (atoi(nim) / 100000000) % 10;
	kodeJur = atoi(nim) / 10000000;
	
	pos1 = fakultas[kodeFak-1]->next;
	
	while (atoi(pos1->kode) != kodeJur){
		pos1 = pos1->next;
	}
	pos3 = pos1;
	pos1 = pos1->daftar;
	pos2 = pos1;
	while (pos1 != NULL){
		if (atoi(pos1->nbi) == atoi(nim)) break;
		pos2 = pos1;
		pos1 = pos1->next;
	}
	if (pos1 == NULL){
		gotoxy(19,16); cout<<"Data tidak ditemukan !";
		getch();
		return;
	} else if (pos1 == pos2){
		gotoxy(19,16); cout<<"Data telah dihapus !";
		getch();
		pos3->daftar = pos1->next;
		delete pos1;
	} else {
		gotoxy(19,16); cout<<"Data telah dihapus !";
		getch();
		pos2->next = pos1->next;
		delete pos1;
	}
}

void tampilSemuaNode(){
	int i = 0, j, k = 0;
	mahasiswa *pos1;
	pos1 = pos = fakultas[i];
	
	system("cls");
	do{	
		if (pos1 == fakultas[i]){
			gotoxy(15,0+k); cout<<"=========================================================================================";
			gotoxy(15,1+k); cout<<"||                                "<<fakultas[i]->nama;
			gotoxy(102,1+k); cout<<"||";
			j = 0;
			k+=2;
			pos1 = pos = pos->next;
		}
		
		if (pos1 == feb[j] || pos1 == fh[j] || pos1 == fib[j] || pos1 == ft[j]){
			gotoxy(15,0+k); cout<<"=========================================================================================";
			gotoxy(15,1+k); cout<<"|  "<<pos1->nama;
			gotoxy(103,1+k); cout<<"|";
			gotoxy(15,2+k); cout<<"\\_______________________________________________________________________________________/";
			//cout<<pos1->nama<<", "<<pos1->kode<<endl;
			k+=3;
			pos1 = pos->daftar;
		}
		
		if (pos1 != NULL){
			gotoxy(16,0+k); cout<<"| "<<pos1->nbi<<" | "<<pos1->nama;
			gotoxy(103,0+k); cout<<"|";
			k++;
			/*cout<<pos1->nama<<endl;
			cout<<pos1->nbi<<endl;
			cout<<pos1->pass<<endl;
			cout<<pos1->id<<endl;*/
			pos1 = pos1->next;
		}
		
		if (pos1 == NULL){
			j++;
			pos = pos->next;
			pos1 = pos;
			
			if (pos == NULL && pos1 == NULL){
				i++;
				pos1 = pos = fakultas[i];
			}
		}
	} while (fakultas[i] != NULL);
	gotoxy(15,0+k); cout<<"========================================================================================";
	getch();
}

void Cari(){
	mahasiswa *pos1, *pos2, *pos3;
	int kodeFak, kodeJur;
	
	char nim[20];
	system("cls");
	gotoxy(16,3); cout<<"========================================================================================";
	gotoxy(16,4); cout<<"||"; gotoxy(102,4); cout<<"||";
	gotoxy(16,5); cout<<"||"; gotoxy(102,5); cout<<"||";
	gotoxy(16,6); cout<<"||"; gotoxy(102,6); cout<<"||";
	gotoxy(54,5); cout<<"CARI DATA MAHASISWA";
	gotoxy(16,7); cout<<"========================================================================================";
	gotoxy(25,10); cout<<"Masukkan NBI mahasiswa yang ingin dicari : ";
	gotoxy(16,8); cout<<"||"; gotoxy(102,8); cout<<"||";
	gotoxy(16,9); cout<<"||"; gotoxy(102,9); cout<<"||";
	gotoxy(16,10); cout<<"||"; gotoxy(102,10); cout<<"||";
	gotoxy(16,11); cout<<"||"; gotoxy(102,11); cout<<"||";
	gotoxy(16,12); cout<<"||"; gotoxy(102,12); cout<<"||";
	gotoxy(16,13); cout<<"||"; gotoxy(102,13); cout<<"||";
	gotoxy(16,14); cout<<"||"; gotoxy(102,14); cout<<"||";
	gotoxy(16,15); cout<<"||"; gotoxy(102,15); cout<<"||";
	gotoxy(16,16); cout<<"||"; gotoxy(102,16); cout<<"||";
	gotoxy(16,17); cout<<"||"; gotoxy(102,17); cout<<"||";
	gotoxy(16,18); cout<<"||"; gotoxy(102,18); cout<<"||";
	gotoxy(16,19); cout<<"========================================================================================";
	gotoxy(68,10); cin>>nim;
	
	kodeFak = ((atoi(nim) / 100000000) % 10) - 1;
	kodeJur = atoi(nim) / 10000000;
	
	pos1 = fakultas[kodeFak]->next;
	pos3 = fakultas[kodeFak];
	
	while (atoi(pos1->kode) != kodeJur){
		pos1 = pos1->next;
	}
    
    pos2 = pos1;
    pos1 = pos1->daftar;
    
    while (pos1 != NULL) {
        if (strcmp(pos1->nbi, nim) == 0) {
            break;
        } else pos1 = pos1->next;
    }
    
    if (pos1 == NULL) {
        gotoxy(25,12); cout << "Mahasiswa tidak ditemukan";
        getch();
    } 
	
	else {
        gotoxy(25,12); cout << "Mahasiswa ditemukan! ";
        gotoxy(47,12); cout <<"Nama : "<< pos1->nama;
        gotoxy(47,13); cout <<"NBI  : "<< pos1->nbi;
        gotoxy(47,14); cout << pos3->nama;
        gotoxy(47,15); cout << pos2->nama;
        getch();
    }
}

void tampilKRS(){
	 
	int j = 0;
	int tot = 0;
	
	system("cls");
	gotoxy(48,2); cout<<"Kartu Rencana Studi (KRS)";
	gotoxy(46,3); cout<<"(Semester Genap 2022 - 2023)";
	gotoxy(2,4); cout<<"NPM\t: "<<pos->nbi;
	gotoxy(2,5); cout<<"Nama\t: "<<pos->nama;
	gotoxy(85,4); cout<<"Jurusan\t: "<<pos->jurusan;
	gotoxy(85,5); cout<<"Semester\t: "<<"2";
	gotoxy(1,6); cout<<"--------------------------------------------------------------------------------------------------------------------";
	gotoxy(1,7); cout<<"|";			gotoxy(116,7); cout<<"|";
	gotoxy(3,7); cout<<"No.";
	gotoxy(7,7); cout<<"|";
	gotoxy(9,7); cout<<"Kode";
	gotoxy(16,7); cout<<"|";
	gotoxy(35,7); cout<<"Nama Matakuliah";
	gotoxy(65,7); cout<<"|";
	gotoxy(71,7); cout<<"Kelas";
	gotoxy(69,7); cout<<"|";
	gotoxy(66,7); cout<<"SKS";
	gotoxy(77,7); cout<<"|";
	gotoxy(88,7); cout<<"Dosen Pengajar";
	gotoxy(1,8); cout<<"--------------------------------------------------------------------------------------------------------------------";
	
	for (int i = 1; i<=baru->total; i++){
		gotoxy(18,9+j); cout<<pos->matkul[i];
		gotoxy(8,9+j); cout<<pos->kodeMatkul[i];
		gotoxy(67,9+j); cout<<pos->sks[i];
		gotoxy(73,9+j); cout<<pos->kelas[i];
		gotoxy(80,9+j); cout<<pos->dosen[i];
		tot = pos->sks[i] + tot;
		gotoxy(1,9+j); cout<<"|"; gotoxy(7,9+j); cout<<"|"; gotoxy(16,9+j); cout<<"|"; gotoxy(69,9+j); cout<<"|";
		gotoxy(3,9+j); cout<<i<<".";
		gotoxy(65,9+j); cout<<"|";
		gotoxy(77,9+j); cout<<"|";
		gotoxy(116,9+j); cout<<"|";
		gotoxy(1,10+j); cout<<"--------------------------------------------------------------------------------------------------------------------";
		j += 2;
	}
	gotoxy(1,10+j); cout<<"--------------------------------------------------------------------------------------------------------------------";
	gotoxy(40,11+j); cout<<"Total SKS yang diambil";
	gotoxy(65,11+j); cout<<"|";
	gotoxy(67,11+j); cout<<tot;
	gotoxy(69,11+j); cout<<"|";
	gotoxy(116,11+j); cout<<"|";
	gotoxy(1,12+j); cout<<"--------------------------------------------------------------------------------------------------------------------";
	gotoxy(87,13+j); cout<<"Surabaya, 4 April 2023";
	gotoxy(1,14+j); cout<<"====================================";
	gotoxy(1,15+j); cout<<"|"; 										gotoxy(36,15+j); cout<<"|";
	gotoxy(1,16+j); cout<<"|     Persetujuan Dosen Wali";				gotoxy(36,16+j); cout<<"|";
	gotoxy(1,17+j); cout<<"|";										gotoxy(36,17+j); cout<<"|";
	gotoxy(1,18+j); cout<<"|";										gotoxy(36,18+j); cout<<"|";
	gotoxy(1,19+j); cout<<"|";										gotoxy(36,19+j); cout<<"|";
	gotoxy(1,20+j); cout<<"|";										gotoxy(36,20+j); cout<<"|";
	gotoxy(1,21+j); cout<<"|";										gotoxy(36,21+j); cout<<"|";
	gotoxy(1,22+j); cout<<"|  (Gery Kusnanto, S Kom., M.M.)";			gotoxy(36,22+j); cout<<"|";
	gotoxy(1,23+j); cout<<"====================================";	
	gotoxy(81,14+j); cout<<"====================================";
	gotoxy(81,15+j); cout<<"|"; 										gotoxy(116,15+j); cout<<"|";
	gotoxy(81,16+j); cout<<"|         Tanda Tangan Ybs,";				gotoxy(116,16+j); cout<<"|";
	gotoxy(81,17+j); cout<<"|";										gotoxy(116,17+j); cout<<"|";
	gotoxy(81,18+j); cout<<"|";										gotoxy(116,18+j); cout<<"|";
	gotoxy(81,19+j); cout<<"|";										gotoxy(116,19+j); cout<<"|";
	gotoxy(81,20+j); cout<<"|";										gotoxy(116,20+j); cout<<"|";
	gotoxy(81,21+j); cout<<"|    ("<<pos->nama<<")";	 		gotoxy(116,21+j); cout<<"|";
	gotoxy(81,22+j); cout<<"|  	       "<<pos->nbi;					gotoxy(116,22+j); cout<<"|";
	gotoxy(81,23+j); cout<<"====================================";
	j = 0;
	getch();
}

void userpg(){
	int pil;
	
	while (pil <3) {
		system("cls");
		gotoxy(16,1); cout<<pos->nama;
		gotoxy(16,2); cout<<pos->nbi;
		gotoxy(80,1); cout<<pos->fakultas;
		gotoxy(80,2); cout<<pos->jurusan;
		gotoxy(16,3); cout<<"========================================================================================";
		gotoxy(16,4); cout<<"||"; gotoxy(102,4); cout<<"||";
		gotoxy(16,5); cout<<"||"; gotoxy(102,5); cout<<"||";
		gotoxy(16,6); cout<<"||"; gotoxy(102,6); cout<<"||";
		gotoxy(54,5); cout<<"USER PAGE";
		gotoxy(16,7); cout<<"========================================================================================";
		gotoxy(54,10); cout<<"(1)Tampil SKS";
		gotoxy(16,8); cout<<"||"; gotoxy(102,8); cout<<"||";
		gotoxy(16,9); cout<<"||"; gotoxy(102,9); cout<<"||";
		gotoxy(16,10); cout<<"||"; gotoxy(102,10); cout<<"||";
		gotoxy(16,11); cout<<"||"; gotoxy(102,11); cout<<"||";
		gotoxy(16,12); cout<<"||"; gotoxy(102,12); cout<<"||";
		gotoxy(16,13); cout<<"||"; gotoxy(102,13); cout<<"||";
		gotoxy(16,14); cout<<"||"; gotoxy(102,14); cout<<"||";
		gotoxy(16,15); cout<<"||"; gotoxy(102,15); cout<<"||";
		gotoxy(16,16); cout<<"||"; gotoxy(102,16); cout<<"||";
		gotoxy(16,17); cout<<"========================================================================================";
		gotoxy(90,18); cout<<"(2)Logout";
		gotoxy(16,18); cout<<"||"; gotoxy(102,18); cout<<"||";
		gotoxy(16,19); cout<<"========================================================================================";
		gotoxy(16,21); cout<<"Pilihan Anda :";
		gotoxy(32,21); cin>>pil;
		
		
		if (pil == 1) tampilKRS();
		else if (pil == 2) logout();
		else userpg();
	}
}
