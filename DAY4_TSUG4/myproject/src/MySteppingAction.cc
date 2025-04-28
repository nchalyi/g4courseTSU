#include "MySteppingAction.hh"

#include "MyDetectorConstruction.hh"
#include "MyEventAction.hh"

#include "G4Step.hh"

MySteppingAction::MySteppingAction(MyDetectorConstruction* det, MyEventAction* evta)
: G4UserSteppingAction(),
  fDetector(det),
  fEventAction(evta) {}

MySteppingAction::~MySteppingAction() {}

void MySteppingAction::UserSteppingAction(const G4Step* step) {

  if( step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()  
      != fDetector->GetTargetPhysicalVolume() ) return;

   G4double edep = step->GetTotalEnergyDeposit();
   if (edep>0.0) {
     fEventAction->AddEnergyDeposit(edep);
   }

}
