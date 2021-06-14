//
//  Object.hpp
//  GraphicTermProject
//
//  Created by Aybüke Buket Akgül on 11.06.2021.
//  Copyright © 2021 Aybüke Buket Akgül. All rights reserved.
//

#ifndef Object_h
#define Object_h

#include "Angel.h"
#include "Decleration.h"
#include <stdio.h>

namespace Object {
void initialize_buffer(int index);
void colorcube();
void room();
void roof();
void
tetrahedron( int count );
void initialize_sphere_buffer();
void read_bunny();
void initialize_bunny_buffer();
}
#endif /* Object_h */
