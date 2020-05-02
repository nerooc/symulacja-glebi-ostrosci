#pragma once
#include <wx/wx.h>
/*
Jak tego uzywac?

-ustawianie obrazkow - original i depth(mapa glabe) uzywajac setOrginalImage() i setDepthImage()
	funkcje kopiuja obrazki do pamieci klasy 

-ustawianie parametrow setFocalDistance() (ogniskowa) i setFocalDepth() (glebia ogniskowa - nie wiem jak to poprawnie nazwac), 
	sa jeszcze funkcje get...
	na samym dole jest napisane co parametr robi

-obliczenie finalnego obrazka: wystarczy uzyc calculate_SAT_DOF()
	jezeli rozmiar obrazka z glebia jest rozny od orginalnego obrazka metoda nic nie zrobi

-i mala uwaga na koniec: jezeli NIE zmieniamy oryginalnego obrazka, a tylko parametry zamiast calculate_SAT_DOF() 
	wystarczy uzyc calculateDOF(), nie trzeba liczyc SAT jeszcze raz
*/
class DOF
{
public:
	~DOF();

	void setOriginalImage(const wxImage& img);
	void setDepthImage(const wxImage& img);

	void setFocalDistance(unsigned char dis);	//ogniskowa
	void setFocalDepth(float val);				//glebia ogniskowa

	unsigned char getFocalDistance() const;		//ogniskowa
	float getFocalDepth() const;				//glebia ogniskowa

	float getMaxFocalDepth() const;				//makszymalna glebia ostrosci (zyby nie przesadzic z rozmazaniem)

	void calculate_SAT_DOF();//przelicza SAT a potem wywoluje calculateDOF()
	void calculateDOF();	//updajtuje obraz final, ale nie przelicza SAT!!!!!

	wxImage& getOriginalImg();
	wxImage& getBlurredImg();
	wxImage& getFinalImg();	
	

private:
	void allocateSAT(unsigned int x, unsigned int y);
	void freeSAT();

	void calculateSAT();
	

	wxImage original;
	wxImage depth;
	wxImage blurred;
	wxImage final;

	unsigned int ***SAT = nullptr;
	unsigned int sizeX = 0;
	unsigned int sizeY = 0;

	unsigned char focal_distance = 0;	// ogniskowa - odleglosc w jakiej nalezy ustawic obiekt, aby byl ostry
	float focal_depth = 0.f;			// glebia ogniskowa - szybkosc z jaka obiekty przestaja byc ostre wraz 
												 // z oddalaniem sie od ogniskowej
												 // jak to przetlumaczyc???
	
	const float max_focal_depth = 16.f; //makszymalna glebia ostrosci (zyby nie przesadzic z rozmazaniem)
};

