#include <iostream>
#include "bismillah.h"

using namespace std;

int main()
{
    User U;
    Grup G;
    createGrup(G);
    createUser(U);
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    adrUser A = alokasiUser("AZRIEL","0000","azrielnaufal@gmail.com","azriel123");
    adrUser B = alokasiUser("ADHIE","1111","adhie@gmail.com","adhie123");
    adrUser C = alokasiUser("BANGTIKO","2222","bangtiko@gmail.com","tiko123");
    adrUser D = alokasiUser("HANAFI","3333","hanafi@gmail.com","mas123");
    adrUser E = alokasiUser("AFA","4444","afa@gmail.com","afa123");
    adrUser F = alokasiUser("AFRYAN","5555","afryan@gmail.com","afryan123");
    adrUser Ga = alokasiUser("FIONA","6666","agung@gmail.com","fiona123");
    adrUser H = alokasiUser("ALDI","7777","aldi@gmail.com","aldi123");
    adrUser I = alokasiUser("BIMA","8888","bima@gmail.com","bima123");
    adrUser J = alokasiUser("DIKA","9999","dika@gmail.com","dika123");
    adrUser K = alokasiUser("DITA","0000","dita@gmail.com","dita123");
    adrUser L = alokasiUser("ZAKIA","1010","zakia@gmail.com","zakia123");
    adrUser M = alokasiUser("FAIZ","1212","faiz@gmail.com","faiz123");
    adrUser N = alokasiUser("KHOIRU","1313","khoiru@gmail.com","khoiru123");
    adrUser O = alokasiUser("RYAN","1414","ryan@gmail.com","ryan123");
    adrUser P = alokasiUser("INDRA","1515","indra@gmail.com","indra123");
    adrUser Q = alokasiUser("ANDRA","1616","andra@gmail.com","andra123");
    adrUser R = alokasiUser("BU_HANI","1717","buHani@gmail.com","buHani123");
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    adrGrup a = alokasiGrup("IF4310");
    adrGrup b = alokasiGrup("UKMFORCI");
    adrGrup c = alokasiGrup("HIPMI");
    adrGrup d = alokasiGrup("LAB-IF");
    adrGrup e = alokasiGrup("AL-FATH");
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    insertLastUser(U,A);
    insertLastUser(U,B);
    insertLastUser(U,C);
    insertLastUser(U,D);
    insertLastUser(U,E);
    insertLastUser(U,F);
    insertLastUser(U,Ga);
    insertLastUser(U,H);
    insertLastUser(U,I);
    insertLastUser(U,J);
    insertLastUser(U,K);
    insertLastUser(U,L);
    insertLastUser(U,M);
    insertLastUser(U,N);
    insertLastUser(U,O);
    insertLastUser(U,P);
    insertLastUser(U,Q);
    insertLastUser(U,R);
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    insertLastGrup(G,a);
    insertLastGrup(G,b);
    insertLastGrup(G,c);
    insertLastGrup(G,d);
    insertLastGrup(G,e);
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    inviteUser(G,U,"IF4310","AZRIEL");
    inviteUser(G,U,"IF4310","ADHIE");
    inviteUser(G,U,"IF4310","BANGTIKO");
    inviteUser(G,U,"IF4310","HANAFI");
    inviteUser(G,U,"IF4310","ZAKIA");
    inviteUser(G,U,"IF4310","FAIZ");
    inviteUser(G,U,"IF4310","ANDRA");
    inviteUser(G,U,"IF4310","RYAN");
    inviteUser(G,U,"IF4310","INDRA");
    inviteUser(G,U,"IF4310","KHOIRU");
    inviteUser(G,U,"IF4310","FIONA");
    inviteUser(G,U,"IF4310","DIKA");
    inviteUser(G,U,"IF4310","BU_HANI");
    inviteUser(G,U,"HIPMI","ANDRA");
    inviteUser(G,U,"HIPMI","AZRIEL");
    inviteUser(G,U,"HIPMI","KHOIRU");
    inviteUser(G,U,"LAB-IF","RYAN");
    inviteUser(G,U,"LAB-IF","FAIZ");
    inviteUser(G,U,"LAB-IF","INDRA");
    inviteUser(G,U,"LAB-IF","AFRYAN");
    inviteUser(G,U,"LAB-IF","AZRIEL");
    inviteUser(G,U,"UKMFORCI","ADHIE");
    inviteUser(G,U,"UKMFORCI","ZAKIA");
    inviteUser(G,U,"UKMFORCI","FAIZ");
    inviteUser(G,U,"AL-FATH","FIONA");
    inviteUser(G,U,"AL-FATH","DIKA");
    inviteUser(G,U,"AL-FATH","FAIZ");
    //////////////////////////////////////////////////////////////////
    //spasi enter di gunakan hanya supaya tampilan terlihat rapih saat memulai program
    cout<<"\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n"<<endl;
    ///////////////////////////////////////////////////////////////////

    //menu_login(U,G);
    menu_main(U,G);
    return 0;
}
