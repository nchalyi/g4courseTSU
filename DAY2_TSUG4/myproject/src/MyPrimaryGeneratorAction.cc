#include "MyPrimaryGeneratorAction.hh"
#include "MyDetectorConstruction.hh"

#include "G4ParticleGun.hh"
#include "G4Event.hh"
#include "G4ParticleTable.hh"

MyPrimaryGeneratorAction::MyPrimaryGeneratorAction(MyDetectorConstruction* det)
:	G4VUserPrimaryGeneratorAction(),
	fMyDetector(det),
	fParticleGun(nullptr) {

	G4int nParticle = 1;
	fParticleGun = new G4ParticleGun (nParticle);
	SetDefaultKinematics();
}

MyPrimaryGeneratorAction::~MyPrimaryGeneratorAction() {
	delete fParticleGun;
}

void MyPrimaryGeneratorAction::GeneratePrimaries(G4Event* evt) {
	fParticleGun->GeneratePrimaryVertex(evt);
}

void MyPrimaryGeneratorAction::SetDefaultKinematics() {
	G4ParticleDefinition* part = G4ParticleTable::GetParticleTable()->FindParticle("e-");
	fParticleGun->SetParticleDefinition( part );
	fParticleGun->SetParticleMomentumDirection ( G4ThreeVector(1.,0.,0.) );
	fParticleGun->SetParticleEnergy( 30.*CLHEP::MeV );
	UpdatePosition();
}

void MyPrimaryGeneratorAction::UpdatePosition() {
	fParticleGun->SetParticlePosition ( G4ThreeVector ( fMyDetector->GetGunXPosition(),0.,0.) );
}






