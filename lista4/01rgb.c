#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct pixel {
    unsigned char r, g, b;
} Pixel;

typedef enum display {
    HEX,
    RGB,
    BLOCKS
} Display;

#define WIDTH 80
#define HEIGHT 45
#define MX 256
#define W 3

Pixel generateRandomPixel();
void setTextColor(unsigned char r, unsigned char g, unsigned char b);
void setBlockColor(unsigned char r, unsigned char g, unsigned char b);
void resetFormatting();
void printPixel(Pixel, Display, int );
void printImageMatrix(Pixel **, int, int, Display, int);
void fillMask(Pixel [W][W], Pixel **, int, int, int, int);
Pixel generateMaskBinary(Pixel [W][W]);

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int width = WIDTH, height = HEIGHT;

    Pixel **image = malloc(height * sizeof(Pixel *));
    for (int i = 0; i < height; i++) {image[i] = malloc(width * sizeof(Pixel));}

    for (int i = 0; i < height; i++) {for (int j = 0; j < width; j++) {image[i][j] = generateRandomPixel();}}

    puts("Imagem:");
    // printImageMatrix(image, width, height, HEX, 1);
    // printImageMatrix(image, width, height, RGB, 1);
    printImageMatrix(image, width, height, BLOCKS, 0);
    
    // Declaração e preenchimento da matriz 'lbp' e do histograma.
    Pixel **lbp = malloc(height * sizeof(Pixel *)); // Declaração da imagem LBP
    for (int i = 0; i < height; i++) {lbp[i] = malloc(width * sizeof(Pixel));}
    unsigned histograma[3][256] = {0}; // Declaração do histograma

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            Pixel mask[W][W] = {0};
            fillMask(mask, image, i, j, width, height);
            // printImageMatrix(mask, 3, 3, HEX, 1);
            lbp[i][j] = generateMaskBinary(mask); // Preenchimento
            histograma[0][lbp[i][j].r]++;
            histograma[1][lbp[i][j].g]++;
            histograma[2][lbp[i][j].b]++;
        }
    }

    // Exibição da matriz 'lbp'
    puts("LBP:");
    //printImageMatrix(lbp, width, height, HEX, 1);
    // printImageMatrix(lbp, width, height, RGB, 1);
    printImageMatrix(lbp, width, height, BLOCKS, 0);

    printf("Histograma:\n");
    for (int i = 0; i < 3; i++) {
        i == 0 ? printf("RED → [") : i == 1 ? printf("GREEN → [") : printf("BLUE → [");
        for (int k = 0; k < 256; k++) {
            (k == 255) ? printf("%d]\n", histograma[i][k]) : printf("%d, ", histograma[i][k]);
        }
    }

    for (int i = 0; i < height; i++) {free(image[i]);}
    free(image);
    for (int i = 0; i < height; i++) {free(lbp[i]);}
    free(lbp);

    return 0;
}

Pixel generateRandomPixel() {
    Pixel p;
    p.r = rand() % 256;
    p.g = rand() % 256;
    p.b = rand() % 256;
    return p;
}

void setTextColor(unsigned char r, unsigned char g, unsigned char b) {
    printf("\033[38;2;%d;%d;%dm", r, g, b);  // Set foreground color
}

// ANSI escape code to print colored block
void setBlockColor(unsigned char r, unsigned char g, unsigned char b) {
    printf("\033[48;2;%d;%d;%dm  \033[0m", r, g, b);  // Set background color with space block
}

// Reset console formatting
void resetFormatting() {
    printf("\033[0m");
}

/**
 * @brief Prints a given pixel on the given way, mode and colored or not.
 * 
 * @param p Given pixel to print.
 * @param mode HEX, RGB or BLOCKS. Sets how the pixel will be printed.
 * @param colored !=0 to color the HEX and RGB modes.
 */
void printPixel(Pixel const p, Display mode, int colored) {
    switch (mode) {
        case HEX:
            if (colored) setTextColor(p.r, p.g, p.b);
            printf("#%02X%02X%02X", p.r, p.g, p.b);
            if (colored) resetFormatting();
            break;
        case RGB:
            if (colored) setTextColor(p.r, p.g, p.b);
            printf("RGB(%3d, %3d, %3d)", p.r, p.g, p.b);
            if (colored) resetFormatting();
            break;
        case BLOCKS:
            setBlockColor(p.r, p.g, p.b);
            break;
    }
}

/**
 * @brief Prints the given 'img', basing the print on the Display mode, and whether it is colored or not.
 * 
 * @param img Pointer to matrix of 'Pixel'.
 * @param width Width of 'img'. 
 * @param height Height of 'img'.
 * @param mode HEX, RGB or BLOCKS. Sets how 'img' will be printed.
 * @param colored !=0 to color the HEX and RGB modes.
 */
void printImageMatrix(Pixel **img, int width, int height, Display mode, int colored) {
    for (int i = 0; i < height; i++) {
        if (mode != BLOCKS) printf("{");
        for (int j = 0; j < width; j++) {
            printPixel(img[i][j], mode, colored);
            if (mode != BLOCKS) (j == width-1) ? printf("}"): printf(", ");
        }
        printf("\n");
    }
}

void fillMask(Pixel mask[W][W], Pixel **img, int row, int col, int width, int height) {
    int offset = W / 2;  // Calculate once, reuse
    int startRow = row - offset;
    int endRow = row + offset;
    int startCol = col - offset;
    int endCol = col + offset;

    for (int i = startRow; i <= endRow; i++) {
        for (int j = startCol; j <= endCol; j++) {
            int maskRow = (i - startRow);
            int maskCol = (j - startCol);

            // Check if (i, j) is out of bounds
            if (i < 0 || j < 0 || i >= height || j >= width) {
                mask[maskRow][maskCol].r = 0;
                mask[maskRow][maskCol].g = 0;
                mask[maskRow][maskCol].b = 0;
            } else {
                // Set mask values based on the comparison
                mask[maskRow][maskCol].r = (img[i][j].r >= img[row][col].r) ? 1 : 0;
                mask[maskRow][maskCol].g = (img[i][j].g >= img[row][col].g) ? 1 : 0;
                mask[maskRow][maskCol].b = (img[i][j].b >= img[row][col].b) ? 1 : 0;
            }
        }
    }
}

Pixel generateMaskBinary(Pixel mask[W][W]) {
    Pixel binary = {0, 0, 0};
    for (int k = 0; k < (W * W) - 1; k++) {
        int row, col;
        
        // Determine the row and column for each k value.
        if (k < 3) {
            row = 0;
            col = k;
        } else if (k == 3) {
            row = 1;
            col = 2;
        } else if (k <= (2 * W)) {
            row = 2;
            col = (2 * W) - k;
        } else {
            row = 1;
            col = 0;
        }

        // Use the row and column to index the mask array and accumulate the color components.
        binary.r += mask[row][col].r << k;
        binary.g += mask[row][col].g << k;
        binary.b += mask[row][col].b << k;
    }
        
    return binary;
}