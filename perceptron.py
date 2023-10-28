import random

# Función de activación para la compuerta AND
def step_function(x):
    return 1 if x >= 0.5 else 0

# Función para entrenar el perceptrón
def train_perceptron(inputs, weights, target_output, learning_rate, epochs):
    for epoch in range(epochs):
        error = False
        for i in range(len(inputs)):
            input_data = inputs[i]
            weighted_sum = sum([input_data[j] * weights[j] for j in range(len(input_data))])
            output = step_function(weighted_sum)
            delta = target_output[i] - output
            if delta != 0:
                error = True
            for j in range(len(weights)):
                weights[j] += learning_rate * delta * input_data[j]
        if not error:
            break

# Datos de entrenamiento (compuerta AND)
inputs = [(0, 0), (0, 1), (1, 0), (1, 1)]
target_output = [0, 0, 0, 1]

# Inicializar pesos de forma aleatoria
weights = [random.uniform(-1, 1) for _ in range(2)]

# Hiperparámetros
learning_rate = 0.1
epochs = 1000

# Entrenar el perceptrón
train_perceptron(inputs, weights, target_output, learning_rate, epochs)

# Probar el perceptrón entrenado
for i in range(len(inputs)):
    input_data = inputs[i]
    weighted_sum = sum([input_data[j] * weights[j] for j in range(len(input_data))])
    output = step_function(weighted_sum)
    print(f"Input: {input_data} --> Output: {output}")
