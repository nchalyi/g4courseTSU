#ifndef MYDETECTORCONSTRUCTION_HH
#define MYDETECTORCONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

class G4Material;

class MyDetectorConstruction : public G4VUserDetectorConstruction {
		public:
			MyDetectorConstruction(); //constructor
			~MyDetectorConstruction() override; //destructor
			
			G4VPhysicalVolume* Construct() override;
			
			G4double GetGunXPosition() { return fGunXPosition; }		
			
		private:
			G4Material* 	fTargetMaterial;
			G4double 		fTargetThickness;
			G4double 		fGunXPosition;
};

#endif
