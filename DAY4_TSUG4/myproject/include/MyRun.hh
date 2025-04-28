#ifndef MYRUN_HH
#define MYRUN_HH

#include "G4Run.hh"
#include "Hist.hh"

class MyPrimaryGeneratorAction;
class MyDetectorConstruction;

class MyRun : public G4Run {
public:
  MyRun(MyDetectorConstruction* det, MyPrimaryGeneratorAction* prim);
 ~MyRun() override;


  void Merge(const G4Run* run) override;  


  void AddEnergyDeposit(G4double edep) {
     fHist->Fill(edep);
  }

  
  void  EndOfRunSummary();


private:

 MyDetectorConstruction*      fDetector;
 MyPrimaryGeneratorAction*    fPrimary;

 Hist*                          fHist;

};

#endif
