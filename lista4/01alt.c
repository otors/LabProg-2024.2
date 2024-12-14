#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define W 3 //Tamanho do lado da matriz que percorre a imagem

void mostrar_matriz(unsigned char *matriz_p, int n, int m); //Prototipo da função 'mostrar_matriz'
void mostrar_mask(unsigned char mask[W][W]); //Prototipo da função 'mostrar_mask'
void preencher_mask(unsigned char mask[W][W], unsigned char *matriz_p, int n, int m, int linha, int coluna); //Prototipo da função 'preencher_mask'
unsigned char gerar_binario_da_mask(unsigned char mask[W][W]); //Prototipo da função 'gerar_binario_da_mask'

int main(int argc, char const *argv[])
{
    srand(time(NULL)); //Definição da seed do 'rand()'

    // Declaração, alocação dinâmica, preenchimento e exibição da matriz 'img'.
    int width, height;
    unsigned char *img_p = NULL; // Declaração

    // Coleta de dados para alocação dinâmica
    printf("Digite a largura da imagem (px): ");
    scanf("%d", &width);
    printf("Digite a altura da imagem (px): ");
    scanf("%d", &height);

    img_p = (unsigned char *) malloc(width*height*sizeof(unsigned char)); // Alocação dinâmica

    if (!img_p) {
        puts("Memória insuficiente!");
        exit(1);
    }

    for (int i = 0; i < height*width; i++) {*(img_p+i) = rand() % 256;} // Preenchimento
    puts("Imagem:");
    mostrar_matriz(img_p, height, width); // Exibição

    // Declaração e preenchimento da matriz 'lbp' e do histograma.
    unsigned histograma[256] = {0}; // Declaração do histograma
    unsigned char *lbp_p = NULL; //Declaração da imagem LBP
    lbp_p = (unsigned char *) malloc(width*height*sizeof(unsigned char)); // Alocação dinâmica da imagem LBP

    if (!lbp_p) {
        puts("Memória insuficiente!");
        exit(2);
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            //'mask' poderia ser somente um 'unsigned char' para usar menos memória
            unsigned char mask[W][W] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}; //Reseta 'mask' a cada pixel da imagem
            preencher_mask(mask, img_p, height, width, i, j);
            // mostrar_mask(mask);
            *(lbp_p+(i*width)+j) = gerar_binario_da_mask(mask); // Preenchimento
            histograma[*(lbp_p+(i*width)+j)]++;
        }
    }

    puts("LBP:");
    mostrar_matriz(lbp_p, height, width); // Exibição da matriz 'lbp'

    //Exibição do Histograma
    printf("Histograma:\n[");
    for (int k = 0; k < 256; k++) {
        (k == 255) ? printf("%d]\n", histograma[k]) : printf("%d, ", histograma[k]);
    }

    return 0;
}

/**
 * @brief Função que mostra uma matriz NxM recebida como parametro.
 * A função só aceita matrizes NxM, o que funciona para o caso desse 
 * programa, podendo exibir a Imagem e o LBP. Uma melhoria seria 
 * generalizar a função para matrizes de tamanhos arbitrarios, 
 * recebios como parametros.
 * 
 * @param matriz_p Ponteiro para a matriz a ser mostrada
 * @param n Número de linhas da matriz a ser mostrada
 * @param m Número de colunas da matriz a ser mostrada
 */
void mostrar_matriz(unsigned char *matriz_p, int n, int m) {
    for (int i = 0; i < n; i++) {
        printf("[");
        for (int j = 0; j < m; j++) {
            (j == m-1) ? printf("%03d]\n", *(matriz_p+(i*m)+j)): printf("%03d, ", *(matriz_p+(i*m)+j));
        }
    }
    printf("\n");
}

/**
 * @brief Função que mostra uma matriz WxW recebida como parametro.
 * A função serve propositos de debug.
 * 
 * @param mask Matriz a ser mostrada
 */
void mostrar_mask(unsigned char mask[W][W]) {
    for (int i = 0; i < W; i++) {
        printf("[");
        for (int j = 0; j < W; j++) {
            (j == W-1) ? printf("%03d]\n", mask[i][j]): printf("%03d, ", mask[i][j]);
        }
    }
    printf("\n");
}

/**
 * @brief Preenche a matriz 'mask' comparando o elemento de referência
 * 'matriz[linha][coluna]' com os seus vizinhos no range 'W/2', 
 * preenchendo com 1 os valores maiores ou iguais ao de referência, e 
 * com 0 os menores.
 * 
 * @param mask Matriz WxW que será preenchida.
 * @param matriz_p Ponteiro para a matriz NxM de referencia para o preenchimento.
 * @param n Número de linhas da matriz de referência
 * @param m Número de colunas da matriz de referência
 * @param linha Linha de referencia da 'matriz'.
 * @param coluna Coluna de referencia da 'matriz'.
 */
void preencher_mask(unsigned char mask[W][W], unsigned char *matriz_p, int n, int m, int linha, int coluna) {
    for (int i = linha-(W/2); i < linha+(W/2)+1; i++) {
        for (int j = coluna-(W/2); j < coluna+(W/2)+1; j++) {
            // mask[(W/2)+i-linha][(W/2)+j-coluna] = !((i<0 || j<0) || (i>=N || j>=M)) && (matriz[i][j] >= matriz[linha][coluna]) ? 1 : 0;
            if ((i < 0 || j < 0) || (i >= n || j >= m)) {
                mask[(W/2)+i-linha][(W/2)+j-coluna] = 0;
            } else {
                if (*(matriz_p+(i*m)+j) >= *(matriz_p+(linha*m)+coluna)) {
                    mask[(W/2)+i-linha][(W/2)+j-coluna] = 1;
                } else {
                    mask[(W/2)+i-linha][(W/2)+j-coluna] = 0;
                }
            }
        }
    }    
}

/**
 * @brief Recebe uma matriz 'mask' WxW, e gera um binario iterando 
 * sobre a matriz em sentido horário começando pelo elemento [0][0]
 * e ignorando o elemento central.
 * 
 * @param mask Matriz WxW que será usada de referência para construção do binário.
 * @return unsigned char 
 */
unsigned char gerar_binario_da_mask(unsigned char mask[W][W]) {
    unsigned char binary = 0;
    for (int k = 0; k < (W*W)-1; k++) {
        if (k < 3) {
            binary += mask[0][k] << k;
        } else if (k == 3) {
            binary += mask[1][2] << k;
        } else if (k > 3 && k <= (2*W)) {
            binary += mask[2][(2*W)-k] << k;
        } else {
            binary += mask[1][0] << k;
        }
    }
        
    return binary;
}