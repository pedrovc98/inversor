/* Data de submissao: 17/03/2020
 * Nome: Pedro Vieira de Carvalho
 * RA:204773
 */

#include <stdio.h>
const int tam_buffer=100;

int main() {
  char buffer_in[tam_buffer]; // Armazena string de entrada 
  char buffer_out[tam_buffer]; // Armazena string de saida

  int word_begin=0; // Posicao do inicio da palavra
  int word_end=0; // Primeira posicao depois do fim da palavra
  int i=0; // Contador auxiliar
  int word_size=0; // Tamanho da palavra em questao
  int end_flag = 0; // Indica o fim da inversao de palavras

  fgets(buffer_in, tam_buffer, stdin); 

  while(end_flag == 0){ 

    // Apontamos o inicio da nova palavra
    word_begin = word_end; 

    // Fazemos uma varredura ate achar o fim da palavra
    while(buffer_in[word_end]!='\n' && buffer_in[word_end]!=' '){
      word_end++;
    }

    // Encontramos o tamanho da palavra lida
    word_size = word_end-word_begin;

    // Copiamos a palavra invertida para a string de saida
    for(i=0;i<word_size;i++){
      buffer_out[word_begin+i] = buffer_in[word_end-i-1];
    }

    // Copiamos o espaco ou a quebra de linha para a string de saida
    buffer_out[word_end] = buffer_in[word_end];

    // Se for um espaco, continuamos, se for uma quebra de linha, acabou a inversao
    if(buffer_in[word_end]=='\n'){
      end_flag = 1;
    }
    else{
      word_end++;
    }
  }

  printf("%s", buffer_out);
  return 0;
}
