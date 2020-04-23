#ifndef __SimGOSymulatorGO__
#define __SimGOSymulatorGO__

/**
@file
Subclass of SymulatorGO, which is generated by wxFormBuilder.
*/

#include "GUI.h"

//// end generated include

/** Implementing SymulatorGO */
class SimGOSymulatorGO : public SymulatorGO
{
	protected:
		// Handlers for SymulatorGO events.
		void loadImage( wxCommandEvent& event );
		void loadDepthMap( wxCommandEvent& event );
		void mapOn( wxCommandEvent& event );
		void lensOnScroll( wxScrollEvent& event );
		void apertureOnScroll( wxScrollEvent& event );
		void resetImage( wxCommandEvent& event );
		void saveImage( wxCommandEvent& event );
		void windowResized( wxSizeEvent& event );
		void updateUI( wxUpdateUIEvent& event );
		void gammaCorrection( wxScrollEvent& event );
		void setContrast( wxScrollEvent& event );
		void setBrightness( wxScrollEvent& event );
	public:
		/** Constructor */
		SimGOSymulatorGO( wxWindow* parent );
	//// end generated class members





};

#endif // __SimGOSymulatorGO__
