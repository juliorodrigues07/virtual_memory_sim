
[![C99](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n1256.pdf)

# Simulador de memória virtual
 Implementação de um simulador com mecanismos para gerência de memória virtual (Trabalho Prático 2 da disciplina de Sistemas Operacionais - DCOMP - UFSJ)

# Compilação
        make

# Requisitos (Plot dos gráficos)
- [Python](https://python.org) 3.8 ou superior
- Biblioteca [Matplotlib](https://matplotlib.org/)

       pip install matplotlib
       
# Execução

- Para instância matriz.log:
        
       make run
       
- Formato de execução geral:

       gcc main.c -o tp2virtual
       
       ./tp2virtual <nome do algoritmo> ../Instances/<nome do arquivo.log> <tamanho da página> <tamanho da memória>
       
- Exemplo de execução:

       ./tp2virtual nru ../Instances/simulador.log 4 2048
