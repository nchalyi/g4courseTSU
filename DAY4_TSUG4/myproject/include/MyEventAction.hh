#ifndef MYEVENTACATION_HH
#define MYEVENTACATION_HH

#include "G4UserEventAction.hh"

#include "globals.hh"

class MyEventAction : public G4UserEventAction {
public:

  MyEventAction();
 ~MyEventAction() override;

  void BeginOfEventAction(const G4Event* evt) override;
  void EndOfEventAction(const G4Event* evt) override;

  void AddEnergyDeposit(G4double edep) {
    fEdepPerEvent += edep;
  }

private:

  G4double fEdepPerEvent;

};

#endif
