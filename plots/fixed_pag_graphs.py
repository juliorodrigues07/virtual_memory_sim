import matplotlib.pyplot as plt


def plot_graph(x, page_fault, write_backs):

    plt.grid()
    plt.xlabel('Tamanho da memória principal')
    plt.ylabel('Quantidade de páginas')
    plt.plot(x, page_fault, color='b', label='Falta de Páginas')
    plt.plot(x, write_backs, color='g', label='Páginas "Sujas"')
    plt.legend(loc='best')
    plt.show()


def main():

    mem = [128, 256, 512, 1024, 2048, 4096, 8192, 16384]

    # MATRIZ.LOG
    plt.title('LRU - Tamanho de página fixo (4 KB) - matriz.log')
    page_fault = [235318, 142799, 42599, 11685, 8017, 5103, 1597, 0]
    write_backs = [30001, 20311, 6623, 2319, 1858, 1288, 378, 0]
    plot_graph(mem, page_fault, write_backs)

    plt.title('Segunda Chance - Tamanho de página fixo (4 KB) - matriz.log')
    plot_graph(mem, page_fault, write_backs)

    plt.title('NRU - Tamanho de página fixo (4 KB) - matriz.log')
    page_fault = [605859, 566735, 534631, 448863, 302536, 9263, 2056, 0]
    write_backs = [11091, 3555, 2776, 1871, 1111, 0, 0, 0]
    plot_graph(mem, page_fault, write_backs)

    # COMPILADOR.LOG
    plt.title('LRU - Tamanho de página fixo (4 KB) - compilador.log')
    page_fault = [401366, 302019, 196501, 53793, 21029, 9537, 1388, 0]
    write_backs = [46697, 33519, 20879, 5471, 2229, 1072, 320, 0]
    plot_graph(mem, page_fault, write_backs)

    plt.title('Segunda Chance - Tamanho de página fixo (4 KB) - compilador.log')
    plot_graph(mem, page_fault, write_backs)

    plt.title('NRU - Tamanho de página fixo (4 KB) - compilador.log')
    page_fault = [355453, 286933, 264638, 241193, 213242, 31940, 2345, 0]
    write_backs = [18639, 5308, 4313, 3406, 1900, 60, 0, 0]
    plot_graph(mem, page_fault, write_backs)

    # COMPRESSOR.LOG
    plt.title('LRU - Tamanho de página fixo (4 KB) - compressor.log')
    page_fault = [27863, 7046, 3435, 321, 0, 0, 0, 0]
    write_backs = [4692, 1132, 723, 26, 0, 0, 0, 0]
    plot_graph(mem, page_fault, write_backs)

    plt.title('Segunda Chance - Tamanho de página fixo (4 KB) - compressor.log')
    plot_graph(mem, page_fault, write_backs)

    plt.title('NRU - Tamanho de página fixo (4 KB) - compressor.log')
    page_fault = [127762, 116762, 57445, 220, 0, 0, 0, 0]
    write_backs = [1231, 483, 14, 0, 0, 0, 0, 0]
    plot_graph(mem, page_fault, write_backs)

    # SIMULADOR.LOG
    plt.title('LRU - Tamanho de página fixo (4 KB) - simulador.log')
    page_fault = [305122, 216820, 99883, 22517, 15671, 8798, 5369, 0]
    write_backs = [71496, 54578, 29814, 5530, 3753, 2287, 1129, 0]
    plot_graph(mem, page_fault, write_backs)

    plt.title('Segunda Chance - Tamanho de página fixo (4 KB) - simulador.log')
    plot_graph(mem, page_fault, write_backs)

    plt.title('NRU - Tamanho de página fixo (4 KB) - simulador.log')
    page_fault = [430386, 341518, 304338, 298543, 288742, 254820, 7253, 0]
    write_backs = [47547, 16078, 5784, 4899, 4010, 1577, 0, 0]
    plot_graph(mem, page_fault, write_backs)


if __name__ == '__main__':
    main()
