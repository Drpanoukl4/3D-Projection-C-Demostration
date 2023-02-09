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

    //FOV
	float fFovFactor = 200.0f;
	vec2D CubeProjectedpoints[ 9 * 9 * 9 ];

	vec3D cubepoints[ 9 * 9 * 9 ];

	//CAMERA
	vec3D CameraPos = {0, 0 , - 5};

	float fTheta; 

	int CounterPoints;

	//Here We have to scale by the Fov (Campo  De Vision "View Frustum") becasue our cube is normalized between -1 and 1..
	//With origin in 0..
	//Also have to apply Perspective division formula to have deep
	vec2D CubeProjected ( vec3D p ) 
	{

		return vec2D
		{ 
			(p.x * fFovFactor) / p.z, 
			(p.y * fFovFactor) / p.z
		};

	}

	void RotateX(float fAngle, vec3D p, vec3D &o)
	{

		double newY = p.y * cosf(fAngle) - p.z * sinf(fAngle); 
		double newZ = p.y * sinf(fAngle) + p.z * cosf(fAngle);

		o.y = newY;
		o.z = newZ;


	}

	void RotateY(float fAngle, vec3D p , vec3D &o)
	{

		double newX = p.x * cosf(fAngle) - p.z * sinf(fAngle); 
		double newZ = p.x * sinf(fAngle) + p.z * cosf(fAngle);

		o.x = newX;
		o.z = newZ;


	}

	void RotateZ(float fAngle, vec3D p, vec3D &o)
	{

		double newX = p.x * cosf(fAngle) - p.y * sinf(fAngle); 
		double newY = p.x * sinf(fAngle) + p.y * cosf(fAngle);

		o.x = newX;
		o.y = newY;


	}
