//
//  main.cpp
//  FractalWord
//
//  Created by 王子豪 on 2017/12/22.
//  Copyright © 2017年 王子豪. All rights reserved.
//

#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include "svpng.inc"
#include <cstring>
double mandelbrot(double x, double y) {
    double a = x, b = y;
    for(int i = 0; i < 256; ++i) {
        double c = a * a - b * b + x, d = 2 * a * b + y;
        a = c, b = d;
        if(a * a + b * b > 4) return 1 - i / 128.0;
    }
    return 0;
}
unsigned char data[4096 * 6144 * 3];
int main(void) {
    uint8_t* p = data;
    int counter = 0;
    for(int i = 0; i < 4096; ++i) {
        for(int j = 0; j < 6144; ++j) {
            uint8_t n = mandelbrot(j / 2048.0 - 2, i / 2048.0 - 1) * 255;
            *p++ = n; *p++ = n; *p++ = n;
            
            
        }
    }
    FILE* file = fopen("Mandelbrot.png", "wb");
    svpng(file, 6144, 4096, data, 0);
    fclose(file);
}
