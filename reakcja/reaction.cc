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
   TH1* h = new TH1D("h","pProton1 theta",100,0,3.5);
   TH1 *h1 = new TH1D("h1","pProton2 theta",100,0,3.5);
   TH1 *h2 = new TH1D("h2","pPion1 theta",100,0,3.5);
   TH1 *h3 = new TH1D("h3","pPion2 theta",100,0,3.5);
   TH1* h4 = new TH1D("h4","pProton1 phi",100,0,3.5);
   TH1 *h5 = new TH1D("h5","pProton2 phi",100,0,3.5);
   TH1 *h6 = new TH1D("h6","pPion1 phi",100,0,3.5);
   TH1 *h7 = new TH1D("h7","pPion2 phi",100,0,3.5);
   TH1* h8 = new TH1D("h8","pProton1 p",100,0,3.5);
   TH1 *h9 = new TH1D("h9","pProton2 p",100,0,3.5);
   TH1 *h10 = new TH1D("h10","pPion1 p",100,0,3.5);
   TH1 *h11 = new TH1D("h11","pPion2 p",100,0,3.5);
   TH1 *t  = new TH1D("t","pProton1 costheta",100,0,3.5);
   TH1 *t1 = new TH1D("t1","pProton2 costheta",100,0,3.5);
   TH1 *t2 = new TH1D("t2","pPion1 costheta",100,0,3.5);
   TH1 *t3 = new TH1D("t3","pPion2 costheta",100,0,3.5);
   TH1 *h12  = new TH1D("h12","pProton1 E",100,0,3.5);
   TH1 *h13 = new TH1D("h13","pProton2 E",100,0,3.5);
   TH1 *h14 = new TH1D("h14","pPion1 E",100,0,3.5);
   TH1 *h15 = new TH1D("h15","pPion2 E",100,0,3.5);
   TH1* hb = new TH1D("hb","pProton1b theta",100,0,3.5);
   TH1 *h1b = new TH1D("h1b","pProton2b theta",100,0,3.5);
   TH1 *h2b = new TH1D("h2b","pPion1b theta",100,0,3.5);
   TH1 *h3b = new TH1D("h3b","pPion2b theta",100,0,3.5);
   TH1 *h4b = new TH1D("h4b","pProton1b phi",100,0,3.5);
   TH1 *h5b = new TH1D("h5b","pProton2b phi",100,0,3.5);
   TH1 *h6b = new TH1D("h6b","pPion1b phi",100,0,3.5);
   TH1 *h7b = new TH1D("h7b","pPion2b phi",100,0,3.5);
   TH1* h8b = new TH1D("h8b","pProton1b p",100,0,3.5);
   TH1 *h9b = new TH1D("h9b","pProton2b p",100,0,3.5);
   TH1 *h10b = new TH1D("h10b","pPion1b p",100,0,3.5);
   TH1 *h11b = new TH1D("h11b","pPion2b p",100,0,3.5);
   TH1 *tb  = new TH1D("tb","pProton1b costheta",100,0,3.5);
   TH1 *t1b = new TH1D("t1b","pProton2b costheta",100,0,3.5);
   TH1 *t2b = new TH1D("t2b","pPion1b costheta",100,0,3.5);
   TH1 *t3b = new TH1D("t3b","pPion2b costheta",100,0,3.5);
   TH1 *h12b  = new TH1D("h12b","pProton1b E",100,0,3.5);
   TH1 *h13b = new TH1D("h13b","pProton2b E",100,0,3.5);
   TH1 *h14b = new TH1D("h14b","pPion1b E",100,0,3.5);
   TH1 *h15b = new TH1D("h15b","pPion2b E",100,0,3.5);
   
   TLorentzVector target(0.0, 0.0, 0.0, 1.8755);//mn+mp-Dm
   TLorentzVector beam(0.0, 0.0, 0.7, 1.1704);//E=sqrt(0.700^2+0.938^2)
   TLorentzVector W = beam + target;

   TVector3 boost= W.BoostVector();
   cout<< "Masa niezmiennicza przed rozpadem przed boostem  "<<(beam+target).Mag()<<endl;
   cout << "boost:"<<boost.Z() << endl;
   beam.Boost(W.BoostVector());
   target.Boost(W.BoostVector());
   cout<<"Masa niezmiennicza przed rozpadem po booscie  "<<(beam+target).Mag()<<endl;
   //(Momentum, Energy units are Gev/C, GeV)
   Double_t masses[] = { 0.938, 0.938};
   TGenPhaseSpace event;
   event.SetDecay(W, 2, masses);
   TLorentzVector x, x2;
   int l=0,k=0;
   for (Int_t n=0;n<1000;n++) {
      Double_t weight = event.Generate();
      TLorentzVector *pProton1 = event.GetDecay(0);
      TLorentzVector *pProton2 = event.GetDecay(1);
     //TLorentzVector *pPion1 = event.GetDecay(2);
     // TLorentzVector *pPion2= event.GetDecay(3);
      
      x=*pProton1+*pProton2;
      if(l==0){cout<<"Ped przed boostem "<<x.P()<<endl; l=1;}
    
      h->Fill(pProton1->Theta(),weight);
      h1->Fill(pProton2->Theta(),weight);
      //h2->Fill(pPion1->Theta(),weight);
      //h3->Fill(pPion2->Theta(),weight);
      t->Fill(pProton1->CosTheta(),weight);
      t1->Fill(pProton2->CosTheta(),weight);
      //t2->Fill(pPion1->CosTheta(),weight);
      //t3->Fill(pPion2->CosTheta(),weight);
      h4->Fill(pProton1->Phi(),weight);
      h5->Fill(pProton2->Phi(),weight);
      //h6->Fill(pPion1->Phi(),weight);
      //h7->Fill(pPion2->Phi(),weight);
      h8->Fill(pProton1->P(),weight);
      h9->Fill(pProton2->P(),weight);
     // h10->Fill(pPion1->P(),weight);
     // h11->Fill(pPion2->P(),weight);
      h12->Fill(pProton1->E(),weight);
      h13->Fill(pProton2->E(),weight);
     // h14->Fill(pPion1->E(),weight);
      //h15->Fill(pPion2->E(),weight);
      
      pProton1->Boost(-W.BoostVector());
      pProton2->Boost(-W.BoostVector());
      //pPion1->Boost(-W.BoostVector());
     // pPion2->Boost(-W.BoostVector());
      
      x2=*pProton1+*pProton2;
      if(k==0){cout<<"Ped po booscie "<<x2.P()<<endl; k=1;}
       
      hb->Fill(pProton1->Theta(),weight);
      h1b->Fill(pProton2->Theta(),weight);
      //h2b->Fill(pPion1->Theta(),weight);
      //h3b->Fill(pPion2->Theta(),weight);
      tb->Fill(pProton1->CosTheta(),weight);
      t1b->Fill(pProton2->CosTheta(),weight);
      //t2b->Fill(pPion1->CosTheta(),weight);
      //t3b->Fill(pPion2->CosTheta(),weight);
      h4b->Fill(pProton1->Phi(),weight);
      h5b->Fill(pProton2->Phi(),weight);
      //h6b->Fill(pPion1->Phi(),weight);
      //h7b->Fill(pPion2->Phi(),weight);
      h8b->Fill(pProton1->P(),weight);
      h9b->Fill(pProton2->P(),weight);
      //h10b->Fill(pPion1->P(),weight);
      //h11b->Fill(pPion2->P(),weight);
      h12b->Fill(pProton1->E(),weight);
      h13b->Fill(pProton2->E(),weight);
      //h14b->Fill(pPion1->E(),weight);
      //h15b->Fill(pPion2->E(),weight);
      
   }
    cout<<"Masa niezmiennicza po rozpadzie  "<<x.Mag()<<endl;
    outfile.Write();
    outfile.Close();
    
  
     theApp.Run();
	 return 0;
}




