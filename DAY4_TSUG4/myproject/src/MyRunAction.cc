#include "MyRunAction.hh"

#include "MyRun.hh"
#include "MyPrimaryGeneratorAction.hh"
#include "MyDetectorConstruction.hh"

#include "G4Run.hh"

MyRunAction::MyRunAction(MyDetectorConstruction* det, MyPrimaryGeneratorAction* prim)
: G4UserRunAction(),
  fDetector(det),
  fPrimary(prim),
  fRun(nullptr) {}


MyRunAction::~MyRunAction() {}


G4Run* MyRunAction::GenerateRun()  {
  fRun = new MyRun(fDetector, fPrimary);
  return fRun;
}


void MyRunAction::BeginOfRunAction(const G4Run*) {
  if (fPrimary != nullptr) {
    fPrimary->UpdatePosition();
  }
}

void MyRunAction::EndOfRunAction(const G4Run*) {
  if (IsMaster()) {
    fRun->EndOfRunSummary();
  }
}
