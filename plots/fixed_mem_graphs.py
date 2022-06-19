import matplotlib.pyplot as plt


def plot_graph(x, page_fault, write_backs):

    plt.grid()
    plt.xlabel('Tamanho da página')
    plt.ylabel('Quantidade de páginas')
    plt.plot(x, page_fault, color='b', label='Falta de Páginas')
    plt.plot(x, write_backs, color='g', label='Páginas "Sujas"')
    plt.legend(loc='best')
    plt.show()


def main():

    pag = [2, 4, 8, 16, 32, 64]

    # MATRIZ.LOG
    plt.title('LRU - Tamanho da memória fixo (16384 KB) - matriz.log')
    page_fault = [0, 0, 609, 3084, 4884, 5360]
    write_backs = [0, 0, 181, 779, 1128, 1159]
    plot_graph(pag, page_fault, write_backs)

    plt.title('Segunda Chance - Tamanho da memória fixo (16384 KB) - matriz.log')
    plot_graph(pag, page_fault, write_backs)

    plt.title('NRU - Tamanho da memória fixo (16384 KB) - matriz.log')
    page_fault = [0, 0, 747, 3364, 185521, 303850]
    write_backs = [0, 0, 0, 0, 400, 832]
    plot_graph(pag, page_fault, write_backs)

    # COMPILADOR.LOG
    plt.title('LRU - Tamanho da memória fixo (16384 KB) - compilador.log')
    page_fault = [0, 0, 505, 3084, 7983, 12070]
    write_backs = [0, 0, 130, 515, 873, 1308]
    plot_graph(pag, page_fault, write_backs)

    plt.title('Segunda Chance - Tamanho da memória fixo (16384 KB) - compilador.log')
    plot_graph(pag, page_fault, write_backs)

    plt.title('NRU - Tamanho da memória fixo (16384 KB) - compilador.log')
    page_fault = [0, 0, 756, 5821, 94157, 99665]
    write_backs = [0, 0, 0, 0, 323, 1327]
    plot_graph(pag, page_fault, write_backs)

    # COMPRESSOR.LOG
    plt.title('LRU - Tamanho da memória fixo (16384 KB) - compressor.log')
    page_fault = [0, 0, 0, 0, 0, 0]
    write_backs = [0, 0, 0, 0, 0, 0]
    plot_graph(pag, page_fault, write_backs)

    plt.title('Segunda Chance - Tamanho da memória fixo (16384 KB) - compressor.log')
    plot_graph(pag, page_fault, write_backs)

    plt.title('NRU - Tamanho da memória fixo (16384 KB) - compressor.log')
    plot_graph(pag, page_fault, write_backs)

    # SIMULADOR.LOG
    plt.title('LRU - Tamanho da memória fixo (16384 KB) - simulador.log')
    page_fault = [0, 0, 4190, 6008, 8410, 8587]
    write_backs = [0, 0, 628, 1599, 2333, 2293]
    plot_graph(pag, page_fault, write_backs)

    plt.title('Segunda Chance - Tamanho da memória fixo (16384 KB) - simulador.log')
    plot_graph(pag, page_fault, write_backs)

    plt.title('NRU - Tamanho da memória fixo (16384 KB) - simulador.log')
    page_fault = [0, 0, 4980, 227194, 190333, 173179]
    write_backs = [0, 0, 0, 895, 1734, 2479]
    plot_graph(pag, page_fault, write_backs)


if __name__ == '__main__':
    main()
