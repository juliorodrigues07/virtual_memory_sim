from plotting import plot_page_faults
from plotting import plot_writebacks
from plotting import mem_label
import matplotlib.pyplot as plt


def main():

    mem = [128, 256, 512, 1024, 2048, 4096, 8192, 16384]

    # MATRIZ.LOG
    x = [233382, 129136, 31031, 7661, 5532, 4363, 2963, 2543]
    a = [30397, 22260, 7421, 2261, 1697, 1160, 295, 0]

    y = [81558, 30440, 17556, 8563, 4875, 3291, 2812, 2543]
    b = [18161, 7585, 4941, 2840, 1631, 979, 356, 0]

    z = [487913, 189171, 28404, 7949, 6015, 4559, 3125, 2543]
    c = [10621, 4774, 2854, 1674, 968, 265, 0, 0]

    mem_label()
    plt.title('Tamanho de página fixo (4 KB) - matriz.log')
    plot_page_faults(mem, x, y, z)

    mem_label()
    plt.title('Tamanho de página fixo (4 KB) - matriz.log')
    plot_writebacks(mem, a, b, c)

    # COMPILADOR.LOG
    x = [378715, 286483, 182057, 67338, 15258, 8502, 3275, 2852]
    a = [45297, 33621, 21546, 9198, 2516, 1247, 391, 0]

    y = [98087, 70290, 48548, 31693, 15506, 6659, 3453, 2852]
    b = [16751, 12045, 8485, 5939, 3421, 1728, 705, 0]

    z = [310669, 209127, 123885, 48509, 16037, 11294, 3988, 2852]
    c = [18091, 7341, 4854, 3613, 1665, 515, 0, 0]

    mem_label()
    plt.title('Tamanho de página fixo (4 KB) - compilador.log')
    plot_page_faults(mem, x, y, z)

    mem_label()
    plt.title('Tamanho de página fixo (4 KB) - compilador.log')
    plot_writebacks(mem, a, b, c)

    # COMPRESSOR.LOG
    x = [30505, 8262, 3458, 553, 317, 317, 317, 317]
    a = [6028, 1652, 893, 64, 0, 0, 0, 0]

    y = [2498, 1451, 901, 512, 317, 317, 317, 317]
    b = [848, 509, 309, 125, 0, 0, 0, 0]

    z = [13850, 4137, 1558, 454, 317, 317, 317, 317]
    c = [1579, 599, 270, 0, 0, 0, 0, 0]

    mem_label()
    plt.title('Tamanho de página fixo (4 KB) - compressor.log')
    plot_page_faults(mem, x, y, z)

    mem_label()
    plt.title('Tamanho de página fixo (4 KB) - compressor.log')
    plot_writebacks(mem, a, b, c)

    # SIMULADOR.LOG
    x = [303904, 201636, 88261, 19149, 11829, 6953, 5518, 3890]
    a = [75226, 55871, 30680, 6045, 3738, 2078, 1058, 0]

    y = [85261, 48315, 27767, 15422, 8102, 5516, 4359, 3890]
    b = [18806, 11935, 8343, 5412, 3341, 2365, 1572, 0]

    z = [372899, 200680, 63957, 17813, 12013, 8725, 6608, 3890]
    c = [46191, 23270, 6330, 4293, 3062, 1584, 163, 0]

    mem_label()
    plt.title('Tamanho de página fixo (4 KB) - simulador.log')
    plot_page_faults(mem, x, y, z)

    mem_label()
    plt.title('Tamanho de página fixo (4 KB) - simulador.log')
    plot_writebacks(mem, a, b, c)


if __name__ == '__main__':
    main()
