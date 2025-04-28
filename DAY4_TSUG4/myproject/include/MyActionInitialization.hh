#ifndef MYACTIONINITIALIZATION_HH
#define MYACTIONINITIALIZATION_HH

#include "G4VUserActionInitialization.hh"
#include "MyDetectorConstruction.hh"

class MyDetectorConstruction;

class MyActionInitialization : public G4VUserActionInitialization {
	public:
		MyActionInitialization(MyDetectorConstruction* det);
		~MyActionInitialization() override;
		
		void BuildForMaster() const override;
		void Build() const override;
	private:
		MyDetectorConstruction* fMyDetector;

};

#endif
