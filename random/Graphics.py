import numpy as np
import matplotlib.pyplot as plt



x, pdf1 = np.genfromtxt('data1.txt', unpack=True, usecols=(0, 1))

pdf2 = np.genfromtxt('data2.txt', unpack=True, usecols=(1))

pdf3 = np.genfromtxt('data5.txt', unpack=True, usecols=(1))

plt.style.use('seaborn-v0_8')

fig, axes = plt.subplots(figsize=(5, 6))

axes.plot(x, pdf1, '.', label=r'$f(x)$. Semilla: 1')
axes.plot(x, pdf2, '*', label=r'$f(x)$. Semilla: 2')
axes.plot(x, pdf3, '^', markersize = 5, label=r'$f(x)$. Semilla: 5',color='black')



# Se ajustan demás detalles del gráfico.
axes.set_xlabel('x', fontsize=12)
axes.set_ylabel(r'$f(x)$: Densidad de probabilidad.', fontsize=12)
# axes.legend(loc='upper left')
axes.grid(True, linestyle='--')
axes.set_title("Aproximación a funciones densidad de probabilidad para semillas 1,2 y 5.", fontsize=14)
axes.legend()
plt.tight_layout()
plt.show()
fig.savefig('random_pdf.pdf')
