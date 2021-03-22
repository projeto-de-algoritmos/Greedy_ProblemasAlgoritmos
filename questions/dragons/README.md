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

#### Código

Após a leitura dos dados ordenamos todos os elementos. Em 
C++ esse algoritmo é o Merge Sort portanto tem complexidade 
O(N.log(N)).

```C
sort(vet.begin(), vet.end());
```

E após isso analisamos se existirá um dragão com força igual o maior
na sequencia de batalhas o herói perde, caso contrário ele vence.

```C
    bool win = true;

    for(auto [force, bonus] : dragons){
        
        if(s > force){
            // if the hero can beat the dragon
            // add the bonus in his stregth
            s+=bonus;
        }else{
            // if the force of the dragon is greater or equal
            // the hero can't win
            win = false;
        }

    }
```

Visto que temos a fase de sorting e no pior caso (onde o herói vence) temos que interar 
todos os N items (que é desconsiderada em função da complexidade do Merge Sort) a complexidade final é O(N.log(N)).


[**Submissão**](https://codeforces.com/problemset/submission/230/110686592)
