#ifndef ZoneAirLoopEquipmentManager_hh_INCLUDED
#define ZoneAirLoopEquipmentManager_hh_INCLUDED

// C++ Headers
#include <string>

// EnergyPlus Headers
#include <EnergyPlus.hh>

namespace EnergyPlus {

namespace ZoneAirLoopEquipmentManager {

	// Data
	// MODULE PARAMETER DEFINITIONS:
	extern bool GetAirDistUnitsFlag; // If TRUE, Air Distribution Data has not been read in yet
	extern bool MyOneTimeFlag;

	// DERIVED TYPE DEFINITIONS:
	// na

	// MODULE VARIABLE DECLARATIONS:
	// na

	// SUBROUTINE SPECIFICATIONS FOR MODULE ZoneAirLoopEquipmentManager

	// Functions
	void
	clear_state();

	void
	ManageZoneAirLoopEquipment(
		std::string const & ZoneAirLoopEquipName,
		bool const FirstHVACIteration,
		Real64 & SysOutputProvided,
		Real64 & NonAirSysOutput,
		Real64 & LatOutputProvided, // Latent add/removal supplied by window AC (kg/s), dehumid = negative
		int const ActualZoneNum,
		int & ControlledZoneNum,
		int & CompIndex
	);

	void
	GetZoneAirLoopEquipment();

	void
	InitZoneAirLoopEquipment(
		bool const FirstHVACIteration, // unused1208
		int const AirDistUnitNum,
		int const ZoneNum
	);

	void
	SimZoneAirLoopEquipment(
		int const AirDistUnitNum,
		Real64 & SysOutputProvided,
		Real64 & NonAirSysOutput,
		Real64 & LatOutputProvided, // Latent add/removal provided by this unit (kg/s), dehumidify = negative
		bool const FirstHVACIteration,
		int const ControlledZoneNum,
		int const ActualZoneNum
	);

	void
	UpdateZoneAirLoopEquipment();

	// void
	// ReportZoneAirLoopEquipment(
	// 	int const AirDistUnitNum
	// );

	//     NOTICE

	//     Copyright (c) 1996-2015 The Board of Trustees of the University of Illinois
	//     and The Regents of the University of California through Ernest Orlando Lawrence
	//     Berkeley National Laboratory.  All rights reserved.

	//     Portions of the EnergyPlus software package have been developed and copyrighted
	//     by other individuals, companies and institutions.  These portions have been
	//     incorporated into the EnergyPlus software package under license.   For a complete
	//     list of contributors, see "Notice" located in main.cc.

	//     NOTICE: The U.S. Government is granted for itself and others acting on its
	//     behalf a paid-up, nonexclusive, irrevocable, worldwide license in this data to
	//     reproduce, prepare derivative works, and perform publicly and display publicly.
	//     Beginning five (5) years after permission to assert copyright is granted,
	//     subject to two possible five year renewals, the U.S. Government is granted for
	//     itself and others acting on its behalf a paid-up, non-exclusive, irrevocable
	//     worldwide license in this data to reproduce, prepare derivative works,
	//     distribute copies to the public, perform publicly and display publicly, and to
	//     permit others to do so.

	//     TRADEMARKS: EnergyPlus is a trademark of the US Department of Energy.

} // ZoneAirLoopEquipmentManager

} // EnergyPlus

#endif
