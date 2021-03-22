# Saving the City

Problema original [>>aqui<<](https://codeforces.com/contest/1443/problem/B).

## Descrição

Bertown é uma cidade com edifícios dispostos numa reta, todos eles enumerados de 1 até n. Infelizmente, alguns prédios possuem bombas debaixo deles. Um mapa com a presença de bombas é compilado em uma string binária, onde a i-ésima posição representa o i-ésimo edifício. Caso o i-ésimo edifício possua uma bomba debaixo de sua estrutura o i-ésimo caractere da string será '1', e '0' caso contrário.

Os engenheiros sabem desativar a bomba de um prédio sem que o mesmo seja danificado. Ao desativar a bomba do i-ésimo prédio, as bombas dos prédios i-1 e i+1 também são desativadas se existirem. Outro fato curisoso é que mesmo que uma bomba não tenha sido desativada diretamente por um engenheiro, ela também desarma as bombas vizinhas da mesma maneira, gerando assim uma reação em cadeia.

Por exemplo:

11101110

Caso a primeira bomba seja desativada a segunda e a terceira também serão desativadas:

00001110

Desativar uma bomba custa _A_. Sabe-se também que os engenheiros podem colocar novas bombas em outros prédios por um custo de _B_.
Qual o menor custo possível para que todos os prédios tenham suas bombas desativadas?

## Resolução

A resolução desse problema consiste na decisão de quais prédios devem ter novas bombas colocadas. Supondo o cenário em que já pagamos um custo A para desativar uma sequencia contigua de bombas nos prédios anteriores, podemos de forma ambiciosa decidir entre desativar manualmente a próxima sequencia (se houver) ou pagar pelo custo de preencher o intervalo entre as duas sequencias com bombas e, consequentemente, desativa-las.

## Codificando

> Veja o código completo [aqui](1443B.cpp).
>
> Veja o código avaliado pelo juíz [aqui](https://codeforces.com/contest/1443/submission/110773481).

Primeiramente assumimos de cara um custo _A_ na nossa resposta, e então percorremos a string em busca da primeira sequência de bombas. Caso a string inteira seja percorrida e nenhuma bomba seja encontrada, a reposta automaticamente será 0 e não faremos mais nada.

```c++
int a, b;
cin >> a >> b;
string s;
cin >> s;

long long ans = a;
int i = 0;
while (s[i] != '1') {
    if (i == (int) s.size() - 1) {
        ans = 0;
        break;
    }
    i++; 
}
```

Encontrada uma sequência de bombas (um único prédio é considerado uma sequência), iremos então percorrer o resto da string acumulando sempre que necessário o tamanho do intervalo de prédios sem bombas na variável _gap_. Sendo assim, podemos tomar as seguintes decisões:

- Se o prédio que estamos verificando agora possui uma bomba e o intervalo sem bombas medido até agora é maior que 0, adicionamos à reposta o mínimo entre desativar a bomba desse prédio ou pagar o custo de preencher os prédios livres anteriores com bombas. Depois disso, declaramos que o intervalo sem bombas medido até agora é 0.

- Se o prédio que estamos verificando não possui nenhuma bomba, adicionamos 1 ao intervalo sem bombas.

```c++
int gap = 0;
for ( ; i < (int) s.size(); i++) {
    if (s[i] == '1' && gap > 0) {
        ans += min(a, gap * b);
        gap = 0;
    }
    else if (s[i] == '0')
        gap++;
}
```

### Exemplo

> String: 11101110
>
> Custo A: 5
>
> Custo B: 1
>
> Resposta: 5 (pagamos a priori por uma desativação)

| Prédio atual | _Gap_ | Resposta |
| :-: | :-: | :-: |
| **1**1101110 | 0 | 5 |
| 1**1**101110 | 0 | 5 |
| 11**1**01110 | 0 | 5 |
| 111**0**1110 | 1 | 5 |
| 1110**1**110 | 1 | 5 + min(1*1, 5) |
| 11101**1**10 | 0 | 6 |
| 111011**1**0 | 0 | 6 |
| 1110111**0** | 1 | 6 |

> Resposta: 6

Depois de percorrer toda a string, basta então mostrar a resposta.

```c++
cout << ans << endl;
```

Em termos de complexidade, a solução é ***O(n)***, pois percorre a string inteira uma única vez, sempre decidindo localmente pela melhor escolha (desativar a bomba atual ou preencher o intervalo vazio anterior com novas bombas).

O custo desta solução é baixo pois não existe a necessidade de se ordenar previamente o conjunto de dados.