import random

ids = [3249, 3381, 3380, 6681, 163, 5207, 7375, 7893, 2855, 2118, 2895, 1236, 1105, 2950, 7479, 62, 1630, 7437, 7347, 2145]

def generate_random_id():
    return random.randint(100, 1000)

def generate_output():
    output = []
    for _ in range(20):
        gmId = generate_random_id()
        output.append(f'{gmId}')
        gmPlayers = []
        for _ in range(random.randint(2, 8)):
            gmP = random.choice(ids)
            while gmP in gmPlayers:
                gmP = random.choice(ids)
            gmPlayers.append(gmP)
            output.append(f'-{gmP}')
    return output

with open('output.txt', 'w') as file:
    file.write('\n'.join(generate_output()))
