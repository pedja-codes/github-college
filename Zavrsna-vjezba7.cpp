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
#include <cstdlib>
#include <ctime>

//using namespace std

struct logic{

    bool var1,var2;

}polje[50];

int povrat(int a,int b){

 int rng=rand()% (b-a+1)+a;

 return rng;

}

int main(){

    srand(time(0));

    int izbor,istina=0,laz=0,brojac=0;
    char nastavak;
    
    izlaz:   //you never goto but sometimes you have to
    do{
    std::cout<<"IZBORNIK - Odabir (1-4 ili 9):"<<std::endl;
    std::cout<<"1. Unos elemenata u polje "<<std::endl;
    std::cout<<"2. Ispis svih elemenata iz polja "<<std::endl;
    std::cout<<"3. Dinamička alokacija "<<std::endl;
    std::cout<<"4. Potprogram s povratnom vrijednosti "<<std::endl;
    std::cout<<"9. Izlaz iz programa "<<std::endl;
    std::cin>>izbor;

    switch(izbor){

        case 1:{
       

        std::cout<<"Unesite dvije logicke varijable: \n";
        for(int i=0;i<50;i++){
            
             int a,b;

        do{
           
           std::cout<<"Unos "<<i+1<<": "<<std::endl;
           std::cin>>a>>b;
           
           polje[i].var1=a;
           polje[i].var2=b;
           brojac++;
           if( (a != 0 && a != 1) || (b != 0 && b != 1) )
           std::cout<<"Pogrešan unos.Ponovite: "<<std::endl;
           else{
           std::cout<<"Nastavit(Y/N)? "<<std::endl;
           std::cin>>nastavak;
           if(nastavak=='Y'||nastavak=='y')
           continue;
           else
           goto izlaz;
           }
           
        } while( (a != 0 && a != 1) || (b!= 0 && b != 1) ); 
        }//for     
        break;//case 1
        }
        case 2:
        
        std::cout<<std::endl;
        std::cout<<"Ispis unesenih vrijednost: \n";
        for(int i=0;i<brojac;i++){
            std::cout<<i+1<<". unesene vrijednosti: "<<polje[i].var1<<" i "<<polje[i].var2<<std::endl;
            if(polje[i].var1==1)
               istina++;
            if(polje[i].var1==0) 
                laz++;
            if(polje[i].var2==1)
               istina++;
            if(polje[i].var2==0)
               laz++;
            
            std::cout<<"Ukupan broj unesenih 1(istina): "<<istina<<". "<<std::endl;
            std::cout<<"Ukupan broj unesenih 0(laz): "<<laz<<". "<<std::endl;
            std::cout<<std::endl;
        }
        break;//case 2

        case 3:{

        int* a= new int;
        
        do{
        std::cout<<"Unesite dvoznamenkasti broj: \n";
        std::cin>>*a;
        if(*a<10 || *a>99)
        std::cout<<"Pogrešan unos,ponovite: \n";
        }while(!(*a >= 10 && *a <= 99));

        if(*a%2==0)
        std::cout<<"Broj je dijeljiv sa 2 ."<<std::endl;
         if(*a%3==0)
        std::cout<<"Broj je dijeljiv sa 3 ."<<std::endl;
         if(*a%5==0)
        std::cout<<"Broj je dijeljiv sa 5 ."<<std::endl;

        delete a;

        break;//case 3
        }
        case 4:{

        int c,d;

        std::cout<<"Unesite nizu cijelobrojnu vrijednost: \n";
        std::cin>>c;
        std::cout<<"Unesite višu cijelobrojnu vrijednost: \n";
        std::cin>>d;

        std::cout<<"Nasumicni broj između "<<c<<" i "<<d<<": "<<povrat(c,d);
        std::cout<<std::endl;
        break;//case 4
        }
        default:
              std::cout<<"Pogrešan unos!"<<std::endl;
    }//switch

    }while(izbor!=9) ;  


return 0;
    }//main
