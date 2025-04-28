#ifndef MYRUNACTION_HH
#define MYRUNACTION_HH


#include "G4UserRunAction.hh"

class MyRun;
class MyPrimaryGeneratorAction;
class MyDetectorConstruction;


class MyRunAction : public G4UserRunAction {
public:

  MyRunAction(MyDetectorConstruction* det, MyPrimaryGeneratorAction* prim);
 ~MyRunAction() override;
  
  G4Run* GenerateRun() override;

  void BeginOfRunAction(const G4Run*) override;
  void EndOfRunAction(const G4Run*) override;


private:

  MyDetectorConstruction*      fDetector;
  MyPrimaryGeneratorAction*    fPrimary;

  MyRun*  fRun;
  
};

#endif 
