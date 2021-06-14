//
//  Texture.hpp
//  GraphicTermProject
//
//  Created by Aybüke Buket Akgül on 11.06.2021.
//  Copyright © 2021 Aybüke Buket Akgül. All rights reserved.
//

#ifndef Texture_h
#define Texture_h

#include "Angel.h"
#include "Decleration.h"
#include <stdio.h>
#include <iostream>
#include <fstream>

namespace Texture {
void
read_texture(std::string str, int imageIndex);
void
init_texture();
}

#endif /* Texture_h */
