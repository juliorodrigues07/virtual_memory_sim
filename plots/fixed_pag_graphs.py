from plotting import plot_page_faults
from plotting import plot_writebacks
from plotting import mem_label
import matplotlib.pyplot as plt


def main():

    mem = [128, 256, 512, 1024, 2048, 4096, 8192, 16384]

    # MATRIZ.LOG
    x = [233350, 129072, 30903, 7405, 5020, 3339, 915, 0]
    a = [30397, 22260, 7421, 2261, 1697, 1160, 265, 0]

    y = [81526, 30376, 17428, 8347, 4363, 2267, 764, 0]
    b = [18161, 7585, 4941, 2840, 1631, 979, 356, 0]

    z = [576456, 536520, 495942, 438335, 307452, 99159, 1077, 0]
    c = [13071, 4005, 2011, 1506, 889, 171, 0, 0]

    mem_label()
    plt.title('Tamanho de página fixo (4 KB) - matriz.log')
    plot_page_faults(mem, x, y, z)

    mem_label()
    plt.title('Tamanho de página fixo (4 KB) - matriz.log')
    plot_writebacks(mem, a, b, c)

    # COMPILADOR.LOG
    x = [378683, 286419, 181929, 67082, 14746, 7478, 1227, 0]
    a = [45297, 33621, 21546, 9198, 2516, 1247, 391, 0]

    y = [98055, 70226, 48420, 31437, 15094, 5635, 1405, 0]
    b = [16751, 12045, 8485, 5939, 3421, 1728, 705, 0]

    z = [326348, 252460, 223183, 206145, 192634, 42430, 1940, 0]
    c = [21411, 6519, 3423, 2615, 1681, 141, 0, 0]

    mem_label()
    plt.title('Tamanho de página fixo (4 KB) - compilador.log')
    plot_page_faults(mem, x, y, z)

    mem_label()
    plt.title('Tamanho de página fixo (4 KB) - compilador.log')
    plot_writebacks(mem, a, b, c)

    # COMPRESSOR.LOG
    x = [30473, 8198, 3330, 297, 0, 0, 0, 0]
    a = [6028, 1652, 893, 64, 0, 0, 0, 0]

    y = [2466, 1387, 773, 259, 0, 0, 0, 0]
    b = [848, 509, 309, 125, 0, 0, 0, 0]

    z = [118596, 108821, 58187, 198, 0, 0, 0, 0]
    c = [1532, 487, 165, 0, 0, 0, 0, 0]

    mem_label()
    plt.title('Tamanho de página fixo (4 KB) - compressor.log')
    plot_page_faults(mem, x, y, z)

    mem_label()
    plt.title('Tamanho de página fixo (4 KB) - compressor.log')
    plot_writebacks(mem, a, b, c)

    # SIMULADOR.LOG
    x = [303872, 201576, 88133, 18893, 11317, 5929, 3470, 0]
    a = [75226, 55871, 30680, 6045, 3738, 2078, 1058, 0]

    y = [85229, 48251, 27639, 15166, 7590, 4492, 2311, 0]
    b = [18806, 11935, 8343, 5412, 3341, 2365, 1572, 0]

    z = [405118, 331910, 278928, 276668, 268697, 242960, 14682, 0]
    c = [50149, 26298, 5015, 4019, 3257, 1411, 18, 0]

    mem_label()
    plt.title('Tamanho de página fixo (4 KB) - simulador.log')
    plot_page_faults(mem, x, y, z)

    mem_label()
    plt.title('Tamanho de página fixo (4 KB) - simulador.log')
    plot_writebacks(mem, a, b, c)


if __name__ == '__main__':
    main()
