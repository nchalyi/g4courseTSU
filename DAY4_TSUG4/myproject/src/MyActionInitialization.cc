#include "MyDetectorConstruction.hh"
#include "MyActionInitialization.hh"
#include "MyPrimaryGeneratorAction.hh"

#include "MyEventAction.hh"
#include "MySteppingAction.hh"
#include "MyRunAction.hh"

MyActionInitialization::MyActionInitialization(MyDetectorConstruction* det)
:	G4VUserActionInitialization(),
	fMyDetector(det) { }
	
MyActionInitialization::~MyActionInitialization() {	}

void MyActionInitialization::BuildForMaster() const {			// NEW
	SetUserAction( new MyRunAction(fMyDetector, nullptr));		// NEW
}															    // NEW

void MyActionInitialization::Build() const {
	MyPrimaryGeneratorAction* primaryAction = new MyPrimaryGeneratorAction(fMyDetector);
	SetUserAction(primaryAction);

	MyRunAction* runAction = new MyRunAction(fMyDetector, primaryAction); //NEW
	SetUserAction(runAction);   

	MyEventAction* eventAction = new MyEventAction(); //NEW
	SetUserAction(eventAction);

	MySteppingAction* steppingAction = new MySteppingAction(fMyDetector, eventAction); //NEW
	SetUserAction(steppingAction);


}
