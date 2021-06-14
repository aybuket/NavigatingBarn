//
//  Shader.hpp
//  GraphicTermProject
//
//  Created by Aybüke Buket Akgül on 11.06.2021.
//  Copyright © 2021 Aybüke Buket Akgül. All rights reserved.
//

#ifndef Shader_h
#define Shader_h

#include <stdio.h>
#include "Angel.h"
#include "Decleration.h"

namespace Shader {
void initialize_shader_parameters(vec4 material_ambient, vec4 material_diffuse, vec4 material_specular,float  material_shininess);

void init_shader();
void bronze();
void gold();
void silver();
void blue_plastic();
void green_rubber();
void pearl();
}

#endif /* Shader_h */
