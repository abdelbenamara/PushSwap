import sys

import itertools
import random
import subprocess


if __name__ == "__main__":
	n = int(sys.argv[1])
	# numbers = random.sample(range(-2147483648, 2147483647), n)
	numbers = list(range(1, n + 1))
	if n == 3 or n == 5:
		permutations = list(itertools.permutations(numbers))
		for nums in permutations:
			args = " ".join([str(nb) for nb in nums])
			print(args + ' : ', end="")
			push_swap = subprocess.run('./push_swap ' + args + " | wc -l", stdout=subprocess.PIPE, shell=True)
			nb_operations = int(push_swap.stdout.decode('utf-8').strip('\n'))
			print(('KO' if (n == 3 and nb_operations > 2) or (n == 5 and nb_operations > 12) else 'OK') + ' (' + str(nb_operations) + ')')
	else:
		random.shuffle(numbers)
		args = " ".join([str(nb) for nb in numbers])
		print(args + ' : ', end="")
		push_swap = subprocess.run('./push_swap ' + args + " | wc -l", stdout=subprocess.PIPE, shell=True)
		nb_operations = int(push_swap.stdout.decode('utf-8').strip('\n'))
		print(('KO' if (n == 100 and nb_operations > 700) or (n == 500 and nb_operations > 5500) else 'OK') + ' (' + str(nb_operations) + ')')
