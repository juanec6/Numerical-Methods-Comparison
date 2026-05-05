# Comparación de Métodos Numéricos Híbridos frente a Métodos Numéricos Clásicos para Resolución de Ecuaciones No Lineales

## 📋 Descripción del Proyecto

Este proyecto realiza un análisis comparativo exhaustivo entre métodos numéricos clásicos y métodos híbridos para la resolución de ecuaciones no lineales. El objetivo principal es evaluar el rendimiento, precisión y eficiencia de diferentes enfoques numéricos bajo diversas condiciones.

## 🎯 Objetivos

- Implementar métodos numéricos clásicos como bibliotecas independientes
- Desarrollar métodos híbridos combinando las fortalezas de los métodos clásicos
- Comparar el rendimiento de todos los métodos mediante métricas cuantitativas
- Analizar la eficiencia computacional y precisión de cada implementación

## 📚 Métodos Implementados

### Métodos Clásicos

#### 1. **Bisección (Bisection.h)**
- Método de búsqueda por división de intervalos
- Convergencia garantizada pero lenta
- Requiere cambio de signo en el intervalo inicial

#### 2. **Secante (Secant.h)**
- Método iterativo que aproxima la derivada
- No requiere cálculo de derivadas
- Convergencia superlineal

#### 3. **Newton-Raphson (NewtonRaphKantarovich.h)**
- Método de convergencia cuadrática
- Requiere cálculo de la derivada
- Altamente eficiente cerca de la raíz

#### 4. **Regula Falsi (RegulaFalsi.h)**
- Método de posición falsa
- Similar a bisección pero con convergencia más rápida
- Garantiza convergencia con cambio de signo

### Métodos Híbridos

#### 1. **Bisección-Newton-Raphson (BisectionNewtonRaphson.h)**
- Combina la robustez de bisección con la velocidad de Newton-Raphson
- Utiliza bisección para acercarse a la raíz y Newton-Raphson para refinamiento
- Equilibrio entre seguridad y eficiencia

#### 2. **Bisección-Secante (BisectionSecant.h)**
- Fusión de bisección y secante
- No requiere derivadas mientras mantiene convergencia garantizada
- Ideal para funciones donde la derivada es difícil de obtener

#### 3. **Regula Falsi-Newton-Raphson (RegulaFalsiNewtonRaphson.h)**
- Combina regula falsi con Newton-Raphson
- Aprovecha la convergencia cuadrática cuando es posible
- Fallback a regula falsi para casos problemáticos

#### 4. **Regula Falsi-Secante (RegulaFalsiSecant.h)**
- Híbrido de regula falsi y secante
- Convergencia rápida sin necesidad de derivadas
- Robusto ante diversos tipos de funciones

## 📊 Métricas de Comparación

El proyecto evalúa cada método utilizando las siguientes métricas:

### 1. **Iteraciones**
- Número total de iteraciones requeridas para convergencia
- Indicador de eficiencia del método

### 2. **Error Absoluto**
- |f(x)| - Valor de la función en la aproximación final
- Medida de qué tan cerca está de cero

### 3. **Error Relativo**
- Error en relación con el valor de la raíz
- Útil para comparar precisión entre diferentes problemas

### 4. **Evaluaciones en f(x)**
- Número de veces que se evalúa la función
- Importante para funciones computacionalmente costosas

### 5. **Evaluaciones en df(x)**
- Número de evaluaciones de la derivada
- Relevante para métodos que requieren derivadas

### 6. **Evaluaciones en ddf(x)**
- Evaluaciones de la segunda derivada
- Para métodos de orden superior (si aplica)

### 7. **Tiempo de CPU**
- Tiempo de ejecución en milisegundos
- Medida directa de eficiencia computacional

### 8. **Raíces Encontradas**
- Número de soluciones identificadas
- Validación de la completitud del método

### 9. **Raíces Duplicadas**
- Detección de raíces múltiples
- Importante para análisis de estabilidad

### 10. **Razón de Parada**
- Criterio que causó la terminación del algoritmo
- Puede ser: tolerancia alcanzada, máximo de iteraciones, divergencia, etc.

## 🗂️ Estructura del Proyecto

```
Numerical-Methods-Comparison/
│
├── Codes/
│   ├── Bisection.h                      # Método de bisección
│   ├── BisectionNewtonRaphson.h         # Híbrido bisección-Newton
│   ├── BisectionSecant.h                # Híbrido bisección-secante
│   ├── Functions.h                      # Funciones de prueba
│   ├── NewtonRaphKantarovich.h          # Método de Newton-Raphson
│   ├── RegulaFalsi.h                    # Método de regula falsi
│   ├── RegulaFalsiNewtonRaphson.h       # Híbrido regula falsi-Newton
│   ├── RegulaFalsiSecant.h              # Híbrido regula falsi-secante
│   ├── Secant.h                         # Método de la secante
│   └── main.cpp                         # Programa principal
│
├── README.md                            # Este archivo
└── Results/                             # Resultados de las comparaciones
```

## 🚀 Compilación y Ejecución

### Requisitos
- Compilador C++ compatible con C++11 o superior
- Sistema operativo: Windows, Linux o macOS

### Compilación

```bash
# Usando g++
g++ -std=c++11 -O2 main.cpp -o numerical_comparison

# Usando clang++
clang++ -std=c++11 -O2 main.cpp -o numerical_comparison
```

### Ejecución

```bash
./numerical_comparison
```

## 📈 Resultados Esperados

El programa generará una comparación detallada mostrando:

- Tabla comparativa de todas las métricas para cada método
- Análisis de convergencia
- Recomendaciones sobre qué método usar según el tipo de problema
- Gráficos de rendimiento (si se implementa visualización)

## 🔬 Casos de Prueba

El proyecto incluye diversas funciones de prueba en `Functions.h`:

- Polinomios de diferentes grados
- Funciones trigonométricas
- Funciones exponenciales
- Funciones con raíces múltiples
- Funciones con discontinuidades

## 📝 Notas de Implementación

### Ventajas de los Métodos Híbridos

1. **Mayor Robustez**: Combinan la garantía de convergencia de métodos lentos con la velocidad de métodos rápidos
2. **Adaptabilidad**: Se ajustan automáticamente según el comportamiento de la función
3. **Eficiencia**: Reducen el número de iteraciones respecto a métodos clásicos en muchos casos

### Consideraciones

- Los métodos híbridos pueden tener mayor complejidad de implementación
- El overhead de decisión puede ser relevante para funciones muy simples
- La elección del método depende de las características específicas del problema

## 📊 Formato de Salida

```
La comparación se realizará obteniendo las siguientes métricas:
   - Iteraciones.
   - Error Absoluto.
   - Error Relativo.
   - Evaluaciones en f(x).
   - Evaluaciones en df(x).
   - Evaluaciones en ddf(x).
   - CPU Time.
   - Raíces Encontradas.
   - Raíces duplicadas.
   - Reason for Stopping.
```

## 🤝 Contribuciones

Este proyecto es parte de un estudio académico sobre métodos numéricos. Las contribuciones y sugerencias son bienvenidas.

## 📚 Referencias

- Burden, R. L., & Faires, J. D. (2011). *Numerical Analysis*
- Chapra, S. C., & Canale, R. P. (2015). *Numerical Methods for Engineers*
- Press, W. H., et al. (2007). *Numerical Recipes: The Art of Scientific Computing*

## 👤 Autor

**juanec6**

## 📄 Licencia

Este proyecto está desarrollado con fines académicos y de investigación.

---

**Última actualización**: 2025

*Proyecto de Análisis Numérico - Comparación de Métodos para Resolución de Ecuaciones No Lineales*
