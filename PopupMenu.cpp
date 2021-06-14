//
//  PopupMenu.cpp
//  GraphicTermProject
//
//  Created by Aybüke Buket Akgül on 11.06.2021.
//  Copyright © 2021 Aybüke Buket Akgül. All rights reserved.
//

#include "PopupMenu.h"
#include "Shader.h"
using namespace Decleration;

namespace PopupMenu {
void mode_popup_handling(int item);
void component_popup_handling(int item);
void light_popup_handling(int item);
void shinning_popup_handling(int item);
void shadow_popup_handling(int item);

void popup_menu(){

    // Create a menu for drawing mode
    int drawingModeMenu = glutCreateMenu(mode_popup_handling);
    
    // Add menu items
    glutAddMenuEntry("Wireframe", 0);
    glutAddMenuEntry("Shading", 1);
  
    // Create a menu for component mode
    int componentModeMenu = glutCreateMenu(component_popup_handling);
    
    // Add menu items
    glutAddMenuEntry("Turn on/off Ambient", 0);
    glutAddMenuEntry("Turn on/off Diffuse", 1);
    glutAddMenuEntry("Turn on/off Specular", 2);
    
    // Create a menu for light mode
    int lightModeMenu = glutCreateMenu(light_popup_handling);
    
    // Add menu items
    glutAddMenuEntry("Fixed", 0);
    glutAddMenuEntry("Moving", 1);
    
    glutCreateMenu(NULL);
    glutAddSubMenu("Drawing Mode", drawingModeMenu);
    glutAddSubMenu("Component Mode", componentModeMenu);
    glutAddSubMenu("Light Mode", lightModeMenu);
    
    // Associate a mouse button with menu
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    
}

// Drawing mode handling, sets the drawing_mode to corresponding macro
void mode_popup_handling(int item){
    
    switch (item) {
        case 0:
            drawing_mode = GL_LINES;
            break;
        case 1:
            drawing_mode = GL_TRIANGLES;
            break;
        default:
            break;
     
    }
    //glUniform1i(TextureFlagLoc, textureFlag);
    glutPostRedisplay();
    return;
}

// Component mode handling, sets the componet_mode to corresponding macro
void component_popup_handling(int item){
    
    switch (item) {
        case 0:
            ambient_mode *= -1;
            break;
        case 1:
            diffuse_mode *= -1;
            break;
        case 2:
            specular_mode *= -1;
            break;
        default:
            break;
    }
    
    glutPostRedisplay();
    return;
}

// Light mode handling, sets the light_mode to corresponding macro
void light_popup_handling(int item){
        switch (item) {
        case 0:
            fixedLight = true;
            break;
        case 1:
            fixedLight = false;
            break;
        default:
            break;
        }
    glutPostRedisplay();
    return;
}

// Light mode handling, sets the light_mode to corresponding macro
void shinning_popup_handling(int item){
        switch (item) {
        case 1:
            {
                material_ambient = vec4( 1.0, 0.0, 1.0, 1.0 );
                material_diffuse = vec4( 1.0, 0.8, 0.0, 1.0 );
                material_specular = vec4( 1.0, 0.8, 0.0, 1.0 );
                material_shininess = 50.0;
                Shader::initialize_shader_parameters(material_ambient, material_diffuse, material_specular, material_shininess);
                break;
            }
        case 2:
                Shader::blue_plastic();
                break;
        case 4:
                Shader::silver();
                break;
        case 5:
                Shader::pearl();
                break;
        case 0:
                Shader::green_rubber();
                break;
        case 6:
                Shader::gold();
                break;
        case 3:
                Shader::bronze();
                break;
        default:
            break;
    }
    glutPostRedisplay();
    return;
}



}
