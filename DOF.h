#pragma once
#include <wx/wx.h>

class DOF
{
public:
	~DOF();

	void setOriginalImage(const wxImage& img);
	void setDepthImage(const wxImage& img);

	void updateFinalImage();

	void setFocalDistance(unsigned char dis);	//ogniskowa
	void setFocalDepth(float val);				//glebia ogniskowa

	wxImage& getOriginalImg();
	wxImage& getFinalImg();

private:
	void allocateSAT(unsigned int x, unsigned int y);
	void freeSAT();
	void calculateSAT();
	void calculateDOF();

	wxImage original;
	wxImage depth;
	wxImage final;

	unsigned int ***SAT = nullptr;
	unsigned int sizeX = 0;
	unsigned int sizeY = 0;

	unsigned char focal_distance = 0;	// ogniskowa - odleglosc w jakiej nalezy ustawic obiekt, aby byl ostry
	float focal_depth = 14.f;			// glebia ogniskowa - szybkosc z jaka obiekty przestaja byc ostre wraz 
												 // z oddalaniem sie od ogniskowej
};

