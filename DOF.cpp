#include "DOF.h"
#include <cmath>

#define iter(i,j) (i*sizeX+ j)*3


DOF::~DOF()
{
	freeSAT();
}

void DOF::setOriginalImage(const wxImage& img)
{
	original = img;
}

void DOF::setDepthImage(const wxImage& img)
{
	depth = img;
}

void DOF::updateFinalImage()
{
	if (original.GetSize().x != depth.GetSize().x || original.GetSize().y != depth.GetSize().y)
	{
		std::cout << "DOF: updateFinalImage: originalIMG i depthIMG maja rozne wymiary!" << std::endl;
		return;
	}

	unsigned int x = original.GetSize().x;
	unsigned int y = original.GetSize().y;

	if (x != sizeX || y != sizeY) {
		freeSAT();
		allocateSAT(x, y);
	}
	calculateSAT();
	calculateDOF();
}

void DOF::setFocalDistance(unsigned char dis)
{
	focal_distance = dis;
}

void DOF::setFocalDepth(float val)
{
	focal_depth = val;
}

wxImage& DOF::getOriginalImg()
{
	return original;
}

wxImage& DOF::getFinalImg()
{
	return final;
}

void DOF::allocateSAT(unsigned int x, unsigned int y)
{
	if (SAT != nullptr)
		freeSAT();

	sizeX = x;
	sizeY = y;

	SAT = new unsigned int** [sizeX];

	for (int i = 0; i < sizeX; i++)
	{
		SAT[i] = new unsigned int* [sizeY];

		for (int j = 0; j < sizeY; j++)
			SAT[i][j] = new unsigned int[3];
	}
}

void DOF::freeSAT()
{
	if (!SAT)	return;

	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY; j++)
			delete[] SAT[i][j];

		delete[] SAT[i];
	}
	delete[] SAT;
	SAT = nullptr;
	sizeX = 0;
	sizeY = 0;
}

void DOF::calculateSAT()
{
	unsigned char* data = original.GetData();

	for (unsigned int y = 0; y < sizeY; ++y)
	{
		for (unsigned int x = 0; x < sizeX; ++x)
		{
			unsigned int valueX = data[iter(y, x)];
			unsigned int valueY = data[iter(y, x) + 1];
			unsigned int valueZ = data[iter(y, x) + 2];
			if (y > 0) {
				valueX += SAT[x][y - 1][0]; 
				valueY += SAT[x][y - 1][1];
				valueZ += SAT[x][y - 1][2];
			}
			if (x > 0) {
				valueX += SAT[x - 1][y][0];
				valueY += SAT[x - 1][y][1];
				valueZ += SAT[x - 1][y][2];
			}
			if (x > 0 && y > 0) {
				valueX -= SAT[x - 1][y - 1][0];
				valueY -= SAT[x - 1][y - 1][1];
				valueZ -= SAT[x - 1][y - 1][2];
			}
			SAT[x][y][0] = valueX;
			SAT[x][y][1] = valueY;
			SAT[x][y][2] = valueZ;
		}
	}
}

int clamp(int x, int minVal, int maxVal) {
	return std::min(std::max(x, minVal), maxVal);
}

void DOF::calculateDOF()
{
	final.Create(sizeX, sizeY);

	unsigned char* depthData = depth.GetData();
	unsigned char* finalData = final.GetData();

	for (int i = 0; i < sizeY; i++)
	{
		for (int j = 0; j < sizeX; j++) {


			// r - "promien" filtra,	"promien" bo filtra bedzie kwadratem, a nie kolem
			float r; 

			r = fabs(depthData[iter(i, j)] - focal_distance) / 255. * focal_depth;

			//	!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			//r = ceil(r);	
			//r = floor(r);
			r = round(r);
			//	!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			

			wxPoint P0;
			wxPoint P1;
			wxPoint P2;
			wxPoint P3;

			unsigned int square;
			unsigned int sideX, sideY;

			if (r == 0) {

				if (i == 0 || j == 0) {
					if (i == 0 && j == 0) {
						finalData[iter(i, j)] = SAT[0][0][0];
						finalData[iter(i, j) + 1] = SAT[0][0][1];
						finalData[iter(i, j) + 2] = SAT[0][0][2];
					}
					else if (i == 0) {
						finalData[iter(i, j)] = SAT[j][0][0] - SAT[j - 1][0][0];
						finalData[iter(i, j) + 1] = SAT[j][0][1] - SAT[j - 1][0][1];
						finalData[iter(i, j) + 2] = SAT[j][0][2] - SAT[j - 1][0][2];

					}
					else if (j == 0) {
						finalData[iter(i, j)] = SAT[0][i][0] - SAT[0][i-1][0];
						finalData[iter(i, j) + 1] = SAT[0][i][1] - SAT[0][i - 1][1];
						finalData[iter(i, j) + 2] = SAT[0][i][2] - SAT[0][i - 1][2];
					}
					continue;
				}
				else {
					P0 = wxPoint(clamp(j - 1, 0, sizeY - 1), clamp(i - 1, 0, sizeY - 1));
					P1 = wxPoint(clamp(j - 1, 0, sizeX - 1), i);
					P2 = wxPoint(j, clamp(i - 1, 0, sizeY - 1));
					P3 = wxPoint(j, i);
					square = 1;
				}
			}
			else
			{
				P0 = wxPoint(clamp(j - r, 0, sizeX - 1), clamp(i - r, 0, sizeY - 1));
				P1 = wxPoint(clamp(j - r, 0, sizeX - 1), clamp(i + r, 0, sizeY - 1));
				P2 = wxPoint(clamp(j + r, 0, sizeX - 1), clamp(i - r, 0, sizeY - 1));
				P3 = wxPoint(clamp(j + r, 0, sizeX - 1), clamp(i + r, 0, sizeY - 1));

				sideX = P3.x - P0.x;    sideX = sideX == 0 ? 1 : sideX;
				sideY = P3.y - P0.y;    sideY = sideY == 0 ? 1 : sideY;
				square = sideX * sideY;
			}


			unsigned int a[3]{ SAT[P0.x][P0.y][0], SAT[P0.x][P0.y][1], SAT[P0.x][P0.y][2] };
			unsigned int b[3]{ SAT[P1.x][P1.y][0], SAT[P1.x][P1.y][1], SAT[P1.x][P1.y][2] };
			unsigned int c[3]{ SAT[P2.x][P2.y][0], SAT[P2.x][P2.y][1], SAT[P2.x][P2.y][2] };
			unsigned int d[3]{ SAT[P3.x][P3.y][0], SAT[P3.x][P3.y][1], SAT[P3.x][P3.y][2] };

			
			unsigned int sum[3] = {
				a[0] - b[0] - c[0] + d[0],
				a[1] - b[1] - c[1] + d[1],
				a[2] - b[2] - c[2] + d[2]
			};

			// Dzielenie przez obszar.
			sum[0] = round(static_cast<float>(sum[0]) / square);
			sum[1] = round(static_cast<float>(sum[1]) / square);
			sum[2] = round(static_cast<float>(sum[2]) / square);

			

			// Przekazanie finalnego koloru.
			unsigned char color[3]{
				sum[0] > 255 ? 255 : sum[0],
				sum[1] > 255 ? 255 : sum[1],
				sum[2] > 255 ? 255 : sum[2]
			};

			finalData[iter(i, j)] = color[0];
			finalData[iter(i, j) + 1] = color[1];
			finalData[iter(i, j) + 2] = color[2];
		}
	}
}
