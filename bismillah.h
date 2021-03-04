#ifndef BISMILLAH_H_INCLUDED
#define BISMILLAH_H_INCLUDED

#include <iostream>
#define info(A) A->info
#define first(A) A.first
#define last(A) A.last
#define prev(A) A->prev
#define next(A) A->next
#define relasi(A) A->relasi
#define firstRelasi(A) A->firstRelasi

using namespace std;

struct Tuser {
    string nama_user;
    string telepon;
    string email;
    int jum_grup;
    string password;
};

struct Tgrup{
    string nama_grup;
    int jum_user;
};
typedef Tuser infotypeUser;
typedef Tgrup infotypeGrup;
typedef struct elmtGrup *adrGrup;
typedef struct elmtUser *adrUser;
typedef struct elmtRelasi *adrRelasi;

struct elmtGrup {
    infotypeGrup info;
    adrGrup next;
    adrGrup prev;
    adrRelasi firstRelasi;
};

struct elmtUser {
    infotypeUser info;
    adrUser next;
    adrUser prev;
};

struct elmtRelasi {
    adrRelasi next;
    adrRelasi prev;
    adrUser relasi;
};

struct Grup {
    adrGrup first;
    adrGrup last;
};

struct User {
    adrUser first;
    adrUser last;
};

void createGrup (Grup &G);
void createUser (User &U);
adrGrup alokasiGrup (string namaGrup);
adrUser alokasiUser (string namaUser, string telepon, string email, string pass);
adrRelasi alokasiRelasi (adrUser Q);
bool isEmptyGrup(Grup G);
bool isEmptyUser(User U);
adrGrup searchingGrup(Grup G, string nama);
adrUser searchingUser(User U, string nama);
adrRelasi searchingRelasi(adrGrup P, string namaUser);
void insertLastGrup(Grup &G, adrGrup &P);
void insertLastUser(User &U, adrUser &P);
void insertLastRelasi(adrGrup &P, adrRelasi &R);
void deleteFirstUser(User &U);
void deleteLastUser(User &U);
void deleteAfterUser(User &U, string nama);
void deleteFirstRelasi(adrGrup &P);
void deleteLastRelasi(adrGrup &P);
void deleteAfterRelasi(adrGrup &P, adrRelasi &Q);
void deleteFirstGrup (Grup &G, User &U);
void deleteLastGrup(Grup &G, User &U);
void deleteAfterGrup(Grup &G, User &U, string nama);
void kickUserAll(Grup &G, User U, string nama);
void kickUser(Grup &G, User &U, string nama, string grup);
void deleteGrup(Grup &G, User &U, string nama);
void deleteUser(User &U, string nama);
void deleteTotalUser(User &U, Grup &G, string nama);
void inviteUser(Grup &G, User U, string namaGrup, string namaUser);
void showAll(Grup G);
void showGrupPopuler(Grup G);
void cariGrupdariUser(Grup G, string namaUser);
void userDi3Grup(User U, Grup G);
void showDataUser(User U, string nama);
void menu_main(User U, Grup G);
void menu_invite(User U, Grup G);
void buatUser_Grup(User U, Grup G);
void menu_show(User U, Grup G);
void menu_delete(User &U, Grup &G);
void menu_login(User U, Grup G);
adrUser searchingEmail(User U, string email);
adrUser searchingPass(User U, string pass);
#endif // BISMILLAH_H_INCLUDED
