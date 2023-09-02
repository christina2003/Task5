#library to make one of the players play automatically
import random 

#parent class
class villain:
    def __init__(self, health=100, energy=500):
        self.health = health
        self.energy = energy
        self.shields = 0

#child classes
class Gru(villain):
    def __init__(self, health=100, energy=500):
        super().__init__(health, energy)
        self.weapons = {
            'freeze gun': {'energy': 50, 'damage': 11, 'resources': float('inf')},
            'electric prod': {'energy': 88, 'damage': 18, 'resources': 5},
            'mega magnet': {'energy': 92, 'damage': 10, 'resources': 3},
            'kalman missile': {'energy': 120, 'damage': 20, 'resources': 1}
        }
        self.shields = {
            'energy projected barrier': {'energy': 20, 'save': 40, 'resources': float('inf')},
            'selective permeability': {'energy': 50, 'save': 90, 'resources': 2}
        }
        self.health = health
        self.energy = energy

class Vector(villain):
    def __init__(self, health=100, energy=500):
        super().__init__(health, energy)
        self.weapons = {
            'laser blasters': {'energy': 40, 'damage': 8, 'resources':float('inf')},
            'plasma grenades': {'energy': 8, 'damage': 13, 'resources': 8},
            'sonic resonance cannon': {'energy': 100, 'damage': 22, 'resources': 3}
        }
        self.shields = {
            'energy net trap': {'energy': 15, 'save': 32,'resources': float('inf')},
            'quantum deflector': {'energy': 40, 'save': 80, 'resources': 3}
        }

class SkyClashGame:
    
    def __init__(self):
        self.gru = Gru(health=100, energy=500)
        self.vector = Vector(health=100, energy=500)

    def simulate_round(self):

        # Manual control for Gru's weapon choice
        gru_weapon = input("Choose a weapon for Gru: ")

        #checking the validity of the choosen weapon
        while gru_weapon not in self.gru.weapons :
            print("Invalid weapon choice. Try again.")
            gru_weapon = input("Choose a weapon for Gru: ")

        #printing the number of weapons left after using    
        weapons_left =  self.gru.weapons[gru_weapon]['resources'] -1 
        print(str(weapons_left) + " has left")  

        # Manual control for Gru's shield choice
        gru_shield = input("Choose a shield for Gru: ")  

        #checking the validity of the choosen shield
        while gru_shield not in self.gru.shields:
            print("Invalid shield choice. Try again.")
            gru_shield = input("Choose a shield for Gru: ")

        #display the number of shields left after using   
        shields_left =  self.gru.shields[gru_shield]['resources'] -1
        print(str(shields_left) + " has left")    
        

        # Random weapon choice for Vector
        vector_weapon = random.choice(list(self.vector.weapons.keys()))

        # Random shield choice for Vector
        vector_shield = random.choice(list(self.vector.shields.keys()))


        #getting the value of damage after using a weapon
        gru_damage = self.gru.weapons[gru_weapon]['damage']
        vector_damage = self.vector.weapons[vector_weapon]['damage']

        #if condition to decide the value of damage after vector's using of a shield
        if gru_weapon == "kalman missile":
            gru_damage = 20
        else :
            gru_damage -= int(gru_damage * self.vector.shields[vector_shield]['save'] / 100)

        #equation to calculate the value of damage after Gru's using of a shield
        vector_damage -= int(vector_damage * self.gru.shields[gru_shield]['save'] / 100)

        #getting the value of energy reduction after using of weapons and shields
        gru_energy_reduction = self.gru.shields[gru_shield]['energy'] + self.gru.weapons[gru_weapon]['energy']
        vector_energy_reduction = self.vector.shields[vector_shield]['energy'] + self.vector.weapons[vector_weapon]['energy']
        
        #equations to calculate the energy and health afte reduction
        self.vector.health -= gru_damage
        self.gru.health -= vector_damage
        self.gru.energy -= gru_energy_reduction
        self.vector.energy -= vector_energy_reduction

        # Display health and energy after the round
        print("Gru's Health:", self.gru.health)
        print("Gru's Energy:", self.gru.energy)
        print("Vector's Health:", self.vector.health)
        print("Vector's Energy:", self.vector.energy)
        print()


    def play_game(self):
        while self.gru.health > 0 and self.vector.health > 0 and self.gru.energy>0 and self.vector.energy>0 :
            self.simulate_round()

        if self.gru.health <= 0 or self.vector.health> self.gru.health:
            print("Vector wins!")
        if self.vector.health <= 0 or self.gru.health> self.vector.health:
            print("Gru wins!")


game = SkyClashGame()
game.play_game()


## Notes for what I tried to do but I couldn't:
# 1. control the number of used weapons and shields 
# 2. make the player make the choice if he wants to use a shield or no 
# 3. the effect of using mega magnet on the next opponent's attack

