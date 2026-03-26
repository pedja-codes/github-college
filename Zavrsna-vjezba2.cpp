/*Na početku programa (izvan svih potprograma) kreirajte strukturu (struct) sa sljedećim podatcima:
stranica a (int), stranica b (int), površina (int) i opseg (int) pravokutnika.
Također, kreirajte globalno polje elemenata kreirane strukture od 50 elemenata.
IZBORNIK
1. Unos elementa u polje
2. Ispis svih elemenata iz polja
3. Dinamička alokacija
4. Potprogram s povratnom vrijednosti
9. Izlaz iz programa
Odabir (1-4 ili 9):
1. zadatak – kreirajte potprogram koji radi sljedeće:
Implementirajte mogućnost unosa novog elementa u kreirano polje zadane strukture. Korisnik unosi
vrijednosti stranica a i b dok je površinu i opseg pravokutnika potrebno izračunati na temelju unesenih
vrijednosti stranica. Izračunati podatci površine i opsega se upisuju u element polja.
2. zadatak – kreirajte potprogram koji radi sljedeće:
Implementirajte mogućnost ispisa svih upisanih elemenata u polje struktura. Nakon ispisa svih elemenata
ispišite i broj upisanih elemenata u polju.
3. zadatak:
Dinamički alocirajte cjelobrojnu varijablu. Omogućite korisniku unos cjelobrojne vrijednosti i tražite
unos troznamenkastog broja. Ako korisnik ne unese troznamenkasti broj, tražite ponovni upis broja sve
dok upisani broj ne bude u zadanom rasponu. Ispišite zbroj znamenki upisanog troznamenkastog broja.
Dealocirajte kreiranu dinamičku varijablu.
4. zadatak:
Omogućite korisniku unos dvije cjelobrojne vrijednosti u varijable. Kreirajte potprogram gdje će se
unesene vrijednosti proslijediti potprogramu koji kao povratnu vrijednost treba vratiti veći od dva
proslijeđena broja. Povratnu vrijednost ispišite na ekran*/

#include <iostream>

//using namespace std;

struct prvkt {

    int a,b,P,O;

}polje[50];

int povrat (int a,int b){

    int c=0;

    if(a>b)
    c=a;
    else 
    c=b;

    return c;
}

int main(){

    int izbor,unos,unos2,brojac=0;

do{
std::cout<<"IZBORNIK Odabir (1-4 ili 9): "<<std::endl;
std::cout<<"1. Unos elementa u polje"<<std::endl;
std::cout<<"2. Ispis svih elemenata iz polja"<<std::endl;
std::cout<<"3. Dinamička alokacija"<<std::endl;
std::cout<<"4. Potprogram s povratnom vrijednosti"<<std::endl;
std::cout<<"9. Izlaz iz programa"<<std::endl;
std::cin>>izbor;

switch(izbor){

case 1:

std::cout<<"Koliko pravokutnika unosite? \n";
std::cin>>unos;
std::cout<<"Unesite stranice pravokutnik a i b: \n";

for(int i=0;i<unos;i++){
    std::cout<<"Unesite stranicu a za "<<i+1<<". pravokutnik: ";
    std::cin>>polje[i].a;
    std::cout<<"Unesite stranicu b za "<<i+1<<". pravokutnik: ";
    std::cin>>polje[i].b;

    polje[i].P=polje[i].a*polje[i].b;
    polje[i].O=2*(polje[i].a+polje[i].b);
    brojac++;
}//for
break;
case 2:

std::cout<<"Koliko elemenata zelite ispisat? \n";
std::cin>>unos2;

for(int i=0;i<unos2;i++){
std::cout<<"Za uneseni pravokutnik "<<i+1<<" sa stranicama: "<<polje[i].a<<" i "<<polje[i].b<<": "<<std::endl;
std::cout<<"Površina je: "<<polje[i].P<<". "<<std::endl;
std::cout<<"Opseg je: "<<polje[i].O<<". "<<std::endl;
}

std::cout<<"Ukupan broj unesenih elemenata u polju: "<<brojac<<". "<<std::endl;
break;
case 3:{

    int *var=new int;

    std::cout<<"Unesite troznamenkasti broj: \n";
    do{
    std::cin>>*var;

    if(*var<100 || *var>999)
    std::cout<<"Pogresan unos!"<<std::endl;


    }while(*var<100 || *var>999);

   
    int varj=(*var%10);
    //std::cout<<varj<<std::endl;
    int vard=(*var/10)%10;
    //std::cout<<vard<<std::endl;
    int vars=*var/100;
    //std::cout<<vars<<std::endl;

    std::cout<<"Zbroj znamenki unesenog broja: "<<varj+vard+vars<<". "<<std::endl;

    delete var;
break;
}//case3

case 4:{

    int var4a,var4b;

    std::cout<<"Unesite dvije cijelobrijne vrijednosti: \n";
    std::cin>>var4a>>var4b;

    std::cout<<"Veci broj je: "<<povrat(var4a,var4b)<<". "<<std::endl;
break;
}

default:
if(izbor!=9)
std::cout<<"Pogrešan odabir!"<<std::endl;

}// switch
}while(izbor!=9);

    return 0;
}