
## Appleman and Toastman

### Descrição

Appleman e Toastman decidiram fazer uma brincadeira:
- Ao começar a brincadeira, Appleman entrega a Toastman um grupo de _n_ números
- Toda vez que o Toastman recebe um grupo de números, ele soma todos os números contidos no grupo e acrescenta na pontuação. Em seguida ele devolve o grupo de números para o Appleman.
- Toda vez que o Appleman recebe um grupo com mais de um número, ele divide o grupo em dois, de acordo com a sua vontade. Em seguida entrega cada um desses dois grupos para o Toastman.
- Toda vez que o Appleman recebe um grupo com um único número, ele simplesmente joga o número fora.
- Quando não restarem mais números, os garotos verificam quantos pontos eles fizeram.

Uma hora eles se perguntaram, qual é a maior pontuação possível de se obter pra um determinado grupo de números?

Você pode conferir o problema original [aqui](https://codeforces.com/problemset/problem/461/A).

### Resolução

O problema gira em torno da seguinte decisão: ao recebermos um grupo com _k_ números, como dividí-lo de forma a maximizar a pontuação obtida?

Agindo de forma gulosa podemos proceder da seguinte maneira:

- Descobrimos o menor elemento pertencente ao grupo
- Criamos um grupo somente com o menor elemento
- Os demais elementos serão colocados no segundo grupo
- Entregamos ambos grupos para o Toastman

Dessa maneira, faremos com que os elementos de maior valor permaneçam o maior tempo possível na brincadeira.

## Codificando

Seguindo as restrições do [enunciado presente no codeforces](https://codeforces.com/problemset/problem/461/A), elaborou-se a seguinte solução:

> Solução completa [aqui](461A.cpp)!

Primeiramente lemos a quantidade de números que virão, e então o grupo inicial de números salvando-os em um vetor.
```c++
int numbers_amount;
cin >> numbers_amount;

vector<int> numbers(numbers_amount);

for (auto & element : numbers)
    cin >> element;
```

A cada rodada precisamos descobrir qual o menor elemento presente no vetor, adicioná-lo na pontuação e descartá-lo. Porém, fazer isso possui complexidade ***O(n)***, pois precisamos percorrer todo o vetor para encontrar o menor elemento, e para descartá-lo existe um custo de ordem semelhante envolvido.

Para resolver isso, devemos ordenar o vetor em ordem não crescente para que sempre seja possível encontrar e remover o menor elemento em ***O(1)***. A ordenação nos custará ***O(n log(n))***, mas é mais eficiente do que rodar uma rotina ***O(n)*** para todas as rodadas.

```c++
sort(numbers.begin(), numbers.end(), greater<int>());
```

Pode-se perceber que todas as rodadas são compostas por 2 grupos de números: o grupo com o elemento de menor valor e o grupo com os elementos de maior valor, exceto pela primeira e útlima rodada, que possui o grupo inicial e o grupo com o último número restante, respectivamente.

Sendo assim, podemos manter uma variável com a soma total do grupo inicial e a cada rodada retiramos dessa variável o elemento a ser descartado. A cada rodada adicionamos o valor dessa variável à nossa resposta Enquanto tivermos números sobrando no vetor. Porém, vale perceber que os dois últimos números restantes serão descartados automaticamente, sendo assim, o útilmo maior número deve ser removido da resposta. Para facilitar, o número 0 será incluído no vetor para permitir que somemos o grupo inicial sem a necessidade um novo fluxo de código.

#### Exemplo

> Grupo inicial: [3, 2, 4, 1]
>
> Grupo ordenado a ser processado: [4, 3, 2, 1, 0]
>
> Valor inicial da resposta: -4

| Grupo menor | Grupo maior | Soma total | Resposta |
| :--------:  | :---------: | :---------:| :------: |
| [0] | [4, 3, 2, 1] | 10 | 6 |
| [1] | [4, 3, 2] | 10 | 16 |
| [2] | [4, 3] | 9 | 25 |
| [3] | [4] | 7 | 32 |
| [4] | | 4 | 36 |

> Resposta: 36

```c++
int numbers_amount;
cin >> numbers_amount;

vector<int> numbers(numbers_amount);

// Le os numeros e adiciona na variavel de soma total
long long total_sum = 0;
for (auto & element : numbers) {
    cin >> element;
    total_sum += element;
}

// Ordena os numeros em ordem nao crescente
sort(numbers.begin(), numbers.end(), greater<int>());
// Adiciona o 0 no fim
numbers.push_back(0);

// Inicia a resposta com o valor do maior elemento ja deduzido
long long answer = - numbers.front();
while (not numbers.empty()) {
    //Acrescenta a soma à resposta
    answer += total_sum;

    // Deduz da soma o número retirado
    total_sum -= numbers.back();

    // Retira o numero do vetor
    numbers.pop_back();
}

cout << answer << endl;
```
