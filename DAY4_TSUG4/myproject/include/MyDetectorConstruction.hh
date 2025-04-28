#ifndef MYDETECTORCONSTRUCTION_HH
#define MYDETECTORCONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

class G4Material;

class MyDetectorConstruction : public G4VUserDetectorConstruction {
		public:
			MyDetectorConstruction(); //constructor
			~MyDetectorConstruction() override; //destructor
			
			const G4VPhysicalVolume*  GetTargetPhysicalVolume() const { return fTargetPhysicalVolume; }
			G4double  GetTargetThickness() const { return fTargetThickness; }
			void SetTargetThickness(G4double thickness);
			const G4Material* GetTargetMaterial() const { return fTargetMaterial; }
			void  SetTargetMaterial(const G4String& matName);
			
			G4VPhysicalVolume* Construct() override;
			
			G4double GetGunXPosition() { return fGunXPosition; }		
			
		private:
			G4Material* 	fTargetMaterial;
			G4double 		fTargetThickness;
			G4double 		fGunXPosition;
			
			G4VPhysicalVolume*   fTargetPhysicalVolume;
};

#endif
