from plotting import plot_page_faults
from plotting import plot_writebacks
from plotting import pag_label
import matplotlib.pyplot as plt


def main():

    pag = [2, 4, 8, 16, 32, 64]

    # MATRIZ.LOG
    x = [2994, 2543, 2282, 3016, 3399, 3528]
    a = [0, 0, 108, 738, 1056, 1135]

    y = [2994, 2543, 2330, 2315, 2495, 3202]
    b = [0, 0, 141, 641, 885, 1168]

    z = [2294, 2543, 2368, 2871, 3338, 3702]
    c = [0, 0, 0, 0, 376, 691]

    pag_label()
    plt.title('Tamanho da memória fixo (16384 KB) - matriz.log')
    plot_page_faults(pag, x, y, z)

    pag_label()
    plt.title('Tamanho da memória fixo (16384 KB) - matriz.log')
    plot_writebacks(pag, a, b, c)

    # COMPILADOR.LOG
    x = [3621, 2852, 2482, 3581, 5908, 7793]
    a = [0, 0, 178, 613, 967, 1443]

    y = [3621, 2852, 2498, 3222, 5217, 9815]
    b = [0, 0, 400, 898, 1477, 2482]

    z = [3621, 2852, 2671, 4805, 7727, 8230]
    c = [0, 0, 0, 19, 637, 938]

    pag_label()
    plt.title('Tamanho da memória fixo (16384 KB) - compilador.log')
    plot_page_faults(pag, x, y, z)

    pag_label()
    plt.title('Tamanho da memória fixo (16384 KB) - compilador.log')
    plot_writebacks(pag, a, b, c)

    # COMPRESSOR.LOG
    x = [419, 317, 255, 209, 172, 137]
    a = [0, 0, 0, 0, 0, 0]

    pag_label()
    plt.title('Tamanho da memória fixo (16384 KB) - compressor.log')
    plot_page_faults(pag, x, x, x)

    pag_label()
    plt.title('Tamanho da memória fixo (16384 KB) - compressor.log')
    plot_writebacks(pag, a, a, a)

    # SIMULADOR.LOG
    x = [5144, 3890, 4630, 4761, 6415, 6213]
    a = [0, 0, 591, 1422, 2315, 2322]

    y = [5144, 3890, 3710, 3796, 3878, 3908]
    b = [0, 0, 1161, 1697, 1877, 1884]

    z = [5144, 3890, 5051, 5624, 5725, 6445]
    c = [0, 0, 0, 959, 1457, 1954]

    pag_label()
    plt.title('Tamanho da memória fixo (16384 KB) - simulador.log')
    plot_page_faults(pag, x, y, z)

    pag_label()
    plt.title('Tamanho da memória fixo (16384 KB) - simulador.log')
    plot_writebacks(pag, a, b, c)


if __name__ == '__main__':
    main()
