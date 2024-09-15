import pandas as pd
import matplotlib.pyplot as plt
import matplotlib.animation as animation

# Leer los datos del archivo CSV
data = pd.read_csv('agent_positions.csv')

# Obtener el número de agentes y pasos
num_agents = data['Agent'].nunique()
steps = data['Step'].max()

# Crear la figura y los ejes
fig, ax = plt.subplots(figsize=(8, 8))
ax.set_xlim(0, 10)
ax.set_ylim(0, 10)
ax.set_title('Agent Movements')
ax.set_xlabel('X Position')
ax.set_ylabel('Y Position')
ax.grid(True)

# Crear los puntos (uno para cada agente)
points, = ax.plot([], [], 'o', color='blue')

# Inicializar los puntos
def init():
    points.set_data([], [])
    return points,

# Función para actualizar la posición de los agentes en cada frame
def update(step):
    # Filtrar los datos para el paso actual
    step_data = data[data['Step'] == step]
    # Obtener las posiciones de los agentes
    x = step_data['X']
    y = step_data['Y']
    # Actualizar las posiciones de los puntos
    points.set_data(x, y)
    ax.set_title(f'Step {step}')
    return points,

# Crear la animación: intervalo de 1000 ms (1 segundo) entre frames
ani = animation.FuncAnimation(fig, update, frames=range(1, steps+1), init_func=init, interval=1000, blit=True)

# Mostrar la animación
plt.show()
