import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit



# Se define la función de ajuste:
def gaussiana(x, mu, sigma, A):
    return A * np.exp(-0.5 * ((x - mu) / sigma)**2)


#Se leen los datos de cada semilla:
x, pdf1 = np.genfromtxt('data1.txt', unpack=True, usecols=(0, 1))

pdf2 = np.genfromtxt('data2.txt', unpack=True, usecols=(1))

pdf3 = np.genfromtxt('data5.txt', unpack=True, usecols=(1))


# Se obtienen los parámetros de ajuste.
parametros1, matrizCov1 = curve_fit(gaussiana, x, pdf1, p0=[3.1, 0.7, 1])
parametros2, matrizCov2 = curve_fit(gaussiana, x, pdf2, p0=[3.1, 0.7, 1])
parametros3, matrizCov3 = curve_fit(gaussiana, x, pdf3, p0=[3.1, 0.7, 1])

#Se calcula R^2, el coeficiente de correlación para cada ajuste haciendo uso de la suma de la suma residual de los cuadrados
#y la suma total de cuadrados, que es proporcional a la varianza.

pdf1Ajustado = gaussiana(x, *parametros1)
sumaResidual1 = np.sum((pdf1 - pdf1Ajustado)**2)
varianzaTotalpdf1 = np.sum((pdf1 - np.mean(pdf1))**2)

R2_1 = 1 - sumaResidual1 / varianzaTotalpdf1

pdf2Ajustado = gaussiana(x, *parametros2)
sumaResidual2 = np.sum((pdf2 - pdf2Ajustado)**2)
varianzaTotalpdf2 = np.sum((pdf2 - np.mean(pdf2))**2)

R2_2 = 1 - sumaResidual2 / varianzaTotalpdf2

pdf3Ajustado = gaussiana(x, *parametros3)
sumaResidual3 = np.sum((pdf3 - pdf3Ajustado)**2)
varianzaTotalpdf3 = np.sum((pdf3 - np.mean(pdf3))**2)

R2_3 = 1 - sumaResidual3 / varianzaTotalpdf3


# Imprimir los parámetros óptimos del ajuste y R^2
print("Parámetros óptimos del ajuste gaussiano 1 (mu, sigma,A):", parametros1)
print("Coeficiente de determinación R^2_1:", R2_1)

print("Parámetros óptimos del ajuste gaussiano 2 (mu, sigma,A):", parametros2)
print("Coeficiente de determinación R^2_2:", R2_2)

print("Parámetros óptimos del ajuste gaussiano 3 (mu, sigma,A):", parametros3)
print("Coeficiente de determinación R^2_3:", R2_3)




plt.style.use('seaborn-v0_8')

fig, axes = plt.subplots(figsize=(6, 7))

axes.plot(x, pdf1, '.', label=r'$f(x)$. Semilla: 1',color="cadetblue")
axes.plot(x, pdf1Ajustado, label=r'Curva ajuste. Semilla 1',color="cadetblue")

axes.plot(x, pdf2, '*', label=r'$f(x)$. Semilla: 2', color="crimson")
axes.plot(x, pdf2Ajustado, label=r'Curva ajuste. Semilla 2', color="crimson")

axes.plot(x, pdf3, '^', markersize = 5, label=r'$f(x)$. Semilla: 5', color='black')
axes.plot(x, pdf3Ajustado, label=r'Curva ajuste. Semilla 5', color="black")


# Se ajustan demás detalles del gráfico.
axes.set_xlabel('x', fontsize=12)
axes.set_ylabel(r'$f(x)$: Densidad de probabilidad.', fontsize=12)
# axes.legend(loc='upper left')
axes.grid(True, linestyle='--')
axes.set_title("Aproximación a funciones densidad \n de probabilidad para semillas 1,2 y 5.", fontsize=14)
axes.legend()
plt.tight_layout()
plt.show()
fig.savefig('random_pdf.pdf')
