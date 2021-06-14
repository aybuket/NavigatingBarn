//
//  PopupMenu.hpp
//  GraphicTermProject
//
//  Created by Aybüke Buket Akgül on 11.06.2021.
//  Copyright © 2021 Aybüke Buket Akgül. All rights reserved.
//

#ifndef PopupMenu_h
#define PopupMenu_h

#include <stdio.h>
#include "Angel.h"
#include "Decleration.h"

namespace PopupMenu {
void mode_popup_handling(int item);
void component_popup_handling(int item);
void light_popup_handling(int item);
void shinning_popup_handling(int item);

void popup_menu();
}

#endif /* PopupMenu_h */
