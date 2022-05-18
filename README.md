## ppm-file-handling 
Manipulação de arquivos e
Tratamento de imagens ppm 

#### Atividade desenvolvida na disciplina de Algoritmos e programação - UFRGS (2022),
##### créditos às explicações e fórmulas

##
### O que é uma imagem em formato ppm?
   O formato de imagem `PPM (Portable PixMap)` é utilizado para armazenar imagens coloridas. Seus arquivos possuem um cabeçalho que identifica esse tipo de arquivos. Todas as informações são gravadas em código ASCII, como texto. 

##

### O cabeçalho...
   Ocupa as três primeiras linhas do arquivo. A primeira linha contém os caracteres P3 identificando o formato PPM. Na linha seguinte, a largura da figura e sua altura. O terceiro inteiro corresponde ao valor máximo da escala RGB.
  
 ```
 P3
 
 50 50
 
 255
 ```

##

### Representação da imagem
  No formato PPM a cor de cada pixel é representada por três inteiros positivos menores que 256. Cada inteiro corresponde, respectivamente, à intensidade das componentes Vermelha, Verde e Azul da cor. Ou seja, para o exemplo acima, com largura e altura `50 50`, para cada "pixel" (valor correspondente deste 50), haverá 3 valores correspondentes as cores. 
  ```
   Exemplo de representação
   
   P3
   
   2 2
   
   255
   
   0 0 0 0 0 0
   0 0 0 0 0 0
   
  ```
##

### Os filtros

![Captura de tela de 2022-05-18 18-53-57](https://user-images.githubusercontent.com/76853394/169163085-a20acae0-0847-458a-ac28-ec0a6161c1fa.png)

Um filtro de `negativo` consiste em inverter o valor de cada um dos componentes da cor. Ou seja, se o valor r, g, ou b for 255 ele deve se tornar 0, se for 254 deve se tornar 1, e vice-versa.

![Captura de tela de 2022-05-18 18-54-07](https://user-images.githubusercontent.com/76853394/169163102-a265ab12-4af0-4e43-b081-b779624499cf.png)

O filtro de `sépia` pode ser obtido através das seguintes equações: 

```
tr = (int)(0.393R + 0.769G + 0.189B) 
tg = (int)(0.349R + 0.686G + 0.168B) 
tb = (int)(0.272R + 0.534G + 0.131B) 
```
O novo valor RGB do pixel deve ser determinado de acordo com as seguintes condições: 
```
Se tr > 255 então r = 255, senão r = tr 
Se tg > 255 então g = 255, senão g = tg 
Se tb > 255 então b = 255, senão b = tb 
```
![Captura de tela de 2022-05-18 18-54-15](https://user-images.githubusercontent.com/76853394/169163260-d48e28ca-de6d-48dc-8cf0-75b870e2a9ee.png)


