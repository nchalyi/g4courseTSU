#include "G4RunManagerFactory.hh" 
#include "globals.hh"

//#include "MyGeneratorConstruction.hh"

#include "G4PhysListFactory.hh"

int main(){
	
	auto* runManager = G4RunManagerFactory::CreateRunManager();
	
	G4PhysListFactory plFactory;
	G4VModularPhysicsList *pl = plFactory.GetReferencePhysList( "FTFP_BERT" );
	runManager->SetUserInitialization( pl );
	
	
	G4cout << " === END OF TEST === " << G4endl;
	delete runManager;
	return 0;
}
