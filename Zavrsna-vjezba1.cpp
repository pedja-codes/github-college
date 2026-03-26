/*Na početku programa (izvan svih potprograma) kreirajte strukturu (struct) sa sljedećim podatcima:
ime (char ili string) i ocjena (int).
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
vrijednosti imena i ocjene. Prilikom unosa ocjene napravite provjeru je li ocjena u rasponu od 1 do 5.
Ako ocjena nije u zadanom rasponu, tražite ponovni unos sve dok korisnik ne unese vrijednost u zadanom
rasponu.
2. zadatak – kreirajte potprogram koji radi sljedeće:
Implementirajte mogućnost ispisa svih upisanih elemenata u polje struktura. Nakon ispisa svih elemenata
ispišite i zbroj ocjena svih elemenata u polju.
3. zadatak:
Dinamički alocirajte polje od 10 elemenata cjelobrojnog tipa. U polje generirajte nasumične brojeve u
rasponu od 30 do 70. Napravite ispis svih elemenata polja. Dealocirajte dinamički kreirano polje.
4. zadatak:
Omogućite korisniku unos jedne cjelobrojne vrijednosti u varijablu. Kreirajte potprogram gdje će se
unesena vrijednost proslijediti potprogramu koji kao povratnu vrijednost treba vratiti apsolutnu
vrijednost ulazne vrijednosti. Povratnu vrijednost ispišite na ekran.*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

//using namespace std;

struct ucenici{

    std::string ime;
    int ocijena;
}polje[50];

int apsolutna(int a){
    int aps;

    if(a<0)
    aps=a*-1;
    else
    aps=a;

    return aps;
}

int main(){

srand(time(0));

int izbor,brojac;

do{
std::cout<<"IZBORNIK Odabir (1-4 ili 9):"<<std::endl;
std::cout<<"1. Unos elementa u polje"<<std::endl;
std::cout<<"2. Ispis svih elemenata iz polja"<<std::endl;
std::cout<<"3. Dinamička alokacija"<<std::endl;
std::cout<<"4. Potprogram s povratnom vrijednosti"<<std::endl;
std::cout<<"9. Izlaz iz programa"<<std::endl;
std::cin>>izbor;

switch(izbor){


    case 1:{

    int n;
    std::cout<<"Maximalni unos je 50,koliko unosa želite napravit? "<<std::endl;

    do{
    std::cin>>n;

    if(n<1 || n>50)
    std::cout<<"Pogrešan unos!"<<std::endl;
    brojac=n;
    }while(n<1 || n>50);

    std::cin.ignore(10000, '\n');
   
    
    for(int i=0;i<n;i++){
    std::cout<<"Unesite ime ucenika: \n";
    getline(std::cin,polje[i].ime);
    
    do{
    std::cout<<"Unesite ocijenu(1-5): \n";
    std::cin>>polje[i].ocijena;
    if(polje[i].ocijena<1 || polje[i].ocijena>5)
       std::cout<<"Pogresan unos! \n";

    }while(polje[i].ocijena<1 || polje[i].ocijena>5);

      }//for
       
    break;
}//case 1

    case 2:{

    int m,suma=0;

    std::cout<<"Maximalni ispis je 50,koliko stavki zelite ispisati? "<<std::endl;

    do{
    std::cin>>m;

    if(m<1 || m>50)
    std::cout<<"Pogrešan unos!"<<std::endl;

    }while(m<1 || m>50);

    std::cin.ignore(10000, '\n');

    for(int i=0;i<m;i++){
        std::cout<<i+1<<". ucenik: ";
        std::cout<<"Ime: "<<polje[i].ime<<" ima ocijenu: "<<polje[i].ocijena<<". "<<std::endl;
        suma+=polje[i].ocijena;
    }
    double prosijek=(double)suma/(double)brojac;
    std::cout<<"Ukupan prosjek ocijena: "<<prosijek<<std::endl;

    break;//case 2
   
}//case 2
    
    case 3:{

        int *polje2=new int[10];

        for(int i=0;i<10;i++)
        polje2[i]=rand()%41+30;


        std::cout<<"Ispis generiranih brojeva u polju u razmaku od 30 do 70: "<<std::endl;
        for(int i=0;i<10;i++)
        std::cout<<polje2[i]<<" ";
        std::cout<<std::endl;

        delete[] polje2;

        break;

    }//case 3

    case 4:{

          int apov;

          std::cout<<"Unesite cijeli broj: \n";
          std::cin>>apov;

          std::cout<<"Apsolutna vrijednost unesenog broja je: "<<apsolutna(apov)<<std::endl;
          std::cout<<std::endl;

          break;

    }

    default:
           if(izbor!=9)
           std::cout<<"Pogrešan unos!"<<std::endl;

}//switch
}while(izbor!=9);
    return 0;
}//main