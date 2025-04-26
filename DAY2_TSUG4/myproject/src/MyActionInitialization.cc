#include "MyDetectorConstruction.hh"
#include "MyActionInitialization.hh"
#include "MyPrimaryGeneratorAction.hh"

MyActionInitialization::MyActionInitialization(MyDetectorConstruction* det)
:	G4VUserActionInitialization(),
	fMyDetector(det) { }
	
MyActionInitialization::~MyActionInitialization() {	}

void MyActionInitialization::Build() const {
	MyPrimaryGeneratorAction* primaryAction = new MyPrimaryGeneratorAction(fMyDetector);
	SetUserAction(primaryAction);
}
