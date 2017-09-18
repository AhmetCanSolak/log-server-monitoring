import matplotlib.pyplot as plt
import numpy as np

def piChartFunc(labels,sizes,name):

    patches, texts = plt.pie(sizes, shadow=True, startangle=90)
    plt.legend(patches, labels, loc="best")
    plt.axis('equal')
    plt.tight_layout()
    fig1 = plt.gcf()
    plt.plot()
    plt.draw()
    name = "results/images/" + name + ".png"
    fig1.savefig(name, dpi=100)
    plt.close()

def barChartFunc(labels,values,name,titleChart,labelx,labely):

    objects = labels
    y_pos = np.arange(len(objects))
    performance = values
    plt.legend( labels, loc="best")
    plt.bar(y_pos, performance, alpha=1)
    plt.xticks(y_pos, objects)
    plt.ylabel(labely)
    plt.xlabel(labelx)
    plt.title(titleChart)

    plt.axis('equal')
    plt.tight_layout()
    fig1 = plt.gcf()
    plt.plot()
    plt.draw()
    name = "results/images/" + name + ".png"
    fig1.savefig(name, dpi=100)
