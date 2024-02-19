import numpy as np
import matplotlib.pyplot as plt


n, relativDiff = np.genfromtxt('data.txt', unpack=True, usecols=(0,3))

plt.style.use('seaborn-v0_8')

fig, axes = plt.subplots(figsize=(5, 6 ))

axes.plot(n, relativDiff, 'bo', label=r'$\Delta$(N)')

# Se ajustan demás detalles del gráfico.
axes.set_xlabel('N', fontsize=12)
axes.set_ylabel(r'$\Delta$: Diferencia relativa.', fontsize=12)
# axes.legend(loc='upper left')
axes.grid(True, linestyle='--')
axes.set_title(f"Diferencia relativa vs N.", fontsize=14)
plt.tight_layout()
plt.savefig('Resultados.pdf')
plt.show()
