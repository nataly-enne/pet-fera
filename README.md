# PetFera

É um projeto implementado por Igor Silva Bento, Hilton Thallyson Vieira Machado e Nátaly Enne da Costa Gonçalo para a unidade II e III da disciplina Linguagem de Programação I, ministrada pelo Professor Renan Cipriano Moioli no Instituto Metrópole Digital, na Universidade Federal do Rio Grande do Norte. 

# What is it?

O objetivo deste trabalho é implementar um programa de cadastro de animais para a loja de
animais silvestres denominada "Pet Fera".

##### Há um arquivo .pdf com a proposta do projeto e todas as especificações.

## São atividades comuns na Pet Fera:
<ul>
  <li>Cadastro de um novo animal a ser comercializado;</li>
  <li>Remoção de um animal da lista após a sua comercialização;</li>
  <li>Alteração dos dados cadastrais de um animal;</li>
  <li>Consulta aos dados cadastrais de um determinado animal ou por uma classe de animais;</li>
  <li>Consulta de animais sob a responsabilidade de um determinado Veterinário ou Tratador;</li>
  <li>Cadastrar um funcionário (Veterinário e/ou Tratador);</li>
  <li>Remoção de um funcionário da lista;</li>
  <li>Alteração dos dados cadastrais de um funcionário.</li>
</ul>

### Para compilar é necessário estar no diretório do projeto e saber o diretório para utilizar a biblioteca dinâmica.

#### Para ver o diretório digite:

<pre><code>pwd</code></pre>

#### Em seguida, copie o diretório na frente do comando abaixo e execute.
<pre><code>export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:[diretorio]</code></pre>

#### Em seguida, basta digitar:
 
 <pre><code>make</code></pre>

#### Para executar o programa, escreva a seguinte linha de código:

<pre><code>./exe</code></pre>

#### Para apagar os arquivos executáveis e objetos, basta executar o seguinte comando:
<pre><code>make clear</code></pre>

#### Para exportar apenas dados de animais que satisfaçam a um determinado conjunto de critérios, basta digitar:
<pre><code>./exportar -c [classe] -v [veterinario] -t [tratador] [arquivo_saida.txt]</code></pre>

#### Na sintaxe acima, o arquivo executável 'exportar' é invocado passando quatro possíveis argumentos via linha de comando:
  * -c [classe]: este argumento indica a classe de animais a serem exportados. Deverá ser indicada apenas uma classe;</li>
  * -v [veterinario]: este argumento indica que apenas animais sob a responsabilidade do veterinário informado devem ser exportados. Deverá ser indicado apenas um nome de veterinário;</li>
  * -t [tratador]: este argumento indica que apenas animais tratados pelo tratador informado devem ser exportados. Deverá ser indicado apenas um tratador;</li>
  * [arquivo_saida]: este argumento obrigatório indica o nome do arquivo de saída, ou seja, do arquivo onde serão guardados os dados a serem exportados e é obrigatório que seja com a extensão <strong>.txt.</strong></li>

<ul>  
  <strong> As possíveis opções de entrada de classes para exportar são:</strong>

  <ul>
    <li>amphibia</li>
    <li>reptilia</li>
    <li>mammalia</li>
    <li>aves</li>
  </ul>
</ul>

## Colaboradores
<table>
  <tr>
    <td align="center">
      <a href="https://github.com/Igorsb3000">
        <img src="https://avatars1.githubusercontent.com/u/23422424?s=400&v=4" width="100px;" alt="Igor Bento"/>
        <br />
        <sub><b>Igor Bento</b></sub>
      </a><br />
      <a href="https://github.com/SrtaEnne/pet-fera/commits?author=Igorsb3000" title="Code">💻</a>
    </td>
    <td align="center">
      <a href="https://github.com/SrtaEnne">
        <img src="https://avatars3.githubusercontent.com/u/26802307?s=400&v=4" width="100px;" alt="Nátaly Enne"/>
        <br />
        <sub><b>Nátaly Enne</b></sub>
      </a><br />
      <a href="https://github.com/SrtaEnne/pet-fera/commits?author=SrtaEnne" title="Code">💻</a>
    </td>
    <td align="center">
      <a href="https://github.com/HiltonThallyson">
        <img src="https://avatars1.githubusercontent.com/u/20178068?s=400&v=4" width="100px;" alt="Hilton Thallyson"/>
        <br />
        <sub><b>Hilton Thallyson</b></sub>
      </a><br />
      <a href="https://github.com/SrtaEnne/pet-fera/commits?author=HiltonThallyson" title="Code">💻</a>
    </td>
  </tr>
</table>

