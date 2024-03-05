console.log("Hello World, POKEMON BATTLE!!");

let myPokemon = {
    name: 'Pikachu',
    level: 7,
    health: 140,
    attack: 80,
    tackle: function() {
        console.log('The pokemon tackle the target pokemon');
        console.log("targetPokemon");
    }
};


let trainer = {
    name: 'Dave',
    age: 18,
    pokemonList: [],

    addPokemon: function(pokemon) {
        this.pokemonList.push(pokemon);
        console.log(`${pokemon.name} added to ${this.name}'s team!`);
    }
};


function Pokemon(name, level, health, attack) {
    this.name = name;
    this.level = level;
    this.health = health;
    this.attack = attack;
}


Pokemon.prototype.attackOpponent = function(opponent) {
    console.log(`${this.name} Used tackle to deal damage to ${opponent.name}!`);
    opponent.health -= this.attack; 
    console.log(`${opponent.name}'s health reduced to ${opponent.health}`);
};


let pikachu = new Pokemon('Pikachu', 7, 140, 80);
let charmander = new Pokemon('Charmander', 7, 140, 80);
let squirtle = new Pokemon('Squirtle', 7, 140, 80);


pikachu.attackOpponent(charmander);
charmander.attackOpponent(squirtle);


console.log(`Trainer: ${trainer.name}, Age: ${trainer.age} has defeated`);

console.log(`Trainer: Red  Age: ${trainer['age']}`);


trainer.addPokemon(pikachu);
trainer.addPokemon(charmander);
trainer.addPokemon(squirtle);