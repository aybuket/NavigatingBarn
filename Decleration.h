//
//  Decleration.h
//  GraphicTermProject
//
//  Created by Aybüke Buket Akgül on 11.06.2021.
//  Copyright © 2021 Aybüke Buket Akgül. All rights reserved.
//

#ifndef Decleration_h
#define Decleration_h

#include "Angel.h"

using namespace std;
typedef vec4  point4;
typedef vec4 color4;

namespace Decleration {
// Default values
extern GLenum drawing_mode;

extern float ambient_mode;
extern float diffuse_mode;
extern float specular_mode;

// Array of rotation angles (in degrees) for each coordinate axis
extern int      Axis;
extern GLfloat  Theta[3];

extern mat4 M;
extern color4 light_position;
extern bool fixedLight;
extern bool shadingModeFlag;
extern bool shadowFlag;

extern vec4 material_ambient;
extern vec4 material_diffuse;
extern vec4 material_specular;
extern float  material_shininess;

extern GLfloat aspect;
extern GLuint  TextureFlagLoc, ShadowFlagLoc, ShaderFlagLoc;
extern vec4 ambient_product, diffuse_product, specular_product;
// Model-view and projection matrices uniform location
extern GLuint  ModelView, Projection, ShadingMode;

// vertex array, attributes, program
//extern GLuint vao[3];
extern GLuint vPosition, vNormal, vColor, vTexCoord, program;

extern GLuint textures[12];

extern const int  NumTriangles;
extern const int  NumVertices;

extern point4 points[12][36];
extern color4 colors[12][36];
// Vertex data arrays
extern vec2 tex_coords[12][36];
extern vec4 normals[12][36];

// Create a vertex array object
extern GLuint vao[12];

// Create and initialize a buffer object
extern GLuint buffer[12];
extern  int bunnyVertexNum;
extern  int bunnyPointNum;
extern point4 sphereVertices[3*4096];
extern point4 spherePoints[3*4096];
extern color4 sphereColors[3*4096];
extern vec3   sphereNormals[3*4096];
extern vec2   sphereTexCoords[3*4096];

extern const int NumTimesToSubdivide;
extern const int NumTrianglesOfSphere;
extern const int sphereNumVertices;

extern GLuint sphereBuffer, bunnyBuffer;

}


#endif /* Decleration_h */
