//
//  Object.cpp
//  GraphicTermProject
//
//  Created by Aybüke Buket Akgül on 11.06.2021.
//  Copyright © 2021 Aybüke Buket Akgül. All rights reserved.
//

#include "Object.h"
#include <fstream>
#include <iostream>
using namespace std;
using namespace Decleration;

namespace Object {

void initialize_buffer(int index){
    glBindVertexArray( vao[index] );
    glGenBuffers( 12, buffer );
    glBindBuffer( GL_ARRAY_BUFFER, buffer[index] );
    glBufferData( GL_ARRAY_BUFFER, sizeof(points[index]) + sizeof(normals[index]) +  sizeof(colors[index]) + sizeof(tex_coords[index]), NULL, GL_STATIC_DRAW );
    int offset = 0;
    glBufferSubData( GL_ARRAY_BUFFER, offset, sizeof(points[index]), points[index] );
    offset += sizeof(points[index]);
    glBufferSubData( GL_ARRAY_BUFFER, offset, sizeof(colors[index]), colors[index]);
    offset += sizeof(colors[index]);
    glBufferSubData( GL_ARRAY_BUFFER, offset, sizeof(normals[index]), normals[index]);
    offset += sizeof(normals[index]);
    glBufferSubData( GL_ARRAY_BUFFER, offset, sizeof(tex_coords[index]), tex_coords[index] );

    offset = 0;
    glEnableVertexAttribArray( Decleration::vPosition );
    glVertexAttribPointer( Decleration::vPosition, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(offset) );
    
    offset += sizeof(points[index]);
    glEnableVertexAttribArray( Decleration::vColor );
    glVertexAttribPointer( Decleration::vColor, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(offset) );
    
    offset += sizeof(colors[index]);
    glEnableVertexAttribArray( Decleration::vNormal );
    glVertexAttribPointer( Decleration::vNormal, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(offset) );
    
    offset += sizeof(normals[index]);
    glEnableVertexAttribArray( Decleration::vTexCoord );
    glVertexAttribPointer( Decleration::vTexCoord, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(offset) );
}

 point4 * bunnyVertices;
 point4 * bunnyPoints;
 color4 * bunnyNormals;
 vec2 * bunnyTexCoords;

void read_bunny()
{
    string line;
    string filename ="bunny.off";
    ifstream myfile (filename);
    if (!myfile.is_open()) {
        std::cerr << "Could not open the file - '"
        << filename << "'" << endl;
    }
    
    myfile >> line;
    if ( line == "OFF" )
    {
        int edge_count;
        myfile >> bunnyVertexNum;
        myfile >> bunnyPointNum;
        myfile >> edge_count;
        
        // second part of the file contains indices of an triangle, so makes 3 points.
        bunnyPointNum*=3;
        bunnyVertices = new point4[bunnyVertexNum];
        bunnyPoints = new point4[bunnyPointNum];
        bunnyNormals = new point4[bunnyPointNum];
        
        // (x,y,z) coordinates of vertices.
        for ( int v = 0; v < bunnyVertexNum ; v++ )
        {
            float x; float y; float z;
            myfile >> x;
            myfile >> y;
            myfile >> z;
            bunnyVertices[v] = point4(x, y, z, 1.0);
        }
        
        // indices of triangles
        for ( int t = 0; t < bunnyPointNum ; t+=3 )
        {
            int n; int x; int y; int z;
            myfile >> n;
            myfile >> x;
            myfile >> y;
            myfile >> z;
            bunnyPoints[t] = bunnyVertices[x];
            bunnyPoints[t+1] = bunnyVertices[y];
            bunnyPoints[t+2] = bunnyVertices[z];

            vec4 u = bunnyPoints[t+1] - bunnyPoints[t];
            vec4 v = bunnyPoints[t+2] - bunnyPoints[t];

            vec3 normal = normalize( cross(u, v) );
            
            bunnyNormals[t] = normal;
            bunnyNormals[t+1] = normal;
            bunnyNormals[t+2] = normal;
        }
        myfile.close();
    }
}

//----------------------------------------------------------------------------
// Vertices of a unit cube centered at origin, sides aligned with axes
point4 vertices1[8] = {
    point4( -20, -10, -4, 1.0 ),
    point4( -20,  10, -4, 1.0 ),
    point4(  20,  10, -4, 1.0 ),
    point4(  20, -10, -4, 1.0 ),
    point4( -20, -10, -5, 1.0 ),
    point4( -20,  10, -5, 1.0 ),
    point4(  20,  10, -5, 1.0 ),
    point4(  20, -10, -5, 1.0 ),
};


point4 vertices2[8] = {
    point4( -1, -1, -3, 1.0 ),
    point4( -1,  0, -3, 1.0 ),
    point4(  0,  0, -3, 1.0 ),
    point4(  0, -1, -3, 1.0 ),
    point4( -1, -1, -4, 1.0 ),
    point4( -1,  0, -4, 1.0 ),
    point4(  0,  0, -4, 1.0 ),
    point4(  0, -1, -4, 1.0 )
};

point4 vertices2a[8] = {
    point4(  3, -5, -3, 1.0 ),
    point4(  3, -3, -3, 1.0 ),
    point4(  5, -3, -3, 1.0 ),
    point4(  5, -5, -3, 1.0 ),
    point4(  3, -5, -4, 1.0 ),
    point4(  3, -3, -4, 1.0 ),
    point4(  5, -3, -4, 1.0 ),
    point4(  5, -5, -4, 1.0 )
};

point4 vertices31[8] = {
    point4( -5,   4,  1, 1.0 ),
    point4( -5,   5,  1, 1.0 ),
    point4( -4,   5,  1, 1.0 ),
    point4( -4,   4,  1, 1.0 ),
    point4( -5,   4, -4, 1.0 ),
    point4( -5,   5, -4, 1.0 ),
    point4( -4,   5, -4, 1.0 ),
    point4( -4,   4, -4, 1.0 ),
};

point4 vertices32[8] = {
    point4(  5,  4,  1, 1.0 ),
    point4(  5,  5,  1, 1.0 ),
    point4(  4,  5,  1, 1.0 ),
    point4(  4,  4,  1, 1.0 ),
    point4(  5,  4, -4, 1.0 ),
    point4(  5,  5, -4, 1.0 ),
    point4(  4,  5, -4, 1.0 ),
    point4(  4,  4, -4, 1.0 ),
};


point4 vertices3a[8] = {
    point4(   -5, -5,  1, 1.0 ),
    point4(   -5,  5,  1, 1.0 ),
    point4( -4.8,  5,  1, 1.0 ),
    point4( -4.8, -5,  1, 1.0 ),
    point4(   -5, -5, -4, 1.0 ),
    point4(   -5,  5, -4, 1.0 ),
    point4( -4.8,  5, -4, 1.0 ),
    point4( -4.8, -5, -4, 1.0 )
};

point4 vertices3b[8] = {
    point4( 4.8, -5,  1, 1.0 ),
    point4( 4.8,  5,  1, 1.0 ),
    point4(   5,  5,  1, 1.0 ),
    point4(   5, -5,  1, 1.0 ),
    point4( 4.8, -5, -4, 1.0 ),
    point4( 4.8,  5, -4, 1.0 ),
    point4(   5,  5, -4, 1.0 ),
    point4(   5, -5, -4, 1.0 ),
};

point4 vertices3c[8] = {
    point4( -5, 4.8,  1, 1.0 ),
    point4( -5,   5,  1, 1.0 ),
    point4(  5,   5,  1, 1.0 ),
    point4(  5, 4.8,  1, 1.0 ),
    point4( -5, 4.8, -4, 1.0 ),
    point4( -5,   5, -4, 1.0 ),
    point4(  5,   5, -4, 1.0 ),
    point4(  5, 4.8, -4, 1.0 ),
};

point4 vertices4[] = {
    point4(  0,  0,  4, 1.0),
    point4(  5,  5,  1, 1.0),
    point4(  5, -5,  1, 1.0),
    point4( -5, -5,  1, 1.0),
    point4( -5,  5,  1, 1.0),
};

point4 vertices[8] = {
    point4( -0.5, -0.5,  0.5, 1.0 ),
    point4( -0.5,  0.5,  0.5, 1.0 ),
    point4(  0.5,  0.5,  0.5, 1.0 ),
    point4(  0.5, -0.5,  0.5, 1.0 ),
    point4( -0.5, -0.5, -0.5, 1.0 ),
    point4( -0.5,  0.5, -0.5, 1.0 ),
    point4(  0.5,  0.5, -0.5, 1.0 ),
    point4(  0.5, -0.5, -0.5, 1.0 )
};


// RGBA olors
color4 vertex_colors[10] = {
    color4(   0.0/256, 154.0/256,  23.0/256, 1.0 ),  // grass green
    color4(   0.0/256,   0.0/256,   0.0/256, 1.0 ),  // black
    color4( 169.0/256,  64.0/256,   7.0/256, 1.0 ),  // whiskey brown
    color4( 198.0/256, 161.0/256, 207.0/256, 1.0 ),  // lilac
    color4( 256.0/256,   0.0/256,   0.0/256, 1.0 ),  // red
    color4( 256.0/256, 256.0/256,   0.0/256, 1.0 ),  // yellow
    color4(  50.0/256, 205.0/256,  50.0/256, 1.0 ),  // green
    color4( 169.0/256,  64.0/256,   7.0/256, 1.0 ),  // whiskey brown
    color4( 255.0/256, 140.0/256,   0.0/256, 1.0 ),  // orange
    color4( 256.0/256, 256.0/256, 256.0/256, 1.0 ),  // white
};

// quad generates two triangles for each face and assigns colors
//    to the vertices
int Index = 0;

void
quad(int a, int b, int c, int d )
{
    
    vec4 u = vertices1[b] - vertices1[a];
    vec4 v = vertices1[c] - vertices1[b];

    vec3 normal = normalize( cross(u, v) );
    
    for (int i=0; i<10; i++){
        colors[i][Index] = vertex_colors[i];
    }
    
    normals[0][Index] = normal;
    points[0][Index] = vertices1[a];
    points[1][Index] = vertices2[a];
    points[2][Index] = vertices31[a];
    points[4][Index] = vertices3a[a];
    points[5][Index] = vertices3b[a];
    points[6][Index] = vertices3c[a];
    points[7][Index] = vertices32[a];
    points[8][Index] = vertices2a[a];
    tex_coords[0][Index] = vec2( 0.0, 0.0 );
    tex_coords[1][Index] = vec2( 0.0, 0.25 );
    tex_coords[4][Index] = vec2( 0.0, 0.0 );
    tex_coords[5][Index] = vec2( 0.0, 0.0 );
    tex_coords[6][Index] = vec2( 0.0, 0.0 );
    tex_coords[8][Index] = vec2( 0.0, 0.0 );
    Index++;

    for (int i=0; i<10; i++){
        colors[i][Index] = vertex_colors[i];
    }
    
    normals[0][Index] = normal;
    points[0][Index] = vertices1[b];
    points[1][Index] = vertices2[b];
    points[2][Index] = vertices31[b];
    points[4][Index] = vertices3a[b];
    points[5][Index] = vertices3b[b];
    points[6][Index] = vertices3c[b];
    points[7][Index] = vertices32[b];
    points[8][Index] = vertices2a[b];
    tex_coords[0][Index] = vec2( 0.0, 2.0 );
    tex_coords[1][Index] = vec2( 0.0, 0.75 );
    tex_coords[4][Index] = vec2( 0.0, 2.0 );
    tex_coords[5][Index] = vec2( 0.0, 2.0 );
    tex_coords[6][Index] = vec2( 0.0, 2.0 );
    tex_coords[8][Index] = vec2( 0.0, 1.0 );
    Index++;
    
    for (int i=0; i<10; i++){
        colors[i][Index] = vertex_colors[i];
    }
    
    normals[0][Index] = normal;
    points[0][Index] = vertices1[c];
    points[1][Index] = vertices2[c];
    points[2][Index] = vertices31[c];
    points[4][Index] = vertices3a[c];
    points[5][Index] = vertices3b[c];
    points[6][Index] = vertices3c[c];
    points[7][Index] = vertices32[c];
    points[8][Index] = vertices2a[c];
    tex_coords[0][Index] = vec2( 2.0, 2.0 );
    tex_coords[1][Index] = vec2( 0.5, 0.75 );
    tex_coords[4][Index] = vec2( 2.0, 2.0 );
    tex_coords[5][Index] = vec2( 2.0, 2.0 );
    tex_coords[6][Index] = vec2( 2.0, 2.0 );
    tex_coords[8][Index] = vec2( 1.0, 1.0 );
    Index++;
    
    for (int i=0; i<10; i++){
        colors[i][Index] = vertex_colors[i];
    }
    
    normals[0][Index] = normal;
    points[0][Index] = vertices1[a];
    points[1][Index] = vertices2[a];
    points[2][Index] = vertices31[a];
    points[4][Index] = vertices3a[a];
    points[5][Index] = vertices3b[a];
    points[6][Index] = vertices3c[a];
    points[7][Index] = vertices32[a];
    points[8][Index] = vertices2a[a];
    tex_coords[0][Index] = vec2( 0.0, 0.0 );
    tex_coords[1][Index] = vec2( 0.0, 0.25 );
    tex_coords[4][Index] = vec2( 0.0, 0.0 );
    tex_coords[5][Index] = vec2( 0.0, 0.0 );
    tex_coords[6][Index] = vec2( 0.0, 0.0 );
    tex_coords[8][Index] = vec2( 0.0, 0.0 );
    Index++;

    for (int i=0; i<10; i++){
        colors[i][Index] = vertex_colors[i];
    }
    
    normals[0][Index] = normal;
    points[0][Index] = vertices1[c];
    points[1][Index] = vertices2[c];
    points[2][Index] = vertices31[c];
    points[4][Index] = vertices3a[c];
    points[5][Index] = vertices3b[c];
    points[6][Index] = vertices3c[c];
    points[7][Index] = vertices32[c];
    points[8][Index] = vertices2a[c];
    tex_coords[0][Index] = vec2( 2.0, 2.0 );
    tex_coords[1][Index] = vec2( 0.5, 0.75 );
    tex_coords[4][Index] = vec2( 2.0, 2.0 );
    tex_coords[5][Index] = vec2( 2.0, 2.0 );
    tex_coords[6][Index] = vec2( 2.0, 2.0 );
    tex_coords[8][Index] = vec2( 1.0, 1.0 );
    Index++;
    
    for (int i=0; i<10; i++){
        colors[i][Index] = vertex_colors[i];
    }
    
    normals[0][Index] = normal;
    points[0][Index] = vertices1[d];
    points[1][Index] = vertices2[d];
    points[2][Index] = vertices31[d];
    points[4][Index] = vertices3a[d];
    points[5][Index] = vertices3b[d];
    points[6][Index] = vertices3c[d];
    points[7][Index] = vertices32[d];
    points[8][Index] = vertices2a[d];
    tex_coords[0][Index] = vec2( 2.0, 0.0 );
    tex_coords[1][Index] = vec2( 0.5, 0.25 );
    tex_coords[4][Index] = vec2( 2.0, 0.0 );
    tex_coords[5][Index] = vec2( 2.0, 0.0 );
    tex_coords[6][Index] = vec2( 2.0, 0.0 );
    tex_coords[8][Index] = vec2( 1.0, 0.0 );
    Index++;
}

//----------------------------------------------------------------------------

// generate 12 triangles: 36 vertices and 36 colors
void
colorcube()
{
    quad( 1, 0, 3, 2 );
    quad( 2, 3, 7, 6 );
    quad( 3, 0, 4, 7 );
    quad( 6, 5, 1, 2 );
    quad( 4, 5, 6, 7 );
    quad( 5, 4, 0, 1 );
}
/*
void
room()
{
    Index = 0;
    vec4 indices[] = {
        vec4(2, 3, 7, 6),
        vec4(6, 5, 1, 2),
        vec4(5, 4, 0, 1)
    };
    
    for (int i=0; i<3; i++){
        int a = indices[i][0];
        int b = indices[i][1];
        int c = indices[i][2];
        int d = indices[i][3];
        
        vec4 u = vertices3[b] - vertices3[a];
        vec4 v = vertices3[c] - vertices3[b];

        vec3 normal = normalize( cross(u, v) );
        
        normals[2][Index] = normal;
        points[2][Index] = vertices3[a];
        tex_coords[2][Index] = vec2( 0.0, 0.0);
        Index++;
        
        normals[2][Index] = normal;
        points[2][Index] = vertices3[b];
        tex_coords[2][Index] = vec2( 0.0, 2.0 );
        Index++;
        
        normals[2][Index] = normal;
        points[2][Index] = vertices3[c];
        tex_coords[2][Index] = vec2( 2.0, 2.0 );
        Index++;
        
        normals[2][Index] = normal;
        points[2][Index] = vertices3[a];
        tex_coords[2][Index] = vec2( 0.0, 0.0 );
        Index++;
        
        normals[2][Index] = normal;
        points[2][Index] = vertices3[c];
        tex_coords[2][Index] = vec2( 2.0, 2.0 );
        Index++;
        
        normals[2][Index] = normal;
        points[2][Index] = vertices3[d];
        tex_coords[2][Index] = vec2( 2.0, 0.0 );
        Index++;
        
    }
}
*/
void roof()
{
    Index = 0;
    vec3 indices[] = {
        vec3(0, 1, 2),
        vec3(0, 2, 3),
        vec3(0, 3, 4),
        vec3(0, 4, 1),
        vec3(1, 2, 3),
        vec3(1, 3, 4)
    };
    
    for (int i=0; i<6; i++){
        int a = indices[i][0];
        int b = indices[i][1];
        int c = indices[i][2];
        
        vec4 u = vertices4[b] - vertices4[a];
        vec4 v = vertices4[c] - vertices4[b];

        vec3 normal = normalize( cross(u, v) );
        
        points[3][Index] = vertices4[a]; normals[3][Index] = normal; Index++;
        points[3][Index] = vertices4[b]; normals[3][Index] = normal; Index++;
        points[3][Index] = vertices4[c]; normals[3][Index] = normal; Index++;
    }
}

vec2 UVcoordinates(point4 a)
{
    float radius = sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
    
    float u = acos(a.y / radius) / (2*M_PI);
    float v = acos( a.z / (radius * sin(2 *M_PI * u)))/(2*M_PI);
    
    if ( a.x < 0.0)
    {
        u = 0.5+u;
        v = 1.0-v;
    }
    else if (a.x == 0)
    {
        v = a.z > 0 ? a.z : 1+a.z;
        std::cout << a << " " << vec2(u,v) << endl;
    }
    
    return vec2(u,v);
}

int sphereIndex = 0;
void
triangle( const point4& a, const point4& b, const point4& c )
{
    sphereTexCoords[sphereIndex] = UVcoordinates(a);
    sphereNormals[sphereIndex] = vec3(a[0], a[1], a[2]);
    sphereColors[sphereIndex] = color4(1.0,0.5,0.5,1.0);
    spherePoints[sphereIndex] = a;  sphereIndex++;
    
    sphereTexCoords[sphereIndex] = UVcoordinates(b);
    sphereNormals[sphereIndex] = vec3(b[0], b[1], b[2]);
    sphereColors[sphereIndex] = color4(1.0,0.5,0.5,1.0);
    spherePoints[sphereIndex] = b;  sphereIndex++;
    
    sphereTexCoords[sphereIndex] = UVcoordinates(c);
    sphereNormals[sphereIndex] = vec3(c[0], c[1], c[2]);
    sphereColors[sphereIndex] = color4(1.0,0.5,0.5,1.0);
    spherePoints[sphereIndex] = c;  sphereIndex++;
}
//----------------------------------------------------------------------
point4
unit( const point4& p )
{
    float len = p.x*p.x + p.y*p.y + p.z*p.z;
    point4 t;
    if ( len > DivideByZeroTolerance ) {
        t = p / sqrt(len);
        t.w = 1.0;
    }
    return t;
}

void
divide_triangle( const point4& a, const point4& b,
       const point4& c, int count )
{
    if ( count > 0 ) {
        point4 v1 = unit( a + b );
        point4 v2 = unit( a + c );
        point4 v3 = unit( b + c );
        divide_triangle(  a, v1, v2, count - 1 );
        divide_triangle(  c, v2, v3, count - 1 );
        divide_triangle(  b, v3, v1, count - 1 );
        divide_triangle( v1, v3, v2, count - 1 );
    }
    else
    {
        triangle( a, b, c );
    }
}

void
tetrahedron( int count )
{
    point4 v[4] = {
        vec4( 0.0, 0.0, 1.0, 1.0 ),
        vec4( 0.0, 0.942809, -0.333333, 1.0 ),
        vec4( -0.816497, -0.471405, -0.333333, 1.0 ),
        vec4( 0.816497, -0.471405, -0.333333, 1.0 )
};
    divide_triangle( v[0], v[1], v[2], count );
    divide_triangle( v[3], v[2], v[1], count );
    divide_triangle( v[0], v[3], v[1], count );
    divide_triangle( v[0], v[2], v[3], count );
}

//----------------------------------------------------------------------------
//initialize buffer for sphere object
void initialize_sphere_buffer(){
    glGenBuffers( 1, &sphereBuffer );
    glBindBuffer( GL_ARRAY_BUFFER, sphereBuffer );
    glBufferData( GL_ARRAY_BUFFER, sizeof(spherePoints) + sizeof(sphereNormals) + sizeof(sphereColors) + sizeof(sphereTexCoords), NULL, GL_STATIC_DRAW );
    int offset = 0;
    glBufferSubData( GL_ARRAY_BUFFER, offset, sizeof(spherePoints), spherePoints );
    offset += sizeof(spherePoints);
    glBufferSubData( GL_ARRAY_BUFFER, offset, sizeof(sphereNormals), sphereNormals);
    offset += sizeof(sphereNormals);
    glBufferSubData( GL_ARRAY_BUFFER, offset, sizeof(sphereColors), sphereColors );
    offset += sizeof(sphereColors);
    glBufferSubData( GL_ARRAY_BUFFER, offset, sizeof(sphereTexCoords), sphereTexCoords );

    offset = 0;
    glEnableVertexAttribArray( vPosition );
    glVertexAttribPointer( vPosition, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(offset) );
    
    offset += sizeof(spherePoints);
    glEnableVertexAttribArray( vNormal );
    glVertexAttribPointer( vNormal, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(offset) );
    
    offset += sizeof(sphereNormals);
    glEnableVertexAttribArray( vColor );
    glVertexAttribPointer( vColor, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(offset) );
    
    offset += sizeof(sphereColors);
    glEnableVertexAttribArray( vTexCoord );
    glVertexAttribPointer( vTexCoord, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(offset) );
}

// initialize buffer for bunny object
void initialize_bunny_buffer()
{
    glGenBuffers( 1, &bunnyBuffer );
    glBindBuffer( GL_ARRAY_BUFFER, bunnyBuffer );
    glBufferData( GL_ARRAY_BUFFER, sizeof(point4)*bunnyPointNum*2,
                 NULL, GL_STATIC_DRAW );
    glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof(point4)*bunnyPointNum, bunnyPoints );
    glBufferSubData( GL_ARRAY_BUFFER, sizeof(point4)*bunnyPointNum, sizeof(color4)*bunnyPointNum, bunnyNormals);
    glEnableVertexAttribArray( vPosition );
    glVertexAttribPointer( vPosition, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0) );
    glEnableVertexAttribArray( vNormal );
    glVertexAttribPointer( vNormal, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(point4)*bunnyPointNum) );
}

}
