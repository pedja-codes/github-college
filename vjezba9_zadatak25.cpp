/*Kreirajte polje od 10 elemenata za unos podataka o krugovima.
Kreirajte i strukturu u koju ćete zapisati naziv (string), radijus (float), opseg (float) i površinu (float) kruga.

U izborniku omogućite sljedeće opcije:
4. Unos novog kruga u polje krugova (unose se naziv i radijus, izračunavaju se opseg i površina)
5. Ispis svih krugova iz polja
6. Ispis na temelju naziva kruga  */


#include <iostream>
#include <cmath>

//using namespace std;

int main(){
    
    int izbor,br_krg,brojac=0;
    
    const double pi=3.14;
    
    char nastavak;
    std::string naziv2;
    
    struct krugovi{
        
        std::string naziv;
        double r,O,P;
        
    }polje[10];
    
   do{
    std::cout<<"IZBORNIK"<<std::endl;
    std::cout<<"4. Unos novog kruga u polje krugova (unose se naziv i radijus, izračunavaju se opseg i površina)"<<std::endl;
    std::cout<<"5. Ispis svih krugova iz polja"<<std::endl;
    std::cout<<"6. Ispis na temelju naziva kruga"<<std::endl;
    std::cout<<"0 za izlaz"<<std::endl;
    std::cin>>izbor;
    
    switch(izbor){
    
    case 4:{
    std::cout<<"Unesite naziv i radijus kruga: \n";
    for(int i=0;i<10;i++){
        std::cout<<"Naziv "<<i+1<<" kruga: \n";
        std::cin>>polje[i].naziv;
        brojac++;//pripazit na mjesto brojaca
        std::cout<<"Radijus: \n";
        std::cin>>polje[i].r;
        std::cout<<"Sljedeći krug?(Y/N): \n";
        std::cin>>nastavak;
        if(nastavak=='Y' || nastavak=='y')
        continue;
        else
        break;
    }
    break;
    }
    case 5:
         std::cout<<"Koliko krugova zelite ispisat? \n";
         std::cin>>br_krg;
         if(br_krg<=brojac){
         for(int i=0;i<br_krg;i++){
             std::cout<<i+1<<". krug: "<<polje[i].naziv<<std::endl;
             std::cout<<"Uneseni radijus "<<i+1<<". kruga : "<<polje[i].r<<std::endl;
             polje[i].O=pi*(2*polje[i].r);
             std::cout<<"Opseg "<<i+1<<". kruga : "<<polje[i].O<<std::endl;
             polje[i].P=pi*pow(polje[i].r,2);
             std::cout<<"Povrsina "<<i+1<<". kruga : "<<polje[i].P<<std::endl;
         }
    }else{
        std::cout<<"Prevelik unos!"<<std::endl;
        break;
    }
    break;
    case 6:
    std::cin.ignore(10000, '\n');

    std::cout<<"Unesite ime kruga: \n";
    getline(std::cin,naziv2);
    for(int i=0;i<10;i++){
    if(polje[i].naziv==naziv2){
       std::cout<<"Ime kruga: "<<polje[i].naziv<<std::endl;
       std::cout<<"Radijus kruga: "<<polje[i].r<<std::endl;
       polje[i].O=pi*(2*polje[i].r);
       std::cout<<"Opseg kruga : "<<polje[i].O<<std::endl;
       polje[i].P=pi*pow(polje[i].r,2);
       std::cout<<"Povrsina kruga : "<<polje[i].P<<std::endl;
       }
    }
    break;
    default:
    if (izbor != 0 && izbor != 4 && izbor != 5 && izbor != 6)
    std::cout<<"Pogrešan unos!"<<std::endl;
    }//kraj switcha
    
    }while(izbor!=0);
    return 0;
}