#include "MyRun.hh"
#include "G4PhysicalConstants.hh"
#include "G4SystemOfUnits.hh"
#include "MyPrimaryGeneratorAction.hh"
#include "MyDetectorConstruction.hh"

MyRun::MyRun(MyDetectorConstruction* det, MyPrimaryGeneratorAction* prim) 
: G4Run(), 
  fDetector(det),
  fPrimary(prim) {

  fHist = new Hist("Hist_Edep.dat", 0.0, 10.0*CLHEP::keV, 100);
} 

MyRun::~MyRun() {
  delete fHist;
}


void MyRun::Merge(const G4Run* run) {
  const MyRun* localRun = static_cast<const MyRun*>(run);

  fHist->Add(localRun->fHist);

  fPrimary = localRun->fPrimary;

  G4Run::Merge(run);
}


void MyRun::EndOfRunSummary() {
  G4int nEvents  = GetNumberOfEvent();
  if (nEvents==0) return;

  G4cout << " #Events = " << nEvents << G4endl;
  G4cout << " Particle type: " << fPrimary->GetParticleName() 
         << " Energy = " <<  fPrimary->GetParticleEnergy() 
         << G4endl;
  G4cout << " Target thickness = " << fDetector->GetTargetThickness() << G4endl;

  fHist->WriteToFile(true);
}
