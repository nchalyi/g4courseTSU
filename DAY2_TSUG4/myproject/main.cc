#include "G4RunManagerFactory.hh" 
#include "globals.hh"

#include "MyDetectorConstruction.hh"
#include "MyActionInitialization.hh"

#include "G4PhysListFactory.hh"

int main(){
	
	auto* runManager = G4RunManagerFactory::CreateRunManager(); // hearth of our programm
	
	MyDetectorConstruction* detector = new MyDetectorConstruction;
	runManager->SetUserInitialization( detector );
	
	G4PhysListFactory plFactory; // our physics
	G4VModularPhysicsList *pl = plFactory.GetReferencePhysList( "FTFP_BERT" );
	runManager->SetUserInitialization( pl );
	
	runManager->SetUserInitialization( new MyActionInitialization ( detector ) );
	
	runManager->Initialize();
	
	runManager->BeamOn(10);
	
	G4cout << " === END OF TEST === " << G4endl;
	delete runManager;
	return 0;
}

