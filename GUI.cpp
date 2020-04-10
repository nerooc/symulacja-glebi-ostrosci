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
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

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

	m_button2 = new wxButton( this, wxID_ANY, wxT("Wczytaj mapę głębokości"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_button2->SetMinSize( wxSize( 200,-1 ) );

	bSizer2->Add( m_button2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


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

	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Przysłona"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer2->Add( m_staticText2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_slider2 = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	m_slider2->SetMinSize( wxSize( 200,-1 ) );

	bSizer2->Add( m_slider2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer2->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText6 = new wxStaticText( this, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	bSizer2->Add( m_staticText6, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_slider3 = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxSize( 200,-1 ), wxSL_HORIZONTAL );
	bSizer2->Add( m_slider3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


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


	Sizer1->Add( bSizer3, 1, wxEXPAND, 0 );

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

	m_staticText9 = new wxStaticText( this, wxID_ANY, wxT("Jasność"), wxDefaultPosition, wxDefaultSize, 0 );
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
}

SymulatorGO::~SymulatorGO()
{
}
