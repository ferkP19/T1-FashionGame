# T1-FashionGame :)

## 1. Compilación del programa  
Este pequeño proyecto puede compilarse ya sea en VS CODE o directamente en la terminal con el compilador de g++ usando el siguiente comando:

**g++ fashion.cpp -o fashion.out**

## 2. Ejecución del programa 
Para poder ejecutarlo desde la terminal se utiliza el siguiente comando:
**./fashion.out**

## 3. Descripción de como funciona ✨
El programa implementa una simulación de un proceso de producción en la industria de la moda mediante un juego por turnos entre dos equipos.

Cada jugador representa un equipo de producción:

**Player 1:** Equipo de Moda Urbana
**Player 2:** Equipo de Alta Costura

El objetivo del sistema es modelar la producción de una colección de moda a través de un tablero de 30 casillas, donde cada casilla representa una fase del proceso productivo.

El primer jugador en alcanzar o superar la casilla 30 completa exitosamente la producción y termina el juego.

## 4. Jerarquía de herencias usadas
Se implementa una jerarquía de clases para modelar los distintos tipos de casillas:

**Tile** (clase base)
**NormalTile** (sin efecto)
**AdvanceTile** (incrementa la posición del jugador)
**SetbackTile** (reduce la posición del jugador)

Cada una hereda a la clase papá que es Tile, y las hijas tienen también atributos propios

## 4.1 Polimorfismo
El método applyEffect() es redefinido en las clases derivadas para implementar comportamientos específicos según el tipo de casilla, permitiendo la ejecución correspondiente como en el caso de la casilla **N**, **S** y **L**.

## 5. Lógica detras de este juego (realmente que se hace y que muestra)
El juego se ejecuta por turnos alternados entre los dos jugadores. En cada turno:
- Se solicita al usuario continuar o terminar el juego.
- Determina que el jugador exista.
- Simula el lanzamiento del dado.
- Se actualiza la posición del jugador.
- Identifica el tipo de casilla alcanzada.
- Aplica el efecto correspondiente (si aplica).
- Valida el rango de posiciones (1–30).
- Verifica condición de quien gano, si jugador 1 o 2.

## 6. Significado de las clases
**MyGame** control principal de la lógica del programa.
**Board** encapsula la estructura del tablero.
**Player** modela cada participante.
**Tile** modela el funcionamiento de las casillas mediante el polimorfismo.
**Dice** encapsula la lógica de generación aleatoria de los turnos.
  


