from plotting import plot_page_faults
from plotting import plot_writebacks
from plotting import pag_label
import matplotlib.pyplot as plt


def main():

    pag = [2, 4, 8, 16, 32, 64]

    # MATRIZ.LOG
    x = [0, 0, 234, 1992, 2887, 3272]
    a = [0, 0, 108, 738, 1056, 1135]

    y = [0, 0, 282, 1291, 1983, 2946]
    b = [0, 0, 141, 641, 885, 1168]

    z = [0, 0, 320, 1847, 197593, 312677]
    c = [0, 0, 0, 0, 361, 615]

    pag_label()
    plt.title('Tamanho da memória fixo (16384 KB) - matriz.log')
    plot_page_faults(pag, x, y, z)

    pag_label()
    plt.title('Tamanho da memória fixo (16384 KB) - matriz.log')
    plot_writebacks(pag, a, b, c)

    # COMPILADOR.LOG
    x = [0, 0, 434, 2557, 5396, 7537]
    a = [0, 0, 178, 613, 967, 1443]

    y = [0, 0, 450, 2198, 4705, 9559]
    b = [0, 0, 400, 898, 1477, 2482]

    z = [0, 0, 623, 3785, 100277, 91484]
    c = [0, 0, 0, 0, 282, 930]

    pag_label()
    plt.title('Tamanho da memória fixo (16384 KB) - compilador.log')
    plot_page_faults(pag, x, y, z)

    pag_label()
    plt.title('Tamanho da memória fixo (16384 KB) - compilador.log')
    plot_writebacks(pag, a, b, c)

    # COMPRESSOR.LOG
    x = [0, 0, 0, 0, 0, 0]
    a = [0, 0, 0, 0, 0, 0]

    pag_label()
    plt.title('Tamanho da memória fixo (16384 KB) - compressor.log')
    plot_page_faults(pag, x, x, x)

    pag_label()
    plt.title('Tamanho da memória fixo (16384 KB) - compressor.log')
    plot_writebacks(pag, a, a, a)

    # SIMULADOR.LOG
    x = [0, 0, 2582, 3737, 5903, 5957]
    a = [0, 0, 591, 1422, 2315, 2322]

    y = [0, 0, 1162, 2772, 3366, 3652]
    b = [0, 0, 1161, 1697, 1877, 1884]

    z = [0, 0, 3003, 220521, 169381, 157653]
    c = [0, 0, 0, 810, 1500, 1997]

    pag_label()
    plt.title('Tamanho da memória fixo (16384 KB) - simulador.log')
    plot_page_faults(pag, x, y, z)

    pag_label()
    plt.title('Tamanho da memória fixo (16384 KB) - simulador.log')
    plot_writebacks(pag, a, b, c)


if __name__ == '__main__':
    main()
