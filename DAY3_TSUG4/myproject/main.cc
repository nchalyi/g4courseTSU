#include "G4RunManagerFactory.hh" 
#include "globals.hh"

#include "MyDetectorConstruction.hh"
#include "MyActionInitialization.hh"

#include "G4PhysListFactory.hh"

#include "G4UImanager.hh"
#include "G4UIExecutive.hh"

#include "G4VisExecutive.hh"

int main(int argc, char** argv){
	
	G4String macrofile = "";
	G4UIExecutive* ui = nullptr;
	if ( argc == 1 ) {
		ui = new G4UIExecutive(argc,argv);
	} else {
		macrofile = argv[1]; // ./main file.mac
	}
	
	auto* runManager = G4RunManagerFactory::CreateRunManager(); // hearth of our programm
	
	MyDetectorConstruction* detector = new MyDetectorConstruction; // 1. Detector
	runManager->SetUserInitialization( detector );
	
	G4PhysListFactory plFactory; // 2. Physics
	G4VModularPhysicsList *pl = plFactory.GetReferencePhysList( "FTFP_BERT" );
	runManager->SetUserInitialization( pl );
	
	runManager->SetUserInitialization( new MyActionInitialization ( detector ) ); // 3. Actions (+ particle gun)
	
	//runManager->Initialize();
	
	//runManager->BeamOn(10);
	runManager->SetNumberOfThreads(1);
	
	G4VisManager* visManager = new G4VisExecutive; // visualization
	visManager->Initialize();
	
	G4UImanager* UI = G4UImanager::GetUIpointer();
	if ( ui == nullptr ) {
		// batch mode
		G4String command = "/control/execute ";
		UI->ApplyCommand( command + macrofile );
		G4cout<< "=== BATCH MODE ==="<<G4endl;
	} else {
		ui->SessionStart();
		G4cout<< "=== UI MODE ==="<<G4endl;
		delete ui;
	}
	
	G4cout << " === END OF TEST === " << G4endl;
	delete visManager;
	delete runManager;
	return 0;
}

