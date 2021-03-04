#include "bismillah.h"

void createGrup (Grup &G){
    first(G) = NULL;
    last(G) = NULL;
}
void createUser (User &U){
    first(U) = NULL;
    last(U) = NULL;
}
adrGrup alokasiGrup (string namaGrup){
    adrGrup P = new elmtGrup;
    info(P).nama_grup = namaGrup;
    info(P).jum_user = 0;
    next(P) = NULL;
    prev(P) = NULL;
    firstRelasi(P) = NULL;
    return P;
}
adrUser alokasiUser (string namaUser, string telepon, string email, string password){
    adrUser P = new elmtUser;
    info(P).nama_user = namaUser;
    info(P).telepon = telepon;
    info(P).email = email;
    info(P).jum_grup = 0;
    info(P).password = password;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}
adrRelasi alokasiRelasi (adrUser Q){
    adrRelasi P = new elmtRelasi;
    next(P) = NULL;
    prev(P) = NULL;
    relasi(P) = Q;
    return P;
}
bool isEmptyGrup(Grup G){
    if (first(G) == NULL){
        return true;
    } else {
        return false;
    }
}
bool isEmptyUser(User U){
    if (first(U) == NULL){
        return true;
    } else {
        return false;
    }
}
adrGrup searchingGrup(Grup G, string nama){
    adrGrup P = first(G);
    bool found = false;
    while (!(found) && (P != NULL)){
        if (info(P).nama_grup == nama){
            found = true;
        }else {
            P = next(P);
        }
    }
    if (found){
        return P;
    }else {
        return NULL;
    }
}
adrUser searchingUser(User U, string nama){
    adrUser P = first(U);
    bool found = false;
    while (!(found) && (P != NULL)){
        if (info(P).nama_user == nama){
            found = true;
        }else {
            P = next(P);
        }
    }
    if (found) {
        return P;
    }else {
        return NULL;
    }
}
adrRelasi searchingRelasi(adrGrup P, string namaUser){
    adrRelasi i = firstRelasi(P);
    bool found = false;
    while (!(found) && (i != NULL)){
        if (info(relasi(i)).nama_user == namaUser){
            found = true;
        }else {
            i = next(i);
        }
    }
    if (found){
        return i;
    }else {
        return NULL;
    }
}
void insertLastGrup(Grup &G, adrGrup &P){
    string nama = info(P).nama_grup;
    if (isEmptyGrup(G) == true){
        first(G) = P;
        last(G) = P;
        cout<<"PEMBUATAN GRUP BERHASIL!!!!"<<endl;
    }else {
        if (searchingGrup(G,nama) == NULL){
            next(last(G)) = P;
            prev(P) = last(G);
            last(G) = P;
            cout<<"PEMBUATAN GRUP BERHASIL!!!!"<<endl;
        }else {
            cout<<"GAGAL, KARENA GRUP SUDAH TERDAFTAR!!!!"<<endl;
        }
    }
}
void insertLastUser(User &U, adrUser &P){
    string email = info(P).email;
    string nama = info(P).nama_user;
    if (isEmptyUser(U) == true){
        first(U) = P;
        last(U) = P;
        cout<<"PEMBUATAN USER BERHASIL!!!!"<<endl;
    }else {
        if ((searchingEmail(U,email) == NULL) && (searchingUser(U,nama) == NULL)){
            next(last(U)) = P;
            prev(P) = last(U);
            last(U) = P;
            cout<<"PEMBUATAN USER BERHASIL!!!!"<<endl;
        }else {
            cout<<"GAGAL, KARENA USER SUDAH TERDAFTAR!!!!"<<endl;
        }
    }
}
void insertLastRelasi(adrGrup &P, adrRelasi &R){
    string nama = info(relasi(R)).nama_user;
    if (firstRelasi(P) == NULL){
        firstRelasi(P) = R;
        cout<<"INVITE BERHASIL!!!!!"<<endl;
    }else {
        if (searchingRelasi(P,nama) == NULL){
            adrRelasi i = firstRelasi(P);
            while (next(i) != NULL){
                i = next(i);
            }
            next(i) = R;
            prev(R) = i;
            cout<<"INVITE BERHASIL!!!!!"<<endl;
        }else {
            cout<<"INVITE GAGAL, USER SUDAH ADA DALAM GRUP!!!"<<endl;
        }
    }
}
void deleteFirstUser(User &U){
    adrUser Q;

    Q = first(U);
    if (next(Q) == NULL){
        first(U) = NULL;
    }else{
        first(U) = next(Q);
        prev(first(U)) = NULL;
        next(Q) = NULL;
    }
}
void deleteLastUser(User &U){
    adrUser Q;

    Q = prev(last(U));
    prev(last(U)) = NULL;
    next(Q) = NULL;
    last(U) = Q;
}
void deleteAfterUser(User &U, string nama){
    adrUser P, Q;

    P = searchingUser(U, nama);
    if (P == NULL){
        cout << "Tidak ada user dengan nama itu" << endl;
    }else{
        Q = prev(P);
        next(Q) = next(P);
        prev(next(P)) = Q;
        prev(P) = NULL;
        next(P) = NULL;
    }
}
void deleteFirstRelasi(adrGrup &P){
    adrRelasi Q;

    Q = firstRelasi(P);
    if (next(Q) == NULL){
        firstRelasi(P) = NULL;
    }else{
        firstRelasi(P) = next(Q);
        prev(firstRelasi(P)) = NULL;
        next(Q) = NULL;
    }
}
void deleteLastRelasi(adrGrup &P){
    adrRelasi Q, R;

    Q = firstRelasi(P);
    while (next(Q) != NULL){
        Q = next(Q);
    }
    R = prev(Q);
    prev(Q) = NULL;
    next(R) = NULL;
}
void deleteAfterRelasi(adrGrup &P, adrRelasi &Q){
    adrRelasi Prec = prev(Q);
    next(Prec) = next(Q);
    prev(next(Q)) = Prec;
    prev(Q) = NULL;
    next(Q) = NULL;
}
void deleteFirstGrup(Grup &G, User &U){
    adrRelasi P;
    adrGrup J;

    P = firstRelasi(first(G));
    while (P != NULL){
        info(relasi(P)).jum_grup--;
        P = next(P);
    }
    J = first(G);
    if (next(J) == NULL){
        first(G) = NULL;
    }else{
        first(G) = next(J);
        prev(first(G)) = NULL;
        next(J) = NULL;
    }
}
void deleteLastGrup(Grup &G, User &U){
    adrRelasi P;
    adrGrup J;

    J = last(G);
    P = firstRelasi(J);
    while (P != NULL){
        info(relasi(P)).jum_grup--;
        P = next(P);
    }
    last(G) = prev(J);
    next(last(G)) = NULL;
    prev(J) = NULL;
}
void deleteAfterGrup(Grup &G, User &U, string nama){
    adrGrup prec, P;
    adrRelasi R;

    P = searchingGrup(G, nama);
    if (P == NULL){
        cout << "Tidak ada grup dengan nama itu" << endl;
    }else{
        R = firstRelasi(P);
        while (R != NULL){
            info(relasi(R)).jum_grup--;
            R = next(R);
        }
        prec = prev(P);
        next(prec) = next(P);
        prev(next(P)) = prec;
        prev(P) = NULL;
        next(P) = NULL;
    }
}
void kickUserAll(Grup &G, User U, string nama){
    adrRelasi P;
    adrGrup a;
    adrUser n;

    a = first(G);
    n = searchingUser(U, nama);
    if (n == NULL){
        cout << "Tidak ada user dengan nama itu" << endl;
    }else{
        while (a != NULL){
            P = searchingRelasi(a,nama);
            if (P != NULL){
                if (P == firstRelasi(a)){
                    deleteFirstRelasi(a);
                }else {
                    if (next(P) == NULL){
                        deleteLastRelasi(a);
                    }else {
                        deleteAfterRelasi(a,P);
                    }
                }
                info(relasi(P)).jum_grup--;
            }else {
                a = next(a);
            }
        }
    }
}
void kickUser(Grup &G, User &U, string nama, string grup){
    adrRelasi P;
    adrGrup a;
    adrUser n;

    a = searchingGrup(G, grup);
    n = searchingUser(U, nama);

    if (a == NULL || n == NULL){
        cout << "Data tidak ada" << endl;
    }else{
        P = searchingRelasi(a, nama);
        if (P != NULL){
            if (P == firstRelasi(a)){
                deleteFirstRelasi(a);
            }else {
                if (next(P) == NULL){
                    deleteLastRelasi(a);
                }else {
                    deleteAfterRelasi(a,P);
                }
            }
            info(relasi(P)).jum_grup--;
        }
    }
}
void deleteGrup(Grup &G, User &U, string nama){
    adrGrup P;

    P = searchingGrup(G, nama);
    if (P == NULL){
        cout << "Tidak ada grup dengan nama itu" << endl;
    }else{
        if (P == first(G)){
            deleteFirstGrup(G, U);
        }else if (P == last(G)){
            deleteLastGrup(G, U);
        }else{
            deleteAfterGrup(G, U, nama);
        }
    }
}
void deleteUser(User &U, string nama){
    adrUser P;

    P = searchingUser(U, nama);
    if (P == NULL){
        cout << "Tidak ada user dengan nama itu" << endl;
    }else{
        if (first(U) == P){
            deleteFirstUser(U);
        }else if (last(U) == P){
            deleteLastUser(U);
        }else{
            deleteAfterUser(U, nama);
        }
    }
}
void deleteTotalUser(User &U, Grup &G, string nama){
    kickUserAll(G, U, nama);
    deleteUser(U, nama);
}
void inviteUser(Grup &G, User U, string namaGrup, string namaUser){
    adrGrup P = searchingGrup(G,namaGrup);
    adrUser Q = searchingUser(U,namaUser);
    if ((P != NULL) && (Q != NULL)){
        info(Q).jum_grup++;
        info(P).jum_user++;
        adrRelasi R = alokasiRelasi(Q);
        insertLastRelasi(P,R);
    }else {
        if (Q == NULL){
        cout<<"user tidak ditemukan"<<endl;
        }else {
            if (P == NULL){
                cout<<"grup tidak ditemukan"<<endl;
            }
        }
    }
}
void showAll(Grup G){
    adrGrup P = first(G);
    int i = 1;
    while (P != NULL){
        cout<<"grup "<<i<<" : "<<info(P).nama_grup<<"\n";
        adrRelasi Q = firstRelasi(P);
        int y = 1;
        while (Q != NULL){
            cout<<"anggota "<<y<<" : "<<info(relasi(Q)).nama_user<<"\n";
            Q = next(Q);
            y++;
        }
        P = next(P);
        i++;
    }
}
void showGrupPopuler(Grup G){
    adrGrup Q = first(G);
    adrGrup P = next(first(G));
    bool hasil = true;
    if (Q != NULL){
        int populer = info(Q).jum_user;
            while(P != NULL){
                if (populer != info(P).jum_user){
                    if (populer < info(P).jum_user){
                        populer = info(P).jum_user;
                        Q = P;
                    }
                hasil = false;
                }
                P = next(P);
            }
        if (hasil){
            cout<<"==> jumlah anggota dari semua grup sama, yaitu "<<populer<<" anggota"<<endl;
        } else {
            cout<<"==> grup terpopuler adalah : "<<info(Q).nama_grup<<" dengan "<<info(Q).jum_user<<" anggota "<<endl;
        }
    }
}
void cariGrupdariUser(Grup G, string namaUser){
    adrGrup P = first(G);
    bool found = false;
    while (P != NULL){
        adrRelasi i = searchingRelasi(P,namaUser);
        if(i != NULL){
            cout<<"user berada di grup- "<<info(P).nama_grup<<endl;
            found = true;
        }
        P = next(P);
    }
    if (found == false){
        cout<<"user tidak ditemukan atau tidak berada di grup manapun \nCOBA PERHATIKAN HURUS KAPITALNYA!!"<<endl;
    }
}
void userDi3Grup(User U, Grup G){
    adrUser P = first(U);
    int i = 0;
    while(P != NULL){
        if (info(P).jum_grup >= 3){
            cout<<"==> "<<info(P).nama_user<<" di grup :"<<endl;
            adrGrup Q = first(G);
            i++;
            while (Q != NULL){
            adrRelasi i = searchingRelasi(Q,info(P).nama_user);
                if (i != NULL){
                    cout<<"GRUP : "<<info(Q).nama_grup<<endl;
                }
            Q = next(Q);
            }
        }
        P = next(P);
    }
    if (i == 0){
        cout<<"==> tidak ada user yang berada di 3 grup berbeda"<<endl;
    }
}
void showDataUser(User U, string nama){
    adrUser P = searchingUser(U,nama);
    if (P != NULL){
        cout<<"DATA USER : "<<endl;
        cout<<"nama : "<<info(P).nama_user<<endl;
        cout<<"nomor telepon : "<<info(P).telepon<<endl;
        cout<<"email : "<<info(P).email<<endl;
        cout<<"password : "<<info(P).password<<endl;
        cout<<"user berada di "<<info(P).jum_grup<<" grup berbeda"<<endl;
    }else {
        cout<<"user tidak ada, \nPERHATIKAN : penulisan huruf harus dengan kapital"<<endl;
    }
}
void menu_main(User U, Grup G){
    int a;
    cout<<"\n----------------------------------------------SELAMAT DATANG DI TUBES KAMI----------------------------------------------\n"<<endl;
    cout<<"oleh : \nAzriel Naufal Aulia (1301190374) \nAdhie Rachmatulloh Sugiono(1301194509)\n"<<endl;
    cout<<"pilih menu :"<<endl;
    cout<<"1. invite user \n2. buat user atau grup \n3. show \n4. delete grup / delete user / kick user \n5. keluar program"<<endl;
    cout<<"PENGATURAN : PILIH MENU HARUS DENGAN ANGKA"<<endl;
    cout<<"menu ke : ";cin>>a;
    if (a == 1){
        menu_invite(U,G);
    }else {
        if (a == 2){
            buatUser_Grup(U,G);
        }else {
            if (a == 3){
                menu_show(U,G);
            }else {
                if (a == 4){
                    menu_delete(U,G);
                }else {
                    if (a == 5){
                        cout<<"TERIMA KASIH SUDAH MENGGUNAKAN TUBER KAMI, SELAMAT JUMPA LAGI"<<endl;
                    }else {
                        cout<<"menu tidak tersedia, tolong input lagi!!!!"<<endl;
                        menu_main(U,G);
                    }
                }
            }
        }
    }
}
void menu_invite(User U, Grup G){
    string nama_user;
    string nama_grup;
    cout<<"\n----------------------------------------------INVITE USER KE DALAM GRUP----------------------------------------------\n"<<endl;
    cout<<"peraturan : \nA. INVITE BERHASIL, JIKA DAN HANYA JIKA MENULIS DENGAN NAMA DAN GRUP DENGAN LENGKAP DAN HURUF KAPITAL. \nB. INVITE TIDAK BERHASIL JIKA MENGGUNAKAN ANGKA URUTAN"<<endl;
    cout<<endl;
    adrUser P = first(U);
    int i = 1;
    while (P != NULL){
        cout<<i<<". "<<info(P).nama_user<<endl;
        P = next(P);
        i++;
    }
    cout<<"invite siapa :";cin>>nama_user;
    adrUser a = searchingUser(U,nama_user);
    if (a == NULL){
        cout<<"user tidak ditemukan, tolong input lagi, \nPerhatikan : penulisan huruf harus kapital"<<endl;
        menu_invite(U,G);
    }
    cout<<endl;
    adrGrup Q = first(G);
    int y = 1;
    while (Q != NULL){
        cout<<y<<". "<<info(Q).nama_grup<<endl;
        Q = next(Q);
        y++;
    }
    cout<<"ke grup apa :";cin>>nama_grup;
    adrGrup b = searchingGrup(G,nama_grup);
    if (b == NULL){
        cout<<"grup tidak ditemukan, tolong input lagi, \nPerhatikan : penulisan huruf harus kapital"<<endl;
        menu_invite(U,G);
    }
    inviteUser(G,U,nama_grup,nama_user);
    menu_main(U,G);
}
void buatUser_Grup(User U, Grup G){
    int a;
    cout<<"\n----------------------------------------------BUAT USER DAN GRUP----------------------------------------------\n"<<endl;
    cout<<"1.buat user \n2.buat grup \n3.kembali ke manu utama"<<endl;
    cout<<"manu ke : ";cin>>a;
    if (a == 1){
        string nama;
        string telepon;
        string email;
        string pass;
        adrUser P;
        cout<<"nama : ";cin>>nama;
        cout<<"telepon : ";cin>>telepon;
        cout<<"email : ";cin>>email;
        cout<<"password : ";cin>>pass;
        P = alokasiUser(nama,telepon,email,pass);
        insertLastUser(U,P);
        menu_main(U,G);
    }else {
        if (a == 2){
            string nama1;
            adrGrup Q;
            cout<<"nama grup :";cin>>nama1;
            Q = alokasiGrup(nama1);
            insertLastGrup(G,Q);
            menu_main(U,G);
        }else {
            if(a == 3){
                menu_main(U,G);
            }else {
                cout<<"menu tidak tersedia, tolong input lagi !!!"<<endl;
                buatUser_Grup(U,G);
            }
        }
    }
}
void menu_show(User U, Grup G){
    int a;
    cout<<"\n----------------------------------------------SHOW DATA & LIST----------------------------------------------\n"<<endl;
    cout<<"1. lihat daftar grup dan user \n2. siapa grup populer? \n3. cari user? \n4. list user yang di dalam 3 grup berbeda \n5. liat data user, siapa?? \n6. kembali ke menu utama"<<endl;
    cout<<"menu ke- ";cin>>a;
    if (a == 1){
        cout<<endl;
        if (first(G) != NULL){
            showAll(G);
        }else {
            cout<<"==> tidak ada grup yang tersedia"<<endl;
        }
        cout<<endl;
        menu_show(U,G);
    }else {
        if(a == 2){
            cout<<endl;
            if (first(G) != NULL){
                showGrupPopuler(G);
            }else {
                cout<<"==> tidak ada grup yang tersedia sehingga tidak ada grup populer"<<endl;
            }
            cout<<endl;
            menu_show(U,G);
        }else{
            if (a == 3){
                string x;
                cout<<"\nPENGATURAN : \nA. NAMA HARUS DENGAN HURUF KAPITAL\n"<<endl;
                cout<<"ingin mencari siapa? ";cin>>x;
                cariGrupdariUser(G,x);
                cout<<endl;
                menu_show(U,G);
            }else {
                if (a == 4){
                    cout<<endl;
                    if (first(G) != NULL){
                        cout<<"User yang berada di 3 grup yang berbeda adalah:"<<endl;
                        userDi3Grup(U,G);
                        cout<<endl;
                    }else{
                        cout << "Tidak ada user yang berada di 3 grup yang berbeda" << endl;
                    }
                    menu_show(U,G);
                }else {
                    if (a == 5){
                        string nama;
                        cout<<"PENGATURAN : PENULISAN NAMA HARUS DENGAN HURUF KAPITAL"<<endl;
                        cout<<"nama? ";cin>>nama;
                        showDataUser(U,nama);
                        menu_show(U,G);
                    }else {
                        if (a == 6){
                            menu_main(U,G);
                        }else {
                            cout<<"Menu tidak tersedia, tolong input lagi"<<endl;
                            menu_show(U,G);
                        }
                    }
                }
            }
        }
    }
}
void menu_delete(User &U, Grup &G){
    int a;
    string namaUser, namaGrup;
    cout<<"\n----------------------------------------------MENGHAPUS DATA----------------------------------------------\n"<<endl;
    cout<<"1. delete data user \n2. delete data grup \n3. kick user \n4. balik ke menu utama"<<endl;
    cout<<"menu ke- ";cin>>a;
    if (a == 1){
        adrUser P = first(U);
        int i = 1;
        while (P != NULL){
            cout<<i<<". "<<info(P).nama_user<<endl;
            P = next(P);
            i++;
        }
        cout << "Masukkan nama user yang ingin dihapus: ";
        cin >> namaUser;
        deleteTotalUser(U, G, namaUser);
        showAll(G);
        menu_main(U, G);
    }else{
        if (a == 2){
            adrGrup Q = first(G);
            int y = 1;
            while (Q != NULL){
            cout<<y<<". "<<info(Q).nama_grup<<endl;
            Q = next(Q);
            y++;
            }
            cout << "Masukkan nama grup yang ingin dihapus: ";
            cin >> namaGrup;
            deleteGrup(G, U, namaGrup);
            cout << "Grup berhasil dihapus" << endl;
            showAll(G);
            menu_main(U, G);
        }else {
            if(a == 3){
                showAll(G);
                cout << "Masukkan nama user yang ingin dikick: ";
                cin >> namaUser;
                cout << endl;
                cout << namaUser << " ingin dikeluarkan dari grup: ";
                cin >> namaGrup;
                kickUser(G, U, namaUser, namaGrup);
                showAll(G);
                menu_main(U, G);
            }else {
                if (a == 4){
                    menu_main(U,G);
                }else {
                    cout<<"menu tidak tersedia, tolong input lagi !!"<<endl;
                    menu_delete(U,G);
                }
            }
        }
    }
}
//untuk menu login dibawah bisa dipakai saat di awal-awal program.
//jika menu login dipakai, user harus sign in terlebih dahulu di awal.
//user harus memasukkan email dan password yang sudah terdaftar atau sudah terbuat didalam program.
void menu_login(User U, Grup G){
    int a;
    cout<<"\n----------------------------------------------MENU SIGN IN----------------------------------------------\n"<<endl;
    cout<<"pilih menu :"<<endl;
    cout<<"1. Sign In \n2. Sign Out "<<endl;
    cout<<"menu ke - ";cin>>a;cout<<endl;
    string emailU;
    string passU;
    if (a == 1){
        cout<<"email : ";cin>>emailU;
        cout<<"password : ";cin>>passU;
        adrUser P = searchingEmail(U,emailU);
        adrUser Q = searchingPass(U,passU);
        if ((P != NULL) && (Q != NULL)){
            cout<<"LOGIN BERHASIL !!!"<<endl;
            menu_main(U,G);
        }else{
            if ((P == NULL) && (Q == NULL)){
                cout<<"EMAIL DAN PASSWORD TIDAK TERDAFTAR!!!"<<endl;
            }else {
                if (P == NULL){
                    cout<<"EMAIL TIDAK TERDAFTAR!!!"<<endl;
                }else {
                    cout<<"PASSWORD SALAH!!!"<<endl;
                }
            }
            menu_login(U,G);
        }
    }else {
        if(a == 2){
            cout<<"TERIMA KASIH MENGGUNAKAN TUBES KAMI, SAMPAI JUMPA LAGI!!"<<endl;
        }
    }
}
adrUser searchingEmail(User U, string email){
    adrUser P = first(U);
    bool found = false;
    while ((P != NULL) && !(found)){
        if (info(P).email == email){
            found  = true;
        }else {
            P = next(P);
        }
    }
    if (found){
        return P;
    }else {
        return NULL;
    }
}
adrUser searchingPass(User U, string pass){
    adrUser P = first(U);
    bool found = false;
    while ((P != NULL) && !(found)){
        if (info(P).password == pass){
            found  = true;
        }else {
            P = next(P);
        }
    }
    if (found){
        return P;
    }else {
        return NULL;
    }
}

