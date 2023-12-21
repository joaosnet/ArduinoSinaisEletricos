# ArduinoSinaisEletricos - ATmega328

![GitHub repo size](https://img.shields.io/github/repo-size/joaosnet/ArduinoSinaisEletricos?style=for-the-badge)
![GitHub language count](https://img.shields.io/github/languages/count/joaosnet/ArduinoSinaisEletricos?style=for-the-badge)
![GitHub forks](https://img.shields.io/github/forks/joaosnet/ArduinoSinaisEletricos?style=for-the-badge)
![Bitbucket open issues](https://img.shields.io/bitbucket/issues/joaosnet/ArduinoSinaisEletricos?style=for-the-badge)
![Bitbucket open pull requests](https://img.shields.io/bitbucket/pr-raw/joaosnet/ArduinoSinaisEletricos?style=for-the-badge)

<img src="screenshots\ArduinoSinaisEletricos.bmp" alt="Projeto Proteus">

 > Projeto de Aquisição e Análise de Sinais Elétricos com Arduino  Este repositório contém o código e a documentação para um projeto realizado no Laboratório de Processamento de Sinais (LaPS). O objetivo é realizar a aquisição e análise de sinais de corrente e tensão em um circuito elétrico, utilizando a plataforma Arduino. O projeto abrange a implementação de um sistema de aquisição, incluindo a definição da taxa de amostragem, resolução e a análise da qualidade de energia em diferentes condições operacionais.  

 🔧 Tecnologias: Arduino, Python, Processamento de Sinais 

 📊 Disciplina: Processamento de Sinais (PDS) 

 📆 Ano: 2023/4  

 Entrega final composta por uma apresentação em PDF justificada, contendo simulações e/ou fundamentos teóricos, e o código Arduino desenvolvido.

 # Sobre o Projeto 
 O projeto visa fornecer uma base para análise de qualidade de energia, permitindo avaliações objetivas em situações simuladas de surtos na rede elétrica. 

<img src="screenshots\20231218_124734.jpg" alt="Materiais Utilizados">

<img src="screenshots\plot.png" alt="Amostras no Gráfico">

## ☕ Usando o protótipo em python do Arduino Sinais Eletricos

## 💻 Pré-requisitos

Antes de começar, verifique se você atendeu aos seguintes requisitos:

- Você instalou a versão mais recente do Microchip Studio
- Você tem instalado o Proteus 8.7 SP3 ou um microcontrolador ATmega328p
- ter baixado o projeto do GitHub e entre na pasta do projeto
```bash
cd caminho/para/a/pasta/do/projeto
```

Obs . : para executar o projeto com Proteus 8.7 SP3 é necessário ter um virtualizador de Porta Serial como o [com0com](https://com0com.sourceforge.net/)

### No windows
1. Instale o [anaconda](https://docs.anaconda.com/free/anaconda/install/windows.html)
2. Crie um ambiente virtual
```bash
conda create -n pds python=3.10 -y
```
3. Ative o ambiente virtual
```bash
conda activate pds
```
4. Instale as dependências
```bash
pip install -r requirements_windows.txt
```
5. Execute o aplicativo
```bash
python main.py
```

### No Linux
1. Instale o [anaconda](https://www.digitalocean.com/community/tutorials/how-to-install-the-anaconda-python-distribution-on-ubuntu-20-04-pt)
2. Crie um ambiente virtual
```bash
conda create -n pds python=3.10 -y
```
3. Ative o ambiente virtual
```bash
conda activate pds
```
4. Instale as dependências
```bash
pip install -r requirements_linux.txt
```
5. Execute o aplicativo
```bash
python main.py
```


## 🤝 Colaboradores

Agradecemos às seguintes pessoas que contribuíram para este projeto:

<table>
  <tr>
    <td align="center">
      <a href="https://www.instagram.com/jaonativi/" title="Gerente de Projetos Desenvolvedor Backend">
        <img src="https://avatars.githubusercontent.com/u/87316339?v=4" width="100px;" alt="Foto do João Natividade no GitHub"/><br>
        <sub>
          <b>João Natividade</b>
        </sub>
      </a>
    </td>

</table>

## 😄 Seja um dos contribuidores

Quer fazer parte desse projeto? Clique [AQUI](CONTRIBUTING.md) e leia como contribuir.

## 📝 Licença

Esse projeto está sob licença. Veja o arquivo [LICENÇA](LICENSE.md) para mais detalhes.