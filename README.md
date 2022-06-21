
[![C99](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n1256.pdf)

# Simulador de memória virtual
 Implementação de um simulador com mecanismos para gerência de memória virtual, incluindo algoritmos de substituição de página como _LRU_ (Least Recently Used), _NRU_ (Not Recently Used) e _Second Chance_. (Trabalho Prático 2 da disciplina de Sistemas Operacionais - DCOMP - UFSJ)

# Compilação
        make

# Requisitos (Plot dos gráficos)
- [Python](https://python.org) 3.8 ou superior
- Biblioteca [Matplotlib](https://matplotlib.org/)

       pip install matplotlib
       
# Execução

- Para instância _matriz.log_:
        
       make run
       
- Exemplo de execução:

       ./tp2virtual nru ../Instances/simulador.log 4 2048
       
- Formato de execução geral: 

  `./tp2virtual <nome do algoritmo> ../Instances/<nome do arquivo.log> <tamanho da página> <tamanho da memória>`
