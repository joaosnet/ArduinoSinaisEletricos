# ArduinoSinaisEletricos - ATmega328

![GitHub repo size](https://img.shields.io/github/repo-size/joaosnet/ButtonControlledCounter_ATmega328?style=for-the-badge)
![GitHub language count](https://img.shields.io/github/languages/count/joaosnet/ButtonControlledCounter_ATmega328?style=for-the-badge)
![GitHub forks](https://img.shields.io/github/forks/joaosnet/ButtonControlledCounter_ATmega328?style=for-the-badge)
![Bitbucket open issues](https://img.shields.io/bitbucket/issues/joaosnet/ButtonControlledCounter_ATmega328?style=for-the-badge)
![Bitbucket open pull requests](https://img.shields.io/bitbucket/pr-raw/joaosnet/ButtonControlledCounter_ATmega328?style=for-the-badge)

<img src="screenshots\ArduinoSinaisEletricos.bmp" alt="Projeto A4">

 > Projeto de Aquisição e Análise de Sinais Elétricos com Arduino  Este repositório contém o código e a documentação para um projeto realizado no Laboratório de Processamento de Sinais (LaPS). O objetivo é realizar a aquisição e análise de sinais de corrente e tensão em um circuito elétrico, utilizando a plataforma Arduino. O projeto abrange a implementação de um sistema de aquisição, incluindo a definição da taxa de amostragem, resolução e a análise da qualidade de energia em diferentes condições operacionais.  🔧 Tecnologias: Arduino, Python, Processamento de Sinais 📊 Disciplina: Processamento de Sinais (PDS) 📆 Ano: 2023/4  Entrega final composta por uma apresentação em PDF justificada, contendo simulações e/ou fundamentos teóricos, e o código Arduino desenvolvido.  # Sobre o Projeto O projeto visa fornecer uma base para análise de qualidade de energia, permitindo avaliações objetivas em situações simuladas de surtos na rede elétrica. 

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
    <td align="center">
      <a href="https://www.instagram.com/aly_lustoza/" title="QA Tester Analista de Mercado">
        <img src="https://instagram.fbel1-1.fna.fbcdn.net/v/t51.2885-19/274501676_537691970910933_7250418063848294931_n.jpg?stp=dst-jpg_s150x150&_nc_ht=instagram.fbel1-1.fna.fbcdn.net&_nc_cat=109&_nc_ohc=KgbJtfViehAAX9mB9cR&edm=ACWDqb8BAAAA&ccb=7-5&oh=00_AfApyka_2lTirZVLEmvZec5PMm-mFW-SU1m3uIYbYDNZ5w&oe=65664ACE&_nc_sid=ee9879" width="100px;" alt="Foto do Alydson Lustoza"/><br>
        <sub>
          <b>Alydson Lustoza</b>
        </sub>
      </a>
        <td align="center">
      <a href="https://www.instagram.com/c.j_silva/" title="UX Designer Desenvolvedora Backend">
        <img src="https://instagram.fbel1-1.fna.fbcdn.net/v/t51.2885-19/361771304_833908247939807_9019221283482484802_n.jpg?stp=dst-jpg_s150x150&_nc_ht=instagram.fbel1-1.fna.fbcdn.net&_nc_cat=111&_nc_ohc=6VEjSCPRkm0AX-I87Do&edm=ACWDqb8BAAAA&ccb=7-5&oh=00_AfAZPuIQzYFL-7ojBTLjwU-cWWeeBRhDd_4y8QxFkIYUqw&oe=656549F2&_nc_sid=ee9879" width="100px;" alt="Foto da Carla Silva"/><br>
        <sub>
          <b>Carla Silva</b>
        </sub>
      </a>
    </td>
    <td align="center">
      <a href="https://www.instagram.com/tms.jpeg/" title="UI Designer Especialista em Marketing">
        <img src="https://instagram.fbel1-1.fna.fbcdn.net/v/t51.2885-19/300225876_600418448208671_8750170704882872093_n.jpg?stp=dst-jpg_s150x150&_nc_ht=instagram.fbel1-1.fna.fbcdn.net&_nc_cat=111&_nc_ohc=zkwa2sgjdMYAX-g_-gi&edm=ACWDqb8BAAAA&ccb=7-5&oh=00_AfCdAENfZaw2HUE5i5Mj9XrHStvDv2d348cJUBAutNyrlg&oe=6566888B&_nc_sid=ee9879" width="100px;" alt="Foto do José Soares"/><br>
        <sub>
          <b>José Soares</b>
        </sub>
      </a>
    </td>
<td align="center">
      <a href="https://www.linkedin.com/in/haroldo-magano-j%C3%BAnior-1a0b2265/" title="UI Designer Especialista em Marketing">
        <img src="https://media.licdn.com/dms/image/C5635AQF8PVFSmAHKyw/profile-framedphoto-shrink_400_400/0/1615418813549?e=1701450000&v=beta&t=HeCNpYmNhkZidKERm419sz3Kaat4mjW6anvc4VzlsR8" width="100px;" alt="Foto do José Soares"/><br>
        <sub>
          <b>Haroldo Magano</b>
        </sub>
      </a>
    </td>
<td align="center">
      <a href="https://www.linkedin.com/in/hugo-barros-013833170/" title="UI Designer Especialista em Marketing">
        <img src="https://media.licdn.com/dms/image/C5603AQFwkCvZP4Sszg/profile-displayphoto-shrink_200_200/0/1656009934326?e=1706140800&v=beta&t=rHW0AHp9_1MNLDjn0w9vKunl1nD3I5y3rp0mGYe_CSc" width="100px;" alt="Foto do José Soares"/><br>
        <sub>
          <b>Hugo Barros</b>
        </sub>
      </a>
    </td>
  </tr>
</table>

## 😄 Seja um dos contribuidores

Quer fazer parte desse projeto? Clique [AQUI](CONTRIBUTING.md) e leia como contribuir.

## 📝 Licença

Esse projeto está sob licença. Veja o arquivo [LICENÇA](LICENSE.md) para mais detalhes.