import sys

import itertools
import math
import random
import subprocess


if __name__ == "__main__":
	n = int(sys.argv[1])
	# numbers = random.sample(range(-2147483648, 2147483647), n)
	numbers = list(range(1, n + 1))
	max_case = ""
	max_score = 0
	min_score = 1000000
	scores_sum = 0
	if n == 3 or n == 5:
		permutations = list(itertools.permutations(numbers))
		nb_cases = len(permutations)
		for nums in permutations:
			args = " ".join([str(nb) for nb in nums])
			print(args + ' : ', end="")
			push_swap = subprocess.run('./push_swap ' + args + " | wc -l", stdout=subprocess.PIPE, shell=True)
			nb_operations = int(push_swap.stdout.decode('utf-8').strip('\n'))
			if nb_operations > max_score:
				max_case = args
				max_score = nb_operations
			elif nb_operations < min_score:
				min_score = nb_operations
			scores_sum += nb_operations
			print(('\033[1m\033[31mKO' if (n == 3 and nb_operations > 2) or (n == 5 and nb_operations > 12) else 'OK') + ' (' + str(nb_operations) + ')\033[0m')
	else:
		nb_cases = 1000
		for i in range(nb_cases):
			random.shuffle(numbers)
			args = " ".join([str(nb) for nb in numbers])
			push_swap = subprocess.run('./push_swap ' + args + " | wc -l", stdout=subprocess.PIPE, shell=True)
			nb_operations = int(push_swap.stdout.decode('utf-8').strip('\n'))
			if nb_operations > max_score:
				max_case = args
				max_score = nb_operations
			elif nb_operations < min_score:
				min_score = nb_operations
			scores_sum += nb_operations
			if n == 100 and nb_operations > 700 or n == 500 and nb_operations > 5500:
				print(args + ' -> ', end='')
			print(('\033[1m\033[31mKO' if (n == 100 and nb_operations > 700) or (n == 500 and nb_operations > 5500) else 'OK') + ' (' + str(nb_operations) + ')\033[0m')
	print(f'\n- - -\nMax : {max_case}', end='')
	print(f'\n- - -\nMax : {max_score}\nAvg : {math.ceil(scores_sum / nb_cases)}\nMin : {min_score}')
