### Problema [link](https://codeforces.com/problemset/problem/230/A)

Neste problema existe um herói que luta contra dragões, cada dragão
tem uma força e um valor de bonus yi. O herói pode escolhe a sequência 
de dragões que ele pode lutar. A cada dragão derrotado ele adiciona a sua
força o seu valor de bonus. 

O problema é determina dada a força inicial do herói, a força dos dragões 
e os bonus se é possível derrotar todos os dragões.

O herói somente pode vencer um dragão com força menor do que a dele.


### Solução

A melhor estratégia e iniciar com os dragões com menor força, dessa forma basta
derrotar os dragões menos fortes primeiro e analisar se desta forma conseguimos 
adiquirir bonus suficiente para derrotar os dragões mais fortes. Caso isso não 
seja possível a jornada é impossível.

[**Submissão**](https://codeforces.com/problemset/submission/230/110686592)
