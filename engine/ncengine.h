#include <iostream>

#pragma region DEFINE STRUCTS 

struct Charmap {
    std::string object_name;
    char** charmap;
    int s_width;
    int s_height;
};

#pragma endregion

#pragma region DEFINE FUNCTIONS

Charmap nc_create_charmap(std::string object_name, int sprite_width, int sprite_height, char** array)
{
    Charmap cm;
    cm.object_name = object_name;
    cm.s_width = sprite_width;
    cm.s_height = sprite_height;
    cm.charmap = new char*[sprite_height];
    for (int i = 0; i < sprite_height; i++) {
        cm.charmap[i] = new char[sprite_width];
        for (int j = 0; j < sprite_width; j++) {
            cm.charmap[i][j] = array[i][j];
        }
    }
    return cm;
}

char** nc_convert_to_double_pointer(char charmap[][3], int s_height, int s_width) {
    char** result = new char*[s_height];
    for (int i = 0; i < s_height; i++) {
        result[i] = new char[s_width];
        for (int j = 0; j < s_width; j++) {
            result[i][j] = charmap[i][j];
        }
    }
    return result;
}

Charmap nc_parse_charmap(std::string object_name, int sprite_width, int sprite_height)
{
    Charmap cm;
    cm.object_name = object_name;
    cm.s_width = sprite_width;
    cm.s_height = sprite_height;

    // Allocate memory for the charmap
    cm.charmap = new char*[sprite_height];
    for (int i = 0; i < sprite_height; i++) {
        cm.charmap[i] = new char[sprite_width];
    }

    return cm;
}

void nc_print_charmap(const Charmap& cm)
{
    std::cout << "Object name: " << cm.object_name << std::endl;
    std::cout << "Dimensions: " << cm.s_width << "x" << cm.s_height << std::endl;

    for (int i = 0; i < cm.s_height; i++) {
        for (int j = 0; j < cm.s_width; j++) {
            std::cout << cm.charmap[i][j];
        }
        std::cout << std::endl;
    }
}

void nc_free_charmap(Charmap& cm)
{
    // Deallocate memory for the charmap
    for (int i = 0; i < cm.s_height; i++) {
        delete[] cm.charmap[i];
    }
    delete[] cm.charmap;
}

#pragma endregion