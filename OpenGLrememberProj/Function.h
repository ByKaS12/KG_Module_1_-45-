#pragma once
#include <vector>
using std::vector;
void taskONe(double A[], double B[], double C[]) {
	glBegin(GL_LINES);

	glVertex3dv(A);
	glVertex3dv(B);

	glVertex3dv(B);
	glVertex3dv(C);

	glVertex3dv(C);
	glVertex3dv(A);


	glEnd();

}
double* FindNormal(double T1[], double T2[], double T3[]) {
	double A[] = { T2[0] - T1[0],T2[1] - T1[1] ,T2[2] - T1[2] };
	double B[] = { T3[0] - T1[0],T3[1] - T1[1] ,T3[2] - T1[2] };
	double* array = new double[3];
	array[0] = (A[1] * B[2]) - (B[1] * A[2]);
	array[1] = (-(A[0] * B[2])) + (B[0] * A[2]);
	array[2] = (A[0] * B[1]) - (B[0] * A[1]);
	return array;

}
void createQuad(double A[], double B[], double C[], double D[], double color[]) {
	glBegin(GL_QUADS);
	glColor3dv(color);
	glVertex3dv(A);
	glVertex3dv(B);
	glVertex3dv(C);
	glVertex3dv(D);
	glEnd();

}
void taskFour(double A[], double B[], double C[]) {
	glBegin(GL_TRIANGLES);
	glVertex3dv(A);
	glColor3d(0.7, 0.2, 0.4);
	glVertex3dv(B);
	glColor3d(0.7, 0.2, 0);
	glVertex3dv(C);
	glColor3d(0.3, 0.1, 0.8);
	glEnd();

}
void taskFive(int i) {
	if (i == 0) {
		double A[] = { 1, 1, 0 };
		double B[] = { -1, 1, 0 };
		double C[] = { -1,-1, 0 };
		double D[] = { 1,-1, 0 };
		glBegin(GL_QUADS);
		glColor3d(0.2, 0.7, 0.7);
		glVertex3dv(A);
		glVertex3dv(B);
		glVertex3dv(C);
		glVertex3dv(D);
		glEnd();
	}
	else {
		double A[] = { 1, 1, 1 };
		double B[] = { -1, 1, 1 };
		double C[] = { -1,-1, 1 };
		double D[] = { 1,-1, 1 };
		glBegin(GL_QUADS);
		glColor3d(0.2, 0.7, 0.7);
		glVertex3dv(A);
		glVertex3dv(B);
		glVertex3dv(C);
		glVertex3dv(D);
		glEnd();
	}


}
void point50(double z, vector <GLfloat>& X, vector <GLfloat>& Y);
void vectorSum(vector <GLfloat> &X, vector <GLfloat> &Y,int z) {
	float x = 0.1f;
	float y = 0.04f;
	float deltaX = 0.1f;
	float deltaY = 0.04f;
	if (z==0)
	{
		double copyA[3] = { 6 - 2.21429f,0 + 0.64286f,z };
		double copyB[3] = { 1 - 2.21429f,3 + 0.64286f,z };
		double copyC[3] = { 2 - 2.21429f,7 + 0.64286f,z };
		double copyD[3] = { 6 - 2.21429f,5 + 0.64286f,z };
		for (int i = 0; i < X.size(); i++)
		{
			X[i] = copyD[0] - x;
			Y[i] = copyD[1] - y;
			x += deltaX;
			y += deltaY;
		}
	}
	else {
		double copyA[3] = { 6 - 2.21429f,0 + 0.64286f,z };
		double copyB[3] = { 1 - 2.21429f,3 + 0.64286f,z };
		double copyC[3] = { 2 - 2.21429f,7 + 0.64286f,z };
		double copyD[3] = { 6 - 2.21429f,5 + 0.64286f,z };
		for (int i = 0; i < X.size(); i++)
		{
			X[i] = copyD[0] - x;
			Y[i] = copyD[1] - y;
			x += deltaX;
			y += deltaY;
		}
	}
}
void createPolygon(double color[],int z) {
	vector <GLfloat> X(15), Y(15);
	vector <GLfloat> X2(50), Y2(50);
	point50(z, X, Y);
	vectorSum(X2,Y2,z);
	double array[3];
	double xy[3];
	double xy2[3];
	double array2[3];
	float x = 0.1f, y = 0.04f;
	float deltaX = 0.1f;
	float deltaY = 0.04f;
	if (z == 0) {
		double C[3] = { 6 - 2.21429f,5 + 0.64286f,z };
		double A[3] = { 1 - 2.21429f,3 + 0.64286f,z };
		double B[3] = { 2 - 2.21429f,7 + 0.64286f,z };
		double copyA[3] = { 6 - 2.21429f,0 + 0.64286f,z };
		double copyD[3] = { 6 - 2.21429f,5 + 0.64286f,z };
		glPushMatrix();
		glTranslatef(2.21429f, -0.64286f, 0.0f);
		for (int j = 0; j < X.size(); j++)
		{

			array[0] = X[j];
			array[1] = Y[j];
			array[2] = z;
			xy[0] = X2[j];
			xy[1] = Y2[j];
			xy[2] = z;
			if(j==0)
				createQuad(array, xy, copyD, copyA, color);
			else {
				array2[0] = X[j-1];
				array2[1] = Y[j-1];
				array2[2] = z;
				xy2[0] = X2[j-1];
				xy2[1] = Y2[j-1];
				xy2[2] = z;
				createQuad(array, xy, xy2, array2, color);
			}
		}
		taskFour(A, B, C);
		glPopMatrix();
	}
	else {
		double C[3] = { 6 - 2.21429f,5 + 0.64286f,z };
		double A[3] = { 1 - 2.21429f,3 + 0.64286f,z };
		double B[3] = { 2 - 2.21429f,7 + 0.64286f,z };
		double copyA[3] = { 6 - 2.21429f,0 + 0.64286f,z };
		double copyD[3] = { 6 - 2.21429f,5 + 0.64286f,z };
		glPushMatrix();
		glTranslatef(2.21429f, -0.64286f, 0.0f);
		for (int j = 0; j < X.size(); j++)
		{

			array[0] = X[j];
			array[1] = Y[j];
			array[2] = z;
			xy[0] = X2[j];
			xy[1] = Y2[j];
			xy[2] = z;
			if (j == 0)
				createQuad(array, xy, copyD, copyA, color);
			else {
				array2[0] = X[j - 1];
				array2[1] = Y[j - 1];
				array2[2] = z;
				xy2[0] = X2[j - 1];
				xy2[1] = Y2[j - 1];
				xy2[2] = z;
				createQuad(array, xy, xy2, array2, color);
			}
		}
		taskFour(A, B, C);
		glPopMatrix();
	}
}
void createTriangle(double A[], double B[], double C[], double color[]) {
	glBegin(GL_TRIANGLES);
	glColor3dv(color);
	glVertex3dv(A);
	glVertex3dv(B);
	glVertex3dv(C);

	glEnd();


}
void DrawCircle(double r, int num_segments, float z,vector <GLfloat> &X, vector <GLfloat>& Y, vector <GLfloat>& X2, vector <GLfloat>& Y2) {
	float x = 0.0f;
	float y = 0.0f;
	float prevX = x;
	float prevY = y - float(r);
	float floatR = float(r);
	int i=0;
	glBegin(GL_TRIANGLES);
	glColor3f(sin(z), sin(z), cos(z));
	for (int ii = 0; ii <= num_segments; ii++) {
		float theta = 3.1415926f * float(ii) / float(num_segments);

		float newX = floatR * sin(theta);
		float newY = -floatR * cos(theta);
		glBegin(GL_TRIANGLES);
		if(z==0.0f)
		glNormal3f(0,0,-1);
		else
			glNormal3f(0, 0, 1);
		glVertex3d(0, 0, z);
		glVertex3d(prevX, prevY, z);
		if (i == X.size() || i == Y.size() || i == X2.size() || i == Y2.size())
		{
			X.resize(X.size() + 1);
			Y.resize(Y.size() + 1);
			X2.resize(X.size() + 1);
			Y2.resize(Y.size() + 1);
		}
		X[i] = prevX;
		Y[i] = prevY;
		glVertex3d(newX, newY, z);
		X2[i] = newX;
		Y2[i] = newY;
		glEnd();
		prevX = newX;
		prevY = newY;
		i++;
	}

}

void taskSix() {

	//
	double A[] = { -1, 1, 0 };
	double B[] = { -1, 1, 1 };
	double C[] = { 1, 1, 1 };
	double D[] = { 1,1, 0 };
	double color1[] = { 0.1,0.2,0,3 };
	//

	//
	double revA[] = { 1, -1, 0 };
	double revB[] = { 1, -1, 1 };
	double revC[] = { -1, -1, 1 };
	double revD[] = { -1,-1, 0 };
	double color2[] = { 0.2,0.4,0.7 };
	//
	double color3[] = { 0.1,0.1,0.2 };
	double color4[] = { 0.5,0.3,0.9 };
	taskFive(0);
	createQuad(A, B, C, D, color1);
	createQuad(revA, revB, revC, revD, color2);
	createQuad(revA, revB, C, D, color3);
	createQuad(A, B, revC, revD, color4);
	taskFive(1);
	double Zero[] = { 0,0,3 };

	taskFour(B, C, Zero);
	taskFour(revB, C, Zero);
	taskFour(B, revC, Zero);
	taskFour(revB, revC, Zero);

}

void taskFinnaly() {
	double A[] = { 1, -2, 3 };
	double B[] = { -4, 5, 8 };
	double C[] = { 1,2,3 };


	//taskONe(A, B, C);
	//taskFour(A, B, C);
	double angle = 7.2;
	for (int i = 0; i < 50; i++)
	{


		glPushMatrix();
		glRotated(angle, 0, 0, 1);
		glTranslated(0, 100, 0);
		glRotated(angle, 1, 0, 0);
		glScaled(5, 5, 5);
		taskSix();

		glPopMatrix();
		angle += 7.2;


	}
}
void Side4() {
	vector <GLfloat> X(15);
	vector <GLfloat> Y(15);
	vector <GLfloat> X2(15);
	vector <GLfloat> Y2(15);
	double A[3];
	double B[3];
	double C[3];
	double D[3];
	float delta = 0.016f;
	glPushMatrix();
	glTranslated(10, 10, 0);
	glRotated(90, 0, 0, 10);
	double r = 2;
	int num_segments = 60;
	DrawCircle(r, num_segments, 0, X, Y, X2, Y2);
	DrawCircle(r, num_segments, 3, X, Y, X2, Y2);
	for (int i = 0; i < X.size(); i++)
	{
		A[0] = X[i];
		A[1] = Y[i];
		A[2] = 0;
		B[0] = X[i];
		B[1] = Y[i];
		B[2] = 3;
		C[0] = X2[i];
		C[1] = Y2[i];
		C[2] = 3;
		D[0] = X2[i];
		D[1] = Y2[i];
		D[2] = 0;
		double color[3] = { acosf(X[i]),asinf(Y[i]),tanf(X[i] + Y[i]) };
		glNormal3dv(FindNormal(A, D, B));
		//createQuad(A, B, C, D, color);
		glBegin(GL_QUADS);
		glColor3dv(color);
		glTexCoord2d(1 - delta, 0);
		glVertex3dv(A);
		glTexCoord2d(1 - delta, 1);
		glVertex3dv(B);
		glTexCoord2d(1 - delta - 0.016f, 1);
		glVertex3dv(C);
		glTexCoord2d(1 - delta - 0.016f, 0);
		glVertex3dv(D);
		glEnd();
		delta += 0.016f;

	}
	glPopMatrix();
}
void labTwo() {
	double z = 0;
	double A1[] = { 1,3,z };////
	double B1[] = { 1,10,z };
	double C12[] = { 2,7,z };/////
	double color[] = { 0.2,0.3,0.5 };
	glNormal3d(0, 0, -1);
	createTriangle(A1, B1, C12, color);
	double B2[] = { 6,5,z };/////
	double A2[] = { 5,12,z };
	createTriangle(C12, B2, A2, color);
	double D1[] = { 6,0,z };////
	//glBegin(GL_POLYGON);
	//point50(0);
	//glVertex3dv(C12);
	//glVertex3dv(B2);
	//glVertex3dv(D1);

	//glEnd();
	createPolygon(color,z);/////////
	double C3[] = { 8,10,z };
	double D3[] = { 12,10,z };
	createQuad(D1, B2, C3, D3, color);
	z = 3;
	double A13[] = { 1,3,z };
	double B13[] = { 1,10,z };
	double C123[] = { 2,7,z };
	glNormal3d(0, 0, 1);
	createTriangle(A13, B13, C123, color);
	double B23[] = { 6,5,z };
	double A23[] = { 5,12,z };
	createTriangle(C123, B23, A23, color);
	double D13[] = { 6,0,z };
	createPolygon(color,z);
	double C33[] = { 8,10,z };
	double D33[] = { 12,10,z };
	createQuad(D13, B23, C33, D33, color);
	double color1[] = { 0.7,0.5,0.3 };
	glNormal3dv(FindNormal(B1, A1, B13));
	createQuad(A1, B1, B13, A13, color1);
	//
	glNormal3dv(FindNormal(C12, B1, C123));
	createQuad(C12, B1, B13, C123, color1);
	//
	glNormal3dv(FindNormal(A2, C12, C123));
	createQuad(C12, C123, A23, A2, color1);
	//
	glNormal3dv(FindNormal(B2, A2, B23));
	createQuad(A2, A23, B23, B2, color1);
	//
	glNormal3dv(FindNormal(C3, B2, C33));
	createQuad(B2, B23, C33, C3, color1);

	Side4();


	glNormal3dv(FindNormal(D3, D13, D1));
	createQuad(D3, D33, D13, D1, color1);



}

void point50(double z, vector <GLfloat> &X, vector <GLfloat> &Y ) {
	//glTranslatef(2.21429f, -0.64286f, 0.0f);
	GLfloat theta;
	GLfloat pi = acos(-1.0);
	GLfloat radius = 3.84f; // радиус
	GLfloat step = 1.0f; // чем больше шаг тем хуже диск
	int i = 0;
		for (GLfloat a = 5.0f; a < 55.0f; a += step) {
			theta = 2.0f * pi * a / 180.0f;
			//glColor4f(a / 360.0f, 1.0f, 1.0f - a / 360.0f, 1.0f);
			//glVertex3f(radius * cos(theta), radius * sin(theta), z);
			if (i == X.size() || i == Y.size())
			{
				X.resize(X.size() + 1);
				Y.resize(Y.size() + 1);
			}
			X[i] = radius * cos(theta);
			Y[i] = radius * sin(theta);
			i++;

		}


}
void Side3() {	
	vector <GLfloat> X(50);
	vector <GLfloat> Y(50);
	vector <GLfloat> X2(5);
	vector <GLfloat> Y2(5);
	double A[3];
	double B[3];
	double C[3];
	double D[3];
	float delta = 0.02f;
	glPushMatrix();
	glTranslatef(2.21429f, -0.64286f, 0.0f);
	point50(0.0,X,Y);
	point50(3.0, X2, Y2);
	for (int i = 0; i < X.size()-1; i++)
	{
			A[0] = X[i];
			A[1] = Y[i];
			A[2] = 0;
			B[0] = X[i];
			B[1] = Y[i];
			B[2] = 3;
			C[0] = X[i+1];
			C[1] = Y[i+1];
			C[2] = 3;
			D[0] = X[i+1];
			D[1] = Y[i+1];
			D[2] = 0;
			
			double color[3] = { acosf(X[i]),asinf(Y[i]),tanf(X[i+1]+Y[i+1])};
			glNormal3dv(FindNormal(B, D, A));
				glBegin(GL_QUADS);
				glColor3dv(color);
				glTexCoord2d(1-delta, 0);
				glVertex3dv(A);
				glTexCoord2d(1-delta, 1);
				glVertex3dv(B);
				glTexCoord2d(1 -delta - 0.02f, 1);
				glVertex3dv(C);
				glTexCoord2d(1 -delta- 0.02f, 0);
				glVertex3dv(D);
				glEnd();	
				delta += 0.02f;
	}

	double copyA[3] = {6- 2.21429f,0+0.64286f,0};
	double copyB[3] = { 6 - 2.21429f,0 + 0.64286f,3 };
	double copyC[3] = { X[0],Y[0],3 };
	double copyD[3] = { X[0],Y[0],0 };
	double color[3] = { 0,0,1 }; 
	glNormal3dv(FindNormal(copyB, copyD, copyA));
	//createQuad(copyA, copyB, copyC, copyD, color);
	glBegin(GL_QUADS);
	glColor3dv(color);
	glTexCoord2d(1, 0);
	glVertex3dv(copyA);
	glTexCoord2d(1, 1);
	glVertex3dv(copyB);
	glTexCoord2d(1 - 0.02f, 1);
	glVertex3dv(copyC);
	glTexCoord2d(1 - 0.02f, 0);
	glVertex3dv(copyD);
	glEnd();
	double copyA2[3] = { 1 - 2.21429f,3 + 0.64286f,0 };
	double copyB2[3] = { 1 - 2.21429f,3 + 0.64286f,3 };
	double copyC2[3] = { X[X.size() - 1],Y[Y.size() - 1],3 };
	double copyD2[3] = { X[X.size() - 1],Y[Y.size() - 1],0 };
	glNormal3dv(FindNormal(copyA2, copyD2, copyB2));
	
	//createQuad(copyA2, copyB2, copyC2, copyD2, color);
	glBegin(GL_QUADS);
	glColor3dv(color);
	glTexCoord2d(0, 0);
	glVertex3dv(copyA2);
	glTexCoord2d(0, 1);
	glVertex3dv(copyB2);
	glTexCoord2d(0.02f, 1);
	glVertex3dv(copyC2);
	glTexCoord2d(0.02f, 0);
	glVertex3dv(copyD2);
	glEnd();
	glPopMatrix();

}
