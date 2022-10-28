#include <iostream>

// using std::cout;
#define display_size_x 20
#define display_size_y 20

void print_display(char display[display_size_x][display_size_y]){
     for (int i = 0; i < display_size_y; i++){
        std::cout << std::endl;
        for (int j = 0; j < display_size_x; j++)
        {
            std::cout << " " << display[i][j];
        }
    }
}

int main(void)
    {
        // std::cout << "hello world" << std::endl;
    char display[display_size_x][display_size_y];
    int display_size = sizeof(display) / sizeof(display[0]);

    for (int i = 0; i < display_size; i++)
    {
        for (int j = 0; j < display_size; j++)
        {
            display[i][j] = 'x';
        }
    }

    print_display(display);
   
}