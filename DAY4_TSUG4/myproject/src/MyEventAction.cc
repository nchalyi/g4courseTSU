#include "MyEventAction.hh"

#include "G4RunManager.hh"
#include "MyRun.hh"

MyEventAction::MyEventAction() 
: G4UserEventAction(),
  fEdepPerEvent(0.0) {}

MyEventAction::~MyEventAction() {} 

void MyEventAction::BeginOfEventAction(const G4Event*) {
  fEdepPerEvent = 0.0;
}

void MyEventAction::EndOfEventAction(const G4Event*) {
  MyRun* run = static_cast<MyRun*>(G4RunManager::GetRunManager()->GetNonConstCurrentRun());
  run->AddEnergyDeposit(fEdepPerEvent);
}
