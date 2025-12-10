/*Na početku programa (izvan svih potprograma) kreirajte strukturu (struct) sa sljedećim podatcima:
dvije logičke vrijednosti (bool).
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
vrijednosti obje logičke vrijednosti. Tražite od korisnika da unese vrijednost 0 ili 1. Ako korisnik ne
unese u pojedinu varijablu traženu vrijednost, tražite ponovni unos u tu varijablu sve dok korisnik ne
unese vrijednost u zadanom rasponu.
2. zadatak – kreirajte potprogram koji radi sljedeće:
Implementirajte mogućnost ispisa svih upisanih elemenata u polje struktura. Prebrojite i na kraju, nakon
ispisa svih elemenata polja, ispišite koliko je ukupno u polju upisano nula a koliko jedinica.
3. zadatak:
Dinamički alocirajte cjelobrojnu varijablu i omogućite korisniku unos vrijednosti u tu varijablu. Zatražite
unos dvoznamenkastog broja. Ako korisnik ne unese traženu vrijednost, ponavljajte unos u varijablu dok
korisnik ne unese vrijednost u traženom rasponu. Nakon uspješnog unosa ispišite je li uneseni broj djeljiv
s 2, 3 ili 5 (za svaki broj posebno). Dealocirajte kreiranu dinamičku varijablu.
4. zadatak:
Omogućite korisniku unos dvije cjelobrojne vrijednosti u varijable. Kreirajte potprogram kojemu će se
proslijediti upisane vrijednost a potprogram treba vratiti nasumični broj u rasponu od prve upisane
vrijednosti do druge upisane vrijednosti. Pretpostavka je da će korisnik upisati prvo manju a onda veću
vrijednost. Povratnu vrijednost ispišite na ekran.*/


#include <iostream>


//using namespace std

struct logic{

    bool var1,var2;

}polje[50];

int main(){

    int izbor;
    char nastavak;

    std::cout<<"IZBORNIK"<<std::endl;
    std::cout<<"1. Unos elemenata u polje "<<std::endl;
    std::cout<<"2. Ispis svih elemenata iz polja "<<std::endl;
    std::cout<<"3. Dinamička alokacija "<<std::endl;
    std::cout<<"4. Potprogram s povratnom vrijednosti "<<std::endl;
    std::cout<<"9. Izlaz iz programa "<<std::endl;
    std::cout<<"   Odabir (1-4 ili 9): "<<std::endl;
    std::cin>>izbor;

    switch(izbor){

        case 1:
       

        std::cout<<"Unesite dvije logicke varijable(za izlaz unesite 9): \n";
        for(int i=0;i<50;i++){

           int a=polje[i].var1;  //zbog problema kod usporedbe bool varijabli treba unose privremeno pretvorit u cijelobrojne tipove;
           int b=polje[i].var2;

        do{

           std::cout<<"Unos "<<i+1<<": "<<std::endl;
           std::cin>>a>>b;

           if( (a != 0 && a != 1) || (b != 0 && b != 1) )
           std::cout<<"Pogrešan unos.Ponovite: "<<std::endl;
          
        } while( (a != 0 && a != 1) || (b != 0 && b != 1) );
            
        }//for     
        break;//case 1
        default:
              std::cout<<"Pogrešan unos!"<<std::endl;
    }//switch
       


return 0;
    }//main
