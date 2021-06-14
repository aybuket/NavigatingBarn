//
//  Decleration.cpp
//  GraphicTermProject
//
//  Created by Aybüke Buket Akgül on 12.06.2021.
//  Copyright © 2021 Aybüke Buket Akgül. All rights reserved.
//

#include <stdio.h>
#include "Decleration.h"

namespace Decleration {
// Default values
GLenum drawing_mode = GL_TRIANGLES;


float ambient_mode  = 1.0;
float diffuse_mode  = 1.0;
float specular_mode = 1.0;

// Array of rotation angles (in degrees) for each coordinate axis
enum { Xaxis = 0, Yaxis = 1, Zaxis = 2, NumAxes = 3 };
int      Axis = Yaxis;
GLfloat  Theta[NumAxes] = { 0.0, 0.0, 0.0 };

vec4 light_position(5.0, 0.0, 2.0, 1.0 );
bool fixedLight = true;
bool shadingModeFlag = false;
bool shadowFlag = true;

vec4 material_ambient( 1.0, 0.0, 1.0, 1.0 );
vec4 material_diffuse( 1.0, 0.8, 0.0, 1.0 );
vec4 material_specular( 1.0, 0.8, 0.0, 1.0 );
float  material_shininess = 100.0;

mat4 M = identity(); // shadow projection matrix initially an identity matrix

GLfloat aspect = 0.0;
GLuint  TextureFlagLoc = 0;
GLuint ShadowFlagLoc = 0;
GLuint ShaderFlagLoc = 0;
vec4 ambient_product(0.0, 0.0, 0.0, 0.0);
vec4 diffuse_product(0.0, 0.0, 0.0, 0.0);
vec4 specular_product(0.0, 0.0, 0.0, 0.0);
// Model-view and projection matrices uniform location
GLuint  ModelView = 0;
GLuint Projection = 0;
GLuint ShadingMode = 0;

// vertex array, attributes, program
//GLuint vao[3] = {0, 0, 0};
GLuint vPosition = 0;
GLuint vNormal = 0;
GLuint vColor = 0;
GLuint vTexCoord = 0;
GLuint program = 0;

GLuint textures[12] = {};

const int  NumTriangles = 12; // (6 faces)(2 triangles/face)
const int  NumVertices  = 3 * NumTriangles;

point4 points[12][NumVertices] = {};
color4 colors[12][NumVertices] = {};
// Vertex data arrays
vec2 tex_coords[12][NumVertices] = {};
vec4 normals[12][NumVertices] = {};
// Create a vertex array object
GLuint vao[12] = {};

// Create and initialize a buffer object
GLuint buffer[12] = {};
int bunnyVertexNum = 0;
int bunnyPointNum = 0;
extern const int NumTimesToSubdivide   = 5;
extern const int NumTrianglesOfSphere  = 4096;
extern const int sphereNumVertices     = 3 * NumTrianglesOfSphere;

point4 sphereVertices[sphereNumVertices] = {};
point4 spherePoints[sphereNumVertices] = {};
color4 sphereColors[sphereNumVertices] = {};
vec3   sphereNormals[sphereNumVertices] = {};
vec2   sphereTexCoords[sphereNumVertices] = {};

GLuint sphereBuffer = 0;
GLuint bunnyBuffer = 0;
}
