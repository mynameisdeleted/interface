//
//  menu.h
//  interface
//
//  Created by stephen schuresko on 11/16/12.
//
//

#ifndef __interface__menu__
#define __interface__menu__

#include <iostream>
#define MENU_MAX_LEN 100

class menu {
public:
    
    void(*functions[MENU_MAX_LEN][MENU_MAX_LEN])(void);
    
    int selected_menu;
    int Xpos, Ypos;
    char ** top_items;
    int top_item_count;
    char *** menu_items;
    int * menu_item_count;
    void init( int X, int Y);
    void draw(int mouse_x, int mouse_y, int mouse_down);
    void add_top_item( char * text);
    void add_menu_item(int menu_no, char * text, void(*action)() );
};

#endif /* defined(__interface__menu__) */
