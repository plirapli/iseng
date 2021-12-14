const fireFight = (str) => {
  return str.split(' ').map(a => a === 'Fire' ? '~~' : a ).join(' ')
}

console.log(fireFight("Boat Rudder Mast Boat Hull Water Fire Boat Deck Hull Fire Propeller Deck Fire Deck Boat Mast"), "Boat Rudder Mast Boat Hull Water ~~ Boat Deck Hull ~~ Propeller Deck ~~ Deck Boat Mast");
console.log(fireFight("Mast Deck Engine Water Fire"), "Mast Deck Engine Water ~~");
console.log(fireFight("Fire Deck Engine Sail Deck Fire Fire Fire Rudder Fire Boat Fire Fire Captain"), "~~ Deck Engine Sail Deck ~~ ~~ ~~ Rudder ~~ Boat ~~ ~~ Captain");