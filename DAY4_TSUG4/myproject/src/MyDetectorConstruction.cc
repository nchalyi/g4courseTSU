#include "MyDetectorConstruction.hh"

#include "G4Box.hh" // type of geometry
#include "G4LogicalVolume.hh" // logical volume
#include "G4PVPlacement.hh" // PV -- physical volume

#include "G4Material.hh"
#include "G4NistManager.hh"

#include "G4PhysicalConstants.hh"
#include "G4SystemOfUnits.hh"

#include "G4RunManager.hh"

MyDetectorConstruction::MyDetectorConstruction()
:	G4VUserDetectorConstruction() {
		/* G4String matName = "G4_Si";		
		fTargetMaterial = G4NistManager::Instance()->FindOrBuildMaterial(matName);
		if (!fTargetMaterial) {
			G4cerr << " === Error in material! ===" << G4endl;
			exit(-1);
		} */
		SetTargetMaterial("G4_Si");
		fTargetThickness = 5.6*CLHEP::um;
		fGunXPosition	 = -0.25*(1.1*fTargetThickness + fTargetThickness);
}

MyDetectorConstruction::~MyDetectorConstruction() {}

void MyDetectorConstruction::SetTargetMaterial(const G4String& matName) {
  G4Material* mat = G4NistManager::Instance()->FindOrBuildMaterial(matName);
  if (mat==nullptr) {
    G4cerr << " ERROR: YourDetectorConstruction::SetTargetMaterial unknown material name  = " << matName <<G4endl;
    exit(-1);
   }  
   
   fTargetMaterial = mat;   
   G4RunManager::GetRunManager()->PhysicsHasBeenModified();
}


void MyDetectorConstruction::SetTargetThickness(G4double thickness) {
   fTargetThickness = thickness;
   G4RunManager::GetRunManager()->ReinitializeGeometry();
}

G4VPhysicalVolume* MyDetectorConstruction::Construct() {
	G4cout << " == MyDetectorConstruction::Construct() is called! == " << G4endl;
	G4Material* materialWorld = G4NistManager::Instance()->FindOrBuildMaterial("G4_Galactic");
	G4Material* materialTarget = fTargetMaterial;
	
	G4double targetXSize 	= fTargetThickness;
	G4double targetYZSize 	= 1.25*fTargetThickness;
	G4double worldXSize 	= 1.1*targetXSize;
	G4double worldYZSize 	= 1.1*targetYZSize;
	
	G4Box*				worldSolid 		= new G4Box("solid-World",
													0.5*worldXSize, // half-size x
													0.5*worldYZSize, // half-size y
													0.5*worldYZSize); // half-size z
													
	G4LogicalVolume* 	worldLogical	= new G4LogicalVolume(worldSolid,
															  materialWorld,
															  "logic-World");
															
	G4VPhysicalVolume*  worldPhysical   = new G4PVPlacement(nullptr, //rotation
															G4ThreeVector(0.,0.,0.), //translation
															worldLogical, 
															"World", //name
															nullptr, // is mother volume?
															0, // boolean
															0); // check overlaps
	
	G4Box*				targetSolid 		= new G4Box("solid-Target",
													0.5*targetXSize, //x
													0.5*targetYZSize, //y
													0.5*targetYZSize); //z-half
	G4LogicalVolume* 	targetLogical	= new G4LogicalVolume(targetSolid,
															  materialTarget,
															  "logic-Target");
															
	G4VPhysicalVolume*  targetPhysical   = new G4PVPlacement(nullptr, //rotation
															G4ThreeVector(0.,0.,0.), //translation
															targetLogical, 
															"Target", //name
															worldLogical, // is mother volume?
															0,
															0);
	fTargetPhysicalVolume = targetPhysical;
	return worldPhysical;	
}
