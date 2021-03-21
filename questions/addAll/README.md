### Problema [link](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1895)

Neste problema é adicionado o conceito de custo de uma soma. O custo de uma soma é o 
valor de todas as somas feitas para somar um array. Um exemplo:A

1 + 2 = 3 (custo 3)
3 + 3 = 6 (custo 6)

O custo para essa soma é 9.

Outra forma de executar essa soma é 

3 + 2 = 5 (custo 5)
5 + 1 = 6 (custo 6)

O custo total é 11.

O objetivo da questão é minizar o custo da soma de vários números.

### Solução

Esse problema parece ser bem bobinho de inicio porém vamos demonstrar que é 
interessantemente complexo. A primeira coisa é que para minizar o custo da soma 
final temos que minimizar os valores dos custos de cara operação par a par. Ou 
seja para ter o menor custo possível precisamos escolher os valores das somas 
de forma que a + b = c tenha o valor c o menor possível no conjunto de todas as 
operações.

É fácil provar que para minimizar a + b precisamos escolher os menores a e b possíveis no
momento. Após isso colocamos o resultado da soma novamente para ser adicionado por outra pessoa.
Ou seja, precisamos fazer as somas dos menores números disponíveis para os maiores.

Realizar uma ordenação simples não é uma boa ideia neste problema pois os valores novos das somas
precisam estar na soma final e portanto você precisa ou adicionar de forma ordenada em um vetor
ou precisa realizar o sorting novamente após cada soma de 2 números.

A melhor opção é ter uma estrutura que consegue recuperar o menor número disponível para soma e 
que possamos inserir novos números de forma que essa propriedade se mantenha. Para isso 
utilizamos uma Heap. A Heap fica responsável por entregar os menores 2 números de todos o conjunto
existente, após isso pegamos esses números, somamos e inserimos novamente na Heap. 

Durante esse processo acumulamos o custo das somas, o algoritmo para no momento em que tem apenas 
um único elemento na Heap.

**Submissão**

![Submissão](submission2.png)
