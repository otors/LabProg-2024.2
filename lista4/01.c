#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 2 //Número de linhas da matriz imagem
#define M 2 //Número de colunas da matriz imagem
#define W 3 //Tamanho do lado da matriz que percorre a imagem

void mostrar_matriz(unsigned char matriz[N][M]); //Prototipo da função 'mostrar_matriz'
void mostrar_mask(unsigned char mask[W][W]); //Prototipo da função 'mostrar_mask'
void preencher_mask(unsigned char mask[W][W], unsigned char matriz[N][M], int linha, int coluna); //Prototipo da função 'preencher_mask'
unsigned char gerar_binario_da_mask(unsigned char mask[W][W]); //Prototipo da função 'gerar_binario_da_mask'

int main(int argc, char const *argv[])
{
    srand(time(NULL)); //Definição da seed do 'rand()'

    // Declaração, preenchimento e exibição da matriz 'img'.
    unsigned char img[N][M]; // Declaração
    for (int i = 0; i < N; i++) {for (int j = 0; j < M; j++) {img[i][j] = rand() % 256;}} // Preenhimento
    puts("Imagem:");
    mostrar_matriz(img); // Exibição

    // Declaração e preenchimento da matriz 'lbp' e do histograma. 
    unsigned char lbp[N][M]; // Declaração da imagem LBP
    unsigned histograma[256] = {0}; // Declaração do histograma
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            //'mask' poderia ser somente um 'unsigned char' para usar menos memória, modificando algumas partes do código
            unsigned char mask[W][W] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}; //Reseta 'mask' a cada pixel da imagem
            preencher_mask(mask, img, i, j);
            // mostrar_mask(mask);
            lbp[i][j] = gerar_binario_da_mask(mask); // Preenchimento
            histograma[lbp[i][j]]++;
        }
    }
    puts("LBP:");
    mostrar_matriz(lbp); // Exibição da matriz 'lbp'

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
 * @param matriz Matriz a ser mostrada
 */
void mostrar_matriz(unsigned char matriz[N][M]) {
    for (int i = 0; i < N; i++) {
        printf("[");
        for (int j = 0; j < M; j++) {
            (j == M-1) ? printf("%03d]\n", matriz[i][j]): printf("%03d, ", matriz[i][j]);
        }
    }
    printf("\n");
}

/**
 * @brief Função que mostra uma matriz WxW recebida como parametro.
 * A função serve propositos de debug.
 * 
 * @param matriz Matriz a ser mostrada
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
 * @param matriz Matriz NxM de referencia para o preenchimento.
 * @param linha Linha de referencia da 'matriz'.
 * @param coluna Coluna de referencia da 'matriz'.
 */
void preencher_mask(unsigned char mask[W][W], unsigned char matriz[N][M], int linha, int coluna) {
    for (int i = linha-(W/2); i < linha+(W/2)+1; i++) {
        for (int j = coluna-(W/2); j < coluna+(W/2)+1; j++) {
            // mask[(W/2)+i-linha][(W/2)+j-coluna] = !((i<0 || j<0) || (i>=N || j>=M)) && (matriz[i][j] >= matriz[linha][coluna]) ? 1 : 0;
            if ((i < 0 || j < 0) || (i >= N || j >= M)) {
                mask[(W/2)+i-linha][(W/2)+j-coluna] = 0;
            } else {
                if (matriz[i][j] >= matriz[linha][coluna]) {
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