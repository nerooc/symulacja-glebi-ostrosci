///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"

///////////////////////////////////////////////////////////////////////////

SymulatorGO::SymulatorGO( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 1300,600 ), wxSize( 1300,600 ) );

	wxBoxSizer* Sizer1;
	Sizer1 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	bSizer2->SetMinSize( wxSize( 250,-1 ) );

	bSizer2->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button1 = new wxButton( this, wxID_ANY, wxT("Wczytaj obraz"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button1->SetMinSize( wxSize( 200,-1 ) );

	bSizer2->Add( m_button1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer2->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button2 = new wxButton( this, wxID_ANY, wxT("Wczytaj mape glebokosci"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_button2->SetMinSize( wxSize( 200,-1 ) );

	bSizer2->Add( m_button2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer2->Add( 0, 0, 1, wxEXPAND, 5 );

	m_checkBox1 = new wxCheckBox( this, wxID_ANY, wxT("Mapa glebokosci"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_checkBox1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer2->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer2->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );


	bSizer2->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("Obiektyw"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer2->Add( m_staticText1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_slider1 = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	m_slider1->SetMinSize( wxSize( 200,-1 ) );

	bSizer2->Add( m_slider1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer2->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Przyslona"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer2->Add( m_staticText2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_slider2 = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	m_slider2->SetMinSize( wxSize( 200,-1 ) );

	bSizer2->Add( m_slider2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer2->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticline2 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer2->Add( m_staticline2, 0, wxEXPAND | wxALL, 5 );


	bSizer2->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button3 = new wxButton( this, wxID_ANY, wxT("Reset"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button3->SetMinSize( wxSize( 200,-1 ) );

	bSizer2->Add( m_button3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer2->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button4 = new wxButton( this, wxID_ANY, wxT("Zapis do pliku"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button4->SetMinSize( wxSize( 200,-1 ) );

	bSizer2->Add( m_button4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer2->Add( 0, 0, 1, wxEXPAND, 5 );


	Sizer1->Add( bSizer2, 1, wxEXPAND, 0 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	bSizer3->SetMinSize( wxSize( 800,-1 ) );
	m_panel1 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel1->SetBackgroundColour( wxColour( 234, 234, 234 ) );

	bSizer3->Add( m_panel1, 1, wxEXPAND | wxALL, 0 );


	Sizer1->Add( bSizer3, 3, wxEXPAND, 0 );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	bSizer4->SetMinSize( wxSize( 250,-1 ) );

	bSizer4->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText7 = new wxStaticText( this, wxID_ANY, wxT("Korekcja Gamma"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	bSizer4->Add( m_staticText7, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_slider4 = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	m_slider4->SetMinSize( wxSize( 200,-1 ) );

	bSizer4->Add( m_slider4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer4->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText8 = new wxStaticText( this, wxID_ANY, wxT("Kontrast"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	bSizer4->Add( m_staticText8, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_slider5 = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	m_slider5->SetMinSize( wxSize( 200,-1 ) );

	bSizer4->Add( m_slider5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer4->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText9 = new wxStaticText( this, wxID_ANY, wxT("Jasnosc"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	bSizer4->Add( m_staticText9, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_slider6 = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	m_slider6->SetMinSize( wxSize( 200,-1 ) );

	bSizer4->Add( m_slider6, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer4->Add( 0, 0, 1, wxEXPAND, 5 );


	Sizer1->Add( bSizer4, 1, wxEXPAND, 0 );


	this->SetSizer( Sizer1 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_button1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SymulatorGO::loadImage ), NULL, this );
	m_button2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SymulatorGO::loadDepthMap ), NULL, this );
	m_checkBox1->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( SymulatorGO::mapOn ), NULL, this );
	m_slider1->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SymulatorGO::lensOnScroll ), NULL, this );
	m_slider1->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SymulatorGO::lensOnScroll ), NULL, this );
	m_slider1->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SymulatorGO::lensOnScroll ), NULL, this );
	m_slider1->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SymulatorGO::lensOnScroll ), NULL, this );
	m_slider1->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SymulatorGO::lensOnScroll ), NULL, this );
	m_slider1->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SymulatorGO::lensOnScroll ), NULL, this );
	m_slider1->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SymulatorGO::lensOnScroll ), NULL, this );
	m_slider1->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SymulatorGO::lensOnScroll ), NULL, this );
	m_slider1->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SymulatorGO::lensOnScroll ), NULL, this );
	m_slider2->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SymulatorGO::apertureOnScroll ), NULL, this );
	m_slider2->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SymulatorGO::apertureOnScroll ), NULL, this );
	m_slider2->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SymulatorGO::apertureOnScroll ), NULL, this );
	m_slider2->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SymulatorGO::apertureOnScroll ), NULL, this );
	m_slider2->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SymulatorGO::apertureOnScroll ), NULL, this );
	m_slider2->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SymulatorGO::apertureOnScroll ), NULL, this );
	m_slider2->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SymulatorGO::apertureOnScroll ), NULL, this );
	m_slider2->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SymulatorGO::apertureOnScroll ), NULL, this );
	m_slider2->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SymulatorGO::apertureOnScroll ), NULL, this );
	m_button3->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SymulatorGO::resetImage ), NULL, this );
	m_button4->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SymulatorGO::saveImage ), NULL, this );
	m_panel1->Connect( wxEVT_SIZE, wxSizeEventHandler( SymulatorGO::windowResized ), NULL, this );
	m_panel1->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( SymulatorGO::updateUI ), NULL, this );
	m_slider4->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SymulatorGO::gammaCorrection ), NULL, this );
	m_slider4->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SymulatorGO::gammaCorrection ), NULL, this );
	m_slider4->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SymulatorGO::gammaCorrection ), NULL, this );
	m_slider4->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SymulatorGO::gammaCorrection ), NULL, this );
	m_slider4->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SymulatorGO::gammaCorrection ), NULL, this );
	m_slider4->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SymulatorGO::gammaCorrection ), NULL, this );
	m_slider4->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SymulatorGO::gammaCorrection ), NULL, this );
	m_slider4->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SymulatorGO::gammaCorrection ), NULL, this );
	m_slider4->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SymulatorGO::gammaCorrection ), NULL, this );
	m_slider5->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SymulatorGO::setContrast ), NULL, this );
	m_slider5->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SymulatorGO::setContrast ), NULL, this );
	m_slider5->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SymulatorGO::setContrast ), NULL, this );
	m_slider5->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SymulatorGO::setContrast ), NULL, this );
	m_slider5->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SymulatorGO::setContrast ), NULL, this );
	m_slider5->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SymulatorGO::setContrast ), NULL, this );
	m_slider5->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SymulatorGO::setContrast ), NULL, this );
	m_slider5->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SymulatorGO::setContrast ), NULL, this );
	m_slider5->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SymulatorGO::setContrast ), NULL, this );
	m_slider6->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SymulatorGO::setBrightness ), NULL, this );
	m_slider6->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SymulatorGO::setBrightness ), NULL, this );
	m_slider6->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SymulatorGO::setBrightness ), NULL, this );
	m_slider6->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SymulatorGO::setBrightness ), NULL, this );
	m_slider6->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SymulatorGO::setBrightness ), NULL, this );
	m_slider6->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SymulatorGO::setBrightness ), NULL, this );
	m_slider6->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SymulatorGO::setBrightness ), NULL, this );
	m_slider6->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SymulatorGO::setBrightness ), NULL, this );
	m_slider6->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SymulatorGO::setBrightness ), NULL, this );
}

SymulatorGO::~SymulatorGO()
{
	// Disconnect Events
	m_button1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SymulatorGO::loadImage ), NULL, this );
	m_button2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SymulatorGO::loadDepthMap ), NULL, this );
	m_checkBox1->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( SymulatorGO::mapOn ), NULL, this );
	m_slider1->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SymulatorGO::lensOnScroll ), NULL, this );
	m_slider1->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SymulatorGO::lensOnScroll ), NULL, this );
	m_slider1->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SymulatorGO::lensOnScroll ), NULL, this );
	m_slider1->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SymulatorGO::lensOnScroll ), NULL, this );
	m_slider1->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SymulatorGO::lensOnScroll ), NULL, this );
	m_slider1->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SymulatorGO::lensOnScroll ), NULL, this );
	m_slider1->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SymulatorGO::lensOnScroll ), NULL, this );
	m_slider1->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SymulatorGO::lensOnScroll ), NULL, this );
	m_slider1->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SymulatorGO::lensOnScroll ), NULL, this );
	m_slider2->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SymulatorGO::apertureOnScroll ), NULL, this );
	m_slider2->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SymulatorGO::apertureOnScroll ), NULL, this );
	m_slider2->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SymulatorGO::apertureOnScroll ), NULL, this );
	m_slider2->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SymulatorGO::apertureOnScroll ), NULL, this );
	m_slider2->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SymulatorGO::apertureOnScroll ), NULL, this );
	m_slider2->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SymulatorGO::apertureOnScroll ), NULL, this );
	m_slider2->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SymulatorGO::apertureOnScroll ), NULL, this );
	m_slider2->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SymulatorGO::apertureOnScroll ), NULL, this );
	m_slider2->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SymulatorGO::apertureOnScroll ), NULL, this );
	m_button3->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SymulatorGO::resetImage ), NULL, this );
	m_button4->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SymulatorGO::saveImage ), NULL, this );
	m_panel1->Disconnect( wxEVT_SIZE, wxSizeEventHandler( SymulatorGO::windowResized ), NULL, this );
	m_panel1->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( SymulatorGO::updateUI ), NULL, this );
	m_slider4->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SymulatorGO::gammaCorrection ), NULL, this );
	m_slider4->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SymulatorGO::gammaCorrection ), NULL, this );
	m_slider4->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SymulatorGO::gammaCorrection ), NULL, this );
	m_slider4->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SymulatorGO::gammaCorrection ), NULL, this );
	m_slider4->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SymulatorGO::gammaCorrection ), NULL, this );
	m_slider4->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SymulatorGO::gammaCorrection ), NULL, this );
	m_slider4->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SymulatorGO::gammaCorrection ), NULL, this );
	m_slider4->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SymulatorGO::gammaCorrection ), NULL, this );
	m_slider4->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SymulatorGO::gammaCorrection ), NULL, this );
	m_slider5->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SymulatorGO::setContrast ), NULL, this );
	m_slider5->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SymulatorGO::setContrast ), NULL, this );
	m_slider5->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SymulatorGO::setContrast ), NULL, this );
	m_slider5->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SymulatorGO::setContrast ), NULL, this );
	m_slider5->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SymulatorGO::setContrast ), NULL, this );
	m_slider5->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SymulatorGO::setContrast ), NULL, this );
	m_slider5->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SymulatorGO::setContrast ), NULL, this );
	m_slider5->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SymulatorGO::setContrast ), NULL, this );
	m_slider5->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SymulatorGO::setContrast ), NULL, this );
	m_slider6->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SymulatorGO::setBrightness ), NULL, this );
	m_slider6->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SymulatorGO::setBrightness ), NULL, this );
	m_slider6->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SymulatorGO::setBrightness ), NULL, this );
	m_slider6->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SymulatorGO::setBrightness ), NULL, this );
	m_slider6->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SymulatorGO::setBrightness ), NULL, this );
	m_slider6->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SymulatorGO::setBrightness ), NULL, this );
	m_slider6->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SymulatorGO::setBrightness ), NULL, this );
	m_slider6->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SymulatorGO::setBrightness ), NULL, this );
	m_slider6->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SymulatorGO::setBrightness ), NULL, this );

}
