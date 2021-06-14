//
//  Shader.cpp
//  GraphicTermProject
//
//  Created by Aybüke Buket Akgül on 11.06.2021.
//  Copyright © 2021 Aybüke Buket Akgül. All rights reserved.
//

#include "Shader.h"
using namespace Decleration;

namespace Shader {

void initialize_shader_parameters(vec4 material_ambient, vec4 material_diffuse, vec4 material_specular,float  material_shininess)
{
    // Initialize shader lighting parameters
    vec4 light_ambient( 0.2, 0.2, 0.2, 1.0 );
    vec4 light_diffuse( 1.0, 1.0, 1.0, 1.0 );
    vec4 light_specular( 1.0, 1.0, 1.0, 1.0 );
    
    if (ambient_mode < 0.0)
    {
        ambient_product = vec4(0.0, 0.0, 0.0, 0.0);
    }
    else
    {
        ambient_product = light_ambient * material_ambient;
    }
    
    if (diffuse_mode < 0.0)
    {
        diffuse_product = vec4(0.0, 0.0, 0.0, 0.0);
    }
    else
    {
        diffuse_product = light_diffuse * material_diffuse;
    }
    
    if (specular_mode < 0.0)
    {
        specular_product = vec4(0.0, 0.0, 0.0, 0.0);
    }
    else
    {
        specular_product = light_specular * material_specular;
    }
    
    glUniform4fv( glGetUniformLocation(program, "AmbientProduct"), 1, ambient_product );
    glUniform4fv( glGetUniformLocation(program, "DiffuseProduct"), 1, diffuse_product );
    glUniform4fv( glGetUniformLocation(program, "SpecularProduct"), 1, specular_product );
    glUniform4fv( glGetUniformLocation(program, "LightPosition"), 1, light_position );
    glUniform1f( glGetUniformLocation(program, "Shininess"), material_shininess );
    glUniform1i( ShadingMode, true );
}

void init_shader()
{
    // Load shaders and use the resulting shader program
   program = InitShader( "vshader.glsl", "fshader.glsl" );
    glUseProgram( program );
    
    // Initialize the vertex position attribute from the vertex shader
    vPosition = glGetAttribLocation( program, "vPosition" );
    vNormal = glGetAttribLocation( program, "vNormal" );
    vColor = glGetAttribLocation( program, "vColor" );
    vTexCoord = glGetAttribLocation( program, "vTexCoord" );
    
    // Retrieve transformation uniform variable locations
    ModelView = glGetUniformLocation( program, "ModelView" );
    Projection = glGetUniformLocation( program, "Projection" );
    TextureFlagLoc = glGetUniformLocation( program, "TextureFlag" );
    ShadowFlagLoc = glGetUniformLocation( program, "ShadowFlag" );
    ShaderFlagLoc = glGetUniformLocation( program, "ShaderFlag" );
    initialize_shader_parameters(material_ambient, material_diffuse, material_specular, material_shininess);
}

void bronze(){
    material_ambient = vec4( 0.2125, 0.1275, 0.054, 1.0 );
    material_diffuse = vec4( 0.714, 0.4284, 0.18144, 1.0 );
    material_specular = vec4( 0.393548, 0.271906, 0.166721, 1.0 );
    material_shininess = 20.0;
    initialize_shader_parameters(material_ambient, material_diffuse, material_specular, material_shininess);
}

void blue_plastic()
{
    material_ambient = vec4( 0.0, 0.1, 0.06, 1.0 );
    material_diffuse = vec4( 0.0, 0.50980392, 0.50980392, 1.0 );
    material_specular = vec4( 0.50196078, 0.50196078, 0.50196078, 1.0 );
    material_shininess = 25.0;
    initialize_shader_parameters(material_ambient, material_diffuse, material_specular, material_shininess);
}

void silver(){
    material_ambient = vec4( 0.19225, 0.19225, 0.19225, 1.0 );
    material_diffuse = vec4( 0.50754, 0.50754, 0.50754, 1.0 );
    material_specular = vec4( 0.508273, 0.508273, 0.508273, 1.0 );
    material_shininess = 40.0;
    initialize_shader_parameters(material_ambient, material_diffuse, material_specular, material_shininess);
}

void gold(){
    material_ambient = vec4( 0.24725, 0.1995, 0.0745, 1.0 );
    material_diffuse = vec4( 0.75164, 0.60648, 0.22648, 1.0 );
    material_specular = vec4( 0.628281, 0.555802, 0.366065, 1.0 );
    material_shininess = 40.0;
    initialize_shader_parameters(material_ambient, material_diffuse, material_specular, material_shininess);
}

void pearl(){
    material_ambient = vec4( 0.25, 0.20725, 0.20725, 1.0 );
    material_diffuse = vec4( 1.0, 0.829, 0.829, 1.0 );
    material_specular = vec4( 0.296648, 0.296648, 0.296648, 1.0 );
    material_shininess = 8.8;
    initialize_shader_parameters(material_ambient, material_diffuse, material_specular, material_shininess);
}

void green_rubber(){
    material_ambient = vec4( 0.0, 0.05, 0.0, 1.0 );
    material_diffuse = vec4( 0.4, 0.5, 0.4, 1.0 );
    material_specular = vec4( 0.04, 0.7, 0.04, 1.0 );
    material_shininess = 7.8125;
    initialize_shader_parameters(material_ambient, material_diffuse, material_specular, material_shininess);
}
}
