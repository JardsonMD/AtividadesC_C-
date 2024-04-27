#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

void gotoxy( int column, int line )
  {
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    coord
    );
  }

int wherex()
  {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  COORD                      result;
  if (!GetConsoleScreenBufferInfo(
         GetStdHandle( STD_OUTPUT_HANDLE ),
         &csbi
         ))
    return -1;
  return result.X;
  }

int wherey()
  {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  COORD                      result;
  if (!GetConsoleScreenBufferInfo(
         GetStdHandle( STD_OUTPUT_HANDLE ),
         &csbi
         ))
    return -1;
  return result.Y;
  }

// Fun��o para desenhar uma linha usando o algoritmo de Bresenham
// Recebe como parametros as poci��es iniciais e finais da linha 
void drawLine(int x0, int y0, int x1, int y1) {

// Calcula a diferen�a entre os pontos para saber a quantidade total de pixels que ser�o percorridos
	int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    
// Determina a dire��o que esta sendo seguida 1 para positivo ou -1 para negativo, desse modo as coordenadas de x por exemplo iriam para a 
// direita ou esquerda respectivamente
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;

// Calcula o erro inicial do algoritmo de Bresenham. O erro � uma vari�vel que controla a inclina��o da linha determinando quando mudar a 
// dire��o do desenho
    int err = dx - dy;

// Loop para desenhar cada pixel da linha
    while (x0 != x1 || y0 != y1) {
    
	// Desenha o pixel nas coordenadas enviadas por parametro     
		gotoxy(x0, y0);
		putchar('*');
	
	// Calcula o dobro do erro atual, para determinar quando o x ou y devem ser incrementados a variavel de erro deve acompanhar o desenho
	// da linha
        int err2 = 2 * err;
        
    // Verifica se o dobro do erro � maior que a diferen�a de y, se isso for verdade significa que a inclina��o da linha est� mais proxima
    // de ser horizontal (0), ou seja, o proximo ponto a se incrementar na linha deve ser em x 
        if (err2 > -dy) {
            
    	// Atualiza o valor do erro, retirando a diferen�a de y para corrigir o erro acumulado ao longo da linha
			err -= dy;
		
		// Move o ponto para o pr�ximo pixel na dire��o horizontal
            x0 += sx;
        }
    
	// Verifica se o dobro do erro � menor que a diferen�a de x, se isso for verdade significa que a inclina��o da linha est� mais proxima
    // de ser vertical (90 graus), ou seja, o proximo ponto a se incrementar na linha deve ser em y
        if (err2 < dx) {
           
	  	// Atualiza o valor do erro, retirando a diferen�a de x para corrigir o erro acumulado ao longo da linha
		    err += dx;
        
        // Move o ponto para o pr�ximo pixel na dire��o vertical
            y0 += sy;
        }
    }
}
int main(void) {
	 
    drawLine(1, 2 , 8, 12);

    return 0;
}
