#include <iostream>
#include <stdlib.h>

// using std::cout;
#define display_size_x 20
#define display_size_y 20

// TODO optimize array display output speed add different sleep function
void print_display(char display[display_size_y][display_size_x]){
    // draw display borders
    for (int i = 0; i < display_size_y; i++)
    {
        display[0][i]='x';
        display[i][0]='x';
        display[display_size_y-1][i]='x';
        display[i][display_size_x-1]='x';
        
    }
    // output display 
     for (int i = 0; i < display_size_y; i++){
        std::cout << std::endl;
        for (int j = 0; j < display_size_x; j++)
        {
            std::cout << "  " << display[i][j];
        }
    }
    // delay 50ms   
    std::cout.flush();
    _sleep(33);
    system("CLS");
}

/*
TODO add fruit spawn logic
TODO add keyboard inputs 
TODO add snake movement logic, passtrough borders
TODO snake lenght changes, eating
*/
int main(void)
    {
    char display[display_size_y][display_size_x];
    int display_size = sizeof(display) / sizeof(display[0]);
     //display fill
    for (int i = 1; i < display_size; i++)
    {
        for (int j = 1; j < display_size; j++)
        {
            display[i][j] = '.';
        }
    }
    while (1)
    {    
       
    
    print_display(display);
    }
}