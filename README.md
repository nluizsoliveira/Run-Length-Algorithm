# Run-Length-Algorithm
Run Length Algorithm for compressing and decompressing .pgm images 

## Objetivos:

### 1- Compressão: 
Comprimir imagens .pgm usando o algoritmo **run-length**. A técnica consiste em representar cadeias com caracteres repetidos de uma mesma linha no formato **@CN**, sendo

- **@** o indicador de que a cadeia a seguir está comprimida
- **C** o caractere que se repete. 
- **N** o número de caracteres repeditos em tal cadeia


Por exemplo, a sequência ```BAAAAAAAAAAC``` passa a ser representada como ```B@A10C```.

A convenção para o tipo de PGM convertido adotada é **P8**.

**A compressão só é feita se |cadeia| > 3**. (Ex: ```AAA```  **NÃO** será convertido em  ```@A3```, pois |AAA| == |@A3|, o que não economiza caracteres). 

### 2- Decompressão: 
Busca por cadeias em formato **@CN** e as transforma em seu estado original. 

## Entrada:
Imput no formato PGM. Caso o tipo de .pgm seja **```P8```**, o algoritmo de decompressão e executado. Caso contrário, o algoritmo de compressão é executado. 

Ex: Imput que representa um .pgm a ser comprimido: 
```
P2
24 7
15
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  3  3  3  3  0  0  7  7  7  7  0  0 11 11 11 11  0  0 15 15 15 15  0
0  3  0  0  0  0  0  7  0  0  0  0  0 11  0  0  0  0  0 15  0  0 15  0
0  3  3  3  0  0  0  7  7  7  0  0  0 11 11 11  0  0  0 15 15 15 15  0
0  3  0  0  0  0  0  7  0  0  0  0  0 11  0  0  0  0  0 15  0  0  0  0
0  3  0  0  0  0  0  7  7  7  7  0  0 11 11 11 11  0  0 15  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
```


## Saída 
Imagem processada. Caso uma imagem standard seja **imputada (```P != P8```)**, a saída será uma imagem decomprimida. Caso uma imagem comprimida **(```P == P8```)** seja imputada, a saída será uma imagem pgm padrão. 


```
P8
24 7
15
@ 0 24
0 @ 3 4 0 0 @ 7 4 0 0 @ 11 4 0 0 @ 15 4 0
0 3 @ 0 5 7 @ 0 5 11 @ 0 5 15 0 0 15 0
0 3 3 3 0 0 0 7 7 7 0 0 0 11 11 11 0 0 0 @ 15 4 0
0 3 @ 0 5 7 @ 0 5 11 @ 0 5 15 @ 0 4
0 3 @ 0 5 @ 7 4 0 0 @ 11 4 0 0 15 @ 0 4
@ 0 24
```
