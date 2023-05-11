<h3>1. Quais são as tarefas no caminho crítico para cada grafo de dependência? Para responder a pergunta, apresente um DAG do seu projeto.</h3>

 DAG: https://github.com/L3borim/Labs_Computacao_Paralela/blob/main/Projeto/DAG%20(Euler).jpeg <br/>
 *TAREFAS* <br/>
 T1) Criação das variáveis fat e termo <br/>
 T2) Incializa result com o valor igual a 1.0 <br/>
 T3) Loop externo que itera o i 'n' vezes <br/>
 T4) Loop interno qur itera de 1 a 'i' <br/>
 T5) Calculo de fat dentro do loop interno <br/>
 T6) Calcula o termo após o loop interno <br/>
 T7) Incrementa o result com o termo <br/>
 T8) Limpa as variáveis fat e termo <br/>

<h3>2. Qual é o limite inferior do tempo de execução paralela para cada decomposição?</h3>
O limite inferior é 7

<h3>3. Quantos processadores são necessários para se conseguir o tempo mínimo de execução?</h3>


<h3>4. Qual é o grau máximo de concorrência?</h3>
O grau máximo de concorrencia dependerá da quantidade de threads definidos no código. Se utilizarmos 4 threads, o grau máximo de
concorrência será 4.


<h3>5. Qual é o paralelismo médio?</h3>
O paralelismo médio 8/7 = 1,1428
