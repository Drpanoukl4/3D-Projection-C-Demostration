#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

struct vec2D 
{

	double x;
	double y;

};

struct vec3D 
{

	double x;
	double y;
	double z;

};

class Rect : public olc::PixelGameEngine
{
public:
	Rect()
	{
		sAppName = "Rect";
	}

public:

	//FOV
	float fFovFactor = 100.0f;
	vec2D CubeProjectedpoints[ 9 * 9 * 9 ];

	vec3D cubepoints[ 9 * 9 * 9 ];

	int CounterPoints;

	//Here We have to scale by the Fov (Campo  De Vision "View Frustum") becasue our cube is normalized between -1 and 1..
	//With origin in 0..
	//Also have to apply Perspective division formula to have deep
	vec2D CubeProjected ( vec3D p ) 
	{

		return vec2D
		{ 
			p.x * fFovFactor, 
			p.y * fFovFactor 
		};

	}

	bool OnUserCreate() override
	{
		// Called once at the start, so create things here

		for (double x = -1; x <= 1; x += 0.25)
		{
			
			for (double y = -1; y <= 1; y += 0.25)
			{

				for (double z = -1; z <= 1; z += 0.25)
				{

					cubepoints[CounterPoints ++] = vec3D{x, y, z};
					
				}	
			
			}

		}

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{	
		Clear(olc::BLACK);

		// called once per frame
		for (int x = 0; x < ScreenWidth(); x += 15)
			for (int y = 0; y < ScreenHeight(); y += 15)
				Draw(x, y, olc::Pixel(100,100,110));	

		//Proyeccion Ortografica de Puntos
		for (int i = 0; i < 9 * 9 * 9; i ++)
		{

			CubeProjectedpoints[i] = CubeProjected(cubepoints[i]);

		}

		//Drawing of the cube
		//We Have to add the position of the screnn to the th epoint because its origin is now in 0, 0...
		//So now its origin going to be (ScreenWidth() / 2, ScreenHeight() / 2)

		for (int i = 0; i < 9 * 9 * 9; i ++)
		{

			Draw(

				CubeProjectedpoints[i].x  + ScreenWidth() / 2, 
				CubeProjectedpoints[i].y + ScreenHeight() / 2, 
				olc::Pixel(129, 228, 220)
			);

		}

		return true;

	}
};


int main()
{
	Rect demo;
	if (demo.Construct(400, 400, 4, 4))
		demo.Start();

	return 0;
}
