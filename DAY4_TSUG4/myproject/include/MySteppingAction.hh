#ifndef MYSTEPPINGACTION_HH
#define MYSTEPPINGACTION_HH

#include "G4UserSteppingAction.hh"

class MyDetectorConstruction;
class MyEventAction;

class MySteppingAction : public G4UserSteppingAction {

public:
 
  MySteppingAction(MyDetectorConstruction* det,
                     MyEventAction*  eventa);
 ~MySteppingAction() override;


  void UserSteppingAction(const G4Step* step) override;

private:

  MyDetectorConstruction* fDetector;
  MyEventAction*          fEventAction;

};

#endif 
