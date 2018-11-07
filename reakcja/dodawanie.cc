// compile with:  g++ -o reaction.x reaction.cc `root-config --cflags --glibs`

# include <cstdlib>  
# include <iostream> 
# include "TRandom.h"  
# include "TH1.h" 
# include "TF1.h"
# include "TH2.h"
# include "TCanvas.h"
# include "TApplication.h"
# include "TLorentzVector.h"
# include "TGenPhaseSpace.h"
# include "TFile.h"
# include <cmath>

 
using namespace std;


TString home_path=Form("/home/mateusz/Desktop/reakcja/wynik.root");


int main()
{    
   TApplication theApp("App",0,0);
   TFile outfile(home_path.Data(),"recreate");

  
   TCanvas *c1 = new TCanvas("c1","transparent pad",200,10,700,500);
   // TCanvas *c2 = new TCanvas("c2","transparent pad",200,10,700,500);
   c1->cd();
  
   
   TLorentzVector p1(0.0, 0.0, 0.7, 1.17040334928);//mn+mp-Dm
   TLorentzVector d1(0.0, 0.0, 0.0, 1.8756);//E=sqrt(0.700^2+0.938^2)
   TLorentzVector p2(0.0, 0.0, 0.0, 0.938  );
   TLorentzVector d2(0.0, 0.0, 0.7, 2.00196787187);
   TLorentzVector p3(0.0, 0.0, 0.35, 1.90797677135);
   TLorentzVector d3(0.0, 0.0, 0.35, 1.00117131401);
   TLorentzVector W1 = p1 + d1;
   TLorentzVector W2 = p2 + d2;
   TLorentzVector W3 = p3 + d3;
   
   

   TVector3 boost1= W1.BoostVector();
   TVector3 boost2= W2.BoostVector();
   TVector3 boost3= W3.BoostVector();
   
   p1.Boost(boost1);
   d1.Boost(boost1);
   p2.Boost(boost2);
   d2.Boost(boost2);
   p3.Boost(boost3);
   d3.Boost(boost3);

   cout<<"Energia p1->d1 ktory jest tarcza"<<(p1+d1).E()<<endl;
   cout<<"Energia p2<-d2 p2 jest tarcza"<<(p2+d2).E()<<endl;
   cout<<"Energia p3-><-d3"<<(p3+d3).E()<<endl;

   
    outfile.Write();
    outfile.Close();
    
  
     theApp.Run();
	 return 0;
}


