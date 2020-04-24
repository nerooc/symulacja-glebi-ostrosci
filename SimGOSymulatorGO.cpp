#include "SimGOSymulatorGO.h"
#include <string>

SimGOSymulatorGO::SimGOSymulatorGO( wxWindow* parent )
:
SymulatorGO( parent )
{
	m_slider1->SetValue(0);
	m_slider2->SetValue(50);
	dof.setFocalDistance(m_slider1->GetValue() / 100. * 255);
	dof.setFocalDepth(m_slider2->GetValue() / 100. * dof.getMaxFocalDepth());

}

void SimGOSymulatorGO::Repaint()
{
	wxClientDC dc(m_panel1);

	if (m_checkBox1->IsChecked() && dof.getFinalImg().IsOk())
		dc.DrawBitmap(dof.getFinalImg(), 0, 0);
	else if(!m_checkBox1->IsChecked() && dof.getOriginalImg().IsOk())
		dc.DrawBitmap(dof.getOriginalImg(), 0, 0);

	dc.DrawText("ogniskowa: " + std::to_string(dof.getFocalDistance()), 10, 10);
	dc.DrawText("przyslona: " + std::to_string(dof.getFocalDepth()), 10, 30);
		
}

void SimGOSymulatorGO::loadImage( wxCommandEvent& event )
{
// TODO: Implement loadImage
	wxImage img;
	img.AddHandler(new wxJPEGHandler);
	img.AddHandler(new wxPNGHandler);
	img.LoadFile("Flowers-alternative.jpg");
	dof.setOriginalImage(img);
	Repaint();
}

void SimGOSymulatorGO::loadDepthMap( wxCommandEvent& event )
{
// TODO: Implement loadDepthMap
	wxImage img;
	img.AddHandler(new wxJPEGHandler);
	img.AddHandler(new wxPNGHandler);
	img.LoadFile("Flowers-depthmap.jpg");
	dof.setDepthImage(img);
	dof.calculate_SAT_DOF();
	Repaint();
}

void SimGOSymulatorGO::mapOn( wxCommandEvent& event )
{
// TODO: Implement mapOn
}

void SimGOSymulatorGO::lensOnScroll( wxScrollEvent& event )
{
// TODO: Implement lensOnScroll
	dof.setFocalDistance(m_slider1->GetValue() / 100. * 255);
	dof.calculateDOF();
}

void SimGOSymulatorGO::apertureOnScroll( wxScrollEvent& event )
{
// TODO: Implement apertureOnScroll
	dof.setFocalDepth(m_slider2->GetValue() / 100. * dof.getMaxFocalDepth());
	dof.calculateDOF();
}

void SimGOSymulatorGO::resetImage( wxCommandEvent& event )
{
// TODO: Implement resetImage
}

void SimGOSymulatorGO::saveImage( wxCommandEvent& event )
{
// TODO: Implement saveImage
}

void SimGOSymulatorGO::windowResized( wxSizeEvent& event )
{
// TODO: Implement windowResized
}

void SimGOSymulatorGO::updateUI( wxUpdateUIEvent& event )
{
// TODO: Implement updateUI
	Repaint();
}

void SimGOSymulatorGO::gammaCorrection( wxScrollEvent& event )
{
// TODO: Implement gammaCorrection
}

void SimGOSymulatorGO::setContrast( wxScrollEvent& event )
{
// TODO: Implement setContrast
}

void SimGOSymulatorGO::setBrightness( wxScrollEvent& event )
{
// TODO: Implement setBrightness
}
