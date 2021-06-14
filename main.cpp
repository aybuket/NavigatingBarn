//
//  main.cpp
//  GraphicTermProject
//
//  Created by Aybüke Buket Akgül on 11.06.2021.
//  Copyright © 2021 Aybüke Buket Akgül. All rights reserved.
//

#include "Angel.h"
#include "Texture.h"
#include "PopupMenu.h"
#include "Shader.h"
#include "Decleration.h"
#include "Object.h"
#include <math.h>
using namespace Decleration;

vec3 move_arrows (0.0, 0.0 ,0.0);

int numObjectVertices[12] = {
    NumVertices,       //grass
    NumVertices,       //cube
    NumVertices,       //corner
    18,                //roof
    NumVertices,       //wall
    NumVertices,       //wall
    NumVertices,       //wall
    NumVertices,       //corner
    NumVertices,       //cube
    sphereNumVertices, //sphere
    bunnyPointNum};   //bunny

// Array of rotation angles (in degrees) for each coordinate axis
enum { Xaxis = 0, Yaxis = 1, Zaxis = 2, NumAxes = 3 };
GLfloat scaleFactor = 0.7;
int light_turn = 0;
//                     grass,  cube, corner,   roof,  wall,   wall,   wall, corner,   cube, sphere,  bunny
bool textureFlag[12] = {true,  true,  false,  false,   true,   true,   true,  false,   true,  false,  false};
bool shaderFlag[12] =  {false, false, false,   true,  false,  false,  false,  false,  false,   true,  true};

//----------------------------------------------------------------------------

mat4  model_view[12];

//----------------------------------------------------------------------------

// OpenGL initialization
void
init()
{
    Object::colorcube();
    //Object::room();
    Object::roof();
    M[3][2] = -1.0/light_position[2];
    M[3][3] = 0.0;
    Texture::init_texture();

    // Load shaders and use the resulting shader program
    Shader::init_shader();
    glGenVertexArrays( 12, vao );
    
    for(int i=0; i<9; i++){
        Object::initialize_buffer(i);
    }
    // Subdivide a tetrahedron into a sphere
    Object::tetrahedron( NumTimesToSubdivide );
    glBindVertexArray( vao[9] );
    Object::initialize_sphere_buffer();
    
    Object::read_bunny();
    glBindVertexArray( vao[10] );
    Object::initialize_bunny_buffer();
    numObjectVertices[10] = bunnyPointNum;
    
    glEnable( GL_DEPTH_TEST );

    // Set state variable "clear color" to clear buffer with.
    glClearColor( 0.0/256, 181.0/256, 226.0/256, 1.0 );
   }
void
display( void )
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    
    const vec3 viewer_pos( 0.0, 0.0, 4.0 );
    
    
    for(int i =0; i<10; i++)
    {
        PopupMenu::shinning_popup_handling(i);
        if (!fixedLight)
        {
            light_position =  Translate( -viewer_pos ) * Scale(scaleFactor, scaleFactor, scaleFactor) *
            RotateZ(light_turn) * RotateY( light_turn ) * light_position;
            
        }
        glUniform4fv( glGetUniformLocation(program, "LightPosition"), 1, light_position );
        glUniform1i( ShadingMode, true );
        glUniform1i( TextureFlagLoc, textureFlag[i] );
        glUniform1i( ShaderFlagLoc, shaderFlag[i]);
        glBindTexture( GL_TEXTURE_2D, Decleration::textures[i] );
        model_view[i] = Translate(-viewer_pos) *Translate(move_arrows) * Scale(scaleFactor, scaleFactor, scaleFactor) * RotateX(Theta[Xaxis]) * RotateY(Theta[Yaxis]) * RotateZ(Theta[Zaxis]) * Scale(0.25, 0.25, 0.25) * RotateX(-90);
        glBindVertexArray( vao[i] );
        glUniformMatrix4fv( ModelView, 1, GL_TRUE, model_view[i] );
        glDrawArrays( drawing_mode, 0, numObjectVertices[i] );
    }

    PopupMenu::shinning_popup_handling(3);
    glUniform4fv( glGetUniformLocation(program, "LightPosition"), 1, light_position );
    glUniform1i( ShadingMode, true );
    glUniform1i( TextureFlagLoc, textureFlag[10] );
    glUniform1i( ShaderFlagLoc, shaderFlag[10]);
    model_view[10] =  Translate(-viewer_pos) *Translate(move_arrows) * Scale(scaleFactor, scaleFactor, scaleFactor) * RotateX(Theta[Xaxis]) * RotateY(Theta[Yaxis]) * RotateZ(Theta[Zaxis]) *Scale(0.03, 0.03, 0.03) * RotateY(90) * RotateX(-90) * Translate(-7.0, 80.0, -32);
    glBindVertexArray( vao[10] );
    glUniformMatrix4fv( ModelView, 1, GL_TRUE, model_view[10] );
    glDrawArrays( drawing_mode, 0, numObjectVertices[10] );
    glutSwapBuffers();
}

//----------------------------------------------------------------------------

void
mouse( int button, int state, int x, int y )
{
    if ( state == GLUT_DOWN ) {
    switch( button ) {
        case GLUT_LEFT_BUTTON:    Axis = Xaxis;  break;
        case GLUT_MIDDLE_BUTTON:  Axis = Yaxis;  break;
        case GLUT_RIGHT_BUTTON:   Axis = Zaxis;  break;
    }
    }
}

//----------------------------------------------------------------------------

// Reshape the application window, preserving the object aspect ratio
void reshape(int w, int h){
    glViewport( 0, 0, w, h );

    GLfloat aspect = GLfloat(w)/h;
    mat4  projection = Perspective( 45.0, aspect, 0.5, 60.0 );

    glUniformMatrix4fv( Projection, 1, GL_TRUE, projection );
}

//----------------------------------------------------------------------------

// print helper information to console.
void print_help()
{
    std::cout << "------------------------------" << std::endl;
    std::cout << "Right click to choose mode:" << std::endl;
    std::cout << "--Wireframe, Shading/Texture" << std::endl;
    std::cout << "Right click to turn on/off:" << std::endl;
    std::cout << "--Ambient, Diffuse, Specular" << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << "Q/q : Quit" << std::endl;
    std::cout << "H/h : Helper" << std::endl;
    std::cout << "W/w : Look up" << std::endl;
    std::cout << "A/a : Look left" << std::endl;
    std::cout << "S/s : Look down" << std::endl;
    std::cout << "D/d : Look right" << std::endl;
    std::cout << "Z/z : Zoom in" << std::endl;
    std::cout << "X/x : Zoom out" << std::endl;
    std::cout << "Arrow keys to move up, left, down, or right" << std::endl;
}

//----------------------------------------------------------------------------

void
keyboard( unsigned char key, int mousex, int mousey )
{
    switch( key ) {
    case 033: // Escape Key
    case 'q': case 'Q':
        exit( EXIT_SUCCESS );
        break;
        case 'a':
        case 'A':
            Theta[Yaxis] -= 3.0;
            
            if (Theta[Yaxis] < 360.0){
                    Theta[Yaxis] += 360.0;
            }
            break;
        case 'd':
        case 'D':
            Theta[Yaxis] += 3.0;
            
            if (Theta[Yaxis] > 360.0){
                    Theta[Yaxis] -= 360.0;
            }
            break;
        case 'w':
        case 'W':
            Theta[Xaxis] -= 3.0;
            
            if (Theta[Xaxis] < 360.0){
                    Theta[Xaxis] += 360.0;
            }
            break;
        case 's':
        case 'S':
            Theta[Xaxis] += 3.0;
            
            if (Theta[Xaxis] > 360.0){
                    Theta[Xaxis] -= 360.0;
            }
        case 'z':
        case 'Z':
            scaleFactor *= 1.1;
            break;
            
            // "Zoom-out" from the object
        case 'x':
        case 'X':
            scaleFactor *= 0.9;
            break;
        case 'h':
        case 'H':
            print_help();

    }

    glutPostRedisplay();
}

void special(int key, int x, int y){
    switch (key) {
        case GLUT_KEY_UP:
            move_arrows[1] -= 0.1;
            break;
            
        case GLUT_KEY_DOWN:
            move_arrows[1] += 0.1;
            break;
            
        case GLUT_KEY_LEFT:
            move_arrows[0] += 0.1;
            break;
        case GLUT_KEY_RIGHT:
            move_arrows[0] -= 0.1;
            break;
            
        default:
            break;
    }
    glutPostRedisplay();
}


//----------------------------------------------------------------------------
void
idle( void )
{
    if (!fixedLight){
        light_turn += 3;
        if (light_turn >360)
        {
            light_turn -= 360;
        }
    }
}
int
main( int argc, char **argv )
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_3_2_CORE_PROFILE );
    glutInitWindowSize( 1024, 512 );
    glutCreateWindow( "Term Project" );
    
    glewExperimental = GL_TRUE;
    glewInit();

    init();
    PopupMenu::popup_menu();
    glutDisplayFunc( display );
    glutKeyboardFunc( keyboard );
    glutIdleFunc( idle );
    glutMouseFunc( mouse );
    glutReshapeFunc( reshape );
    glutSpecialFunc( special );

    glutMainLoop();
    return 0;
}
