console.log("Hello World, POKEMON BATTLE!!");

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
    this.attacksLeft = 2; // Added to track remaining attacks
}

Pokemon.prototype.attackOpponent = function(opponent) {
    console.log(`${this.name} Used tackle to deal damage to ${opponent.name}!`);
    opponent.health -= this.attack;
    console.log(`${opponent.name}'s health reduced to ${opponent.health}`);
    displayBattleLog(`${this.name} used Tackle! ${opponent.name} lost ${this.attack} HP.`);
    this.attacksLeft--; // Decrease remaining attacks
    if (opponent.health <= 0 || this.attacksLeft === 0) { // Check fainting condition
        console.log(`${opponent.name} fainted!`);
        displayBattleLog(`${opponent.name} fainted!`);
        return true; // Indicate opponent fainted
    }
    return false; // Indicate opponent still alive
};

function displayBattleLog(message) {
    let battleLog = document.getElementById('battleLog');
    let p = document.createElement('p');
    p.textContent = message;
    battleLog.appendChild(p);
}

let pikachu = new Pokemon('Pikachu', 7, 140, 80);
let charmander = new Pokemon('Charmander', 7, 140, 80);

document.getElementById('tackleButton1').addEventListener('click', function() {
    if (charmander.attackOpponent(pikachu)) {
        declareWinner(charmander);
    }
});

document.getElementById('tackleButton2').addEventListener('click', function() {
    if (pikachu.attackOpponent(charmander)) {
        declareWinner(pikachu);
    }
});

trainer.addPokemon(pikachu);
trainer.addPokemon(charmander);

function declareWinner(winner) {
    let remainingPokemon = trainer.pokemonList.filter(pokemon => pokemon !== winner);
    console.log(`${winner.name} is the winner!`);
    displayBattleLog(`${winner.name} is the winner!`);
    if (remainingPokemon.length > 0) {
        console.log(`${remainingPokemon[0].name} is the remaining Pokemon.`);
        displayBattleLog(`${remainingPokemon[0].name} is the remaining Pokemon.`);
    } else {
        console.log("No Pokemon remaining!");
        displayBattleLog("No Pokemon remaining!");
    }
}