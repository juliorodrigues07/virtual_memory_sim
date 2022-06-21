import matplotlib.pyplot as plt


def plot_graph(x, page_fault, write_backs):

    plt.grid()
    plt.xlabel('Tamanho da memória principal')
    plt.ylabel('Quantidade de páginas')
    plt.plot(x, page_fault, color='b', label='Falta de Páginas')
    plt.plot(x, write_backs, color='g', label='Páginas "Sujas"')
    plt.legend(loc='best')
    plt.show()


def plot_page_faults(mem, x, y, z):

    plt.grid()
    plt.ylabel('Faltas de Páginas')
    plt.plot(mem, x, color='b', label='LRU')
    plt.plot(mem, y, color='g', label='Segunda Chance')
    plt.plot(mem, z, color='r', label='NRU')
    plt.legend(loc='best')
    plt.show()


def plot_writebacks(mem, a, b, c):

    plt.grid()
    plt.ylabel('Páginas Sujas')
    plt.plot(mem, a, color='b', label='LRU')
    plt.plot(mem, b, color='g', label='Segunda Chance')
    plt.plot(mem, c, color='r', label='NRU')
    plt.legend(loc='best')
    plt.show()


def mem_label():
    plt.xlabel('Tamanho da memória principal')


def pag_label():
    plt.xlabel('Tamanho de página')