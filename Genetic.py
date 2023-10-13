import random 

# Numero de individuos en cada generacion
POPULATION_SIZE = 100

# genes validos
GENES = '''abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOP 
QRSTUVWXYZ 1234567890, .-;:_!"#%&/()=?@${[]}'''

# Target a generar 
TARGET = "LAZARO FERNANDO"

class Individual(object): 
	''' 
	clase que representa al individuo en la poblacion
	'''
	def __init__(self, chromosome): 
		self.chromosome = chromosome 
		self.fitness = self.cal_fitness() 

	@classmethod
	def mutated_genes(self): 
		''' 
		crear genes aleatorios para la mutacion 
		'''
		global GENES 
		gene = random.choice(GENES) 
		return gene 

	@classmethod
	def create_gnome(self): 
		''' 
		crear cromosoma o cadena de genes
		'''
		global TARGET 
		gnome_len = len(TARGET) 
		return [self.mutated_genes() for _ in range(gnome_len)] 

	def mate(self, par2): 
		''' 
		Realizar el apareamiento y producir nueva descendencia 
		'''

		# cromosoma para la descendencia 
		child_chromosome = [] 
		for gp1, gp2 in zip(self.chromosome, par2.chromosome):	 

			# probabilidad aleatoria 
			prob = random.random() 

			# si prob es menor que 0.45, insertar gen 
			if prob < 0.45: 
				child_chromosome.append(gp1) 

			# si prob esta entre 0.45 y 0.90, insertar 
			elif prob < 0.90: 
				child_chromosome.append(gp2) 

			# de otra forma insertar gen mutado
			else: 
				child_chromosome.append(self.mutated_genes()) 

		# crear nuevo Individuo(descendencia) usando 
		# cromosoma generado para la descendencia
		return Individual(child_chromosome) 

	def cal_fitness(self): 
		''' 
		Calcular la puntuación de aptitud, es el número de 
		caracteres de la cadena que difieren de la 
		objetivo.
		'''
		global TARGET 
		fitness = 0
		for gs, gt in zip(self.chromosome, TARGET): 
			if gs != gt: fitness+= 1
		return fitness 

# Driver code 
def main(): 
	global POPULATION_SIZE 

	#generacion actual 
	generation = 1

	found = False
	population = [] 

	# crear poblacion inicial 
	for _ in range(POPULATION_SIZE): 
				gnome = Individual.create_gnome() 
				population.append(Individual(gnome)) 

	while not found: 

# ordena la población en orden creciente de puntuación de fitness
		population = sorted(population, key = lambda x:x.fitness) 

		# si el individuo que tiene menor puntuación de fitness es decir. 
		# 0 entonces sabemos que hemos alcanzado el objetivo 
		# y rompemos el bucle
		if population[0].fitness <= 0: 
			found = True
			break

# En caso contrario, generar nuevas crías para la nueva generación.
		new_generation = [] 

		# Realiza elitismo, eso significa que el 10% de la población más apta 
		# pasa a la siguiente generación
		s = int((10*POPULATION_SIZE)/100) 
		new_generation.extend(population[:s]) 

		# Del 50% de la población más apta, los individuos 
		# se aparearán para producir descendencia
		s = int((90*POPULATION_SIZE)/100) 
		for _ in range(s): 
			parent1 = random.choice(population[:50]) 
			parent2 = random.choice(population[:50]) 
			child = parent1.mate(parent2) 
			new_generation.append(child) 

		population = new_generation 

		print("Generation: {}\tString: {}\tFitness: {}".format
		(generation, 
			"".join(population[0].chromosome), 
			population[0].fitness)) 

		generation += 1

	
	print("Generation: {}\tString: {}\tFitness: {}".format(
    generation,
    "".join(population[0].chromosome),
    population[0].fitness))


if __name__ == '__main__': 
	main() 
