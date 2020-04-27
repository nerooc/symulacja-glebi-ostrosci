#include "SimGOSymulatorGO.h"

SimGOSymulatorGO::SimGOSymulatorGO( wxWindow* parent )
:
SymulatorGO( parent )
{

	panelHeight = m_panel1->GetSize().GetHeight();
	panelWidth = m_panel1->GetSize().GetWidth();

	translationX = 0;
	translationY = 0;

	m_slider1->SetValue(0);
	m_slider2->SetValue(50);

	m_slider1->Disable();
	m_slider2->Disable();

	dof.setFocalDistance(m_slider1->GetValue() / 100. * 255);
	dof.setFocalDepth(m_slider2->GetValue() / 100. * dof.getMaxFocalDepth());

	depthMapOn = false;

}

void SimGOSymulatorGO::loadImage( wxCommandEvent& event )
{
	// TODO: Implement loadImage

	depthScaledMap.Destroy();

	translationX = 0;
	translationY = 0;

	wxImage img;
	wxImage scaledImage;

	img.AddHandler(new wxJPEGHandler);
	img.AddHandler(new wxPNGHandler);

	//DOLACZANIE PLIKU PRZEZ WXFILEDIALOG///////////////////////////////////////////////////////////////////////////////////////
	wxFileDialog WxOpenFileDialog(this, wxT("Wybierz obraz:"), wxT(""), wxT(""), wxT("JPG file (*.jpg)|*.jpg|PNG file (*.png) |*.png"), wxFD_OPEN | wxFD_FILE_MUST_EXIST);

	if (WxOpenFileDialog.ShowModal() == wxID_OK) {

		if (img.LoadFile(WxOpenFileDialog.GetPath())) {
			img.LoadFile(WxOpenFileDialog.GetPath());

			depthMap.Destroy();
			mainImage = img;

			double imgHeight = imageHeight = img.GetSize().GetHeight();
			double imgWidth = imageWidth = img.GetSize().GetWidth();

			if (imgHeight > imgWidth) {
				double ratio = imgWidth / imgHeight;
				scaledImage = img.Scale(panelHeight * ratio, panelHeight);
				translationX = (panelWidth - scaledImage.GetSize().GetWidth()) / 2;
			}
			else {
				double ratio = imgHeight / imgWidth;
				scaledImage = img.Scale(panelWidth, panelWidth * ratio);
				translationY = (panelHeight - scaledImage.GetSize().GetHeight()) / 2;
			}

				

		} else {

		wxMessageBox(_("ERROR - Plik nie mogl zostac zaladowany"));

		}

		
	}
	mainScaledImage = scaledImage;
	dof.setOriginalImage(mainScaledImage);
	Repaint();

}

void SimGOSymulatorGO::loadDepthMap( wxCommandEvent& event )
{
	// TODO: Implement loadDepthMap
	wxImage img;
	wxImage scaledImage;

	img.AddHandler(new wxJPEGHandler);
	img.AddHandler(new wxPNGHandler);

	wxFileDialog WxOpenFileDialog(this, wxT("Wybierz mape glebii:"), wxT(""), wxT(""), wxT("JPG file (*.jpg)|*.jpg|PNG file (*.png) |*.png"), wxFD_OPEN | wxFD_FILE_MUST_EXIST);

	if (mainScaledImage.IsOk()) {

	if (WxOpenFileDialog.ShowModal() == wxID_OK) {

		if (img.LoadFile(WxOpenFileDialog.GetPath())) {
			img.LoadFile(WxOpenFileDialog.GetPath());

			depthMap = img;

			double imgHeight = img.GetSize().GetHeight();
			double imgWidth = img.GetSize().GetWidth();


			

				if ((imgHeight != imageHeight) && (imgWidth != imageWidth)) {

					wxMessageBox(_("ERROR - Zla mapa glebokosci (rozmiary sie nie pokrywaja)"));
					img.Destroy();
					depthScaledMap.Destroy();

				}
				else {

					if (imgHeight > imgWidth) {

						double ratio = imgWidth / imgHeight;
						scaledImage = img.Scale(panelHeight * ratio, panelHeight);
						translationX = (panelWidth - scaledImage.GetSize().GetWidth()) / 2;

					}
					else {

						double ratio = imgHeight / imgWidth;
						scaledImage = img.Scale(panelWidth, panelWidth * ratio);
						translationY = (panelHeight - scaledImage.GetSize().GetHeight()) / 2;

					}

				}
			
		} else {

		wxMessageBox(_("ERROR - Plik nie mogl zostac zaladowany"));

		}

		
		depthScaledMap = scaledImage;
		dof.setDepthImage(depthScaledMap);
		dof.calculate_SAT_DOF();

		wxMessageBox(_("Mapa zaladowana pomyslnie!"));


		Repaint();

	}


	}
	else {
		wxMessageBox(_("ERROR - Najpierw wczytaj zdjecie"));

	}
}

void SimGOSymulatorGO::mapOn( wxCommandEvent& event )
{
// TODO: Implement mapOn
depthMapOn = event.IsChecked();
m_slider1->Enable(depthMapOn);
m_slider2->Enable(depthMapOn);

if (depthMapOn) {
m_button1->Disable();
m_button2->Disable();
}
else {
m_button1->Enable();
m_button2->Enable();
}
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
m_slider1->SetValue(0);
m_slider2->SetValue(50);

dof.setFocalDistance(m_slider1->GetValue() / 100. * 255);
dof.calculateDOF();

dof.setFocalDepth(m_slider2->GetValue() / 100. * dof.getMaxFocalDepth());
dof.calculateDOF();
}

void SimGOSymulatorGO::saveImage( wxCommandEvent& event )
{
	if (dof.getFinalImg().IsOk()) 
	{
		wxTextEntryDialog* textEntry = new wxTextEntryDialog(this, "Podaj nazwê pliku");
		textEntry->ShowModal();
	
		std::string fileName;
		while (textEntry) 
		{
			if (!textEntry->IsActive()) 
			{
				fileName = textEntry->GetValue();
				delete textEntry;
				textEntry = nullptr;
			}
		}

		dof.getFinalImg().SaveFile(fileName + ".bmp");
	}
	else 
	{
		wxMessageDialog* message = new wxMessageDialog(this, "za³aduj obraz");
		message->ShowModal();

		while (message) 
		{
			if (!message->IsActive()) 
			{
				delete message;
				message = nullptr;
			}
		}
	}
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


void SimGOSymulatorGO::Repaint()
{
	wxClientDC DC(m_panel1);
	wxBufferedDC dc(&DC);
	dc.Clear();

	if (m_checkBox1->IsChecked() && dof.getFinalImg().IsOk())
		dc.DrawBitmap(dof.getFinalImg(), translationX, translationY);
	else if (!m_checkBox1->IsChecked() && dof.getOriginalImg().IsOk())
		dc.DrawBitmap(dof.getOriginalImg(), translationX, translationY);

	dc.DrawText("ogniskowa: " + std::to_string(dof.getFocalDistance()), 10, 10);
	dc.DrawText("przyslona: " + std::to_string(dof.getFocalDepth()), 10, 30);

}