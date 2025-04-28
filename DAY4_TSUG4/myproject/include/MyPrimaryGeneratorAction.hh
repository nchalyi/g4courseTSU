#ifndef MYPRIMARYGENERATORACTION_HH
#define MYPRIMARYGENERATORACTION_HH

#include "G4VUserPrimaryGeneratorAction.hh"
#include "MyDetectorConstruction.hh"
#include "globals.hh"
#include "G4ParticleGun.hh"

class MyDetectorConstruction;
class G4ParticleGun;
class G4Event;

class MyPrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction {
		public:
			MyPrimaryGeneratorAction(MyDetectorConstruction* det);
			~MyPrimaryGeneratorAction() override;
			
			void GeneratePrimaries(G4Event*) override;
			
			void SetDefaultKinematics();
			void UpdatePosition();
			
			const G4String& GetParticleName()   { return fParticleGun->GetParticleDefinition()->GetParticleName(); }
			G4double GetParticleEnergy() { return fParticleGun->GetParticleEnergy(); }
		private:
			MyDetectorConstruction* fMyDetector;
			G4ParticleGun* fParticleGun;	
};

#endif
