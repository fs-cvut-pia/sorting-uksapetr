#include "trideni.h"

void nacti(std::string nazev, seznam_slov & jmena){
	std::ifstream vstupni_soubor;
	vstupni_soubor.open(nazev.c_str());

   std::string radek;

   while (std::getline(vstupni_soubor,radek)){
    jmena.push_back(radek);
   }
   
   vstupni_soubor.close();
}

void serad(seznam_slov & jmena){
	bool prohozeno;
    int j,i;
    for (j = 0; j < jmena.size() - 1; j++){
        prohozeno = false;

		for (i = 0; i < jmena.size() - j - 1; ++i) {
           if (jmena[i] > jmena[i+1]) {
               std::swap(jmena[i], jmena[i+1]);
               prohozeno = true;
            }
        }
        
		if (!prohozeno){
            break;
		}
	}
}
bool zeptej_se_jestli_vypsat(){
	char vypis;
    bool kontrola=true;
	while(kontrola){
		std::cout << "Chcete vypsat serazena jmena [A/n]" << std::endl;
    	std::cin >> vypis;
    
	    if (vypis =='A'|| vypis =='a') {
	        kontrola=!kontrola;
			return true;
	    }
	    else if(vypis =='N'|| vypis =='n') {
	    	kontrola=!kontrola;
	        return false;
	    }
	    else{
	    	std::cout<<"Chybne zadana odpoved"<<std::endl;
		} 
	}
}	
void vypis(seznam_slov const& jmena){
	for (int i = 0; i < jmena.size(); ++i)
    {
      std::cout << jmena[i] << std::endl;
    }
}


