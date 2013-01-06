//
// menu.cpp
// interface
//
// Created by stephen schuresko on 11/16/12.
//
//

#include "menu.h"
#include "util.h"


#define MAX_LEN 100
#define MENU_WIDTH 80
#define MENU_HEIGHT 15
/*
 int Xpos, Ypos
 char ** top_items;
 int top_item_count;
 char *** menu_items;
 int * menu_item_count;*/

typedef char* cptr;
typedef char** cpptr;
void menu::init( int X, int Y){
    Xpos=X;
    Ypos=Y;
    top_items = new cptr[MAX_LEN];
    menu_items= new cpptr[MAX_LEN];
    menu_item_count = new int[MAX_LEN];
    top_item_count=0;
    for(int N=0;N<MAX_LEN;N++){
        menu_items[N]= new cptr[MAX_LEN];
        menu_item_count[N]=0;
    }
    
    selected_menu=-1;
}
void menu::draw(int mouse_x, int mouse_y, int mouse_down){
    for(int N=0;N<top_item_count;N++)
        drawtext(Xpos+N*MENU_WIDTH, Ypos,0.09,0,1.0,0,top_items[N],1,0,0);
    // drawtext(<#int x#>, <#int y#>, <#float scale#>, <#float rotate#>, <#float thick#>, <#int mono#>, <#char *string#>)
    
    
    
    if (mouse_down==1){
        for(int N=0;N<top_item_count;N++){
            int min_X=Xpos+N*MENU_WIDTH,
            max_X = Xpos+(N+1)*MENU_WIDTH,
            min_Y = Ypos - MENU_HEIGHT,
            max_Y = Ypos ;
            if( mouse_x >= min_X
               && mouse_x <= max_X
               && mouse_y >= min_Y
               && mouse_y <= max_Y)
            {
                // std::cout<<"selected menu: "<<N<<std::endl;
                selected_menu=N;
            }
            
        }
        
        if(selected_menu >= 0){
            for(int N=0;N<menu_item_count[selected_menu];N++){
                if(mouse_y > Ypos+MENU_HEIGHT*N && mouse_y <=Ypos+MENU_HEIGHT*(N+1))
                    drawtext(Xpos+selected_menu*MENU_WIDTH,
                             Ypos+MENU_HEIGHT*(N+1), 0.09, 0, 1.0, 0, menu_items[selected_menu][N],0,1,0);
                else
                    drawtext(Xpos+selected_menu*MENU_WIDTH,
                             Ypos+MENU_HEIGHT*(N+1), 0.09, 0, 1.0, 0, menu_items[selected_menu][N],1,1,1);
            }
            
        }
        
        
    }
    else
    {
        
        
        if(selected_menu >= 0){
            for(int N=0;N<menu_item_count[selected_menu];N++){
                if(mouse_y > Ypos+MENU_HEIGHT*N && mouse_y <=Ypos+MENU_HEIGHT*(N+1))
                    functions[selected_menu][N]();
            }
            
        }
        
        if (mouse_x <Xpos || mouse_x > Xpos + top_item_count*MENU_WIDTH)
            selected_menu=-1;
    }
    
}
void menu::add_top_item(char * text){
    top_items[top_item_count]=text;
    top_item_count++;
    
}
void menu::add_menu_item(int menu_no, char * text, void(*action)() ){
    int current_menu_count = menu_item_count[menu_no];
    menu_items[menu_no][current_menu_count]=text;
    menu_item_count[menu_no]++;
    functions[menu_no][current_menu_count]=action;
    
    
    
    
}